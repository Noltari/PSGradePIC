#if defined (WBOOTLOADERHID)
	#define BOOTLOADER_EXPORT	wBTL_HID
#elif defined (WBOOTLOADERMCHP)
	#define BOOTLOADER_EXPORT	wBTL_MCHP
#else
	#define BOOTLOADER_EXPORT	nBTL
#endif

#define FILE_EXPORT(btl) FILE=PSGradePIC_##btl.hex
#export (HEX, FILE_EXPORT(BOOTLOADER_EXPORT))

const unsigned int8 USB_DEVICE_DESC[] = {
	//HUB_DEVICE
		0x12, 0x01, 0x00, 0x02, 0x09, 0x00, 0x01, 0x08,
		0xAA, 0xAA, 0xCC, 0xCC, 0x00, 0x01, 0x00, 0x00,
		0x00, 0x01,
	//HUB_HUB_DEVICE
		0x09, 0x29, 0x06, 0xa9, 0x00, 0x32, 0x64, 0x00,
		0xff,
	//PORT5_DEVICE
		0x12, 0x01, 0x00, 0x02, 0x00, 0x00, 0x00, 0x08,
		0x4c, 0x05, 0xeb, 0x02, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x01,
};

const unsigned int8 USB_CONFIG_DESC[] = {
	//HUB_CONFIG
		// Config
		0x09, 0x02, 0x19, 0x00, 0x01, 0x01, 0x00, 0xe0,
		0x32,
		// Interface
		0x09, 0x04, 0x00, 0x00, 0x01, 0x09, 0x00, 0x00,
		0x00,
		// Endpoint (interrupt in)
		0x07, 0x05, 0x81, 0x03, 0x01, 0x00, 0x0c,
	//PORT5_CONFIG
		// config
		0x09, 0x02, 0x20, 0x00, 0x01, 0x00, 0x00, 0x80,
		0x01,
		// interface
		0x09, 0x04, 0x00, 0x00, 0x02, 0xff, 0x00, 0x00,
		0x00,
		// endpoint
		0x07, 0x05, 0x02, 0x02, 0x08, 0x00, 0x00,
		// endpoint
		0x07, 0x05, 0x81, 0x02, 0x08, 0x00, 0x00,
};

const unsigned int8 jig_key[20] = {
// RETAIL
	0x04, 0x4E, 0x61, 0x1B, 0xA6, 0xA6, 0xE3, 0x9A, 0x98, 0xCF,
	0x35, 0x81, 0x2C, 0x80, 0x68, 0xC7, 0xFC, 0x5F, 0x7A, 0xE8

// CEB / DEBUG / TEST
//	0x01, 0x23, 0x45, 0x67, 0x89, 0xAB, 0xCD, 0xEF, 0xFE, 0xDC,
//	0xBA, 0x98, 0x76, 0x54, 0x32, 0x10, 0xF0, 0xE1, 0xD2, 0xC3
};

const unsigned int8 jig_id [] = {0xaa, 0xaa};

static unsigned int8 jig_challenge_res[64];


#define HUB_DEVICE_SIZE				0x0012
#define HUB_HUB_DEVICE_SIZE			0x0009
#define PORT5_DEVICE_SIZE			0x0012

#define HUB_DEVICE_OFFSET			0x0000
#define HUB_HUB_DEVICE_OFFSET			HUB_DEVICE_SIZE
#define PORT5_DEVICE_OFFSET			HUB_HUB_DEVICE_OFFSET + HUB_HUB_DEVICE_SIZE

#define HUB_CONFIG_SIZE				0x0019
#define PORT5_CONFIG_SIZE			0x0020

#define HUB_CONFIG_OFFSET			0x0000
#define PORT5_CONFIG_OFFSET			HUB_CONFIG_SIZE
