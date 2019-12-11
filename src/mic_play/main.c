#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "i2s.h"
#include "sysctl.h"
#include "fpioa.h"
#include "uarths.h"
#include "board_config.h"
#include "syslog.h"

#define FRAME_LEN   128
uint32_t rx_buf[1024];
uint32_t g_index;
uint32_t g_tx_len;

static const char *TAG = "MIC_PLAY";

void mic_spk_i2s_io_mux_init()
{
    fpioa_set_function(MIC_I2S_IN_D0_PIN_NUM, FUNC_I2S0_IN_D0);
    fpioa_set_function(MIC_I2S_WS_PIN_NUM, FUNC_I2S0_WS);
    fpioa_set_function(MIC_I2S_SCLK_PIN_NUM, FUNC_I2S0_SCLK);

	fpioa_set_function(SPK_I2S_OUT_D1_PIN_NUM, FUNC_I2S2_OUT_D1);
    fpioa_set_function(SPK_I2S_SCLK_PIN_NUM, FUNC_I2S2_SCLK);
    fpioa_set_function(SPK_I2S_WS_PIN_NUM, FUNC_I2S2_WS);
}

int main(void)
{
    sysctl_pll_set_freq(SYSCTL_PLL0, 320000000UL);
    sysctl_pll_set_freq(SYSCTL_PLL1, 160000000UL);
    sysctl_pll_set_freq(SYSCTL_PLL2, 45158400UL);
    uarths_init();
    mic_spk_i2s_io_mux_init();
    LOGI(TAG, "I2S0 DD receive , I2S2 play...\r\n");

    g_index = 0;
    g_tx_len = 0;

    i2s_init(I2S_DEVICE_0, I2S_RECEIVER, 0x3);
    i2s_init(I2S_DEVICE_2, I2S_TRANSMITTER, 0xC);

    i2s_rx_channel_config(I2S_DEVICE_0, I2S_CHANNEL_0,
        RESOLUTION_16_BIT, SCLK_CYCLES_32,
        TRIGGER_LEVEL_4, STANDARD_MODE);

    i2s_tx_channel_config(I2S_DEVICE_2, I2S_CHANNEL_1,
        RESOLUTION_16_BIT, SCLK_CYCLES_32,
        TRIGGER_LEVEL_4,
        RIGHT_JUSTIFYING_MODE
        );

    i2s_receive_data_dma(I2S_DEVICE_0, &rx_buf[g_index], FRAME_LEN * 2, DMAC_CHANNEL1);

    while (1)
    {
        g_index += (FRAME_LEN*2);
        if(g_index >= 1023)
        {
            g_index = 0;
        }
		//LOGI(TAG, "g_index = %d",g_index);
        i2s_receive_data_dma(I2S_DEVICE_0, &rx_buf[g_index], FRAME_LEN * 2, DMAC_CHANNEL1);
		
		//LOGI(TAG, "g_index - g_tx_len = %d",g_index - g_tx_len);
        if (g_index - g_tx_len >= FRAME_LEN || g_tx_len - g_index >= (1023 - FRAME_LEN * 2))
        {
            i2s_send_data_dma(I2S_DEVICE_2, &rx_buf[g_tx_len], FRAME_LEN * 2, DMAC_CHANNEL0);
            g_tx_len += (FRAME_LEN * 2);
			//LOGI(TAG, "g_tx_len = %d",g_tx_len);
            if (g_tx_len >= 1023)
                g_tx_len = 0;
        }
    }

    return 0;
}

