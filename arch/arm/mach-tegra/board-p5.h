/*
 * arch/arm/mach-tegra/board-p5.h
 *
 * Copyright (C) 2011 Google, Inc.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

#ifndef _MACH_TEGRA_BOARD_P5_H
#define _MACH_TEGRA_BOARD_P5_H

int p3_regulator_init(void);
int p3_sdhci_init(void);
int p3_pinmux_init(void);
int p3_panel_init(void);
int p3_gpio_i2c_init(void);
int p3_sensors_init(void);
int p4_kbc_init(void);
int p3_emc_init(void);
void p3_stmpe1801_gpio_setup_board(void);
void p3_stmpe1801_gpio_setup_sensor(void);
void p3_panel_gpio_init(void);
int p4_gpio_fixed_voltage_regulator_init(void);


/*Check ADC value to select headset type*/
//extern s16 adc_get_value(u8 channel);
//extern s16 stmpe811_adc_get_value(u8 channel);

//extern usb_path_type usb_sel_status;
//extern void p3_set_usb_path(usb_path_type usb_path);

#if defined(CONFIG_TDMB) || defined(CONFIG_TDMB_MODULE)
extern int nvhost_t20_boost_2d(bool enable);
#endif

/* PCA954x I2C bus expander bus addresses */
#define PCA954x_I2C_BUS_BASE	6
#define PCA954x_I2C_BUS0	(PCA954x_I2C_BUS_BASE + 0)
#define PCA954x_I2C_BUS1	(PCA954x_I2C_BUS_BASE + 1)
#define PCA954x_I2C_BUS2	(PCA954x_I2C_BUS_BASE + 2)

/* STMPE1801 gpio expander */
#define STMPE1801_NR_INTERNAL_IRQS	5
#define STMPE1801_GPIO_BASE	(TEGRA_NR_GPIOS+STMPE1801_NR_INTERNAL_IRQS)
#define STMPE1801_NR_GPIOS	18
#define STMPE1801_INT_BASE	TEGRA_NR_IRQS
#define STMPE1801_NR_IRQ	(STMPE1801_NR_INTERNAL_IRQS+STMPE1801_NR_GPIOS)

/* Sensor gpios */
#define ISL29018_IRQ_GPIO	TEGRA_GPIO_PZ2
#define AKM8975_IRQ_GPIO	TEGRA_GPIO_PN5
#define NCT1008_THERM2_GPIO	TEGRA_GPIO_PN6

#define CAMERA_POWER_GPIO	TEGRA_GPIO_PV4
#define CAMERA_CSI_MUX_SEL_GPIO	TEGRA_GPIO_PBB4
#define CAMERA_FLASH_ACT_GPIO	TEGRA_GPIO_PD2

/* TPS6586X gpios */
#define TPS6586X_GPIO_BASE	(STMPE1801_GPIO_BASE+STMPE1801_NR_GPIOS)
#define AVDD_DSI_CSI_ENB_GPIO	(TPS6586X_GPIO_BASE + 1) /* gpio2 */

/* TCA6416 gpios */
#define TCA6416_GPIO_BASE	(TEGRA_NR_GPIOS + 4)
#define CAM1_PWR_DN_GPIO	(TCA6416_GPIO_BASE + 0) /* gpio0 */
#define CAM1_RST_L_GPIO		(TCA6416_GPIO_BASE + 1) /* gpio1 */
#define CAM1_AF_PWR_DN_L_GPIO	(TCA6416_GPIO_BASE + 2) /* gpio2 */
#define CAM1_LDO_SHUTDN_L_GPIO	(TCA6416_GPIO_BASE + 3) /* gpio3 */
#define CAM2_PWR_DN_GPIO	(TCA6416_GPIO_BASE + 4) /* gpio4 */
#define CAM2_RST_L_GPIO		(TCA6416_GPIO_BASE + 5) /* gpio5 */
#define CAM2_AF_PWR_DN_L_GPIO	(TCA6416_GPIO_BASE + 6) /* gpio6 */
#define CAM2_LDO_SHUTDN_L_GPIO	(TCA6416_GPIO_BASE + 7) /* gpio7 */
#define CAM3_PWR_DN_GPIO	(TCA6416_GPIO_BASE + 8) /* gpio8 */
#define CAM3_RST_L_GPIO		(TCA6416_GPIO_BASE + 9) /* gpio9 */
#define CAM3_AF_PWR_DN_L_GPIO	(TCA6416_GPIO_BASE + 10) /* gpio10 */
#define CAM3_LDO_SHUTDN_L_GPIO	(TCA6416_GPIO_BASE + 11) /* gpio11 */
#define CAM_I2C_MUX_RST_GPIO	(TCA6416_GPIO_BASE + 15) /* gpio15 */
#define TCA6416_GPIO_END	(TCA6416_GPIO_BASE + 31)

#define TPS6586X_GPIO_END	TPS6586X_GPIO(TPS6586X_NR_GPIOS - 1)

/* WM8903 GPIOs */
#define WM8903_GPIO_BASE	(TCA6416_GPIO_END + 1)
#define WM8903_GPIO(_x_)	(WM8903_GPIO_BASE + (_x_))
#define WM8903_NR_GPIOS		4
#define WM8903_GPIO_END		WM8903_GPIO(WM8903_NR_GPIOS - 1)

/* Audio-related GPIOs */
#define TEGRA_GPIO_CDC_IRQ	TEGRA_GPIO_PX3
#define TEGRA_GPIO_SPKR_EN	WM8903_GPIO(2)
#define TEGRA_GPIO_HP_DET	TEGRA_GPIO_PW2
#define TEGRA_GPIO_HP_DET	TEGRA_GPIO_PW2
#define TEGRA_GPIO_INT_MIC_EN	TEGRA_GPIO_PX0
#define TEGRA_GPIO_EXT_MIC_EN	TEGRA_GPIO_PX1

/* AC detect GPIO */
#define AC_PRESENT_GPIO		TEGRA_GPIO_PV3

/* Interrupt numbers from external peripherals */
#define TPS6586X_INT_BASE	(STMPE1801_INT_BASE+STMPE1801_NR_IRQ)
#define TPS6586X_INT_END	(TPS6586X_INT_BASE + 32)

/* Invensense MPU Definitions */
#define MPU_TYPE_MPU3050	1
#define MPU_TYPE_MPU6050	2
#define MPU_GYRO_TYPE		MPU_TYPE_MPU3050
#define MPU_GYRO_IRQ_GPIO	TEGRA_GPIO_PZ4
#define MPU_GYRO_ADDR		0x68
#define MPU_GYRO_BUS_NUM	0
#define MPU_GYRO_ORIENTATION	{ 0, -1, 0, -1, 0, 0, 0, 0, -1 }
#define MPU_ACCEL_NAME		"kxtf9"
#define MPU_ACCEL_IRQ_GPIO	0 /* Disable ACCELIRQ: TEGRA_GPIO_PN4 */
#define MPU_ACCEL_ADDR		0x0F
#define MPU_ACCEL_BUS_NUM	0
#define MPU_ACCEL_ORIENTATION	{ 0, -1, 0, -1, 0, 0, 0, 0, -1 }
#define MPU_COMPASS_NAME	"ak8975"
#define MPU_COMPASS_IRQ_GPIO	TEGRA_GPIO_PN5
#define MPU_COMPASS_ADDR	0x0C
#define MPU_COMPASS_BUS_NUM	4
#define MPU_COMPASS_ORIENTATION	{ 1, 0, 0, 0, 1, 0, 0, 0, 1 }

#endif
