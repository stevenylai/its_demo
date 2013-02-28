#define dbg(mode, format, ...) ((void)0)
#define dbg_clear(mode, format, ...) ((void)0)
#define dbg_active(mode) 0
# 60 "/usr/local/avr/include/inttypes.h"
typedef signed char int8_t;




typedef unsigned char uint8_t;
# 83 "/usr/local/avr/include/inttypes.h" 3
typedef int int16_t;




typedef unsigned int uint16_t;










typedef long int32_t;




typedef unsigned long uint32_t;
#line 117
typedef long long int64_t;




typedef unsigned long long uint64_t;
#line 134
typedef int16_t intptr_t;




typedef uint16_t uintptr_t;
# 213 "/usr/local/lib/gcc-lib/avr/3.3-tinyos/include/stddef.h" 3
typedef unsigned int size_t;
#line 325
typedef int wchar_t;
# 60 "/usr/local/avr/include/stdlib.h"
typedef struct __nesc_unnamed4242 {
  int quot;
  int rem;
} div_t;


typedef struct __nesc_unnamed4243 {
  long quot;
  long rem;
} ldiv_t;


typedef int (*__compar_fn_t)(const void *, const void *);
# 151 "/usr/local/lib/gcc-lib/avr/3.3-tinyos/include/stddef.h" 3
typedef int ptrdiff_t;
# 91 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/system/tos.h"
typedef unsigned char bool;






enum __nesc_unnamed4244 {
  FALSE = 0, 
  TRUE = 1
};

uint16_t TOS_LOCAL_ADDRESS = 1;

enum __nesc_unnamed4245 {
  FAIL = 0, 
  SUCCESS = 1
};
static inline 

uint8_t rcombine(uint8_t r1, uint8_t r2);
typedef uint8_t  result_t;
static inline 






result_t rcombine(result_t r1, result_t r2);
static inline 
#line 133
result_t rcombine4(result_t r1, result_t r2, result_t r3, 
result_t r4);





enum __nesc_unnamed4246 {
  NULL = 0x0
};
# 81 "/usr/local/avr/include/avr/pgmspace.h"
typedef void __attribute((__progmem__)) prog_void;
typedef char __attribute((__progmem__)) prog_char;
typedef unsigned char __attribute((__progmem__)) prog_uchar;
typedef int __attribute((__progmem__)) prog_int;
typedef long __attribute((__progmem__)) prog_long;
typedef long long __attribute((__progmem__)) prog_long_long;
# 82 "/usr/local/avr/include/avr/eeprom.h"
extern uint8_t eeprom_read_byte(uint8_t *addr);









extern void eeprom_write_byte(uint8_t *addr, uint8_t val);
# 139 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/avrmote/avrhardware.h"
enum __nesc_unnamed4247 {
  TOSH_period16 = 0x00, 
  TOSH_period32 = 0x01, 
  TOSH_period64 = 0x02, 
  TOSH_period128 = 0x03, 
  TOSH_period256 = 0x04, 
  TOSH_period512 = 0x05, 
  TOSH_period1024 = 0x06, 
  TOSH_period2048 = 0x07
};
static inline 
void TOSH_wait(void);







typedef uint8_t __nesc_atomic_t;

__nesc_atomic_t __nesc_atomic_start(void );
void __nesc_atomic_end(__nesc_atomic_t oldSreg);



__inline __nesc_atomic_t  __nesc_atomic_start(void );






__inline void  __nesc_atomic_end(__nesc_atomic_t oldSreg);
static 





__inline void __nesc_atomic_sleep(void);
static 






__inline void __nesc_enable_interrupt(void);
# 58 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/CC2420Radio/CC2420Const.h"
enum __nesc_unnamed4248 {
  CC2420_TIME_BIT = 4, 
  CC2420_TIME_BYTE = CC2420_TIME_BIT << 3, 
  CC2420_TIME_SYMBOL = 16
};










uint8_t CC2420_CHANNEL = 11;
uint8_t CC2420_RFPOWER = 0x1F;

enum __nesc_unnamed4249 {
  CC2420_MIN_CHANNEL = 11, 
  CC2420_MAX_CHANNEL = 26
};
#line 261
enum __nesc_unnamed4250 {
  CP_MAIN = 0, 
  CP_MDMCTRL0, 
  CP_MDMCTRL1, 
  CP_RSSI, 
  CP_SYNCWORD, 
  CP_TXCTRL, 
  CP_RXCTRL0, 
  CP_RXCTRL1, 
  CP_FSCTRL, 
  CP_SECCTRL0, 
  CP_SECCTRL1, 
  CP_BATTMON, 
  CP_IOCFG0, 
  CP_IOCFG1
};
static 
# 101 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/micaz/hardware.h"
void __inline TOSH_uwait(int u_sec);
#line 116
static __inline void TOSH_SET_RED_LED_PIN(void);
#line 116
static __inline void TOSH_CLR_RED_LED_PIN(void);
#line 116
static __inline void TOSH_MAKE_RED_LED_OUTPUT(void);
static __inline void TOSH_SET_GREEN_LED_PIN(void);
#line 117
static __inline void TOSH_CLR_GREEN_LED_PIN(void);
#line 117
static __inline void TOSH_MAKE_GREEN_LED_OUTPUT(void);
static __inline void TOSH_SET_YELLOW_LED_PIN(void);
#line 118
static __inline void TOSH_CLR_YELLOW_LED_PIN(void);
#line 118
static __inline void TOSH_MAKE_YELLOW_LED_OUTPUT(void);

static __inline void TOSH_CLR_SERIAL_ID_PIN(void);
#line 120
static __inline void TOSH_MAKE_SERIAL_ID_INPUT(void);
static 









void __inline CC2420_FIFOP_INT_MODE(bool LowToHigh);









static __inline void TOSH_SET_CC_RSTN_PIN(void);
#line 141
static __inline void TOSH_CLR_CC_RSTN_PIN(void);
#line 141
static __inline void TOSH_MAKE_CC_RSTN_OUTPUT(void);
static __inline void TOSH_SET_CC_VREN_PIN(void);
#line 142
static __inline void TOSH_MAKE_CC_VREN_OUTPUT(void);

static __inline int TOSH_READ_CC_FIFOP_PIN(void);
static __inline void TOSH_MAKE_CC_FIFOP1_INPUT(void);

static __inline int TOSH_READ_CC_CCA_PIN(void);
#line 147
static __inline void TOSH_MAKE_CC_CCA_INPUT(void);
static __inline int TOSH_READ_CC_SFD_PIN(void);
#line 148
static __inline void TOSH_MAKE_CC_SFD_INPUT(void);
static __inline void TOSH_SET_CC_CS_PIN(void);
#line 149
static __inline void TOSH_CLR_CC_CS_PIN(void);
#line 149
static __inline void TOSH_MAKE_CC_CS_OUTPUT(void);
#line 149
static __inline void TOSH_MAKE_CC_CS_INPUT(void);
static __inline int TOSH_READ_CC_FIFO_PIN(void);
#line 150
static __inline void TOSH_MAKE_CC_FIFO_INPUT(void);

static __inline int TOSH_READ_RADIO_CCA_PIN(void);
#line 152
static __inline void TOSH_MAKE_RADIO_CCA_INPUT(void);


static __inline void TOSH_SET_FLASH_SELECT_PIN(void);
#line 155
static __inline void TOSH_CLR_FLASH_SELECT_PIN(void);
#line 155
static __inline void TOSH_MAKE_FLASH_SELECT_OUTPUT(void);
static __inline void TOSH_SET_FLASH_CLK_PIN(void);
#line 156
static __inline void TOSH_CLR_FLASH_CLK_PIN(void);
#line 156
static __inline void TOSH_MAKE_FLASH_CLK_OUTPUT(void);
static __inline void TOSH_SET_FLASH_OUT_PIN(void);
#line 157
static __inline void TOSH_MAKE_FLASH_OUT_OUTPUT(void);
static __inline void TOSH_CLR_FLASH_IN_PIN(void);
#line 158
static __inline int TOSH_READ_FLASH_IN_PIN(void);
#line 158
static __inline void TOSH_MAKE_FLASH_IN_INPUT(void);



static __inline void TOSH_SET_INT1_PIN(void);
#line 162
static __inline void TOSH_CLR_INT1_PIN(void);
#line 162
static __inline void TOSH_MAKE_INT1_OUTPUT(void);
#line 162
static __inline void TOSH_MAKE_INT1_INPUT(void);




static __inline void TOSH_MAKE_MOSI_OUTPUT(void);
static __inline void TOSH_MAKE_MISO_INPUT(void);

static __inline void TOSH_MAKE_SPI_SCK_OUTPUT(void);


static __inline void TOSH_SET_PW0_PIN(void);
#line 173
static __inline void TOSH_CLR_PW0_PIN(void);
#line 173
static __inline void TOSH_MAKE_PW0_OUTPUT(void);
#line 173
static __inline void TOSH_MAKE_PW0_INPUT(void);
static __inline void TOSH_MAKE_PW1_OUTPUT(void);
static __inline void TOSH_SET_PW2_PIN(void);
#line 175
static __inline void TOSH_MAKE_PW2_OUTPUT(void);
static __inline void TOSH_MAKE_PW3_OUTPUT(void);
static __inline void TOSH_MAKE_PW4_OUTPUT(void);
static __inline void TOSH_MAKE_PW5_OUTPUT(void);
static __inline void TOSH_MAKE_PW6_OUTPUT(void);
static __inline void TOSH_MAKE_PW7_OUTPUT(void);
static inline 
#line 196
void TOSH_SET_PIN_DIRECTIONS(void );
#line 249
enum __nesc_unnamed4251 {
  TOSH_ADC_PORTMAPSIZE = 12
};

enum __nesc_unnamed4252 {


  TOSH_ACTUAL_BANDGAP_PORT = 30, 
  TOSH_ACTUAL_GND_PORT = 31
};

enum __nesc_unnamed4253 {


  TOS_ADC_BANDGAP_PORT = 10, 
  TOS_ADC_GND_PORT = 11
};
# 54 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/types/dbg_modes.h"
typedef long long TOS_dbg_mode;



enum __nesc_unnamed4254 {
  DBG_ALL = ~0ULL, 


  DBG_BOOT = 1ULL << 0, 
  DBG_CLOCK = 1ULL << 1, 
  DBG_TASK = 1ULL << 2, 
  DBG_SCHED = 1ULL << 3, 
  DBG_SENSOR = 1ULL << 4, 
  DBG_LED = 1ULL << 5, 
  DBG_CRYPTO = 1ULL << 6, 


  DBG_ROUTE = 1ULL << 7, 
  DBG_AM = 1ULL << 8, 
  DBG_CRC = 1ULL << 9, 
  DBG_PACKET = 1ULL << 10, 
  DBG_ENCODE = 1ULL << 11, 
  DBG_RADIO = 1ULL << 12, 


  DBG_LOG = 1ULL << 13, 
  DBG_ADC = 1ULL << 14, 
  DBG_I2C = 1ULL << 15, 
  DBG_UART = 1ULL << 16, 
  DBG_PROG = 1ULL << 17, 
  DBG_SOUNDER = 1ULL << 18, 
  DBG_TIME = 1ULL << 19, 
  DBG_POWER = 1ULL << 20, 



  DBG_SIM = 1ULL << 21, 
  DBG_QUEUE = 1ULL << 22, 
  DBG_SIMRADIO = 1ULL << 23, 
  DBG_HARD = 1ULL << 24, 
  DBG_MEM = 1ULL << 25, 



  DBG_USR1 = 1ULL << 27, 
  DBG_USR2 = 1ULL << 28, 
  DBG_USR3 = 1ULL << 29, 
  DBG_TEMP = 1ULL << 30, 

  DBG_ERROR = 1ULL << 31, 
  DBG_NONE = 0, 

  DBG_DEFAULT = DBG_ALL
};
# 59 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/system/sched.c"
typedef struct __nesc_unnamed4255 {
  void (*tp)(void);
} TOSH_sched_entry_T;

enum __nesc_unnamed4256 {






  TOSH_MAX_TASKS = 8, 

  TOSH_TASK_BITMASK = TOSH_MAX_TASKS - 1
};

volatile TOSH_sched_entry_T TOSH_queue[TOSH_MAX_TASKS];
uint8_t TOSH_sched_full;
volatile uint8_t TOSH_sched_free;
static inline 
void TOSH_sched_init(void );








bool TOS_post(void (*tp)(void));
#line 102
bool  TOS_post(void (*tp)(void));
static inline 
#line 136
bool TOSH_run_next_task(void);
static inline 
#line 159
void TOSH_run_task(void);
static 
# 149 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/system/tos.h"
void *nmemcpy(void *to, const void *from, size_t n);
static inline 








void *nmemset(void *to, int val, size_t n);
# 28 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/system/Ident.h"
enum __nesc_unnamed4257 {

  IDENT_MAX_PROGRAM_NAME_LENGTH = 16
};

typedef struct __nesc_unnamed4258 {

  uint32_t unix_time;
  uint32_t user_hash;
  char program_name[IDENT_MAX_PROGRAM_NAME_LENGTH];
} Ident_t;
#line 52
static const Ident_t G_Ident = { 
.unix_time = 0x4be61f5fL, 
.user_hash = 0x08e68161L, 
.program_name = "Blink" };
# 1 "OscopeMsg.h"
enum __nesc_unnamed4259 {
  BUFFER_SIZE = 5
};

struct OscopeMsg {

  uint8_t type;
  uint16_t sourceMoteID;
  uint16_t seqno;
  uint16_t channel;
  uint16_t data1;
  uint16_t data2;
  uint16_t data3;
  uint16_t data4;
};

struct OscopeResetMsg {

  uint16_t type;
  uint16_t interval;
  uint16_t light;
  uint16_t temp;
};


enum __nesc_unnamed4260 {
  AM_OSCOPEMSG = 10, 
  AM_OSCOPERESETMSG = 32
};
# 39 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/Timer.h"
enum __nesc_unnamed4261 {
  TIMER_REPEAT = 0, 
  TIMER_ONE_SHOT = 1, 
  NUM_TIMERS = 11
};
# 33 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/mica128/Clock.h"
enum __nesc_unnamed4262 {
  TOS_I1000PS = 32, TOS_S1000PS = 1, 
  TOS_I100PS = 40, TOS_S100PS = 2, 
  TOS_I10PS = 101, TOS_S10PS = 3, 
  TOS_I1024PS = 0, TOS_S1024PS = 3, 
  TOS_I512PS = 1, TOS_S512PS = 3, 
  TOS_I256PS = 3, TOS_S256PS = 3, 
  TOS_I128PS = 7, TOS_S128PS = 3, 
  TOS_I64PS = 15, TOS_S64PS = 3, 
  TOS_I32PS = 31, TOS_S32PS = 3, 
  TOS_I16PS = 63, TOS_S16PS = 3, 
  TOS_I8PS = 127, TOS_S8PS = 3, 
  TOS_I4PS = 255, TOS_S4PS = 3, 
  TOS_I2PS = 15, TOS_S2PS = 7, 
  TOS_I1PS = 31, TOS_S1PS = 7, 
  TOS_I0PS = 0, TOS_S0PS = 0
};
enum __nesc_unnamed4263 {
  DEFAULT_SCALE = 3, DEFAULT_INTERVAL = 127
};
# 31 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/avrmote/crc.h"
uint16_t __attribute((__progmem__)) crcTable[256] = { 
0x0000, 0x1021, 0x2042, 0x3063, 0x4084, 0x50a5, 0x60c6, 0x70e7, 
0x8108, 0x9129, 0xa14a, 0xb16b, 0xc18c, 0xd1ad, 0xe1ce, 0xf1ef, 
0x1231, 0x0210, 0x3273, 0x2252, 0x52b5, 0x4294, 0x72f7, 0x62d6, 
0x9339, 0x8318, 0xb37b, 0xa35a, 0xd3bd, 0xc39c, 0xf3ff, 0xe3de, 
0x2462, 0x3443, 0x0420, 0x1401, 0x64e6, 0x74c7, 0x44a4, 0x5485, 
0xa56a, 0xb54b, 0x8528, 0x9509, 0xe5ee, 0xf5cf, 0xc5ac, 0xd58d, 
0x3653, 0x2672, 0x1611, 0x0630, 0x76d7, 0x66f6, 0x5695, 0x46b4, 
0xb75b, 0xa77a, 0x9719, 0x8738, 0xf7df, 0xe7fe, 0xd79d, 0xc7bc, 
0x48c4, 0x58e5, 0x6886, 0x78a7, 0x0840, 0x1861, 0x2802, 0x3823, 
0xc9cc, 0xd9ed, 0xe98e, 0xf9af, 0x8948, 0x9969, 0xa90a, 0xb92b, 
0x5af5, 0x4ad4, 0x7ab7, 0x6a96, 0x1a71, 0x0a50, 0x3a33, 0x2a12, 
0xdbfd, 0xcbdc, 0xfbbf, 0xeb9e, 0x9b79, 0x8b58, 0xbb3b, 0xab1a, 
0x6ca6, 0x7c87, 0x4ce4, 0x5cc5, 0x2c22, 0x3c03, 0x0c60, 0x1c41, 
0xedae, 0xfd8f, 0xcdec, 0xddcd, 0xad2a, 0xbd0b, 0x8d68, 0x9d49, 
0x7e97, 0x6eb6, 0x5ed5, 0x4ef4, 0x3e13, 0x2e32, 0x1e51, 0x0e70, 
0xff9f, 0xefbe, 0xdfdd, 0xcffc, 0xbf1b, 0xaf3a, 0x9f59, 0x8f78, 
0x9188, 0x81a9, 0xb1ca, 0xa1eb, 0xd10c, 0xc12d, 0xf14e, 0xe16f, 
0x1080, 0x00a1, 0x30c2, 0x20e3, 0x5004, 0x4025, 0x7046, 0x6067, 
0x83b9, 0x9398, 0xa3fb, 0xb3da, 0xc33d, 0xd31c, 0xe37f, 0xf35e, 
0x02b1, 0x1290, 0x22f3, 0x32d2, 0x4235, 0x5214, 0x6277, 0x7256, 
0xb5ea, 0xa5cb, 0x95a8, 0x8589, 0xf56e, 0xe54f, 0xd52c, 0xc50d, 
0x34e2, 0x24c3, 0x14a0, 0x0481, 0x7466, 0x6447, 0x5424, 0x4405, 
0xa7db, 0xb7fa, 0x8799, 0x97b8, 0xe75f, 0xf77e, 0xc71d, 0xd73c, 
0x26d3, 0x36f2, 0x0691, 0x16b0, 0x6657, 0x7676, 0x4615, 0x5634, 
0xd94c, 0xc96d, 0xf90e, 0xe92f, 0x99c8, 0x89e9, 0xb98a, 0xa9ab, 
0x5844, 0x4865, 0x7806, 0x6827, 0x18c0, 0x08e1, 0x3882, 0x28a3, 
0xcb7d, 0xdb5c, 0xeb3f, 0xfb1e, 0x8bf9, 0x9bd8, 0xabbb, 0xbb9a, 
0x4a75, 0x5a54, 0x6a37, 0x7a16, 0x0af1, 0x1ad0, 0x2ab3, 0x3a92, 
0xfd2e, 0xed0f, 0xdd6c, 0xcd4d, 0xbdaa, 0xad8b, 0x9de8, 0x8dc9, 
0x7c26, 0x6c07, 0x5c64, 0x4c45, 0x3ca2, 0x2c83, 0x1ce0, 0x0cc1, 
0xef1f, 0xff3e, 0xcf5d, 0xdf7c, 0xaf9b, 0xbfba, 0x8fd9, 0x9ff8, 
0x6e17, 0x7e36, 0x4e55, 0x5e74, 0x2e93, 0x3eb2, 0x0ed1, 0x1ef0 };
static inline 

uint16_t crcByte(uint16_t oldCrc, uint8_t byte);
# 36 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/DelugeMetadata.h"
typedef int8_t dm_cmp_t;
typedef int16_t imgvnum_t;
typedef uint8_t imgnum_t;
typedef uint8_t pgnum_t;

typedef struct DelugeImgDesc {
  uint32_t uid;
  imgvnum_t vNum;
  imgnum_t imgNum;
  pgnum_t numPgs;
  uint16_t crc;
  uint8_t numPgsComplete;
  uint8_t reserved;
} DelugeImgDesc;
# 31 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/micaz/TOSBoot_platform.h"
enum __nesc_unnamed4264 {

  TOSBOOT_ARGS_ADDR = 0xff0, 

  TOSBOOT_GESTURE_MAX_COUNT = 3, 

  TOSBOOT_GOLDEN_IMG_ADDR = 0x0L, 

  TOSBOOT_INT_PAGE_SIZE = 256
};

enum __nesc_unnamed4265 {
  DELUGE_MIN_ADV_PERIOD_LOG2 = 9, 
  DELUGE_QSIZE = 2
};
# 33 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/TOSBoot.h"
typedef struct tosboot_args_t {
  uint32_t imageAddr;
  uint8_t gestureCount;
  bool noReprogram;
} tosboot_args_t;
# 41 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/Deluge.h"
enum __nesc_unnamed4266 {
  DELUGE_VERSION = 2, 
  DELUGE_MAX_ADV_PERIOD_LOG2 = 22, 
  DELUGE_NUM_NEWDATA_ADVS_REQUIRED = 2, 
  DELUGE_NUM_MIN_ADV_PERIODS = 2, 
  DELUGE_MAX_NUM_REQ_TRIES = 1, 
  DELUGE_REBOOT_DELAY = 4, 
  DELUGE_FAILED_SEND_DELAY = 16, 
  DELUGE_MIN_DELAY = 16, 
  DELUGE_PKTS_PER_PAGE = 48, 
  DELUGE_PKT_PAYLOAD_SIZE = 23, 
  DELUGE_DATA_OFFSET = 128, 
  DELUGE_IDENT_SIZE = 128, 
  DELUGE_INVALID_ADDR = 0x7fffffffL, 
  DELUGE_MAX_REQ_DELAY = 0x1L << (DELUGE_MIN_ADV_PERIOD_LOG2 - 1), 
  DELUGE_NACK_TIMEOUT = DELUGE_MAX_REQ_DELAY >> 0x1, 
  DELUGE_BYTES_PER_PAGE = DELUGE_PKTS_PER_PAGE * DELUGE_PKT_PAYLOAD_SIZE, 
  DELUGE_PKT_BITVEC_SIZE = (DELUGE_PKTS_PER_PAGE - 1) / 8 + 1, 
  DELUGE_MAX_IMAGE_SIZE = 128L * 1024L, 
  DELUGE_MAX_PAGES = 128, 
  DELUGE_CRC_SIZE = sizeof(uint16_t ), 
  DELUGE_CRC_BLOCK_SIZE = DELUGE_MAX_PAGES * DELUGE_CRC_SIZE, 
  DELUGE_GOLDEN_IMAGE_NUM = 0x0, 
  DELUGE_INVALID_VNUM = -1, 
  DELUGE_INVALID_IMGNUM = 0xff, 
  DELUGE_INVALID_PKTNUM = 0xff, 
  DELUGE_INVALID_PGNUM = 0xff
};
# 31 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/Storage.h"
enum __nesc_unnamed4267 {
  STORAGE_OK, 
  STORAGE_FAIL, 
  STORAGE_INVALID_SIGNATURE, 
  STORAGE_INVALID_CRC
};

enum __nesc_unnamed4268 {
  STORAGE_INVALID_ADDR = (uint32_t )0xffff
};

typedef uint8_t volume_t;
typedef uint8_t volume_id_t;
typedef uint8_t storage_result_t;
# 36 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/mica/PageEEPROM_platform.h"
enum __nesc_unnamed4269 {
  TOS_EEPROM_MAX_PAGES = 2048, 
  TOS_EEPROM_PAGE_SIZE = 264, 
  TOS_EEPROM_PAGE_SIZE_LOG2 = 8
};

typedef uint16_t eeprompage_t;
typedef uint16_t eeprompageoffset_t;
# 36 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/PageEEPROM.h"
enum __nesc_unnamed4270 {
  TOS_EEPROM_ERASE, 
  TOS_EEPROM_DONT_ERASE, 
  TOS_EEPROM_PREVIOUSLY_ERASED
};
# 8 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/HALAT45DB.h"
typedef eeprompage_t at45page_t;
typedef eeprompageoffset_t at45pageoffset_t;

enum __nesc_unnamed4271 {
  AT45_MAX_PAGES = TOS_EEPROM_MAX_PAGES, 
  AT45_PAGE_SIZE = TOS_EEPROM_PAGE_SIZE, 
  AT45_PAGE_SIZE_LOG2 = TOS_EEPROM_PAGE_SIZE_LOG2, 
  AT45_ERASE = TOS_EEPROM_ERASE, 
  AT45_DONT_ERASE = TOS_EEPROM_DONT_ERASE, 
  AT45_PREVIOUSLY_ERASED = TOS_EEPROM_PREVIOUSLY_ERASED
};
# 8 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/Storage_chip.h"
typedef uint32_t storage_addr_t;
# 72 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/Deluge.h"
struct deluge_image_t {
  imgnum_t imageNum;
  volume_id_t volumeId;
};

typedef struct DelugeAdvTimer {
  uint32_t timer : 32;
  uint8_t periodLog2 : 8;
  bool overheard : 1;
  uint8_t newAdvs : 7;
} DelugeAdvTimer;

typedef struct DelugeNodeDesc {
  imgvnum_t vNum;
  uint32_t uid;
  imgnum_t imgNum;
  uint8_t reserved;
  uint16_t crc;
} DelugeNodeDesc;

enum __nesc_unnamed4272 {
  DELUGE_VOLUME_ID_0 = 0, 

  DELUGE_VOLUME_ID_1 = 1, 

  DELUGE_VOLUME_ID_2 = 2
};
#line 117
static const struct deluge_image_t DELUGE_IMAGES[3] = { 
{ DELUGE_VOLUME_ID_0, 0xDF }, 

{ DELUGE_VOLUME_ID_1, 0xD0 }, 

{ DELUGE_VOLUME_ID_2, 0xD1 } };
# 37 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/DelugeMsgs.h"
enum __nesc_unnamed4273 {
  DELUGE_SHARED_MSG_BUF = 0
};

enum __nesc_unnamed4274 {
  AM_DELUGEADVMSG = 161, 
  AM_DELUGEREQMSG = 162, 
  AM_DELUGEDATAMSG = 163
};

enum __nesc_unnamed4275 {
  DELUGE_ADV_NORMAL = 0, 
  DELUGE_ADV_ERROR = 1, 
  DELUGE_ADV_PC = 2, 
  DELUGE_ADV_PING = 3, 
  DELUGE_ADV_RESET = 4
};

typedef struct DelugeAdvMsg {
  uint16_t sourceAddr;
  uint8_t version;
  uint8_t type;
  DelugeNodeDesc nodeDesc;
  DelugeImgDesc imgDesc;
  uint8_t numImages;
  uint8_t reserved;
} DelugeAdvMsg;

typedef struct DelugeReqMsg {
  uint16_t dest;
  uint16_t sourceAddr;
  imgvnum_t vNum;
  imgnum_t imgNum;
  pgnum_t pgNum;
  uint8_t requestedPkts[DELUGE_PKT_BITVEC_SIZE];
} DelugeReqMsg;

typedef struct DelugeDataMsg {
  imgvnum_t vNum;
  imgnum_t imgNum;
  pgnum_t pgNum;
  uint8_t pktNum;
  uint8_t data[DELUGE_PKT_PAYLOAD_SIZE];
} DelugeDataMsg;
# 34 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/mica2/NetProg_platform.h"
enum __nesc_unnamed4276 {
  IFLASH_TOS_INFO_ADDR = 0xfe0, 
  IFLASH_NODE_DESC_ADDR = 0xfe6
};
static inline 
void netprog_reboot(void);
# 42 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/NetProg.h"
typedef struct NetProg_TOSInfo {
  uint16_t addr;
  uint8_t groupId;
  uint16_t crc;
} NetProg_TOSInfo;
# 50 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/micaz/AM.h"
enum __nesc_unnamed4277 {
  TOS_BCAST_ADDR = 0xffff, 
  TOS_UART_ADDR = 0x007e
};
#line 66
enum __nesc_unnamed4278 {
  TOS_DEFAULT_AM_GROUP = 0x7d
};

uint8_t TOS_AM_GROUP = TOS_DEFAULT_AM_GROUP;
#line 92
typedef struct TOS_Msg {


  uint8_t length;
  uint8_t fcfhi;
  uint8_t fcflo;
  uint8_t dsn;
  uint16_t destpan;
  uint16_t addr;
  uint8_t type;
  uint8_t group;
  int8_t data[29];







  uint8_t strength;
  uint8_t lqi;
  bool crc;
  uint8_t ack;
  uint16_t time;
} TOS_Msg;

typedef struct TinySec_Msg {

  uint8_t invalid;
} TinySec_Msg;







enum __nesc_unnamed4279 {

  MSG_HEADER_SIZE = (size_t )& ((struct TOS_Msg *)0)->data - 1, 

  MSG_FOOTER_SIZE = 2, 

  MSG_DATA_SIZE = (size_t )& ((struct TOS_Msg *)0)->strength + sizeof(uint16_t ), 

  DATA_LENGTH = 29, 

  LENGTH_BYTE_NUMBER = (size_t )& ((struct TOS_Msg *)0)->length + 1, 

  TOS_HEADER_SIZE = 5
};

typedef TOS_Msg *TOS_MsgPtr;
# 31 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/BlockStorage.h"
typedef uint32_t block_addr_t;
typedef uint8_t blockstorage_t;
# 4 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/StorageManager.h"
struct volume_definition_header_t {

  uint16_t crc;
  uint8_t nvolumes;
};

struct volume_definition_t {

  volume_id_t id;
  at45page_t start, length;
};

enum __nesc_unnamed4280 {
  INVALID_VOLUME_ID = 0, 
  VOLUME_TABLE_SIZE = AT45_PAGE_SIZE, 
  VOLUME_TABLE_PAGE = AT45_MAX_PAGES - 1, 
  MAX_VOLUMES = (VOLUME_TABLE_SIZE - sizeof(struct volume_definition_header_t )) / sizeof(struct volume_definition_t )
};
# 34 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/NetProgMsgs.h"
enum __nesc_unnamed4281 {
  AM_NETPROGMSG = 164
};

typedef struct NetProgMsg {
  Ident_t ident;
  uint16_t sourceAddr;
} NetProgMsg;
static 
# 12 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/CC2420Radio/byteorder.h"
__inline int is_host_lsb(void);
static 




__inline uint16_t toLSB16(uint16_t a);
static 



__inline uint16_t fromLSB16(uint16_t a);
# 31 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/micaz/HPLTimer1.h"
enum __nesc_unnamed4282 {
  TCLK_CPU_OFF = 0, 
  TCLK_CPU_DIV1 = 1, 
  TCLK_CPU_DIV8 = 2, 
  TCLK_CPU_DIV64 = 3, 
  TCLK_CPU_DIV256 = 4, 
  TCLK_CPU_DIV1024 = 5
};
enum __nesc_unnamed4283 {
  TIMER1_DEFAULT_SCALE = TCLK_CPU_DIV64, 
  TIMER1_DEFAULT_INTERVAL = 255
};
# 45 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/sensorboards/micasb/sensorboard.h"
enum __nesc_unnamed4284 {
  TOSH_ACTUAL_PHOTO_PORT = 1, 
  TOSH_ACTUAL_TEMP_PORT = 1, 
  TOSH_ACTUAL_MIC_PORT = 2, 
  TOSH_ACTUAL_ACCEL_X_PORT = 3, 
  TOSH_ACTUAL_ACCEL_Y_PORT = 4, 
  TOSH_ACTUAL_MAG_X_PORT = 6, 
  TOSH_ACTUAL_MAG_Y_PORT = 5
};

enum __nesc_unnamed4285 {
  TOS_ADC_PHOTO_PORT = 1, 
  TOS_ADC_TEMP_PORT = 2, 
  TOS_ADC_MIC_PORT = 3, 
  TOS_ADC_ACCEL_X_PORT = 4, 
  TOS_ADC_ACCEL_Y_PORT = 5, 
  TOS_ADC_MAG_X_PORT = 6, 

  TOS_ADC_MAG_Y_PORT = 8
};

enum __nesc_unnamed4286 {
  TOS_MAG_POT_ADDR = 0, 
  TOS_MIC_POT_ADDR = 1
};



static __inline void TOSH_SET_PHOTO_CTL_PIN(void);
#line 73
static __inline void TOSH_CLR_PHOTO_CTL_PIN(void);
#line 73
static __inline void TOSH_MAKE_PHOTO_CTL_OUTPUT(void);
#line 73
static __inline void TOSH_MAKE_PHOTO_CTL_INPUT(void);

static __inline void TOSH_SET_TEMP_CTL_PIN(void);
#line 75
static __inline void TOSH_CLR_TEMP_CTL_PIN(void);
#line 75
static __inline void TOSH_MAKE_TEMP_CTL_OUTPUT(void);
#line 75
static __inline void TOSH_MAKE_TEMP_CTL_INPUT(void);
# 35 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/ADC.h"
enum __nesc_unnamed4287 {
  TOS_ADCSample3750ns = 0, 
  TOS_ADCSample7500ns = 1, 
  TOS_ADCSample15us = 2, 
  TOS_ADCSample30us = 3, 
  TOS_ADCSample60us = 4, 
  TOS_ADCSample120us = 5, 
  TOS_ADCSample240us = 6, 
  TOS_ADCSample480us = 7
};
# 34 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/micaz/Voltage.h"
enum __nesc_unnamed4288 {
  TOS_ADC_VOLTAGE_PORT = 7, 
  TOSH_ACTUAL_VOLTAGE_PORT = 30
};
static  result_t PotM$Pot$init(uint8_t arg_0xa2f4d98);
static  result_t HPLPotC$Pot$finalise(void);
static  result_t HPLPotC$Pot$decrease(void);
static  result_t HPLPotC$Pot$increase(void);
static  result_t HPLInit$init(void);
static  result_t BlinkM$App$start(void);
static  result_t BlinkM$App$stop(void);
static  result_t BlinkM$StdControl$init(void);
static  result_t BlinkM$StdControl$start(void);
static  result_t BlinkM$Timer$fired(void);
static   result_t TimerM$Clock$fire(void);
static  result_t TimerM$StdControl$init(void);
static  result_t TimerM$StdControl$start(void);
static  result_t TimerM$Timer$default$fired(uint8_t arg_0xa34ee80);
static  result_t TimerM$Timer$start(uint8_t arg_0xa34ee80, char arg_0xa344320, uint32_t arg_0xa344478);
static  result_t TimerM$Timer$stop(uint8_t arg_0xa34ee80);
static   void HPLClock$Clock$setInterval(uint8_t arg_0xa3734e8);
static   uint8_t HPLClock$Clock$readCounter(void);
static   result_t HPLClock$Clock$setRate(char arg_0xa3729e8, char arg_0xa372b28);
static   uint8_t HPLClock$Clock$getInterval(void);
static   result_t NoLeds$Leds$yellowOff(void);
static   result_t NoLeds$Leds$yellowOn(void);
static   result_t NoLeds$Leds$init(void);
static   result_t NoLeds$Leds$redOff(void);
static   result_t NoLeds$Leds$greenToggle(void);
static   result_t NoLeds$Leds$set(uint8_t arg_0xa3426c8);
static   result_t NoLeds$Leds$redOn(void);
static   uint8_t HPLPowerManagementM$PowerManagement$adjustPower(void);
static   result_t LedsC$Leds$yellowOff(void);
static   result_t LedsC$Leds$yellowOn(void);
static   result_t LedsC$Leds$init(void);
static   result_t LedsC$Leds$greenOff(void);
static   result_t LedsC$Leds$redOff(void);
static   result_t LedsC$Leds$yellowToggle(void);
static   result_t LedsC$Leds$redOn(void);
static   result_t LedsC$Leds$greenOn(void);
static  result_t BitVecUtilsC$BitVecUtils$indexOf(uint16_t *arg_0xa407798, uint16_t arg_0xa4078f0, uint8_t *arg_0xa407a60, uint16_t arg_0xa407bb0);
static  uint16_t CrcC$Crc$crc16(void *arg_0xa448f60, uint8_t arg_0xa4490a8);
static  result_t DelugeM$SendAdvMsg$sendDone(TOS_MsgPtr arg_0xa46fc60, result_t arg_0xa46fdb0);
static  void DelugeM$PageTransfer$suppressMsgs(imgnum_t arg_0xa468788);
static  void DelugeM$PageTransfer$receivedPage(imgnum_t arg_0xa468238, pgnum_t arg_0xa468380);
static  void DelugeM$SharedMsgBuf$bufFree(void);
static  TOS_MsgPtr DelugeM$ReceiveAdvMsg$receive(TOS_MsgPtr arg_0xa485df0);
static  result_t DelugeM$MetadataControl$startDone(void);
static  result_t DelugeM$StdControl$init(void);
static  result_t DelugeM$StdControl$start(void);
static  void DelugeM$Metadata$updateDone(result_t arg_0xa459e48);
static  result_t DelugeM$Timer$fired(void);
static  result_t DelugeMetadataM$SplitControl$init(void);
static  result_t DelugeMetadataM$SplitControl$start(void);
static  void DelugeMetadataM$MetadataStore$writeDone(storage_result_t arg_0xa4da060);
static  void DelugeMetadataM$MetadataStore$readDone(storage_result_t arg_0xa4c96d8);
static  imgvnum_t DelugeMetadataM$DelugeStats$getVNum(imgnum_t arg_0xa4b9578);
static  pgnum_t DelugeMetadataM$DelugeStats$getNumPgsComplete(imgnum_t arg_0xa4b9170);
static  void DelugeMetadataM$DataRead$verifyDone(storage_result_t arg_0xa4d6720, bool arg_0xa4d6868);
static  void DelugeMetadataM$DataRead$readDone(storage_result_t arg_0xa4dbd98);
static  void DelugeMetadataM$FlashWP$setWPDone(void);
static  void DelugeMetadataM$FlashWP$clrWPDone(void);
static  result_t DelugeMetadataM$Timer$fired(void);
static  void DelugeMetadataM$DataWrite$writeDone(storage_result_t arg_0xa4d2580);
static  void DelugeMetadataM$DataWrite$eraseDone(storage_result_t arg_0xa4d2d90);
static  void DelugeMetadataM$DataWrite$commitDone(storage_result_t arg_0xa4d35a0);
static  void DelugeMetadataM$DelugeStorage$loadImagesDone(result_t arg_0xa4d5b38);
static  result_t DelugeMetadataM$Metadata$receivedPage(imgnum_t arg_0xa4598f8, pgnum_t arg_0xa459a40);
static  bool DelugeMetadataM$Metadata$isImgDescValid(DelugeImgDesc *arg_0xa458c98);
static  DelugeImgDesc *DelugeMetadataM$Metadata$getImgDesc(imgnum_t arg_0xa4590a8);
static  result_t DelugeMetadataM$Metadata$setupNewImage(DelugeImgDesc *arg_0xa4594e8);
static  result_t DelugeStorageM$DataRead$read(imgnum_t arg_0xa4db580, block_addr_t arg_0xa4db6d0, void *arg_0xa4db828, uint16_t arg_0xa4db978);
static  result_t DelugeStorageM$DataRead$verify(imgnum_t arg_0xa4d61c8, pgnum_t arg_0xa4d6310);
static  uint32_t DelugeStorageM$StorageRemap$default$physicalAddr(blockstorage_t arg_0xa537660, uint32_t arg_0xa538488);
static  void DelugeStorageM$BlockRead$verifyDone(blockstorage_t arg_0xa528458, storage_result_t arg_0xa526410);
static  result_t DelugeStorageM$BlockRead$default$read(blockstorage_t arg_0xa528458, block_addr_t arg_0xa529268, void *arg_0xa5293c0, block_addr_t arg_0xa529510);
static  void DelugeStorageM$BlockRead$computeCrcDone(blockstorage_t arg_0xa528458, storage_result_t arg_0xa526d80, uint16_t arg_0xa526ed0, block_addr_t arg_0xa527020, block_addr_t arg_0xa527170);
static  result_t DelugeStorageM$BlockRead$default$computeCrc(blockstorage_t arg_0xa528458, block_addr_t arg_0xa526820, block_addr_t arg_0xa526970);
static  void DelugeStorageM$BlockRead$readDone(blockstorage_t arg_0xa528458, storage_result_t arg_0xa529928, block_addr_t arg_0xa529a78, void *arg_0xa529bd0, block_addr_t arg_0xa529d20);
static  void DelugeStorageM$BlockWrite$writeDone(blockstorage_t arg_0xa527ef0, storage_result_t arg_0xa50b400, block_addr_t arg_0xa50b550, void *arg_0xa50b6a8, block_addr_t arg_0xa50b7f8);
static  result_t DelugeStorageM$BlockWrite$default$erase(blockstorage_t arg_0xa527ef0);
static  void DelugeStorageM$BlockWrite$eraseDone(blockstorage_t arg_0xa527ef0, storage_result_t arg_0xa50bec8);
static  result_t DelugeStorageM$BlockWrite$default$commit(blockstorage_t arg_0xa527ef0);
static  result_t DelugeStorageM$BlockWrite$default$write(blockstorage_t arg_0xa527ef0, block_addr_t arg_0xa50ad40, void *arg_0xa50ae98, block_addr_t arg_0xa50afe8);
static  void DelugeStorageM$BlockWrite$commitDone(blockstorage_t arg_0xa527ef0, storage_result_t arg_0xa53a5a0);
static  result_t DelugeStorageM$Mount$default$mount(blockstorage_t arg_0xa53afa0, volume_id_t arg_0xa5369b8);
static  void DelugeStorageM$Mount$mountDone(blockstorage_t arg_0xa53afa0, storage_result_t arg_0xa536dc0, volume_id_t arg_0xa536f10);
static  uint32_t DelugeStorageM$DelugeStorage$imgNum2Addr(imgnum_t arg_0xa4d5f48);
static  result_t DelugeStorageM$DelugeStorage$loadImages(void);
static  result_t DelugeStorageM$DataWrite$erase(imgnum_t arg_0xa4d2988);
static  result_t DelugeStorageM$DataWrite$commit(imgnum_t arg_0xa4d3198);
static  result_t DelugeStorageM$DataWrite$write(imgnum_t arg_0xa4d7d58, block_addr_t arg_0xa4d7ea8, void *arg_0xa4d2010, uint16_t arg_0xa4d2160);
static  result_t DelugeStorageM$MetadataStore$read(imgnum_t arg_0xa4c9170, void *arg_0xa4c92c8);
static  result_t DelugeStorageM$MetadataStore$write(imgnum_t arg_0xa4c9ae0, void *arg_0xa4c9c38);
static  result_t BlockStorageM$PageEEPROM$syncDone(blockstorage_t arg_0xa571d00, result_t arg_0xa56b498);
static  result_t BlockStorageM$PageEEPROM$flushDone(blockstorage_t arg_0xa571d00, result_t arg_0xa568010);
static  result_t BlockStorageM$PageEEPROM$writeDone(blockstorage_t arg_0xa571d00, result_t arg_0xa56a060);
static  result_t BlockStorageM$PageEEPROM$eraseDone(blockstorage_t arg_0xa571d00, result_t arg_0xa56a9d0);
static  result_t BlockStorageM$PageEEPROM$computeCrcDone(blockstorage_t arg_0xa571d00, result_t arg_0xa566030, uint16_t arg_0xa566180);
static  result_t BlockStorageM$PageEEPROM$readDone(blockstorage_t arg_0xa571d00, result_t arg_0xa568c58);
static  void BlockStorageM$ActualMount$mountDone(blockstorage_t arg_0xa567268, storage_result_t arg_0xa536dc0, volume_id_t arg_0xa536f10);
static  void BlockStorageM$BlockWrite$default$writeDone(blockstorage_t arg_0xa570b10, storage_result_t arg_0xa50b400, block_addr_t arg_0xa50b550, void *arg_0xa50b6a8, block_addr_t arg_0xa50b7f8);
static  result_t BlockStorageM$BlockWrite$erase(blockstorage_t arg_0xa570b10);
static  void BlockStorageM$BlockWrite$default$eraseDone(blockstorage_t arg_0xa570b10, storage_result_t arg_0xa50bec8);
static  result_t BlockStorageM$BlockWrite$commit(blockstorage_t arg_0xa570b10);
static  result_t BlockStorageM$BlockWrite$write(blockstorage_t arg_0xa570b10, block_addr_t arg_0xa50ad40, void *arg_0xa50ae98, block_addr_t arg_0xa50afe8);
static  void BlockStorageM$BlockWrite$default$commitDone(blockstorage_t arg_0xa570b10, storage_result_t arg_0xa53a5a0);
static  result_t BlockStorageM$Mount$mount(blockstorage_t arg_0xa570550, volume_id_t arg_0xa5369b8);
static  void BlockStorageM$Mount$default$mountDone(blockstorage_t arg_0xa570550, storage_result_t arg_0xa536dc0, volume_id_t arg_0xa536f10);
static  void BlockStorageM$BlockRead$default$verifyDone(blockstorage_t arg_0xa571390, storage_result_t arg_0xa526410);
static  result_t BlockStorageM$BlockRead$read(blockstorage_t arg_0xa571390, block_addr_t arg_0xa529268, void *arg_0xa5293c0, block_addr_t arg_0xa529510);
static  void BlockStorageM$BlockRead$default$computeCrcDone(blockstorage_t arg_0xa571390, storage_result_t arg_0xa526d80, uint16_t arg_0xa526ed0, block_addr_t arg_0xa527020, block_addr_t arg_0xa527170);
static  result_t BlockStorageM$BlockRead$computeCrc(blockstorage_t arg_0xa571390, block_addr_t arg_0xa526820, block_addr_t arg_0xa526970);
static  void BlockStorageM$BlockRead$default$readDone(blockstorage_t arg_0xa571390, storage_result_t arg_0xa529928, block_addr_t arg_0xa529a78, void *arg_0xa529bd0, block_addr_t arg_0xa529d20);
static  at45page_t StorageManagerM$AT45Remap$remap(volume_t arg_0xa5630a8, at45page_t arg_0xa563200);
static  result_t StorageManagerM$PageEEPROM$syncDone(result_t arg_0xa56b498);
static  result_t StorageManagerM$PageEEPROM$flushDone(result_t arg_0xa568010);
static  result_t StorageManagerM$PageEEPROM$writeDone(result_t arg_0xa56a060);
static  result_t StorageManagerM$PageEEPROM$eraseDone(result_t arg_0xa56a9d0);
static  result_t StorageManagerM$PageEEPROM$computeCrcDone(result_t arg_0xa566030, uint16_t arg_0xa566180);
static  result_t StorageManagerM$PageEEPROM$readDone(result_t arg_0xa568c58);
static  result_t StorageManagerM$Mount$mount(volume_t arg_0xa5aac10, volume_id_t arg_0xa5369b8);
static  result_t StorageManagerM$StdControl$init(void);
static  result_t StorageManagerM$StdControl$start(void);
static  uint32_t StorageManagerM$StorageRemap$physicalAddr(volume_t arg_0xa5ab1d0, uint32_t arg_0xa538488);
static  result_t PageEEPROMM$PageEEPROM$read(eeprompage_t arg_0xa568418, eeprompageoffset_t arg_0xa568570, void *arg_0xa5686d8, eeprompageoffset_t arg_0xa568830);
static  result_t PageEEPROMM$PageEEPROM$erase(eeprompage_t arg_0xa56a468, uint8_t arg_0xa56a5b8);
static  result_t PageEEPROMM$PageEEPROM$computeCrcContinue(eeprompage_t arg_0xa5697d0, eeprompageoffset_t arg_0xa569928, eeprompageoffset_t arg_0xa569a90, uint16_t arg_0xa569be0);
static  result_t PageEEPROMM$PageEEPROM$syncAll(void);
static  result_t PageEEPROMM$PageEEPROM$write(eeprompage_t arg_0xa5537f8, eeprompageoffset_t arg_0xa553950, void *arg_0xa553ab8, eeprompageoffset_t arg_0xa553c10);
static  result_t PageEEPROMM$PageEEPROM$computeCrc(eeprompage_t arg_0xa569068, eeprompageoffset_t arg_0xa5691c0, eeprompageoffset_t arg_0xa569328);
static  result_t PageEEPROMM$FlashSelect$notifyHigh(void);
static  result_t PageEEPROMM$StdControl$init(void);
static  result_t PageEEPROMM$StdControl$start(void);
static  result_t PageEEPROMM$FlashIdle$available(void);
static  result_t PageEEPROMShare$PageEEPROM$default$syncDone(uint8_t arg_0xa5db170, result_t arg_0xa56b498);
static  result_t PageEEPROMShare$PageEEPROM$default$flushDone(uint8_t arg_0xa5db170, result_t arg_0xa568010);
static  result_t PageEEPROMShare$PageEEPROM$read(uint8_t arg_0xa5db170, eeprompage_t arg_0xa568418, eeprompageoffset_t arg_0xa568570, void *arg_0xa5686d8, eeprompageoffset_t arg_0xa568830);
static  result_t PageEEPROMShare$PageEEPROM$default$writeDone(uint8_t arg_0xa5db170, result_t arg_0xa56a060);
static  result_t PageEEPROMShare$PageEEPROM$erase(uint8_t arg_0xa5db170, eeprompage_t arg_0xa56a468, uint8_t arg_0xa56a5b8);
static  result_t PageEEPROMShare$PageEEPROM$computeCrcContinue(uint8_t arg_0xa5db170, eeprompage_t arg_0xa5697d0, eeprompageoffset_t arg_0xa569928, eeprompageoffset_t arg_0xa569a90, uint16_t arg_0xa569be0);
static  result_t PageEEPROMShare$PageEEPROM$default$eraseDone(uint8_t arg_0xa5db170, result_t arg_0xa56a9d0);
static  result_t PageEEPROMShare$PageEEPROM$default$computeCrcDone(uint8_t arg_0xa5db170, result_t arg_0xa566030, uint16_t arg_0xa566180);
static  result_t PageEEPROMShare$PageEEPROM$syncAll(uint8_t arg_0xa5db170);
static  result_t PageEEPROMShare$PageEEPROM$write(uint8_t arg_0xa5db170, eeprompage_t arg_0xa5537f8, eeprompageoffset_t arg_0xa553950, void *arg_0xa553ab8, eeprompageoffset_t arg_0xa553c10);
static  result_t PageEEPROMShare$PageEEPROM$computeCrc(uint8_t arg_0xa5db170, eeprompage_t arg_0xa569068, eeprompageoffset_t arg_0xa5691c0, eeprompageoffset_t arg_0xa569328);
static  result_t PageEEPROMShare$PageEEPROM$default$readDone(uint8_t arg_0xa5db170, result_t arg_0xa568c58);
static  result_t PageEEPROMShare$ActualEEPROM$syncDone(result_t arg_0xa56b498);
static  result_t PageEEPROMShare$ActualEEPROM$flushDone(result_t arg_0xa568010);
static  result_t PageEEPROMShare$ActualEEPROM$writeDone(result_t arg_0xa56a060);
static  result_t PageEEPROMShare$ActualEEPROM$eraseDone(result_t arg_0xa56a9d0);
static  result_t PageEEPROMShare$ActualEEPROM$computeCrcDone(result_t arg_0xa566030, uint16_t arg_0xa566180);
static  result_t PageEEPROMShare$ActualEEPROM$readDone(result_t arg_0xa568c58);
static  bool HPLFlash$getCompareStatus(void);
static   result_t HPLFlash$FlashSelect$low(void);
static   result_t HPLFlash$FlashSelect$high(bool arg_0xa5ec1c8);
static  result_t HPLFlash$FlashControl$init(void);
static  result_t HPLFlash$FlashControl$start(void);
static   uint8_t HPLFlash$FlashSPI$txByte(uint8_t arg_0xa5edb20);
static  result_t HPLFlash$FlashIdle$wait(void);
static  result_t HALAT45DBShare$PageEEPROM$read(volume_t arg_0xa644fa0, eeprompage_t arg_0xa568418, eeprompageoffset_t arg_0xa568570, void *arg_0xa5686d8, eeprompageoffset_t arg_0xa568830);
static  result_t HALAT45DBShare$PageEEPROM$erase(volume_t arg_0xa644fa0, eeprompage_t arg_0xa56a468, uint8_t arg_0xa56a5b8);
static  result_t HALAT45DBShare$PageEEPROM$computeCrcContinue(volume_t arg_0xa644fa0, eeprompage_t arg_0xa5697d0, eeprompageoffset_t arg_0xa569928, eeprompageoffset_t arg_0xa569a90, uint16_t arg_0xa569be0);
static  result_t HALAT45DBShare$PageEEPROM$syncAll(volume_t arg_0xa644fa0);
static  result_t HALAT45DBShare$PageEEPROM$write(volume_t arg_0xa644fa0, eeprompage_t arg_0xa5537f8, eeprompageoffset_t arg_0xa553950, void *arg_0xa553ab8, eeprompageoffset_t arg_0xa553c10);
static  result_t HALAT45DBShare$PageEEPROM$computeCrc(volume_t arg_0xa644fa0, eeprompage_t arg_0xa569068, eeprompageoffset_t arg_0xa5691c0, eeprompageoffset_t arg_0xa569328);
static  result_t HALAT45DBShare$ActualAT45$syncDone(result_t arg_0xa56b498);
static  result_t HALAT45DBShare$ActualAT45$flushDone(result_t arg_0xa568010);
static  result_t HALAT45DBShare$ActualAT45$writeDone(result_t arg_0xa56a060);
static  result_t HALAT45DBShare$ActualAT45$eraseDone(result_t arg_0xa56a9d0);
static  result_t HALAT45DBShare$ActualAT45$computeCrcDone(result_t arg_0xa566030, uint16_t arg_0xa566180);
static  result_t HALAT45DBShare$ActualAT45$readDone(result_t arg_0xa568c58);
static  result_t InternalFlashC$InternalFlash$read(void *arg_0xa464e98, void *arg_0xa464ff0, uint16_t arg_0xa465140);
static  result_t InternalFlashC$InternalFlash$write(void *arg_0xa4647d0, void *arg_0xa464928, uint16_t arg_0xa464a78);
static  result_t FlashWPC$FlashWP$setWP(void);
static  result_t FlashWPC$FlashWP$clrWP(void);
static  result_t FlashWPC$StdControl$init(void);
static  result_t FlashWPC$StdControl$start(void);
static  void DelugePageTransferM$DataRead$verifyDone(storage_result_t arg_0xa4d6720, bool arg_0xa4d6868);
static  void DelugePageTransferM$DataRead$readDone(storage_result_t arg_0xa4dbd98);
static  result_t DelugePageTransferM$PageTransfer$dataAvailable(uint16_t arg_0xa453cc0, imgnum_t arg_0xa453e10);
static  bool DelugePageTransferM$PageTransfer$isTransferring(void);
static  result_t DelugePageTransferM$PageTransfer$setWorkingPage(imgnum_t arg_0xa4534a8, pgnum_t arg_0xa4535f0);
static  void DelugePageTransferM$SharedMsgBuf$bufFree(void);
static  result_t DelugePageTransferM$SendReqMsg$sendDone(TOS_MsgPtr arg_0xa46fc60, result_t arg_0xa46fdb0);
static  TOS_MsgPtr DelugePageTransferM$ReceiveReqMsg$receive(TOS_MsgPtr arg_0xa485df0);
static  TOS_MsgPtr DelugePageTransferM$ReceiveDataMsg$receive(TOS_MsgPtr arg_0xa485df0);
static  result_t DelugePageTransferM$SendDataMsg$sendDone(TOS_MsgPtr arg_0xa46fc60, result_t arg_0xa46fdb0);
static  void DelugePageTransferM$DataWrite$writeDone(storage_result_t arg_0xa4d2580);
static  void DelugePageTransferM$DataWrite$eraseDone(storage_result_t arg_0xa4d2d90);
static  void DelugePageTransferM$DataWrite$commitDone(storage_result_t arg_0xa4d35a0);
static  result_t DelugePageTransferM$StdControl$init(void);
static  result_t DelugePageTransferM$StdControl$start(void);
static  result_t DelugePageTransferM$Timer$fired(void);
static   uint16_t RandomLFSR$Random$rand(void);
static   result_t RandomLFSR$Random$init(void);
static  result_t NetProgM$NetProg$programImgAndReboot(uint8_t arg_0xa45e840);
static  void NetProgM$Storage$loadImagesDone(result_t arg_0xa4d5b38);
static  TOS_MsgPtr NetProgM$ReceiveMsg$receive(TOS_MsgPtr arg_0xa485df0);
static  void NetProgM$SharedMsgBuf$bufFree(void);
static  result_t NetProgM$MetadataControl$startDone(void);
static  result_t NetProgM$SendMsg$sendDone(TOS_MsgPtr arg_0xa46fc60, result_t arg_0xa46fdb0);
static  result_t NetProgM$StdControl$init(void);
static  result_t NetProgM$StdControl$start(void);
static  void SharedMsgBufM$SharedMsgBuf$unlock(void);
static  void SharedMsgBufM$SharedMsgBuf$lock(void);
static  bool SharedMsgBufM$SharedMsgBuf$isLocked(void);
static  TOS_MsgPtr SharedMsgBufM$SharedMsgBuf$getMsgBuf(void);
static  TOS_MsgPtr AMStandard$ReceiveMsg$default$receive(uint8_t arg_0xa726b68, TOS_MsgPtr arg_0xa485df0);
static  result_t AMStandard$ActivityTimer$fired(void);
static  result_t AMStandard$UARTSend$sendDone(TOS_MsgPtr arg_0xa71ecc8, result_t arg_0xa71ee18);
static  TOS_MsgPtr AMStandard$RadioReceive$receive(TOS_MsgPtr arg_0xa485df0);
static  result_t AMStandard$Control$init(void);
static  result_t AMStandard$Control$start(void);
static  result_t AMStandard$default$sendDone(void);
static  result_t AMStandard$RadioSend$sendDone(TOS_MsgPtr arg_0xa71ecc8, result_t arg_0xa71ee18);
static  result_t AMStandard$SendMsg$send(uint8_t arg_0xa7265b0, uint16_t arg_0xa46f5a8, uint8_t arg_0xa46f6f0, TOS_MsgPtr arg_0xa46f840);
static  result_t AMStandard$SendMsg$default$sendDone(uint8_t arg_0xa7265b0, TOS_MsgPtr arg_0xa46fc60, result_t arg_0xa46fdb0);
static  TOS_MsgPtr AMStandard$UARTReceive$receive(TOS_MsgPtr arg_0xa485df0);
static  result_t CC2420RadioM$SplitControl$default$initDone(void);
static  result_t CC2420RadioM$SplitControl$init(void);
static  result_t CC2420RadioM$SplitControl$default$startDone(void);
static  result_t CC2420RadioM$SplitControl$start(void);
static   result_t CC2420RadioM$FIFOP$fired(void);
static   result_t CC2420RadioM$BackoffTimerJiffy$fired(void);
static  result_t CC2420RadioM$Send$send(TOS_MsgPtr arg_0xa71e7b0);
static   void CC2420RadioM$RadioReceiveCoordinator$default$startSymbol(uint8_t arg_0xa749aa8, uint8_t arg_0xa749bf0, TOS_MsgPtr arg_0xa749d40);
static   result_t CC2420RadioM$SFD$captured(uint16_t arg_0xa78da10);
static   void CC2420RadioM$RadioSendCoordinator$default$startSymbol(uint8_t arg_0xa749aa8, uint8_t arg_0xa749bf0, TOS_MsgPtr arg_0xa749d40);
static   result_t CC2420RadioM$HPLChipconFIFO$TXFIFODone(uint8_t arg_0xa790010, uint8_t *arg_0xa790170);
static   result_t CC2420RadioM$HPLChipconFIFO$RXFIFODone(uint8_t arg_0xa765970, uint8_t *arg_0xa765ad0);
static  result_t CC2420RadioM$StdControl$init(void);
static  result_t CC2420RadioM$StdControl$start(void);
static   int16_t CC2420RadioM$MacBackoff$default$initialBackoff(TOS_MsgPtr arg_0xa7482f0);
static   int16_t CC2420RadioM$MacBackoff$default$congestionBackoff(TOS_MsgPtr arg_0xa748718);
static  result_t CC2420RadioM$CC2420SplitControl$initDone(void);
static  result_t CC2420RadioM$CC2420SplitControl$startDone(void);
static  result_t CC2420ControlM$SplitControl$init(void);
static  result_t CC2420ControlM$SplitControl$start(void);
static   result_t CC2420ControlM$CCA$fired(void);
static   result_t CC2420ControlM$HPLChipconRAM$writeDone(uint16_t arg_0xa7d8b70, uint8_t arg_0xa7d8cb8, uint8_t *arg_0xa7d8e18);
static   result_t CC2420ControlM$CC2420Control$VREFOn(void);
static   result_t CC2420ControlM$CC2420Control$RxMode(void);
static  result_t CC2420ControlM$CC2420Control$TuneManual(uint16_t arg_0xa75b3a0);
static  result_t CC2420ControlM$CC2420Control$setShortAddress(uint16_t arg_0xa750e80);
static   result_t CC2420ControlM$CC2420Control$OscillatorOn(void);
static   uint16_t HPLCC2420M$HPLCC2420$read(uint8_t arg_0xa769728);
static   uint8_t HPLCC2420M$HPLCC2420$write(uint8_t arg_0xa769130, uint16_t arg_0xa769280);
static   uint8_t HPLCC2420M$HPLCC2420$cmd(uint8_t arg_0xa768cd8);
static   result_t HPLCC2420M$HPLCC2420RAM$write(uint16_t arg_0xa7d8448, uint8_t arg_0xa7d8590, uint8_t *arg_0xa7d86f0);
static  result_t HPLCC2420M$StdControl$init(void);
static  result_t HPLCC2420M$StdControl$start(void);
static   result_t HPLCC2420FIFOM$HPLCC2420FIFO$writeTXFIFO(uint8_t arg_0xa7652f0, uint8_t *arg_0xa765450);
static   result_t HPLCC2420FIFOM$HPLCC2420FIFO$readRXFIFO(uint8_t arg_0xa764bb8, uint8_t *arg_0xa764d18);
static   result_t HPLCC2420InterruptM$FIFO$default$fired(void);
static   result_t HPLCC2420InterruptM$FIFOP$disable(void);
static   result_t HPLCC2420InterruptM$FIFOP$startWait(bool arg_0xa7917f8);
static  result_t HPLCC2420InterruptM$CCATimer$fired(void);
static  result_t HPLCC2420InterruptM$FIFOTimer$fired(void);
static   void HPLCC2420InterruptM$SFDCapture$captured(uint16_t arg_0xa837500);
static   result_t HPLCC2420InterruptM$CCA$startWait(bool arg_0xa7917f8);
static   result_t HPLCC2420InterruptM$SFD$disable(void);
static   result_t HPLCC2420InterruptM$SFD$enableCapture(bool arg_0xa78d4e8);
static   result_t HPLTimer1M$Timer1$setRate(uint16_t arg_0xa84e8b0, char arg_0xa84e9f0);
static   result_t HPLTimer1M$Timer1$default$fire(void);
static   uint16_t HPLTimer1M$CaptureT1$getEvent(void);
static   void HPLTimer1M$CaptureT1$enableEvents(void);
static   void HPLTimer1M$CaptureT1$disableEvents(void);
static   void HPLTimer1M$CaptureT1$clearOverflow(void);
static   bool HPLTimer1M$CaptureT1$isOverflowPending(void);
static   void HPLTimer1M$CaptureT1$setEdge(uint8_t arg_0xa83f938);
static  result_t HPLTimer1M$StdControl$init(void);
static  result_t HPLTimer1M$StdControl$start(void);
static   result_t TimerJiffyAsyncM$TimerJiffyAsync$setOneShot(uint32_t arg_0xa7896e0);
static   bool TimerJiffyAsyncM$TimerJiffyAsync$isSet(void);
static   result_t TimerJiffyAsyncM$TimerJiffyAsync$stop(void);
static  result_t TimerJiffyAsyncM$StdControl$init(void);
static  result_t TimerJiffyAsyncM$StdControl$start(void);
static   result_t TimerJiffyAsyncM$Timer$fire(void);
static   result_t HPLTimer2$Timer2$setIntervalAndScale(uint8_t arg_0xa36e880, uint8_t arg_0xa36e9c8);
static   void HPLTimer2$Timer2$intDisable(void);
static   result_t FramerM$ByteComm$txDone(void);
static   result_t FramerM$ByteComm$txByteReady(bool arg_0xa8c34d0);
static   result_t FramerM$ByteComm$rxByteReady(uint8_t arg_0xa8c2d00, bool arg_0xa8c2e48, uint16_t arg_0xa8c2fa0);
static  result_t FramerM$BareSendMsg$send(TOS_MsgPtr arg_0xa71e7b0);
static  result_t FramerM$StdControl$init(void);
static  result_t FramerM$StdControl$start(void);
static  result_t FramerM$TokenReceiveMsg$ReflectToken(uint8_t arg_0xa8c6c10);
static  TOS_MsgPtr FramerAckM$ReceiveMsg$receive(TOS_MsgPtr arg_0xa485df0);
static  TOS_MsgPtr FramerAckM$TokenReceiveMsg$receive(TOS_MsgPtr arg_0xa8c64b0, uint8_t arg_0xa8c65f8);
static   result_t UARTM$HPLUART$get(uint8_t arg_0xa933888);
static   result_t UARTM$HPLUART$putDone(void);
static   result_t UARTM$ByteComm$txByte(uint8_t arg_0xa8c2870);
static  result_t UARTM$Control$init(void);
static  result_t UARTM$Control$start(void);
static   result_t HPLUART0M$UART$init(void);
static   result_t HPLUART0M$UART$put(uint8_t arg_0xa933388);
static  int TestSenseM$TestSense_interface$getStatus(void);
static  result_t TestSenseM$DataMsg$sendDone(TOS_MsgPtr arg_0xa46fc60, result_t arg_0xa46fdb0);
static  result_t TestSenseM$TempTimer$fired(void);
static   result_t TestSenseM$VolADC$dataReady(uint16_t arg_0xa95fa50);
static  result_t TestSenseM$initTimer$fired(void);
static  TOS_MsgPtr TestSenseM$ResetCounterMsg$receive(TOS_MsgPtr arg_0xa485df0);
static   result_t TestSenseM$TempADC$dataReady(uint16_t arg_0xa95fa50);
static  result_t TestSenseM$StdControl$init(void);
static  result_t TestSenseM$StdControl$start(void);
static  result_t TestSenseM$Timer$fired(void);
static   result_t TestSenseM$LightADC$dataReady(uint16_t arg_0xa95fa50);
static  result_t PhotoTempM$PhotoTempTimer$fired(void);
static  result_t PhotoTempM$PhotoStdControl$init(void);
static  result_t PhotoTempM$PhotoStdControl$start(void);
static  result_t PhotoTempM$PhotoStdControl$stop(void);
static   result_t PhotoTempM$InternalTempADC$dataReady(uint16_t arg_0xa95fa50);
static  result_t PhotoTempM$TempStdControl$init(void);
static  result_t PhotoTempM$TempStdControl$start(void);
static  result_t PhotoTempM$TempStdControl$stop(void);
static   result_t PhotoTempM$ExternalTempADC$getData(void);
static   result_t PhotoTempM$ExternalPhotoADC$getData(void);
static   result_t PhotoTempM$InternalPhotoADC$dataReady(uint16_t arg_0xa95fa50);
static   result_t ADCM$HPLADC$dataReady(uint16_t arg_0xa9ce318);
static  result_t ADCM$ADCControl$bindPort(uint8_t arg_0xa979670, uint8_t arg_0xa9797b8);
static  result_t ADCM$ADCControl$init(void);
static   result_t ADCM$ADC$getData(uint8_t arg_0xa99f2a0);
static   result_t ADCM$ADC$default$dataReady(uint8_t arg_0xa99f2a0, uint16_t arg_0xa95fa50);
static   result_t HPLADCC$ADC$bindPort(uint8_t arg_0xa9d11b0, uint8_t arg_0xa9d12f8);
static   result_t HPLADCC$ADC$sampleStop(void);
static   result_t HPLADCC$ADC$init(void);
static   result_t HPLADCC$ADC$samplePort(uint8_t arg_0xa9d17e0);
static   result_t VoltageM$Voltage$getData(void);
static   result_t VoltageM$ADC$dataReady(uint16_t arg_0xa95fa50);
static  result_t VoltageM$StdControl$start(void);
static  result_t VoltageM$StdControl$stop(void);
static  
# 47 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/system/RealMain.nc"
result_t RealMain$hardwareInit(void);
static  
# 78 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/Pot.nc"
result_t RealMain$Pot$init(uint8_t arg_0xa2f4d98);
static  
# 63 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/StdControl.nc"
result_t RealMain$StdControl$init(void);
static  





result_t RealMain$StdControl$start(void);
# 54 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/system/RealMain.nc"
int   main(void);
static  
# 74 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/HPLPot.nc"
result_t PotM$HPLPot$finalise(void);
static  
#line 59
result_t PotM$HPLPot$decrease(void);
static  






result_t PotM$HPLPot$increase(void);
# 91 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/system/PotM.nc"
uint8_t PotM$potSetting;
static inline 
void PotM$setPot(uint8_t value);
static inline  
#line 106
result_t PotM$Pot$init(uint8_t initialSetting);
static inline  
# 57 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/mica2/HPLPotC.nc"
result_t HPLPotC$Pot$decrease(void);
static inline  







result_t HPLPotC$Pot$increase(void);
static inline  







result_t HPLPotC$Pot$finalise(void);
static inline  
# 57 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/avrmote/HPLInit.nc"
result_t HPLInit$init(void);
static   
# 122 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/Leds.nc"
result_t BlinkM$Leds$yellowOff(void);
static   
#line 114
result_t BlinkM$Leds$yellowOn(void);
static   
#line 56
result_t BlinkM$Leds$init(void);
static   
#line 97
result_t BlinkM$Leds$greenOff(void);
static   
#line 72
result_t BlinkM$Leds$redOff(void);
static   
#line 64
result_t BlinkM$Leds$redOn(void);
static   
#line 89
result_t BlinkM$Leds$greenOn(void);
static  
# 4 "TestSense_interface.nc"
int BlinkM$App$getStatus(void);
static  
# 59 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/Timer.nc"
result_t BlinkM$Timer$start(char arg_0xa344320, uint32_t arg_0xa344478);
static  







result_t BlinkM$Timer$stop(void);
# 51 "BlinkM.nc"
int BlinkM$i = 1;
static inline  






result_t BlinkM$StdControl$init(void);
static inline  









result_t BlinkM$StdControl$start(void);
static inline  
#line 93
result_t BlinkM$Timer$fired(void);
static inline  
#line 128
result_t BlinkM$App$start(void);
static inline  


result_t BlinkM$App$stop(void);
static   
# 41 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/PowerManagement.nc"
uint8_t TimerM$PowerManagement$adjustPower(void);
static   
# 105 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/Clock.nc"
void TimerM$Clock$setInterval(uint8_t arg_0xa3734e8);
static   
#line 153
uint8_t TimerM$Clock$readCounter(void);
static   
#line 96
result_t TimerM$Clock$setRate(char arg_0xa3729e8, char arg_0xa372b28);
static   
#line 121
uint8_t TimerM$Clock$getInterval(void);
static  
# 73 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/Timer.nc"
result_t TimerM$Timer$fired(
# 49 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/system/TimerM.nc"
uint8_t arg_0xa34ee80);









uint32_t TimerM$mState;
uint8_t TimerM$setIntervalFlag;
uint8_t TimerM$mScale;
#line 61
uint8_t TimerM$mInterval;
int8_t TimerM$queue_head;
int8_t TimerM$queue_tail;
uint8_t TimerM$queue_size;
uint8_t TimerM$queue[NUM_TIMERS];
volatile uint16_t TimerM$interval_outstanding;

struct TimerM$timer_s {
  uint8_t type;
  int32_t ticks;
  int32_t ticksLeft;
} TimerM$mTimerList[NUM_TIMERS];

enum TimerM$__nesc_unnamed4289 {
  TimerM$maxTimerInterval = 230
};
static  result_t TimerM$StdControl$init(void);
static inline  








result_t TimerM$StdControl$start(void);
static  









result_t TimerM$Timer$start(uint8_t id, char type, 
uint32_t interval);
#line 129
static void TimerM$adjustInterval(void);
static  
#line 168
result_t TimerM$Timer$stop(uint8_t id);
static inline   
#line 182
result_t TimerM$Timer$default$fired(uint8_t id);
static inline 


void TimerM$enqueue(uint8_t value);
static inline 






uint8_t TimerM$dequeue(void);
static inline  








void TimerM$signalOneTimer(void);
static inline  




void TimerM$HandleFire(void);
static inline   
#line 253
result_t TimerM$Clock$fire(void);
static   
# 180 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/Clock.nc"
result_t HPLClock$Clock$fire(void);
# 54 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/mica/HPLClock.nc"
uint8_t HPLClock$set_flag;
uint8_t HPLClock$mscale;
#line 55
uint8_t HPLClock$nextScale;
#line 55
uint8_t HPLClock$minterval;
static inline   
#line 87
void HPLClock$Clock$setInterval(uint8_t value);
static inline   








uint8_t HPLClock$Clock$getInterval(void);
static inline   
#line 134
uint8_t HPLClock$Clock$readCounter(void);
static inline   
#line 149
result_t HPLClock$Clock$setRate(char interval, char scale);
#line 167
void __attribute((interrupt))   __vector_15(void);
static inline   
# 51 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/system/NoLeds.nc"
result_t NoLeds$Leds$init(void);
static inline   


result_t NoLeds$Leds$redOn(void);
static inline   


result_t NoLeds$Leds$redOff(void);
static inline   
#line 75
result_t NoLeds$Leds$greenToggle(void);
static inline   


result_t NoLeds$Leds$yellowOn(void);
static inline   


result_t NoLeds$Leds$yellowOff(void);
static inline   
#line 95
result_t NoLeds$Leds$set(uint8_t value);
 
# 51 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/mica2/HPLPowerManagementM.nc"
int8_t HPLPowerManagementM$disableCount = 1;
uint8_t HPLPowerManagementM$powerLevel;

enum HPLPowerManagementM$__nesc_unnamed4290 {
  HPLPowerManagementM$IDLE = 0, 
  HPLPowerManagementM$ADC_NR = 1 << 3, 
  HPLPowerManagementM$POWER_DOWN = 1 << 4, 
  HPLPowerManagementM$POWER_SAVE = (1 << 3) + (1 << 4), 
  HPLPowerManagementM$STANDBY = (1 << 2) + (1 << 4), 
  HPLPowerManagementM$EXT_STANDBY = (1 << 3) + (1 << 4) + (1 << 2)
};
static inline 

uint8_t HPLPowerManagementM$getPowerLevel(void);
static inline  
#line 85
void HPLPowerManagementM$doAdjustment(void);
static   
#line 102
uint8_t HPLPowerManagementM$PowerManagement$adjustPower(void);
# 50 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/system/LedsC.nc"
uint8_t LedsC$ledsOn;

enum LedsC$__nesc_unnamed4291 {
  LedsC$RED_BIT = 1, 
  LedsC$GREEN_BIT = 2, 
  LedsC$YELLOW_BIT = 4
};
static inline   
result_t LedsC$Leds$init(void);
static inline   
#line 72
result_t LedsC$Leds$redOn(void);
static inline   







result_t LedsC$Leds$redOff(void);
static inline   
#line 101
result_t LedsC$Leds$greenOn(void);
static inline   







result_t LedsC$Leds$greenOff(void);
static inline   
#line 130
result_t LedsC$Leds$yellowOn(void);
static inline   







result_t LedsC$Leds$yellowOff(void);
static inline   







result_t LedsC$Leds$yellowToggle(void);
static  
# 41 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/BitVecUtilsC.nc"
result_t BitVecUtilsC$BitVecUtils$indexOf(uint16_t *pResult, uint16_t fromIndex, 
uint8_t *bitVec, uint16_t length);
static  
# 39 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/system/CrcC.nc"
uint16_t CrcC$Crc$crc16(void *buf, uint8_t len);
static  
# 48 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/SendMsg.nc"
result_t DelugeM$SendAdvMsg$send(uint16_t arg_0xa46f5a8, uint8_t arg_0xa46f6f0, TOS_MsgPtr arg_0xa46f840);
static  
# 54 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/NetProg.nc"
result_t DelugeM$NetProg$programImgAndReboot(uint8_t arg_0xa45e840);
static  
# 34 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/DelugePageTransfer.nc"
result_t DelugeM$PageTransfer$dataAvailable(uint16_t arg_0xa453cc0, imgnum_t arg_0xa453e10);
static  
#line 33
bool DelugeM$PageTransfer$isTransferring(void);
static  
#line 32
result_t DelugeM$PageTransfer$setWorkingPage(imgnum_t arg_0xa4534a8, pgnum_t arg_0xa4535f0);
static  
# 51 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/SharedMsgBuf.nc"
void DelugeM$SharedMsgBuf$unlock(void);
static  
#line 46
void DelugeM$SharedMsgBuf$lock(void);
static  
#line 59
bool DelugeM$SharedMsgBuf$isLocked(void);
static  
#line 41
TOS_MsgPtr DelugeM$SharedMsgBuf$getMsgBuf(void);
static   
# 63 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/Random.nc"
uint16_t DelugeM$Random$rand(void);
static  
# 36 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/InternalFlash.nc"
result_t DelugeM$IFlash$read(void *arg_0xa464e98, void *arg_0xa464ff0, uint16_t arg_0xa465140);
static  
#line 35
result_t DelugeM$IFlash$write(void *arg_0xa4647d0, void *arg_0xa464928, uint16_t arg_0xa464a78);
static  
# 63 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/StdControl.nc"
result_t DelugeM$PageTransferControl$init(void);
static  





result_t DelugeM$PageTransferControl$start(void);
static   
# 122 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/Leds.nc"
result_t DelugeM$Leds$yellowOff(void);
static   
#line 114
result_t DelugeM$Leds$yellowOn(void);
static   
#line 56
result_t DelugeM$Leds$init(void);
static   
#line 72
result_t DelugeM$Leds$redOff(void);
static   
#line 106
result_t DelugeM$Leds$greenToggle(void);
static   
#line 64
result_t DelugeM$Leds$redOn(void);
static  
# 33 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/Crc.nc"
uint16_t DelugeM$Crc$crc16(void *arg_0xa448f60, uint8_t arg_0xa4490a8);
static  
# 37 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/DelugeMetadata.nc"
result_t DelugeM$Metadata$receivedPage(imgnum_t arg_0xa4598f8, pgnum_t arg_0xa459a40);
static  
#line 33
bool DelugeM$Metadata$isImgDescValid(DelugeImgDesc *arg_0xa458c98);
static  DelugeImgDesc *DelugeM$Metadata$getImgDesc(imgnum_t arg_0xa4590a8);
static  
result_t DelugeM$Metadata$setupNewImage(DelugeImgDesc *arg_0xa4594e8);
static  
# 59 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/Timer.nc"
result_t DelugeM$Timer$start(char arg_0xa344320, uint32_t arg_0xa344478);
static  







result_t DelugeM$Timer$stop(void);
# 54 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/DelugeM.nc"
enum DelugeM$__nesc_unnamed4292 {
  DelugeM$DELUGE_NUM_TIMERS = 3
};

enum DelugeM$__nesc_unnamed4293 {
  DelugeM$S_INITIALIZING, 
  DelugeM$S_STARTED, 
  DelugeM$S_STOPPED
};

uint8_t DelugeM$state;
uint8_t DelugeM$rebootDelay;
uint8_t DelugeM$curImage;
bool DelugeM$imagesLoaded;

DelugeAdvTimer DelugeM$advTimers[DelugeM$DELUGE_NUM_TIMERS];
DelugeNodeDesc DelugeM$nodeDesc;
static 
int DelugeM$findMinTimer(void);
static 
#line 86
void DelugeM$setupAdvTimer(int timerNum);
static inline 
#line 101
void DelugeM$updateTimers(int minTimer);
static 






void DelugeM$resetTimer(int i);
static 






void DelugeM$checkReboot(void);
static 






void DelugeM$setNextPage(void);
static  
#line 147
result_t DelugeM$StdControl$init(void);
static 
#line 160
void DelugeM$realStart(void);
static inline  
#line 172
result_t DelugeM$StdControl$start(void);
static inline  
#line 196
result_t DelugeM$MetadataControl$startDone(void);
static 









bool DelugeM$isNodeDescValid(DelugeNodeDesc *tmpNodeDesc);
static 



void DelugeM$sendAdvMsg(int imgNum, uint16_t addr);
static inline  
#line 245
result_t DelugeM$Timer$fired(void);
static inline  
#line 280
TOS_MsgPtr DelugeM$ReceiveAdvMsg$receive(TOS_MsgPtr pMsg);
static inline  
#line 373
result_t DelugeM$SendAdvMsg$sendDone(TOS_MsgPtr pMsg, result_t result);
static inline  



void DelugeM$PageTransfer$receivedPage(imgnum_t imgNum, pgnum_t pgNum);
static inline  



void DelugeM$PageTransfer$suppressMsgs(imgnum_t imgNum);
static inline  


void DelugeM$Metadata$updateDone(result_t result);
static inline  




void DelugeM$SharedMsgBuf$bufFree(void);
static  
# 85 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/SplitControl.nc"
result_t DelugeMetadataM$SplitControl$startDone(void);
static  
# 35 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/DelugeMetadataStore.nc"
result_t DelugeMetadataM$MetadataStore$read(imgnum_t arg_0xa4c9170, void *arg_0xa4c92c8);
static  

result_t DelugeMetadataM$MetadataStore$write(imgnum_t arg_0xa4c9ae0, void *arg_0xa4c9c38);
static  
# 39 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/DelugeDataRead.nc"
result_t DelugeMetadataM$DataRead$verify(imgnum_t arg_0xa4d61c8, pgnum_t arg_0xa4d6310);
static  
# 29 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/FlashWP.nc"
result_t DelugeMetadataM$FlashWP$setWP(void);
static  
result_t DelugeMetadataM$FlashWP$clrWP(void);
static  
# 59 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/Timer.nc"
result_t DelugeMetadataM$Timer$start(char arg_0xa344320, uint32_t arg_0xa344478);
static  
# 33 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/Crc.nc"
uint16_t DelugeMetadataM$Crc$crc16(void *arg_0xa448f60, uint8_t arg_0xa4490a8);
static  
# 36 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/DelugeDataWrite.nc"
result_t DelugeMetadataM$DataWrite$erase(imgnum_t arg_0xa4d2988);
static  

result_t DelugeMetadataM$DataWrite$commit(imgnum_t arg_0xa4d3198);
static  
# 34 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/DelugeStorage.nc"
result_t DelugeMetadataM$DelugeStorage$loadImages(void);
static  
# 38 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/DelugeMetadata.nc"
void DelugeMetadataM$Metadata$updateDone(result_t arg_0xa459e48);
# 51 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/DelugeMetadataM.nc"
DelugeImgDesc DelugeMetadataM$imgDesc[3];

uint8_t DelugeMetadataM$curImage;
uint8_t DelugeMetadataM$state;


enum DelugeMetadataM$__nesc_unnamed4294 {
  DelugeMetadataM$S_INIT, 
  DelugeMetadataM$S_SCAN_METADATA, 
  DelugeMetadataM$S_IDLE, 
  DelugeMetadataM$S_CLEAR_WP, 
  DelugeMetadataM$S_SETUP, 
  DelugeMetadataM$S_VERIFY, 
  DelugeMetadataM$S_SET_WP
};
static 
void DelugeMetadataM$verifyNextPage(void);
static inline  
result_t DelugeMetadataM$SplitControl$init(void);
static inline  



result_t DelugeMetadataM$SplitControl$start(void);
static inline 








void DelugeMetadataM$signalDone(void);
static 



result_t DelugeMetadataM$execute(void);
static inline  
#line 122
result_t DelugeMetadataM$Timer$fired(void);
static inline  



void DelugeMetadataM$DelugeStorage$loadImagesDone(result_t result);
static 








void DelugeMetadataM$scanNextImage(void);
static 
#line 150
void DelugeMetadataM$verifyNextPage(void);
static inline  



void DelugeMetadataM$MetadataStore$readDone(storage_result_t result);
static inline  
#line 177
void DelugeMetadataM$DataRead$verifyDone(storage_result_t result, bool isValid);
static inline  
#line 222
void DelugeMetadataM$DataWrite$commitDone(storage_result_t result);
static  
#line 240
bool DelugeMetadataM$Metadata$isImgDescValid(DelugeImgDesc *tmpImgDesc);
static inline  




imgvnum_t DelugeMetadataM$DelugeStats$getVNum(imgnum_t imgNum);
static inline  






pgnum_t DelugeMetadataM$DelugeStats$getNumPgsComplete(imgnum_t imgNum);
static inline  


result_t DelugeMetadataM$Metadata$receivedPage(imgnum_t imgNum, pgnum_t pgNum);
static  
#line 272
result_t DelugeMetadataM$Metadata$setupNewImage(DelugeImgDesc *newImgDesc);
static inline  
#line 289
DelugeImgDesc *DelugeMetadataM$Metadata$getImgDesc(uint8_t imgNum);
static inline  


void DelugeMetadataM$FlashWP$clrWPDone(void);
static inline  



void DelugeMetadataM$FlashWP$setWPDone(void);
static inline  


void DelugeMetadataM$DataWrite$eraseDone(storage_result_t result);
static inline  






void DelugeMetadataM$MetadataStore$writeDone(storage_result_t result);
static inline  


void DelugeMetadataM$DataRead$readDone(storage_result_t result);
static inline  void DelugeMetadataM$DataWrite$writeDone(storage_result_t result);
static  
# 40 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/DelugeDataRead.nc"
void DelugeStorageM$DataRead$verifyDone(storage_result_t arg_0xa4d6720, bool arg_0xa4d6868);
static  
#line 37
void DelugeStorageM$DataRead$readDone(storage_result_t arg_0xa4dbd98);
static  
# 29 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/StorageRemap.nc"
uint32_t DelugeStorageM$StorageRemap$physicalAddr(
# 42 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/DelugeStorageM.nc"
blockstorage_t arg_0xa537660, 
# 29 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/StorageRemap.nc"
uint32_t arg_0xa538488);
static  
# 32 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/BlockRead.nc"
result_t DelugeStorageM$BlockRead$read(
# 39 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/DelugeStorageM.nc"
blockstorage_t arg_0xa528458, 
# 32 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/BlockRead.nc"
block_addr_t arg_0xa529268, void *arg_0xa5293c0, block_addr_t arg_0xa529510);
static  




result_t DelugeStorageM$BlockRead$computeCrc(
# 39 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/DelugeStorageM.nc"
blockstorage_t arg_0xa528458, 
# 38 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/BlockRead.nc"
block_addr_t arg_0xa526820, block_addr_t arg_0xa526970);
static  
# 35 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/BlockWrite.nc"
result_t DelugeStorageM$BlockWrite$erase(
# 40 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/DelugeStorageM.nc"
blockstorage_t arg_0xa527ef0);
static  
# 38 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/BlockWrite.nc"
result_t DelugeStorageM$BlockWrite$commit(
# 40 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/DelugeStorageM.nc"
blockstorage_t arg_0xa527ef0);
static  
# 32 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/BlockWrite.nc"
result_t DelugeStorageM$BlockWrite$write(
# 40 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/DelugeStorageM.nc"
blockstorage_t arg_0xa527ef0, 
# 32 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/BlockWrite.nc"
block_addr_t arg_0xa50ad40, void *arg_0xa50ae98, block_addr_t arg_0xa50afe8);
static  
# 31 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/Mount.nc"
result_t DelugeStorageM$Mount$mount(
# 41 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/DelugeStorageM.nc"
blockstorage_t arg_0xa53afa0, 
# 31 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/Mount.nc"
volume_id_t arg_0xa5369b8);
static  
# 35 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/DelugeStorage.nc"
void DelugeStorageM$DelugeStorage$loadImagesDone(result_t arg_0xa4d5b38);
static  
# 34 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/DelugeDataWrite.nc"
void DelugeStorageM$DataWrite$writeDone(storage_result_t arg_0xa4d2580);
static  

void DelugeStorageM$DataWrite$eraseDone(storage_result_t arg_0xa4d2d90);
static  

void DelugeStorageM$DataWrite$commitDone(storage_result_t arg_0xa4d35a0);
static  
# 39 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/DelugeMetadataStore.nc"
void DelugeStorageM$MetadataStore$writeDone(storage_result_t arg_0xa4da060);
static  
#line 36
void DelugeStorageM$MetadataStore$readDone(storage_result_t arg_0xa4c96d8);
# 49 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/DelugeStorageM.nc"
enum DelugeStorageM$__nesc_unnamed4295 {
  DelugeStorageM$S_NEVER_USED, 
  DelugeStorageM$S_MOUNTING, 
  DelugeStorageM$S_IDLE, 
  DelugeStorageM$S_METADATA_READ, 
  DelugeStorageM$S_METADATA_WRITE, 
  DelugeStorageM$S_READ, 
  DelugeStorageM$S_WRITE, 
  DelugeStorageM$S_ERASE, 
  DelugeStorageM$S_VERIFY, 
  DelugeStorageM$S_COMMIT
};

uint8_t DelugeStorageM$state = DelugeStorageM$S_NEVER_USED;
uint8_t DelugeStorageM$client;
uint16_t DelugeStorageM$crcScratch;
uint8_t DelugeStorageM$pgNum;
static 
void DelugeStorageM$signalDone(result_t result);
static inline  
#line 86
result_t DelugeStorageM$DelugeStorage$loadImages(void);
static  
#line 104
void DelugeStorageM$Mount$mountDone(volume_t volume, storage_result_t result, volume_id_t id);
static inline  
#line 123
uint32_t DelugeStorageM$DelugeStorage$imgNum2Addr(imgnum_t imgNum);
static 




result_t DelugeStorageM$newRequest(uint8_t newState, imgnum_t imgNum, 
block_addr_t addr, void *buf, uint16_t len);
static inline  
#line 166
result_t DelugeStorageM$MetadataStore$read(imgnum_t imgNum, void *buf);
static inline  


result_t DelugeStorageM$MetadataStore$write(imgnum_t imgNum, void *buf);
static inline  


result_t DelugeStorageM$DataRead$read(imgnum_t imgNum, block_addr_t addr, 
void *buf, uint16_t length);
static inline  


result_t DelugeStorageM$DataRead$verify(imgnum_t imgNum, pgnum_t tmpPgNum);
static inline  


result_t DelugeStorageM$DataWrite$write(imgnum_t imgNum, block_addr_t addr, 
void *buf, uint16_t length);
static inline  


result_t DelugeStorageM$DataWrite$erase(imgnum_t imgNum);
static inline  


result_t DelugeStorageM$DataWrite$commit(imgnum_t imgNum);
static  


void DelugeStorageM$BlockRead$readDone(uint8_t volume, storage_result_t result, block_addr_t addr, void *buf, block_addr_t len);
static inline  
#line 216
void DelugeStorageM$BlockRead$computeCrcDone(uint8_t volume, storage_result_t result, uint16_t crc, block_addr_t addr, block_addr_t len);
static inline  



void DelugeStorageM$BlockWrite$writeDone(uint8_t volume, storage_result_t result, block_addr_t addr, void *buf, block_addr_t len);
static inline  


void DelugeStorageM$BlockWrite$eraseDone(uint8_t volume, storage_result_t result);
static inline  


void DelugeStorageM$BlockWrite$commitDone(uint8_t volume, storage_result_t result);
static inline  


void DelugeStorageM$BlockRead$verifyDone(uint8_t volume, storage_result_t result);
static inline   
result_t DelugeStorageM$BlockRead$default$read(blockstorage_t blockId, block_addr_t addr, void *buf, block_addr_t len);
static inline   
result_t DelugeStorageM$BlockRead$default$computeCrc(blockstorage_t blockId, block_addr_t addr, block_addr_t len);
static inline   result_t DelugeStorageM$BlockWrite$default$write(blockstorage_t blockId, block_addr_t addr, void *buf, block_addr_t len);
static inline   result_t DelugeStorageM$BlockWrite$default$erase(blockstorage_t blockId);
static inline   result_t DelugeStorageM$BlockWrite$default$commit(blockstorage_t blockId);
static inline   result_t DelugeStorageM$Mount$default$mount(blockstorage_t blockId, volume_id_t id);
static inline   uint32_t DelugeStorageM$StorageRemap$default$physicalAddr(blockstorage_t blockId, uint32_t id);
static  
# 48 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/PageEEPROM.nc"
result_t BlockStorageM$PageEEPROM$read(
# 40 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/BlockStorageM.nc"
blockstorage_t arg_0xa571d00, 
# 48 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/PageEEPROM.nc"
eeprompage_t arg_0xa568418, eeprompageoffset_t arg_0xa568570, 
void *arg_0xa5686d8, eeprompageoffset_t arg_0xa568830);
static  
#line 37
result_t BlockStorageM$PageEEPROM$erase(
# 40 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/BlockStorageM.nc"
blockstorage_t arg_0xa571d00, 
# 37 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/PageEEPROM.nc"
eeprompage_t arg_0xa56a468, uint8_t arg_0xa56a5b8);
static  
#line 54
result_t BlockStorageM$PageEEPROM$computeCrcContinue(
# 40 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/BlockStorageM.nc"
blockstorage_t arg_0xa571d00, 
# 54 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/PageEEPROM.nc"
eeprompage_t arg_0xa5697d0, eeprompageoffset_t arg_0xa569928, 
eeprompageoffset_t arg_0xa569a90, uint16_t arg_0xa569be0);
static  
#line 41
result_t BlockStorageM$PageEEPROM$syncAll(
# 40 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/BlockStorageM.nc"
blockstorage_t arg_0xa571d00);
static  
# 33 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/PageEEPROM.nc"
result_t BlockStorageM$PageEEPROM$write(
# 40 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/BlockStorageM.nc"
blockstorage_t arg_0xa571d00, 
# 33 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/PageEEPROM.nc"
eeprompage_t arg_0xa5537f8, eeprompageoffset_t arg_0xa553950, 
void *arg_0xa553ab8, eeprompageoffset_t arg_0xa553c10);
static  
# 31 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/Mount.nc"
result_t BlockStorageM$ActualMount$mount(
# 41 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/BlockStorageM.nc"
blockstorage_t arg_0xa567268, 
# 31 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/Mount.nc"
volume_id_t arg_0xa5369b8);
static  
# 33 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/BlockWrite.nc"
void BlockStorageM$BlockWrite$writeDone(
# 36 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/BlockStorageM.nc"
blockstorage_t arg_0xa570b10, 
# 33 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/BlockWrite.nc"
storage_result_t arg_0xa50b400, block_addr_t arg_0xa50b550, void *arg_0xa50b6a8, block_addr_t arg_0xa50b7f8);
static  

void BlockStorageM$BlockWrite$eraseDone(
# 36 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/BlockStorageM.nc"
blockstorage_t arg_0xa570b10, 
# 36 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/BlockWrite.nc"
storage_result_t arg_0xa50bec8);
static  

void BlockStorageM$BlockWrite$commitDone(
# 36 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/BlockStorageM.nc"
blockstorage_t arg_0xa570b10, 
# 39 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/BlockWrite.nc"
storage_result_t arg_0xa53a5a0);
static  
# 32 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/Mount.nc"
void BlockStorageM$Mount$mountDone(
# 35 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/BlockStorageM.nc"
blockstorage_t arg_0xa570550, 
# 32 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/Mount.nc"
storage_result_t arg_0xa536dc0, volume_id_t arg_0xa536f10);
static  
# 36 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/BlockRead.nc"
void BlockStorageM$BlockRead$verifyDone(
# 37 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/BlockStorageM.nc"
blockstorage_t arg_0xa571390, 
# 36 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/BlockRead.nc"
storage_result_t arg_0xa526410);
static  

void BlockStorageM$BlockRead$computeCrcDone(
# 37 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/BlockStorageM.nc"
blockstorage_t arg_0xa571390, 
# 39 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/BlockRead.nc"
storage_result_t arg_0xa526d80, uint16_t arg_0xa526ed0, block_addr_t arg_0xa527020, block_addr_t arg_0xa527170);
static  
#line 33
void BlockStorageM$BlockRead$readDone(
# 37 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/BlockStorageM.nc"
blockstorage_t arg_0xa571390, 
# 33 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/BlockRead.nc"
storage_result_t arg_0xa529928, block_addr_t arg_0xa529a78, void *arg_0xa529bd0, block_addr_t arg_0xa529d20);
# 47 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/BlockStorageM.nc"
enum BlockStorageM$__nesc_unnamed4296 {
  BlockStorageM$S_IDLE, 
  BlockStorageM$S_WRITE, 
  BlockStorageM$S_ERASE, 
  BlockStorageM$S_COMMIT, BlockStorageM$S_COMMIT2, BlockStorageM$S_COMMIT3, 
  BlockStorageM$S_READ, 
  BlockStorageM$S_VERIFY, BlockStorageM$S_VERIFY2, 
  BlockStorageM$S_CRC
};

uint8_t BlockStorageM$state = BlockStorageM$S_IDLE;
uint8_t BlockStorageM$client;

uint8_t *BlockStorageM$bufPtr;
block_addr_t BlockStorageM$curAddr;
block_addr_t BlockStorageM$bytesRemaining;
#line 62
block_addr_t BlockStorageM$requestedLength;
uint16_t BlockStorageM$crc;
block_addr_t BlockStorageM$maxAddr[3];
uint8_t BlockStorageM$sig[8];
static inline 
void BlockStorageM$verifySignature(void);
static inline void BlockStorageM$commitSignature(void);
static inline void BlockStorageM$commitSync(void);
static 
result_t BlockStorageM$actualSignal(storage_result_t result);
static inline  
#line 105
void BlockStorageM$signalSuccess(void);
static inline  
void BlockStorageM$signalFail(void);
static 
void BlockStorageM$signalDone(result_t result);
static inline 
#line 128
void BlockStorageM$check(result_t ok);
static inline 



bool BlockStorageM$admitRequest(uint8_t newState, uint8_t id);
static inline 






void BlockStorageM$calcRequest(block_addr_t addr, at45page_t *page, 
at45pageoffset_t *offset, at45pageoffset_t *count);
static 







void BlockStorageM$continueRequest(void);
static 
#line 175
result_t BlockStorageM$newRequest(uint8_t newState, uint8_t id, 
block_addr_t addr, uint8_t *buf, block_addr_t len);
static  
#line 190
result_t BlockStorageM$BlockWrite$write(uint8_t id, block_addr_t addr, void *buf, block_addr_t len);
static  







result_t BlockStorageM$BlockWrite$erase(uint8_t id);
static inline  







result_t BlockStorageM$BlockWrite$commit(uint8_t id);
static inline 



void BlockStorageM$commitSignature(void);
static inline 
#line 229
void BlockStorageM$commitSync(void);
static inline  







result_t BlockStorageM$BlockRead$read(uint8_t id, block_addr_t addr, void *buf, block_addr_t len);
static inline 
#line 252
void BlockStorageM$verifySignature(void);
static inline  
#line 264
result_t BlockStorageM$BlockRead$computeCrc(uint8_t id, block_addr_t addr, block_addr_t len);
static inline 


void BlockStorageM$multipageDone(result_t result);
static inline  





result_t BlockStorageM$PageEEPROM$writeDone(uint8_t id, result_t result);
static inline  




result_t BlockStorageM$PageEEPROM$readDone(uint8_t id, result_t result);
static inline  




result_t BlockStorageM$PageEEPROM$computeCrcDone(uint8_t id, result_t result, uint16_t newCrc);
static inline  







result_t BlockStorageM$PageEEPROM$eraseDone(uint8_t id, result_t result);
static inline  




result_t BlockStorageM$PageEEPROM$syncDone(uint8_t id, result_t result);
static inline  




result_t BlockStorageM$PageEEPROM$flushDone(uint8_t id, result_t result);
static inline   


void BlockStorageM$BlockWrite$default$writeDone(uint8_t id, storage_result_t result, block_addr_t addr, void *buf, block_addr_t len);
static inline   void BlockStorageM$BlockWrite$default$eraseDone(uint8_t id, storage_result_t result);
static inline   void BlockStorageM$BlockWrite$default$commitDone(uint8_t id, result_t result);
static inline   void BlockStorageM$BlockRead$default$readDone(uint8_t id, storage_result_t result, block_addr_t addr, void *buf, block_addr_t len);
static inline   void BlockStorageM$BlockRead$default$verifyDone(uint8_t id, result_t result);
static inline   void BlockStorageM$BlockRead$default$computeCrcDone(uint8_t id, storage_result_t result, uint16_t x, block_addr_t addr, block_addr_t len);
static inline  
result_t BlockStorageM$Mount$mount(blockstorage_t blockId, volume_id_t id);
static inline  



void BlockStorageM$ActualMount$mountDone(blockstorage_t blockId, storage_result_t result, volume_id_t id);
static inline   


void BlockStorageM$Mount$default$mountDone(blockstorage_t blockId, storage_result_t result, volume_id_t id);
static  
# 48 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/PageEEPROM.nc"
result_t StorageManagerM$PageEEPROM$read(eeprompage_t arg_0xa568418, eeprompageoffset_t arg_0xa568570, 
void *arg_0xa5686d8, eeprompageoffset_t arg_0xa568830);
static  

result_t StorageManagerM$PageEEPROM$computeCrc(eeprompage_t arg_0xa569068, eeprompageoffset_t arg_0xa5691c0, 
eeprompageoffset_t arg_0xa569328);
static  
# 32 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/Mount.nc"
void StorageManagerM$Mount$mountDone(
# 7 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/StorageManagerM.nc"
volume_t arg_0xa5aac10, 
# 32 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/Mount.nc"
storage_result_t arg_0xa536dc0, volume_id_t arg_0xa536f10);
# 14 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/StorageManagerM.nc"
enum StorageManagerM$__nesc_unnamed4297 {
  StorageManagerM$NVOLUMES = 3
};

struct volume_definition_header_t StorageManagerM$header;
struct volume_definition_t StorageManagerM$volumes[StorageManagerM$NVOLUMES];

enum StorageManagerM$__nesc_unnamed4298 {
  StorageManagerM$S_READY, 
  StorageManagerM$S_MOUNTING
};
struct StorageManagerM$__nesc_unnamed4299 {
  bool validated : 1;
  bool invalid : 1;
  bool busy : 1;
  uint8_t state : 2;
} StorageManagerM$f;

uint8_t StorageManagerM$nextVolume;
volume_t StorageManagerM$client;
volume_id_t StorageManagerM$id;
static inline  
result_t StorageManagerM$StdControl$init(void);
static inline  







result_t StorageManagerM$StdControl$start(void);
static inline 






void StorageManagerM$mountComplete(storage_result_t r);
static inline 



void StorageManagerM$check(result_t r);
static 



void StorageManagerM$checkNextVolume(void);
static inline  
#line 75
void StorageManagerM$mountVolume(void);
static  





result_t StorageManagerM$Mount$mount(volume_t v, volume_id_t i);
static inline  
#line 95
uint32_t StorageManagerM$StorageRemap$physicalAddr(volume_t v, uint32_t volumeAddr);
static inline  


at45page_t StorageManagerM$AT45Remap$remap(volume_t volume, at45page_t volumePage);
static inline  









result_t StorageManagerM$PageEEPROM$writeDone(result_t result);
static inline  


result_t StorageManagerM$PageEEPROM$eraseDone(result_t result);
static inline  


result_t StorageManagerM$PageEEPROM$syncDone(result_t result);
static inline  


result_t StorageManagerM$PageEEPROM$flushDone(result_t result);
static inline  


result_t StorageManagerM$PageEEPROM$readDone(result_t result);
static inline  
#line 145
result_t StorageManagerM$PageEEPROM$computeCrcDone(result_t result, uint16_t crc);
static  
# 43 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/mica/PageEEPROMM.nc"
bool PageEEPROMM$getCompareStatus(void);
static  
# 42 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/PageEEPROM.nc"
result_t PageEEPROMM$PageEEPROM$syncDone(result_t arg_0xa56b498);
static  


result_t PageEEPROMM$PageEEPROM$flushDone(result_t arg_0xa568010);
static  
#line 35
result_t PageEEPROMM$PageEEPROM$writeDone(result_t arg_0xa56a060);
static  

result_t PageEEPROMM$PageEEPROM$eraseDone(result_t arg_0xa56a9d0);
static  
#line 56
result_t PageEEPROMM$PageEEPROM$computeCrcDone(result_t arg_0xa566030, uint16_t arg_0xa566180);
static  
#line 50
result_t PageEEPROMM$PageEEPROM$readDone(result_t arg_0xa568c58);
static   
# 51 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/mica/SlavePin.nc"
result_t PageEEPROMM$FlashSelect$low(void);
static   








result_t PageEEPROMM$FlashSelect$high(bool arg_0xa5ec1c8);
static  
# 63 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/StdControl.nc"
result_t PageEEPROMM$FlashControl$init(void);
static  





result_t PageEEPROMM$FlashControl$start(void);
static   
# 59 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/FastSPI.nc"
uint8_t PageEEPROMM$FlashSPI$txByte(uint8_t arg_0xa5edb20);
static  
# 32 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/Resource.nc"
result_t PageEEPROMM$FlashIdle$wait(void);
# 64 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/mica/PageEEPROMM.nc"
enum PageEEPROMM$__nesc_unnamed4300 {
  PageEEPROMM$IDLE, 
  PageEEPROMM$R_READ, 
  PageEEPROMM$R_READCRC, 
  PageEEPROMM$R_WRITE, 
  PageEEPROMM$R_ERASE, 
  PageEEPROMM$R_SYNC, 
  PageEEPROMM$R_SYNCALL, 
  PageEEPROMM$R_FLUSH, 
  PageEEPROMM$R_FLUSHALL
};
uint8_t PageEEPROMM$request;
uint8_t *PageEEPROMM$reqBuf;
eeprompageoffset_t PageEEPROMM$reqOffset;
#line 77
eeprompageoffset_t PageEEPROMM$reqBytes;
eeprompage_t PageEEPROMM$reqPage;

bool PageEEPROMM$deselectRequested;

bool PageEEPROMM$broken;
bool PageEEPROMM$compareOk;

enum PageEEPROMM$__nesc_unnamed4301 {
  PageEEPROMM$P_SEND_CMD, 
  PageEEPROMM$P_READ, 
  PageEEPROMM$P_READCRC, 
  PageEEPROMM$P_WRITE, 
  PageEEPROMM$P_FLUSH, 
  PageEEPROMM$P_FILL, 
  PageEEPROMM$P_ERASE, 
  PageEEPROMM$P_COMPARE, 
  PageEEPROMM$P_COMPARE_CHECK
};
uint8_t PageEEPROMM$cmdPhase;
#line 96
uint8_t PageEEPROMM$waiting;
uint8_t *PageEEPROMM$data;
#line 97
uint8_t PageEEPROMM$cmd[4];
uint8_t PageEEPROMM$cmdCount;
eeprompageoffset_t PageEEPROMM$dataCount;
uint16_t PageEEPROMM$computedCrc;

struct PageEEPROMM$__nesc_unnamed4302 {
  eeprompage_t page;
  bool busy : 1;
  bool clean : 1;
  bool erased : 1;
  uint8_t unchecked : 2;
} PageEEPROMM$buffer[2];
uint8_t PageEEPROMM$selected;
uint8_t PageEEPROMM$checking;
bool PageEEPROMM$flashBusy;

enum PageEEPROMM$__nesc_unnamed4303 {
  PageEEPROMM$C_READ_BUFFER1 = 0xd4, 
  PageEEPROMM$C_READ_BUFFER2 = 0xd6, 
  PageEEPROMM$C_WRITE_BUFFER1 = 0x84, 
  PageEEPROMM$C_WRITE_BUFFER2 = 0x87, 
  PageEEPROMM$C_FILL_BUFFER1 = 0x53, 
  PageEEPROMM$C_FILL_BUFFER2 = 0x55, 
  PageEEPROMM$C_FLUSH_BUFFER1 = 0x83, 
  PageEEPROMM$C_FLUSH_BUFFER2 = 0x86, 
  PageEEPROMM$C_QFLUSH_BUFFER1 = 0x88, 
  PageEEPROMM$C_QFLUSH_BUFFER2 = 0x89, 
  PageEEPROMM$C_COMPARE_BUFFER1 = 0x60, 
  PageEEPROMM$C_COMPARE_BUFFER2 = 0x61, 
  PageEEPROMM$C_REQ_STATUS = 0xd7, 
  PageEEPROMM$C_ERASE_PAGE = 0x81
};
static inline  



result_t PageEEPROMM$StdControl$init(void);
static inline  
#line 148
result_t PageEEPROMM$StdControl$start(void);
static inline 







void PageEEPROMM$selectFlash(void);
static inline 



void PageEEPROMM$requestDeselect(void);
static inline  



result_t PageEEPROMM$FlashIdle$available(void);
static 





void PageEEPROMM$requestFlashStatus(void);
static 








void PageEEPROMM$sendFlashCommand(void);
static 
#line 249
void PageEEPROMM$requestDone(result_t result);
static inline  
void PageEEPROMM$taskSuccess(void);
static inline  


void PageEEPROMM$taskFail(void);
static 


void PageEEPROMM$handleRWRequest(void);
static void PageEEPROMM$execCommand(bool wait, uint8_t reqCmd, uint8_t dontCare, 
eeprompage_t page, eeprompageoffset_t offset);
static 
void PageEEPROMM$checkBuffer(uint8_t buf);
static 





void PageEEPROMM$flushBuffer(void);
static 






void PageEEPROMM$flashCommandComplete(void);
static inline  
#line 361
result_t PageEEPROMM$FlashSelect$notifyHigh(void);
static 







void PageEEPROMM$execCommand(bool wait, uint8_t reqCmd, uint8_t dontCare, 
eeprompage_t page, eeprompageoffset_t offset);
static inline 
#line 385
void PageEEPROMM$execRWBuffer(uint8_t reqCmd, uint8_t dontCare, eeprompageoffset_t offset);
static 


result_t PageEEPROMM$syncOrFlushAll(uint8_t newReq);
static 
void PageEEPROMM$handleRWRequest(void);
static 
#line 480
void PageEEPROMM$requestDone(result_t result);
static 
#line 495
result_t PageEEPROMM$newRequest(uint8_t req, eeprompage_t page, 
eeprompageoffset_t offset, 
void *reqdata, eeprompageoffset_t n, 
uint16_t crc);
static inline  
#line 533
result_t PageEEPROMM$PageEEPROM$read(eeprompage_t page, eeprompageoffset_t offset, 
void *reqdata, eeprompageoffset_t n);
static 


result_t PageEEPROMM$computeCrc(eeprompage_t page, eeprompageoffset_t offset, 
eeprompageoffset_t n, uint16_t crc);
static inline  
#line 553
result_t PageEEPROMM$PageEEPROM$computeCrc(eeprompage_t page, 
eeprompageoffset_t offset, 
eeprompageoffset_t n);
static inline  


result_t PageEEPROMM$PageEEPROM$computeCrcContinue(eeprompage_t page, 
eeprompageoffset_t offset, 
eeprompageoffset_t n, 
uint16_t crc);
static inline  


result_t PageEEPROMM$PageEEPROM$write(eeprompage_t page, eeprompageoffset_t offset, 
void *reqdata, eeprompageoffset_t n);
static inline  
#line 602
result_t PageEEPROMM$PageEEPROM$erase(eeprompage_t page, uint8_t eraseKind);
static 
#line 640
result_t PageEEPROMM$syncOrFlushAll(uint8_t newReq);
static inline  
#line 666
result_t PageEEPROMM$PageEEPROM$syncAll(void);
static  
# 42 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/PageEEPROM.nc"
result_t PageEEPROMShare$PageEEPROM$syncDone(
# 36 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/PageEEPROMShare.nc"
uint8_t arg_0xa5db170, 
# 42 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/PageEEPROM.nc"
result_t arg_0xa56b498);
static  


result_t PageEEPROMShare$PageEEPROM$flushDone(
# 36 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/PageEEPROMShare.nc"
uint8_t arg_0xa5db170, 
# 46 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/PageEEPROM.nc"
result_t arg_0xa568010);
static  
#line 35
result_t PageEEPROMShare$PageEEPROM$writeDone(
# 36 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/PageEEPROMShare.nc"
uint8_t arg_0xa5db170, 
# 35 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/PageEEPROM.nc"
result_t arg_0xa56a060);
static  

result_t PageEEPROMShare$PageEEPROM$eraseDone(
# 36 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/PageEEPROMShare.nc"
uint8_t arg_0xa5db170, 
# 38 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/PageEEPROM.nc"
result_t arg_0xa56a9d0);
static  
#line 56
result_t PageEEPROMShare$PageEEPROM$computeCrcDone(
# 36 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/PageEEPROMShare.nc"
uint8_t arg_0xa5db170, 
# 56 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/PageEEPROM.nc"
result_t arg_0xa566030, uint16_t arg_0xa566180);
static  
#line 50
result_t PageEEPROMShare$PageEEPROM$readDone(
# 36 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/PageEEPROMShare.nc"
uint8_t arg_0xa5db170, 
# 50 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/PageEEPROM.nc"
result_t arg_0xa568c58);
static  
#line 48
result_t PageEEPROMShare$ActualEEPROM$read(eeprompage_t arg_0xa568418, eeprompageoffset_t arg_0xa568570, 
void *arg_0xa5686d8, eeprompageoffset_t arg_0xa568830);
static  
#line 37
result_t PageEEPROMShare$ActualEEPROM$erase(eeprompage_t arg_0xa56a468, uint8_t arg_0xa56a5b8);
static  
#line 54
result_t PageEEPROMShare$ActualEEPROM$computeCrcContinue(eeprompage_t arg_0xa5697d0, eeprompageoffset_t arg_0xa569928, 
eeprompageoffset_t arg_0xa569a90, uint16_t arg_0xa569be0);
static  
#line 41
result_t PageEEPROMShare$ActualEEPROM$syncAll(void);
static  
#line 33
result_t PageEEPROMShare$ActualEEPROM$write(eeprompage_t arg_0xa5537f8, eeprompageoffset_t arg_0xa553950, 
void *arg_0xa553ab8, eeprompageoffset_t arg_0xa553c10);
static  
#line 52
result_t PageEEPROMShare$ActualEEPROM$computeCrc(eeprompage_t arg_0xa569068, eeprompageoffset_t arg_0xa5691c0, 
eeprompageoffset_t arg_0xa569328);
# 40 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/PageEEPROMShare.nc"
enum PageEEPROMShare$__nesc_unnamed4304 {
  PageEEPROMShare$NCLIENTS = 1
};
uint8_t PageEEPROMShare$lastClient;
static inline 


int PageEEPROMShare$setClient(uint8_t client);
static inline 








uint8_t PageEEPROMShare$getClient(void);
static inline 
#line 70
result_t PageEEPROMShare$check(result_t requestOk);
static 







__inline  result_t PageEEPROMShare$PageEEPROM$write(uint8_t client, eeprompage_t page, eeprompageoffset_t offset, 
void *data, eeprompageoffset_t n);
static 




__inline  result_t PageEEPROMShare$ActualEEPROM$writeDone(result_t result);
static 


__inline  result_t PageEEPROMShare$PageEEPROM$erase(uint8_t client, eeprompage_t page, uint8_t eraseKind);
static 




__inline  result_t PageEEPROMShare$ActualEEPROM$eraseDone(result_t result);
static 








__inline  result_t PageEEPROMShare$PageEEPROM$syncAll(uint8_t client);
static 




__inline  result_t PageEEPROMShare$ActualEEPROM$syncDone(result_t result);
static 
#line 128
__inline  result_t PageEEPROMShare$ActualEEPROM$flushDone(result_t result);
static 


__inline  result_t PageEEPROMShare$PageEEPROM$read(uint8_t client, eeprompage_t page, eeprompageoffset_t offset, 
void *data, eeprompageoffset_t n);
static 




__inline  result_t PageEEPROMShare$ActualEEPROM$readDone(result_t result);
static 


__inline  result_t PageEEPROMShare$PageEEPROM$computeCrc(uint8_t client, eeprompage_t page, eeprompageoffset_t offset, 
eeprompageoffset_t n);
static 




__inline  result_t PageEEPROMShare$ActualEEPROM$computeCrcDone(result_t result, uint16_t crc);
static 


__inline  result_t PageEEPROMShare$PageEEPROM$computeCrcContinue(uint8_t client, eeprompage_t page, eeprompageoffset_t offset, eeprompageoffset_t n, uint16_t crc);
static inline   





result_t PageEEPROMShare$PageEEPROM$default$writeDone(uint8_t client, result_t result);
static inline   


result_t PageEEPROMShare$PageEEPROM$default$eraseDone(uint8_t client, result_t result);
static inline   


result_t PageEEPROMShare$PageEEPROM$default$syncDone(uint8_t client, result_t result);
static inline   


result_t PageEEPROMShare$PageEEPROM$default$flushDone(uint8_t client, result_t result);
static inline   


result_t PageEEPROMShare$PageEEPROM$default$readDone(uint8_t client, result_t result);
static inline   


result_t PageEEPROMShare$PageEEPROM$default$computeCrcDone(uint8_t client, result_t result, uint16_t crc);
static  
# 66 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/mica/SlavePin.nc"
result_t HPLFlash$FlashSelect$notifyHigh(void);
static  
# 33 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/Resource.nc"
result_t HPLFlash$FlashIdle$available(void);
static inline  
# 58 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/mica2/HPLFlash.nc"
result_t HPLFlash$FlashControl$init(void);
static inline  
#line 74
result_t HPLFlash$FlashControl$start(void);
static inline   







result_t HPLFlash$FlashSelect$low(void);
static inline  




void HPLFlash$sigHigh(void);
static inline   


result_t HPLFlash$FlashSelect$high(bool needEvent);
static   
#line 113
uint8_t HPLFlash$FlashSPI$txByte(uint8_t spiOut);
static inline  
#line 141
void HPLFlash$avail(void);
static inline  


result_t HPLFlash$FlashIdle$wait(void);
#line 173
void __attribute((signal))   __vector_3(void);
static inline  



bool HPLFlash$getCompareStatus(void);
static  
# 42 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/PageEEPROM.nc"
result_t HALAT45DBShare$PageEEPROM$syncDone(
# 43 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/HALAT45DBShare.nc"
volume_t arg_0xa644fa0, 
# 42 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/PageEEPROM.nc"
result_t arg_0xa56b498);
static  


result_t HALAT45DBShare$PageEEPROM$flushDone(
# 43 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/HALAT45DBShare.nc"
volume_t arg_0xa644fa0, 
# 46 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/PageEEPROM.nc"
result_t arg_0xa568010);
static  
#line 35
result_t HALAT45DBShare$PageEEPROM$writeDone(
# 43 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/HALAT45DBShare.nc"
volume_t arg_0xa644fa0, 
# 35 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/PageEEPROM.nc"
result_t arg_0xa56a060);
static  

result_t HALAT45DBShare$PageEEPROM$eraseDone(
# 43 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/HALAT45DBShare.nc"
volume_t arg_0xa644fa0, 
# 38 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/PageEEPROM.nc"
result_t arg_0xa56a9d0);
static  
#line 56
result_t HALAT45DBShare$PageEEPROM$computeCrcDone(
# 43 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/HALAT45DBShare.nc"
volume_t arg_0xa644fa0, 
# 56 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/PageEEPROM.nc"
result_t arg_0xa566030, uint16_t arg_0xa566180);
static  
#line 50
result_t HALAT45DBShare$PageEEPROM$readDone(
# 43 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/HALAT45DBShare.nc"
volume_t arg_0xa644fa0, 
# 50 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/PageEEPROM.nc"
result_t arg_0xa568c58);
static  
#line 48
result_t HALAT45DBShare$ActualAT45$read(eeprompage_t arg_0xa568418, eeprompageoffset_t arg_0xa568570, 
void *arg_0xa5686d8, eeprompageoffset_t arg_0xa568830);
static  
#line 37
result_t HALAT45DBShare$ActualAT45$erase(eeprompage_t arg_0xa56a468, uint8_t arg_0xa56a5b8);
static  
#line 54
result_t HALAT45DBShare$ActualAT45$computeCrcContinue(eeprompage_t arg_0xa5697d0, eeprompageoffset_t arg_0xa569928, 
eeprompageoffset_t arg_0xa569a90, uint16_t arg_0xa569be0);
static  
#line 41
result_t HALAT45DBShare$ActualAT45$syncAll(void);
static  
#line 33
result_t HALAT45DBShare$ActualAT45$write(eeprompage_t arg_0xa5537f8, eeprompageoffset_t arg_0xa553950, 
void *arg_0xa553ab8, eeprompageoffset_t arg_0xa553c10);
static  
#line 52
result_t HALAT45DBShare$ActualAT45$computeCrc(eeprompage_t arg_0xa569068, eeprompageoffset_t arg_0xa5691c0, 
eeprompageoffset_t arg_0xa569328);
static  
# 4 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/AT45Remap.nc"
at45page_t HALAT45DBShare$AT45Remap$remap(volume_t arg_0xa5630a8, at45page_t arg_0xa563200);
# 48 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/HALAT45DBShare.nc"
volume_t HALAT45DBShare$lastClient;
static inline 
int HALAT45DBShare$setClient(volume_t client);
static inline 






volume_t HALAT45DBShare$getClient(void);
static 






__inline at45page_t HALAT45DBShare$remap(at45page_t page);
static inline 



result_t HALAT45DBShare$check(result_t requestOk);
static 







__inline  result_t HALAT45DBShare$PageEEPROM$write(volume_t client, at45page_t page, at45pageoffset_t offset, 
void *data, at45pageoffset_t n);
static 




__inline  result_t HALAT45DBShare$ActualAT45$writeDone(result_t result);
static 


__inline  result_t HALAT45DBShare$PageEEPROM$erase(volume_t client, at45page_t page, uint8_t eraseKind);
static 




__inline  result_t HALAT45DBShare$ActualAT45$eraseDone(result_t result);
static 








__inline  result_t HALAT45DBShare$PageEEPROM$syncAll(volume_t client);
static 




__inline  result_t HALAT45DBShare$ActualAT45$syncDone(result_t result);
static 
#line 129
__inline  result_t HALAT45DBShare$ActualAT45$flushDone(result_t result);
static 


__inline  result_t HALAT45DBShare$PageEEPROM$read(volume_t client, at45page_t page, at45pageoffset_t offset, 
void *data, at45pageoffset_t n);
static 




__inline  result_t HALAT45DBShare$ActualAT45$readDone(result_t result);
static 


__inline  result_t HALAT45DBShare$PageEEPROM$computeCrc(volume_t client, at45page_t page, at45pageoffset_t offset, 
at45pageoffset_t n);
static 




__inline  result_t HALAT45DBShare$PageEEPROM$computeCrcContinue(volume_t client, at45page_t page, at45pageoffset_t offset, at45pageoffset_t n, uint16_t crc);
static 




__inline  result_t HALAT45DBShare$ActualAT45$computeCrcDone(result_t result, uint16_t crc);
# 44 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/avrmote/InternalFlashC.nc"
enum InternalFlashC$__nesc_unnamed4305 {
  InternalFlashC$IFLASH_BOUND_LOW = 0x000, 
  InternalFlashC$IFLASH_BOUND_HIGH = 0xfff
};
static  
result_t InternalFlashC$InternalFlash$write(void *addr, void *buf, uint16_t size);
static  
#line 70
result_t InternalFlashC$InternalFlash$read(void *addr, void *buf, uint16_t size);
static  
# 30 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/FlashWP.nc"
void FlashWPC$FlashWP$setWPDone(void);
static  
void FlashWPC$FlashWP$clrWPDone(void);
static inline  
# 37 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/FlashWPC.nc"
result_t FlashWPC$StdControl$init(void);
static inline  result_t FlashWPC$StdControl$start(void);
static inline  

void FlashWPC$signalClrDone(void);
static inline  


void FlashWPC$signalSetDone(void);
static inline  


result_t FlashWPC$FlashWP$clrWP(void);
static inline  


result_t FlashWPC$FlashWP$setWP(void);
static  
# 36 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/DelugeDataRead.nc"
result_t DelugePageTransferM$DataRead$read(imgnum_t arg_0xa4db580, block_addr_t arg_0xa4db6d0, void *arg_0xa4db828, uint16_t arg_0xa4db978);
static  
# 36 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/DelugePageTransfer.nc"
void DelugePageTransferM$PageTransfer$suppressMsgs(imgnum_t arg_0xa468788);
static  
#line 35
void DelugePageTransferM$PageTransfer$receivedPage(imgnum_t arg_0xa468238, pgnum_t arg_0xa468380);
static  
# 35 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/DelugeStats.nc"
imgvnum_t DelugePageTransferM$DelugeStats$getVNum(imgnum_t arg_0xa4b9578);
static  
#line 34
pgnum_t DelugePageTransferM$DelugeStats$getNumPgsComplete(imgnum_t arg_0xa4b9170);
static  
# 51 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/SharedMsgBuf.nc"
void DelugePageTransferM$SharedMsgBuf$unlock(void);
static  
#line 46
void DelugePageTransferM$SharedMsgBuf$lock(void);
static  
#line 59
bool DelugePageTransferM$SharedMsgBuf$isLocked(void);
static  
#line 41
TOS_MsgPtr DelugePageTransferM$SharedMsgBuf$getMsgBuf(void);
static   
# 63 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/Random.nc"
uint16_t DelugePageTransferM$Random$rand(void);
static  
# 48 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/SendMsg.nc"
result_t DelugePageTransferM$SendReqMsg$send(uint16_t arg_0xa46f5a8, uint8_t arg_0xa46f6f0, TOS_MsgPtr arg_0xa46f840);
static  
# 44 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/BitVecUtils.nc"
result_t DelugePageTransferM$BitVecUtils$indexOf(uint16_t *arg_0xa407798, uint16_t arg_0xa4078f0, 
uint8_t *arg_0xa407a60, uint16_t arg_0xa407bb0);
static  
# 48 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/SendMsg.nc"
result_t DelugePageTransferM$SendDataMsg$send(uint16_t arg_0xa46f5a8, uint8_t arg_0xa46f6f0, TOS_MsgPtr arg_0xa46f840);
static   
# 149 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/Leds.nc"
result_t DelugePageTransferM$Leds$set(uint8_t arg_0xa3426c8);
static  
# 33 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/DelugeDataWrite.nc"
result_t DelugePageTransferM$DataWrite$write(imgnum_t arg_0xa4d7d58, block_addr_t arg_0xa4d7ea8, void *arg_0xa4d2010, uint16_t arg_0xa4d2160);
static  
# 59 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/Timer.nc"
result_t DelugePageTransferM$Timer$start(char arg_0xa344320, uint32_t arg_0xa344478);
# 55 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/DelugePageTransferM.nc"
uint8_t DelugePageTransferM$pktsToSend[DELUGE_PKT_BITVEC_SIZE];
uint8_t DelugePageTransferM$pktsToReceive[DELUGE_PKT_BITVEC_SIZE];

DelugeDataMsg DelugePageTransferM$rxQueue[DELUGE_QSIZE];
uint8_t DelugePageTransferM$head;
#line 59
uint8_t DelugePageTransferM$size;


uint8_t DelugePageTransferM$state;
imgnum_t DelugePageTransferM$workingImgNum;
pgnum_t DelugePageTransferM$workingPgNum;
uint16_t DelugePageTransferM$nodeAddr;
uint8_t DelugePageTransferM$remainingAttempts;
bool DelugePageTransferM$suppressReq;
uint8_t DelugePageTransferM$imgToSend;
uint8_t DelugePageTransferM$pageToSend;

enum DelugePageTransferM$__nesc_unnamed4306 {
  DelugePageTransferM$S_DISABLED, 
  DelugePageTransferM$S_IDLE, 
  DelugePageTransferM$S_TX_LOCKING, 
  DelugePageTransferM$S_SENDING, 
  DelugePageTransferM$S_RX_LOCKING, 
  DelugePageTransferM$S_RECEIVING
};
static 
void DelugePageTransferM$changeState(uint8_t newState);
static inline  








result_t DelugePageTransferM$StdControl$init(void);
static inline  





result_t DelugePageTransferM$StdControl$start(void);
static inline  








result_t DelugePageTransferM$PageTransfer$setWorkingPage(imgnum_t imgNum, pgnum_t pgNum);
static inline  





bool DelugePageTransferM$PageTransfer$isTransferring(void);
static 


void DelugePageTransferM$startReqTimer(bool first);
static inline  







result_t DelugePageTransferM$PageTransfer$dataAvailable(uint16_t sourceAddr, imgnum_t imgNum);
static inline 
#line 144
block_addr_t DelugePageTransferM$calcOffset(pgnum_t pgNum, uint8_t pktNum);
static 




void DelugePageTransferM$setupReqMsg(void);
static 
#line 190
void DelugePageTransferM$writeData(void);
static 




void DelugePageTransferM$suppressMsgs(imgnum_t imgNum, pgnum_t pgNum);
static inline  
#line 215
TOS_MsgPtr DelugePageTransferM$ReceiveDataMsg$receive(TOS_MsgPtr pMsg);
static 
#line 250
void DelugePageTransferM$setupDataMsg(void);
static inline  
#line 288
result_t DelugePageTransferM$Timer$fired(void);
static inline  




TOS_MsgPtr DelugePageTransferM$ReceiveReqMsg$receive(TOS_MsgPtr pMsg);
static inline  
#line 342
void DelugePageTransferM$DataRead$readDone(storage_result_t result);
static inline  
#line 359
void DelugePageTransferM$DataWrite$writeDone(storage_result_t result);
static inline  
#line 379
result_t DelugePageTransferM$SendReqMsg$sendDone(TOS_MsgPtr pMsg, result_t success);
static inline  
#line 392
result_t DelugePageTransferM$SendDataMsg$sendDone(TOS_MsgPtr pMsg, result_t success);
static inline  






void DelugePageTransferM$SharedMsgBuf$bufFree(void);
static inline  





void DelugePageTransferM$DataRead$verifyDone(storage_result_t result, bool isValid);
static inline  void DelugePageTransferM$DataWrite$eraseDone(storage_result_t result);
static inline  void DelugePageTransferM$DataWrite$commitDone(storage_result_t result);
# 54 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/system/RandomLFSR.nc"
uint16_t RandomLFSR$shiftReg;
uint16_t RandomLFSR$initSeed;
uint16_t RandomLFSR$mask;
static inline   

result_t RandomLFSR$Random$init(void);
static   









uint16_t RandomLFSR$Random$rand(void);
static  
# 36 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/DelugeStorage.nc"
uint32_t NetProgM$Storage$imgNum2Addr(imgnum_t arg_0xa4d5f48);
static  
# 51 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/SharedMsgBuf.nc"
void NetProgM$SharedMsgBuf$unlock(void);
static  
#line 46
void NetProgM$SharedMsgBuf$lock(void);
static  
#line 59
bool NetProgM$SharedMsgBuf$isLocked(void);
static  
#line 41
TOS_MsgPtr NetProgM$SharedMsgBuf$getMsgBuf(void);
static  
# 36 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/InternalFlash.nc"
result_t NetProgM$IFlash$read(void *arg_0xa464e98, void *arg_0xa464ff0, uint16_t arg_0xa465140);
static  
#line 35
result_t NetProgM$IFlash$write(void *arg_0xa4647d0, void *arg_0xa464928, uint16_t arg_0xa464a78);
static  
# 64 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/SplitControl.nc"
result_t NetProgM$MetadataControl$init(void);
static  
#line 77
result_t NetProgM$MetadataControl$start(void);
static  
# 33 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/Crc.nc"
uint16_t NetProgM$Crc$crc16(void *arg_0xa448f60, uint8_t arg_0xa4490a8);
static  
# 48 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/SendMsg.nc"
result_t NetProgM$SendMsg$send(uint16_t arg_0xa46f5a8, uint8_t arg_0xa46f6f0, TOS_MsgPtr arg_0xa46f840);
static inline 
# 49 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/NetProgM.nc"
uint16_t NetProgM$computeTosInfoCrc(NetProg_TOSInfo *tosInfo);
static 


void NetProgM$writeTOSinfo(void);
static inline  
#line 67
result_t NetProgM$StdControl$init(void);
static inline  
#line 89
result_t NetProgM$StdControl$start(void);
static inline  






result_t NetProgM$MetadataControl$startDone(void);
static inline  
#line 110
result_t NetProgM$NetProg$programImgAndReboot(imgnum_t newImgNum);
static inline  
#line 133
TOS_MsgPtr NetProgM$ReceiveMsg$receive(TOS_MsgPtr pMsg);
static inline  
#line 153
result_t NetProgM$SendMsg$sendDone(TOS_MsgPtr pMsg, result_t result);
static inline  



void NetProgM$Storage$loadImagesDone(result_t result);
static inline  void NetProgM$SharedMsgBuf$bufFree(void);
static  
# 65 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/SharedMsgBuf.nc"
void SharedMsgBufM$SharedMsgBuf$bufFree(void);
# 42 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/SharedMsgBufM.nc"
TOS_Msg SharedMsgBufM$msgBuf;
bool SharedMsgBufM$isLocked = FALSE;
static inline  
TOS_MsgPtr SharedMsgBufM$SharedMsgBuf$getMsgBuf(void);
static inline  


void SharedMsgBufM$SharedMsgBuf$lock(void);
static inline  


void SharedMsgBufM$SharedMsgBuf$unlock(void);
static inline  



bool SharedMsgBufM$SharedMsgBuf$isLocked(void);
static  
# 75 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/ReceiveMsg.nc"
TOS_MsgPtr AMStandard$ReceiveMsg$receive(
# 56 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/system/AMStandard.nc"
uint8_t arg_0xa726b68, 
# 75 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/ReceiveMsg.nc"
TOS_MsgPtr arg_0xa485df0);
static  
# 59 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/Timer.nc"
result_t AMStandard$ActivityTimer$start(char arg_0xa344320, uint32_t arg_0xa344478);
static  
# 58 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/BareSendMsg.nc"
result_t AMStandard$UARTSend$send(TOS_MsgPtr arg_0xa71e7b0);
static   
# 41 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/PowerManagement.nc"
uint8_t AMStandard$PowerManagement$adjustPower(void);
static  
# 63 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/StdControl.nc"
result_t AMStandard$RadioControl$init(void);
static  





result_t AMStandard$RadioControl$start(void);
static  
#line 63
result_t AMStandard$TimerControl$init(void);
static  





result_t AMStandard$TimerControl$start(void);
static  
#line 63
result_t AMStandard$UARTControl$init(void);
static  





result_t AMStandard$UARTControl$start(void);
static  
# 65 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/system/AMStandard.nc"
result_t AMStandard$sendDone(void);
static  
# 58 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/BareSendMsg.nc"
result_t AMStandard$RadioSend$send(TOS_MsgPtr arg_0xa71e7b0);
static  
# 49 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/SendMsg.nc"
result_t AMStandard$SendMsg$sendDone(
# 55 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/system/AMStandard.nc"
uint8_t arg_0xa7265b0, 
# 49 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/SendMsg.nc"
TOS_MsgPtr arg_0xa46fc60, result_t arg_0xa46fdb0);
# 81 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/system/AMStandard.nc"
bool AMStandard$state;
TOS_MsgPtr AMStandard$buffer;
uint16_t AMStandard$lastCount;
uint16_t AMStandard$counter;
static  

bool AMStandard$Control$init(void);
static  
#line 103
bool AMStandard$Control$start(void);
static inline 
#line 132
void AMStandard$dbgPacket(TOS_MsgPtr data);
static 









result_t AMStandard$reportSendDone(TOS_MsgPtr msg, result_t success);
static inline  






result_t AMStandard$ActivityTimer$fired(void);
static inline   




result_t AMStandard$SendMsg$default$sendDone(uint8_t id, TOS_MsgPtr msg, result_t success);
static inline   

result_t AMStandard$default$sendDone(void);
static inline  



void AMStandard$sendTask(void);
static  
#line 179
result_t AMStandard$SendMsg$send(uint8_t id, uint16_t addr, uint8_t length, TOS_MsgPtr data);
static inline  
#line 207
result_t AMStandard$UARTSend$sendDone(TOS_MsgPtr msg, result_t success);
static inline  

result_t AMStandard$RadioSend$sendDone(TOS_MsgPtr msg, result_t success);




TOS_MsgPtr   received(TOS_MsgPtr packet);
static inline   
#line 242
TOS_MsgPtr AMStandard$ReceiveMsg$default$receive(uint8_t id, TOS_MsgPtr msg);
static inline  


TOS_MsgPtr AMStandard$UARTReceive$receive(TOS_MsgPtr packet);
static inline  




TOS_MsgPtr AMStandard$RadioReceive$receive(TOS_MsgPtr packet);
static  
# 70 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/SplitControl.nc"
result_t CC2420RadioM$SplitControl$initDone(void);
static  
#line 85
result_t CC2420RadioM$SplitControl$startDone(void);
static   
# 59 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/CC2420Radio/HPLCC2420Interrupt.nc"
result_t CC2420RadioM$FIFOP$disable(void);
static   
#line 43
result_t CC2420RadioM$FIFOP$startWait(bool arg_0xa7917f8);
static   
# 6 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/CC2420Radio/TimerJiffyAsync.nc"
result_t CC2420RadioM$BackoffTimerJiffy$setOneShot(uint32_t arg_0xa7896e0);
static   


bool CC2420RadioM$BackoffTimerJiffy$isSet(void);
static   
#line 8
result_t CC2420RadioM$BackoffTimerJiffy$stop(void);
static  
# 67 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/BareSendMsg.nc"
result_t CC2420RadioM$Send$sendDone(TOS_MsgPtr arg_0xa71ecc8, result_t arg_0xa71ee18);
static   
# 63 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/Random.nc"
uint16_t CC2420RadioM$Random$rand(void);
static   
#line 57
result_t CC2420RadioM$Random$init(void);
static  
# 63 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/StdControl.nc"
result_t CC2420RadioM$TimerControl$init(void);
static  





result_t CC2420RadioM$TimerControl$start(void);
static  
# 75 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/ReceiveMsg.nc"
TOS_MsgPtr CC2420RadioM$Receive$receive(TOS_MsgPtr arg_0xa485df0);
static   
# 61 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/CC2420Radio/HPLCC2420.nc"
uint16_t CC2420RadioM$HPLChipcon$read(uint8_t arg_0xa769728);
static   
#line 47
uint8_t CC2420RadioM$HPLChipcon$cmd(uint8_t arg_0xa768cd8);
static   
# 33 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/RadioCoordinator.nc"
void CC2420RadioM$RadioReceiveCoordinator$startSymbol(uint8_t arg_0xa749aa8, uint8_t arg_0xa749bf0, TOS_MsgPtr arg_0xa749d40);
static   
# 60 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/CC2420Radio/HPLCC2420Capture.nc"
result_t CC2420RadioM$SFD$disable(void);
static   
#line 43
result_t CC2420RadioM$SFD$enableCapture(bool arg_0xa78d4e8);
static   
# 33 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/RadioCoordinator.nc"
void CC2420RadioM$RadioSendCoordinator$startSymbol(uint8_t arg_0xa749aa8, uint8_t arg_0xa749bf0, TOS_MsgPtr arg_0xa749d40);
static   
# 29 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/CC2420Radio/HPLCC2420FIFO.nc"
result_t CC2420RadioM$HPLChipconFIFO$writeTXFIFO(uint8_t arg_0xa7652f0, uint8_t *arg_0xa765450);
static   
#line 19
result_t CC2420RadioM$HPLChipconFIFO$readRXFIFO(uint8_t arg_0xa764bb8, uint8_t *arg_0xa764d18);
static   
# 163 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/CC2420Radio/CC2420Control.nc"
result_t CC2420RadioM$CC2420Control$RxMode(void);
static   
# 74 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/CC2420Radio/MacBackoff.nc"
int16_t CC2420RadioM$MacBackoff$initialBackoff(TOS_MsgPtr arg_0xa7482f0);
static   int16_t CC2420RadioM$MacBackoff$congestionBackoff(TOS_MsgPtr arg_0xa748718);
static  
# 64 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/SplitControl.nc"
result_t CC2420RadioM$CC2420SplitControl$init(void);
static  
#line 77
result_t CC2420RadioM$CC2420SplitControl$start(void);
# 76 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/CC2420Radio/CC2420RadioM.nc"
enum CC2420RadioM$__nesc_unnamed4307 {
  CC2420RadioM$DISABLED_STATE = 0, 
  CC2420RadioM$DISABLED_STATE_STARTTASK, 
  CC2420RadioM$IDLE_STATE, 
  CC2420RadioM$TX_STATE, 
  CC2420RadioM$TX_WAIT, 
  CC2420RadioM$PRE_TX_STATE, 
  CC2420RadioM$POST_TX_STATE, 
  CC2420RadioM$POST_TX_ACK_STATE, 
  CC2420RadioM$RX_STATE, 
  CC2420RadioM$POWER_DOWN_STATE, 
  CC2420RadioM$WARMUP_STATE, 

  CC2420RadioM$TIMER_INITIAL = 0, 
  CC2420RadioM$TIMER_BACKOFF, 
  CC2420RadioM$TIMER_ACK
};
 


uint8_t CC2420RadioM$countRetry;
uint8_t CC2420RadioM$stateRadio;
 uint8_t CC2420RadioM$stateTimer;
 uint8_t CC2420RadioM$currentDSN;
 bool CC2420RadioM$bAckEnable;
bool CC2420RadioM$bPacketReceiving;
uint8_t CC2420RadioM$txlength;
 TOS_MsgPtr CC2420RadioM$txbufptr;
 TOS_MsgPtr CC2420RadioM$rxbufptr;
TOS_Msg CC2420RadioM$RxBuf;

volatile uint16_t CC2420RadioM$LocalAddr;
static 




void CC2420RadioM$sendFailed(void);
static 




void CC2420RadioM$flushRXFIFO(void);
static 







__inline result_t CC2420RadioM$setInitialTimer(uint16_t jiffy);
static 






__inline result_t CC2420RadioM$setBackoffTimer(uint16_t jiffy);
static 






__inline result_t CC2420RadioM$setAckTimer(uint16_t jiffy);
static inline  







void CC2420RadioM$PacketRcvd(void);
static  
#line 168
void CC2420RadioM$PacketSent(void);
static inline  
#line 186
result_t CC2420RadioM$StdControl$init(void);
static inline  



result_t CC2420RadioM$SplitControl$init(void);
static inline  
#line 208
result_t CC2420RadioM$CC2420SplitControl$initDone(void);
static inline   


result_t CC2420RadioM$SplitControl$default$initDone(void);
static inline  
#line 239
void CC2420RadioM$startRadio(void);
static inline  
#line 253
result_t CC2420RadioM$StdControl$start(void);
static inline  
#line 277
result_t CC2420RadioM$SplitControl$start(void);
static inline  
#line 294
result_t CC2420RadioM$CC2420SplitControl$startDone(void);
static inline   
#line 312
result_t CC2420RadioM$SplitControl$default$startDone(void);
static inline 







void CC2420RadioM$sendPacket(void);
static inline   
#line 344
result_t CC2420RadioM$SFD$captured(uint16_t time);
static  
#line 393
void CC2420RadioM$startSend(void);
static 
#line 410
void CC2420RadioM$tryToSend(void);
static inline   
#line 449
result_t CC2420RadioM$BackoffTimerJiffy$fired(void);
static inline  
#line 491
result_t CC2420RadioM$Send$send(TOS_MsgPtr pMsg);
static 
#line 534
void CC2420RadioM$delayedRXFIFO(void);
static inline  
void CC2420RadioM$delayedRXFIFOtask(void);
static 


void CC2420RadioM$delayedRXFIFO(void);
static inline   
#line 591
result_t CC2420RadioM$FIFOP$fired(void);
static inline   
#line 628
result_t CC2420RadioM$HPLChipconFIFO$RXFIFODone(uint8_t length, uint8_t *data);
static inline   
#line 721
result_t CC2420RadioM$HPLChipconFIFO$TXFIFODone(uint8_t length, uint8_t *data);
static inline    
#line 744
int16_t CC2420RadioM$MacBackoff$default$initialBackoff(TOS_MsgPtr m);
static inline    





int16_t CC2420RadioM$MacBackoff$default$congestionBackoff(TOS_MsgPtr m);
static inline    






void CC2420RadioM$RadioSendCoordinator$default$startSymbol(uint8_t bitsPerBlock, uint8_t offset, TOS_MsgPtr msgBuff);
static inline    
void CC2420RadioM$RadioReceiveCoordinator$default$startSymbol(uint8_t bitsPerBlock, uint8_t offset, TOS_MsgPtr msgBuff);
static  
# 70 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/SplitControl.nc"
result_t CC2420ControlM$SplitControl$initDone(void);
static  
#line 85
result_t CC2420ControlM$SplitControl$startDone(void);
static   
# 61 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/CC2420Radio/HPLCC2420.nc"
uint16_t CC2420ControlM$HPLChipcon$read(uint8_t arg_0xa769728);
static   
#line 54
uint8_t CC2420ControlM$HPLChipcon$write(uint8_t arg_0xa769130, uint16_t arg_0xa769280);
static   
#line 47
uint8_t CC2420ControlM$HPLChipcon$cmd(uint8_t arg_0xa768cd8);
static   
# 43 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/CC2420Radio/HPLCC2420Interrupt.nc"
result_t CC2420ControlM$CCA$startWait(bool arg_0xa7917f8);
static  
# 63 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/StdControl.nc"
result_t CC2420ControlM$HPLChipconControl$init(void);
static  





result_t CC2420ControlM$HPLChipconControl$start(void);
static   
# 47 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/CC2420Radio/HPLCC2420RAM.nc"
result_t CC2420ControlM$HPLChipconRAM$write(uint16_t arg_0xa7d8448, uint8_t arg_0xa7d8590, uint8_t *arg_0xa7d86f0);
# 63 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/CC2420Radio/CC2420ControlM.nc"
enum CC2420ControlM$__nesc_unnamed4308 {
  CC2420ControlM$IDLE_STATE = 0, 
  CC2420ControlM$INIT_STATE, 
  CC2420ControlM$INIT_STATE_DONE, 
  CC2420ControlM$START_STATE, 
  CC2420ControlM$START_STATE_DONE, 
  CC2420ControlM$STOP_STATE
};

uint8_t CC2420ControlM$state = 0;
 uint16_t CC2420ControlM$gCurrentParameters[14];
static inline 





bool CC2420ControlM$SetRegs(void);
static inline  
#line 108
void CC2420ControlM$taskInitDone(void);
static inline  






void CC2420ControlM$PostOscillatorOn(void);
static inline  
#line 129
result_t CC2420ControlM$SplitControl$init(void);
static inline  
#line 227
result_t CC2420ControlM$SplitControl$start(void);
static inline  
#line 286
result_t CC2420ControlM$CC2420Control$TuneManual(uint16_t DesiredFreq);
static inline   
#line 343
result_t CC2420ControlM$CC2420Control$RxMode(void);
static inline   
#line 368
result_t CC2420ControlM$CC2420Control$OscillatorOn(void);
static inline   
#line 400
result_t CC2420ControlM$CC2420Control$VREFOn(void);
static inline  
#line 432
result_t CC2420ControlM$CC2420Control$setShortAddress(uint16_t addr);
static inline   







result_t CC2420ControlM$HPLChipconRAM$writeDone(uint16_t addr, uint8_t length, uint8_t *buffer);
static inline   


result_t CC2420ControlM$CCA$fired(void);
static  
# 63 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/StdControl.nc"
result_t HPLCC2420M$TimerControl$init(void);
static   
# 49 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/CC2420Radio/HPLCC2420RAM.nc"
result_t HPLCC2420M$HPLCC2420RAM$writeDone(uint16_t arg_0xa7d8b70, uint8_t arg_0xa7d8cb8, uint8_t *arg_0xa7d8e18);
 
# 55 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/micaz/HPLCC2420M.nc"
bool HPLCC2420M$bSpiAvail;
 uint8_t *HPLCC2420M$rambuf;
 uint8_t HPLCC2420M$ramlen;
 uint16_t HPLCC2420M$ramaddr;
static inline  





result_t HPLCC2420M$StdControl$init(void);
static inline  
#line 95
result_t HPLCC2420M$StdControl$start(void);
static   






uint8_t HPLCC2420M$HPLCC2420$cmd(uint8_t addr);
static   
#line 128
result_t HPLCC2420M$HPLCC2420$write(uint8_t addr, uint16_t data);
static   
#line 159
uint16_t HPLCC2420M$HPLCC2420$read(uint8_t addr);
static inline  
#line 197
void HPLCC2420M$signalRAMWr(void);
static inline   









result_t HPLCC2420M$HPLCC2420RAM$write(uint16_t addr, uint8_t length, uint8_t *buffer);
static   
# 50 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/CC2420Radio/HPLCC2420FIFO.nc"
result_t HPLCC2420FIFOM$HPLCC2420FIFO$TXFIFODone(uint8_t arg_0xa790010, uint8_t *arg_0xa790170);
static   
#line 39
result_t HPLCC2420FIFOM$HPLCC2420FIFO$RXFIFODone(uint8_t arg_0xa765970, uint8_t *arg_0xa765ad0);
 
# 51 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/micaz/HPLCC2420FIFOM.nc"
bool HPLCC2420FIFOM$bSpiAvail;
 uint8_t *HPLCC2420FIFOM$txbuf;
#line 52
uint8_t *HPLCC2420FIFOM$rxbuf;
 uint8_t HPLCC2420FIFOM$txlength;
 
#line 53
uint8_t HPLCC2420FIFOM$rxlength;
bool HPLCC2420FIFOM$rxbufBusy;
#line 54
bool HPLCC2420FIFOM$txbufBusy;
static inline  

void HPLCC2420FIFOM$signalTXdone(void);
static inline  
#line 74
void HPLCC2420FIFOM$signalRXdone(void);
static inline   
#line 95
result_t HPLCC2420FIFOM$HPLCC2420FIFO$writeTXFIFO(uint8_t len, uint8_t *msg);
static inline   
#line 146
result_t HPLCC2420FIFOM$HPLCC2420FIFO$readRXFIFO(uint8_t len, uint8_t *msg);
static   
# 51 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/CC2420Radio/HPLCC2420Interrupt.nc"
result_t HPLCC2420InterruptM$FIFO$fired(void);
static   
#line 51
result_t HPLCC2420InterruptM$FIFOP$fired(void);
static  
# 59 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/Timer.nc"
result_t HPLCC2420InterruptM$CCATimer$start(char arg_0xa344320, uint32_t arg_0xa344478);
static  
#line 59
result_t HPLCC2420InterruptM$FIFOTimer$start(char arg_0xa344320, uint32_t arg_0xa344478);
static   
# 62 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/micaz/TimerCapture.nc"
void HPLCC2420InterruptM$SFDCapture$enableEvents(void);
static   void HPLCC2420InterruptM$SFDCapture$disableEvents(void);
static   
#line 52
void HPLCC2420InterruptM$SFDCapture$clearOverflow(void);
static   
#line 47
bool HPLCC2420InterruptM$SFDCapture$isOverflowPending(void);
static   
#line 40
void HPLCC2420InterruptM$SFDCapture$setEdge(uint8_t arg_0xa83f938);
static   
# 51 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/CC2420Radio/HPLCC2420Interrupt.nc"
result_t HPLCC2420InterruptM$CCA$fired(void);
static   
# 53 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/CC2420Radio/HPLCC2420Capture.nc"
result_t HPLCC2420InterruptM$SFD$captured(uint16_t arg_0xa78da10);
 
# 57 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/micaz/HPLCC2420InterruptM.nc"
uint8_t HPLCC2420InterruptM$FIFOWaitForState;
 uint8_t HPLCC2420InterruptM$FIFOLastState;
 
uint8_t HPLCC2420InterruptM$CCAWaitForState;
 uint8_t HPLCC2420InterruptM$CCALastState;
static inline   
#line 78
result_t HPLCC2420InterruptM$FIFOP$startWait(bool low_to_high);
static inline   









result_t HPLCC2420InterruptM$FIFOP$disable(void);







void __attribute((signal))   __vector_7(void);
static inline  
#line 125
result_t HPLCC2420InterruptM$FIFOTimer$fired(void);
static inline    
#line 150
result_t HPLCC2420InterruptM$FIFO$default$fired(void);
static inline   






result_t HPLCC2420InterruptM$CCA$startWait(bool low_to_high);
static inline  
#line 175
result_t HPLCC2420InterruptM$CCATimer$fired(void);
static inline   
#line 200
result_t HPLCC2420InterruptM$SFD$enableCapture(bool low_to_high);
static inline   









result_t HPLCC2420InterruptM$SFD$disable(void);
static   








void HPLCC2420InterruptM$SFDCapture$captured(uint16_t time);
static   
# 177 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/micaz/Clock16.nc"
result_t HPLTimer1M$Timer1$fire(void);
static   
# 72 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/micaz/TimerCapture.nc"
void HPLTimer1M$CaptureT1$captured(uint16_t arg_0xa837500);
# 43 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/micaz/HPLTimer1M.nc"
uint8_t HPLTimer1M$set_flag;
uint8_t HPLTimer1M$mscale;
#line 44
uint8_t HPLTimer1M$nextScale;
uint16_t HPLTimer1M$minterval;
static inline  
result_t HPLTimer1M$StdControl$init(void);
static inline  






result_t HPLTimer1M$StdControl$start(void);
static inline   
#line 129
result_t HPLTimer1M$Timer1$setRate(uint16_t interval, char scale);
static inline    
#line 168
result_t HPLTimer1M$Timer1$default$fire(void);

void __attribute((interrupt))   __vector_12(void);
static   
#line 194
void HPLTimer1M$CaptureT1$setEdge(uint8_t LowToHigh);
static inline   
#line 219
bool HPLTimer1M$CaptureT1$isOverflowPending(void);
static inline   






uint16_t HPLTimer1M$CaptureT1$getEvent(void);
static inline   







void HPLTimer1M$CaptureT1$clearOverflow(void);
static inline   
#line 252
void HPLTimer1M$CaptureT1$enableEvents(void);
static inline   








void HPLTimer1M$CaptureT1$disableEvents(void);
#line 278
void __attribute((signal))   __vector_11(void);
static   
# 12 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/CC2420Radio/TimerJiffyAsync.nc"
result_t TimerJiffyAsyncM$TimerJiffyAsync$fired(void);
static   
# 148 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/Clock.nc"
result_t TimerJiffyAsyncM$Timer$setIntervalAndScale(uint8_t arg_0xa36e880, uint8_t arg_0xa36e9c8);
static   
#line 168
void TimerJiffyAsyncM$Timer$intDisable(void);
# 18 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/micaz/TimerJiffyAsyncM.nc"
uint32_t TimerJiffyAsyncM$jiffy;
bool TimerJiffyAsyncM$bSet;
static inline  

result_t TimerJiffyAsyncM$StdControl$init(void);
static inline  




result_t TimerJiffyAsyncM$StdControl$start(void);
static inline   
#line 44
result_t TimerJiffyAsyncM$Timer$fire(void);
static   
#line 61
result_t TimerJiffyAsyncM$TimerJiffyAsync$setOneShot(uint32_t _jiffy);
static inline   
#line 76
bool TimerJiffyAsyncM$TimerJiffyAsync$isSet(void);
static inline   



result_t TimerJiffyAsyncM$TimerJiffyAsync$stop(void);
static   
# 180 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/Clock.nc"
result_t HPLTimer2$Timer2$fire(void);
# 56 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/micaz/HPLTimer2.nc"
uint8_t HPLTimer2$set_flag;
uint8_t HPLTimer2$mscale;
#line 57
uint8_t HPLTimer2$nextScale;
#line 57
uint8_t HPLTimer2$minterval;
static   
#line 118
result_t HPLTimer2$Timer2$setIntervalAndScale(uint8_t interval, uint8_t scale);
static inline   
#line 165
void HPLTimer2$Timer2$intDisable(void);






void __attribute((interrupt))   __vector_9(void);
static  
# 75 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/ReceiveMsg.nc"
TOS_MsgPtr FramerM$ReceiveMsg$receive(TOS_MsgPtr arg_0xa485df0);
static   
# 55 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/ByteComm.nc"
result_t FramerM$ByteComm$txByte(uint8_t arg_0xa8c2870);
static  
# 63 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/StdControl.nc"
result_t FramerM$ByteControl$init(void);
static  





result_t FramerM$ByteControl$start(void);
static  
# 67 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/BareSendMsg.nc"
result_t FramerM$BareSendMsg$sendDone(TOS_MsgPtr arg_0xa71ecc8, result_t arg_0xa71ee18);
static  
# 75 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/TokenReceiveMsg.nc"
TOS_MsgPtr FramerM$TokenReceiveMsg$receive(TOS_MsgPtr arg_0xa8c64b0, uint8_t arg_0xa8c65f8);
# 82 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/micaz/FramerM.nc"
enum FramerM$__nesc_unnamed4309 {
  FramerM$HDLC_QUEUESIZE = 2, 

  FramerM$HDLC_MTU = sizeof(TOS_Msg ) - 5, 



  FramerM$HDLC_FLAG_BYTE = 0x7e, 
  FramerM$HDLC_CTLESC_BYTE = 0x7d, 
  FramerM$PROTO_ACK = 64, 
  FramerM$PROTO_PACKET_ACK = 65, 
  FramerM$PROTO_PACKET_NOACK = 66, 
  FramerM$PROTO_UNKNOWN = 255
};

enum FramerM$__nesc_unnamed4310 {
  FramerM$RXSTATE_NOSYNC, 
  FramerM$RXSTATE_PROTO, 
  FramerM$RXSTATE_TOKEN, 
  FramerM$RXSTATE_INFO, 
  FramerM$RXSTATE_ESC
};

enum FramerM$__nesc_unnamed4311 {
  FramerM$TXSTATE_IDLE, 
  FramerM$TXSTATE_PROTO, 
  FramerM$TXSTATE_INFO, 
  FramerM$TXSTATE_ESC, 
  FramerM$TXSTATE_FCS1, 
  FramerM$TXSTATE_FCS2, 
  FramerM$TXSTATE_ENDFLAG, 
  FramerM$TXSTATE_FINISH, 
  FramerM$TXSTATE_ERROR
};

enum FramerM$__nesc_unnamed4312 {
  FramerM$FLAGS_TOKENPEND = 0x2, 
  FramerM$FLAGS_DATAPEND = 0x4, 
  FramerM$FLAGS_UNKNOWN = 0x8
};

TOS_Msg FramerM$gMsgRcvBuf[FramerM$HDLC_QUEUESIZE];

typedef struct FramerM$_MsgRcvEntry {
  uint8_t Proto;
  uint8_t Token;
  uint16_t Length;
  TOS_MsgPtr pMsg;
} FramerM$MsgRcvEntry_t;

FramerM$MsgRcvEntry_t FramerM$gMsgRcvTbl[FramerM$HDLC_QUEUESIZE];

uint8_t *FramerM$gpRxBuf;
uint8_t *FramerM$gpTxBuf;

uint8_t FramerM$gFlags;
 

uint8_t FramerM$gTxState;
 uint8_t FramerM$gPrevTxState;
 uint8_t FramerM$gTxProto;
 uint16_t FramerM$gTxByteCnt;
 uint16_t FramerM$gTxLength;
 uint16_t FramerM$gTxRunningCRC;


uint8_t FramerM$gRxState;
uint8_t FramerM$gRxHeadIndex;
uint8_t FramerM$gRxTailIndex;
uint16_t FramerM$gRxByteCnt;

uint16_t FramerM$gRxRunningCRC;

TOS_MsgPtr FramerM$gpTxMsg;
uint8_t FramerM$gTxTokenBuf;
uint8_t FramerM$gTxUnknownBuf;
 uint8_t FramerM$gTxEscByte;
static  
void FramerM$PacketSent(void);
static 
uint8_t FramerM$fRemapRxPos(uint8_t InPos);
static 





uint8_t FramerM$fRemapRxPos(uint8_t InPos);
static 
#line 184
result_t FramerM$StartTx(void);
static inline  
#line 244
void FramerM$PacketUnknown(void);
static inline  






void FramerM$PacketRcvd(void);
static  
#line 291
void FramerM$PacketSent(void);
static 
#line 313
void FramerM$HDLCInitialize(void);
static inline  
#line 336
result_t FramerM$StdControl$init(void);
static inline  



result_t FramerM$StdControl$start(void);
static inline  








result_t FramerM$BareSendMsg$send(TOS_MsgPtr pMsg);
static inline  
#line 373
result_t FramerM$TokenReceiveMsg$ReflectToken(uint8_t Token);
static   
#line 393
result_t FramerM$ByteComm$rxByteReady(uint8_t data, bool error, uint16_t strength);
static 
#line 520
result_t FramerM$TxArbitraryByte(uint8_t inByte);
static inline   
#line 533
result_t FramerM$ByteComm$txByteReady(bool LastByteSuccess);
static inline   
#line 611
result_t FramerM$ByteComm$txDone(void);
static  
# 75 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/ReceiveMsg.nc"
TOS_MsgPtr FramerAckM$ReceiveCombined$receive(TOS_MsgPtr arg_0xa485df0);
static  
# 88 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/TokenReceiveMsg.nc"
result_t FramerAckM$TokenReceiveMsg$ReflectToken(uint8_t arg_0xa8c6c10);
# 72 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/system/FramerAckM.nc"
uint8_t FramerAckM$gTokenBuf;
static inline  
void FramerAckM$SendAckTask(void);
static inline  



TOS_MsgPtr FramerAckM$TokenReceiveMsg$receive(TOS_MsgPtr Msg, uint8_t token);
static inline  
#line 91
TOS_MsgPtr FramerAckM$ReceiveMsg$receive(TOS_MsgPtr Msg);
static   
# 62 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/HPLUART.nc"
result_t UARTM$HPLUART$init(void);
static   
#line 80
result_t UARTM$HPLUART$put(uint8_t arg_0xa933388);
static   
# 83 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/ByteComm.nc"
result_t UARTM$ByteComm$txDone(void);
static   
#line 75
result_t UARTM$ByteComm$txByteReady(bool arg_0xa8c34d0);
static   
#line 66
result_t UARTM$ByteComm$rxByteReady(uint8_t arg_0xa8c2d00, bool arg_0xa8c2e48, uint16_t arg_0xa8c2fa0);
# 58 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/system/UARTM.nc"
bool UARTM$state;
static inline  
result_t UARTM$Control$init(void);
static inline  






result_t UARTM$Control$start(void);
static inline   







result_t UARTM$HPLUART$get(uint8_t data);
static   








result_t UARTM$HPLUART$putDone(void);
static   
#line 110
result_t UARTM$ByteComm$txByte(uint8_t data);
static   
# 88 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/HPLUART.nc"
result_t HPLUART0M$UART$get(uint8_t arg_0xa933888);
static   






result_t HPLUART0M$UART$putDone(void);
static inline   
# 60 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/mica2/HPLUART0M.nc"
result_t HPLUART0M$UART$init(void);
#line 90
void __attribute((signal))   __vector_18(void);









void __attribute((interrupt))   __vector_20(void);
static inline   



result_t HPLUART0M$UART$put(uint8_t data);
static  
# 63 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/StdControl.nc"
result_t TestSenseM$SensorControl$init(void);
static  





result_t TestSenseM$SensorControl$start(void);
static  






result_t TestSenseM$SensorControl$stop(void);
static  
# 6 "TestSense_interface.nc"
result_t TestSenseM$TestSense_interface$start(void);
static  
result_t TestSenseM$TestSense_interface$stop(void);
static  
# 48 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/SendMsg.nc"
result_t TestSenseM$DataMsg$send(uint16_t arg_0xa46f5a8, uint8_t arg_0xa46f6f0, TOS_MsgPtr arg_0xa46f840);
static  
# 59 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/Timer.nc"
result_t TestSenseM$TempTimer$start(char arg_0xa344320, uint32_t arg_0xa344478);
static  







result_t TestSenseM$TempTimer$stop(void);
static  
# 63 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/StdControl.nc"
result_t TestSenseM$TempControl$init(void);
static  





result_t TestSenseM$TempControl$start(void);
static  






result_t TestSenseM$TempControl$stop(void);
static  
#line 70
result_t TestSenseM$VolControl$start(void);
static  






result_t TestSenseM$VolControl$stop(void);
static  
#line 63
result_t TestSenseM$CommControl$init(void);
static  





result_t TestSenseM$CommControl$start(void);
static   
# 52 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/ADC.nc"
result_t TestSenseM$VolADC$getData(void);
static  
# 59 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/Timer.nc"
result_t TestSenseM$initTimer$start(char arg_0xa344320, uint32_t arg_0xa344478);
static  







result_t TestSenseM$initTimer$stop(void);
static   
# 131 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/Leds.nc"
result_t TestSenseM$Leds$yellowToggle(void);
static   
# 52 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/ADC.nc"
result_t TestSenseM$TempADC$getData(void);
static  
# 59 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/Timer.nc"
result_t TestSenseM$Timer$start(char arg_0xa344320, uint32_t arg_0xa344478);
static  







result_t TestSenseM$Timer$stop(void);
static   
# 52 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/ADC.nc"
result_t TestSenseM$LightADC$getData(void);
# 27 "TestSenseM.nc"
int TestSenseM$timer = 0;
uint8_t TestSenseM$packetReadingNumber;
uint16_t TestSenseM$readingNumber;
TOS_Msg TestSenseM$msg[2];
uint8_t TestSenseM$currentMsg;

uint16_t TestSenseM$gSensorDataLight;
#line 33
uint16_t TestSenseM$gSensorDataTemp;
#line 33
uint16_t TestSenseM$gSensorDataVoltage;

uint16_t TestSenseM$test = 0;


int TestSenseM$sleeping;
bool TestSenseM$gfSendBusy;

uint16_t TestSenseM$seqno = 0;
bool TestSenseM$type = 1;
bool TestSenseM$init;
static inline  



int TestSenseM$TestSense_interface$getStatus(void);
#line 85
static void TestSenseM$initialize(void);
static inline  
#line 99
result_t TestSenseM$StdControl$init(void);
static inline  
#line 113
result_t TestSenseM$StdControl$start(void);
static inline  




result_t TestSenseM$initTimer$fired(void);
static  
#line 134
void TestSenseM$SendData(void);
static  
#line 165
void TestSenseM$sendStatus(void);
static inline   
#line 198
result_t TestSenseM$LightADC$dataReady(uint16_t data);
static inline   
#line 211
result_t TestSenseM$TempADC$dataReady(uint16_t data);
static inline   
#line 224
result_t TestSenseM$VolADC$dataReady(uint16_t data);
static inline  
#line 236
result_t TestSenseM$DataMsg$sendDone(TOS_MsgPtr sent, result_t success);
static inline  


result_t TestSenseM$Timer$fired(void);
static inline  
#line 258
result_t TestSenseM$TempTimer$fired(void);
static inline  




TOS_MsgPtr TestSenseM$ResetCounterMsg$receive(TOS_MsgPtr m);
static  
# 59 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/Timer.nc"
result_t PhotoTempM$PhotoTempTimer$start(char arg_0xa344320, uint32_t arg_0xa344478);
static  







result_t PhotoTempM$PhotoTempTimer$stop(void);
static   
# 52 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/ADC.nc"
result_t PhotoTempM$InternalTempADC$getData(void);
static  
# 89 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/ADCControl.nc"
result_t PhotoTempM$ADCControl$bindPort(uint8_t arg_0xa979670, uint8_t arg_0xa9797b8);
static  
#line 50
result_t PhotoTempM$ADCControl$init(void);
static  
# 63 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/StdControl.nc"
result_t PhotoTempM$TimerControl$init(void);
static   
# 70 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/ADC.nc"
result_t PhotoTempM$ExternalTempADC$dataReady(uint16_t arg_0xa95fa50);
static   
#line 70
result_t PhotoTempM$ExternalPhotoADC$dataReady(uint16_t arg_0xa95fa50);
static   
#line 52
result_t PhotoTempM$InternalPhotoADC$getData(void);
# 111 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/sensorboards/micasb/PhotoTempM.nc"
enum PhotoTempM$__nesc_unnamed4313 {
  PhotoTempM$sensorIdle = 0, 
  PhotoTempM$sensorPhotoStarting, 
  PhotoTempM$sensorPhotoReady, 
  PhotoTempM$sensorTempStarting, 
  PhotoTempM$sensorTempReady
} PhotoTempM$hardwareStatus;



typedef enum PhotoTempM$__nesc_unnamed4314 {
  PhotoTempM$stateIdle = 0, 
  PhotoTempM$stateReadOnce, 
  PhotoTempM$stateContinuous
} PhotoTempM$SensorState_t;
PhotoTempM$SensorState_t PhotoTempM$photoSensor;
PhotoTempM$SensorState_t PhotoTempM$tempSensor;




bool PhotoTempM$waitingForSample;
static inline  
result_t PhotoTempM$PhotoStdControl$init(void);
static inline  








result_t PhotoTempM$PhotoStdControl$start(void);
static inline  





result_t PhotoTempM$PhotoStdControl$stop(void);
static inline  





result_t PhotoTempM$TempStdControl$init(void);
static inline  








result_t PhotoTempM$TempStdControl$start(void);
static inline  





result_t PhotoTempM$TempStdControl$stop(void);
static  






void PhotoTempM$getSample(void);
static inline  
#line 291
result_t PhotoTempM$PhotoTempTimer$fired(void);
static inline   
#line 329
result_t PhotoTempM$ExternalPhotoADC$getData(void);
static inline   






result_t PhotoTempM$ExternalTempADC$getData(void);
static inline   
#line 357
result_t PhotoTempM$InternalPhotoADC$dataReady(uint16_t data);
static inline   
#line 379
result_t PhotoTempM$InternalTempADC$dataReady(uint16_t data);
static   
# 70 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/HPLADC.nc"
result_t ADCM$HPLADC$bindPort(uint8_t arg_0xa9d11b0, uint8_t arg_0xa9d12f8);
static   
#line 91
result_t ADCM$HPLADC$sampleStop(void);
static   
#line 54
result_t ADCM$HPLADC$init(void);
static   
#line 77
result_t ADCM$HPLADC$samplePort(uint8_t arg_0xa9d17e0);
static   
# 70 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/ADC.nc"
result_t ADCM$ADC$dataReady(
# 54 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/system/ADCM.nc"
uint8_t arg_0xa99f2a0, 
# 70 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/ADC.nc"
uint16_t arg_0xa95fa50);
# 63 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/system/ADCM.nc"
enum ADCM$__nesc_unnamed4315 {
  ADCM$IDLE = 0, 
  ADCM$SINGLE_CONVERSION = 1, 
  ADCM$CONTINUOUS_CONVERSION = 2
};

uint16_t ADCM$ReqPort;
uint16_t ADCM$ReqVector;
uint16_t ADCM$ContReqMask;
static inline  
result_t ADCM$ADCControl$init(void);
static inline  
#line 87
result_t ADCM$ADCControl$bindPort(uint8_t port, uint8_t adcPort);
static inline    


result_t ADCM$ADC$default$dataReady(uint8_t port, uint16_t data);
static   


result_t ADCM$HPLADC$dataReady(uint16_t data);
static 
#line 132
__inline result_t ADCM$startGet(uint8_t newState, uint8_t port);
static inline   
#line 165
result_t ADCM$ADC$getData(uint8_t port);
static   
# 99 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/HPLADC.nc"
result_t HPLADCC$ADC$dataReady(uint16_t arg_0xa9ce318);
# 57 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/avrmote/HPLADCC.nc"
bool HPLADCC$init_portmap_done;
enum HPLADCC$__nesc_unnamed4316 {
  HPLADCC$TOSH_ADC_PORTMAPSIZE = 10
};

uint8_t HPLADCC$TOSH_adc_portmap[HPLADCC$TOSH_ADC_PORTMAPSIZE];
static 
void HPLADCC$init_portmap(void);
static   
#line 76
result_t HPLADCC$ADC$init(void);
static   
#line 96
result_t HPLADCC$ADC$bindPort(uint8_t port, uint8_t adcPort);
static   
#line 109
result_t HPLADCC$ADC$samplePort(uint8_t port);
static inline   
#line 125
result_t HPLADCC$ADC$sampleStop(void);





void __attribute((signal))   __vector_21(void);
static  
# 89 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/ADCControl.nc"
result_t VoltageM$ADCControl$bindPort(uint8_t arg_0xa979670, uint8_t arg_0xa9797b8);
static  
#line 50
result_t VoltageM$ADCControl$init(void);
static   
# 70 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/ADC.nc"
result_t VoltageM$Voltage$dataReady(uint16_t arg_0xa95fa50);
static   
#line 52
result_t VoltageM$ADC$getData(void);
# 47 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/micaz/VoltageM.nc"
enum VoltageM$__nesc_unnamed4317 {
  VoltageM$ERROR_VOLTAGE = 0xffff
};

enum VoltageM$__nesc_unnamed4318 {
  VoltageM$S_IDLE, 
  VoltageM$S_GET_DATA
};

uint8_t VoltageM$state;
uint16_t VoltageM$voltage;
static  





result_t VoltageM$StdControl$start(void);
static inline  







result_t VoltageM$StdControl$stop(void);
static inline 


void VoltageM$signalReady(uint16_t v);
static inline  



void VoltageM$signalReadyTask(void);
static   









result_t VoltageM$Voltage$getData(void);
static inline   
#line 118
result_t VoltageM$ADC$dataReady(uint16_t data);
# 117 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/micaz/hardware.h"
static __inline void TOSH_SET_GREEN_LED_PIN(void)
#line 117
{
#line 117
  * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x1B + 0x20) |= 1 << 1;
}

#line 118
static __inline void TOSH_SET_YELLOW_LED_PIN(void)
#line 118
{
#line 118
  * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x1B + 0x20) |= 1 << 0;
}

#line 116
static __inline void TOSH_SET_RED_LED_PIN(void)
#line 116
{
#line 116
  * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x1B + 0x20) |= 1 << 2;
}

#line 155
static __inline void TOSH_SET_FLASH_SELECT_PIN(void)
#line 155
{
#line 155
  * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x1B + 0x20) |= 1 << 3;
}

#line 156
static __inline void TOSH_MAKE_FLASH_CLK_OUTPUT(void)
#line 156
{
#line 156
  * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x11 + 0x20) |= 1 << 5;
}

#line 157
static __inline void TOSH_MAKE_FLASH_OUT_OUTPUT(void)
#line 157
{
#line 157
  * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x11 + 0x20) |= 1 << 3;
}

#line 155
static __inline void TOSH_MAKE_FLASH_SELECT_OUTPUT(void)
#line 155
{
#line 155
  * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x1A + 0x20) |= 1 << 3;
}

#line 120
static __inline void TOSH_CLR_SERIAL_ID_PIN(void)
#line 120
{
#line 120
  * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x1B + 0x20) &= ~(1 << 4);
}

#line 120
static __inline void TOSH_MAKE_SERIAL_ID_INPUT(void)
#line 120
{
#line 120
  * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x1A + 0x20) &= ~(1 << 4);
}

#line 152
static __inline void TOSH_MAKE_RADIO_CCA_INPUT(void)
#line 152
{
#line 152
  * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x11 + 0x20) &= ~(1 << 6);
}

#line 150
static __inline void TOSH_MAKE_CC_FIFO_INPUT(void)
#line 150
{
#line 150
  * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x17 + 0x20) &= ~(1 << 7);
}

#line 148
static __inline void TOSH_MAKE_CC_SFD_INPUT(void)
#line 148
{
#line 148
  * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x11 + 0x20) &= ~(1 << 4);
}

#line 147
static __inline void TOSH_MAKE_CC_CCA_INPUT(void)
#line 147
{
#line 147
  * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x11 + 0x20) &= ~(1 << 6);
}

#line 145
static __inline void TOSH_MAKE_CC_FIFOP1_INPUT(void)
#line 145
{
#line 145
  * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x02 + 0x20) &= ~(1 << 6);
}


static __inline void TOSH_MAKE_CC_CS_INPUT(void)
#line 149
{
#line 149
  * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x17 + 0x20) &= ~(1 << 0);
}

#line 142
static __inline void TOSH_MAKE_CC_VREN_OUTPUT(void)
#line 142
{
#line 142
  * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x1A + 0x20) |= 1 << 5;
}

#line 141
static __inline void TOSH_MAKE_CC_RSTN_OUTPUT(void)
#line 141
{
#line 141
  * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x1A + 0x20) |= 1 << 6;
}

#line 170
static __inline void TOSH_MAKE_SPI_SCK_OUTPUT(void)
#line 170
{
#line 170
  * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x17 + 0x20) |= 1 << 1;
}

#line 167
static __inline void TOSH_MAKE_MOSI_OUTPUT(void)
#line 167
{
#line 167
  * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x17 + 0x20) |= 1 << 2;
}

#line 168
static __inline void TOSH_MAKE_MISO_INPUT(void)
#line 168
{
#line 168
  * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x17 + 0x20) &= ~(1 << 3);
}



static __inline void TOSH_MAKE_PW0_OUTPUT(void)
#line 173
{
#line 173
  * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x14 + 0x20) |= 1 << 0;
}

#line 174
static __inline void TOSH_MAKE_PW1_OUTPUT(void)
#line 174
{
#line 174
  * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x14 + 0x20) |= 1 << 1;
}

#line 175
static __inline void TOSH_MAKE_PW2_OUTPUT(void)
#line 175
{
#line 175
  * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x14 + 0x20) |= 1 << 2;
}

#line 176
static __inline void TOSH_MAKE_PW3_OUTPUT(void)
#line 176
{
#line 176
  * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x14 + 0x20) |= 1 << 3;
}

#line 177
static __inline void TOSH_MAKE_PW4_OUTPUT(void)
#line 177
{
#line 177
  * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x14 + 0x20) |= 1 << 4;
}

#line 178
static __inline void TOSH_MAKE_PW5_OUTPUT(void)
#line 178
{
#line 178
  * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x14 + 0x20) |= 1 << 5;
}

#line 179
static __inline void TOSH_MAKE_PW6_OUTPUT(void)
#line 179
{
#line 179
  * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x14 + 0x20) |= 1 << 6;
}

#line 180
static __inline void TOSH_MAKE_PW7_OUTPUT(void)
#line 180
{
#line 180
  * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x14 + 0x20) |= 1 << 7;
}

#line 117
static __inline void TOSH_MAKE_GREEN_LED_OUTPUT(void)
#line 117
{
#line 117
  * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x1A + 0x20) |= 1 << 1;
}

#line 118
static __inline void TOSH_MAKE_YELLOW_LED_OUTPUT(void)
#line 118
{
#line 118
  * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x1A + 0x20) |= 1 << 0;
}

#line 116
static __inline void TOSH_MAKE_RED_LED_OUTPUT(void)
#line 116
{
#line 116
  * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x1A + 0x20) |= 1 << 2;
}

static inline 
#line 196
void TOSH_SET_PIN_DIRECTIONS(void )
{







  TOSH_MAKE_RED_LED_OUTPUT();
  TOSH_MAKE_YELLOW_LED_OUTPUT();
  TOSH_MAKE_GREEN_LED_OUTPUT();


  TOSH_MAKE_PW7_OUTPUT();
  TOSH_MAKE_PW6_OUTPUT();
  TOSH_MAKE_PW5_OUTPUT();
  TOSH_MAKE_PW4_OUTPUT();
  TOSH_MAKE_PW3_OUTPUT();
  TOSH_MAKE_PW2_OUTPUT();
  TOSH_MAKE_PW1_OUTPUT();
  TOSH_MAKE_PW0_OUTPUT();


  TOSH_MAKE_MISO_INPUT();
  TOSH_MAKE_MOSI_OUTPUT();
  TOSH_MAKE_SPI_SCK_OUTPUT();
  TOSH_MAKE_CC_RSTN_OUTPUT();
  TOSH_MAKE_CC_VREN_OUTPUT();
  TOSH_MAKE_CC_CS_INPUT();
  TOSH_MAKE_CC_FIFOP1_INPUT();
  TOSH_MAKE_CC_CCA_INPUT();
  TOSH_MAKE_CC_SFD_INPUT();
  TOSH_MAKE_CC_FIFO_INPUT();

  TOSH_MAKE_RADIO_CCA_INPUT();



  TOSH_MAKE_SERIAL_ID_INPUT();
  TOSH_CLR_SERIAL_ID_PIN();

  TOSH_MAKE_FLASH_SELECT_OUTPUT();
  TOSH_MAKE_FLASH_OUT_OUTPUT();
  TOSH_MAKE_FLASH_CLK_OUTPUT();
  TOSH_SET_FLASH_SELECT_PIN();

  TOSH_SET_RED_LED_PIN();
  TOSH_SET_YELLOW_LED_PIN();
  TOSH_SET_GREEN_LED_PIN();
}

static inline  
# 57 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/avrmote/HPLInit.nc"
result_t HPLInit$init(void)
#line 57
{
  TOSH_SET_PIN_DIRECTIONS();
  return SUCCESS;
}

# 47 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/system/RealMain.nc"
inline static  result_t RealMain$hardwareInit(void){
#line 47
  unsigned char result;
#line 47

#line 47
  result = HPLInit$init();
#line 47

#line 47
  return result;
#line 47
}
#line 47
static inline  
# 75 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/mica2/HPLPotC.nc"
result_t HPLPotC$Pot$finalise(void)
#line 75
{


  return SUCCESS;
}

# 74 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/HPLPot.nc"
inline static  result_t PotM$HPLPot$finalise(void){
#line 74
  unsigned char result;
#line 74

#line 74
  result = HPLPotC$Pot$finalise();
#line 74

#line 74
  return result;
#line 74
}
#line 74
static inline  
# 66 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/mica2/HPLPotC.nc"
result_t HPLPotC$Pot$increase(void)
#line 66
{





  return SUCCESS;
}

# 67 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/HPLPot.nc"
inline static  result_t PotM$HPLPot$increase(void){
#line 67
  unsigned char result;
#line 67

#line 67
  result = HPLPotC$Pot$increase();
#line 67

#line 67
  return result;
#line 67
}
#line 67
static inline  
# 57 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/mica2/HPLPotC.nc"
result_t HPLPotC$Pot$decrease(void)
#line 57
{





  return SUCCESS;
}

# 59 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/HPLPot.nc"
inline static  result_t PotM$HPLPot$decrease(void){
#line 59
  unsigned char result;
#line 59

#line 59
  result = HPLPotC$Pot$decrease();
#line 59

#line 59
  return result;
#line 59
}
#line 59
static inline 
# 93 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/system/PotM.nc"
void PotM$setPot(uint8_t value)
#line 93
{
  uint8_t i;

#line 95
  for (i = 0; i < 151; i++) 
    PotM$HPLPot$decrease();

  for (i = 0; i < value; i++) 
    PotM$HPLPot$increase();

  PotM$HPLPot$finalise();

  PotM$potSetting = value;
}

static inline  result_t PotM$Pot$init(uint8_t initialSetting)
#line 106
{
  PotM$setPot(initialSetting);
  return SUCCESS;
}

# 78 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/Pot.nc"
inline static  result_t RealMain$Pot$init(uint8_t arg_0xa2f4d98){
#line 78
  unsigned char result;
#line 78

#line 78
  result = PotM$Pot$init(arg_0xa2f4d98);
#line 78

#line 78
  return result;
#line 78
}
#line 78
static inline 
# 79 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/system/sched.c"
void TOSH_sched_init(void )
{
  int i;

#line 82
  TOSH_sched_free = 0;
  TOSH_sched_full = 0;
  for (i = 0; i < TOSH_MAX_TASKS; i++) 
    TOSH_queue[i].tp = (void *)0;
}

static inline 
# 120 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/system/tos.h"
result_t rcombine(result_t r1, result_t r2)



{
  return r1 == FAIL ? FAIL : r2;
}

static inline   
# 58 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/system/LedsC.nc"
result_t LedsC$Leds$init(void)
#line 58
{
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 59
    {
      LedsC$ledsOn = 0;
      {
      }
#line 61
      ;
      TOSH_MAKE_RED_LED_OUTPUT();
      TOSH_MAKE_YELLOW_LED_OUTPUT();
      TOSH_MAKE_GREEN_LED_OUTPUT();
      TOSH_SET_RED_LED_PIN();
      TOSH_SET_YELLOW_LED_PIN();
      TOSH_SET_GREEN_LED_PIN();
    }
#line 68
    __nesc_atomic_end(__nesc_atomic); }
  return SUCCESS;
}

# 56 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/Leds.nc"
inline static   result_t BlinkM$Leds$init(void){
#line 56
  unsigned char result;
#line 56

#line 56
  result = LedsC$Leds$init();
#line 56

#line 56
  return result;
#line 56
}
#line 56
static inline  
# 59 "BlinkM.nc"
result_t BlinkM$StdControl$init(void)
#line 59
{
  BlinkM$Leds$init();
  return SUCCESS;
}

# 85 "TestSenseM.nc"
static void TestSenseM$initialize(void)
#line 85
{
  TestSenseM$timer = 0;
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 87
    TestSenseM$gfSendBusy = FALSE;
#line 87
    __nesc_atomic_end(__nesc_atomic); }
  TestSenseM$sleeping = 1;
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 89
    TestSenseM$init = FALSE;
#line 89
    __nesc_atomic_end(__nesc_atomic); }

  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 91
    {
      TestSenseM$gfSendBusy = FALSE;
      TestSenseM$currentMsg = 0;
      TestSenseM$packetReadingNumber = 0;
      TestSenseM$readingNumber = 0;
    }
#line 96
    __nesc_atomic_end(__nesc_atomic); }
}

# 63 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/StdControl.nc"
inline static  result_t TestSenseM$CommControl$init(void){
#line 63
  unsigned char result;
#line 63

#line 63
  result = AMStandard$Control$init();
#line 63

#line 63
  return result;
#line 63
}
#line 63
# 54 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/HPLADC.nc"
inline static   result_t ADCM$HPLADC$init(void){
#line 54
  unsigned char result;
#line 54

#line 54
  result = HPLADCC$ADC$init();
#line 54

#line 54
  return result;
#line 54
}
#line 54
static inline  
# 73 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/system/ADCM.nc"
result_t ADCM$ADCControl$init(void)
#line 73
{
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 74
    {
      ADCM$ReqPort = 0;
      ADCM$ReqVector = ADCM$ContReqMask = 0;
    }
#line 77
    __nesc_atomic_end(__nesc_atomic); }
  {
  }
#line 78
  ;

  return ADCM$HPLADC$init();
}

# 50 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/ADCControl.nc"
inline static  result_t PhotoTempM$ADCControl$init(void){
#line 50
  unsigned char result;
#line 50

#line 50
  result = ADCM$ADCControl$init();
#line 50

#line 50
  return result;
#line 50
}
#line 50
# 63 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/StdControl.nc"
inline static  result_t PhotoTempM$TimerControl$init(void){
#line 63
  unsigned char result;
#line 63

#line 63
  result = TimerM$StdControl$init();
#line 63

#line 63
  return result;
#line 63
}
#line 63
# 70 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/HPLADC.nc"
inline static   result_t ADCM$HPLADC$bindPort(uint8_t arg_0xa9d11b0, uint8_t arg_0xa9d12f8){
#line 70
  unsigned char result;
#line 70

#line 70
  result = HPLADCC$ADC$bindPort(arg_0xa9d11b0, arg_0xa9d12f8);
#line 70

#line 70
  return result;
#line 70
}
#line 70
static inline  
# 87 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/system/ADCM.nc"
result_t ADCM$ADCControl$bindPort(uint8_t port, uint8_t adcPort)
#line 87
{
  return ADCM$HPLADC$bindPort(port, adcPort);
}

# 89 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/ADCControl.nc"
inline static  result_t PhotoTempM$ADCControl$bindPort(uint8_t arg_0xa979670, uint8_t arg_0xa9797b8){
#line 89
  unsigned char result;
#line 89

#line 89
  result = ADCM$ADCControl$bindPort(arg_0xa979670, arg_0xa9797b8);
#line 89

#line 89
  return result;
#line 89
}
#line 89
static inline  
# 158 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/sensorboards/micasb/PhotoTempM.nc"
result_t PhotoTempM$TempStdControl$init(void)
#line 158
{
  PhotoTempM$ADCControl$bindPort(TOS_ADC_TEMP_PORT, TOSH_ACTUAL_TEMP_PORT);
  PhotoTempM$TimerControl$init();
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 161
    {
      PhotoTempM$tempSensor = PhotoTempM$stateIdle;
    }
#line 163
    __nesc_atomic_end(__nesc_atomic); }
#line 163
  ;
  {
  }
#line 164
  ;
  return PhotoTempM$ADCControl$init();
}

# 63 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/StdControl.nc"
inline static  result_t TestSenseM$TempControl$init(void){
#line 63
  unsigned char result;
#line 63

#line 63
  result = PhotoTempM$TempStdControl$init();
#line 63

#line 63
  return result;
#line 63
}
#line 63
static inline  
# 134 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/sensorboards/micasb/PhotoTempM.nc"
result_t PhotoTempM$PhotoStdControl$init(void)
#line 134
{
  PhotoTempM$ADCControl$bindPort(TOS_ADC_PHOTO_PORT, TOSH_ACTUAL_PHOTO_PORT);
  PhotoTempM$TimerControl$init();
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 137
    {
      PhotoTempM$photoSensor = PhotoTempM$stateIdle;
    }
#line 139
    __nesc_atomic_end(__nesc_atomic); }
#line 139
  ;
  {
  }
#line 140
  ;
  return PhotoTempM$ADCControl$init();
}

# 63 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/StdControl.nc"
inline static  result_t TestSenseM$SensorControl$init(void){
#line 63
  unsigned char result;
#line 63

#line 63
  result = PhotoTempM$PhotoStdControl$init();
#line 63

#line 63
  return result;
#line 63
}
#line 63
static inline  
# 99 "TestSenseM.nc"
result_t TestSenseM$StdControl$init(void)
#line 99
{



  TestSenseM$SensorControl$init();
  TestSenseM$TempControl$init();
  TestSenseM$CommControl$init();

  TestSenseM$initialize();


  return SUCCESS;
}

static inline  
# 69 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/DelugeMetadataM.nc"
result_t DelugeMetadataM$SplitControl$init(void)
#line 69
{
  DelugeMetadataM$state = DelugeMetadataM$S_INIT;
  return SUCCESS;
}

# 64 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/SplitControl.nc"
inline static  result_t NetProgM$MetadataControl$init(void){
#line 64
  unsigned char result;
#line 64

#line 64
  result = DelugeMetadataM$SplitControl$init();
#line 64

#line 64
  return result;
#line 64
}
#line 64
# 33 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/Crc.nc"
inline static  uint16_t NetProgM$Crc$crc16(void *arg_0xa448f60, uint8_t arg_0xa4490a8){
#line 33
  unsigned int result;
#line 33

#line 33
  result = CrcC$Crc$crc16(arg_0xa448f60, arg_0xa4490a8);
#line 33

#line 33
  return result;
#line 33
}
#line 33
static inline 
# 49 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/NetProgM.nc"
uint16_t NetProgM$computeTosInfoCrc(NetProg_TOSInfo *tosInfo)
#line 49
{
  return NetProgM$Crc$crc16(tosInfo, sizeof(NetProg_TOSInfo ) - 2);
}

# 36 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/InternalFlash.nc"
inline static  result_t NetProgM$IFlash$read(void *arg_0xa464e98, void *arg_0xa464ff0, uint16_t arg_0xa465140){
#line 36
  unsigned char result;
#line 36

#line 36
  result = InternalFlashC$InternalFlash$read(arg_0xa464e98, arg_0xa464ff0, arg_0xa465140);
#line 36

#line 36
  return result;
#line 36
}
#line 36
static inline  
# 67 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/NetProgM.nc"
result_t NetProgM$StdControl$init(void)
#line 67
{


  NetProg_TOSInfo tosInfo;

  NetProgM$IFlash$read((uint8_t *)IFLASH_TOS_INFO_ADDR, &tosInfo, sizeof tosInfo);

  if (tosInfo.crc == NetProgM$computeTosInfoCrc(&tosInfo)) {
      TOS_AM_GROUP = tosInfo.groupId;
      { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 76
        TOS_LOCAL_ADDRESS = tosInfo.addr;
#line 76
        __nesc_atomic_end(__nesc_atomic); }
    }
  else {
      NetProgM$writeTOSinfo();
    }


  NetProgM$MetadataControl$init();

  return SUCCESS;
}

static inline  
# 37 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/FlashWPC.nc"
result_t FlashWPC$StdControl$init(void)
#line 37
{
#line 37
  return SUCCESS;
}

# 158 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/micaz/hardware.h"
static __inline void TOSH_MAKE_FLASH_IN_INPUT(void)
#line 158
{
#line 158
  * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x11 + 0x20) &= ~(1 << 2);
}

#line 158
static __inline void TOSH_CLR_FLASH_IN_PIN(void)
#line 158
{
#line 158
  * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x12 + 0x20) &= ~(1 << 2);
}

#line 157
static __inline void TOSH_SET_FLASH_OUT_PIN(void)
#line 157
{
#line 157
  * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x12 + 0x20) |= 1 << 3;
}

#line 156
static __inline void TOSH_CLR_FLASH_CLK_PIN(void)
#line 156
{
#line 156
  * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x12 + 0x20) &= ~(1 << 5);
}

static inline  
# 58 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/mica2/HPLFlash.nc"
result_t HPLFlash$FlashControl$init(void)
#line 58
{
  TOSH_MAKE_FLASH_SELECT_OUTPUT();
  TOSH_SET_FLASH_SELECT_PIN();
  TOSH_CLR_FLASH_CLK_PIN();
  TOSH_MAKE_FLASH_CLK_OUTPUT();
  TOSH_SET_FLASH_OUT_PIN();
  TOSH_MAKE_FLASH_OUT_OUTPUT();
  TOSH_CLR_FLASH_IN_PIN();
  TOSH_MAKE_FLASH_IN_INPUT();

  * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x39 + 0x20) &= ~(1 << 2);
  * (volatile unsigned char *)0x6A |= 0x30;

  return SUCCESS;
}

# 63 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/StdControl.nc"
inline static  result_t PageEEPROMM$FlashControl$init(void){
#line 63
  unsigned char result;
#line 63

#line 63
  result = HPLFlash$FlashControl$init();
#line 63

#line 63
  return result;
#line 63
}
#line 63
static inline  
# 133 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/mica/PageEEPROMM.nc"
result_t PageEEPROMM$StdControl$init(void)
#line 133
{
  PageEEPROMM$request = PageEEPROMM$IDLE;
  PageEEPROMM$waiting = PageEEPROMM$deselectRequested = FALSE;
  PageEEPROMM$flashBusy = TRUE;


  PageEEPROMM$buffer[0].page = PageEEPROMM$buffer[1].page = TOS_EEPROM_MAX_PAGES;
  PageEEPROMM$buffer[0].busy = PageEEPROMM$buffer[1].busy = FALSE;
  PageEEPROMM$buffer[0].clean = PageEEPROMM$buffer[1].clean = TRUE;
  PageEEPROMM$buffer[0].unchecked = PageEEPROMM$buffer[1].unchecked = 0;
  PageEEPROMM$buffer[0].erased = PageEEPROMM$buffer[1].erased = FALSE;

  return PageEEPROMM$FlashControl$init();
}

static inline  
# 36 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/StorageManagerM.nc"
result_t StorageManagerM$StdControl$init(void)
#line 36
{
  uint8_t i;

  for (i = 0; i < StorageManagerM$NVOLUMES; i++) 
    StorageManagerM$volumes[i].id = INVALID_VOLUME_ID;

  return SUCCESS;
}

# 63 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/StdControl.nc"
inline static  result_t RealMain$StdControl$init(void){
#line 63
  unsigned char result;
#line 63

#line 63
  result = TimerM$StdControl$init();
#line 63
  result = rcombine(result, DelugeM$StdControl$init());
#line 63
  result = rcombine(result, AMStandard$Control$init());
#line 63
  result = rcombine(result, StorageManagerM$StdControl$init());
#line 63
  result = rcombine(result, PageEEPROMM$StdControl$init());
#line 63
  result = rcombine(result, FlashWPC$StdControl$init());
#line 63
  result = rcombine(result, NetProgM$StdControl$init());
#line 63
  result = rcombine(result, DelugeM$StdControl$init());
#line 63
  result = rcombine(result, TestSenseM$StdControl$init());
#line 63
  result = rcombine(result, TimerM$StdControl$init());
#line 63
  result = rcombine(result, BlinkM$StdControl$init());
#line 63

#line 63
  return result;
#line 63
}
#line 63
static inline   
# 149 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/mica/HPLClock.nc"
result_t HPLClock$Clock$setRate(char interval, char scale)
#line 149
{
  scale &= 0x7;
  scale |= 0x8;
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 152
    {
      * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x37 + 0x20) &= ~(1 << 0);
      * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x37 + 0x20) &= ~(1 << 1);
      * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x30 + 0x20) |= 1 << 3;


      * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x33 + 0x20) = scale;
      * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x32 + 0x20) = 0;
      * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x31 + 0x20) = interval;
      * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x37 + 0x20) |= 1 << 1;
    }
#line 162
    __nesc_atomic_end(__nesc_atomic); }
  return SUCCESS;
}

# 96 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/Clock.nc"
inline static   result_t TimerM$Clock$setRate(char arg_0xa3729e8, char arg_0xa372b28){
#line 96
  unsigned char result;
#line 96

#line 96
  result = HPLClock$Clock$setRate(arg_0xa3729e8, arg_0xa372b28);
#line 96

#line 96
  return result;
#line 96
}
#line 96
# 36 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/InternalFlash.nc"
inline static  result_t DelugeM$IFlash$read(void *arg_0xa464e98, void *arg_0xa464ff0, uint16_t arg_0xa465140){
#line 36
  unsigned char result;
#line 36

#line 36
  result = InternalFlashC$InternalFlash$read(arg_0xa464e98, arg_0xa464ff0, arg_0xa465140);
#line 36

#line 36
  return result;
#line 36
}
#line 36
static inline   
# 51 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/system/NoLeds.nc"
result_t NoLeds$Leds$init(void)
#line 51
{
  return SUCCESS;
}

# 56 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/Leds.nc"
inline static   result_t DelugeM$Leds$init(void){
#line 56
  unsigned char result;
#line 56

#line 56
  result = NoLeds$Leds$init();
#line 56

#line 56
  return result;
#line 56
}
#line 56
static inline  
# 90 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/DelugePageTransferM.nc"
result_t DelugePageTransferM$StdControl$init(void)
#line 90
{
  DelugePageTransferM$changeState(DelugePageTransferM$S_DISABLED);
  DelugePageTransferM$workingImgNum = DELUGE_INVALID_IMGNUM;
  DelugePageTransferM$workingPgNum = DELUGE_INVALID_PGNUM;
  return SUCCESS;
}

# 63 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/StdControl.nc"
inline static  result_t DelugeM$PageTransferControl$init(void){
#line 63
  unsigned char result;
#line 63

#line 63
  result = DelugePageTransferM$StdControl$init();
#line 63

#line 63
  return result;
#line 63
}
#line 63
static inline  
# 400 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/DelugePageTransferM.nc"
void DelugePageTransferM$SharedMsgBuf$bufFree(void)
#line 400
{
  switch (DelugePageTransferM$state) {
      case DelugePageTransferM$S_TX_LOCKING: DelugePageTransferM$setupDataMsg();
#line 402
      break;
      case DelugePageTransferM$S_RX_LOCKING: DelugePageTransferM$setupReqMsg();
#line 403
      break;
    }
}

static inline  
# 393 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/DelugeM.nc"
void DelugeM$SharedMsgBuf$bufFree(void)
#line 393
{
}

static inline  
# 159 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/NetProgM.nc"
void NetProgM$SharedMsgBuf$bufFree(void)
#line 159
{
}

# 65 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/SharedMsgBuf.nc"
inline static  void SharedMsgBufM$SharedMsgBuf$bufFree(void){
#line 65
  NetProgM$SharedMsgBuf$bufFree();
#line 65
  DelugeM$SharedMsgBuf$bufFree();
#line 65
  DelugePageTransferM$SharedMsgBuf$bufFree();
#line 65
}
#line 65
static inline  
# 53 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/SharedMsgBufM.nc"
void SharedMsgBufM$SharedMsgBuf$unlock(void)
#line 53
{
  SharedMsgBufM$isLocked = FALSE;
  SharedMsgBufM$SharedMsgBuf$bufFree();
}

# 51 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/SharedMsgBuf.nc"
inline static  void DelugePageTransferM$SharedMsgBuf$unlock(void){
#line 51
  SharedMsgBufM$SharedMsgBuf$unlock();
#line 51
}
#line 51
static inline  
# 383 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/DelugeM.nc"
void DelugeM$PageTransfer$suppressMsgs(imgnum_t imgNum)
#line 383
{
  DelugeM$advTimers[imgNum].overheard = 1;
}

# 36 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/DelugePageTransfer.nc"
inline static  void DelugePageTransferM$PageTransfer$suppressMsgs(imgnum_t arg_0xa468788){
#line 36
  DelugeM$PageTransfer$suppressMsgs(arg_0xa468788);
#line 36
}
#line 36
static inline  
# 58 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/SharedMsgBufM.nc"
bool SharedMsgBufM$SharedMsgBuf$isLocked(void)
#line 58
{
  return SharedMsgBufM$isLocked;
}

# 59 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/SharedMsgBuf.nc"
inline static  bool DelugePageTransferM$SharedMsgBuf$isLocked(void){
#line 59
  unsigned char result;
#line 59

#line 59
  result = SharedMsgBufM$SharedMsgBuf$isLocked();
#line 59

#line 59
  return result;
#line 59
}
#line 59
static inline  
# 49 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/SharedMsgBufM.nc"
void SharedMsgBufM$SharedMsgBuf$lock(void)
#line 49
{
  SharedMsgBufM$isLocked = TRUE;
}

# 46 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/SharedMsgBuf.nc"
inline static  void DelugePageTransferM$SharedMsgBuf$lock(void){
#line 46
  SharedMsgBufM$SharedMsgBuf$lock();
#line 46
}
#line 46
static inline  
# 174 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/DelugeStorageM.nc"
result_t DelugeStorageM$DataRead$read(imgnum_t imgNum, block_addr_t addr, 
void *buf, uint16_t length)
#line 175
{
  return DelugeStorageM$newRequest(DelugeStorageM$S_READ, imgNum, addr, buf, length);
}

# 36 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/DelugeDataRead.nc"
inline static  result_t DelugePageTransferM$DataRead$read(imgnum_t arg_0xa4db580, block_addr_t arg_0xa4db6d0, void *arg_0xa4db828, uint16_t arg_0xa4db978){
#line 36
  unsigned char result;
#line 36

#line 36
  result = DelugeStorageM$DataRead$read(arg_0xa4db580, arg_0xa4db6d0, arg_0xa4db828, arg_0xa4db978);
#line 36

#line 36
  return result;
#line 36
}
#line 36
static inline  
# 238 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/BlockStorageM.nc"
result_t BlockStorageM$BlockRead$read(uint8_t id, block_addr_t addr, void *buf, block_addr_t len)
#line 238
{
  return BlockStorageM$newRequest(BlockStorageM$S_READ, id, addr, buf, len);
}

static inline   
# 235 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/DelugeStorageM.nc"
result_t DelugeStorageM$BlockRead$default$read(blockstorage_t blockId, block_addr_t addr, void *buf, block_addr_t len)
#line 235
{
#line 235
  return FAIL;
}

# 32 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/BlockRead.nc"
inline static  result_t DelugeStorageM$BlockRead$read(blockstorage_t arg_0xa528458, block_addr_t arg_0xa529268, void *arg_0xa5293c0, block_addr_t arg_0xa529510){
#line 32
  unsigned char result;
#line 32

#line 32
  switch (arg_0xa528458) {
#line 32
    case DELUGE_VOLUME_ID_0:
#line 32
      result = BlockStorageM$BlockRead$read(DELUGE_VOLUME_ID_0, arg_0xa529268, arg_0xa5293c0, arg_0xa529510);
#line 32
      break;
#line 32
    case DELUGE_VOLUME_ID_1:
#line 32
      result = BlockStorageM$BlockRead$read(DELUGE_VOLUME_ID_1, arg_0xa529268, arg_0xa5293c0, arg_0xa529510);
#line 32
      break;
#line 32
    case DELUGE_VOLUME_ID_2:
#line 32
      result = BlockStorageM$BlockRead$read(DELUGE_VOLUME_ID_2, arg_0xa529268, arg_0xa5293c0, arg_0xa529510);
#line 32
      break;
#line 32
    default:
#line 32
      result = DelugeStorageM$BlockRead$default$read(arg_0xa528458, arg_0xa529268, arg_0xa5293c0, arg_0xa529510);
#line 32
    }
#line 32

#line 32
  return result;
#line 32
}
#line 32
static inline 
# 133 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/BlockStorageM.nc"
bool BlockStorageM$admitRequest(uint8_t newState, uint8_t id)
#line 133
{
  if (BlockStorageM$state != BlockStorageM$S_IDLE) {
    return FALSE;
    }
#line 136
  BlockStorageM$client = id;
  BlockStorageM$state = newState;
  return TRUE;
}

static inline void BlockStorageM$calcRequest(block_addr_t addr, at45page_t *page, 
at45pageoffset_t *offset, at45pageoffset_t *count)
#line 142
{
  *page = addr >> AT45_PAGE_SIZE_LOG2;
  *offset = addr & ((1 << AT45_PAGE_SIZE_LOG2) - 1);
  if (BlockStorageM$bytesRemaining < (1 << AT45_PAGE_SIZE_LOG2) - *offset) {
    *count = BlockStorageM$bytesRemaining;
    }
  else {
#line 148
    *count = (1 << AT45_PAGE_SIZE_LOG2) - *offset;
    }
}

static inline   
#line 315
void BlockStorageM$BlockRead$default$readDone(uint8_t id, storage_result_t result, block_addr_t addr, void *buf, block_addr_t len)
#line 315
{
}

# 33 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/BlockRead.nc"
inline static  void BlockStorageM$BlockRead$readDone(blockstorage_t arg_0xa571390, storage_result_t arg_0xa529928, block_addr_t arg_0xa529a78, void *arg_0xa529bd0, block_addr_t arg_0xa529d20){
#line 33
  switch (arg_0xa571390) {
#line 33
    case DELUGE_VOLUME_ID_0:
#line 33
      DelugeStorageM$BlockRead$readDone(DELUGE_VOLUME_ID_0, arg_0xa529928, arg_0xa529a78, arg_0xa529bd0, arg_0xa529d20);
#line 33
      break;
#line 33
    case DELUGE_VOLUME_ID_1:
#line 33
      DelugeStorageM$BlockRead$readDone(DELUGE_VOLUME_ID_1, arg_0xa529928, arg_0xa529a78, arg_0xa529bd0, arg_0xa529d20);
#line 33
      break;
#line 33
    case DELUGE_VOLUME_ID_2:
#line 33
      DelugeStorageM$BlockRead$readDone(DELUGE_VOLUME_ID_2, arg_0xa529928, arg_0xa529a78, arg_0xa529bd0, arg_0xa529d20);
#line 33
      break;
#line 33
    default:
#line 33
      BlockStorageM$BlockRead$default$readDone(arg_0xa571390, arg_0xa529928, arg_0xa529a78, arg_0xa529bd0, arg_0xa529d20);
#line 33
    }
#line 33
}
#line 33
static inline  
# 264 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/BlockStorageM.nc"
result_t BlockStorageM$BlockRead$computeCrc(uint8_t id, block_addr_t addr, block_addr_t len)
#line 264
{
  return BlockStorageM$newRequest(BlockStorageM$S_CRC, id, addr, (void *)0, len);
}

static inline   
# 237 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/DelugeStorageM.nc"
result_t DelugeStorageM$BlockRead$default$computeCrc(blockstorage_t blockId, block_addr_t addr, block_addr_t len)
#line 237
{
#line 237
  return FAIL;
}

# 38 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/BlockRead.nc"
inline static  result_t DelugeStorageM$BlockRead$computeCrc(blockstorage_t arg_0xa528458, block_addr_t arg_0xa526820, block_addr_t arg_0xa526970){
#line 38
  unsigned char result;
#line 38

#line 38
  switch (arg_0xa528458) {
#line 38
    case DELUGE_VOLUME_ID_0:
#line 38
      result = BlockStorageM$BlockRead$computeCrc(DELUGE_VOLUME_ID_0, arg_0xa526820, arg_0xa526970);
#line 38
      break;
#line 38
    case DELUGE_VOLUME_ID_1:
#line 38
      result = BlockStorageM$BlockRead$computeCrc(DELUGE_VOLUME_ID_1, arg_0xa526820, arg_0xa526970);
#line 38
      break;
#line 38
    case DELUGE_VOLUME_ID_2:
#line 38
      result = BlockStorageM$BlockRead$computeCrc(DELUGE_VOLUME_ID_2, arg_0xa526820, arg_0xa526970);
#line 38
      break;
#line 38
    default:
#line 38
      result = DelugeStorageM$BlockRead$default$computeCrc(arg_0xa528458, arg_0xa526820, arg_0xa526970);
#line 38
    }
#line 38

#line 38
  return result;
#line 38
}
#line 38
# 59 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/Timer.nc"
inline static  result_t DelugeMetadataM$Timer$start(char arg_0xa344320, uint32_t arg_0xa344478){
#line 59
  unsigned char result;
#line 59

#line 59
  result = TimerM$Timer$start(2, arg_0xa344320, arg_0xa344478);
#line 59

#line 59
  return result;
#line 59
}
#line 59
static inline  
# 155 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/DelugeMetadataM.nc"
void DelugeMetadataM$MetadataStore$readDone(storage_result_t result)
#line 155
{

  if (result != STORAGE_OK) {
      DelugeMetadataM$Timer$start(TIMER_ONE_SHOT, 512);
      return;
    }



  if (
#line 163
  !DelugeMetadataM$Metadata$isImgDescValid(&DelugeMetadataM$imgDesc[DelugeMetadataM$curImage])
   || DelugeMetadataM$imgDesc[DelugeMetadataM$curImage].imgNum != DelugeMetadataM$curImage) {
      DelugeMetadataM$imgDesc[DelugeMetadataM$curImage].vNum = DELUGE_INVALID_VNUM;
      DelugeMetadataM$imgDesc[DelugeMetadataM$curImage].imgNum = DelugeMetadataM$curImage;
      DelugeMetadataM$imgDesc[DelugeMetadataM$curImage].numPgs = 0;
      DelugeMetadataM$imgDesc[DelugeMetadataM$curImage].numPgsComplete = 0;
      DelugeMetadataM$scanNextImage();
      return;
    }

  DelugeMetadataM$verifyNextPage();
}

# 36 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/DelugeMetadataStore.nc"
inline static  void DelugeStorageM$MetadataStore$readDone(storage_result_t arg_0xa4c96d8){
#line 36
  DelugeMetadataM$MetadataStore$readDone(arg_0xa4c96d8);
#line 36
}
#line 36
static inline 
# 64 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/mica2/HPLPowerManagementM.nc"
uint8_t HPLPowerManagementM$getPowerLevel(void)
#line 64
{
  uint8_t diff;

#line 66
  if (* (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x37 + 0x20) & ~((1 << 1) | (1 << 0))) {

      return HPLPowerManagementM$IDLE;
    }
  else {
#line 69
    if (* (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x0D + 0x20) & (1 << 7)) {
        return HPLPowerManagementM$IDLE;
      }
    else {
      if (* (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x06 + 0x20) & (1 << 7)) {
          return HPLPowerManagementM$ADC_NR;
        }
      else {
#line 75
        if (* (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x37 + 0x20) & ((1 << 1) | (1 << 0))) {
            diff = * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x31 + 0x20) - * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x32 + 0x20);
            if (diff < 16) {
              return HPLPowerManagementM$EXT_STANDBY;
              }
#line 79
            return HPLPowerManagementM$POWER_SAVE;
          }
        else 
#line 80
          {
            return HPLPowerManagementM$POWER_DOWN;
          }
        }
      }
    }
}

static inline  
#line 85
void HPLPowerManagementM$doAdjustment(void)
#line 85
{
  uint8_t foo;
#line 86
  uint8_t mcu;

#line 87
  HPLPowerManagementM$powerLevel = foo = HPLPowerManagementM$getPowerLevel();
  mcu = * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x35 + 0x20);
  mcu &= 0xe3;
  if (foo == HPLPowerManagementM$EXT_STANDBY || foo == HPLPowerManagementM$POWER_SAVE) {
      mcu |= HPLPowerManagementM$IDLE;
      while ((* (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x30 + 0x20) & 0x7) != 0) {
           __asm volatile ("nop");}

      mcu &= 0xe3;
    }
  mcu |= foo;
  * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x35 + 0x20) = mcu;
  * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x35 + 0x20) |= 1 << 5;
}

# 33 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/Crc.nc"
inline static  uint16_t DelugeMetadataM$Crc$crc16(void *arg_0xa448f60, uint8_t arg_0xa4490a8){
#line 33
  unsigned int result;
#line 33

#line 33
  result = CrcC$Crc$crc16(arg_0xa448f60, arg_0xa4490a8);
#line 33

#line 33
  return result;
#line 33
}
#line 33
# 31 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/Mount.nc"
inline static  result_t BlockStorageM$ActualMount$mount(blockstorage_t arg_0xa567268, volume_id_t arg_0xa5369b8){
#line 31
  unsigned char result;
#line 31

#line 31
  result = StorageManagerM$Mount$mount(arg_0xa567268, arg_0xa5369b8);
#line 31

#line 31
  return result;
#line 31
}
#line 31
static inline  
# 319 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/BlockStorageM.nc"
result_t BlockStorageM$Mount$mount(blockstorage_t blockId, volume_id_t id)
#line 319
{
  BlockStorageM$maxAddr[id] = 0;
  return BlockStorageM$ActualMount$mount(blockId, id);
}

static inline   
# 241 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/DelugeStorageM.nc"
result_t DelugeStorageM$Mount$default$mount(blockstorage_t blockId, volume_id_t id)
#line 241
{
#line 241
  return FAIL;
}

# 31 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/Mount.nc"
inline static  result_t DelugeStorageM$Mount$mount(blockstorage_t arg_0xa53afa0, volume_id_t arg_0xa5369b8){
#line 31
  unsigned char result;
#line 31

#line 31
  switch (arg_0xa53afa0) {
#line 31
    case DELUGE_VOLUME_ID_0:
#line 31
      result = BlockStorageM$Mount$mount(DELUGE_VOLUME_ID_0, arg_0xa5369b8);
#line 31
      break;
#line 31
    case DELUGE_VOLUME_ID_1:
#line 31
      result = BlockStorageM$Mount$mount(DELUGE_VOLUME_ID_1, arg_0xa5369b8);
#line 31
      break;
#line 31
    case DELUGE_VOLUME_ID_2:
#line 31
      result = BlockStorageM$Mount$mount(DELUGE_VOLUME_ID_2, arg_0xa5369b8);
#line 31
      break;
#line 31
    default:
#line 31
      result = DelugeStorageM$Mount$default$mount(arg_0xa53afa0, arg_0xa5369b8);
#line 31
    }
#line 31

#line 31
  return result;
#line 31
}
#line 31
static inline  
# 86 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/DelugeStorageM.nc"
result_t DelugeStorageM$DelugeStorage$loadImages(void)
#line 86
{

  result_t result;

  if (DelugeStorageM$state != DelugeStorageM$S_NEVER_USED) {
    return FAIL;
    }
  DelugeStorageM$client = 0;

  result = DelugeStorageM$Mount$mount(DELUGE_IMAGES[DelugeStorageM$client].imageNum, DELUGE_IMAGES[DelugeStorageM$client].volumeId);

  if (result == SUCCESS) {
    DelugeStorageM$state = DelugeStorageM$S_MOUNTING;
    }
  return result;
}

# 34 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/DelugeStorage.nc"
inline static  result_t DelugeMetadataM$DelugeStorage$loadImages(void){
#line 34
  unsigned char result;
#line 34

#line 34
  result = DelugeStorageM$DelugeStorage$loadImages();
#line 34

#line 34
  return result;
#line 34
}
#line 34
static inline  
# 99 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/StorageManagerM.nc"
at45page_t StorageManagerM$AT45Remap$remap(volume_t volume, at45page_t volumePage)
#line 99
{
  if (volume == StorageManagerM$NVOLUMES) {
    return volumePage;
    }
  else {
#line 103
    return volumePage + StorageManagerM$volumes[volume].start;
    }
}

# 4 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/AT45Remap.nc"
inline static  at45page_t HALAT45DBShare$AT45Remap$remap(volume_t arg_0xa5630a8, at45page_t arg_0xa563200){
#line 4
  unsigned int result;
#line 4

#line 4
  result = StorageManagerM$AT45Remap$remap(arg_0xa5630a8, arg_0xa563200);
#line 4

#line 4
  return result;
#line 4
}
#line 4
static 
# 66 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/HALAT45DBShare.nc"
__inline at45page_t HALAT45DBShare$remap(at45page_t page)
#line 66
{
  return HALAT45DBShare$AT45Remap$remap(HALAT45DBShare$lastClient - 1, page);
}

static inline  
# 533 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/mica/PageEEPROMM.nc"
result_t PageEEPROMM$PageEEPROM$read(eeprompage_t page, eeprompageoffset_t offset, 
void *reqdata, eeprompageoffset_t n)
#line 534
{
  return PageEEPROMM$newRequest(PageEEPROMM$R_READ, page, offset, reqdata, n, 0);
}

# 48 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/PageEEPROM.nc"
inline static  result_t PageEEPROMShare$ActualEEPROM$read(eeprompage_t arg_0xa568418, eeprompageoffset_t arg_0xa568570, void *arg_0xa5686d8, eeprompageoffset_t arg_0xa568830){
#line 48
  unsigned char result;
#line 48

#line 48
  result = PageEEPROMM$PageEEPROM$read(arg_0xa568418, arg_0xa568570, arg_0xa5686d8, arg_0xa568830);
#line 48

#line 48
  return result;
#line 48
}
#line 48
static inline 
# 70 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/PageEEPROMShare.nc"
result_t PageEEPROMShare$check(result_t requestOk)
#line 70
{
  if (requestOk != FAIL) {
    return requestOk;
    }
#line 73
  PageEEPROMShare$lastClient = 0;
  return FAIL;
}

static inline 
#line 47
int PageEEPROMShare$setClient(uint8_t client)
#line 47
{
  if (PageEEPROMShare$NCLIENTS != 1) 
    {
      if (PageEEPROMShare$lastClient) {
        return FALSE;
        }
#line 52
      PageEEPROMShare$lastClient = client + 1;
    }
  return TRUE;
}

static 
#line 132
__inline  result_t PageEEPROMShare$PageEEPROM$read(uint8_t client, eeprompage_t page, eeprompageoffset_t offset, 
void *data, eeprompageoffset_t n)
#line 133
{
  if (!PageEEPROMShare$setClient(client)) {
    return FAIL;
    }
#line 136
  return PageEEPROMShare$check(PageEEPROMShare$ActualEEPROM$read(page, offset, data, n));
}

# 48 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/PageEEPROM.nc"
inline static  result_t HALAT45DBShare$ActualAT45$read(eeprompage_t arg_0xa568418, eeprompageoffset_t arg_0xa568570, void *arg_0xa5686d8, eeprompageoffset_t arg_0xa568830){
#line 48
  unsigned char result;
#line 48

#line 48
  result = PageEEPROMShare$PageEEPROM$read(0, arg_0xa568418, arg_0xa568570, arg_0xa5686d8, arg_0xa568830);
#line 48

#line 48
  return result;
#line 48
}
#line 48
static inline 
# 71 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/HALAT45DBShare.nc"
result_t HALAT45DBShare$check(result_t requestOk)
#line 71
{
  if (requestOk != FAIL) {
    return requestOk;
    }
#line 74
  HALAT45DBShare$lastClient = 0;
  return FAIL;
}

static inline 
#line 50
int HALAT45DBShare$setClient(volume_t client)
#line 50
{
  if (HALAT45DBShare$lastClient) {
    return FALSE;
    }
#line 53
  HALAT45DBShare$lastClient = client + 1;

  return TRUE;
}

static 
#line 133
__inline  result_t HALAT45DBShare$PageEEPROM$read(volume_t client, at45page_t page, at45pageoffset_t offset, 
void *data, at45pageoffset_t n)
#line 134
{
  if (!HALAT45DBShare$setClient(client)) {
    return FAIL;
    }
#line 137
  return HALAT45DBShare$check(HALAT45DBShare$ActualAT45$read(HALAT45DBShare$remap(page), offset, data, n));
}

# 48 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/PageEEPROM.nc"
inline static  result_t StorageManagerM$PageEEPROM$read(eeprompage_t arg_0xa568418, eeprompageoffset_t arg_0xa568570, void *arg_0xa5686d8, eeprompageoffset_t arg_0xa568830){
#line 48
  unsigned char result;
#line 48

#line 48
  result = HALAT45DBShare$PageEEPROM$read(3, arg_0xa568418, arg_0xa568570, arg_0xa5686d8, arg_0xa568830);
#line 48

#line 48
  return result;
#line 48
}
#line 48
static inline   
# 328 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/BlockStorageM.nc"
void BlockStorageM$Mount$default$mountDone(blockstorage_t blockId, storage_result_t result, volume_id_t id)
#line 328
{
}

# 32 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/Mount.nc"
inline static  void BlockStorageM$Mount$mountDone(blockstorage_t arg_0xa570550, storage_result_t arg_0xa536dc0, volume_id_t arg_0xa536f10){
#line 32
  switch (arg_0xa570550) {
#line 32
    case DELUGE_VOLUME_ID_0:
#line 32
      DelugeStorageM$Mount$mountDone(DELUGE_VOLUME_ID_0, arg_0xa536dc0, arg_0xa536f10);
#line 32
      break;
#line 32
    case DELUGE_VOLUME_ID_1:
#line 32
      DelugeStorageM$Mount$mountDone(DELUGE_VOLUME_ID_1, arg_0xa536dc0, arg_0xa536f10);
#line 32
      break;
#line 32
    case DELUGE_VOLUME_ID_2:
#line 32
      DelugeStorageM$Mount$mountDone(DELUGE_VOLUME_ID_2, arg_0xa536dc0, arg_0xa536f10);
#line 32
      break;
#line 32
    default:
#line 32
      BlockStorageM$Mount$default$mountDone(arg_0xa570550, arg_0xa536dc0, arg_0xa536f10);
#line 32
    }
#line 32
}
#line 32
static inline  
# 324 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/BlockStorageM.nc"
void BlockStorageM$ActualMount$mountDone(blockstorage_t blockId, storage_result_t result, volume_id_t id)
#line 324
{
  BlockStorageM$Mount$mountDone(blockId, result, id);
}

# 32 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/Mount.nc"
inline static  void StorageManagerM$Mount$mountDone(volume_t arg_0xa5aac10, storage_result_t arg_0xa536dc0, volume_id_t arg_0xa536f10){
#line 32
  BlockStorageM$ActualMount$mountDone(arg_0xa5aac10, arg_0xa536dc0, arg_0xa536f10);
#line 32
}
#line 32
static inline 
# 53 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/StorageManagerM.nc"
void StorageManagerM$mountComplete(storage_result_t r)
#line 53
{
  StorageManagerM$f.busy = FALSE;
  StorageManagerM$Mount$mountDone(StorageManagerM$client, r, StorageManagerM$id);
}

static inline void StorageManagerM$check(result_t r)
#line 58
{
  if (r == FAIL) {
    StorageManagerM$mountComplete(STORAGE_FAIL);
    }
}

static inline  
#line 75
void StorageManagerM$mountVolume(void)
#line 75
{
  if (! StorageManagerM$f.validated) {
    StorageManagerM$check(StorageManagerM$PageEEPROM$read(VOLUME_TABLE_PAGE, 0, &StorageManagerM$header, sizeof StorageManagerM$header));
    }
  else {
#line 79
    StorageManagerM$checkNextVolume();
    }
}

static inline  
# 255 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/mica/PageEEPROMM.nc"
void PageEEPROMM$taskFail(void)
#line 255
{
  PageEEPROMM$requestDone(FAIL);
}

static inline 
# 57 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/PageEEPROMShare.nc"
uint8_t PageEEPROMShare$getClient(void)
#line 57
{
  uint8_t id = 0;

  if (PageEEPROMShare$NCLIENTS != 1) 
    {
      id = PageEEPROMShare$lastClient - 1;
      PageEEPROMShare$lastClient = 0;
    }

  return id;
}

static inline 
# 58 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/HALAT45DBShare.nc"
volume_t HALAT45DBShare$getClient(void)
#line 58
{
  volume_t id = HALAT45DBShare$lastClient - 1;

  HALAT45DBShare$lastClient = 0;

  return id;
}

static inline  
# 553 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/mica/PageEEPROMM.nc"
result_t PageEEPROMM$PageEEPROM$computeCrc(eeprompage_t page, 
eeprompageoffset_t offset, 
eeprompageoffset_t n)
#line 555
{
  return PageEEPROMM$computeCrc(page, offset, n, 0);
}

# 52 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/PageEEPROM.nc"
inline static  result_t PageEEPROMShare$ActualEEPROM$computeCrc(eeprompage_t arg_0xa569068, eeprompageoffset_t arg_0xa5691c0, eeprompageoffset_t arg_0xa569328){
#line 52
  unsigned char result;
#line 52

#line 52
  result = PageEEPROMM$PageEEPROM$computeCrc(arg_0xa569068, arg_0xa5691c0, arg_0xa569328);
#line 52

#line 52
  return result;
#line 52
}
#line 52
static 
# 143 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/PageEEPROMShare.nc"
__inline  result_t PageEEPROMShare$PageEEPROM$computeCrc(uint8_t client, eeprompage_t page, eeprompageoffset_t offset, 
eeprompageoffset_t n)
#line 144
{
  if (!PageEEPROMShare$setClient(client)) {
    return FAIL;
    }
#line 147
  return PageEEPROMShare$check(PageEEPROMShare$ActualEEPROM$computeCrc(page, offset, n));
}

# 52 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/PageEEPROM.nc"
inline static  result_t HALAT45DBShare$ActualAT45$computeCrc(eeprompage_t arg_0xa569068, eeprompageoffset_t arg_0xa5691c0, eeprompageoffset_t arg_0xa569328){
#line 52
  unsigned char result;
#line 52

#line 52
  result = PageEEPROMShare$PageEEPROM$computeCrc(0, arg_0xa569068, arg_0xa5691c0, arg_0xa569328);
#line 52

#line 52
  return result;
#line 52
}
#line 52
static 
# 144 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/HALAT45DBShare.nc"
__inline  result_t HALAT45DBShare$PageEEPROM$computeCrc(volume_t client, at45page_t page, at45pageoffset_t offset, 
at45pageoffset_t n)
#line 145
{
  if (!HALAT45DBShare$setClient(client)) {
    return FAIL;
    }
#line 148
  return HALAT45DBShare$check(HALAT45DBShare$ActualAT45$computeCrc(HALAT45DBShare$remap(page), offset, n));
}

# 52 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/PageEEPROM.nc"
inline static  result_t StorageManagerM$PageEEPROM$computeCrc(eeprompage_t arg_0xa569068, eeprompageoffset_t arg_0xa5691c0, eeprompageoffset_t arg_0xa569328){
#line 52
  unsigned char result;
#line 52

#line 52
  result = HALAT45DBShare$PageEEPROM$computeCrc(3, arg_0xa569068, arg_0xa5691c0, arg_0xa569328);
#line 52

#line 52
  return result;
#line 52
}
#line 52
static inline  
# 126 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/StorageManagerM.nc"
result_t StorageManagerM$PageEEPROM$readDone(result_t result)
#line 126
{
  if (! StorageManagerM$f.validated) 
    {
      size_t nvOffset = (size_t )& ((struct volume_definition_header_t *)0)->nvolumes;
      size_t n = StorageManagerM$header.nvolumes * sizeof  (*StorageManagerM$volumes) + 
      sizeof(struct volume_definition_header_t ) - nvOffset;

      StorageManagerM$check(StorageManagerM$PageEEPROM$computeCrc(VOLUME_TABLE_PAGE, nvOffset, n));
    }
  else 
    {
      if (StorageManagerM$volumes[StorageManagerM$client].id == StorageManagerM$id) {
        StorageManagerM$mountComplete(STORAGE_OK);
        }
      else {
#line 140
        StorageManagerM$checkNextVolume();
        }
    }
#line 142
  return SUCCESS;
}

static inline 
# 268 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/BlockStorageM.nc"
void BlockStorageM$multipageDone(result_t result)
#line 268
{
  if (BlockStorageM$bytesRemaining == 0 || result == FAIL) {
    BlockStorageM$signalDone(result);
    }
  else {
#line 272
    BlockStorageM$continueRequest();
    }
}

static inline  




result_t BlockStorageM$PageEEPROM$readDone(uint8_t id, result_t result)
#line 281
{
  if (id == BlockStorageM$client) {
    BlockStorageM$multipageDone(result);
    }
#line 284
  return SUCCESS;
}

# 50 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/PageEEPROM.nc"
inline static  result_t HALAT45DBShare$PageEEPROM$readDone(volume_t arg_0xa644fa0, result_t arg_0xa568c58){
#line 50
  unsigned char result;
#line 50

#line 50
  result = BlockStorageM$PageEEPROM$readDone(arg_0xa644fa0, arg_0xa568c58);
#line 50
  switch (arg_0xa644fa0) {
#line 50
    case 3:
#line 50
      result = rcombine(result, StorageManagerM$PageEEPROM$readDone(arg_0xa568c58));
#line 50
      break;
#line 50
  }
#line 50

#line 50
  return result;
#line 50
}
#line 50
static 
# 140 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/HALAT45DBShare.nc"
__inline  result_t HALAT45DBShare$ActualAT45$readDone(result_t result)
#line 140
{
  return HALAT45DBShare$PageEEPROM$readDone(HALAT45DBShare$getClient(), result);
}

static inline   
# 177 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/PageEEPROMShare.nc"
result_t PageEEPROMShare$PageEEPROM$default$readDone(uint8_t client, result_t result)
#line 177
{
  return FAIL;
}

# 50 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/PageEEPROM.nc"
inline static  result_t PageEEPROMShare$PageEEPROM$readDone(uint8_t arg_0xa5db170, result_t arg_0xa568c58){
#line 50
  unsigned char result;
#line 50

#line 50
  switch (arg_0xa5db170) {
#line 50
    case 0:
#line 50
      result = HALAT45DBShare$ActualAT45$readDone(arg_0xa568c58);
#line 50
      break;
#line 50
    default:
#line 50
      result = PageEEPROMShare$PageEEPROM$default$readDone(arg_0xa5db170, arg_0xa568c58);
#line 50
    }
#line 50

#line 50
  return result;
#line 50
}
#line 50
static 
# 139 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/PageEEPROMShare.nc"
__inline  result_t PageEEPROMShare$ActualEEPROM$readDone(result_t result)
#line 139
{
  return PageEEPROMShare$PageEEPROM$readDone(PageEEPROMShare$getClient(), result);
}

# 50 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/PageEEPROM.nc"
inline static  result_t PageEEPROMM$PageEEPROM$readDone(result_t arg_0xa568c58){
#line 50
  unsigned char result;
#line 50

#line 50
  result = PageEEPROMShare$ActualEEPROM$readDone(arg_0xa568c58);
#line 50

#line 50
  return result;
#line 50
}
#line 50
static inline  
# 566 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/mica/PageEEPROMM.nc"
result_t PageEEPROMM$PageEEPROM$write(eeprompage_t page, eeprompageoffset_t offset, 
void *reqdata, eeprompageoffset_t n)
#line 567
{
#line 598
  return PageEEPROMM$newRequest(PageEEPROMM$R_WRITE, page, offset, reqdata, n, 0);
}

# 33 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/PageEEPROM.nc"
inline static  result_t PageEEPROMShare$ActualEEPROM$write(eeprompage_t arg_0xa5537f8, eeprompageoffset_t arg_0xa553950, void *arg_0xa553ab8, eeprompageoffset_t arg_0xa553c10){
#line 33
  unsigned char result;
#line 33

#line 33
  result = PageEEPROMM$PageEEPROM$write(arg_0xa5537f8, arg_0xa553950, arg_0xa553ab8, arg_0xa553c10);
#line 33

#line 33
  return result;
#line 33
}
#line 33
static 
# 79 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/PageEEPROMShare.nc"
__inline  result_t PageEEPROMShare$PageEEPROM$write(uint8_t client, eeprompage_t page, eeprompageoffset_t offset, 
void *data, eeprompageoffset_t n)
#line 80
{
  if (!PageEEPROMShare$setClient(client)) {
    return FAIL;
    }
#line 83
  return PageEEPROMShare$check(PageEEPROMShare$ActualEEPROM$write(page, offset, data, n));
}

# 33 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/PageEEPROM.nc"
inline static  result_t HALAT45DBShare$ActualAT45$write(eeprompage_t arg_0xa5537f8, eeprompageoffset_t arg_0xa553950, void *arg_0xa553ab8, eeprompageoffset_t arg_0xa553c10){
#line 33
  unsigned char result;
#line 33

#line 33
  result = PageEEPROMShare$PageEEPROM$write(0, arg_0xa5537f8, arg_0xa553950, arg_0xa553ab8, arg_0xa553c10);
#line 33

#line 33
  return result;
#line 33
}
#line 33
static 
# 80 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/HALAT45DBShare.nc"
__inline  result_t HALAT45DBShare$PageEEPROM$write(volume_t client, at45page_t page, at45pageoffset_t offset, 
void *data, at45pageoffset_t n)
#line 81
{
  if (!HALAT45DBShare$setClient(client)) {
    return FAIL;
    }
#line 84
  return HALAT45DBShare$check(HALAT45DBShare$ActualAT45$write(HALAT45DBShare$remap(page), offset, data, n));
}

# 33 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/PageEEPROM.nc"
inline static  result_t BlockStorageM$PageEEPROM$write(blockstorage_t arg_0xa571d00, eeprompage_t arg_0xa5537f8, eeprompageoffset_t arg_0xa553950, void *arg_0xa553ab8, eeprompageoffset_t arg_0xa553c10){
#line 33
  unsigned char result;
#line 33

#line 33
  result = HALAT45DBShare$PageEEPROM$write(arg_0xa571d00, arg_0xa5537f8, arg_0xa553950, arg_0xa553ab8, arg_0xa553c10);
#line 33

#line 33
  return result;
#line 33
}
#line 33
static inline  
# 107 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/BlockStorageM.nc"
void BlockStorageM$signalFail(void)
#line 107
{
#line 107
  BlockStorageM$actualSignal(STORAGE_FAIL);
}

static inline 
#line 128
void BlockStorageM$check(result_t ok)
#line 128
{
  if (!ok) {
    TOS_post(BlockStorageM$signalFail);
    }
}

static inline 
#line 213
void BlockStorageM$commitSignature(void)
#line 213
{
  BlockStorageM$sig[0] = BlockStorageM$crc;
  BlockStorageM$sig[1] = BlockStorageM$crc >> 8;
  BlockStorageM$sig[2] = BlockStorageM$maxAddr[BlockStorageM$client];
  BlockStorageM$sig[3] = BlockStorageM$maxAddr[BlockStorageM$client] >> 8;
  BlockStorageM$sig[4] = BlockStorageM$maxAddr[BlockStorageM$client] >> 16;
  BlockStorageM$sig[5] = BlockStorageM$maxAddr[BlockStorageM$client] >> 24;
  BlockStorageM$sig[6] = 0xb1;
  BlockStorageM$sig[7] = 0x0c;
  BlockStorageM$state = BlockStorageM$S_COMMIT2;


  BlockStorageM$check(BlockStorageM$PageEEPROM$write(BlockStorageM$client, 0, 1 << AT45_PAGE_SIZE_LOG2, BlockStorageM$sig, sizeof BlockStorageM$sig));
}

static inline  
# 666 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/mica/PageEEPROMM.nc"
result_t PageEEPROMM$PageEEPROM$syncAll(void)
#line 666
{
  return PageEEPROMM$syncOrFlushAll(PageEEPROMM$R_SYNCALL);
}

# 41 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/PageEEPROM.nc"
inline static  result_t PageEEPROMShare$ActualEEPROM$syncAll(void){
#line 41
  unsigned char result;
#line 41

#line 41
  result = PageEEPROMM$PageEEPROM$syncAll();
#line 41

#line 41
  return result;
#line 41
}
#line 41
static 
# 106 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/PageEEPROMShare.nc"
__inline  result_t PageEEPROMShare$PageEEPROM$syncAll(uint8_t client)
#line 106
{
  if (!PageEEPROMShare$setClient(client)) {
    return FAIL;
    }
#line 109
  return PageEEPROMShare$check(PageEEPROMShare$ActualEEPROM$syncAll());
}

# 41 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/PageEEPROM.nc"
inline static  result_t HALAT45DBShare$ActualAT45$syncAll(void){
#line 41
  unsigned char result;
#line 41

#line 41
  result = PageEEPROMShare$PageEEPROM$syncAll(0);
#line 41

#line 41
  return result;
#line 41
}
#line 41
static 
# 107 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/HALAT45DBShare.nc"
__inline  result_t HALAT45DBShare$PageEEPROM$syncAll(volume_t client)
#line 107
{
  if (!HALAT45DBShare$setClient(client)) {
    return FAIL;
    }
#line 110
  return HALAT45DBShare$check(HALAT45DBShare$ActualAT45$syncAll());
}

# 41 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/PageEEPROM.nc"
inline static  result_t BlockStorageM$PageEEPROM$syncAll(blockstorage_t arg_0xa571d00){
#line 41
  unsigned char result;
#line 41

#line 41
  result = HALAT45DBShare$PageEEPROM$syncAll(arg_0xa571d00);
#line 41

#line 41
  return result;
#line 41
}
#line 41
static inline 
#line 229
void BlockStorageM$commitSync(void)
#line 229
{
  BlockStorageM$state = BlockStorageM$S_COMMIT3;
  BlockStorageM$check(BlockStorageM$PageEEPROM$syncAll(BlockStorageM$client));
}

static inline  
# 251 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/mica/PageEEPROMM.nc"
void PageEEPROMM$taskSuccess(void)
#line 251
{
  PageEEPROMM$requestDone(SUCCESS);
}

# 155 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/micaz/hardware.h"
static __inline void TOSH_CLR_FLASH_SELECT_PIN(void)
#line 155
{
#line 155
  * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x1B + 0x20) &= ~(1 << 3);
}

static inline   
# 83 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/mica2/HPLFlash.nc"
result_t HPLFlash$FlashSelect$low(void)
#line 83
{
  TOSH_CLR_FLASH_CLK_PIN();
  TOSH_CLR_FLASH_SELECT_PIN();
  return SUCCESS;
}

# 51 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/mica/SlavePin.nc"
inline static   result_t PageEEPROMM$FlashSelect$low(void){
#line 51
  unsigned char result;
#line 51

#line 51
  result = HPLFlash$FlashSelect$low();
#line 51

#line 51
  return result;
#line 51
}
#line 51
static inline 
# 157 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/mica/PageEEPROMM.nc"
void PageEEPROMM$selectFlash(void)
#line 157
{
  PageEEPROMM$FlashSelect$low();
}

# 59 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/FastSPI.nc"
inline static   uint8_t PageEEPROMM$FlashSPI$txByte(uint8_t arg_0xa5edb20){
#line 59
  unsigned char result;
#line 59

#line 59
  result = HPLFlash$FlashSPI$txByte(arg_0xa5edb20);
#line 59

#line 59
  return result;
#line 59
}
#line 59
# 158 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/micaz/hardware.h"
static __inline int TOSH_READ_FLASH_IN_PIN(void)
#line 158
{
#line 158
  return (* (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x10 + 0x20) & (1 << 2)) != 0;
}

static 
#line 101
void __inline TOSH_uwait(int u_sec)
#line 101
{
  while (u_sec > 0) {
       __asm volatile ("nop");
       __asm volatile ("nop");
       __asm volatile ("nop");
       __asm volatile ("nop");
       __asm volatile ("nop");
       __asm volatile ("nop");
       __asm volatile ("nop");
       __asm volatile ("nop");
      u_sec--;
    }
}

static inline  
# 145 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/mica2/HPLFlash.nc"
result_t HPLFlash$FlashIdle$wait(void)
#line 145
{
  result_t waits;


  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
    {
      * (volatile unsigned char *)(0x38 + 0x20) = 1 << 2;
      * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x39 + 0x20) |= 1 << 2;
      TOSH_CLR_FLASH_CLK_PIN();




      TOSH_uwait(2);

      if (TOSH_READ_FLASH_IN_PIN()) 
        {

          * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x39 + 0x20) &= ~(1 << 2);
          waits = FAIL;
        }
      else {
        waits = SUCCESS;
        }
    }
#line 169
    __nesc_atomic_end(__nesc_atomic); }
#line 169
  return waits;
}

# 32 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/Resource.nc"
inline static  result_t PageEEPROMM$FlashIdle$wait(void){
#line 32
  unsigned char result;
#line 32

#line 32
  result = HPLFlash$FlashIdle$wait();
#line 32

#line 32
  return result;
#line 32
}
#line 32
static inline  
# 361 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/mica/PageEEPROMM.nc"
result_t PageEEPROMM$FlashSelect$notifyHigh(void)
#line 361
{
  if (PageEEPROMM$deselectRequested) 
    {
      PageEEPROMM$deselectRequested = FALSE;
      PageEEPROMM$flashCommandComplete();
    }
  return SUCCESS;
}

# 66 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/mica/SlavePin.nc"
inline static  result_t HPLFlash$FlashSelect$notifyHigh(void){
#line 66
  unsigned char result;
#line 66

#line 66
  result = PageEEPROMM$FlashSelect$notifyHigh();
#line 66

#line 66
  return result;
#line 66
}
#line 66
static inline  
# 89 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/mica2/HPLFlash.nc"
void HPLFlash$sigHigh(void)
#line 89
{
  HPLFlash$FlashSelect$notifyHigh();
}

static inline   result_t HPLFlash$FlashSelect$high(bool needEvent)
#line 93
{
  TOSH_SET_FLASH_SELECT_PIN();
  if (needEvent) {
    TOS_post(HPLFlash$sigHigh);
    }
#line 97
  return SUCCESS;
}

# 61 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/mica/SlavePin.nc"
inline static   result_t PageEEPROMM$FlashSelect$high(bool arg_0xa5ec1c8){
#line 61
  unsigned char result;
#line 61

#line 61
  result = HPLFlash$FlashSelect$high(arg_0xa5ec1c8);
#line 61

#line 61
  return result;
#line 61
}
#line 61
static inline 
# 162 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/mica/PageEEPROMM.nc"
void PageEEPROMM$requestDeselect(void)
#line 162
{
  PageEEPROMM$deselectRequested = TRUE;
  PageEEPROMM$FlashSelect$high(TRUE);
}

# 156 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/micaz/hardware.h"
static __inline void TOSH_SET_FLASH_CLK_PIN(void)
#line 156
{
#line 156
  * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x12 + 0x20) |= 1 << 5;
}

static inline  
# 178 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/mica2/HPLFlash.nc"
bool HPLFlash$getCompareStatus(void)
#line 178
{
  TOSH_SET_FLASH_CLK_PIN();
  TOSH_CLR_FLASH_CLK_PIN();

   __asm volatile ("nop");
   __asm volatile ("nop");
  return !TOSH_READ_FLASH_IN_PIN();
}

# 43 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/mica/PageEEPROMM.nc"
inline static  bool PageEEPROMM$getCompareStatus(void){
#line 43
  unsigned char result;
#line 43

#line 43
  result = HPLFlash$getCompareStatus();
#line 43

#line 43
  return result;
#line 43
}
#line 43
static inline  
#line 167
result_t PageEEPROMM$FlashIdle$available(void)
#line 167
{
  if (PageEEPROMM$cmdPhase == PageEEPROMM$P_COMPARE_CHECK) {
    PageEEPROMM$compareOk = PageEEPROMM$getCompareStatus();
    }
#line 170
  PageEEPROMM$requestDeselect();
  return SUCCESS;
}

static inline 
#line 385
void PageEEPROMM$execRWBuffer(uint8_t reqCmd, uint8_t dontCare, eeprompageoffset_t offset)
#line 385
{
  PageEEPROMM$execCommand(PageEEPROMM$buffer[PageEEPROMM$selected].busy, reqCmd, dontCare, 0, offset);
}

static inline 
# 252 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/BlockStorageM.nc"
void BlockStorageM$verifySignature(void)
#line 252
{
  if (BlockStorageM$sig[6] == 0xb1 && BlockStorageM$sig[7] == 0x0c) 
    {
      BlockStorageM$maxAddr[BlockStorageM$client] = ((BlockStorageM$sig[2] | ((uint32_t )BlockStorageM$sig[3] << 8)) | (
      (uint32_t )BlockStorageM$sig[4] << 16)) | ((uint32_t )BlockStorageM$sig[5] << 24);
      BlockStorageM$state = BlockStorageM$S_IDLE;
      BlockStorageM$newRequest(BlockStorageM$S_VERIFY2, BlockStorageM$client, 0, (void *)0, BlockStorageM$maxAddr[BlockStorageM$client]);
    }
  else {
    BlockStorageM$actualSignal(STORAGE_INVALID_SIGNATURE);
    }
}

static inline  
#line 105
void BlockStorageM$signalSuccess(void)
#line 105
{
#line 105
  BlockStorageM$actualSignal(STORAGE_OK);
}

static inline  
# 145 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/StorageManagerM.nc"
result_t StorageManagerM$PageEEPROM$computeCrcDone(result_t result, uint16_t crc)
#line 145
{
  StorageManagerM$f.validated = TRUE;
  StorageManagerM$f.invalid = crc != StorageManagerM$header.crc;
  StorageManagerM$checkNextVolume();
  return SUCCESS;
}

static inline  
# 287 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/BlockStorageM.nc"
result_t BlockStorageM$PageEEPROM$computeCrcDone(uint8_t id, result_t result, uint16_t newCrc)
#line 287
{
  if (id == BlockStorageM$client) 
    {
      BlockStorageM$crc = newCrc;
      BlockStorageM$multipageDone(result);
    }
  return SUCCESS;
}

# 56 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/PageEEPROM.nc"
inline static  result_t HALAT45DBShare$PageEEPROM$computeCrcDone(volume_t arg_0xa644fa0, result_t arg_0xa566030, uint16_t arg_0xa566180){
#line 56
  unsigned char result;
#line 56

#line 56
  result = BlockStorageM$PageEEPROM$computeCrcDone(arg_0xa644fa0, arg_0xa566030, arg_0xa566180);
#line 56
  switch (arg_0xa644fa0) {
#line 56
    case 3:
#line 56
      result = rcombine(result, StorageManagerM$PageEEPROM$computeCrcDone(arg_0xa566030, arg_0xa566180));
#line 56
      break;
#line 56
  }
#line 56

#line 56
  return result;
#line 56
}
#line 56
static 
# 157 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/HALAT45DBShare.nc"
__inline  result_t HALAT45DBShare$ActualAT45$computeCrcDone(result_t result, uint16_t crc)
#line 157
{
  return HALAT45DBShare$PageEEPROM$computeCrcDone(HALAT45DBShare$getClient(), result, crc);
}

static inline   
# 181 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/PageEEPROMShare.nc"
result_t PageEEPROMShare$PageEEPROM$default$computeCrcDone(uint8_t client, result_t result, uint16_t crc)
#line 181
{
  return FAIL;
}

# 56 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/PageEEPROM.nc"
inline static  result_t PageEEPROMShare$PageEEPROM$computeCrcDone(uint8_t arg_0xa5db170, result_t arg_0xa566030, uint16_t arg_0xa566180){
#line 56
  unsigned char result;
#line 56

#line 56
  switch (arg_0xa5db170) {
#line 56
    case 0:
#line 56
      result = HALAT45DBShare$ActualAT45$computeCrcDone(arg_0xa566030, arg_0xa566180);
#line 56
      break;
#line 56
    default:
#line 56
      result = PageEEPROMShare$PageEEPROM$default$computeCrcDone(arg_0xa5db170, arg_0xa566030, arg_0xa566180);
#line 56
    }
#line 56

#line 56
  return result;
#line 56
}
#line 56
static 
# 150 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/PageEEPROMShare.nc"
__inline  result_t PageEEPROMShare$ActualEEPROM$computeCrcDone(result_t result, uint16_t crc)
#line 150
{
  return PageEEPROMShare$PageEEPROM$computeCrcDone(PageEEPROMShare$getClient(), result, crc);
}

# 56 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/PageEEPROM.nc"
inline static  result_t PageEEPROMM$PageEEPROM$computeCrcDone(result_t arg_0xa566030, uint16_t arg_0xa566180){
#line 56
  unsigned char result;
#line 56

#line 56
  result = PageEEPROMShare$ActualEEPROM$computeCrcDone(arg_0xa566030, arg_0xa566180);
#line 56

#line 56
  return result;
#line 56
}
#line 56
static inline  
# 110 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/StorageManagerM.nc"
result_t StorageManagerM$PageEEPROM$writeDone(result_t result)
#line 110
{
  return SUCCESS;
}

static inline  
# 275 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/BlockStorageM.nc"
result_t BlockStorageM$PageEEPROM$writeDone(uint8_t id, result_t result)
#line 275
{
  if (id == BlockStorageM$client) {
    BlockStorageM$multipageDone(result);
    }
#line 278
  return SUCCESS;
}

# 35 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/PageEEPROM.nc"
inline static  result_t HALAT45DBShare$PageEEPROM$writeDone(volume_t arg_0xa644fa0, result_t arg_0xa56a060){
#line 35
  unsigned char result;
#line 35

#line 35
  result = BlockStorageM$PageEEPROM$writeDone(arg_0xa644fa0, arg_0xa56a060);
#line 35
  switch (arg_0xa644fa0) {
#line 35
    case 3:
#line 35
      result = rcombine(result, StorageManagerM$PageEEPROM$writeDone(arg_0xa56a060));
#line 35
      break;
#line 35
  }
#line 35

#line 35
  return result;
#line 35
}
#line 35
static 
# 87 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/HALAT45DBShare.nc"
__inline  result_t HALAT45DBShare$ActualAT45$writeDone(result_t result)
#line 87
{
  return HALAT45DBShare$PageEEPROM$writeDone(HALAT45DBShare$getClient(), result);
}

static inline   
# 161 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/PageEEPROMShare.nc"
result_t PageEEPROMShare$PageEEPROM$default$writeDone(uint8_t client, result_t result)
#line 161
{
  return FAIL;
}

# 35 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/PageEEPROM.nc"
inline static  result_t PageEEPROMShare$PageEEPROM$writeDone(uint8_t arg_0xa5db170, result_t arg_0xa56a060){
#line 35
  unsigned char result;
#line 35

#line 35
  switch (arg_0xa5db170) {
#line 35
    case 0:
#line 35
      result = HALAT45DBShare$ActualAT45$writeDone(arg_0xa56a060);
#line 35
      break;
#line 35
    default:
#line 35
      result = PageEEPROMShare$PageEEPROM$default$writeDone(arg_0xa5db170, arg_0xa56a060);
#line 35
    }
#line 35

#line 35
  return result;
#line 35
}
#line 35
static 
# 86 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/PageEEPROMShare.nc"
__inline  result_t PageEEPROMShare$ActualEEPROM$writeDone(result_t result)
#line 86
{
  return PageEEPROMShare$PageEEPROM$writeDone(PageEEPROMShare$getClient(), result);
}

# 35 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/PageEEPROM.nc"
inline static  result_t PageEEPROMM$PageEEPROM$writeDone(result_t arg_0xa56a060){
#line 35
  unsigned char result;
#line 35

#line 35
  result = PageEEPROMShare$ActualEEPROM$writeDone(arg_0xa56a060);
#line 35

#line 35
  return result;
#line 35
}
#line 35
static inline  
# 118 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/StorageManagerM.nc"
result_t StorageManagerM$PageEEPROM$syncDone(result_t result)
#line 118
{
  return SUCCESS;
}

static inline  
# 302 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/BlockStorageM.nc"
result_t BlockStorageM$PageEEPROM$syncDone(uint8_t id, result_t result)
#line 302
{
  if (id == BlockStorageM$client) {
    BlockStorageM$signalDone(result);
    }
#line 305
  return SUCCESS;
}

# 42 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/PageEEPROM.nc"
inline static  result_t HALAT45DBShare$PageEEPROM$syncDone(volume_t arg_0xa644fa0, result_t arg_0xa56b498){
#line 42
  unsigned char result;
#line 42

#line 42
  result = BlockStorageM$PageEEPROM$syncDone(arg_0xa644fa0, arg_0xa56b498);
#line 42
  switch (arg_0xa644fa0) {
#line 42
    case 3:
#line 42
      result = rcombine(result, StorageManagerM$PageEEPROM$syncDone(arg_0xa56b498));
#line 42
      break;
#line 42
  }
#line 42

#line 42
  return result;
#line 42
}
#line 42
static 
# 113 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/HALAT45DBShare.nc"
__inline  result_t HALAT45DBShare$ActualAT45$syncDone(result_t result)
#line 113
{
  return HALAT45DBShare$PageEEPROM$syncDone(HALAT45DBShare$getClient(), result);
}

static inline   
# 169 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/PageEEPROMShare.nc"
result_t PageEEPROMShare$PageEEPROM$default$syncDone(uint8_t client, result_t result)
#line 169
{
  return FAIL;
}

# 42 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/PageEEPROM.nc"
inline static  result_t PageEEPROMShare$PageEEPROM$syncDone(uint8_t arg_0xa5db170, result_t arg_0xa56b498){
#line 42
  unsigned char result;
#line 42

#line 42
  switch (arg_0xa5db170) {
#line 42
    case 0:
#line 42
      result = HALAT45DBShare$ActualAT45$syncDone(arg_0xa56b498);
#line 42
      break;
#line 42
    default:
#line 42
      result = PageEEPROMShare$PageEEPROM$default$syncDone(arg_0xa5db170, arg_0xa56b498);
#line 42
    }
#line 42

#line 42
  return result;
#line 42
}
#line 42
static 
# 112 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/PageEEPROMShare.nc"
__inline  result_t PageEEPROMShare$ActualEEPROM$syncDone(result_t result)
#line 112
{
  return PageEEPROMShare$PageEEPROM$syncDone(PageEEPROMShare$getClient(), result);
}

# 42 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/PageEEPROM.nc"
inline static  result_t PageEEPROMM$PageEEPROM$syncDone(result_t arg_0xa56b498){
#line 42
  unsigned char result;
#line 42

#line 42
  result = PageEEPROMShare$ActualEEPROM$syncDone(arg_0xa56b498);
#line 42

#line 42
  return result;
#line 42
}
#line 42
static inline  
# 122 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/StorageManagerM.nc"
result_t StorageManagerM$PageEEPROM$flushDone(result_t result)
#line 122
{
  return SUCCESS;
}

static inline  
# 308 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/BlockStorageM.nc"
result_t BlockStorageM$PageEEPROM$flushDone(uint8_t id, result_t result)
#line 308
{
  return SUCCESS;
}

# 46 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/PageEEPROM.nc"
inline static  result_t HALAT45DBShare$PageEEPROM$flushDone(volume_t arg_0xa644fa0, result_t arg_0xa568010){
#line 46
  unsigned char result;
#line 46

#line 46
  result = BlockStorageM$PageEEPROM$flushDone(arg_0xa644fa0, arg_0xa568010);
#line 46
  switch (arg_0xa644fa0) {
#line 46
    case 3:
#line 46
      result = rcombine(result, StorageManagerM$PageEEPROM$flushDone(arg_0xa568010));
#line 46
      break;
#line 46
  }
#line 46

#line 46
  return result;
#line 46
}
#line 46
static 
# 129 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/HALAT45DBShare.nc"
__inline  result_t HALAT45DBShare$ActualAT45$flushDone(result_t result)
#line 129
{
  return HALAT45DBShare$PageEEPROM$flushDone(HALAT45DBShare$getClient(), result);
}

static inline   
# 173 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/PageEEPROMShare.nc"
result_t PageEEPROMShare$PageEEPROM$default$flushDone(uint8_t client, result_t result)
#line 173
{
  return FAIL;
}

# 46 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/PageEEPROM.nc"
inline static  result_t PageEEPROMShare$PageEEPROM$flushDone(uint8_t arg_0xa5db170, result_t arg_0xa568010){
#line 46
  unsigned char result;
#line 46

#line 46
  switch (arg_0xa5db170) {
#line 46
    case 0:
#line 46
      result = HALAT45DBShare$ActualAT45$flushDone(arg_0xa568010);
#line 46
      break;
#line 46
    default:
#line 46
      result = PageEEPROMShare$PageEEPROM$default$flushDone(arg_0xa5db170, arg_0xa568010);
#line 46
    }
#line 46

#line 46
  return result;
#line 46
}
#line 46
static 
# 128 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/PageEEPROMShare.nc"
__inline  result_t PageEEPROMShare$ActualEEPROM$flushDone(result_t result)
#line 128
{
  return PageEEPROMShare$PageEEPROM$flushDone(PageEEPROMShare$getClient(), result);
}

# 46 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/PageEEPROM.nc"
inline static  result_t PageEEPROMM$PageEEPROM$flushDone(result_t arg_0xa568010){
#line 46
  unsigned char result;
#line 46

#line 46
  result = PageEEPROMShare$ActualEEPROM$flushDone(arg_0xa568010);
#line 46

#line 46
  return result;
#line 46
}
#line 46
static inline  
# 114 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/StorageManagerM.nc"
result_t StorageManagerM$PageEEPROM$eraseDone(result_t result)
#line 114
{
  return SUCCESS;
}

static inline  
# 296 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/BlockStorageM.nc"
result_t BlockStorageM$PageEEPROM$eraseDone(uint8_t id, result_t result)
#line 296
{
  if (id == BlockStorageM$client) {
    BlockStorageM$signalDone(result);
    }
#line 299
  return SUCCESS;
}

# 38 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/PageEEPROM.nc"
inline static  result_t HALAT45DBShare$PageEEPROM$eraseDone(volume_t arg_0xa644fa0, result_t arg_0xa56a9d0){
#line 38
  unsigned char result;
#line 38

#line 38
  result = BlockStorageM$PageEEPROM$eraseDone(arg_0xa644fa0, arg_0xa56a9d0);
#line 38
  switch (arg_0xa644fa0) {
#line 38
    case 3:
#line 38
      result = rcombine(result, StorageManagerM$PageEEPROM$eraseDone(arg_0xa56a9d0));
#line 38
      break;
#line 38
  }
#line 38

#line 38
  return result;
#line 38
}
#line 38
static 
# 97 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/HALAT45DBShare.nc"
__inline  result_t HALAT45DBShare$ActualAT45$eraseDone(result_t result)
#line 97
{
  return HALAT45DBShare$PageEEPROM$eraseDone(HALAT45DBShare$getClient(), result);
}

static inline   
# 165 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/PageEEPROMShare.nc"
result_t PageEEPROMShare$PageEEPROM$default$eraseDone(uint8_t client, result_t result)
#line 165
{
  return FAIL;
}

# 38 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/PageEEPROM.nc"
inline static  result_t PageEEPROMShare$PageEEPROM$eraseDone(uint8_t arg_0xa5db170, result_t arg_0xa56a9d0){
#line 38
  unsigned char result;
#line 38

#line 38
  switch (arg_0xa5db170) {
#line 38
    case 0:
#line 38
      result = HALAT45DBShare$ActualAT45$eraseDone(arg_0xa56a9d0);
#line 38
      break;
#line 38
    default:
#line 38
      result = PageEEPROMShare$PageEEPROM$default$eraseDone(arg_0xa5db170, arg_0xa56a9d0);
#line 38
    }
#line 38

#line 38
  return result;
#line 38
}
#line 38
static 
# 96 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/PageEEPROMShare.nc"
__inline  result_t PageEEPROMShare$ActualEEPROM$eraseDone(result_t result)
#line 96
{
  return PageEEPROMShare$PageEEPROM$eraseDone(PageEEPROMShare$getClient(), result);
}

# 38 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/PageEEPROM.nc"
inline static  result_t PageEEPROMM$PageEEPROM$eraseDone(result_t arg_0xa56a9d0){
#line 38
  unsigned char result;
#line 38

#line 38
  result = PageEEPROMShare$ActualEEPROM$eraseDone(arg_0xa56a9d0);
#line 38

#line 38
  return result;
#line 38
}
#line 38
static inline  
# 166 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/DelugeStorageM.nc"
result_t DelugeStorageM$MetadataStore$read(imgnum_t imgNum, void *buf)
#line 166
{
  return DelugeStorageM$newRequest(DelugeStorageM$S_METADATA_READ, imgNum, 0, buf, sizeof(DelugeImgDesc ));
}

# 35 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/DelugeMetadataStore.nc"
inline static  result_t DelugeMetadataM$MetadataStore$read(imgnum_t arg_0xa4c9170, void *arg_0xa4c92c8){
#line 35
  unsigned char result;
#line 35

#line 35
  result = DelugeStorageM$MetadataStore$read(arg_0xa4c9170, arg_0xa4c92c8);
#line 35

#line 35
  return result;
#line 35
}
#line 35
static inline  
# 293 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/DelugeMetadataM.nc"
void DelugeMetadataM$FlashWP$clrWPDone(void)
#line 293
{
  DelugeMetadataM$state = DelugeMetadataM$S_SETUP;
  DelugeMetadataM$execute();
}

# 32 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/FlashWP.nc"
inline static  void FlashWPC$FlashWP$clrWPDone(void){
#line 32
  DelugeMetadataM$FlashWP$clrWPDone();
#line 32
}
#line 32
static inline  
# 41 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/FlashWPC.nc"
void FlashWPC$signalClrDone(void)
#line 41
{
  FlashWPC$FlashWP$clrWPDone();
}

static inline  



result_t FlashWPC$FlashWP$clrWP(void)
#line 49
{
  return TOS_post(FlashWPC$signalClrDone) ? SUCCESS : FAIL;
}

# 31 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/FlashWP.nc"
inline static  result_t DelugeMetadataM$FlashWP$clrWP(void){
#line 31
  unsigned char result;
#line 31

#line 31
  result = FlashWPC$FlashWP$clrWP();
#line 31

#line 31
  return result;
#line 31
}
#line 31
static inline  
# 188 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/DelugeStorageM.nc"
result_t DelugeStorageM$DataWrite$erase(imgnum_t imgNum)
#line 188
{
  return DelugeStorageM$newRequest(DelugeStorageM$S_ERASE, imgNum, 0, 0, 0);
}

# 36 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/DelugeDataWrite.nc"
inline static  result_t DelugeMetadataM$DataWrite$erase(imgnum_t arg_0xa4d2988){
#line 36
  unsigned char result;
#line 36

#line 36
  result = DelugeStorageM$DataWrite$erase(arg_0xa4d2988);
#line 36

#line 36
  return result;
#line 36
}
#line 36
static inline  
# 179 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/DelugeStorageM.nc"
result_t DelugeStorageM$DataRead$verify(imgnum_t imgNum, pgnum_t tmpPgNum)
#line 179
{
  return DelugeStorageM$newRequest(DelugeStorageM$S_VERIFY, imgNum, tmpPgNum, (void *)0, 0);
}

# 39 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/DelugeDataRead.nc"
inline static  result_t DelugeMetadataM$DataRead$verify(imgnum_t arg_0xa4d61c8, pgnum_t arg_0xa4d6310){
#line 39
  unsigned char result;
#line 39

#line 39
  result = DelugeStorageM$DataRead$verify(arg_0xa4d61c8, arg_0xa4d6310);
#line 39

#line 39
  return result;
#line 39
}
#line 39
static inline  
# 387 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/DelugeM.nc"
void DelugeM$Metadata$updateDone(result_t result)
#line 387
{
  if (DelugeM$curImage == DelugeM$nodeDesc.imgNum) {
    DelugeM$checkReboot();
    }
#line 390
  DelugeM$setNextPage();
}

# 38 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/DelugeMetadata.nc"
inline static  void DelugeMetadataM$Metadata$updateDone(result_t arg_0xa459e48){
#line 38
  DelugeM$Metadata$updateDone(arg_0xa459e48);
#line 38
}
#line 38
static inline 
# 84 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/DelugeMetadataM.nc"
void DelugeMetadataM$signalDone(void)
#line 84
{
  DelugeMetadataM$state = DelugeMetadataM$S_IDLE;
  DelugeMetadataM$Metadata$updateDone(SUCCESS);
}

static inline  
#line 298
void DelugeMetadataM$FlashWP$setWPDone(void)
#line 298
{
  DelugeMetadataM$signalDone();
}

# 30 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/FlashWP.nc"
inline static  void FlashWPC$FlashWP$setWPDone(void){
#line 30
  DelugeMetadataM$FlashWP$setWPDone();
#line 30
}
#line 30
static inline  
# 45 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/FlashWPC.nc"
void FlashWPC$signalSetDone(void)
#line 45
{
  FlashWPC$FlashWP$setWPDone();
}

static inline  



result_t FlashWPC$FlashWP$setWP(void)
#line 53
{
  return TOS_post(FlashWPC$signalSetDone) ? SUCCESS : FAIL;
}

# 29 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/FlashWP.nc"
inline static  result_t DelugeMetadataM$FlashWP$setWP(void){
#line 29
  unsigned char result;
#line 29

#line 29
  result = FlashWPC$FlashWP$setWP();
#line 29

#line 29
  return result;
#line 29
}
#line 29
# 63 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/Random.nc"
inline static   uint16_t DelugeM$Random$rand(void){
#line 63
  unsigned int result;
#line 63

#line 63
  result = RandomLFSR$Random$rand();
#line 63

#line 63
  return result;
#line 63
}
#line 63
# 68 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/Timer.nc"
inline static  result_t DelugeM$Timer$stop(void){
#line 68
  unsigned char result;
#line 68

#line 68
  result = TimerM$Timer$stop(1);
#line 68

#line 68
  return result;
#line 68
}
#line 68
# 59 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/Timer.nc"
inline static  result_t DelugeM$Timer$start(char arg_0xa344320, uint32_t arg_0xa344478){
#line 59
  unsigned char result;
#line 59

#line 59
  result = TimerM$Timer$start(1, arg_0xa344320, arg_0xa344478);
#line 59

#line 59
  return result;
#line 59
}
#line 59
static inline   
# 59 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/system/NoLeds.nc"
result_t NoLeds$Leds$redOff(void)
#line 59
{
  return SUCCESS;
}

# 72 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/Leds.nc"
inline static   result_t DelugeM$Leds$redOff(void){
#line 72
  unsigned char result;
#line 72

#line 72
  result = NoLeds$Leds$redOff();
#line 72

#line 72
  return result;
#line 72
}
#line 72
static inline   
# 55 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/system/NoLeds.nc"
result_t NoLeds$Leds$redOn(void)
#line 55
{
  return SUCCESS;
}

# 64 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/Leds.nc"
inline static   result_t DelugeM$Leds$redOn(void){
#line 64
  unsigned char result;
#line 64

#line 64
  result = NoLeds$Leds$redOn();
#line 64

#line 64
  return result;
#line 64
}
#line 64
static inline  
# 196 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/DelugeM.nc"
result_t DelugeM$MetadataControl$startDone(void)
#line 196
{
  if (DelugeM$state == DelugeM$S_STARTED) {
    DelugeM$realStart();
    }
#line 199
  DelugeM$imagesLoaded = TRUE;
  return SUCCESS;
}

static inline  
# 97 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/NetProgM.nc"
result_t NetProgM$MetadataControl$startDone(void)
#line 97
{
#line 97
  return SUCCESS;
}

# 85 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/SplitControl.nc"
inline static  result_t DelugeMetadataM$SplitControl$startDone(void){
#line 85
  unsigned char result;
#line 85

#line 85
  result = NetProgM$MetadataControl$startDone();
#line 85
  result = rcombine(result, DelugeM$MetadataControl$startDone());
#line 85

#line 85
  return result;
#line 85
}
#line 85
static inline  
# 97 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/DelugePageTransferM.nc"
result_t DelugePageTransferM$StdControl$start(void)
#line 97
{
  DelugePageTransferM$changeState(DelugePageTransferM$S_IDLE);
  return SUCCESS;
}

# 70 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/StdControl.nc"
inline static  result_t DelugeM$PageTransferControl$start(void){
#line 70
  unsigned char result;
#line 70

#line 70
  result = DelugePageTransferM$StdControl$start();
#line 70

#line 70
  return result;
#line 70
}
#line 70
static inline  
# 314 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/DelugeMetadataM.nc"
void DelugeMetadataM$DataRead$readDone(storage_result_t result)
#line 314
{
}

# 59 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/Timer.nc"
inline static  result_t DelugePageTransferM$Timer$start(char arg_0xa344320, uint32_t arg_0xa344478){
#line 59
  unsigned char result;
#line 59

#line 59
  result = TimerM$Timer$start(3, arg_0xa344320, arg_0xa344478);
#line 59

#line 59
  return result;
#line 59
}
#line 59
# 48 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/SendMsg.nc"
inline static  result_t DelugePageTransferM$SendDataMsg$send(uint16_t arg_0xa46f5a8, uint8_t arg_0xa46f6f0, TOS_MsgPtr arg_0xa46f840){
#line 48
  unsigned char result;
#line 48

#line 48
  result = AMStandard$SendMsg$send(AM_DELUGEDATAMSG, arg_0xa46f5a8, arg_0xa46f6f0, arg_0xa46f840);
#line 48

#line 48
  return result;
#line 48
}
#line 48
static inline  
# 45 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/SharedMsgBufM.nc"
TOS_MsgPtr SharedMsgBufM$SharedMsgBuf$getMsgBuf(void)
#line 45
{
  return &SharedMsgBufM$msgBuf;
}

# 41 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/SharedMsgBuf.nc"
inline static  TOS_MsgPtr DelugePageTransferM$SharedMsgBuf$getMsgBuf(void){
#line 41
  struct TOS_Msg *result;
#line 41

#line 41
  result = SharedMsgBufM$SharedMsgBuf$getMsgBuf();
#line 41

#line 41
  return result;
#line 41
}
#line 41
static inline  
# 342 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/DelugePageTransferM.nc"
void DelugePageTransferM$DataRead$readDone(storage_result_t result)
#line 342
{

  TOS_MsgPtr pMsgBuf = DelugePageTransferM$SharedMsgBuf$getMsgBuf();

  if (DelugePageTransferM$state != DelugePageTransferM$S_SENDING) {
    return;
    }
  if (result != STORAGE_OK) {
      DelugePageTransferM$changeState(DelugePageTransferM$S_IDLE);
      return;
    }

  if (DelugePageTransferM$SendDataMsg$send(DelugePageTransferM$nodeAddr, sizeof(DelugeDataMsg ), pMsgBuf) == FAIL) {
    DelugePageTransferM$Timer$start(TIMER_ONE_SHOT, DELUGE_FAILED_SEND_DELAY);
    }
}

# 37 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/DelugeDataRead.nc"
inline static  void DelugeStorageM$DataRead$readDone(storage_result_t arg_0xa4dbd98){
#line 37
  DelugePageTransferM$DataRead$readDone(arg_0xa4dbd98);
#line 37
  DelugeMetadataM$DataRead$readDone(arg_0xa4dbd98);
#line 37
}
#line 37
# 63 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/Random.nc"
inline static   uint16_t CC2420RadioM$Random$rand(void){
#line 63
  unsigned int result;
#line 63

#line 63
  result = RandomLFSR$Random$rand();
#line 63

#line 63
  return result;
#line 63
}
#line 63
static inline    
# 744 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/CC2420Radio/CC2420RadioM.nc"
int16_t CC2420RadioM$MacBackoff$default$initialBackoff(TOS_MsgPtr m)
#line 744
{
  return (CC2420RadioM$Random$rand() & 0xF) + 1;
}

# 74 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/CC2420Radio/MacBackoff.nc"
inline static   int16_t CC2420RadioM$MacBackoff$initialBackoff(TOS_MsgPtr arg_0xa7482f0){
#line 74
  int result;
#line 74

#line 74
  result = CC2420RadioM$MacBackoff$default$initialBackoff(arg_0xa7482f0);
#line 74

#line 74
  return result;
#line 74
}
#line 74
# 6 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/CC2420Radio/TimerJiffyAsync.nc"
inline static   result_t CC2420RadioM$BackoffTimerJiffy$setOneShot(uint32_t arg_0xa7896e0){
#line 6
  unsigned char result;
#line 6

#line 6
  result = TimerJiffyAsyncM$TimerJiffyAsync$setOneShot(arg_0xa7896e0);
#line 6

#line 6
  return result;
#line 6
}
#line 6
static 
# 128 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/CC2420Radio/CC2420RadioM.nc"
__inline result_t CC2420RadioM$setInitialTimer(uint16_t jiffy)
#line 128
{
  CC2420RadioM$stateTimer = CC2420RadioM$TIMER_INITIAL;
  if (jiffy == 0) {

    return CC2420RadioM$BackoffTimerJiffy$setOneShot(2);
    }
#line 133
  return CC2420RadioM$BackoffTimerJiffy$setOneShot(jiffy);
}

static 
# 12 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/CC2420Radio/byteorder.h"
__inline int is_host_lsb(void)
{
  const uint8_t n[2] = { 1, 0 };

#line 15
  return * (uint16_t *)n == 1;
}

static __inline uint16_t toLSB16(uint16_t a)
{
  return is_host_lsb() ? a : (a << 8) | (a >> 8);
}

static inline  
# 491 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/CC2420Radio/CC2420RadioM.nc"
result_t CC2420RadioM$Send$send(TOS_MsgPtr pMsg)
#line 491
{
  uint8_t currentstate;

#line 493
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 493
    currentstate = CC2420RadioM$stateRadio;
#line 493
    __nesc_atomic_end(__nesc_atomic); }

  if (currentstate == CC2420RadioM$IDLE_STATE) {

      pMsg->fcflo = 0x08;
      if (CC2420RadioM$bAckEnable) {
        pMsg->fcfhi = 0x21;
        }
      else {
#line 501
        pMsg->fcfhi = 0x01;
        }
      pMsg->destpan = TOS_BCAST_ADDR;

      pMsg->addr = toLSB16(pMsg->addr);

      pMsg->length = pMsg->length + MSG_HEADER_SIZE + MSG_FOOTER_SIZE;

      pMsg->dsn = ++CC2420RadioM$currentDSN;

      pMsg->time = 0;

      CC2420RadioM$txlength = pMsg->length - MSG_FOOTER_SIZE;
      CC2420RadioM$txbufptr = pMsg;
      CC2420RadioM$countRetry = 8;

      if (CC2420RadioM$setInitialTimer(CC2420RadioM$MacBackoff$initialBackoff(CC2420RadioM$txbufptr) * 10)) {
          { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 518
            CC2420RadioM$stateRadio = CC2420RadioM$PRE_TX_STATE;
#line 518
            __nesc_atomic_end(__nesc_atomic); }
          return SUCCESS;
        }
    }
  return FAIL;
}

# 58 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/BareSendMsg.nc"
inline static  result_t AMStandard$RadioSend$send(TOS_MsgPtr arg_0xa71e7b0){
#line 58
  unsigned char result;
#line 58

#line 58
  result = CC2420RadioM$Send$send(arg_0xa71e7b0);
#line 58

#line 58
  return result;
#line 58
}
#line 58
static inline  
# 351 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/micaz/FramerM.nc"
result_t FramerM$BareSendMsg$send(TOS_MsgPtr pMsg)
#line 351
{
  result_t Result = SUCCESS;

  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 354
    {
      if (!(FramerM$gFlags & FramerM$FLAGS_DATAPEND)) {
          FramerM$gFlags |= FramerM$FLAGS_DATAPEND;
          FramerM$gpTxMsg = pMsg;
        }
      else 

        {
          Result = FAIL;
        }
    }
#line 364
    __nesc_atomic_end(__nesc_atomic); }

  if (Result == SUCCESS) {
      Result = FramerM$StartTx();
    }

  return Result;
}

# 58 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/BareSendMsg.nc"
inline static  result_t AMStandard$UARTSend$send(TOS_MsgPtr arg_0xa71e7b0){
#line 58
  unsigned char result;
#line 58

#line 58
  result = FramerM$BareSendMsg$send(arg_0xa71e7b0);
#line 58

#line 58
  return result;
#line 58
}
#line 58
static inline  
# 165 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/system/AMStandard.nc"
void AMStandard$sendTask(void)
#line 165
{
  result_t ok;
  TOS_MsgPtr buf;

#line 168
  buf = AMStandard$buffer;
  if (buf->addr == TOS_UART_ADDR) {
    ok = AMStandard$UARTSend$send(buf);
    }
  else {
#line 172
    ok = AMStandard$RadioSend$send(buf);
    }
  if (ok == FAIL) {
    AMStandard$reportSendDone(AMStandard$buffer, FAIL);
    }
}

static inline   
# 105 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/mica2/HPLUART0M.nc"
result_t HPLUART0M$UART$put(uint8_t data)
#line 105
{
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 106
    {
      * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x0C + 0x20) = data;
      * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x0B + 0x20) |= 1 << 6;
    }
#line 109
    __nesc_atomic_end(__nesc_atomic); }

  return SUCCESS;
}

# 80 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/HPLUART.nc"
inline static   result_t UARTM$HPLUART$put(uint8_t arg_0xa933388){
#line 80
  unsigned char result;
#line 80

#line 80
  result = HPLUART0M$UART$put(arg_0xa933388);
#line 80

#line 80
  return result;
#line 80
}
#line 80
static inline  
# 207 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/system/AMStandard.nc"
result_t AMStandard$UARTSend$sendDone(TOS_MsgPtr msg, result_t success)
#line 207
{
  return AMStandard$reportSendDone(msg, success);
}

# 67 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/BareSendMsg.nc"
inline static  result_t FramerM$BareSendMsg$sendDone(TOS_MsgPtr arg_0xa71ecc8, result_t arg_0xa71ee18){
#line 67
  unsigned char result;
#line 67

#line 67
  result = AMStandard$UARTSend$sendDone(arg_0xa71ecc8, arg_0xa71ee18);
#line 67

#line 67
  return result;
#line 67
}
#line 67
static inline  
# 379 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/DelugePageTransferM.nc"
result_t DelugePageTransferM$SendReqMsg$sendDone(TOS_MsgPtr pMsg, result_t success)
#line 379
{

  if (DelugePageTransferM$state != DelugePageTransferM$S_RECEIVING) {
    return SUCCESS;
    }
  DelugePageTransferM$remainingAttempts--;


  DelugePageTransferM$startReqTimer(FALSE);
  return SUCCESS;
}

static inline  
result_t DelugePageTransferM$SendDataMsg$sendDone(TOS_MsgPtr pMsg, result_t success)
#line 392
{
  TOS_MsgPtr pMsgBuf = DelugePageTransferM$SharedMsgBuf$getMsgBuf();
  DelugeDataMsg *pDataMsg = (DelugeDataMsg *)pMsgBuf->data;

#line 395
  DelugePageTransferM$pktsToSend[pDataMsg->pktNum / 8] = DelugePageTransferM$pktsToSend[pDataMsg->pktNum / 8] & ~(1 << pDataMsg->pktNum % 8);
  DelugePageTransferM$Timer$start(TIMER_ONE_SHOT, 2);
  return SUCCESS;
}

# 51 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/SharedMsgBuf.nc"
inline static  void DelugeM$SharedMsgBuf$unlock(void){
#line 51
  SharedMsgBufM$SharedMsgBuf$unlock();
#line 51
}
#line 51
static inline  
# 373 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/DelugeM.nc"
result_t DelugeM$SendAdvMsg$sendDone(TOS_MsgPtr pMsg, result_t result)
#line 373
{
  DelugeM$SharedMsgBuf$unlock();
  return SUCCESS;
}

# 51 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/SharedMsgBuf.nc"
inline static  void NetProgM$SharedMsgBuf$unlock(void){
#line 51
  SharedMsgBufM$SharedMsgBuf$unlock();
#line 51
}
#line 51
static inline  
# 153 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/NetProgM.nc"
result_t NetProgM$SendMsg$sendDone(TOS_MsgPtr pMsg, result_t result)
#line 153
{
  NetProgM$SharedMsgBuf$unlock();
  return SUCCESS;
}

static inline  
# 236 "TestSenseM.nc"
result_t TestSenseM$DataMsg$sendDone(TOS_MsgPtr sent, result_t success)
#line 236
{
  return SUCCESS;
}

static inline   
# 157 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/system/AMStandard.nc"
result_t AMStandard$SendMsg$default$sendDone(uint8_t id, TOS_MsgPtr msg, result_t success)
#line 157
{
  return SUCCESS;
}

# 49 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/SendMsg.nc"
inline static  result_t AMStandard$SendMsg$sendDone(uint8_t arg_0xa7265b0, TOS_MsgPtr arg_0xa46fc60, result_t arg_0xa46fdb0){
#line 49
  unsigned char result;
#line 49

#line 49
  switch (arg_0xa7265b0) {
#line 49
    case AM_OSCOPEMSG:
#line 49
      result = TestSenseM$DataMsg$sendDone(arg_0xa46fc60, arg_0xa46fdb0);
#line 49
      break;
#line 49
    case AM_DELUGEADVMSG:
#line 49
      result = DelugeM$SendAdvMsg$sendDone(arg_0xa46fc60, arg_0xa46fdb0);
#line 49
      break;
#line 49
    case AM_DELUGEREQMSG:
#line 49
      result = DelugePageTransferM$SendReqMsg$sendDone(arg_0xa46fc60, arg_0xa46fdb0);
#line 49
      break;
#line 49
    case AM_DELUGEDATAMSG:
#line 49
      result = DelugePageTransferM$SendDataMsg$sendDone(arg_0xa46fc60, arg_0xa46fdb0);
#line 49
      break;
#line 49
    case AM_NETPROGMSG:
#line 49
      result = NetProgM$SendMsg$sendDone(arg_0xa46fc60, arg_0xa46fdb0);
#line 49
      break;
#line 49
    default:
#line 49
      result = AMStandard$SendMsg$default$sendDone(arg_0xa7265b0, arg_0xa46fc60, arg_0xa46fdb0);
#line 49
    }
#line 49

#line 49
  return result;
#line 49
}
#line 49
# 63 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/Random.nc"
inline static   uint16_t DelugePageTransferM$Random$rand(void){
#line 63
  unsigned int result;
#line 63

#line 63
  result = RandomLFSR$Random$rand();
#line 63

#line 63
  return result;
#line 63
}
#line 63
static inline   
# 160 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/system/AMStandard.nc"
result_t AMStandard$default$sendDone(void)
#line 160
{
  return SUCCESS;
}

#line 65
inline static  result_t AMStandard$sendDone(void){
#line 65
  unsigned char result;
#line 65

#line 65
  result = AMStandard$default$sendDone();
#line 65

#line 65
  return result;
#line 65
}
#line 65
static inline 
#line 132
void AMStandard$dbgPacket(TOS_MsgPtr data)
#line 132
{
  uint8_t i;

  for (i = 0; i < sizeof(TOS_Msg ); i++) 
    {
      {
      }
#line 137
      ;
    }
  {
  }
#line 139
  ;
}

static inline  
# 310 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/DelugeMetadataM.nc"
void DelugeMetadataM$MetadataStore$writeDone(storage_result_t result)
#line 310
{
  DelugeMetadataM$signalDone();
}

# 39 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/DelugeMetadataStore.nc"
inline static  void DelugeStorageM$MetadataStore$writeDone(storage_result_t arg_0xa4da060){
#line 39
  DelugeMetadataM$MetadataStore$writeDone(arg_0xa4da060);
#line 39
}
#line 39
static inline  
# 315 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/DelugeMetadataM.nc"
void DelugeMetadataM$DataWrite$writeDone(storage_result_t result)
#line 315
{
}

static inline  
#line 258
result_t DelugeMetadataM$Metadata$receivedPage(imgnum_t imgNum, pgnum_t pgNum)
#line 258
{

  if (DelugeMetadataM$state != DelugeMetadataM$S_IDLE || imgNum >= 3) {
    return FAIL;
    }
  DelugeMetadataM$state = DelugeMetadataM$S_VERIFY;
  DelugeMetadataM$curImage = imgNum;

  DelugeMetadataM$execute();

  return SUCCESS;
}

# 37 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/DelugeMetadata.nc"
inline static  result_t DelugeM$Metadata$receivedPage(imgnum_t arg_0xa4598f8, pgnum_t arg_0xa459a40){
#line 37
  unsigned char result;
#line 37

#line 37
  result = DelugeMetadataM$Metadata$receivedPage(arg_0xa4598f8, arg_0xa459a40);
#line 37

#line 37
  return result;
#line 37
}
#line 37
static inline  
# 378 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/DelugeM.nc"
void DelugeM$PageTransfer$receivedPage(imgnum_t imgNum, pgnum_t pgNum)
#line 378
{
  DelugeM$curImage = imgNum;
  DelugeM$Metadata$receivedPage(imgNum, pgNum);
}

# 35 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/DelugePageTransfer.nc"
inline static  void DelugePageTransferM$PageTransfer$receivedPage(imgnum_t arg_0xa468238, pgnum_t arg_0xa468380){
#line 35
  DelugeM$PageTransfer$receivedPage(arg_0xa468238, arg_0xa468380);
#line 35
}
#line 35
# 44 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/BitVecUtils.nc"
inline static  result_t DelugePageTransferM$BitVecUtils$indexOf(uint16_t *arg_0xa407798, uint16_t arg_0xa4078f0, uint8_t *arg_0xa407a60, uint16_t arg_0xa407bb0){
#line 44
  unsigned char result;
#line 44

#line 44
  result = BitVecUtilsC$BitVecUtils$indexOf(arg_0xa407798, arg_0xa4078f0, arg_0xa407a60, arg_0xa407bb0);
#line 44

#line 44
  return result;
#line 44
}
#line 44
static inline  
# 359 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/DelugePageTransferM.nc"
void DelugePageTransferM$DataWrite$writeDone(storage_result_t result)
#line 359
{

  uint16_t tmp;


  DelugePageTransferM$pktsToReceive[DelugePageTransferM$rxQueue[DelugePageTransferM$head].pktNum / 8] = DelugePageTransferM$pktsToReceive[DelugePageTransferM$rxQueue[DelugePageTransferM$head].pktNum / 8] & ~(1 << DelugePageTransferM$rxQueue[DelugePageTransferM$head].pktNum % 8);
  DelugePageTransferM$head = (DelugePageTransferM$head + 1) % DELUGE_QSIZE;
  DelugePageTransferM$size--;

  if (!DelugePageTransferM$BitVecUtils$indexOf(&tmp, 0, DelugePageTransferM$pktsToReceive, DELUGE_PKTS_PER_PAGE)) {
      DelugePageTransferM$PageTransfer$receivedPage(DelugePageTransferM$workingImgNum, DelugePageTransferM$workingPgNum);
      DelugePageTransferM$changeState(DelugePageTransferM$S_IDLE);
      DelugePageTransferM$size = 0;
    }
  else {
#line 373
    if (DelugePageTransferM$size) {
        DelugePageTransferM$writeData();
      }
    }
}

# 34 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/DelugeDataWrite.nc"
inline static  void DelugeStorageM$DataWrite$writeDone(storage_result_t arg_0xa4d2580){
#line 34
  DelugePageTransferM$DataWrite$writeDone(arg_0xa4d2580);
#line 34
  DelugeMetadataM$DataWrite$writeDone(arg_0xa4d2580);
#line 34
}
#line 34
static inline  
# 183 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/DelugeStorageM.nc"
result_t DelugeStorageM$DataWrite$write(imgnum_t imgNum, block_addr_t addr, 
void *buf, uint16_t length)
#line 184
{
  return DelugeStorageM$newRequest(DelugeStorageM$S_WRITE, imgNum, addr, buf, length);
}

# 33 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/DelugeDataWrite.nc"
inline static  result_t DelugePageTransferM$DataWrite$write(imgnum_t arg_0xa4d7d58, block_addr_t arg_0xa4d7ea8, void *arg_0xa4d2010, uint16_t arg_0xa4d2160){
#line 33
  unsigned char result;
#line 33

#line 33
  result = DelugeStorageM$DataWrite$write(arg_0xa4d7d58, arg_0xa4d7ea8, arg_0xa4d2010, arg_0xa4d2160);
#line 33

#line 33
  return result;
#line 33
}
#line 33
static inline 
# 144 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/DelugePageTransferM.nc"
block_addr_t DelugePageTransferM$calcOffset(pgnum_t pgNum, uint8_t pktNum)
#line 144
{
  return (block_addr_t )pgNum * (block_addr_t )DELUGE_BYTES_PER_PAGE
   + (uint16_t )pktNum * (uint16_t )DELUGE_PKT_PAYLOAD_SIZE
   + 16;
}

static inline  
# 170 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/DelugeStorageM.nc"
result_t DelugeStorageM$MetadataStore$write(imgnum_t imgNum, void *buf)
#line 170
{
  return DelugeStorageM$newRequest(DelugeStorageM$S_METADATA_WRITE, imgNum, 0, buf, sizeof(DelugeImgDesc ));
}

# 38 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/DelugeMetadataStore.nc"
inline static  result_t DelugeMetadataM$MetadataStore$write(imgnum_t arg_0xa4c9ae0, void *arg_0xa4c9c38){
#line 38
  unsigned char result;
#line 38

#line 38
  result = DelugeStorageM$MetadataStore$write(arg_0xa4c9ae0, arg_0xa4c9c38);
#line 38

#line 38
  return result;
#line 38
}
#line 38
static inline  
# 302 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/DelugeMetadataM.nc"
void DelugeMetadataM$DataWrite$eraseDone(storage_result_t result)
#line 302
{


  if (
#line 304
  result != STORAGE_OK
   || DelugeMetadataM$MetadataStore$write(DelugeMetadataM$curImage, &DelugeMetadataM$imgDesc[DelugeMetadataM$curImage]) == FAIL) {
    DelugeMetadataM$Timer$start(TIMER_ONE_SHOT, 512);
    }
}

static inline  
# 408 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/DelugePageTransferM.nc"
void DelugePageTransferM$DataWrite$eraseDone(storage_result_t result)
#line 408
{
}

# 37 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/DelugeDataWrite.nc"
inline static  void DelugeStorageM$DataWrite$eraseDone(storage_result_t arg_0xa4d2d90){
#line 37
  DelugePageTransferM$DataWrite$eraseDone(arg_0xa4d2d90);
#line 37
  DelugeMetadataM$DataWrite$eraseDone(arg_0xa4d2d90);
#line 37
}
#line 37
static inline  
# 192 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/DelugeStorageM.nc"
result_t DelugeStorageM$DataWrite$commit(imgnum_t imgNum)
#line 192
{
  return DelugeStorageM$newRequest(DelugeStorageM$S_COMMIT, imgNum, 0, 0, 0);
}

# 39 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/DelugeDataWrite.nc"
inline static  result_t DelugeMetadataM$DataWrite$commit(imgnum_t arg_0xa4d3198){
#line 39
  unsigned char result;
#line 39

#line 39
  result = DelugeStorageM$DataWrite$commit(arg_0xa4d3198);
#line 39

#line 39
  return result;
#line 39
}
#line 39
static inline  
# 177 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/DelugeMetadataM.nc"
void DelugeMetadataM$DataRead$verifyDone(storage_result_t result, bool isValid)
#line 177
{

  if (result != STORAGE_OK) {
      DelugeMetadataM$Timer$start(TIMER_ONE_SHOT, 512);
      return;
    }


  if (DelugeMetadataM$state == DelugeMetadataM$S_SCAN_METADATA) {

      if (isValid) {
          DelugeMetadataM$imgDesc[DelugeMetadataM$curImage].numPgsComplete++;
          if (DelugeMetadataM$imgDesc[DelugeMetadataM$curImage].numPgsComplete < DelugeMetadataM$imgDesc[DelugeMetadataM$curImage].numPgs) {
              DelugeMetadataM$verifyNextPage();
              return;
            }
        }

      DelugeMetadataM$scanNextImage();
    }
  else 


    {

      if (!isValid) {
          DelugeMetadataM$imgDesc[DelugeMetadataM$curImage].numPgsComplete = 0;
          DelugeMetadataM$state = DelugeMetadataM$S_SETUP;
          DelugeMetadataM$execute();
          return;
        }

      if (DelugeMetadataM$imgDesc[DelugeMetadataM$curImage].numPgsComplete + 1 >= DelugeMetadataM$imgDesc[DelugeMetadataM$curImage].numPgs) {
          if (DelugeMetadataM$DataWrite$commit(DelugeMetadataM$curImage) == FAIL) {
            DelugeMetadataM$Timer$start(TIMER_ONE_SHOT, 512);
            }
#line 212
          return;
        }

      DelugeMetadataM$imgDesc[DelugeMetadataM$curImage].numPgsComplete++;
      DelugeMetadataM$signalDone();
    }
}

static inline  
# 407 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/DelugePageTransferM.nc"
void DelugePageTransferM$DataRead$verifyDone(storage_result_t result, bool isValid)
#line 407
{
}

# 40 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/DelugeDataRead.nc"
inline static  void DelugeStorageM$DataRead$verifyDone(storage_result_t arg_0xa4d6720, bool arg_0xa4d6868){
#line 40
  DelugePageTransferM$DataRead$verifyDone(arg_0xa4d6720, arg_0xa4d6868);
#line 40
  DelugeMetadataM$DataRead$verifyDone(arg_0xa4d6720, arg_0xa4d6868);
#line 40
}
#line 40
static inline  
# 222 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/DelugeMetadataM.nc"
void DelugeMetadataM$DataWrite$commitDone(storage_result_t result)
#line 222
{

  if (result != STORAGE_OK) {
      DelugeMetadataM$Timer$start(TIMER_ONE_SHOT, 512);
      return;
    }

  DelugeMetadataM$imgDesc[DelugeMetadataM$curImage].numPgsComplete = DelugeMetadataM$imgDesc[DelugeMetadataM$curImage].numPgs;
  if (DelugeMetadataM$curImage == DELUGE_GOLDEN_IMAGE_NUM) {
      DelugeMetadataM$state = DelugeMetadataM$S_SET_WP;
      DelugeMetadataM$execute();
      return;
    }

  DelugeMetadataM$signalDone();
}

static inline  
# 409 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/DelugePageTransferM.nc"
void DelugePageTransferM$DataWrite$commitDone(storage_result_t result)
#line 409
{
}

# 40 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/DelugeDataWrite.nc"
inline static  void DelugeStorageM$DataWrite$commitDone(storage_result_t arg_0xa4d35a0){
#line 40
  DelugePageTransferM$DataWrite$commitDone(arg_0xa4d35a0);
#line 40
  DelugeMetadataM$DataWrite$commitDone(arg_0xa4d35a0);
#line 40
}
#line 40
static inline  
# 127 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/DelugeMetadataM.nc"
void DelugeMetadataM$DelugeStorage$loadImagesDone(result_t result)
#line 127
{

  if (result == SUCCESS) {
      DelugeMetadataM$curImage = 0;
      DelugeMetadataM$state = DelugeMetadataM$S_SCAN_METADATA;
    }
  DelugeMetadataM$execute();
}

static inline  
# 158 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/NetProgM.nc"
void NetProgM$Storage$loadImagesDone(result_t result)
#line 158
{
}

# 35 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/DelugeStorage.nc"
inline static  void DelugeStorageM$DelugeStorage$loadImagesDone(result_t arg_0xa4d5b38){
#line 35
  NetProgM$Storage$loadImagesDone(arg_0xa4d5b38);
#line 35
  DelugeMetadataM$DelugeStorage$loadImagesDone(arg_0xa4d5b38);
#line 35
}
#line 35
static inline  
# 221 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/DelugeStorageM.nc"
void DelugeStorageM$BlockWrite$writeDone(uint8_t volume, storage_result_t result, block_addr_t addr, void *buf, block_addr_t len)
#line 221
{
  DelugeStorageM$signalDone(result);
}

static inline   
# 312 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/BlockStorageM.nc"
void BlockStorageM$BlockWrite$default$writeDone(uint8_t id, storage_result_t result, block_addr_t addr, void *buf, block_addr_t len)
#line 312
{
}

# 33 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/BlockWrite.nc"
inline static  void BlockStorageM$BlockWrite$writeDone(blockstorage_t arg_0xa570b10, storage_result_t arg_0xa50b400, block_addr_t arg_0xa50b550, void *arg_0xa50b6a8, block_addr_t arg_0xa50b7f8){
#line 33
  switch (arg_0xa570b10) {
#line 33
    case DELUGE_VOLUME_ID_0:
#line 33
      DelugeStorageM$BlockWrite$writeDone(DELUGE_VOLUME_ID_0, arg_0xa50b400, arg_0xa50b550, arg_0xa50b6a8, arg_0xa50b7f8);
#line 33
      break;
#line 33
    case DELUGE_VOLUME_ID_1:
#line 33
      DelugeStorageM$BlockWrite$writeDone(DELUGE_VOLUME_ID_1, arg_0xa50b400, arg_0xa50b550, arg_0xa50b6a8, arg_0xa50b7f8);
#line 33
      break;
#line 33
    case DELUGE_VOLUME_ID_2:
#line 33
      DelugeStorageM$BlockWrite$writeDone(DELUGE_VOLUME_ID_2, arg_0xa50b400, arg_0xa50b550, arg_0xa50b6a8, arg_0xa50b7f8);
#line 33
      break;
#line 33
    default:
#line 33
      BlockStorageM$BlockWrite$default$writeDone(arg_0xa570b10, arg_0xa50b400, arg_0xa50b550, arg_0xa50b6a8, arg_0xa50b7f8);
#line 33
    }
#line 33
}
#line 33
static inline  
# 225 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/DelugeStorageM.nc"
void DelugeStorageM$BlockWrite$eraseDone(uint8_t volume, storage_result_t result)
#line 225
{
  DelugeStorageM$signalDone(result);
}

static inline   
# 313 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/BlockStorageM.nc"
void BlockStorageM$BlockWrite$default$eraseDone(uint8_t id, storage_result_t result)
#line 313
{
}

# 36 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/BlockWrite.nc"
inline static  void BlockStorageM$BlockWrite$eraseDone(blockstorage_t arg_0xa570b10, storage_result_t arg_0xa50bec8){
#line 36
  switch (arg_0xa570b10) {
#line 36
    case DELUGE_VOLUME_ID_0:
#line 36
      DelugeStorageM$BlockWrite$eraseDone(DELUGE_VOLUME_ID_0, arg_0xa50bec8);
#line 36
      break;
#line 36
    case DELUGE_VOLUME_ID_1:
#line 36
      DelugeStorageM$BlockWrite$eraseDone(DELUGE_VOLUME_ID_1, arg_0xa50bec8);
#line 36
      break;
#line 36
    case DELUGE_VOLUME_ID_2:
#line 36
      DelugeStorageM$BlockWrite$eraseDone(DELUGE_VOLUME_ID_2, arg_0xa50bec8);
#line 36
      break;
#line 36
    default:
#line 36
      BlockStorageM$BlockWrite$default$eraseDone(arg_0xa570b10, arg_0xa50bec8);
#line 36
    }
#line 36
}
#line 36
static inline  
# 216 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/DelugeStorageM.nc"
void DelugeStorageM$BlockRead$computeCrcDone(uint8_t volume, storage_result_t result, uint16_t crc, block_addr_t addr, block_addr_t len)
#line 216
{
  DelugeStorageM$crcScratch = crc == DelugeStorageM$crcScratch;
  DelugeStorageM$signalDone(result);
}

static inline   
# 317 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/BlockStorageM.nc"
void BlockStorageM$BlockRead$default$computeCrcDone(uint8_t id, storage_result_t result, uint16_t x, block_addr_t addr, block_addr_t len)
#line 317
{
}

# 39 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/BlockRead.nc"
inline static  void BlockStorageM$BlockRead$computeCrcDone(blockstorage_t arg_0xa571390, storage_result_t arg_0xa526d80, uint16_t arg_0xa526ed0, block_addr_t arg_0xa527020, block_addr_t arg_0xa527170){
#line 39
  switch (arg_0xa571390) {
#line 39
    case DELUGE_VOLUME_ID_0:
#line 39
      DelugeStorageM$BlockRead$computeCrcDone(DELUGE_VOLUME_ID_0, arg_0xa526d80, arg_0xa526ed0, arg_0xa527020, arg_0xa527170);
#line 39
      break;
#line 39
    case DELUGE_VOLUME_ID_1:
#line 39
      DelugeStorageM$BlockRead$computeCrcDone(DELUGE_VOLUME_ID_1, arg_0xa526d80, arg_0xa526ed0, arg_0xa527020, arg_0xa527170);
#line 39
      break;
#line 39
    case DELUGE_VOLUME_ID_2:
#line 39
      DelugeStorageM$BlockRead$computeCrcDone(DELUGE_VOLUME_ID_2, arg_0xa526d80, arg_0xa526ed0, arg_0xa527020, arg_0xa527170);
#line 39
      break;
#line 39
    default:
#line 39
      BlockStorageM$BlockRead$default$computeCrcDone(arg_0xa571390, arg_0xa526d80, arg_0xa526ed0, arg_0xa527020, arg_0xa527170);
#line 39
    }
#line 39
}
#line 39
static inline  
# 229 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/DelugeStorageM.nc"
void DelugeStorageM$BlockWrite$commitDone(uint8_t volume, storage_result_t result)
#line 229
{
  DelugeStorageM$signalDone(result);
}

static inline   
# 314 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/BlockStorageM.nc"
void BlockStorageM$BlockWrite$default$commitDone(uint8_t id, result_t result)
#line 314
{
}

# 39 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/BlockWrite.nc"
inline static  void BlockStorageM$BlockWrite$commitDone(blockstorage_t arg_0xa570b10, storage_result_t arg_0xa53a5a0){
#line 39
  switch (arg_0xa570b10) {
#line 39
    case DELUGE_VOLUME_ID_0:
#line 39
      DelugeStorageM$BlockWrite$commitDone(DELUGE_VOLUME_ID_0, arg_0xa53a5a0);
#line 39
      break;
#line 39
    case DELUGE_VOLUME_ID_1:
#line 39
      DelugeStorageM$BlockWrite$commitDone(DELUGE_VOLUME_ID_1, arg_0xa53a5a0);
#line 39
      break;
#line 39
    case DELUGE_VOLUME_ID_2:
#line 39
      DelugeStorageM$BlockWrite$commitDone(DELUGE_VOLUME_ID_2, arg_0xa53a5a0);
#line 39
      break;
#line 39
    default:
#line 39
      BlockStorageM$BlockWrite$default$commitDone(arg_0xa570b10, arg_0xa53a5a0);
#line 39
    }
#line 39
}
#line 39
static inline  
# 233 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/DelugeStorageM.nc"
void DelugeStorageM$BlockRead$verifyDone(uint8_t volume, storage_result_t result)
#line 233
{
}

static inline   
# 316 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/BlockStorageM.nc"
void BlockStorageM$BlockRead$default$verifyDone(uint8_t id, result_t result)
#line 316
{
}

# 36 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/BlockRead.nc"
inline static  void BlockStorageM$BlockRead$verifyDone(blockstorage_t arg_0xa571390, storage_result_t arg_0xa526410){
#line 36
  switch (arg_0xa571390) {
#line 36
    case DELUGE_VOLUME_ID_0:
#line 36
      DelugeStorageM$BlockRead$verifyDone(DELUGE_VOLUME_ID_0, arg_0xa526410);
#line 36
      break;
#line 36
    case DELUGE_VOLUME_ID_1:
#line 36
      DelugeStorageM$BlockRead$verifyDone(DELUGE_VOLUME_ID_1, arg_0xa526410);
#line 36
      break;
#line 36
    case DELUGE_VOLUME_ID_2:
#line 36
      DelugeStorageM$BlockRead$verifyDone(DELUGE_VOLUME_ID_2, arg_0xa526410);
#line 36
      break;
#line 36
    default:
#line 36
      BlockStorageM$BlockRead$default$verifyDone(arg_0xa571390, arg_0xa526410);
#line 36
    }
#line 36
}
#line 36
# 48 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/PageEEPROM.nc"
inline static  result_t BlockStorageM$PageEEPROM$read(blockstorage_t arg_0xa571d00, eeprompage_t arg_0xa568418, eeprompageoffset_t arg_0xa568570, void *arg_0xa5686d8, eeprompageoffset_t arg_0xa568830){
#line 48
  unsigned char result;
#line 48

#line 48
  result = HALAT45DBShare$PageEEPROM$read(arg_0xa571d00, arg_0xa568418, arg_0xa568570, arg_0xa5686d8, arg_0xa568830);
#line 48

#line 48
  return result;
#line 48
}
#line 48
static inline  
# 559 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/mica/PageEEPROMM.nc"
result_t PageEEPROMM$PageEEPROM$computeCrcContinue(eeprompage_t page, 
eeprompageoffset_t offset, 
eeprompageoffset_t n, 
uint16_t crc)
#line 562
{
  return PageEEPROMM$computeCrc(page, offset, n, crc);
}

# 54 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/PageEEPROM.nc"
inline static  result_t PageEEPROMShare$ActualEEPROM$computeCrcContinue(eeprompage_t arg_0xa5697d0, eeprompageoffset_t arg_0xa569928, eeprompageoffset_t arg_0xa569a90, uint16_t arg_0xa569be0){
#line 54
  unsigned char result;
#line 54

#line 54
  result = PageEEPROMM$PageEEPROM$computeCrcContinue(arg_0xa5697d0, arg_0xa569928, arg_0xa569a90, arg_0xa569be0);
#line 54

#line 54
  return result;
#line 54
}
#line 54
static 
# 154 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/PageEEPROMShare.nc"
__inline  result_t PageEEPROMShare$PageEEPROM$computeCrcContinue(uint8_t client, eeprompage_t page, eeprompageoffset_t offset, eeprompageoffset_t n, uint16_t crc)
#line 154
{
  if (!PageEEPROMShare$setClient(client)) {
    return FAIL;
    }
#line 157
  return PageEEPROMShare$check(PageEEPROMShare$ActualEEPROM$computeCrcContinue(page, offset, n, crc));
}

# 54 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/PageEEPROM.nc"
inline static  result_t HALAT45DBShare$ActualAT45$computeCrcContinue(eeprompage_t arg_0xa5697d0, eeprompageoffset_t arg_0xa569928, eeprompageoffset_t arg_0xa569a90, uint16_t arg_0xa569be0){
#line 54
  unsigned char result;
#line 54

#line 54
  result = PageEEPROMShare$PageEEPROM$computeCrcContinue(0, arg_0xa5697d0, arg_0xa569928, arg_0xa569a90, arg_0xa569be0);
#line 54

#line 54
  return result;
#line 54
}
#line 54
static 
# 151 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/HALAT45DBShare.nc"
__inline  result_t HALAT45DBShare$PageEEPROM$computeCrcContinue(volume_t client, at45page_t page, at45pageoffset_t offset, at45pageoffset_t n, uint16_t crc)
#line 151
{
  if (!HALAT45DBShare$setClient(client)) {
    return FAIL;
    }
#line 154
  return HALAT45DBShare$check(HALAT45DBShare$ActualAT45$computeCrcContinue(HALAT45DBShare$remap(page), offset, n, crc));
}

# 54 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/PageEEPROM.nc"
inline static  result_t BlockStorageM$PageEEPROM$computeCrcContinue(blockstorage_t arg_0xa571d00, eeprompage_t arg_0xa5697d0, eeprompageoffset_t arg_0xa569928, eeprompageoffset_t arg_0xa569a90, uint16_t arg_0xa569be0){
#line 54
  unsigned char result;
#line 54

#line 54
  result = HALAT45DBShare$PageEEPROM$computeCrcContinue(arg_0xa571d00, arg_0xa5697d0, arg_0xa569928, arg_0xa569a90, arg_0xa569be0);
#line 54

#line 54
  return result;
#line 54
}
#line 54
static inline   
# 238 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/DelugeStorageM.nc"
result_t DelugeStorageM$BlockWrite$default$write(blockstorage_t blockId, block_addr_t addr, void *buf, block_addr_t len)
#line 238
{
#line 238
  return FAIL;
}

# 32 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/BlockWrite.nc"
inline static  result_t DelugeStorageM$BlockWrite$write(blockstorage_t arg_0xa527ef0, block_addr_t arg_0xa50ad40, void *arg_0xa50ae98, block_addr_t arg_0xa50afe8){
#line 32
  unsigned char result;
#line 32

#line 32
  switch (arg_0xa527ef0) {
#line 32
    case DELUGE_VOLUME_ID_0:
#line 32
      result = BlockStorageM$BlockWrite$write(DELUGE_VOLUME_ID_0, arg_0xa50ad40, arg_0xa50ae98, arg_0xa50afe8);
#line 32
      break;
#line 32
    case DELUGE_VOLUME_ID_1:
#line 32
      result = BlockStorageM$BlockWrite$write(DELUGE_VOLUME_ID_1, arg_0xa50ad40, arg_0xa50ae98, arg_0xa50afe8);
#line 32
      break;
#line 32
    case DELUGE_VOLUME_ID_2:
#line 32
      result = BlockStorageM$BlockWrite$write(DELUGE_VOLUME_ID_2, arg_0xa50ad40, arg_0xa50ae98, arg_0xa50afe8);
#line 32
      break;
#line 32
    default:
#line 32
      result = DelugeStorageM$BlockWrite$default$write(arg_0xa527ef0, arg_0xa50ad40, arg_0xa50ae98, arg_0xa50afe8);
#line 32
    }
#line 32

#line 32
  return result;
#line 32
}
#line 32
static inline   
# 239 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/DelugeStorageM.nc"
result_t DelugeStorageM$BlockWrite$default$erase(blockstorage_t blockId)
#line 239
{
#line 239
  return FAIL;
}

# 35 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/BlockWrite.nc"
inline static  result_t DelugeStorageM$BlockWrite$erase(blockstorage_t arg_0xa527ef0){
#line 35
  unsigned char result;
#line 35

#line 35
  switch (arg_0xa527ef0) {
#line 35
    case DELUGE_VOLUME_ID_0:
#line 35
      result = BlockStorageM$BlockWrite$erase(DELUGE_VOLUME_ID_0);
#line 35
      break;
#line 35
    case DELUGE_VOLUME_ID_1:
#line 35
      result = BlockStorageM$BlockWrite$erase(DELUGE_VOLUME_ID_1);
#line 35
      break;
#line 35
    case DELUGE_VOLUME_ID_2:
#line 35
      result = BlockStorageM$BlockWrite$erase(DELUGE_VOLUME_ID_2);
#line 35
      break;
#line 35
    default:
#line 35
      result = DelugeStorageM$BlockWrite$default$erase(arg_0xa527ef0);
#line 35
    }
#line 35

#line 35
  return result;
#line 35
}
#line 35
static inline  
# 602 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/mica/PageEEPROMM.nc"
result_t PageEEPROMM$PageEEPROM$erase(eeprompage_t page, uint8_t eraseKind)
#line 602
{
  return PageEEPROMM$newRequest(PageEEPROMM$R_ERASE, page, eraseKind, (void *)0, 0, 0);
}

# 37 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/PageEEPROM.nc"
inline static  result_t PageEEPROMShare$ActualEEPROM$erase(eeprompage_t arg_0xa56a468, uint8_t arg_0xa56a5b8){
#line 37
  unsigned char result;
#line 37

#line 37
  result = PageEEPROMM$PageEEPROM$erase(arg_0xa56a468, arg_0xa56a5b8);
#line 37

#line 37
  return result;
#line 37
}
#line 37
static 
# 90 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/PageEEPROMShare.nc"
__inline  result_t PageEEPROMShare$PageEEPROM$erase(uint8_t client, eeprompage_t page, uint8_t eraseKind)
#line 90
{
  if (!PageEEPROMShare$setClient(client)) {
    return FAIL;
    }
#line 93
  return PageEEPROMShare$check(PageEEPROMShare$ActualEEPROM$erase(page, eraseKind));
}

# 37 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/PageEEPROM.nc"
inline static  result_t HALAT45DBShare$ActualAT45$erase(eeprompage_t arg_0xa56a468, uint8_t arg_0xa56a5b8){
#line 37
  unsigned char result;
#line 37

#line 37
  result = PageEEPROMShare$PageEEPROM$erase(0, arg_0xa56a468, arg_0xa56a5b8);
#line 37

#line 37
  return result;
#line 37
}
#line 37
static 
# 91 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/HALAT45DBShare.nc"
__inline  result_t HALAT45DBShare$PageEEPROM$erase(volume_t client, at45page_t page, uint8_t eraseKind)
#line 91
{
  if (!HALAT45DBShare$setClient(client)) {
    return FAIL;
    }
#line 94
  return HALAT45DBShare$check(HALAT45DBShare$ActualAT45$erase(HALAT45DBShare$remap(page), eraseKind));
}

# 37 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/PageEEPROM.nc"
inline static  result_t BlockStorageM$PageEEPROM$erase(blockstorage_t arg_0xa571d00, eeprompage_t arg_0xa56a468, uint8_t arg_0xa56a5b8){
#line 37
  unsigned char result;
#line 37

#line 37
  result = HALAT45DBShare$PageEEPROM$erase(arg_0xa571d00, arg_0xa56a468, arg_0xa56a5b8);
#line 37

#line 37
  return result;
#line 37
}
#line 37
static inline  
# 208 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/BlockStorageM.nc"
result_t BlockStorageM$BlockWrite$commit(uint8_t id)
#line 208
{
  return BlockStorageM$newRequest(BlockStorageM$S_COMMIT, id, 0, (void *)0, BlockStorageM$maxAddr[id]);
}

static inline   
# 240 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/DelugeStorageM.nc"
result_t DelugeStorageM$BlockWrite$default$commit(blockstorage_t blockId)
#line 240
{
#line 240
  return FAIL;
}

# 38 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/BlockWrite.nc"
inline static  result_t DelugeStorageM$BlockWrite$commit(blockstorage_t arg_0xa527ef0){
#line 38
  unsigned char result;
#line 38

#line 38
  switch (arg_0xa527ef0) {
#line 38
    case DELUGE_VOLUME_ID_0:
#line 38
      result = BlockStorageM$BlockWrite$commit(DELUGE_VOLUME_ID_0);
#line 38
      break;
#line 38
    case DELUGE_VOLUME_ID_1:
#line 38
      result = BlockStorageM$BlockWrite$commit(DELUGE_VOLUME_ID_1);
#line 38
      break;
#line 38
    case DELUGE_VOLUME_ID_2:
#line 38
      result = BlockStorageM$BlockWrite$commit(DELUGE_VOLUME_ID_2);
#line 38
      break;
#line 38
    default:
#line 38
      result = DelugeStorageM$BlockWrite$default$commit(arg_0xa527ef0);
#line 38
    }
#line 38

#line 38
  return result;
#line 38
}
#line 38
# 48 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/SendMsg.nc"
inline static  result_t DelugePageTransferM$SendReqMsg$send(uint16_t arg_0xa46f5a8, uint8_t arg_0xa46f6f0, TOS_MsgPtr arg_0xa46f840){
#line 48
  unsigned char result;
#line 48

#line 48
  result = AMStandard$SendMsg$send(AM_DELUGEREQMSG, arg_0xa46f5a8, arg_0xa46f6f0, arg_0xa46f840);
#line 48

#line 48
  return result;
#line 48
}
#line 48
# 63 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/StdControl.nc"
inline static  result_t AMStandard$TimerControl$init(void){
#line 63
  unsigned char result;
#line 63

#line 63
  result = TimerM$StdControl$init();
#line 63

#line 63
  return result;
#line 63
}
#line 63
static inline  
# 60 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/system/UARTM.nc"
result_t UARTM$Control$init(void)
#line 60
{
  {
  }
#line 61
  ;
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 62
    {
      UARTM$state = FALSE;
    }
#line 64
    __nesc_atomic_end(__nesc_atomic); }
  return SUCCESS;
}

# 63 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/StdControl.nc"
inline static  result_t FramerM$ByteControl$init(void){
#line 63
  unsigned char result;
#line 63

#line 63
  result = UARTM$Control$init();
#line 63

#line 63
  return result;
#line 63
}
#line 63
static inline  
# 336 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/micaz/FramerM.nc"
result_t FramerM$StdControl$init(void)
#line 336
{
  FramerM$HDLCInitialize();
  return FramerM$ByteControl$init();
}

# 63 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/StdControl.nc"
inline static  result_t AMStandard$UARTControl$init(void){
#line 63
  unsigned char result;
#line 63

#line 63
  result = FramerM$StdControl$init();
#line 63

#line 63
  return result;
#line 63
}
#line 63
static inline   
# 212 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/CC2420Radio/CC2420RadioM.nc"
result_t CC2420RadioM$SplitControl$default$initDone(void)
#line 212
{
  return SUCCESS;
}

# 70 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/SplitControl.nc"
inline static  result_t CC2420RadioM$SplitControl$initDone(void){
#line 70
  unsigned char result;
#line 70

#line 70
  result = CC2420RadioM$SplitControl$default$initDone();
#line 70

#line 70
  return result;
#line 70
}
#line 70
static inline  
# 208 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/CC2420Radio/CC2420RadioM.nc"
result_t CC2420RadioM$CC2420SplitControl$initDone(void)
#line 208
{
  return CC2420RadioM$SplitControl$initDone();
}

# 70 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/SplitControl.nc"
inline static  result_t CC2420ControlM$SplitControl$initDone(void){
#line 70
  unsigned char result;
#line 70

#line 70
  result = CC2420RadioM$CC2420SplitControl$initDone();
#line 70

#line 70
  return result;
#line 70
}
#line 70
static inline  
# 108 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/CC2420Radio/CC2420ControlM.nc"
void CC2420ControlM$taskInitDone(void)
#line 108
{
  CC2420ControlM$SplitControl$initDone();
}

static inline  
# 47 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/micaz/HPLTimer1M.nc"
result_t HPLTimer1M$StdControl$init(void)
#line 47
{
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 48
    {
      HPLTimer1M$mscale = TCLK_CPU_DIV256;
      HPLTimer1M$minterval = TIMER1_DEFAULT_INTERVAL;
    }
#line 51
    __nesc_atomic_end(__nesc_atomic); }
  return SUCCESS;
}

# 63 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/StdControl.nc"
inline static  result_t HPLCC2420M$TimerControl$init(void){
#line 63
  unsigned char result;
#line 63

#line 63
  result = TimerM$StdControl$init();
#line 63

#line 63
  return result;
#line 63
}
#line 63
# 149 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/micaz/hardware.h"
static __inline void TOSH_MAKE_CC_CS_OUTPUT(void)
#line 149
{
#line 149
  * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x17 + 0x20) |= 1 << 0;
}

static inline  
# 65 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/micaz/HPLCC2420M.nc"
result_t HPLCC2420M$StdControl$init(void)
#line 65
{

  HPLCC2420M$bSpiAvail = TRUE;
  TOSH_MAKE_MISO_INPUT();
  TOSH_MAKE_MOSI_OUTPUT();
  TOSH_MAKE_SPI_SCK_OUTPUT();
  TOSH_MAKE_CC_RSTN_OUTPUT();
  TOSH_MAKE_CC_VREN_OUTPUT();
  TOSH_MAKE_CC_CS_OUTPUT();
  TOSH_MAKE_CC_FIFOP1_INPUT();
  TOSH_MAKE_CC_CCA_INPUT();
  TOSH_MAKE_CC_SFD_INPUT();
  TOSH_MAKE_CC_FIFO_INPUT();
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 78
    {
      TOSH_MAKE_SPI_SCK_OUTPUT();
      TOSH_MAKE_MISO_INPUT();
      TOSH_MAKE_MOSI_OUTPUT();
      * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x0E + 0x20) |= 1 << 0;
      * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x0D + 0x20) |= 1 << 4;
      * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x0D + 0x20) &= ~(1 << 3);
      * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x0D + 0x20) &= ~(1 << 2);
      * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x0D + 0x20) &= ~(1 << 1);
      * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x0D + 0x20) &= ~(1 << 0);

      * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x0D + 0x20) |= 1 << 6;
    }
#line 90
    __nesc_atomic_end(__nesc_atomic); }
  HPLCC2420M$TimerControl$init();
  return SUCCESS;
}

# 63 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/StdControl.nc"
inline static  result_t CC2420ControlM$HPLChipconControl$init(void){
#line 63
  unsigned char result;
#line 63

#line 63
  result = HPLCC2420M$StdControl$init();
#line 63
  result = rcombine(result, HPLTimer1M$StdControl$init());
#line 63

#line 63
  return result;
#line 63
}
#line 63
static inline  
# 129 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/CC2420Radio/CC2420ControlM.nc"
result_t CC2420ControlM$SplitControl$init(void)
#line 129
{

  uint8_t _state = FALSE;

  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 133
    {
      if (CC2420ControlM$state == CC2420ControlM$IDLE_STATE) {
          CC2420ControlM$state = CC2420ControlM$INIT_STATE;
          _state = TRUE;
        }
    }
#line 138
    __nesc_atomic_end(__nesc_atomic); }
  if (!_state) {
    return FAIL;
    }
  CC2420ControlM$HPLChipconControl$init();


  CC2420ControlM$gCurrentParameters[CP_MAIN] = 0xf800;
  CC2420ControlM$gCurrentParameters[CP_MDMCTRL0] = ((((0 << 11) | (
  2 << 8)) | (3 << 6)) | (
  1 << 5)) | (2 << 0);

  CC2420ControlM$gCurrentParameters[CP_MDMCTRL1] = 20 << 6;

  CC2420ControlM$gCurrentParameters[CP_RSSI] = 0xE080;
  CC2420ControlM$gCurrentParameters[CP_SYNCWORD] = 0xA70F;
  CC2420ControlM$gCurrentParameters[CP_TXCTRL] = ((((1 << 14) | (
  1 << 13)) | (3 << 6)) | (
  1 << 5)) | (CC2420_RFPOWER << 0);

  CC2420ControlM$gCurrentParameters[CP_RXCTRL0] = (((((1 << 12) | (
  2 << 8)) | (3 << 6)) | (
  2 << 4)) | (1 << 2)) | (
  1 << 0);

  CC2420ControlM$gCurrentParameters[CP_RXCTRL1] = (((((1 << 11) | (
  1 << 9)) | (1 << 6)) | (
  1 << 4)) | (1 << 2)) | (
  2 << 0);

  CC2420ControlM$gCurrentParameters[CP_FSCTRL] = (1 << 14) | ((
  357 + 5 * (CC2420_CHANNEL - 11)) << 0);

  CC2420ControlM$gCurrentParameters[CP_SECCTRL0] = (((1 << 8) | (
  1 << 7)) | (1 << 6)) | (
  1 << 2);

  CC2420ControlM$gCurrentParameters[CP_SECCTRL1] = 0;
  CC2420ControlM$gCurrentParameters[CP_BATTMON] = 0;



  CC2420ControlM$gCurrentParameters[CP_IOCFG0] = (127 << 0) | (
  1 << 9);

  CC2420ControlM$gCurrentParameters[CP_IOCFG1] = 0;

  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 185
    CC2420ControlM$state = CC2420ControlM$INIT_STATE_DONE;
#line 185
    __nesc_atomic_end(__nesc_atomic); }
  TOS_post(CC2420ControlM$taskInitDone);
  return SUCCESS;
}

# 64 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/SplitControl.nc"
inline static  result_t CC2420RadioM$CC2420SplitControl$init(void){
#line 64
  unsigned char result;
#line 64

#line 64
  result = CC2420ControlM$SplitControl$init();
#line 64

#line 64
  return result;
#line 64
}
#line 64
static inline   
# 59 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/system/RandomLFSR.nc"
result_t RandomLFSR$Random$init(void)
#line 59
{
  {
  }
#line 60
  ;
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 61
    {
      RandomLFSR$shiftReg = 119 * 119 * (TOS_LOCAL_ADDRESS + 1);
      RandomLFSR$initSeed = RandomLFSR$shiftReg;
      RandomLFSR$mask = 137 * 29 * (TOS_LOCAL_ADDRESS + 1);
    }
#line 65
    __nesc_atomic_end(__nesc_atomic); }
  return SUCCESS;
}

# 57 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/Random.nc"
inline static   result_t CC2420RadioM$Random$init(void){
#line 57
  unsigned char result;
#line 57

#line 57
  result = RandomLFSR$Random$init();
#line 57

#line 57
  return result;
#line 57
}
#line 57
static inline  
# 22 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/micaz/TimerJiffyAsyncM.nc"
result_t TimerJiffyAsyncM$StdControl$init(void)
{

  return SUCCESS;
}

# 63 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/StdControl.nc"
inline static  result_t CC2420RadioM$TimerControl$init(void){
#line 63
  unsigned char result;
#line 63

#line 63
  result = TimerJiffyAsyncM$StdControl$init();
#line 63

#line 63
  return result;
#line 63
}
#line 63
static inline  
# 191 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/CC2420Radio/CC2420RadioM.nc"
result_t CC2420RadioM$SplitControl$init(void)
#line 191
{

  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 193
    {
      CC2420RadioM$stateRadio = CC2420RadioM$DISABLED_STATE;
      CC2420RadioM$currentDSN = 0;
      CC2420RadioM$bAckEnable = FALSE;
      CC2420RadioM$bPacketReceiving = FALSE;
      CC2420RadioM$rxbufptr = &CC2420RadioM$RxBuf;
      CC2420RadioM$rxbufptr->length = 0;
    }
#line 200
    __nesc_atomic_end(__nesc_atomic); }

  CC2420RadioM$TimerControl$init();
  CC2420RadioM$Random$init();
  CC2420RadioM$LocalAddr = TOS_LOCAL_ADDRESS;
  return CC2420RadioM$CC2420SplitControl$init();
}

static inline  
#line 186
result_t CC2420RadioM$StdControl$init(void)
#line 186
{
  return CC2420RadioM$SplitControl$init();
}

# 63 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/StdControl.nc"
inline static  result_t AMStandard$RadioControl$init(void){
#line 63
  unsigned char result;
#line 63

#line 63
  result = CC2420RadioM$StdControl$init();
#line 63

#line 63
  return result;
#line 63
}
#line 63
# 59 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/Timer.nc"
inline static  result_t BlinkM$Timer$start(char arg_0xa344320, uint32_t arg_0xa344478){
#line 59
  unsigned char result;
#line 59

#line 59
  result = TimerM$Timer$start(0, arg_0xa344320, arg_0xa344478);
#line 59

#line 59
  return result;
#line 59
}
#line 59
static inline  
# 48 "TestSenseM.nc"
int TestSenseM$TestSense_interface$getStatus(void)
{
  return TestSenseM$sleeping;
}

# 4 "TestSense_interface.nc"
inline static  int BlinkM$App$getStatus(void){
#line 4
  int result;
#line 4

#line 4
  result = TestSenseM$TestSense_interface$getStatus();
#line 4

#line 4
  return result;
#line 4
}
#line 4
static inline  
# 70 "BlinkM.nc"
result_t BlinkM$StdControl$start(void)
#line 70
{
  if (BlinkM$App$getStatus() == 1) {
    BlinkM$Timer$start(TIMER_REPEAT, 1000);
    }
}

static inline  
# 87 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/system/TimerM.nc"
result_t TimerM$StdControl$start(void)
#line 87
{
  return SUCCESS;
}

# 70 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/StdControl.nc"
inline static  result_t TestSenseM$CommControl$start(void){
#line 70
  unsigned char result;
#line 70

#line 70
  result = AMStandard$Control$start();
#line 70

#line 70
  return result;
#line 70
}
#line 70
# 59 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/Timer.nc"
inline static  result_t TestSenseM$initTimer$start(char arg_0xa344320, uint32_t arg_0xa344478){
#line 59
  unsigned char result;
#line 59

#line 59
  result = TimerM$Timer$start(9, arg_0xa344320, arg_0xa344478);
#line 59

#line 59
  return result;
#line 59
}
#line 59
static inline  
# 113 "TestSenseM.nc"
result_t TestSenseM$StdControl$start(void)
#line 113
{
  TestSenseM$initTimer$start(TIMER_ONE_SHOT, 1000);
  TestSenseM$CommControl$start();
  return SUCCESS;
}

static inline  
# 172 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/DelugeM.nc"
result_t DelugeM$StdControl$start(void)
#line 172
{

  if (DelugeM$state == DelugeM$S_STOPPED) {
    DelugeM$realStart();
    }
  DelugeM$state = DelugeM$S_STARTED;

  DelugeM$resetTimer(0);

  return SUCCESS;
}

static inline  
# 74 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/DelugeMetadataM.nc"
result_t DelugeMetadataM$SplitControl$start(void)
#line 74
{
  if (DelugeMetadataM$state == DelugeMetadataM$S_INIT) {
    DelugeMetadataM$Timer$start(TIMER_ONE_SHOT, 32);
    }
#line 77
  return SUCCESS;
}

# 77 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/SplitControl.nc"
inline static  result_t NetProgM$MetadataControl$start(void){
#line 77
  unsigned char result;
#line 77

#line 77
  result = DelugeMetadataM$SplitControl$start();
#line 77

#line 77
  return result;
#line 77
}
#line 77
static inline  
# 89 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/NetProgM.nc"
result_t NetProgM$StdControl$start(void)
#line 89
{
  NetProgM$MetadataControl$start();
  return SUCCESS;
}

static inline  
# 38 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/FlashWPC.nc"
result_t FlashWPC$StdControl$start(void)
#line 38
{
#line 38
  return SUCCESS;
}

static inline  
# 74 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/mica2/HPLFlash.nc"
result_t HPLFlash$FlashControl$start(void)
#line 74
{
  return SUCCESS;
}

# 70 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/StdControl.nc"
inline static  result_t PageEEPROMM$FlashControl$start(void){
#line 70
  unsigned char result;
#line 70

#line 70
  result = HPLFlash$FlashControl$start();
#line 70

#line 70
  return result;
#line 70
}
#line 70
static inline  
# 148 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/mica/PageEEPROMM.nc"
result_t PageEEPROMM$StdControl$start(void)
#line 148
{
  return PageEEPROMM$FlashControl$start();
}

static inline  
# 45 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/StorageManagerM.nc"
result_t StorageManagerM$StdControl$start(void)
#line 45
{
  return SUCCESS;
}

# 70 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/StdControl.nc"
inline static  result_t RealMain$StdControl$start(void){
#line 70
  unsigned char result;
#line 70

#line 70
  result = TimerM$StdControl$start();
#line 70
  result = rcombine(result, DelugeM$StdControl$start());
#line 70
  result = rcombine(result, AMStandard$Control$start());
#line 70
  result = rcombine(result, StorageManagerM$StdControl$start());
#line 70
  result = rcombine(result, PageEEPROMM$StdControl$start());
#line 70
  result = rcombine(result, FlashWPC$StdControl$start());
#line 70
  result = rcombine(result, NetProgM$StdControl$start());
#line 70
  result = rcombine(result, DelugeM$StdControl$start());
#line 70
  result = rcombine(result, TestSenseM$StdControl$start());
#line 70
  result = rcombine(result, TimerM$StdControl$start());
#line 70
  result = rcombine(result, BlinkM$StdControl$start());
#line 70

#line 70
  return result;
#line 70
}
#line 70
inline static  result_t AMStandard$TimerControl$start(void){
#line 70
  unsigned char result;
#line 70

#line 70
  result = TimerM$StdControl$start();
#line 70

#line 70
  return result;
#line 70
}
#line 70
static inline   
# 60 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/mica2/HPLUART0M.nc"
result_t HPLUART0M$UART$init(void)
#line 60
{





  * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)0x90 = 0;
  * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x09 + 0x20) = 15;


  * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x0B + 0x20) = 1 << 1;


  * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)0x95 = (1 << 2) | (1 << 1);


  * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x0A + 0x20) = (((1 << 7) | (1 << 6)) | (1 << 4)) | (1 << 3);


  return SUCCESS;
}

# 62 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/HPLUART.nc"
inline static   result_t UARTM$HPLUART$init(void){
#line 62
  unsigned char result;
#line 62

#line 62
  result = HPLUART0M$UART$init();
#line 62

#line 62
  return result;
#line 62
}
#line 62
static inline  
# 68 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/system/UARTM.nc"
result_t UARTM$Control$start(void)
#line 68
{
  return UARTM$HPLUART$init();
}

# 70 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/StdControl.nc"
inline static  result_t FramerM$ByteControl$start(void){
#line 70
  unsigned char result;
#line 70

#line 70
  result = UARTM$Control$start();
#line 70

#line 70
  return result;
#line 70
}
#line 70
static inline  
# 341 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/micaz/FramerM.nc"
result_t FramerM$StdControl$start(void)
#line 341
{
  FramerM$HDLCInitialize();
  return FramerM$ByteControl$start();
}

# 70 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/StdControl.nc"
inline static  result_t AMStandard$UARTControl$start(void){
#line 70
  unsigned char result;
#line 70

#line 70
  result = FramerM$StdControl$start();
#line 70

#line 70
  return result;
#line 70
}
#line 70
# 47 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/CC2420Radio/HPLCC2420.nc"
inline static   uint8_t CC2420ControlM$HPLChipcon$cmd(uint8_t arg_0xa768cd8){
#line 47
  unsigned char result;
#line 47

#line 47
  result = HPLCC2420M$HPLCC2420$cmd(arg_0xa768cd8);
#line 47

#line 47
  return result;
#line 47
}
#line 47
# 59 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/Timer.nc"
inline static  result_t HPLCC2420InterruptM$CCATimer$start(char arg_0xa344320, uint32_t arg_0xa344478){
#line 59
  unsigned char result;
#line 59

#line 59
  result = TimerM$Timer$start(6, arg_0xa344320, arg_0xa344478);
#line 59

#line 59
  return result;
#line 59
}
#line 59
# 147 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/micaz/hardware.h"
static __inline int TOSH_READ_CC_CCA_PIN(void)
#line 147
{
#line 147
  return (* (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x10 + 0x20) & (1 << 6)) != 0;
}

static inline   
# 158 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/micaz/HPLCC2420InterruptM.nc"
result_t HPLCC2420InterruptM$CCA$startWait(bool low_to_high)
#line 158
{
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 159
    HPLCC2420InterruptM$CCAWaitForState = low_to_high;
#line 159
    __nesc_atomic_end(__nesc_atomic); }
  HPLCC2420InterruptM$CCALastState = TOSH_READ_CC_CCA_PIN();
  return HPLCC2420InterruptM$CCATimer$start(TIMER_ONE_SHOT, 1);
}

# 43 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/CC2420Radio/HPLCC2420Interrupt.nc"
inline static   result_t CC2420ControlM$CCA$startWait(bool arg_0xa7917f8){
#line 43
  unsigned char result;
#line 43

#line 43
  result = HPLCC2420InterruptM$CCA$startWait(arg_0xa7917f8);
#line 43

#line 43
  return result;
#line 43
}
#line 43
# 54 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/CC2420Radio/HPLCC2420.nc"
inline static   uint8_t CC2420ControlM$HPLChipcon$write(uint8_t arg_0xa769130, uint16_t arg_0xa769280){
#line 54
  unsigned char result;
#line 54

#line 54
  result = HPLCC2420M$HPLCC2420$write(arg_0xa769130, arg_0xa769280);
#line 54

#line 54
  return result;
#line 54
}
#line 54
static inline   
# 368 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/CC2420Radio/CC2420ControlM.nc"
result_t CC2420ControlM$CC2420Control$OscillatorOn(void)
#line 368
{
  uint16_t i;
  uint8_t status;

  i = 0;
#line 384
  CC2420ControlM$HPLChipcon$write(0x1D, 24);


  CC2420ControlM$CCA$startWait(TRUE);


  status = CC2420ControlM$HPLChipcon$cmd(0x01);

  return SUCCESS;
}

static inline 
# 150 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/avrmote/avrhardware.h"
void TOSH_wait(void)
{
   __asm volatile ("nop");
   __asm volatile ("nop");}

# 141 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/micaz/hardware.h"
static __inline void TOSH_SET_CC_RSTN_PIN(void)
#line 141
{
#line 141
  * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x1B + 0x20) |= 1 << 6;
}

#line 141
static __inline void TOSH_CLR_CC_RSTN_PIN(void)
#line 141
{
#line 141
  * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x1B + 0x20) &= ~(1 << 6);
}

#line 142
static __inline void TOSH_SET_CC_VREN_PIN(void)
#line 142
{
#line 142
  * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x1B + 0x20) |= 1 << 5;
}

static inline   
# 400 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/CC2420Radio/CC2420ControlM.nc"
result_t CC2420ControlM$CC2420Control$VREFOn(void)
#line 400
{
  TOSH_SET_CC_VREN_PIN();

  TOSH_uwait(600);
  return SUCCESS;
}

static inline   
# 129 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/micaz/HPLTimer1M.nc"
result_t HPLTimer1M$Timer1$setRate(uint16_t interval, char scale)
#line 129
{


  scale &= 0x7;
  scale |= 0x8;
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 134
    {
      * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x2F + 0x20) = 0;
      * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x37 + 0x20) &= ~(1 << 4);
      * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x37 + 0x20) &= ~(1 << 2);
      * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x37 + 0x20) &= ~(1 << 5);
      * (volatile unsigned int *)(unsigned int )& * (volatile unsigned char *)(0x2C + 0x20) = 0;
      * (volatile unsigned int *)(unsigned int )& * (volatile unsigned char *)(0x2A + 0x20) = interval;
      * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x36 + 0x20) |= 1 << 4;

      * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x2E + 0x20) = scale;
    }
#line 144
    __nesc_atomic_end(__nesc_atomic); }
  return SUCCESS;
}

static inline  
#line 55
result_t HPLTimer1M$StdControl$start(void)
#line 55
{
  uint16_t mi;
  uint8_t ms;

#line 58
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 58
    {
      mi = HPLTimer1M$minterval;
      ms = HPLTimer1M$mscale;
    }
#line 61
    __nesc_atomic_end(__nesc_atomic); }
  HPLTimer1M$Timer1$setRate(mi, ms);
  return SUCCESS;
}

static inline  
# 95 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/micaz/HPLCC2420M.nc"
result_t HPLCC2420M$StdControl$start(void)
#line 95
{
#line 95
  return SUCCESS;
}

# 70 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/StdControl.nc"
inline static  result_t CC2420ControlM$HPLChipconControl$start(void){
#line 70
  unsigned char result;
#line 70

#line 70
  result = HPLCC2420M$StdControl$start();
#line 70
  result = rcombine(result, HPLTimer1M$StdControl$start());
#line 70

#line 70
  return result;
#line 70
}
#line 70
static inline  
# 227 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/CC2420Radio/CC2420ControlM.nc"
result_t CC2420ControlM$SplitControl$start(void)
#line 227
{
  result_t status;
  uint8_t _state = FALSE;

  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 231
    {
      if (CC2420ControlM$state == CC2420ControlM$INIT_STATE_DONE) {
          CC2420ControlM$state = CC2420ControlM$START_STATE;
          _state = TRUE;
        }
    }
#line 236
    __nesc_atomic_end(__nesc_atomic); }
  if (!_state) {
    return FAIL;
    }
  CC2420ControlM$HPLChipconControl$start();

  CC2420ControlM$CC2420Control$VREFOn();

  TOSH_CLR_CC_RSTN_PIN();
  TOSH_wait();
  TOSH_SET_CC_RSTN_PIN();
  TOSH_wait();


  status = CC2420ControlM$CC2420Control$OscillatorOn();

  return status;
}

# 77 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/SplitControl.nc"
inline static  result_t CC2420RadioM$CC2420SplitControl$start(void){
#line 77
  unsigned char result;
#line 77

#line 77
  result = CC2420ControlM$SplitControl$start();
#line 77

#line 77
  return result;
#line 77
}
#line 77
static inline  
# 28 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/micaz/TimerJiffyAsyncM.nc"
result_t TimerJiffyAsyncM$StdControl$start(void)
{
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 30
    TimerJiffyAsyncM$bSet = FALSE;
#line 30
    __nesc_atomic_end(__nesc_atomic); }
  return SUCCESS;
}

# 70 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/StdControl.nc"
inline static  result_t CC2420RadioM$TimerControl$start(void){
#line 70
  unsigned char result;
#line 70

#line 70
  result = TimerJiffyAsyncM$StdControl$start();
#line 70

#line 70
  return result;
#line 70
}
#line 70
static inline  
# 277 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/CC2420Radio/CC2420RadioM.nc"
result_t CC2420RadioM$SplitControl$start(void)
#line 277
{
  uint8_t chkstateRadio;

  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 280
    chkstateRadio = CC2420RadioM$stateRadio;
#line 280
    __nesc_atomic_end(__nesc_atomic); }

  if (chkstateRadio == CC2420RadioM$DISABLED_STATE) {
      { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 283
        {
          CC2420RadioM$stateRadio = CC2420RadioM$WARMUP_STATE;
          CC2420RadioM$countRetry = 0;
          CC2420RadioM$rxbufptr->length = 0;
        }
#line 287
        __nesc_atomic_end(__nesc_atomic); }
      CC2420RadioM$TimerControl$start();
      return CC2420RadioM$CC2420SplitControl$start();
    }
  return FAIL;
}

static inline  
#line 239
void CC2420RadioM$startRadio(void)
#line 239
{
  result_t success = FAIL;

#line 241
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 241
    {
      if (CC2420RadioM$stateRadio == CC2420RadioM$DISABLED_STATE_STARTTASK) {
          CC2420RadioM$stateRadio = CC2420RadioM$DISABLED_STATE;
          success = SUCCESS;
        }
    }
#line 246
    __nesc_atomic_end(__nesc_atomic); }

  if (success == SUCCESS) {
    CC2420RadioM$SplitControl$start();
    }
}

static inline  result_t CC2420RadioM$StdControl$start(void)
#line 253
{







  result_t success = FAIL;

  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 263
    {
      if (CC2420RadioM$stateRadio == CC2420RadioM$DISABLED_STATE) {

          if (TOS_post(CC2420RadioM$startRadio)) {
              success = SUCCESS;
              CC2420RadioM$stateRadio = CC2420RadioM$DISABLED_STATE_STARTTASK;
            }
        }
    }
#line 271
    __nesc_atomic_end(__nesc_atomic); }

  return success;
}

# 70 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/StdControl.nc"
inline static  result_t AMStandard$RadioControl$start(void){
#line 70
  unsigned char result;
#line 70

#line 70
  result = CC2420RadioM$StdControl$start();
#line 70

#line 70
  return result;
#line 70
}
#line 70
# 59 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/Timer.nc"
inline static  result_t AMStandard$ActivityTimer$start(char arg_0xa344320, uint32_t arg_0xa344478){
#line 59
  unsigned char result;
#line 59

#line 59
  result = TimerM$Timer$start(4, arg_0xa344320, arg_0xa344478);
#line 59

#line 59
  return result;
#line 59
}
#line 59
# 41 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/PowerManagement.nc"
inline static   uint8_t AMStandard$PowerManagement$adjustPower(void){
#line 41
  unsigned char result;
#line 41

#line 41
  result = HPLPowerManagementM$PowerManagement$adjustPower();
#line 41

#line 41
  return result;
#line 41
}
#line 41
static inline 
# 133 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/system/tos.h"
result_t rcombine4(result_t r1, result_t r2, result_t r3, 
result_t r4)
{
  return rcombine(r1, rcombine(r2, rcombine(r3, r4)));
}

# 172 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/avrmote/avrhardware.h"
__inline void  __nesc_atomic_end(__nesc_atomic_t oldSreg)
{
  * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x3F + 0x20) = oldSreg;
}

static 

__inline void __nesc_atomic_sleep(void)
{

   __asm volatile ("sei");
   __asm volatile ("sleep");
  TOSH_wait();
}

#line 165
__inline __nesc_atomic_t  __nesc_atomic_start(void )
{
  __nesc_atomic_t result = * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x3F + 0x20);

#line 168
   __asm volatile ("cli");
  return result;
}

static inline 
# 136 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/system/sched.c"
bool TOSH_run_next_task(void)
{
  __nesc_atomic_t fInterruptFlags;
  uint8_t old_full;
  void (*func)(void );

  fInterruptFlags = __nesc_atomic_start();
  old_full = TOSH_sched_full;
  func = TOSH_queue[old_full].tp;
  if (func == (void *)0) 
    {
      __nesc_atomic_sleep();
      return 0;
    }

  TOSH_queue[old_full].tp = (void *)0;
  TOSH_sched_full = (old_full + 1) & TOSH_TASK_BITMASK;
  __nesc_atomic_end(fInterruptFlags);
  func();

  return 1;
}

static inline void TOSH_run_task(void)
#line 159
{
  for (; ; ) 
    TOSH_run_next_task();
}

static inline   
# 97 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/mica/HPLClock.nc"
uint8_t HPLClock$Clock$getInterval(void)
#line 97
{
  return * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x31 + 0x20);
}

# 121 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/Clock.nc"
inline static   uint8_t TimerM$Clock$getInterval(void){
#line 121
  unsigned char result;
#line 121

#line 121
  result = HPLClock$Clock$getInterval();
#line 121

#line 121
  return result;
#line 121
}
#line 121
# 41 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/PowerManagement.nc"
inline static   uint8_t TimerM$PowerManagement$adjustPower(void){
#line 41
  unsigned char result;
#line 41

#line 41
  result = HPLPowerManagementM$PowerManagement$adjustPower();
#line 41

#line 41
  return result;
#line 41
}
#line 41
static inline   
# 87 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/mica/HPLClock.nc"
void HPLClock$Clock$setInterval(uint8_t value)
#line 87
{
  * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x31 + 0x20) = value;
}

# 105 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/Clock.nc"
inline static   void TimerM$Clock$setInterval(uint8_t arg_0xa3734e8){
#line 105
  HPLClock$Clock$setInterval(arg_0xa3734e8);
#line 105
}
#line 105
static inline   
# 134 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/mica/HPLClock.nc"
uint8_t HPLClock$Clock$readCounter(void)
#line 134
{
  return * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x32 + 0x20);
}

# 153 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/Clock.nc"
inline static   uint8_t TimerM$Clock$readCounter(void){
#line 153
  unsigned char result;
#line 153

#line 153
  result = HPLClock$Clock$readCounter();
#line 153

#line 153
  return result;
#line 153
}
#line 153
# 129 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/system/TimerM.nc"
static void TimerM$adjustInterval(void)
#line 129
{
  uint8_t i;
#line 130
  uint8_t val = TimerM$maxTimerInterval;

#line 131
  if (TimerM$mState) {
      for (i = 0; i < NUM_TIMERS; i++) {
          if (TimerM$mState & (0x1L << i) && TimerM$mTimerList[i].ticksLeft < val) {
              val = TimerM$mTimerList[i].ticksLeft;
            }
        }
#line 148
      { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 148
        {
          i = TimerM$Clock$readCounter() + 3;
          if (val < i) {
              val = i;
            }
          TimerM$mInterval = val;
          TimerM$Clock$setInterval(TimerM$mInterval);
          TimerM$setIntervalFlag = 0;
        }
#line 156
        __nesc_atomic_end(__nesc_atomic); }
    }
  else {
      { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 159
        {
          TimerM$mInterval = TimerM$maxTimerInterval;
          TimerM$Clock$setInterval(TimerM$mInterval);
          TimerM$setIntervalFlag = 0;
        }
#line 163
        __nesc_atomic_end(__nesc_atomic); }
    }
  TimerM$PowerManagement$adjustPower();
}

static inline 
#line 186
void TimerM$enqueue(uint8_t value)
#line 186
{
  if (TimerM$queue_tail == NUM_TIMERS - 1) {
    TimerM$queue_tail = -1;
    }
#line 189
  TimerM$queue_tail++;
  TimerM$queue_size++;
  TimerM$queue[(uint8_t )TimerM$queue_tail] = value;
}

# 118 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/micaz/hardware.h"
static __inline void TOSH_CLR_YELLOW_LED_PIN(void)
#line 118
{
#line 118
  * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x1B + 0x20) &= ~(1 << 0);
}

static inline   
# 130 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/system/LedsC.nc"
result_t LedsC$Leds$yellowOn(void)
#line 130
{
  {
  }
#line 131
  ;
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 132
    {
      TOSH_CLR_YELLOW_LED_PIN();
      LedsC$ledsOn |= LedsC$YELLOW_BIT;
    }
#line 135
    __nesc_atomic_end(__nesc_atomic); }
  return SUCCESS;
}

# 114 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/Leds.nc"
inline static   result_t BlinkM$Leds$yellowOn(void){
#line 114
  unsigned char result;
#line 114

#line 114
  result = LedsC$Leds$yellowOn();
#line 114

#line 114
  return result;
#line 114
}
#line 114
# 117 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/micaz/hardware.h"
static __inline void TOSH_CLR_GREEN_LED_PIN(void)
#line 117
{
#line 117
  * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x1B + 0x20) &= ~(1 << 1);
}

static inline   
# 101 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/system/LedsC.nc"
result_t LedsC$Leds$greenOn(void)
#line 101
{
  {
  }
#line 102
  ;
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 103
    {
      TOSH_CLR_GREEN_LED_PIN();
      LedsC$ledsOn |= LedsC$GREEN_BIT;
    }
#line 106
    __nesc_atomic_end(__nesc_atomic); }
  return SUCCESS;
}

# 89 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/Leds.nc"
inline static   result_t BlinkM$Leds$greenOn(void){
#line 89
  unsigned char result;
#line 89

#line 89
  result = LedsC$Leds$greenOn();
#line 89

#line 89
  return result;
#line 89
}
#line 89
# 116 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/micaz/hardware.h"
static __inline void TOSH_CLR_RED_LED_PIN(void)
#line 116
{
#line 116
  * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x1B + 0x20) &= ~(1 << 2);
}

static inline   
# 72 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/system/LedsC.nc"
result_t LedsC$Leds$redOn(void)
#line 72
{
  {
  }
#line 73
  ;
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 74
    {
      TOSH_CLR_RED_LED_PIN();
      LedsC$ledsOn |= LedsC$RED_BIT;
    }
#line 77
    __nesc_atomic_end(__nesc_atomic); }
  return SUCCESS;
}

# 64 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/Leds.nc"
inline static   result_t BlinkM$Leds$redOn(void){
#line 64
  unsigned char result;
#line 64

#line 64
  result = LedsC$Leds$redOn();
#line 64

#line 64
  return result;
#line 64
}
#line 64
static inline   
# 139 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/system/LedsC.nc"
result_t LedsC$Leds$yellowOff(void)
#line 139
{
  {
  }
#line 140
  ;
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 141
    {
      TOSH_SET_YELLOW_LED_PIN();
      LedsC$ledsOn &= ~LedsC$YELLOW_BIT;
    }
#line 144
    __nesc_atomic_end(__nesc_atomic); }
  return SUCCESS;
}

# 122 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/Leds.nc"
inline static   result_t BlinkM$Leds$yellowOff(void){
#line 122
  unsigned char result;
#line 122

#line 122
  result = LedsC$Leds$yellowOff();
#line 122

#line 122
  return result;
#line 122
}
#line 122
static inline   
# 110 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/system/LedsC.nc"
result_t LedsC$Leds$greenOff(void)
#line 110
{
  {
  }
#line 111
  ;
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 112
    {
      TOSH_SET_GREEN_LED_PIN();
      LedsC$ledsOn &= ~LedsC$GREEN_BIT;
    }
#line 115
    __nesc_atomic_end(__nesc_atomic); }
  return SUCCESS;
}

# 97 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/Leds.nc"
inline static   result_t BlinkM$Leds$greenOff(void){
#line 97
  unsigned char result;
#line 97

#line 97
  result = LedsC$Leds$greenOff();
#line 97

#line 97
  return result;
#line 97
}
#line 97
static inline   
# 81 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/system/LedsC.nc"
result_t LedsC$Leds$redOff(void)
#line 81
{
  {
  }
#line 82
  ;
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 83
    {
      TOSH_SET_RED_LED_PIN();
      LedsC$ledsOn &= ~LedsC$RED_BIT;
    }
#line 86
    __nesc_atomic_end(__nesc_atomic); }
  return SUCCESS;
}

# 72 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/Leds.nc"
inline static   result_t BlinkM$Leds$redOff(void){
#line 72
  unsigned char result;
#line 72

#line 72
  result = LedsC$Leds$redOff();
#line 72

#line 72
  return result;
#line 72
}
#line 72
static inline  
# 93 "BlinkM.nc"
result_t BlinkM$Timer$fired(void)
{
  BlinkM$Leds$redOff();
  BlinkM$Leds$greenOff();
  BlinkM$Leds$yellowOff();


  switch (BlinkM$i) 
    {
      case 1: 
        BlinkM$Leds$redOn();
      break;
      case 2: 
        BlinkM$Leds$greenOn();
      break;
      case 3: 
        BlinkM$Leds$yellowOn();
      break;
    }
  if (BlinkM$i < 3) {
    BlinkM$i++;
    }
  else {
#line 115
    BlinkM$i = 0;
    }








  return SUCCESS;
}

static inline   
# 83 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/system/NoLeds.nc"
result_t NoLeds$Leds$yellowOff(void)
#line 83
{
  return SUCCESS;
}

# 122 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/Leds.nc"
inline static   result_t DelugeM$Leds$yellowOff(void){
#line 122
  unsigned char result;
#line 122

#line 122
  result = NoLeds$Leds$yellowOff();
#line 122

#line 122
  return result;
#line 122
}
#line 122
static inline 
# 39 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/mica2/NetProg_platform.h"
void netprog_reboot(void)
#line 39
{
   __asm volatile ("in __tmp_reg__,__SREG__""\n\t""cli""\n\t""wdr""\n\t""out %0,%1""\n\t""out __SREG__,__tmp_reg__""\n\t""out %0,%2" :  : "I"((unsigned int )& * (volatile unsigned char *)(0x21 + 0x20) - 0x20), "r"(0x18), "r"((unsigned char )(1 | (1 << 3))) : "r0");
  while (1) ;
}

# 35 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/InternalFlash.nc"
inline static  result_t NetProgM$IFlash$write(void *arg_0xa4647d0, void *arg_0xa464928, uint16_t arg_0xa464a78){
#line 35
  unsigned char result;
#line 35

#line 35
  result = InternalFlashC$InternalFlash$write(arg_0xa4647d0, arg_0xa464928, arg_0xa464a78);
#line 35

#line 35
  return result;
#line 35
}
#line 35
static inline  
# 95 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/StorageManagerM.nc"
uint32_t StorageManagerM$StorageRemap$physicalAddr(volume_t v, uint32_t volumeAddr)
#line 95
{
  return ((uint32_t )StorageManagerM$volumes[v].start << AT45_PAGE_SIZE_LOG2) + volumeAddr;
}

static inline   
# 242 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/DelugeStorageM.nc"
uint32_t DelugeStorageM$StorageRemap$default$physicalAddr(blockstorage_t blockId, uint32_t id)
#line 242
{
#line 242
  return STORAGE_INVALID_ADDR;
}

# 29 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/StorageRemap.nc"
inline static  uint32_t DelugeStorageM$StorageRemap$physicalAddr(blockstorage_t arg_0xa537660, uint32_t arg_0xa538488){
#line 29
  unsigned long result;
#line 29

#line 29
  switch (arg_0xa537660) {
#line 29
    case DELUGE_VOLUME_ID_0:
#line 29
      result = StorageManagerM$StorageRemap$physicalAddr(DELUGE_VOLUME_ID_0, arg_0xa538488);
#line 29
      break;
#line 29
    case DELUGE_VOLUME_ID_1:
#line 29
      result = StorageManagerM$StorageRemap$physicalAddr(DELUGE_VOLUME_ID_1, arg_0xa538488);
#line 29
      break;
#line 29
    case DELUGE_VOLUME_ID_2:
#line 29
      result = StorageManagerM$StorageRemap$physicalAddr(DELUGE_VOLUME_ID_2, arg_0xa538488);
#line 29
      break;
#line 29
    default:
#line 29
      result = DelugeStorageM$StorageRemap$default$physicalAddr(arg_0xa537660, arg_0xa538488);
#line 29
    }
#line 29

#line 29
  return result;
#line 29
}
#line 29
static inline  
# 123 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/DelugeStorageM.nc"
uint32_t DelugeStorageM$DelugeStorage$imgNum2Addr(imgnum_t imgNum)
#line 123
{
  if (imgNum == DELUGE_GOLDEN_IMAGE_NUM) {
    return TOSBOOT_GOLDEN_IMG_ADDR;
    }
#line 126
  return DelugeStorageM$StorageRemap$physicalAddr(DELUGE_IMAGES[imgNum].imageNum, 0);
}

# 36 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/DelugeStorage.nc"
inline static  uint32_t NetProgM$Storage$imgNum2Addr(imgnum_t arg_0xa4d5f48){
#line 36
  unsigned long result;
#line 36

#line 36
  result = DelugeStorageM$DelugeStorage$imgNum2Addr(arg_0xa4d5f48);
#line 36

#line 36
  return result;
#line 36
}
#line 36
static inline  
# 110 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/NetProgM.nc"
result_t NetProgM$NetProg$programImgAndReboot(imgnum_t newImgNum)
#line 110
{


  tosboot_args_t args;

  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 115
    {
      NetProgM$writeTOSinfo();

      args.imageAddr = NetProgM$Storage$imgNum2Addr(newImgNum);
      args.gestureCount = 0xff;
      args.noReprogram = FALSE;
      NetProgM$IFlash$write((uint8_t *)TOSBOOT_ARGS_ADDR, &args, sizeof args);


      netprog_reboot();
    }
#line 125
    __nesc_atomic_end(__nesc_atomic); }



  return FAIL;
}

# 54 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/NetProg.nc"
inline static  result_t DelugeM$NetProg$programImgAndReboot(uint8_t arg_0xa45e840){
#line 54
  unsigned char result;
#line 54

#line 54
  result = NetProgM$NetProg$programImgAndReboot(arg_0xa45e840);
#line 54

#line 54
  return result;
#line 54
}
#line 54
static inline   
# 79 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/system/NoLeds.nc"
result_t NoLeds$Leds$yellowOn(void)
#line 79
{
  return SUCCESS;
}

# 114 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/Leds.nc"
inline static   result_t DelugeM$Leds$yellowOn(void){
#line 114
  unsigned char result;
#line 114

#line 114
  result = NoLeds$Leds$yellowOn();
#line 114

#line 114
  return result;
#line 114
}
#line 114
static inline  
# 114 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/DelugePageTransferM.nc"
bool DelugePageTransferM$PageTransfer$isTransferring(void)
#line 114
{
  return DelugePageTransferM$state != DelugePageTransferM$S_IDLE && DelugePageTransferM$state != DelugePageTransferM$S_DISABLED;
}

# 33 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/DelugePageTransfer.nc"
inline static  bool DelugeM$PageTransfer$isTransferring(void){
#line 33
  unsigned char result;
#line 33

#line 33
  result = DelugePageTransferM$PageTransfer$isTransferring();
#line 33

#line 33
  return result;
#line 33
}
#line 33
static inline 
# 101 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/DelugeM.nc"
void DelugeM$updateTimers(int minTimer)
#line 101
{
  int i;

#line 103
  for (i = 0; i < DelugeM$DELUGE_NUM_TIMERS; i++) {
      if (DelugeM$advTimers[i].timer - 2 >= DelugeM$advTimers[minTimer].timer) {
        DelugeM$advTimers[i].timer -= DelugeM$advTimers[minTimer].timer;
        }
    }
}

static inline  
#line 245
result_t DelugeM$Timer$fired(void)
#line 245
{

  int minTimer = DelugeM$findMinTimer();

  DelugeM$updateTimers(minTimer);

  if (! DelugeM$advTimers[minTimer].overheard) {
    DelugeM$sendAdvMsg(minTimer, TOS_BCAST_ADDR);
    }
  if (DelugeM$PageTransfer$isTransferring()) {
    DelugeM$advTimers[minTimer].newAdvs = DELUGE_NUM_NEWDATA_ADVS_REQUIRED;
    }
  else {
#line 256
    if (DelugeM$advTimers[minTimer].newAdvs > 0) {
      DelugeM$advTimers[minTimer].newAdvs--;
      }
    }
#line 259
  if (DelugeM$rebootDelay > 0) {
      DelugeM$Leds$yellowOn();
      if (! --DelugeM$rebootDelay) {

          DelugeM$NetProg$programImgAndReboot(DelugeM$nodeDesc.imgNum);
        }
    }
  else {
      DelugeM$Leds$yellowOff();

      if (
#line 268
      DelugeM$advTimers[minTimer].newAdvs == 0
       && DelugeM$advTimers[minTimer].periodLog2 < DELUGE_MAX_ADV_PERIOD_LOG2) {
          DelugeM$advTimers[minTimer].periodLog2++;
        }
    }

  DelugeM$setupAdvTimer(minTimer);

  return SUCCESS;
}

static inline  
# 122 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/DelugeMetadataM.nc"
result_t DelugeMetadataM$Timer$fired(void)
#line 122
{
  DelugeMetadataM$execute();
  return SUCCESS;
}

static inline  
# 288 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/DelugePageTransferM.nc"
result_t DelugePageTransferM$Timer$fired(void)
#line 288
{
  DelugePageTransferM$setupReqMsg();
  DelugePageTransferM$setupDataMsg();
  return SUCCESS;
}

static inline  
# 151 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/system/AMStandard.nc"
result_t AMStandard$ActivityTimer$fired(void)
#line 151
{
  AMStandard$lastCount = AMStandard$counter;
  AMStandard$counter = 0;
  return SUCCESS;
}

static inline   
# 312 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/CC2420Radio/CC2420RadioM.nc"
result_t CC2420RadioM$SplitControl$default$startDone(void)
#line 312
{
  return SUCCESS;
}

# 85 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/SplitControl.nc"
inline static  result_t CC2420RadioM$SplitControl$startDone(void){
#line 85
  unsigned char result;
#line 85

#line 85
  result = CC2420RadioM$SplitControl$default$startDone();
#line 85

#line 85
  return result;
#line 85
}
#line 85
static inline   
# 252 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/micaz/HPLTimer1M.nc"
void HPLTimer1M$CaptureT1$enableEvents(void)
#line 252
{

  * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x2E + 0x20) &= ~(1 << 4);
  * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x2E + 0x20) &= ~(1 << 3);
  * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x37 + 0x20) |= 1 << 5;
}

# 62 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/micaz/TimerCapture.nc"
inline static   void HPLCC2420InterruptM$SFDCapture$enableEvents(void){
#line 62
  HPLTimer1M$CaptureT1$enableEvents();
#line 62
}
#line 62
static inline   
# 236 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/micaz/HPLTimer1M.nc"
void HPLTimer1M$CaptureT1$clearOverflow(void)
#line 236
{
  * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x36 + 0x20) |= 1 << 2;
  return;
}

# 52 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/micaz/TimerCapture.nc"
inline static   void HPLCC2420InterruptM$SFDCapture$clearOverflow(void){
#line 52
  HPLTimer1M$CaptureT1$clearOverflow();
#line 52
}
#line 52
#line 40
inline static   void HPLCC2420InterruptM$SFDCapture$setEdge(uint8_t arg_0xa83f938){
#line 40
  HPLTimer1M$CaptureT1$setEdge(arg_0xa83f938);
#line 40
}
#line 40
static inline   
# 262 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/micaz/HPLTimer1M.nc"
void HPLTimer1M$CaptureT1$disableEvents(void)
#line 262
{
  * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x37 + 0x20) &= ~(1 << 5);
  * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x36 + 0x20) |= 1 << 5;
}

# 63 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/micaz/TimerCapture.nc"
inline static   void HPLCC2420InterruptM$SFDCapture$disableEvents(void){
#line 63
  HPLTimer1M$CaptureT1$disableEvents();
#line 63
}
#line 63
static inline   
# 200 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/micaz/HPLCC2420InterruptM.nc"
result_t HPLCC2420InterruptM$SFD$enableCapture(bool low_to_high)
#line 200
{
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 201
    {

      HPLCC2420InterruptM$SFDCapture$disableEvents();
      HPLCC2420InterruptM$SFDCapture$setEdge(low_to_high);
      HPLCC2420InterruptM$SFDCapture$clearOverflow();
      HPLCC2420InterruptM$SFDCapture$enableEvents();
    }
#line 207
    __nesc_atomic_end(__nesc_atomic); }
  return SUCCESS;
}

# 43 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/CC2420Radio/HPLCC2420Capture.nc"
inline static   result_t CC2420RadioM$SFD$enableCapture(bool arg_0xa78d4e8){
#line 43
  unsigned char result;
#line 43

#line 43
  result = HPLCC2420InterruptM$SFD$enableCapture(arg_0xa78d4e8);
#line 43

#line 43
  return result;
#line 43
}
#line 43
static 
# 131 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/micaz/hardware.h"
void __inline CC2420_FIFOP_INT_MODE(bool LowToHigh)
#line 131
{
  * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x3A + 0x20) |= 1 << 5;
  if (LowToHigh) {
    * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x3A + 0x20) |= 1 << 4;
    }
  else {
#line 136
    * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x3A + 0x20) &= ~(1 << 4);
    }
}

static inline   
# 78 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/micaz/HPLCC2420InterruptM.nc"
result_t HPLCC2420InterruptM$FIFOP$startWait(bool low_to_high)
#line 78
{
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 79
    {
      CC2420_FIFOP_INT_MODE(low_to_high);
      * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x39 + 0x20) |= 1 << 6;
    }
#line 82
    __nesc_atomic_end(__nesc_atomic); }
  return SUCCESS;
}

# 43 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/CC2420Radio/HPLCC2420Interrupt.nc"
inline static   result_t CC2420RadioM$FIFOP$startWait(bool arg_0xa7917f8){
#line 43
  unsigned char result;
#line 43

#line 43
  result = HPLCC2420InterruptM$FIFOP$startWait(arg_0xa7917f8);
#line 43

#line 43
  return result;
#line 43
}
#line 43
static inline   
# 343 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/CC2420Radio/CC2420ControlM.nc"
result_t CC2420ControlM$CC2420Control$RxMode(void)
#line 343
{
  CC2420ControlM$HPLChipcon$cmd(0x03);
  return SUCCESS;
}

# 163 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/CC2420Radio/CC2420Control.nc"
inline static   result_t CC2420RadioM$CC2420Control$RxMode(void){
#line 163
  unsigned char result;
#line 163

#line 163
  result = CC2420ControlM$CC2420Control$RxMode();
#line 163

#line 163
  return result;
#line 163
}
#line 163
static inline  
# 294 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/CC2420Radio/CC2420RadioM.nc"
result_t CC2420RadioM$CC2420SplitControl$startDone(void)
#line 294
{
  uint8_t chkstateRadio;

  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 297
    chkstateRadio = CC2420RadioM$stateRadio;
#line 297
    __nesc_atomic_end(__nesc_atomic); }

  if (chkstateRadio == CC2420RadioM$WARMUP_STATE) {
      CC2420RadioM$CC2420Control$RxMode();

      CC2420RadioM$FIFOP$startWait(FALSE);

      CC2420RadioM$SFD$enableCapture(TRUE);

      { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 306
        CC2420RadioM$stateRadio = CC2420RadioM$IDLE_STATE;
#line 306
        __nesc_atomic_end(__nesc_atomic); }
    }
  CC2420RadioM$SplitControl$startDone();
  return SUCCESS;
}

# 85 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/SplitControl.nc"
inline static  result_t CC2420ControlM$SplitControl$startDone(void){
#line 85
  unsigned char result;
#line 85

#line 85
  result = CC2420RadioM$CC2420SplitControl$startDone();
#line 85

#line 85
  return result;
#line 85
}
#line 85
static inline  
# 286 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/CC2420Radio/CC2420ControlM.nc"
result_t CC2420ControlM$CC2420Control$TuneManual(uint16_t DesiredFreq)
#line 286
{
  int fsctrl;
  uint8_t status;

  fsctrl = DesiredFreq - 2048;
  CC2420ControlM$gCurrentParameters[CP_FSCTRL] = (CC2420ControlM$gCurrentParameters[CP_FSCTRL] & 0xfc00) | (fsctrl << 0);
  status = CC2420ControlM$HPLChipcon$write(0x18, CC2420ControlM$gCurrentParameters[CP_FSCTRL]);


  if (status & (1 << 6)) {
    CC2420ControlM$HPLChipcon$cmd(0x03);
    }
#line 297
  return SUCCESS;
}

static inline   
#line 441
result_t CC2420ControlM$HPLChipconRAM$writeDone(uint16_t addr, uint8_t length, uint8_t *buffer)
#line 441
{
  return SUCCESS;
}

# 49 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/CC2420Radio/HPLCC2420RAM.nc"
inline static   result_t HPLCC2420M$HPLCC2420RAM$writeDone(uint16_t arg_0xa7d8b70, uint8_t arg_0xa7d8cb8, uint8_t *arg_0xa7d8e18){
#line 49
  unsigned char result;
#line 49

#line 49
  result = CC2420ControlM$HPLChipconRAM$writeDone(arg_0xa7d8b70, arg_0xa7d8cb8, arg_0xa7d8e18);
#line 49

#line 49
  return result;
#line 49
}
#line 49
static inline  
# 197 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/micaz/HPLCC2420M.nc"
void HPLCC2420M$signalRAMWr(void)
#line 197
{
  HPLCC2420M$HPLCC2420RAM$writeDone(HPLCC2420M$ramaddr, HPLCC2420M$ramlen, HPLCC2420M$rambuf);
}

# 149 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/micaz/hardware.h"
static __inline void TOSH_CLR_CC_CS_PIN(void)
#line 149
{
#line 149
  * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x18 + 0x20) &= ~(1 << 0);
}

static inline   
# 208 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/micaz/HPLCC2420M.nc"
result_t HPLCC2420M$HPLCC2420RAM$write(uint16_t addr, uint8_t length, uint8_t *buffer)
#line 208
{
  uint8_t i = 0;
  uint8_t status;

  if (!HPLCC2420M$bSpiAvail) {
    return FALSE;
    }
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 215
    {
      HPLCC2420M$bSpiAvail = FALSE;
      HPLCC2420M$ramaddr = addr;
      HPLCC2420M$ramlen = length;
      HPLCC2420M$rambuf = buffer;
      TOSH_CLR_CC_CS_PIN();
      * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x0F + 0x20) = (HPLCC2420M$ramaddr & 0x7F) | 0x80;
      while (!(* (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x0E + 0x20) & 0x80)) {
        }
#line 222
      ;
      status = * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x0F + 0x20);
      * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x0F + 0x20) = (HPLCC2420M$ramaddr >> 1) & 0xC0;
      while (!(* (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x0E + 0x20) & 0x80)) {
        }
#line 225
      ;
      status = * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x0F + 0x20);

      for (i = 0; i < HPLCC2420M$ramlen; i++) {
          * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x0F + 0x20) = HPLCC2420M$rambuf[i];

          while (!(* (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x0E + 0x20) & 0x80)) {
            }
#line 231
          ;
        }
    }
#line 233
    __nesc_atomic_end(__nesc_atomic); }
  HPLCC2420M$bSpiAvail = TRUE;
  return TOS_post(HPLCC2420M$signalRAMWr);
}

# 47 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/CC2420Radio/HPLCC2420RAM.nc"
inline static   result_t CC2420ControlM$HPLChipconRAM$write(uint16_t arg_0xa7d8448, uint8_t arg_0xa7d8590, uint8_t *arg_0xa7d86f0){
#line 47
  unsigned char result;
#line 47

#line 47
  result = HPLCC2420M$HPLCC2420RAM$write(arg_0xa7d8448, arg_0xa7d8590, arg_0xa7d86f0);
#line 47

#line 47
  return result;
#line 47
}
#line 47
static inline  
# 432 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/CC2420Radio/CC2420ControlM.nc"
result_t CC2420ControlM$CC2420Control$setShortAddress(uint16_t addr)
#line 432
{
  addr = toLSB16(addr);
  return CC2420ControlM$HPLChipconRAM$write(0x16A, 2, (uint8_t *)&addr);
}

# 61 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/CC2420Radio/HPLCC2420.nc"
inline static   uint16_t CC2420ControlM$HPLChipcon$read(uint8_t arg_0xa769728){
#line 61
  unsigned int result;
#line 61

#line 61
  result = HPLCC2420M$HPLCC2420$read(arg_0xa769728);
#line 61

#line 61
  return result;
#line 61
}
#line 61
static inline 
# 80 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/CC2420Radio/CC2420ControlM.nc"
bool CC2420ControlM$SetRegs(void)
#line 80
{
  uint16_t data;

  CC2420ControlM$HPLChipcon$write(0x10, CC2420ControlM$gCurrentParameters[CP_MAIN]);
  CC2420ControlM$HPLChipcon$write(0x11, CC2420ControlM$gCurrentParameters[CP_MDMCTRL0]);
  data = CC2420ControlM$HPLChipcon$read(0x11);
  if (data != CC2420ControlM$gCurrentParameters[CP_MDMCTRL0]) {
#line 86
    return FALSE;
    }
  CC2420ControlM$HPLChipcon$write(0x12, CC2420ControlM$gCurrentParameters[CP_MDMCTRL1]);
  CC2420ControlM$HPLChipcon$write(0x13, CC2420ControlM$gCurrentParameters[CP_RSSI]);
  CC2420ControlM$HPLChipcon$write(0x14, CC2420ControlM$gCurrentParameters[CP_SYNCWORD]);
  CC2420ControlM$HPLChipcon$write(0x15, CC2420ControlM$gCurrentParameters[CP_TXCTRL]);
  CC2420ControlM$HPLChipcon$write(0x16, CC2420ControlM$gCurrentParameters[CP_RXCTRL0]);
  CC2420ControlM$HPLChipcon$write(0x17, CC2420ControlM$gCurrentParameters[CP_RXCTRL1]);
  CC2420ControlM$HPLChipcon$write(0x18, CC2420ControlM$gCurrentParameters[CP_FSCTRL]);

  CC2420ControlM$HPLChipcon$write(0x19, CC2420ControlM$gCurrentParameters[CP_SECCTRL0]);
  CC2420ControlM$HPLChipcon$write(0x1A, CC2420ControlM$gCurrentParameters[CP_SECCTRL1]);
  CC2420ControlM$HPLChipcon$write(0x1C, CC2420ControlM$gCurrentParameters[CP_IOCFG0]);
  CC2420ControlM$HPLChipcon$write(0x1D, CC2420ControlM$gCurrentParameters[CP_IOCFG1]);

  CC2420ControlM$HPLChipcon$cmd(0x09);
  CC2420ControlM$HPLChipcon$cmd(0x08);

  return TRUE;
}

static inline  








void CC2420ControlM$PostOscillatorOn(void)
#line 116
{

  CC2420ControlM$SetRegs();
  CC2420ControlM$CC2420Control$setShortAddress(TOS_LOCAL_ADDRESS);
  CC2420ControlM$CC2420Control$TuneManual(((CC2420ControlM$gCurrentParameters[CP_FSCTRL] << 0) & 0x1FF) + 2048);
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 121
    CC2420ControlM$state = CC2420ControlM$START_STATE_DONE;
#line 121
    __nesc_atomic_end(__nesc_atomic); }
  CC2420ControlM$SplitControl$startDone();
}

static inline   
#line 445
result_t CC2420ControlM$CCA$fired(void)
#line 445
{

  CC2420ControlM$HPLChipcon$write(0x1D, 0);
  TOS_post(CC2420ControlM$PostOscillatorOn);
  return FAIL;
}

# 51 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/CC2420Radio/HPLCC2420Interrupt.nc"
inline static   result_t HPLCC2420InterruptM$CCA$fired(void){
#line 51
  unsigned char result;
#line 51

#line 51
  result = CC2420ControlM$CCA$fired();
#line 51

#line 51
  return result;
#line 51
}
#line 51
static inline  
# 175 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/micaz/HPLCC2420InterruptM.nc"
result_t HPLCC2420InterruptM$CCATimer$fired(void)
#line 175
{
  uint8_t CCAState;
  result_t val = SUCCESS;

  CCAState = TOSH_READ_CC_CCA_PIN();

  if (HPLCC2420InterruptM$CCALastState != HPLCC2420InterruptM$CCAWaitForState && CCAState == HPLCC2420InterruptM$CCAWaitForState) {
      val = HPLCC2420InterruptM$CCA$fired();
      if (val == FAIL) {
        return SUCCESS;
        }
    }
  HPLCC2420InterruptM$CCALastState = CCAState;
  return HPLCC2420InterruptM$CCATimer$start(TIMER_ONE_SHOT, 1);
}

# 59 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/Timer.nc"
inline static  result_t HPLCC2420InterruptM$FIFOTimer$start(char arg_0xa344320, uint32_t arg_0xa344478){
#line 59
  unsigned char result;
#line 59

#line 59
  result = TimerM$Timer$start(5, arg_0xa344320, arg_0xa344478);
#line 59

#line 59
  return result;
#line 59
}
#line 59
static inline    
# 150 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/micaz/HPLCC2420InterruptM.nc"
result_t HPLCC2420InterruptM$FIFO$default$fired(void)
#line 150
{
#line 150
  return FAIL;
}

# 51 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/CC2420Radio/HPLCC2420Interrupt.nc"
inline static   result_t HPLCC2420InterruptM$FIFO$fired(void){
#line 51
  unsigned char result;
#line 51

#line 51
  result = HPLCC2420InterruptM$FIFO$default$fired();
#line 51

#line 51
  return result;
#line 51
}
#line 51
# 150 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/micaz/hardware.h"
static __inline int TOSH_READ_CC_FIFO_PIN(void)
#line 150
{
#line 150
  return (* (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x16 + 0x20) & (1 << 7)) != 0;
}

static inline  
# 125 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/micaz/HPLCC2420InterruptM.nc"
result_t HPLCC2420InterruptM$FIFOTimer$fired(void)
#line 125
{
  uint8_t FIFOState;
  result_t val = SUCCESS;

  FIFOState = TOSH_READ_CC_FIFO_PIN();
  if (HPLCC2420InterruptM$FIFOLastState != HPLCC2420InterruptM$FIFOWaitForState && FIFOState == HPLCC2420InterruptM$FIFOWaitForState) {

      val = HPLCC2420InterruptM$FIFO$fired();
      if (val == FAIL) {
        return SUCCESS;
        }
    }
  HPLCC2420InterruptM$FIFOLastState = FIFOState;
  return HPLCC2420InterruptM$FIFOTimer$start(TIMER_ONE_SHOT, 1);
}

# 68 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/Timer.nc"
inline static  result_t TestSenseM$initTimer$stop(void){
#line 68
  unsigned char result;
#line 68

#line 68
  result = TimerM$Timer$stop(9);
#line 68

#line 68
  return result;
#line 68
}
#line 68
# 52 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/ADC.nc"
inline static   result_t TestSenseM$VolADC$getData(void){
#line 52
  unsigned char result;
#line 52

#line 52
  result = VoltageM$Voltage$getData();
#line 52

#line 52
  return result;
#line 52
}
#line 52
# 70 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/StdControl.nc"
inline static  result_t TestSenseM$VolControl$start(void){
#line 70
  unsigned char result;
#line 70

#line 70
  result = VoltageM$StdControl$start();
#line 70

#line 70
  return result;
#line 70
}
#line 70
static inline  
# 119 "TestSenseM.nc"
result_t TestSenseM$initTimer$fired(void)
#line 119
{
  TestSenseM$VolControl$start();
  TestSenseM$VolADC$getData();
  TestSenseM$initTimer$stop();
}

static inline   
# 337 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/sensorboards/micasb/PhotoTempM.nc"
result_t PhotoTempM$ExternalTempADC$getData(void)
#line 337
{
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 338
    {
      PhotoTempM$tempSensor = PhotoTempM$stateReadOnce;
    }
#line 340
    __nesc_atomic_end(__nesc_atomic); }
#line 340
  ;
  TOS_post(PhotoTempM$getSample);
  return SUCCESS;
}

# 52 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/ADC.nc"
inline static   result_t TestSenseM$TempADC$getData(void){
#line 52
  unsigned char result;
#line 52

#line 52
  result = PhotoTempM$ExternalTempADC$getData();
#line 52

#line 52
  return result;
#line 52
}
#line 52
static inline  
# 258 "TestSenseM.nc"
result_t TestSenseM$TempTimer$fired(void)
#line 258
{

  TestSenseM$TempADC$getData();
  return SUCCESS;
}

# 68 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/Timer.nc"
inline static  result_t TestSenseM$Timer$stop(void){
#line 68
  unsigned char result;
#line 68

#line 68
  result = TimerM$Timer$stop(7);
#line 68

#line 68
  return result;
#line 68
}
#line 68
# 59 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/Timer.nc"
inline static  result_t TestSenseM$TempTimer$start(char arg_0xa344320, uint32_t arg_0xa344478){
#line 59
  unsigned char result;
#line 59

#line 59
  result = TimerM$Timer$start(8, arg_0xa344320, arg_0xa344478);
#line 59

#line 59
  return result;
#line 59
}
#line 59
static inline  
# 168 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/sensorboards/micasb/PhotoTempM.nc"
result_t PhotoTempM$TempStdControl$start(void)
#line 168
{
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 169
    {
      PhotoTempM$tempSensor = PhotoTempM$stateIdle;
    }
#line 171
    __nesc_atomic_end(__nesc_atomic); }
#line 171
  ;
  return SUCCESS;
}

# 70 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/StdControl.nc"
inline static  result_t TestSenseM$TempControl$start(void){
#line 70
  unsigned char result;
#line 70

#line 70
  result = PhotoTempM$TempStdControl$start();
#line 70

#line 70
  return result;
#line 70
}
#line 70
static inline   
# 329 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/sensorboards/micasb/PhotoTempM.nc"
result_t PhotoTempM$ExternalPhotoADC$getData(void)
#line 329
{
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 330
    {
      PhotoTempM$photoSensor = PhotoTempM$stateReadOnce;
    }
#line 332
    __nesc_atomic_end(__nesc_atomic); }
#line 332
  ;
  TOS_post(PhotoTempM$getSample);
  return SUCCESS;
}

# 52 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/ADC.nc"
inline static   result_t TestSenseM$LightADC$getData(void){
#line 52
  unsigned char result;
#line 52

#line 52
  result = PhotoTempM$ExternalPhotoADC$getData();
#line 52

#line 52
  return result;
#line 52
}
#line 52
static inline  
# 144 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/sensorboards/micasb/PhotoTempM.nc"
result_t PhotoTempM$PhotoStdControl$start(void)
#line 144
{
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 145
    {
      PhotoTempM$photoSensor = PhotoTempM$stateIdle;
    }
#line 147
    __nesc_atomic_end(__nesc_atomic); }
#line 147
  ;
  return SUCCESS;
}

# 70 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/StdControl.nc"
inline static  result_t TestSenseM$SensorControl$start(void){
#line 70
  unsigned char result;
#line 70

#line 70
  result = PhotoTempM$PhotoStdControl$start();
#line 70

#line 70
  return result;
#line 70
}
#line 70
static inline  
# 240 "TestSenseM.nc"
result_t TestSenseM$Timer$fired(void)
#line 240
{

  if (TestSenseM$type == 1) 
    {
      TestSenseM$SensorControl$start();
      TestSenseM$LightADC$getData();

      TestSenseM$TempControl$start();
      TestSenseM$TempTimer$start(TIMER_ONE_SHOT, 10);
    }
  else 
    {
      TestSenseM$Timer$stop();
    }
  return SUCCESS;
}

# 77 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/HPLADC.nc"
inline static   result_t ADCM$HPLADC$samplePort(uint8_t arg_0xa9d17e0){
#line 77
  unsigned char result;
#line 77

#line 77
  result = HPLADCC$ADC$samplePort(arg_0xa9d17e0);
#line 77

#line 77
  return result;
#line 77
}
#line 77
static 
# 132 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/system/ADCM.nc"
__inline result_t ADCM$startGet(uint8_t newState, uint8_t port)
#line 132
{
  uint16_t PortMask;
#line 133
  uint16_t oldReqVector;
  result_t Result = SUCCESS;

  if (port > TOSH_ADC_PORTMAPSIZE) {
      return FAIL;
    }

  PortMask = 1 << port;

  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 142
    {
      if ((PortMask & ADCM$ReqVector) != 0) {

          Result = FAIL;
        }
      else {
          oldReqVector = ADCM$ReqVector;
          ADCM$ReqVector |= PortMask;
          if (newState == ADCM$CONTINUOUS_CONVERSION) {
              ADCM$ContReqMask |= PortMask;
            }
          if (oldReqVector == 0) {

              ADCM$ReqPort = port;
              Result = ADCM$HPLADC$samplePort(port);
            }
        }
    }
#line 159
    __nesc_atomic_end(__nesc_atomic); }


  return Result;
}

static inline   result_t ADCM$ADC$getData(uint8_t port)
#line 165
{
  return ADCM$startGet(ADCM$SINGLE_CONVERSION, port);
}

# 52 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/ADC.nc"
inline static   result_t PhotoTempM$InternalTempADC$getData(void){
#line 52
  unsigned char result;
#line 52

#line 52
  result = ADCM$ADC$getData(TOS_ADC_TEMP_PORT);
#line 52

#line 52
  return result;
#line 52
}
#line 52
# 52 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/ADC.nc"
inline static   result_t PhotoTempM$InternalPhotoADC$getData(void){
#line 52
  unsigned char result;
#line 52

#line 52
  result = ADCM$ADC$getData(TOS_ADC_PHOTO_PORT);
#line 52

#line 52
  return result;
#line 52
}
#line 52
static inline  
# 291 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/sensorboards/micasb/PhotoTempM.nc"
result_t PhotoTempM$PhotoTempTimer$fired(void)
#line 291
{
  switch (PhotoTempM$hardwareStatus) {
      case PhotoTempM$sensorIdle: 
        case PhotoTempM$sensorTempReady: 
          case PhotoTempM$sensorPhotoReady: 

            break;
      case PhotoTempM$sensorPhotoStarting: 
        PhotoTempM$hardwareStatus = PhotoTempM$sensorPhotoReady;
      if (PhotoTempM$InternalPhotoADC$getData() == SUCCESS) {

          return SUCCESS;
        }
#line 303
      ;
      break;
      case PhotoTempM$sensorTempStarting: 
        PhotoTempM$hardwareStatus = PhotoTempM$sensorTempReady;
      if (PhotoTempM$InternalTempADC$getData() == SUCCESS) {

          return SUCCESS;
        }
#line 310
      ;
      break;
    }
#line 312
  ;

  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 314
    {
      PhotoTempM$waitingForSample = FALSE;
    }
#line 316
    __nesc_atomic_end(__nesc_atomic); }
#line 316
  ;
  TOS_post(PhotoTempM$getSample);
  return SUCCESS;
}

static inline   
# 182 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/system/TimerM.nc"
result_t TimerM$Timer$default$fired(uint8_t id)
#line 182
{
  return SUCCESS;
}

# 73 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/Timer.nc"
inline static  result_t TimerM$Timer$fired(uint8_t arg_0xa34ee80){
#line 73
  unsigned char result;
#line 73

#line 73
  switch (arg_0xa34ee80) {
#line 73
    case 0:
#line 73
      result = BlinkM$Timer$fired();
#line 73
      break;
#line 73
    case 1:
#line 73
      result = DelugeM$Timer$fired();
#line 73
      break;
#line 73
    case 2:
#line 73
      result = DelugeMetadataM$Timer$fired();
#line 73
      break;
#line 73
    case 3:
#line 73
      result = DelugePageTransferM$Timer$fired();
#line 73
      break;
#line 73
    case 4:
#line 73
      result = AMStandard$ActivityTimer$fired();
#line 73
      break;
#line 73
    case 5:
#line 73
      result = HPLCC2420InterruptM$FIFOTimer$fired();
#line 73
      break;
#line 73
    case 6:
#line 73
      result = HPLCC2420InterruptM$CCATimer$fired();
#line 73
      break;
#line 73
    case 7:
#line 73
      result = TestSenseM$Timer$fired();
#line 73
      break;
#line 73
    case 8:
#line 73
      result = TestSenseM$TempTimer$fired();
#line 73
      break;
#line 73
    case 9:
#line 73
      result = TestSenseM$initTimer$fired();
#line 73
      break;
#line 73
    case 10:
#line 73
      result = PhotoTempM$PhotoTempTimer$fired();
#line 73
      break;
#line 73
    default:
#line 73
      result = TimerM$Timer$default$fired(arg_0xa34ee80);
#line 73
    }
#line 73

#line 73
  return result;
#line 73
}
#line 73
static inline 
# 194 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/system/TimerM.nc"
uint8_t TimerM$dequeue(void)
#line 194
{
  if (TimerM$queue_size == 0) {
    return NUM_TIMERS;
    }
#line 197
  if (TimerM$queue_head == NUM_TIMERS - 1) {
    TimerM$queue_head = -1;
    }
#line 199
  TimerM$queue_head++;
  TimerM$queue_size--;
  return TimerM$queue[(uint8_t )TimerM$queue_head];
}

static inline  void TimerM$signalOneTimer(void)
#line 204
{
  uint8_t itimer = TimerM$dequeue();

#line 206
  if (itimer < NUM_TIMERS) {
    TimerM$Timer$fired(itimer);
    }
}

static inline  
#line 210
void TimerM$HandleFire(void)
#line 210
{
  uint8_t i;
  uint16_t int_out;

#line 213
  TimerM$setIntervalFlag = 1;


  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 216
    {
      int_out = TimerM$interval_outstanding;
      TimerM$interval_outstanding = 0;
    }
#line 219
    __nesc_atomic_end(__nesc_atomic); }
  if (TimerM$mState) {
      for (i = 0; i < NUM_TIMERS; i++) {
          if (TimerM$mState & (0x1L << i)) {
              TimerM$mTimerList[i].ticksLeft -= int_out;
              if (TimerM$mTimerList[i].ticksLeft <= 2) {


                  if (TOS_post(TimerM$signalOneTimer)) {
                      if (TimerM$mTimerList[i].type == TIMER_REPEAT) {
                          TimerM$mTimerList[i].ticksLeft += TimerM$mTimerList[i].ticks;
                        }
                      else 
#line 230
                        {
                          TimerM$mState &= ~(0x1L << i);
                        }
                      TimerM$enqueue(i);
                    }
                  else {
                      {
                      }
#line 236
                      ;


                      TimerM$mTimerList[i].ticksLeft = TimerM$mInterval;
                    }
                }
            }
        }
    }


  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 247
    int_out = TimerM$interval_outstanding;
#line 247
    __nesc_atomic_end(__nesc_atomic); }
  if (int_out == 0) {
    TimerM$adjustInterval();
    }
}

static inline   result_t TimerM$Clock$fire(void)
#line 253
{
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 254
    {



      if (TimerM$interval_outstanding == 0) {
        TOS_post(TimerM$HandleFire);
        }
      else {
        }
#line 261
      ;

      TimerM$interval_outstanding += TimerM$Clock$getInterval() + 1;
    }
#line 264
    __nesc_atomic_end(__nesc_atomic); }
  return SUCCESS;
}

# 180 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/Clock.nc"
inline static   result_t HPLClock$Clock$fire(void){
#line 180
  unsigned char result;
#line 180

#line 180
  result = TimerM$Clock$fire();
#line 180

#line 180
  return result;
#line 180
}
#line 180
# 175 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/micaz/hardware.h"
static __inline void TOSH_SET_PW2_PIN(void)
#line 175
{
#line 175
  * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x15 + 0x20) |= 1 << 2;
}

#line 162
static __inline void TOSH_SET_INT1_PIN(void)
#line 162
{
#line 162
  * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x03 + 0x20) |= 1 << 5;
}

# 73 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/sensorboards/micasb/sensorboard.h"
static __inline void TOSH_SET_PHOTO_CTL_PIN(void)
#line 73
{
#line 73
  TOSH_SET_INT1_PIN();
}

# 162 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/micaz/hardware.h"
static __inline void TOSH_MAKE_INT1_OUTPUT(void)
#line 162
{
#line 162
  * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x02 + 0x20) |= 1 << 5;
}

# 73 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/sensorboards/micasb/sensorboard.h"
static __inline void TOSH_MAKE_PHOTO_CTL_OUTPUT(void)
#line 73
{
#line 73
  TOSH_MAKE_INT1_OUTPUT();
}

# 173 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/micaz/hardware.h"
static __inline void TOSH_CLR_PW0_PIN(void)
#line 173
{
#line 173
  * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x15 + 0x20) &= ~(1 << 0);
}

# 75 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/sensorboards/micasb/sensorboard.h"
static __inline void TOSH_CLR_TEMP_CTL_PIN(void)
#line 75
{
#line 75
  TOSH_CLR_PW0_PIN();
}

# 173 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/micaz/hardware.h"
static __inline void TOSH_MAKE_PW0_INPUT(void)
#line 173
{
#line 173
  * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x14 + 0x20) &= ~(1 << 0);
}

# 75 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/sensorboards/micasb/sensorboard.h"
static __inline void TOSH_MAKE_TEMP_CTL_INPUT(void)
#line 75
{
#line 75
  TOSH_MAKE_PW0_INPUT();
}

# 68 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/Timer.nc"
inline static  result_t PhotoTempM$PhotoTempTimer$stop(void){
#line 68
  unsigned char result;
#line 68

#line 68
  result = TimerM$Timer$stop(10);
#line 68

#line 68
  return result;
#line 68
}
#line 68
# 59 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/Timer.nc"
inline static  result_t PhotoTempM$PhotoTempTimer$start(char arg_0xa344320, uint32_t arg_0xa344478){
#line 59
  unsigned char result;
#line 59

#line 59
  result = TimerM$Timer$start(10, arg_0xa344320, arg_0xa344478);
#line 59

#line 59
  return result;
#line 59
}
#line 59
# 162 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/micaz/hardware.h"
static __inline void TOSH_CLR_INT1_PIN(void)
#line 162
{
#line 162
  * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x03 + 0x20) &= ~(1 << 5);
}

# 73 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/sensorboards/micasb/sensorboard.h"
static __inline void TOSH_CLR_PHOTO_CTL_PIN(void)
#line 73
{
#line 73
  TOSH_CLR_INT1_PIN();
}

# 162 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/micaz/hardware.h"
static __inline void TOSH_MAKE_INT1_INPUT(void)
#line 162
{
#line 162
  * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x02 + 0x20) &= ~(1 << 5);
}

# 73 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/sensorboards/micasb/sensorboard.h"
static __inline void TOSH_MAKE_PHOTO_CTL_INPUT(void)
#line 73
{
#line 73
  TOSH_MAKE_INT1_INPUT();
}

# 173 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/micaz/hardware.h"
static __inline void TOSH_SET_PW0_PIN(void)
#line 173
{
#line 173
  * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x15 + 0x20) |= 1 << 0;
}

# 75 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/sensorboards/micasb/sensorboard.h"
static __inline void TOSH_SET_TEMP_CTL_PIN(void)
#line 75
{
#line 75
  TOSH_SET_PW0_PIN();
}

#line 75
static __inline void TOSH_MAKE_TEMP_CTL_OUTPUT(void)
#line 75
{
#line 75
  TOSH_MAKE_PW0_OUTPUT();
}

# 50 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/ADCControl.nc"
inline static  result_t VoltageM$ADCControl$init(void){
#line 50
  unsigned char result;
#line 50

#line 50
  result = ADCM$ADCControl$init();
#line 50

#line 50
  return result;
#line 50
}
#line 50
#line 89
inline static  result_t VoltageM$ADCControl$bindPort(uint8_t arg_0xa979670, uint8_t arg_0xa9797b8){
#line 89
  unsigned char result;
#line 89

#line 89
  result = ADCM$ADCControl$bindPort(arg_0xa979670, arg_0xa9797b8);
#line 89

#line 89
  return result;
#line 89
}
#line 89
# 52 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/ADC.nc"
inline static   result_t VoltageM$ADC$getData(void){
#line 52
  unsigned char result;
#line 52

#line 52
  result = ADCM$ADC$getData(TOS_ADC_VOLTAGE_PORT);
#line 52

#line 52
  return result;
#line 52
}
#line 52
# 41 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/SharedMsgBuf.nc"
inline static  TOS_MsgPtr DelugeM$SharedMsgBuf$getMsgBuf(void){
#line 41
  struct TOS_Msg *result;
#line 41

#line 41
  result = SharedMsgBufM$SharedMsgBuf$getMsgBuf();
#line 41

#line 41
  return result;
#line 41
}
#line 41
#line 59
inline static  bool DelugeM$SharedMsgBuf$isLocked(void){
#line 59
  unsigned char result;
#line 59

#line 59
  result = SharedMsgBufM$SharedMsgBuf$isLocked();
#line 59

#line 59
  return result;
#line 59
}
#line 59
# 33 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/Crc.nc"
inline static  uint16_t DelugeM$Crc$crc16(void *arg_0xa448f60, uint8_t arg_0xa4490a8){
#line 33
  unsigned int result;
#line 33

#line 33
  result = CrcC$Crc$crc16(arg_0xa448f60, arg_0xa4490a8);
#line 33

#line 33
  return result;
#line 33
}
#line 33
# 48 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/SendMsg.nc"
inline static  result_t DelugeM$SendAdvMsg$send(uint16_t arg_0xa46f5a8, uint8_t arg_0xa46f6f0, TOS_MsgPtr arg_0xa46f840){
#line 48
  unsigned char result;
#line 48

#line 48
  result = AMStandard$SendMsg$send(AM_DELUGEADVMSG, arg_0xa46f5a8, arg_0xa46f6f0, arg_0xa46f840);
#line 48

#line 48
  return result;
#line 48
}
#line 48
static inline   
# 75 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/system/NoLeds.nc"
result_t NoLeds$Leds$greenToggle(void)
#line 75
{
  return SUCCESS;
}

# 106 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/Leds.nc"
inline static   result_t DelugeM$Leds$greenToggle(void){
#line 106
  unsigned char result;
#line 106

#line 106
  result = NoLeds$Leds$greenToggle();
#line 106

#line 106
  return result;
#line 106
}
#line 106
# 46 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/SharedMsgBuf.nc"
inline static  void DelugeM$SharedMsgBuf$lock(void){
#line 46
  SharedMsgBufM$SharedMsgBuf$lock();
#line 46
}
#line 46
static inline  
# 141 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/mica2/HPLFlash.nc"
void HPLFlash$avail(void)
#line 141
{
  HPLFlash$FlashIdle$available();
}

#line 173
void __attribute((signal))   __vector_3(void)
#line 173
{
  * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x39 + 0x20) &= ~(1 << 2);
  TOS_post(HPLFlash$avail);
}

static inline  
# 254 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/DelugeMetadataM.nc"
pgnum_t DelugeMetadataM$DelugeStats$getNumPgsComplete(imgnum_t imgNum)
#line 254
{
  return DelugeMetadataM$imgDesc[imgNum].numPgsComplete;
}

# 34 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/DelugeStats.nc"
inline static  pgnum_t DelugePageTransferM$DelugeStats$getNumPgsComplete(imgnum_t arg_0xa4b9170){
#line 34
  unsigned char result;
#line 34

#line 34
  result = DelugeMetadataM$DelugeStats$getNumPgsComplete(arg_0xa4b9170);
#line 34

#line 34
  return result;
#line 34
}
#line 34
static inline  
# 246 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/DelugeMetadataM.nc"
imgvnum_t DelugeMetadataM$DelugeStats$getVNum(imgnum_t imgNum)
#line 246
{
  return DelugeMetadataM$imgDesc[imgNum].vNum;
}

# 35 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/DelugeStats.nc"
inline static  imgvnum_t DelugePageTransferM$DelugeStats$getVNum(imgnum_t arg_0xa4b9578){
#line 35
  int result;
#line 35

#line 35
  result = DelugeMetadataM$DelugeStats$getVNum(arg_0xa4b9578);
#line 35

#line 35
  return result;
#line 35
}
#line 35
static inline  
# 294 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/DelugePageTransferM.nc"
TOS_MsgPtr DelugePageTransferM$ReceiveReqMsg$receive(TOS_MsgPtr pMsg)
#line 294
{

  DelugeReqMsg *rxReqMsg = (DelugeReqMsg *)pMsg->data;
  imgnum_t imgNum;
  pgnum_t pgNum;
  int i;

  {
  }
#line 301
  ;



  if (
#line 304
  DelugePageTransferM$state == DelugePageTransferM$S_DISABLED
   || rxReqMsg->imgNum >= 3) {
    return pMsg;
    }
  imgNum = rxReqMsg->imgNum;
  pgNum = rxReqMsg->pgNum;


  DelugePageTransferM$suppressMsgs(imgNum, pgNum);




  if ((
#line 315
  rxReqMsg->dest != TOS_LOCAL_ADDRESS
   || rxReqMsg->vNum != DelugePageTransferM$DelugeStats$getVNum(imgNum))
   || pgNum >= DelugePageTransferM$DelugeStats$getNumPgsComplete(imgNum)) {
    return pMsg;
    }

  if (
#line 320
  DelugePageTransferM$state == DelugePageTransferM$S_IDLE
   || ((DelugePageTransferM$state == DelugePageTransferM$S_SENDING || DelugePageTransferM$state == DelugePageTransferM$S_TX_LOCKING)
   && imgNum == DelugePageTransferM$imgToSend
   && pgNum == DelugePageTransferM$pageToSend)) {

      for (i = 0; i < DELUGE_PKT_BITVEC_SIZE; i++) 
        DelugePageTransferM$pktsToSend[i] |= rxReqMsg->requestedPkts[i];
    }

  if (DelugePageTransferM$state == DelugePageTransferM$S_IDLE) {

      DelugePageTransferM$changeState(DelugePageTransferM$S_TX_LOCKING);
      DelugePageTransferM$imgToSend = imgNum;
      DelugePageTransferM$pageToSend = pgNum;
      DelugePageTransferM$nodeAddr = rxReqMsg->sourceAddr != TOS_UART_ADDR ? TOS_BCAST_ADDR : TOS_UART_ADDR;
      DelugePageTransferM$setupDataMsg();
    }

  return pMsg;
}

static inline   
# 95 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/system/NoLeds.nc"
result_t NoLeds$Leds$set(uint8_t value)
#line 95
{
  return SUCCESS;
}

# 149 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/Leds.nc"
inline static   result_t DelugePageTransferM$Leds$set(uint8_t arg_0xa3426c8){
#line 149
  unsigned char result;
#line 149

#line 149
  result = NoLeds$Leds$set(arg_0xa3426c8);
#line 149

#line 149
  return result;
#line 149
}
#line 149
static inline  
# 215 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/DelugePageTransferM.nc"
TOS_MsgPtr DelugePageTransferM$ReceiveDataMsg$receive(TOS_MsgPtr pMsg)
#line 215
{

  DelugeDataMsg *rxDataMsg = (DelugeDataMsg *)pMsg->data;


  if (
#line 219
  DelugePageTransferM$state == DelugePageTransferM$S_DISABLED
   || rxDataMsg->imgNum >= 3) {
    return pMsg;
    }
  {
  }
#line 223
  ;



  DelugePageTransferM$suppressMsgs(rxDataMsg->imgNum, rxDataMsg->pgNum);





  if (
#line 229
  rxDataMsg->vNum == DelugePageTransferM$DelugeStats$getVNum(rxDataMsg->imgNum)
   && rxDataMsg->imgNum == DelugePageTransferM$workingImgNum
   && rxDataMsg->pgNum == DelugePageTransferM$workingPgNum
   && DelugePageTransferM$pktsToReceive[rxDataMsg->pktNum / 8] & (1 << rxDataMsg->pktNum % 8)
   && DelugePageTransferM$size < DELUGE_QSIZE) {

      DelugePageTransferM$Leds$set(rxDataMsg->pktNum);

      {
      }
#line 237
      ;



      nmemcpy(&DelugePageTransferM$rxQueue[DelugePageTransferM$head ^ DelugePageTransferM$size], rxDataMsg, sizeof(DelugeDataMsg ));
      if (++DelugePageTransferM$size == 1) {
        DelugePageTransferM$writeData();
        }
    }
  return pMsg;
}

static inline  
#line 127
result_t DelugePageTransferM$PageTransfer$dataAvailable(uint16_t sourceAddr, imgnum_t imgNum)
#line 127
{

  if (DelugePageTransferM$state == DelugePageTransferM$S_IDLE && DelugePageTransferM$workingImgNum == imgNum) {

      DelugePageTransferM$changeState(DelugePageTransferM$S_RX_LOCKING);
      DelugePageTransferM$nodeAddr = sourceAddr;
      DelugePageTransferM$remainingAttempts = DELUGE_MAX_NUM_REQ_TRIES;
      DelugePageTransferM$suppressReq = FALSE;


      DelugePageTransferM$startReqTimer(TRUE);
    }

  return SUCCESS;
}

# 34 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/DelugePageTransfer.nc"
inline static  result_t DelugeM$PageTransfer$dataAvailable(uint16_t arg_0xa453cc0, imgnum_t arg_0xa453e10){
#line 34
  unsigned char result;
#line 34

#line 34
  result = DelugePageTransferM$PageTransfer$dataAvailable(arg_0xa453cc0, arg_0xa453e10);
#line 34

#line 34
  return result;
#line 34
}
#line 34
static inline 
# 159 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/system/tos.h"
void *nmemset(void *to, int val, size_t n)
{
  char *cto = to;

  while (n--) * cto++ = val;

  return to;
}

static inline  
# 107 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/DelugePageTransferM.nc"
result_t DelugePageTransferM$PageTransfer$setWorkingPage(imgnum_t imgNum, pgnum_t pgNum)
#line 107
{
  DelugePageTransferM$workingImgNum = imgNum;
  DelugePageTransferM$workingPgNum = pgNum;
  nmemset(DelugePageTransferM$pktsToReceive, 0xff, DELUGE_PKT_BITVEC_SIZE);
  return SUCCESS;
}

# 32 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/DelugePageTransfer.nc"
inline static  result_t DelugeM$PageTransfer$setWorkingPage(imgnum_t arg_0xa4534a8, pgnum_t arg_0xa4535f0){
#line 32
  unsigned char result;
#line 32

#line 32
  result = DelugePageTransferM$PageTransfer$setWorkingPage(arg_0xa4534a8, arg_0xa4535f0);
#line 32

#line 32
  return result;
#line 32
}
#line 32
# 36 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/DelugeMetadata.nc"
inline static  result_t DelugeM$Metadata$setupNewImage(DelugeImgDesc *arg_0xa4594e8){
#line 36
  unsigned char result;
#line 36

#line 36
  result = DelugeMetadataM$Metadata$setupNewImage(arg_0xa4594e8);
#line 36

#line 36
  return result;
#line 36
}
#line 36
#line 33
inline static  bool DelugeM$Metadata$isImgDescValid(DelugeImgDesc *arg_0xa458c98){
#line 33
  unsigned char result;
#line 33

#line 33
  result = DelugeMetadataM$Metadata$isImgDescValid(arg_0xa458c98);
#line 33

#line 33
  return result;
#line 33
}
#line 33
# 35 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/InternalFlash.nc"
inline static  result_t DelugeM$IFlash$write(void *arg_0xa4647d0, void *arg_0xa464928, uint16_t arg_0xa464a78){
#line 35
  unsigned char result;
#line 35

#line 35
  result = InternalFlashC$InternalFlash$write(arg_0xa4647d0, arg_0xa464928, arg_0xa464a78);
#line 35

#line 35
  return result;
#line 35
}
#line 35
static inline  
# 289 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/DelugeMetadataM.nc"
DelugeImgDesc *DelugeMetadataM$Metadata$getImgDesc(uint8_t imgNum)
#line 289
{
  return &DelugeMetadataM$imgDesc[imgNum];
}

# 34 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/DelugeMetadata.nc"
inline static  DelugeImgDesc *DelugeM$Metadata$getImgDesc(imgnum_t arg_0xa4590a8){
#line 34
  struct DelugeImgDesc *result;
#line 34

#line 34
  result = DelugeMetadataM$Metadata$getImgDesc(arg_0xa4590a8);
#line 34

#line 34
  return result;
#line 34
}
#line 34
static inline  
# 280 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/DelugeM.nc"
TOS_MsgPtr DelugeM$ReceiveAdvMsg$receive(TOS_MsgPtr pMsg)
#line 280
{

  DelugeAdvMsg *rxAdvMsg = (DelugeAdvMsg *)pMsg->data;
  imgnum_t imgNum = rxAdvMsg->imgDesc.imgNum;

  DelugeImgDesc *cmpImgDesc = & rxAdvMsg->imgDesc;
  DelugeImgDesc *curImgDesc;
  bool isEqual = FALSE;



  if ((
#line 289
  rxAdvMsg->version != DELUGE_VERSION
   || !DelugeM$isNodeDescValid(& rxAdvMsg->nodeDesc))
   || DelugeM$state != DelugeM$S_STARTED) {
    return pMsg;
    }
  curImgDesc = DelugeM$Metadata$getImgDesc(imgNum);

  if (rxAdvMsg->type != DELUGE_ADV_NORMAL) {


      if (
#line 298
      rxAdvMsg->type == DELUGE_ADV_PING
       || (cmpImgDesc->vNum == curImgDesc->vNum
       && cmpImgDesc->numPgsComplete == curImgDesc->numPgsComplete)) {
          DelugeM$sendAdvMsg(imgNum, rxAdvMsg->sourceAddr);
          if (rxAdvMsg->nodeDesc.vNum == DelugeM$nodeDesc.vNum) {
            return pMsg;
            }
        }
      else {
#line 305
        if (rxAdvMsg->type == DELUGE_ADV_RESET) {
            DelugeM$Metadata$setupNewImage(& rxAdvMsg->imgDesc);
            return pMsg;
          }
        }
    }


  if (
#line 311
  rxAdvMsg->nodeDesc.vNum != DelugeM$nodeDesc.vNum
   && rxAdvMsg->nodeDesc.vNum != DELUGE_INVALID_VNUM
   && rxAdvMsg->nodeDesc.imgNum < 3) {
      DelugeM$resetTimer(rxAdvMsg->nodeDesc.imgNum);
      if (rxAdvMsg->nodeDesc.vNum - DelugeM$nodeDesc.vNum > 0) {
          nmemcpy(&DelugeM$nodeDesc, & rxAdvMsg->nodeDesc, sizeof(DelugeNodeDesc ));

          DelugeM$IFlash$write((uint8_t *)IFLASH_NODE_DESC_ADDR, &DelugeM$nodeDesc, sizeof DelugeM$nodeDesc);

          if (DelugeM$nodeDesc.imgNum == DELUGE_GOLDEN_IMAGE_NUM) {
            DelugeM$rebootDelay = DELUGE_REBOOT_DELAY;
            }
          else {
#line 323
            DelugeM$checkReboot();
            }
#line 324
          if (rxAdvMsg->type == DELUGE_ADV_PC) {
            DelugeM$sendAdvMsg(imgNum, rxAdvMsg->sourceAddr);
            }
        }
    }



  if (
#line 331
  DelugeM$Metadata$isImgDescValid(& rxAdvMsg->imgDesc)
   && DelugeM$state == DelugeM$S_STARTED) {




      if (
#line 336
      imgNum != DELUGE_GOLDEN_IMAGE_NUM
       || (rxAdvMsg->type == DELUGE_ADV_PC && rxAdvMsg->sourceAddr == TOS_UART_ADDR)) {

          if (cmpImgDesc->vNum != curImgDesc->vNum) {


              if (
#line 341
              curImgDesc->vNum == DELUGE_INVALID_VNUM
               || (cmpImgDesc->vNum != DELUGE_INVALID_VNUM
               && cmpImgDesc->vNum - curImgDesc->vNum > 0)) {
                  DelugeM$Metadata$setupNewImage(& rxAdvMsg->imgDesc);
                  DelugeM$PageTransfer$setWorkingPage(DELUGE_INVALID_IMGNUM, DELUGE_INVALID_PGNUM);
                }
            }
          else {
            if (cmpImgDesc->numPgsComplete > curImgDesc->numPgsComplete) {
                if (DelugeM$advTimers[imgNum].newAdvs == 0) {
                  DelugeM$PageTransfer$dataAvailable(rxAdvMsg->sourceAddr, imgNum);
                  }
              }
            else {
#line 354
              if (cmpImgDesc->numPgsComplete < curImgDesc->numPgsComplete) {
                  DelugeM$advTimers[imgNum].newAdvs = DELUGE_NUM_NEWDATA_ADVS_REQUIRED;
                }
              else 
                {
                  DelugeM$advTimers[imgNum].overheard = 1;
                  isEqual = TRUE;
                }
              }
            }
#line 363
          if (!isEqual) {
            DelugeM$resetTimer(imgNum);
            }
        }
    }

  return pMsg;
}

# 46 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/SharedMsgBuf.nc"
inline static  void NetProgM$SharedMsgBuf$lock(void){
#line 46
  SharedMsgBufM$SharedMsgBuf$lock();
#line 46
}
#line 46
# 48 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/SendMsg.nc"
inline static  result_t NetProgM$SendMsg$send(uint16_t arg_0xa46f5a8, uint8_t arg_0xa46f6f0, TOS_MsgPtr arg_0xa46f840){
#line 48
  unsigned char result;
#line 48

#line 48
  result = AMStandard$SendMsg$send(AM_NETPROGMSG, arg_0xa46f5a8, arg_0xa46f6f0, arg_0xa46f840);
#line 48

#line 48
  return result;
#line 48
}
#line 48
# 41 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/SharedMsgBuf.nc"
inline static  TOS_MsgPtr NetProgM$SharedMsgBuf$getMsgBuf(void){
#line 41
  struct TOS_Msg *result;
#line 41

#line 41
  result = SharedMsgBufM$SharedMsgBuf$getMsgBuf();
#line 41

#line 41
  return result;
#line 41
}
#line 41
#line 59
inline static  bool NetProgM$SharedMsgBuf$isLocked(void){
#line 59
  unsigned char result;
#line 59

#line 59
  result = SharedMsgBufM$SharedMsgBuf$isLocked();
#line 59

#line 59
  return result;
#line 59
}
#line 59
static inline  
# 133 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/NetProgM.nc"
TOS_MsgPtr NetProgM$ReceiveMsg$receive(TOS_MsgPtr pMsg)
#line 133
{

  NetProgMsg *rxMsg = (NetProgMsg *)pMsg->data;


  if (
#line 137
  rxMsg->sourceAddr == TOS_UART_ADDR
   || rxMsg->sourceAddr == TOS_BCAST_ADDR) {
      if (!NetProgM$SharedMsgBuf$isLocked()) {
          TOS_MsgPtr pMsgBuf = NetProgM$SharedMsgBuf$getMsgBuf();
          NetProgMsg *txMsg = (NetProgMsg *)pMsgBuf->data;

#line 142
          txMsg->sourceAddr = TOS_LOCAL_ADDRESS;
          nmemcpy(& txMsg->ident, &G_Ident, sizeof G_Ident);
          if (NetProgM$SendMsg$send(rxMsg->sourceAddr, sizeof(NetProgMsg ), pMsgBuf) == SUCCESS) {
            NetProgM$SharedMsgBuf$lock();
            }
        }
    }
  return pMsg;
}

# 68 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/Timer.nc"
inline static  result_t TestSenseM$TempTimer$stop(void){
#line 68
  unsigned char result;
#line 68

#line 68
  result = TimerM$Timer$stop(8);
#line 68

#line 68
  return result;
#line 68
}
#line 68
# 68 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/Timer.nc"
inline static  result_t BlinkM$Timer$stop(void){
#line 68
  unsigned char result;
#line 68

#line 68
  result = TimerM$Timer$stop(0);
#line 68

#line 68
  return result;
#line 68
}
#line 68
static inline  
# 132 "BlinkM.nc"
result_t BlinkM$App$stop(void)
{
  BlinkM$Timer$stop();
  BlinkM$Leds$redOff();
  BlinkM$Leds$greenOff();
  BlinkM$Leds$yellowOff();

  return SUCCESS;
}

# 8 "TestSense_interface.nc"
inline static  result_t TestSenseM$TestSense_interface$stop(void){
#line 8
  unsigned char result;
#line 8

#line 8
  result = BlinkM$App$stop();
#line 8

#line 8
  return result;
#line 8
}
#line 8
static inline  
# 128 "BlinkM.nc"
result_t BlinkM$App$start(void)
{
  return BlinkM$Timer$start(TIMER_REPEAT, 1000);
}

# 6 "TestSense_interface.nc"
inline static  result_t TestSenseM$TestSense_interface$start(void){
#line 6
  unsigned char result;
#line 6

#line 6
  result = BlinkM$App$start();
#line 6

#line 6
  return result;
#line 6
}
#line 6
# 59 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/Timer.nc"
inline static  result_t TestSenseM$Timer$start(char arg_0xa344320, uint32_t arg_0xa344478){
#line 59
  unsigned char result;
#line 59

#line 59
  result = TimerM$Timer$start(7, arg_0xa344320, arg_0xa344478);
#line 59

#line 59
  return result;
#line 59
}
#line 59
static inline   
# 148 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/system/LedsC.nc"
result_t LedsC$Leds$yellowToggle(void)
#line 148
{
  result_t rval;

#line 150
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 150
    {
      if (LedsC$ledsOn & LedsC$YELLOW_BIT) {
        rval = LedsC$Leds$yellowOff();
        }
      else {
#line 154
        rval = LedsC$Leds$yellowOn();
        }
    }
#line 156
    __nesc_atomic_end(__nesc_atomic); }
#line 156
  return rval;
}

# 131 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/Leds.nc"
inline static   result_t TestSenseM$Leds$yellowToggle(void){
#line 131
  unsigned char result;
#line 131

#line 131
  result = LedsC$Leds$yellowToggle();
#line 131

#line 131
  return result;
#line 131
}
#line 131
static inline  
# 264 "TestSenseM.nc"
TOS_MsgPtr TestSenseM$ResetCounterMsg$receive(TOS_MsgPtr m)
#line 264
{


  TestSenseM$Leds$yellowToggle();

  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 269
    {
      struct OscopeResetMsg *reData = (struct OscopeResetMsg *)m->data;

#line 271
      TestSenseM$type = reData->type;



      TestSenseM$test = 0;
      switch (TestSenseM$type) 
        {
          case 0: 
            TestSenseM$timer = 0;
          TestSenseM$Timer$stop();
          TestSenseM$TempTimer$stop();
          break;
          case 1: 
            if (TestSenseM$sleeping == 1 && TestSenseM$timer == 0) 
              {
                TestSenseM$timer = 1;
                TestSenseM$Timer$start(TIMER_REPEAT, reData->interval);
              }
          break;
          case 2: 
            TestSenseM$VolControl$start();
          TestSenseM$VolADC$getData();
          break;
          case 3: 

            if (TestSenseM$sleeping == 2) 
              {
                TestSenseM$sleeping = 1;
                TestSenseM$TestSense_interface$start();
                TestSenseM$VolControl$start();
                TestSenseM$VolADC$getData();
              }
          break;
          case 4: 

            if (TestSenseM$sleeping == 1) 
              {
                TestSenseM$timer = 0;
                TestSenseM$sleeping = 2;
                TestSenseM$TestSense_interface$stop();
                TestSenseM$VolControl$start();
                TestSenseM$VolADC$getData();
                TestSenseM$Timer$stop();
                TestSenseM$TempTimer$stop();
              }
          break;
        }
    }
#line 318
    __nesc_atomic_end(__nesc_atomic); }
  return m;
}

static inline   
# 242 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/system/AMStandard.nc"
TOS_MsgPtr AMStandard$ReceiveMsg$default$receive(uint8_t id, TOS_MsgPtr msg)
#line 242
{
  return msg;
}

# 75 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/ReceiveMsg.nc"
inline static  TOS_MsgPtr AMStandard$ReceiveMsg$receive(uint8_t arg_0xa726b68, TOS_MsgPtr arg_0xa485df0){
#line 75
  struct TOS_Msg *result;
#line 75

#line 75
  switch (arg_0xa726b68) {
#line 75
    case AM_OSCOPERESETMSG:
#line 75
      result = TestSenseM$ResetCounterMsg$receive(arg_0xa485df0);
#line 75
      break;
#line 75
    case AM_DELUGEADVMSG:
#line 75
      result = DelugeM$ReceiveAdvMsg$receive(arg_0xa485df0);
#line 75
      break;
#line 75
    case AM_DELUGEREQMSG:
#line 75
      result = DelugePageTransferM$ReceiveReqMsg$receive(arg_0xa485df0);
#line 75
      break;
#line 75
    case AM_DELUGEDATAMSG:
#line 75
      result = DelugePageTransferM$ReceiveDataMsg$receive(arg_0xa485df0);
#line 75
      break;
#line 75
    case AM_NETPROGMSG:
#line 75
      result = NetProgM$ReceiveMsg$receive(arg_0xa485df0);
#line 75
      break;
#line 75
    default:
#line 75
      result = AMStandard$ReceiveMsg$default$receive(arg_0xa726b68, arg_0xa485df0);
#line 75
    }
#line 75

#line 75
  return result;
#line 75
}
#line 75
static inline   
# 89 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/micaz/HPLCC2420InterruptM.nc"
result_t HPLCC2420InterruptM$FIFOP$disable(void)
#line 89
{
  * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x39 + 0x20) &= ~(1 << 6);
  return SUCCESS;
}

# 59 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/CC2420Radio/HPLCC2420Interrupt.nc"
inline static   result_t CC2420RadioM$FIFOP$disable(void){
#line 59
  unsigned char result;
#line 59

#line 59
  result = HPLCC2420InterruptM$FIFOP$disable();
#line 59

#line 59
  return result;
#line 59
}
#line 59
static inline  
# 536 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/CC2420Radio/CC2420RadioM.nc"
void CC2420RadioM$delayedRXFIFOtask(void)
#line 536
{
  CC2420RadioM$delayedRXFIFO();
}

static inline    
#line 751
int16_t CC2420RadioM$MacBackoff$default$congestionBackoff(TOS_MsgPtr m)
#line 751
{
  return (CC2420RadioM$Random$rand() & 0x3F) + 1;
}

# 75 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/CC2420Radio/MacBackoff.nc"
inline static   int16_t CC2420RadioM$MacBackoff$congestionBackoff(TOS_MsgPtr arg_0xa748718){
#line 75
  int result;
#line 75

#line 75
  result = CC2420RadioM$MacBackoff$default$congestionBackoff(arg_0xa748718);
#line 75

#line 75
  return result;
#line 75
}
#line 75
static inline   
# 165 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/micaz/HPLTimer2.nc"
void HPLTimer2$Timer2$intDisable(void)
#line 165
{
  * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x37 + 0x20) &= ~(1 << 7);
}

# 168 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/Clock.nc"
inline static   void TimerJiffyAsyncM$Timer$intDisable(void){
#line 168
  HPLTimer2$Timer2$intDisable();
#line 168
}
#line 168
static inline   
# 81 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/micaz/TimerJiffyAsyncM.nc"
result_t TimerJiffyAsyncM$TimerJiffyAsync$stop(void)
{
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 83
    {
      TimerJiffyAsyncM$bSet = FALSE;
      TimerJiffyAsyncM$Timer$intDisable();
    }
#line 86
    __nesc_atomic_end(__nesc_atomic); }
  return SUCCESS;
}

# 8 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/CC2420Radio/TimerJiffyAsync.nc"
inline static   result_t CC2420RadioM$BackoffTimerJiffy$stop(void){
#line 8
  unsigned char result;
#line 8

#line 8
  result = TimerJiffyAsyncM$TimerJiffyAsync$stop();
#line 8

#line 8
  return result;
#line 8
}
#line 8
static inline   
# 76 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/micaz/TimerJiffyAsyncM.nc"
bool TimerJiffyAsyncM$TimerJiffyAsync$isSet(void)
{
  return TimerJiffyAsyncM$bSet;
}

# 10 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/CC2420Radio/TimerJiffyAsync.nc"
inline static   bool CC2420RadioM$BackoffTimerJiffy$isSet(void){
#line 10
  unsigned char result;
#line 10

#line 10
  result = TimerJiffyAsyncM$TimerJiffyAsync$isSet();
#line 10

#line 10
  return result;
#line 10
}
#line 10
static inline   
# 591 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/CC2420Radio/CC2420RadioM.nc"
result_t CC2420RadioM$FIFOP$fired(void)
#line 591
{






  if (CC2420RadioM$bAckEnable && CC2420RadioM$stateRadio == CC2420RadioM$PRE_TX_STATE) {
      if (CC2420RadioM$BackoffTimerJiffy$isSet()) {
          CC2420RadioM$BackoffTimerJiffy$stop();
          CC2420RadioM$BackoffTimerJiffy$setOneShot(CC2420RadioM$MacBackoff$congestionBackoff(CC2420RadioM$txbufptr) * 10 + 75);
        }
    }


  if (!TOSH_READ_CC_FIFO_PIN()) {
      CC2420RadioM$flushRXFIFO();
      return SUCCESS;
    }

  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 611
    {
      if (TOS_post(CC2420RadioM$delayedRXFIFOtask)) {
          CC2420RadioM$FIFOP$disable();
        }
      else {
          CC2420RadioM$flushRXFIFO();
        }
    }
#line 618
    __nesc_atomic_end(__nesc_atomic); }


  return SUCCESS;
}

# 51 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/CC2420Radio/HPLCC2420Interrupt.nc"
inline static   result_t HPLCC2420InterruptM$FIFOP$fired(void){
#line 51
  unsigned char result;
#line 51

#line 51
  result = CC2420RadioM$FIFOP$fired();
#line 51

#line 51
  return result;
#line 51
}
#line 51
# 61 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/CC2420Radio/HPLCC2420.nc"
inline static   uint16_t CC2420RadioM$HPLChipcon$read(uint8_t arg_0xa769728){
#line 61
  unsigned int result;
#line 61

#line 61
  result = HPLCC2420M$HPLCC2420$read(arg_0xa769728);
#line 61

#line 61
  return result;
#line 61
}
#line 61
# 144 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/micaz/hardware.h"
static __inline int TOSH_READ_CC_FIFOP_PIN(void)
#line 144
{
#line 144
  return (* (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x01 + 0x20) & (1 << 6)) != 0;
}

static inline  
# 252 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/system/AMStandard.nc"
TOS_MsgPtr AMStandard$RadioReceive$receive(TOS_MsgPtr packet)
#line 252
{
  return received(packet);
}

# 75 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/ReceiveMsg.nc"
inline static  TOS_MsgPtr CC2420RadioM$Receive$receive(TOS_MsgPtr arg_0xa485df0){
#line 75
  struct TOS_Msg *result;
#line 75

#line 75
  result = AMStandard$RadioReceive$receive(arg_0xa485df0);
#line 75

#line 75
  return result;
#line 75
}
#line 75
static inline  
# 153 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/CC2420Radio/CC2420RadioM.nc"
void CC2420RadioM$PacketRcvd(void)
#line 153
{
  TOS_MsgPtr pBuf;

  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 156
    {
      pBuf = CC2420RadioM$rxbufptr;
    }
#line 158
    __nesc_atomic_end(__nesc_atomic); }
  pBuf = CC2420RadioM$Receive$receive((TOS_MsgPtr )pBuf);
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 160
    {
      if (pBuf) {
#line 161
        CC2420RadioM$rxbufptr = pBuf;
        }
#line 162
      CC2420RadioM$rxbufptr->length = 0;
      CC2420RadioM$bPacketReceiving = FALSE;
    }
#line 164
    __nesc_atomic_end(__nesc_atomic); }
}

static 
# 23 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/CC2420Radio/byteorder.h"
__inline uint16_t fromLSB16(uint16_t a)
{
  return is_host_lsb() ? a : (a << 8) | (a >> 8);
}

static inline   
# 628 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/CC2420Radio/CC2420RadioM.nc"
result_t CC2420RadioM$HPLChipconFIFO$RXFIFODone(uint8_t length, uint8_t *data)
#line 628
{





  uint8_t currentstate;

#line 635
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 635
    {
      currentstate = CC2420RadioM$stateRadio;
    }
#line 637
    __nesc_atomic_end(__nesc_atomic); }




  if (((
#line 641
  !TOSH_READ_CC_FIFO_PIN() && !TOSH_READ_CC_FIFOP_PIN())
   || length == 0) || length > MSG_DATA_SIZE) {
      CC2420RadioM$flushRXFIFO();
      { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 644
        CC2420RadioM$bPacketReceiving = FALSE;
#line 644
        __nesc_atomic_end(__nesc_atomic); }
      return SUCCESS;
    }

  CC2420RadioM$rxbufptr = (TOS_MsgPtr )data;




  if (
#line 651
  CC2420RadioM$bAckEnable && currentstate == CC2420RadioM$POST_TX_STATE && (
  CC2420RadioM$rxbufptr->fcfhi & 0x07) == 0x02 && 
  CC2420RadioM$rxbufptr->dsn == CC2420RadioM$currentDSN && 
  data[length - 1] >> 7 == 1) {
      { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 655
        {
          CC2420RadioM$txbufptr->ack = 1;
          CC2420RadioM$txbufptr->strength = data[length - 2];
          CC2420RadioM$txbufptr->lqi = data[length - 1] & 0x7F;

          CC2420RadioM$stateRadio = CC2420RadioM$POST_TX_ACK_STATE;
          CC2420RadioM$bPacketReceiving = FALSE;
        }
#line 662
        __nesc_atomic_end(__nesc_atomic); }
      if (!TOS_post(CC2420RadioM$PacketSent)) {
        CC2420RadioM$sendFailed();
        }
#line 665
      return SUCCESS;
    }




  if ((CC2420RadioM$rxbufptr->fcfhi & 0x07) != 0x01 || 
  CC2420RadioM$rxbufptr->fcflo != 0x08) {
      CC2420RadioM$flushRXFIFO();
      { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 674
        CC2420RadioM$bPacketReceiving = FALSE;
#line 674
        __nesc_atomic_end(__nesc_atomic); }
      return SUCCESS;
    }

  CC2420RadioM$rxbufptr->length = CC2420RadioM$rxbufptr->length - MSG_HEADER_SIZE - MSG_FOOTER_SIZE;

  if (CC2420RadioM$rxbufptr->length > 29) {
      CC2420RadioM$flushRXFIFO();
      { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 682
        CC2420RadioM$bPacketReceiving = FALSE;
#line 682
        __nesc_atomic_end(__nesc_atomic); }
      return SUCCESS;
    }


  CC2420RadioM$rxbufptr->addr = fromLSB16(CC2420RadioM$rxbufptr->addr);


  CC2420RadioM$rxbufptr->crc = data[length - 1] >> 7;

  CC2420RadioM$rxbufptr->strength = data[length - 2];

  CC2420RadioM$rxbufptr->lqi = data[length - 1] & 0x7F;

  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 696
    {
      if (!TOS_post(CC2420RadioM$PacketRcvd)) {
          CC2420RadioM$bPacketReceiving = FALSE;
        }
    }
#line 700
    __nesc_atomic_end(__nesc_atomic); }

  if (!TOSH_READ_CC_FIFO_PIN() && !TOSH_READ_CC_FIFOP_PIN()) {
      CC2420RadioM$flushRXFIFO();
      return SUCCESS;
    }

  if (!TOSH_READ_CC_FIFOP_PIN()) {
      if (TOS_post(CC2420RadioM$delayedRXFIFOtask)) {
        return SUCCESS;
        }
    }
#line 711
  CC2420RadioM$flushRXFIFO();


  return SUCCESS;
}

# 39 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/CC2420Radio/HPLCC2420FIFO.nc"
inline static   result_t HPLCC2420FIFOM$HPLCC2420FIFO$RXFIFODone(uint8_t arg_0xa765970, uint8_t *arg_0xa765ad0){
#line 39
  unsigned char result;
#line 39

#line 39
  result = CC2420RadioM$HPLChipconFIFO$RXFIFODone(arg_0xa765970, arg_0xa765ad0);
#line 39

#line 39
  return result;
#line 39
}
#line 39
static inline  
# 74 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/micaz/HPLCC2420FIFOM.nc"
void HPLCC2420FIFOM$signalRXdone(void)
#line 74
{
  uint8_t _rxlen;
  uint8_t *_rxbuf;

  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 78
    {
      _rxlen = HPLCC2420FIFOM$rxlength;
      _rxbuf = HPLCC2420FIFOM$rxbuf;
      HPLCC2420FIFOM$rxbufBusy = FALSE;
    }
#line 82
    __nesc_atomic_end(__nesc_atomic); }

  HPLCC2420FIFOM$HPLCC2420FIFO$RXFIFODone(_rxlen, _rxbuf);
}

# 149 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/micaz/hardware.h"
static __inline void TOSH_SET_CC_CS_PIN(void)
#line 149
{
#line 149
  * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x18 + 0x20) |= 1 << 0;
}

static inline   
# 146 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/micaz/HPLCC2420FIFOM.nc"
result_t HPLCC2420FIFOM$HPLCC2420FIFO$readRXFIFO(uint8_t len, uint8_t *msg)
#line 146
{
  uint8_t status;
#line 147
  uint8_t i;
  bool returnFail = FALSE;

  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 150
    {
      if (HPLCC2420FIFOM$rxbufBusy) {
        returnFail = TRUE;
        }
      else {
#line 154
        HPLCC2420FIFOM$rxbufBusy = TRUE;
        }
    }
#line 156
    __nesc_atomic_end(__nesc_atomic); }
  if (returnFail) {
    return FAIL;
    }


  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 162
    {
      HPLCC2420FIFOM$bSpiAvail = FALSE;
      HPLCC2420FIFOM$rxbuf = msg;
      TOSH_CLR_CC_CS_PIN();
      * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x0F + 0x20) = 0x3F | 0x40;
      while (!(* (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x0E + 0x20) & 0x80)) {
        }
#line 167
      ;
      status = * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x0F + 0x20);
      * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x0F + 0x20) = 0;
      while (!(* (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x0E + 0x20) & 0x80)) {
        }
#line 170
      ;
      HPLCC2420FIFOM$rxlength = * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x0F + 0x20);
      if (HPLCC2420FIFOM$rxlength > 0) {
          HPLCC2420FIFOM$rxbuf[0] = HPLCC2420FIFOM$rxlength;

          HPLCC2420FIFOM$rxlength++;

          if (HPLCC2420FIFOM$rxlength > len) {
#line 177
            HPLCC2420FIFOM$rxlength = len;
            }
          for (i = 1; i < HPLCC2420FIFOM$rxlength; i++) {
              * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x0F + 0x20) = 0;
              while (!(* (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x0E + 0x20) & 0x80)) {
                }
#line 181
              ;
              HPLCC2420FIFOM$rxbuf[i] = * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x0F + 0x20);
            }
        }

      HPLCC2420FIFOM$bSpiAvail = TRUE;
    }
#line 187
    __nesc_atomic_end(__nesc_atomic); }
  TOSH_SET_CC_CS_PIN();
  if (TOS_post(HPLCC2420FIFOM$signalRXdone) == FAIL) {
      { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 190
        HPLCC2420FIFOM$rxbufBusy = FALSE;
#line 190
        __nesc_atomic_end(__nesc_atomic); }
      return FAIL;
    }
  return SUCCESS;
}

# 19 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/CC2420Radio/HPLCC2420FIFO.nc"
inline static   result_t CC2420RadioM$HPLChipconFIFO$readRXFIFO(uint8_t arg_0xa764bb8, uint8_t *arg_0xa764d18){
#line 19
  unsigned char result;
#line 19

#line 19
  result = HPLCC2420FIFOM$HPLCC2420FIFO$readRXFIFO(arg_0xa764bb8, arg_0xa764d18);
#line 19

#line 19
  return result;
#line 19
}
#line 19
static inline  
# 210 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/system/AMStandard.nc"
result_t AMStandard$RadioSend$sendDone(TOS_MsgPtr msg, result_t success)
#line 210
{
  return AMStandard$reportSendDone(msg, success);
}

# 67 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/BareSendMsg.nc"
inline static  result_t CC2420RadioM$Send$sendDone(TOS_MsgPtr arg_0xa71ecc8, result_t arg_0xa71ee18){
#line 67
  unsigned char result;
#line 67

#line 67
  result = AMStandard$RadioSend$sendDone(arg_0xa71ecc8, arg_0xa71ee18);
#line 67

#line 67
  return result;
#line 67
}
#line 67
static inline    
# 168 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/micaz/HPLTimer1M.nc"
result_t HPLTimer1M$Timer1$default$fire(void)
#line 168
{
#line 168
  return SUCCESS;
}

# 177 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/micaz/Clock16.nc"
inline static   result_t HPLTimer1M$Timer1$fire(void){
#line 177
  unsigned char result;
#line 177

#line 177
  result = HPLTimer1M$Timer1$default$fire();
#line 177

#line 177
  return result;
#line 177
}
#line 177
static inline   
# 227 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/micaz/HPLTimer1M.nc"
uint16_t HPLTimer1M$CaptureT1$getEvent(void)
#line 227
{
  uint16_t i;

#line 229
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 229
    i = * (volatile unsigned int *)(unsigned int )& * (volatile unsigned char *)(0x26 + 0x20);
#line 229
    __nesc_atomic_end(__nesc_atomic); }
  return i;
}

# 72 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/micaz/TimerCapture.nc"
inline static   void HPLTimer1M$CaptureT1$captured(uint16_t arg_0xa837500){
#line 72
  HPLCC2420InterruptM$SFDCapture$captured(arg_0xa837500);
#line 72
}
#line 72
# 278 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/micaz/HPLTimer1M.nc"
void __attribute((signal))   __vector_11(void)
{
  HPLTimer1M$CaptureT1$captured(HPLTimer1M$CaptureT1$getEvent());
}

static inline    
# 761 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/CC2420Radio/CC2420RadioM.nc"
void CC2420RadioM$RadioReceiveCoordinator$default$startSymbol(uint8_t bitsPerBlock, uint8_t offset, TOS_MsgPtr msgBuff)
#line 761
{
}

# 33 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/RadioCoordinator.nc"
inline static   void CC2420RadioM$RadioReceiveCoordinator$startSymbol(uint8_t arg_0xa749aa8, uint8_t arg_0xa749bf0, TOS_MsgPtr arg_0xa749d40){
#line 33
  CC2420RadioM$RadioReceiveCoordinator$default$startSymbol(arg_0xa749aa8, arg_0xa749bf0, arg_0xa749d40);
#line 33
}
#line 33
static 
# 144 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/CC2420Radio/CC2420RadioM.nc"
__inline result_t CC2420RadioM$setAckTimer(uint16_t jiffy)
#line 144
{
  CC2420RadioM$stateTimer = CC2420RadioM$TIMER_ACK;
  return CC2420RadioM$BackoffTimerJiffy$setOneShot(jiffy);
}

static inline   
# 211 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/micaz/HPLCC2420InterruptM.nc"
result_t HPLCC2420InterruptM$SFD$disable(void)
#line 211
{
  HPLCC2420InterruptM$SFDCapture$disableEvents();

  return SUCCESS;
}

# 60 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/CC2420Radio/HPLCC2420Capture.nc"
inline static   result_t CC2420RadioM$SFD$disable(void){
#line 60
  unsigned char result;
#line 60

#line 60
  result = HPLCC2420InterruptM$SFD$disable();
#line 60

#line 60
  return result;
#line 60
}
#line 60
static inline    
# 759 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/CC2420Radio/CC2420RadioM.nc"
void CC2420RadioM$RadioSendCoordinator$default$startSymbol(uint8_t bitsPerBlock, uint8_t offset, TOS_MsgPtr msgBuff)
#line 759
{
}

# 33 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/RadioCoordinator.nc"
inline static   void CC2420RadioM$RadioSendCoordinator$startSymbol(uint8_t arg_0xa749aa8, uint8_t arg_0xa749bf0, TOS_MsgPtr arg_0xa749d40){
#line 33
  CC2420RadioM$RadioSendCoordinator$default$startSymbol(arg_0xa749aa8, arg_0xa749bf0, arg_0xa749d40);
#line 33
}
#line 33
# 148 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/micaz/hardware.h"
static __inline int TOSH_READ_CC_SFD_PIN(void)
#line 148
{
#line 148
  return (* (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x10 + 0x20) & (1 << 4)) != 0;
}

static inline   
# 344 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/CC2420Radio/CC2420RadioM.nc"
result_t CC2420RadioM$SFD$captured(uint16_t time)
#line 344
{
  switch (CC2420RadioM$stateRadio) {
      case CC2420RadioM$TX_STATE: 

        CC2420RadioM$SFD$enableCapture(FALSE);


      if (!TOSH_READ_CC_SFD_PIN()) {
          CC2420RadioM$SFD$disable();
        }
      else {
          CC2420RadioM$stateRadio = CC2420RadioM$TX_WAIT;
        }

      CC2420RadioM$txbufptr->time = time;
      CC2420RadioM$RadioSendCoordinator$startSymbol(8, 0, CC2420RadioM$txbufptr);


      if (CC2420RadioM$stateRadio == CC2420RadioM$TX_WAIT) {
          break;
        }
      case CC2420RadioM$TX_WAIT: 

        CC2420RadioM$stateRadio = CC2420RadioM$POST_TX_STATE;
      CC2420RadioM$SFD$disable();

      CC2420RadioM$SFD$enableCapture(TRUE);

      if (CC2420RadioM$bAckEnable && CC2420RadioM$txbufptr->addr != TOS_BCAST_ADDR) {
          if (!CC2420RadioM$setAckTimer(75)) {
            CC2420RadioM$sendFailed();
            }
        }
      else {
          if (!TOS_post(CC2420RadioM$PacketSent)) {
            CC2420RadioM$sendFailed();
            }
        }
#line 381
      break;
      default: 

        CC2420RadioM$rxbufptr->time = time;
      CC2420RadioM$RadioReceiveCoordinator$startSymbol(8, 0, CC2420RadioM$rxbufptr);
    }
  return SUCCESS;
}

# 53 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/CC2420Radio/HPLCC2420Capture.nc"
inline static   result_t HPLCC2420InterruptM$SFD$captured(uint16_t arg_0xa78da10){
#line 53
  unsigned char result;
#line 53

#line 53
  result = CC2420RadioM$SFD$captured(arg_0xa78da10);
#line 53

#line 53
  return result;
#line 53
}
#line 53
static inline   
# 219 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/micaz/HPLTimer1M.nc"
bool HPLTimer1M$CaptureT1$isOverflowPending(void)
#line 219
{
  return * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x36 + 0x20) & 2;
}

# 47 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/micaz/TimerCapture.nc"
inline static   bool HPLCC2420InterruptM$SFDCapture$isOverflowPending(void){
#line 47
  unsigned char result;
#line 47

#line 47
  result = HPLTimer1M$CaptureT1$isOverflowPending();
#line 47

#line 47
  return result;
#line 47
}
#line 47
# 148 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/Clock.nc"
inline static   result_t TimerJiffyAsyncM$Timer$setIntervalAndScale(uint8_t arg_0xa36e880, uint8_t arg_0xa36e9c8){
#line 148
  unsigned char result;
#line 148

#line 148
  result = HPLTimer2$Timer2$setIntervalAndScale(arg_0xa36e880, arg_0xa36e9c8);
#line 148

#line 148
  return result;
#line 148
}
#line 148
static inline   
# 449 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/CC2420Radio/CC2420RadioM.nc"
result_t CC2420RadioM$BackoffTimerJiffy$fired(void)
#line 449
{
  uint8_t currentstate;

#line 451
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 451
    currentstate = CC2420RadioM$stateRadio;
#line 451
    __nesc_atomic_end(__nesc_atomic); }

  switch (CC2420RadioM$stateTimer) {
      case CC2420RadioM$TIMER_INITIAL: 
        if (!TOS_post(CC2420RadioM$startSend)) {
            CC2420RadioM$sendFailed();
          }
      break;
      case CC2420RadioM$TIMER_BACKOFF: 
        CC2420RadioM$tryToSend();
      break;
      case CC2420RadioM$TIMER_ACK: 
        if (currentstate == CC2420RadioM$POST_TX_STATE) {





            { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 469
              {
                CC2420RadioM$txbufptr->ack = 0;
                CC2420RadioM$stateRadio = CC2420RadioM$POST_TX_ACK_STATE;
              }
#line 472
              __nesc_atomic_end(__nesc_atomic); }
            if (!TOS_post(CC2420RadioM$PacketSent)) {
              CC2420RadioM$sendFailed();
              }
          }
#line 476
      break;
    }
  return SUCCESS;
}

# 12 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/CC2420Radio/TimerJiffyAsync.nc"
inline static   result_t TimerJiffyAsyncM$TimerJiffyAsync$fired(void){
#line 12
  unsigned char result;
#line 12

#line 12
  result = CC2420RadioM$BackoffTimerJiffy$fired();
#line 12

#line 12
  return result;
#line 12
}
#line 12
static inline   
# 44 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/micaz/TimerJiffyAsyncM.nc"
result_t TimerJiffyAsyncM$Timer$fire(void)
#line 44
{
  uint16_t localjiffy;

#line 46
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 46
    localjiffy = TimerJiffyAsyncM$jiffy;
#line 46
    __nesc_atomic_end(__nesc_atomic); }
  if (localjiffy < 0xFF) {
      TimerJiffyAsyncM$Timer$intDisable();
      { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 49
        TimerJiffyAsyncM$bSet = FALSE;
#line 49
        __nesc_atomic_end(__nesc_atomic); }
      TimerJiffyAsyncM$TimerJiffyAsync$fired();
    }
  else {

      localjiffy = localjiffy >> 8;
      { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 55
        TimerJiffyAsyncM$jiffy = localjiffy;
#line 55
        __nesc_atomic_end(__nesc_atomic); }
      TimerJiffyAsyncM$Timer$setIntervalAndScale(localjiffy, 0x4);
    }
  return SUCCESS;
}

# 180 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/Clock.nc"
inline static   result_t HPLTimer2$Timer2$fire(void){
#line 180
  unsigned char result;
#line 180

#line 180
  result = TimerJiffyAsyncM$Timer$fire();
#line 180

#line 180
  return result;
#line 180
}
#line 180
static inline   
# 721 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/CC2420Radio/CC2420RadioM.nc"
result_t CC2420RadioM$HPLChipconFIFO$TXFIFODone(uint8_t length, uint8_t *data)
#line 721
{
  CC2420RadioM$tryToSend();
  return SUCCESS;
}

# 50 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/CC2420Radio/HPLCC2420FIFO.nc"
inline static   result_t HPLCC2420FIFOM$HPLCC2420FIFO$TXFIFODone(uint8_t arg_0xa790010, uint8_t *arg_0xa790170){
#line 50
  unsigned char result;
#line 50

#line 50
  result = CC2420RadioM$HPLChipconFIFO$TXFIFODone(arg_0xa790010, arg_0xa790170);
#line 50

#line 50
  return result;
#line 50
}
#line 50
static inline  
# 57 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/micaz/HPLCC2420FIFOM.nc"
void HPLCC2420FIFOM$signalTXdone(void)
#line 57
{
  uint8_t _txlen;
  uint8_t *_txbuf;

  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 61
    {
      _txlen = HPLCC2420FIFOM$txlength;
      _txbuf = HPLCC2420FIFOM$txbuf;
      HPLCC2420FIFOM$txbufBusy = FALSE;
    }
#line 65
    __nesc_atomic_end(__nesc_atomic); }

  HPLCC2420FIFOM$HPLCC2420FIFO$TXFIFODone(_txlen, _txbuf);
}

static inline   
#line 95
result_t HPLCC2420FIFOM$HPLCC2420FIFO$writeTXFIFO(uint8_t len, uint8_t *msg)
#line 95
{
  uint8_t i = 0;
  uint8_t status;
  bool returnFail = FALSE;

  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 100
    {
      if (HPLCC2420FIFOM$txbufBusy) {
        returnFail = TRUE;
        }
      else {
#line 104
        HPLCC2420FIFOM$txbufBusy = TRUE;
        }
    }
#line 106
    __nesc_atomic_end(__nesc_atomic); }
  if (returnFail) {
    return FAIL;
    }


  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 112
    {
      HPLCC2420FIFOM$bSpiAvail = FALSE;
      HPLCC2420FIFOM$txlength = len;
      HPLCC2420FIFOM$txbuf = msg;
      TOSH_CLR_CC_CS_PIN();
      * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x0F + 0x20) = 0x3E;
      while (!(* (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x0E + 0x20) & 0x80)) {
        }
#line 118
      ;
      status = * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x0F + 0x20);
      for (i = 0; i < HPLCC2420FIFOM$txlength; i++) {
          * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x0F + 0x20) = *HPLCC2420FIFOM$txbuf;
          HPLCC2420FIFOM$txbuf++;
          while (!(* (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x0E + 0x20) & 0x80)) {
            }
#line 123
          ;
        }
      HPLCC2420FIFOM$bSpiAvail = TRUE;
    }
#line 126
    __nesc_atomic_end(__nesc_atomic); }
  TOSH_SET_CC_CS_PIN();
  if (TOS_post(HPLCC2420FIFOM$signalTXdone) == FAIL) {
      { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 129
        HPLCC2420FIFOM$txbufBusy = FALSE;
#line 129
        __nesc_atomic_end(__nesc_atomic); }
      return FAIL;
    }
  return status;
}

# 29 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/CC2420Radio/HPLCC2420FIFO.nc"
inline static   result_t CC2420RadioM$HPLChipconFIFO$writeTXFIFO(uint8_t arg_0xa7652f0, uint8_t *arg_0xa765450){
#line 29
  unsigned char result;
#line 29

#line 29
  result = HPLCC2420FIFOM$HPLCC2420FIFO$writeTXFIFO(arg_0xa7652f0, arg_0xa765450);
#line 29

#line 29
  return result;
#line 29
}
#line 29
# 152 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/micaz/hardware.h"
static __inline int TOSH_READ_RADIO_CCA_PIN(void)
#line 152
{
#line 152
  return (* (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x10 + 0x20) & (1 << 6)) != 0;
}

static 
# 136 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/CC2420Radio/CC2420RadioM.nc"
__inline result_t CC2420RadioM$setBackoffTimer(uint16_t jiffy)
#line 136
{
  CC2420RadioM$stateTimer = CC2420RadioM$TIMER_BACKOFF;
  if (jiffy == 0) {

    return CC2420RadioM$BackoffTimerJiffy$setOneShot(2);
    }
#line 141
  return CC2420RadioM$BackoffTimerJiffy$setOneShot(jiffy);
}

# 47 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/CC2420Radio/HPLCC2420.nc"
inline static   uint8_t CC2420RadioM$HPLChipcon$cmd(uint8_t arg_0xa768cd8){
#line 47
  unsigned char result;
#line 47

#line 47
  result = HPLCC2420M$HPLCC2420$cmd(arg_0xa768cd8);
#line 47

#line 47
  return result;
#line 47
}
#line 47
static inline 
# 321 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/CC2420Radio/CC2420RadioM.nc"
void CC2420RadioM$sendPacket(void)
#line 321
{
  uint8_t status;

  CC2420RadioM$HPLChipcon$cmd(0x05);
  status = CC2420RadioM$HPLChipcon$cmd(0x00);
  if ((status >> 3) & 0x01) {

      CC2420RadioM$SFD$enableCapture(TRUE);
    }
  else {

      { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 332
        CC2420RadioM$stateRadio = CC2420RadioM$PRE_TX_STATE;
#line 332
        __nesc_atomic_end(__nesc_atomic); }
      if (!CC2420RadioM$setBackoffTimer(CC2420RadioM$MacBackoff$congestionBackoff(CC2420RadioM$txbufptr) * 10)) {
          CC2420RadioM$sendFailed();
        }
    }
}

# 66 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/ByteComm.nc"
inline static   result_t UARTM$ByteComm$rxByteReady(uint8_t arg_0xa8c2d00, bool arg_0xa8c2e48, uint16_t arg_0xa8c2fa0){
#line 66
  unsigned char result;
#line 66

#line 66
  result = FramerM$ByteComm$rxByteReady(arg_0xa8c2d00, arg_0xa8c2e48, arg_0xa8c2fa0);
#line 66

#line 66
  return result;
#line 66
}
#line 66
static inline   
# 77 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/system/UARTM.nc"
result_t UARTM$HPLUART$get(uint8_t data)
#line 77
{




  UARTM$ByteComm$rxByteReady(data, FALSE, 0);
  {
  }
#line 83
  ;
  return SUCCESS;
}

# 88 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/HPLUART.nc"
inline static   result_t HPLUART0M$UART$get(uint8_t arg_0xa933888){
#line 88
  unsigned char result;
#line 88

#line 88
  result = UARTM$HPLUART$get(arg_0xa933888);
#line 88

#line 88
  return result;
#line 88
}
#line 88
# 90 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/mica2/HPLUART0M.nc"
void __attribute((signal))   __vector_18(void)
#line 90
{
  if (* (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x0B + 0x20) & (1 << 7)) {
    HPLUART0M$UART$get(* (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x0C + 0x20));
    }
}

static inline  
# 244 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/micaz/FramerM.nc"
void FramerM$PacketUnknown(void)
#line 244
{
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 245
    {
      FramerM$gFlags |= FramerM$FLAGS_UNKNOWN;
    }
#line 247
    __nesc_atomic_end(__nesc_atomic); }

  FramerM$StartTx();
}

static inline  
# 246 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/system/AMStandard.nc"
TOS_MsgPtr AMStandard$UARTReceive$receive(TOS_MsgPtr packet)
#line 246
{


  packet->group = TOS_AM_GROUP;
  return received(packet);
}

# 75 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/ReceiveMsg.nc"
inline static  TOS_MsgPtr FramerAckM$ReceiveCombined$receive(TOS_MsgPtr arg_0xa485df0){
#line 75
  struct TOS_Msg *result;
#line 75

#line 75
  result = AMStandard$UARTReceive$receive(arg_0xa485df0);
#line 75

#line 75
  return result;
#line 75
}
#line 75
static inline  
# 91 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/system/FramerAckM.nc"
TOS_MsgPtr FramerAckM$ReceiveMsg$receive(TOS_MsgPtr Msg)
#line 91
{
  TOS_MsgPtr pBuf;

  pBuf = FramerAckM$ReceiveCombined$receive(Msg);

  return pBuf;
}

# 75 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/ReceiveMsg.nc"
inline static  TOS_MsgPtr FramerM$ReceiveMsg$receive(TOS_MsgPtr arg_0xa485df0){
#line 75
  struct TOS_Msg *result;
#line 75

#line 75
  result = FramerAckM$ReceiveMsg$receive(arg_0xa485df0);
#line 75

#line 75
  return result;
#line 75
}
#line 75
static inline  
# 373 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/micaz/FramerM.nc"
result_t FramerM$TokenReceiveMsg$ReflectToken(uint8_t Token)
#line 373
{
  result_t Result = SUCCESS;

  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 376
    {
      if (!(FramerM$gFlags & FramerM$FLAGS_TOKENPEND)) {
          FramerM$gFlags |= FramerM$FLAGS_TOKENPEND;
          FramerM$gTxTokenBuf = Token;
        }
      else {
          Result = FAIL;
        }
    }
#line 384
    __nesc_atomic_end(__nesc_atomic); }

  if (Result == SUCCESS) {
      Result = FramerM$StartTx();
    }

  return Result;
}

# 88 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/TokenReceiveMsg.nc"
inline static  result_t FramerAckM$TokenReceiveMsg$ReflectToken(uint8_t arg_0xa8c6c10){
#line 88
  unsigned char result;
#line 88

#line 88
  result = FramerM$TokenReceiveMsg$ReflectToken(arg_0xa8c6c10);
#line 88

#line 88
  return result;
#line 88
}
#line 88
static inline  
# 74 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/system/FramerAckM.nc"
void FramerAckM$SendAckTask(void)
#line 74
{

  FramerAckM$TokenReceiveMsg$ReflectToken(FramerAckM$gTokenBuf);
}

static inline  TOS_MsgPtr FramerAckM$TokenReceiveMsg$receive(TOS_MsgPtr Msg, uint8_t token)
#line 79
{
  TOS_MsgPtr pBuf;

  FramerAckM$gTokenBuf = token;

  TOS_post(FramerAckM$SendAckTask);

  pBuf = FramerAckM$ReceiveCombined$receive(Msg);

  return pBuf;
}

# 75 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/TokenReceiveMsg.nc"
inline static  TOS_MsgPtr FramerM$TokenReceiveMsg$receive(TOS_MsgPtr arg_0xa8c64b0, uint8_t arg_0xa8c65f8){
#line 75
  struct TOS_Msg *result;
#line 75

#line 75
  result = FramerAckM$TokenReceiveMsg$receive(arg_0xa8c64b0, arg_0xa8c65f8);
#line 75

#line 75
  return result;
#line 75
}
#line 75
static inline  
# 252 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/micaz/FramerM.nc"
void FramerM$PacketRcvd(void)
#line 252
{
  FramerM$MsgRcvEntry_t *pRcv = &FramerM$gMsgRcvTbl[FramerM$gRxTailIndex];
  TOS_MsgPtr pBuf = pRcv->pMsg;



  if (pRcv->Length >= 5) {



      switch (pRcv->Proto) {
          case FramerM$PROTO_ACK: 
            break;
          case FramerM$PROTO_PACKET_ACK: 
            pBuf->crc = 1;
          pBuf = FramerM$TokenReceiveMsg$receive(pBuf, pRcv->Token);
          break;
          case FramerM$PROTO_PACKET_NOACK: 
            pBuf->crc = 1;
          pBuf = FramerM$ReceiveMsg$receive(pBuf);
          break;
          default: 
            FramerM$gTxUnknownBuf = pRcv->Proto;
          TOS_post(FramerM$PacketUnknown);
          break;
        }
    }

  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 280
    {
      if (pBuf) {
          pRcv->pMsg = pBuf;
        }
      pRcv->Length = 0;
      pRcv->Token = 0;
      FramerM$gRxTailIndex++;
      FramerM$gRxTailIndex %= FramerM$HDLC_QUEUESIZE;
    }
#line 288
    __nesc_atomic_end(__nesc_atomic); }
}

# 96 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/HPLUART.nc"
inline static   result_t HPLUART0M$UART$putDone(void){
#line 96
  unsigned char result;
#line 96

#line 96
  result = UARTM$HPLUART$putDone();
#line 96

#line 96
  return result;
#line 96
}
#line 96
# 100 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/mica2/HPLUART0M.nc"
void __attribute((interrupt))   __vector_20(void)
#line 100
{
  HPLUART0M$UART$putDone();
}

static inline   
# 611 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/micaz/FramerM.nc"
result_t FramerM$ByteComm$txDone(void)
#line 611
{

  if (FramerM$gTxState == FramerM$TXSTATE_FINISH) {
      FramerM$gTxState = FramerM$TXSTATE_IDLE;
      TOS_post(FramerM$PacketSent);
    }

  return SUCCESS;
}

# 83 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/ByteComm.nc"
inline static   result_t UARTM$ByteComm$txDone(void){
#line 83
  unsigned char result;
#line 83

#line 83
  result = FramerM$ByteComm$txDone();
#line 83

#line 83
  return result;
#line 83
}
#line 83
#line 55
inline static   result_t FramerM$ByteComm$txByte(uint8_t arg_0xa8c2870){
#line 55
  unsigned char result;
#line 55

#line 55
  result = UARTM$ByteComm$txByte(arg_0xa8c2870);
#line 55

#line 55
  return result;
#line 55
}
#line 55
static inline 
# 66 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/avrmote/crc.h"
uint16_t crcByte(uint16_t oldCrc, uint8_t byte)
{

  uint16_t *table = crcTable;
  uint16_t newCrc;

   __asm ("eor %1,%B3\n"
  "\tlsl %1\n"
  "\tadc %B2, __zero_reg__\n"
  "\tadd %A2, %1\n"
  "\tadc %B2, __zero_reg__\n"
  "\tlpm\n"
  "\tmov %B0, %A3\n"
  "\tmov %A0, r0\n"
  "\tadiw r30,1\n"
  "\tlpm\n"
  "\teor %B0, r0" : 
  "=r"(newCrc), "+r"(byte), "+z"(table) : "r"(oldCrc));
  return newCrc;
}

static inline   
# 533 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/micaz/FramerM.nc"
result_t FramerM$ByteComm$txByteReady(bool LastByteSuccess)
#line 533
{
  result_t TxResult = SUCCESS;
  uint8_t nextByte;

  if (LastByteSuccess != TRUE) {
      { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 538
        FramerM$gTxState = FramerM$TXSTATE_ERROR;
#line 538
        __nesc_atomic_end(__nesc_atomic); }
      TOS_post(FramerM$PacketSent);
      return SUCCESS;
    }

  switch (FramerM$gTxState) {

      case FramerM$TXSTATE_PROTO: 
        FramerM$gTxState = FramerM$TXSTATE_INFO;
      FramerM$gTxRunningCRC = crcByte(FramerM$gTxRunningCRC, FramerM$gTxProto);
      TxResult = FramerM$ByteComm$txByte(FramerM$gTxProto);
      break;

      case FramerM$TXSTATE_INFO: 
        if (FramerM$gTxProto == FramerM$PROTO_ACK) {
          nextByte = FramerM$gpTxBuf[0];
          }
        else {
#line 555
          nextByte = FramerM$gpTxBuf[FramerM$gTxByteCnt];
          }
#line 556
      FramerM$gTxRunningCRC = crcByte(FramerM$gTxRunningCRC, nextByte);
      FramerM$gTxByteCnt++;

      if (FramerM$gTxByteCnt == 10) {
        FramerM$gTxByteCnt = 0;
        }
#line 561
      if (FramerM$gTxByteCnt == 1) {
        FramerM$gTxByteCnt = 10;
        }
      if (FramerM$gTxByteCnt >= FramerM$gTxLength) {
          FramerM$gTxState = FramerM$TXSTATE_FCS1;
        }

      TxResult = FramerM$TxArbitraryByte(nextByte);
      break;

      case FramerM$TXSTATE_ESC: 

        TxResult = FramerM$ByteComm$txByte(FramerM$gTxEscByte ^ 0x20);
      FramerM$gTxState = FramerM$gPrevTxState;
      break;

      case FramerM$TXSTATE_FCS1: 
        nextByte = (uint8_t )(FramerM$gTxRunningCRC & 0xff);
      FramerM$gTxState = FramerM$TXSTATE_FCS2;
      TxResult = FramerM$TxArbitraryByte(nextByte);
      break;

      case FramerM$TXSTATE_FCS2: 
        nextByte = (uint8_t )((FramerM$gTxRunningCRC >> 8) & 0xff);
      FramerM$gTxState = FramerM$TXSTATE_ENDFLAG;
      TxResult = FramerM$TxArbitraryByte(nextByte);
      break;

      case FramerM$TXSTATE_ENDFLAG: 
        FramerM$gTxState = FramerM$TXSTATE_FINISH;
      TxResult = FramerM$ByteComm$txByte(FramerM$HDLC_FLAG_BYTE);

      break;

      case FramerM$TXSTATE_FINISH: 
        case FramerM$TXSTATE_ERROR: 

          default: 
            break;
    }


  if (TxResult != SUCCESS) {
      FramerM$gTxState = FramerM$TXSTATE_ERROR;
      TOS_post(FramerM$PacketSent);
    }

  return SUCCESS;
}

# 75 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/ByteComm.nc"
inline static   result_t UARTM$ByteComm$txByteReady(bool arg_0xa8c34d0){
#line 75
  unsigned char result;
#line 75

#line 75
  result = FramerM$ByteComm$txByteReady(arg_0xa8c34d0);
#line 75

#line 75
  return result;
#line 75
}
#line 75
# 99 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/HPLADC.nc"
inline static   result_t HPLADCC$ADC$dataReady(uint16_t arg_0xa9ce318){
#line 99
  unsigned char result;
#line 99

#line 99
  result = ADCM$HPLADC$dataReady(arg_0xa9ce318);
#line 99

#line 99
  return result;
#line 99
}
#line 99
static 
# 187 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/avrmote/avrhardware.h"
__inline void __nesc_enable_interrupt(void)
#line 187
{
   __asm volatile ("sei");}

# 131 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/avrmote/HPLADCC.nc"
void __attribute((signal))   __vector_21(void)
#line 131
{
  uint16_t data = * (volatile unsigned int *)(unsigned int )& * (volatile unsigned char *)(0x04 + 0x20);

  __nesc_enable_interrupt();
  HPLADCC$ADC$dataReady(data);
}

static inline   
#line 125
result_t HPLADCC$ADC$sampleStop(void)
#line 125
{
  * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x06 + 0x20) &= ~(1 << 7);
  return SUCCESS;
}

# 91 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/HPLADC.nc"
inline static   result_t ADCM$HPLADC$sampleStop(void){
#line 91
  unsigned char result;
#line 91

#line 91
  result = HPLADCC$ADC$sampleStop();
#line 91

#line 91
  return result;
#line 91
}
#line 91
static inline  
# 175 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/sensorboards/micasb/PhotoTempM.nc"
result_t PhotoTempM$TempStdControl$stop(void)
#line 175
{
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 176
    {
      PhotoTempM$tempSensor = PhotoTempM$stateIdle;
    }
#line 178
    __nesc_atomic_end(__nesc_atomic); }
#line 178
  ;
  return SUCCESS;
}

# 78 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/StdControl.nc"
inline static  result_t TestSenseM$TempControl$stop(void){
#line 78
  unsigned char result;
#line 78

#line 78
  result = PhotoTempM$TempStdControl$stop();
#line 78

#line 78
  return result;
#line 78
}
#line 78
static inline   
# 211 "TestSenseM.nc"
result_t TestSenseM$TempADC$dataReady(uint16_t data)
#line 211
{
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 212
    {
      TestSenseM$gSensorDataTemp = data;
      TestSenseM$test++;

      if (TestSenseM$test == 2) {
        TOS_post(TestSenseM$SendData);
        }
    }
#line 219
    __nesc_atomic_end(__nesc_atomic); }
  TestSenseM$TempControl$stop();
  return SUCCESS;
}

# 70 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/ADC.nc"
inline static   result_t PhotoTempM$ExternalTempADC$dataReady(uint16_t arg_0xa95fa50){
#line 70
  unsigned char result;
#line 70

#line 70
  result = TestSenseM$TempADC$dataReady(arg_0xa95fa50);
#line 70

#line 70
  return result;
#line 70
}
#line 70
static inline   
# 379 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/sensorboards/micasb/PhotoTempM.nc"
result_t PhotoTempM$InternalTempADC$dataReady(uint16_t data)
#line 379
{
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 380
    {
      PhotoTempM$waitingForSample = FALSE;
      switch (PhotoTempM$tempSensor) {
          default: 
            case PhotoTempM$stateIdle: 

              case PhotoTempM$stateReadOnce: 
                PhotoTempM$tempSensor = PhotoTempM$stateIdle;
          break;
          case PhotoTempM$stateContinuous: 
            break;
        }
#line 391
      ;
    }
#line 392
    __nesc_atomic_end(__nesc_atomic); }
#line 392
  ;
  TOS_post(PhotoTempM$getSample);
  return PhotoTempM$ExternalTempADC$dataReady(data);
}

static inline  
#line 151
result_t PhotoTempM$PhotoStdControl$stop(void)
#line 151
{
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 152
    {
      PhotoTempM$photoSensor = PhotoTempM$stateIdle;
    }
#line 154
    __nesc_atomic_end(__nesc_atomic); }
#line 154
  ;
  return SUCCESS;
}

# 78 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/StdControl.nc"
inline static  result_t TestSenseM$SensorControl$stop(void){
#line 78
  unsigned char result;
#line 78

#line 78
  result = PhotoTempM$PhotoStdControl$stop();
#line 78

#line 78
  return result;
#line 78
}
#line 78
static inline   
# 198 "TestSenseM.nc"
result_t TestSenseM$LightADC$dataReady(uint16_t data)
#line 198
{
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 199
    {
      TestSenseM$gSensorDataLight = data;

      TestSenseM$SensorControl$stop();
      TestSenseM$test++;

      if (TestSenseM$test == 2) {
        TOS_post(TestSenseM$SendData);
        }
    }
#line 208
    __nesc_atomic_end(__nesc_atomic); }
#line 208
  return SUCCESS;
}

# 70 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/ADC.nc"
inline static   result_t PhotoTempM$ExternalPhotoADC$dataReady(uint16_t arg_0xa95fa50){
#line 70
  unsigned char result;
#line 70

#line 70
  result = TestSenseM$LightADC$dataReady(arg_0xa95fa50);
#line 70

#line 70
  return result;
#line 70
}
#line 70
static inline   
# 357 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/sensorboards/micasb/PhotoTempM.nc"
result_t PhotoTempM$InternalPhotoADC$dataReady(uint16_t data)
#line 357
{
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 358
    {
      PhotoTempM$waitingForSample = FALSE;
      switch (PhotoTempM$photoSensor) {
          default: 
            case PhotoTempM$stateIdle: 

              case PhotoTempM$stateReadOnce: 
                PhotoTempM$photoSensor = PhotoTempM$stateIdle;
          break;
          case PhotoTempM$stateContinuous: 
            break;
        }
#line 369
      ;
    }
#line 370
    __nesc_atomic_end(__nesc_atomic); }
#line 370
  ;
  TOS_post(PhotoTempM$getSample);
  return PhotoTempM$ExternalPhotoADC$dataReady(data);
}

static inline  
# 73 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/micaz/VoltageM.nc"
result_t VoltageM$StdControl$stop(void)
#line 73
{
  return SUCCESS;
}

# 78 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/StdControl.nc"
inline static  result_t TestSenseM$VolControl$stop(void){
#line 78
  unsigned char result;
#line 78

#line 78
  result = VoltageM$StdControl$stop();
#line 78

#line 78
  return result;
#line 78
}
#line 78
static inline   
# 224 "TestSenseM.nc"
result_t TestSenseM$VolADC$dataReady(uint16_t data)
#line 224
{
  TestSenseM$VolControl$stop();
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 226
    {
      TestSenseM$gSensorDataVoltage = data;
      TOS_post(TestSenseM$sendStatus);
    }
#line 229
    __nesc_atomic_end(__nesc_atomic); }
  return SUCCESS;
}

# 70 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/ADC.nc"
inline static   result_t VoltageM$Voltage$dataReady(uint16_t arg_0xa95fa50){
#line 70
  unsigned char result;
#line 70

#line 70
  result = TestSenseM$VolADC$dataReady(arg_0xa95fa50);
#line 70

#line 70
  return result;
#line 70
}
#line 70
static inline 
# 77 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/micaz/VoltageM.nc"
void VoltageM$signalReady(uint16_t v)
#line 77
{
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 78
    VoltageM$state = VoltageM$S_IDLE;
#line 78
    __nesc_atomic_end(__nesc_atomic); }
  VoltageM$Voltage$dataReady(v);
}

static inline  void VoltageM$signalReadyTask(void)
#line 82
{
  uint32_t tmpVoltage;

  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 85
    {
      tmpVoltage = (uint32_t )1223 * 1024;
      tmpVoltage /= VoltageM$voltage;
    }
#line 88
    __nesc_atomic_end(__nesc_atomic); }
  VoltageM$signalReady(tmpVoltage);
}

static inline   
#line 118
result_t VoltageM$ADC$dataReady(uint16_t data)
#line 118
{

  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 120
    VoltageM$voltage = data;
#line 120
    __nesc_atomic_end(__nesc_atomic); }
  if (TOS_post(VoltageM$signalReadyTask) == FAIL) {
    VoltageM$signalReady(VoltageM$ERROR_VOLTAGE);
    }
#line 123
  return SUCCESS;
}

static inline    
# 91 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/system/ADCM.nc"
result_t ADCM$ADC$default$dataReady(uint8_t port, uint16_t data)
#line 91
{
  return FAIL;
}

# 70 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/ADC.nc"
inline static   result_t ADCM$ADC$dataReady(uint8_t arg_0xa99f2a0, uint16_t arg_0xa95fa50){
#line 70
  unsigned char result;
#line 70

#line 70
  switch (arg_0xa99f2a0) {
#line 70
    case TOS_ADC_PHOTO_PORT:
#line 70
      result = PhotoTempM$InternalPhotoADC$dataReady(arg_0xa95fa50);
#line 70
      break;
#line 70
    case TOS_ADC_TEMP_PORT:
#line 70
      result = PhotoTempM$InternalTempADC$dataReady(arg_0xa95fa50);
#line 70
      break;
#line 70
    case TOS_ADC_VOLTAGE_PORT:
#line 70
      result = VoltageM$ADC$dataReady(arg_0xa95fa50);
#line 70
      break;
#line 70
    default:
#line 70
      result = ADCM$ADC$default$dataReady(arg_0xa99f2a0, arg_0xa95fa50);
#line 70
    }
#line 70

#line 70
  return result;
#line 70
}
#line 70
# 48 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/SendMsg.nc"
inline static  result_t TestSenseM$DataMsg$send(uint16_t arg_0xa46f5a8, uint8_t arg_0xa46f6f0, TOS_MsgPtr arg_0xa46f840){
#line 48
  unsigned char result;
#line 48

#line 48
  result = AMStandard$SendMsg$send(AM_OSCOPEMSG, arg_0xa46f5a8, arg_0xa46f6f0, arg_0xa46f840);
#line 48

#line 48
  return result;
#line 48
}
#line 48
# 102 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/system/sched.c"
bool  TOS_post(void (*tp)(void))
#line 102
{
  __nesc_atomic_t fInterruptFlags;
  uint8_t tmp;



  fInterruptFlags = __nesc_atomic_start();

  tmp = TOSH_sched_free;

  if (TOSH_queue[tmp].tp == (void *)0) {
      TOSH_sched_free = (tmp + 1) & TOSH_TASK_BITMASK;
      TOSH_queue[tmp].tp = tp;
      __nesc_atomic_end(fInterruptFlags);

      return TRUE;
    }
  else {
      __nesc_atomic_end(fInterruptFlags);

      return FALSE;
    }
}

# 54 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/system/RealMain.nc"
int   main(void)
#line 54
{
  RealMain$hardwareInit();
  RealMain$Pot$init(10);
  TOSH_sched_init();

  RealMain$StdControl$init();
  RealMain$StdControl$start();
  __nesc_enable_interrupt();

  while (1) {
      TOSH_run_task();
    }
}

static  
# 77 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/system/TimerM.nc"
result_t TimerM$StdControl$init(void)
#line 77
{
  TimerM$mState = 0;
  TimerM$setIntervalFlag = 0;
  TimerM$queue_head = TimerM$queue_tail = -1;
  TimerM$queue_size = 0;
  TimerM$mScale = 3;
  TimerM$mInterval = TimerM$maxTimerInterval;
  return TimerM$Clock$setRate(TimerM$mInterval, TimerM$mScale);
}

static  
# 147 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/DelugeM.nc"
result_t DelugeM$StdControl$init(void)
#line 147
{

  DelugeM$state = DelugeM$S_INITIALIZING;

  DelugeM$IFlash$read((uint16_t *)IFLASH_NODE_DESC_ADDR, &DelugeM$nodeDesc, sizeof DelugeM$nodeDesc);

  DelugeM$Leds$init();
  DelugeM$PageTransferControl$init();

  return SUCCESS;
}

static  
# 70 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/avrmote/InternalFlashC.nc"
result_t InternalFlashC$InternalFlash$read(void *addr, void *buf, uint16_t size)
#line 70
{

  uint8_t *addrPtr = (uint8_t *)addr;
  uint8_t *bufPtr = (uint8_t *)buf;
  uint16_t i;

  if ((uint16_t )addr < InternalFlashC$IFLASH_BOUND_LOW || InternalFlashC$IFLASH_BOUND_HIGH + 2 <= (uint16_t )addr + size) {
    return FAIL;
    }
  for (i = 0; i < size; i++) {
      *bufPtr = eeprom_read_byte(addrPtr);
      addrPtr++;
      bufPtr++;
    }

  return SUCCESS;
}

static 
# 80 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/DelugePageTransferM.nc"
void DelugePageTransferM$changeState(uint8_t newState)
#line 80
{


  if ((
#line 82
  newState == DelugePageTransferM$S_DISABLED || newState == DelugePageTransferM$S_IDLE)
   && (DelugePageTransferM$state == DelugePageTransferM$S_SENDING || DelugePageTransferM$state == DelugePageTransferM$S_RECEIVING)) {
    DelugePageTransferM$SharedMsgBuf$unlock();
    }
  DelugePageTransferM$state = newState;
}

static 
#line 250
void DelugePageTransferM$setupDataMsg(void)
#line 250
{

  TOS_MsgPtr pMsgBuf = DelugePageTransferM$SharedMsgBuf$getMsgBuf();
  DelugeDataMsg *pDataMsg = (DelugeDataMsg *)pMsgBuf->data;

  uint16_t nextPkt;

  if (DelugePageTransferM$state != DelugePageTransferM$S_SENDING && DelugePageTransferM$state != DelugePageTransferM$S_TX_LOCKING) {
    return;
    }
  DelugePageTransferM$PageTransfer$suppressMsgs(DelugePageTransferM$imgToSend);

  if (DelugePageTransferM$state == DelugePageTransferM$S_TX_LOCKING) {
      if (DelugePageTransferM$SharedMsgBuf$isLocked()) {
        return;
        }
#line 265
      DelugePageTransferM$SharedMsgBuf$lock();
      DelugePageTransferM$changeState(DelugePageTransferM$S_SENDING);
      pDataMsg->vNum = DelugePageTransferM$DelugeStats$getVNum(DelugePageTransferM$imgToSend);
      pDataMsg->imgNum = DelugePageTransferM$imgToSend;
      pDataMsg->pgNum = DelugePageTransferM$pageToSend;
      pDataMsg->pktNum = 0;
    }

  if (!DelugePageTransferM$BitVecUtils$indexOf(&nextPkt, pDataMsg->pktNum, 
  DelugePageTransferM$pktsToSend, DELUGE_PKTS_PER_PAGE)) {

      {
      }
#line 276
      ;
      DelugePageTransferM$changeState(DelugePageTransferM$S_IDLE);
    }
  else {
      pDataMsg->pktNum = nextPkt;

      if (
#line 281
      DelugePageTransferM$DataRead$read(DelugePageTransferM$imgToSend, DelugePageTransferM$calcOffset(DelugePageTransferM$pageToSend, nextPkt), 
      pDataMsg->data, DELUGE_PKT_PAYLOAD_SIZE) == FAIL) {
        DelugePageTransferM$Timer$start(TIMER_ONE_SHOT, DELUGE_FAILED_SEND_DELAY);
        }
    }
}

static  
# 41 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/BitVecUtilsC.nc"
result_t BitVecUtilsC$BitVecUtils$indexOf(uint16_t *pResult, uint16_t fromIndex, 
uint8_t *bitVec, uint16_t length)
#line 42
{

  uint16_t i = fromIndex;

  if (length == 0) {
    return FAIL;
    }
  do {
      if (bitVec[i / 8] & (1 << i % 8)) {
          *pResult = i;
          return SUCCESS;
        }
      i = (i + 1) % length;
    }
  while (
#line 55
  i != fromIndex);

  return FAIL;
}

static 
# 129 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/DelugeStorageM.nc"
result_t DelugeStorageM$newRequest(uint8_t newState, imgnum_t imgNum, 
block_addr_t addr, void *buf, uint16_t len)
#line 130
{

  result_t result = FAIL;
  uint8_t image = DELUGE_IMAGES[imgNum].imageNum;

  if (DelugeStorageM$state != DelugeStorageM$S_IDLE) {
    return FAIL;
    }
  switch (newState) {
      case DelugeStorageM$S_VERIFY: 
        DelugeStorageM$pgNum = addr;
      addr = 16 + sizeof(uint16_t ) * DelugeStorageM$pgNum;
      buf = &DelugeStorageM$crcScratch;
      len = sizeof DelugeStorageM$crcScratch;

      case DelugeStorageM$S_METADATA_READ: case DelugeStorageM$S_READ: 
          result = DelugeStorageM$BlockRead$read(image, addr, buf, len);
      break;
      case DelugeStorageM$S_METADATA_WRITE: case DelugeStorageM$S_WRITE: 
          result = DelugeStorageM$BlockWrite$write(image, addr, buf, len);
      break;
      case DelugeStorageM$S_ERASE: 
        result = DelugeStorageM$BlockWrite$erase(image);
      break;
      case DelugeStorageM$S_COMMIT: 
        result = DelugeStorageM$BlockWrite$commit(image);
      break;
    }

  if (result == SUCCESS) {
    DelugeStorageM$state = newState;
    }
  return result;
}

static 
# 175 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/BlockStorageM.nc"
result_t BlockStorageM$newRequest(uint8_t newState, uint8_t id, 
block_addr_t addr, uint8_t *buf, block_addr_t len)
#line 176
{
  if (BlockStorageM$admitRequest(newState, id) == FAIL) {
    return FAIL;
    }
  BlockStorageM$curAddr = addr;
  BlockStorageM$bufPtr = buf;
  BlockStorageM$bytesRemaining = BlockStorageM$requestedLength = len;
  BlockStorageM$crc = 0;

  BlockStorageM$continueRequest();

  return SUCCESS;
}

static 
#line 151
void BlockStorageM$continueRequest(void)
#line 151
{
  at45page_t page;
  at45pageoffset_t offset;
#line 153
  at45pageoffset_t count;
  uint8_t *buf = BlockStorageM$bufPtr;

  BlockStorageM$calcRequest(BlockStorageM$curAddr, &page, &offset, &count);
  BlockStorageM$bytesRemaining -= count;
  BlockStorageM$curAddr += count;
  BlockStorageM$bufPtr += count;

  switch (BlockStorageM$state) 
    {
      case BlockStorageM$S_WRITE: 
        BlockStorageM$check(BlockStorageM$PageEEPROM$write(BlockStorageM$client, page, offset, buf, count));
      break;
      case BlockStorageM$S_READ: 
        BlockStorageM$check(BlockStorageM$PageEEPROM$read(BlockStorageM$client, page, offset, buf, count));
      break;
      case BlockStorageM$S_CRC: case BlockStorageM$S_COMMIT: case BlockStorageM$S_VERIFY2: 
            BlockStorageM$check(BlockStorageM$PageEEPROM$computeCrcContinue(BlockStorageM$client, page, offset, count, BlockStorageM$crc));
      break;
    }
}

static 
#line 71
result_t BlockStorageM$actualSignal(storage_result_t result)
#line 71
{
  uint8_t tmpState = BlockStorageM$state;
  block_addr_t actualLength;

  BlockStorageM$state = BlockStorageM$S_IDLE;
  actualLength = BlockStorageM$requestedLength - BlockStorageM$bytesRemaining;
  BlockStorageM$curAddr -= actualLength;
  BlockStorageM$bufPtr -= actualLength;

  switch (tmpState) 
    {
      case BlockStorageM$S_READ: 
        BlockStorageM$BlockRead$readDone(BlockStorageM$client, result, BlockStorageM$curAddr, BlockStorageM$bufPtr, actualLength);
      break;
      case BlockStorageM$S_WRITE: 
        BlockStorageM$BlockWrite$writeDone(BlockStorageM$client, result, BlockStorageM$curAddr, BlockStorageM$bufPtr, actualLength);
      break;
      case BlockStorageM$S_ERASE: 
        BlockStorageM$BlockWrite$eraseDone(BlockStorageM$client, result);
      break;
      case BlockStorageM$S_CRC: 
        BlockStorageM$BlockRead$computeCrcDone(BlockStorageM$client, result, BlockStorageM$crc, BlockStorageM$curAddr, actualLength);
      break;
      case BlockStorageM$S_COMMIT: case BlockStorageM$S_COMMIT2: case BlockStorageM$S_COMMIT3: 
            BlockStorageM$BlockWrite$commitDone(BlockStorageM$client, result);
      break;
      case BlockStorageM$S_VERIFY: case BlockStorageM$S_VERIFY2: 
          BlockStorageM$BlockRead$verifyDone(BlockStorageM$client, result);
      break;
    }

  return SUCCESS;
}

static  
# 196 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/DelugeStorageM.nc"
void DelugeStorageM$BlockRead$readDone(uint8_t volume, storage_result_t result, block_addr_t addr, void *buf, block_addr_t len)
#line 196
{

  uint16_t tmpLen;

  if (DelugeStorageM$pgNum == 0) {
      addr = DELUGE_CRC_BLOCK_SIZE;
      tmpLen = DELUGE_BYTES_PER_PAGE - DELUGE_CRC_BLOCK_SIZE;
    }
  else {
      addr = (block_addr_t )DelugeStorageM$pgNum * DELUGE_BYTES_PER_PAGE;
      tmpLen = DELUGE_BYTES_PER_PAGE;
    }



  if ((
#line 209
  result != STORAGE_OK
   || DelugeStorageM$state == DelugeStorageM$S_READ)
   || DelugeStorageM$BlockRead$computeCrc(volume, addr + 16, tmpLen) == FAIL) {
    DelugeStorageM$signalDone(result);
    }
}

static 
#line 67
void DelugeStorageM$signalDone(result_t result)
#line 67
{
  uint8_t tmpState = DelugeStorageM$state;

#line 69
  DelugeStorageM$state = DelugeStorageM$S_IDLE;
  switch (tmpState) {
      case DelugeStorageM$S_METADATA_READ: DelugeStorageM$MetadataStore$readDone(result);
#line 71
      break;
      case DelugeStorageM$S_READ: DelugeStorageM$DataRead$readDone(result);
#line 72
      break;
      case DelugeStorageM$S_METADATA_WRITE: DelugeStorageM$MetadataStore$writeDone(result);
#line 73
      break;
      case DelugeStorageM$S_WRITE: DelugeStorageM$DataWrite$writeDone(result);
#line 74
      break;
      case DelugeStorageM$S_ERASE: DelugeStorageM$DataWrite$eraseDone(result);
#line 75
      break;
      case DelugeStorageM$S_VERIFY: DelugeStorageM$DataRead$verifyDone(result, DelugeStorageM$crcScratch);
#line 76
      break;
      case DelugeStorageM$S_COMMIT: DelugeStorageM$DataWrite$commitDone(result);
#line 77
      break;
      case DelugeStorageM$S_MOUNTING: 
        if (result == FAIL) {
          DelugeStorageM$state = DelugeStorageM$S_NEVER_USED;
          }
#line 81
      DelugeStorageM$DelugeStorage$loadImagesDone(result);
      break;
    }
}

static  
# 98 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/system/TimerM.nc"
result_t TimerM$Timer$start(uint8_t id, char type, 
uint32_t interval)
#line 99
{
  uint8_t diff;

#line 101
  if (id >= NUM_TIMERS) {
#line 101
    return FAIL;
    }
#line 102
  if (type > TIMER_ONE_SHOT) {
#line 102
    return FAIL;
    }





  if (type == TIMER_REPEAT && interval <= 2) {
#line 109
    return FAIL;
    }
  TimerM$mTimerList[id].ticks = interval;
  TimerM$mTimerList[id].type = type;

  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 114
    {
      diff = TimerM$Clock$readCounter();
      interval += diff;
      TimerM$mTimerList[id].ticksLeft = interval;
      TimerM$mState |= 0x1L << id;
      if (interval < TimerM$mInterval) {
          TimerM$mInterval = interval;
          TimerM$Clock$setInterval(TimerM$mInterval);
          TimerM$setIntervalFlag = 0;
          TimerM$PowerManagement$adjustPower();
        }
    }
#line 125
    __nesc_atomic_end(__nesc_atomic); }
  return SUCCESS;
}

static   
# 102 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/mica2/HPLPowerManagementM.nc"
uint8_t HPLPowerManagementM$PowerManagement$adjustPower(void)
#line 102
{
  uint8_t mcu;

#line 104
  if (HPLPowerManagementM$disableCount <= 0) {
    TOS_post(HPLPowerManagementM$doAdjustment);
    }
  else 
#line 106
    {
      mcu = * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x35 + 0x20);
      mcu &= 0xe3;
      mcu |= HPLPowerManagementM$IDLE;
      * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x35 + 0x20) = mcu;
      * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x35 + 0x20) |= 1 << 5;
    }
  return 0;
}

static  
# 240 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/DelugeMetadataM.nc"
bool DelugeMetadataM$Metadata$isImgDescValid(DelugeImgDesc *tmpImgDesc)
#line 240
{
  return tmpImgDesc->crc == DelugeMetadataM$Crc$crc16(tmpImgDesc, 8)
   && tmpImgDesc->crc != 0
   && tmpImgDesc->imgNum < 3;
}

static  
# 39 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/system/CrcC.nc"
uint16_t CrcC$Crc$crc16(void *buf, uint8_t len)
#line 39
{

  uint8_t *tmpBuf = (uint8_t *)buf;
  uint16_t crc;

  for (crc = 0; len > 0; len--) 
    crc = crcByte(crc, * tmpBuf++);

  return crc;
}

static 
# 137 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/DelugeMetadataM.nc"
void DelugeMetadataM$scanNextImage(void)
#line 137
{
  DelugeMetadataM$state = DelugeMetadataM$S_SCAN_METADATA;
  DelugeMetadataM$curImage++;
  if (DelugeMetadataM$curImage < 3) {
      DelugeMetadataM$execute();
    }
  else {

      DelugeMetadataM$state = DelugeMetadataM$S_IDLE;
      DelugeMetadataM$SplitControl$startDone();
    }
}

static 
#line 89
result_t DelugeMetadataM$execute(void)
#line 89
{

  result_t result = FAIL;

  switch (DelugeMetadataM$state) {
      case DelugeMetadataM$S_INIT: 
        result = DelugeMetadataM$DelugeStorage$loadImages();
      break;
      case DelugeMetadataM$S_SCAN_METADATA: 
        result = DelugeMetadataM$MetadataStore$read(DelugeMetadataM$curImage, &DelugeMetadataM$imgDesc[DelugeMetadataM$curImage]);
      break;
      case DelugeMetadataM$S_CLEAR_WP: 
        result = DelugeMetadataM$FlashWP$clrWP();
      break;
      case DelugeMetadataM$S_SETUP: 
        result = DelugeMetadataM$DataWrite$erase(DelugeMetadataM$curImage);
      break;
      case DelugeMetadataM$S_VERIFY: 
        DelugeMetadataM$verifyNextPage();
      result = SUCCESS;
      break;
      case DelugeMetadataM$S_SET_WP: 
        result = DelugeMetadataM$FlashWP$setWP();
      break;
    }

  if (result == FAIL) {
    DelugeMetadataM$Timer$start(TIMER_ONE_SHOT, 512);
    }
  return result;
}

static  
# 82 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/StorageManagerM.nc"
result_t StorageManagerM$Mount$mount(volume_t v, volume_id_t i)
#line 82
{
  if (StorageManagerM$f.busy || StorageManagerM$volumes[v].id != INVALID_VOLUME_ID) {
    return FAIL;
    }
  StorageManagerM$f.busy = TRUE;
  StorageManagerM$client = v;
  StorageManagerM$id = i;
  StorageManagerM$nextVolume = 0;
  TOS_post(StorageManagerM$mountVolume);

  return SUCCESS;
}

static  
# 104 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/DelugeStorageM.nc"
void DelugeStorageM$Mount$mountDone(volume_t volume, storage_result_t result, volume_id_t id)
#line 104
{

  if (result != STORAGE_OK) {
      DelugeStorageM$signalDone(FAIL);
      return;
    }


  if (++DelugeStorageM$client < 3) {
      if (DelugeStorageM$Mount$mount(DELUGE_IMAGES[DelugeStorageM$client].imageNum, DELUGE_IMAGES[DelugeStorageM$client].volumeId) == FAIL) {
        DelugeStorageM$signalDone(FAIL);
        }
#line 115
      return;
    }


  DelugeStorageM$signalDone(SUCCESS);
}

static 
# 495 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/mica/PageEEPROMM.nc"
result_t PageEEPROMM$newRequest(uint8_t req, eeprompage_t page, 
eeprompageoffset_t offset, 
void *reqdata, eeprompageoffset_t n, 
uint16_t crc)
#line 498
{


  if (((
#line 500
  page >= TOS_EEPROM_MAX_PAGES || offset >= TOS_EEPROM_PAGE_SIZE) || 
  n > TOS_EEPROM_PAGE_SIZE) || offset + n > TOS_EEPROM_PAGE_SIZE) {
    return FAIL;
    }

  if (PageEEPROMM$request != PageEEPROMM$IDLE) {
    return FAIL;
    }
#line 507
  PageEEPROMM$request = req;

  if (PageEEPROMM$broken) 
    {
      TOS_post(PageEEPROMM$taskFail);
      return SUCCESS;
    }

  PageEEPROMM$reqBuf = reqdata;
  PageEEPROMM$reqBytes = n;
  PageEEPROMM$reqPage = page;
  PageEEPROMM$reqOffset = offset;
  PageEEPROMM$computedCrc = crc;

  if (page == PageEEPROMM$buffer[0].page) {
    PageEEPROMM$selected = 0;
    }
  else {
#line 523
    if (page == PageEEPROMM$buffer[1].page) {
      PageEEPROMM$selected = 1;
      }
    else {
#line 526
      PageEEPROMM$selected = !PageEEPROMM$selected;
      }
    }
#line 528
  PageEEPROMM$handleRWRequest();

  return SUCCESS;
}

static 
#line 480
void PageEEPROMM$requestDone(result_t result)
#line 480
{
  uint8_t orequest = PageEEPROMM$request;

  PageEEPROMM$request = PageEEPROMM$IDLE;
  switch (orequest) 
    {
      case PageEEPROMM$R_READ: PageEEPROMM$PageEEPROM$readDone(result);
#line 486
      break;
      case PageEEPROMM$R_READCRC: PageEEPROMM$PageEEPROM$computeCrcDone(result, PageEEPROMM$computedCrc);
#line 487
      break;
      case PageEEPROMM$R_WRITE: PageEEPROMM$PageEEPROM$writeDone(result);
#line 488
      break;
      case PageEEPROMM$R_SYNC: case PageEEPROMM$R_SYNCALL: PageEEPROMM$PageEEPROM$syncDone(result);
#line 489
      break;
      case PageEEPROMM$R_FLUSH: case PageEEPROMM$R_FLUSHALL: PageEEPROMM$PageEEPROM$flushDone(result);
#line 490
      break;
      case PageEEPROMM$R_ERASE: PageEEPROMM$PageEEPROM$eraseDone(result);
#line 491
      break;
    }
}

static 
# 109 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/BlockStorageM.nc"
void BlockStorageM$signalDone(result_t result)
#line 109
{
  if (result == SUCCESS) {
    switch (BlockStorageM$state) 
      {
        case BlockStorageM$S_COMMIT: BlockStorageM$commitSignature();
#line 113
        break;
        case BlockStorageM$S_COMMIT2: BlockStorageM$commitSync();
#line 114
        break;
        case BlockStorageM$S_VERIFY: BlockStorageM$verifySignature();
#line 115
        break;
        case BlockStorageM$S_VERIFY2: 
          if (BlockStorageM$crc == (BlockStorageM$sig[0] | ((uint16_t )BlockStorageM$sig[1] << 8))) {
            BlockStorageM$actualSignal(STORAGE_OK);
            }
          else {
#line 120
            BlockStorageM$actualSignal(STORAGE_INVALID_CRC);
            }
#line 121
        break;
        default: TOS_post(BlockStorageM$signalSuccess);
#line 122
        break;
      }
    }
  else {
#line 125
    TOS_post(BlockStorageM$signalFail);
    }
}

static 
# 640 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/mica/PageEEPROMM.nc"
result_t PageEEPROMM$syncOrFlushAll(uint8_t newReq)
#line 640
{
  if (PageEEPROMM$request != PageEEPROMM$IDLE) {
    return FAIL;
    }
#line 643
  PageEEPROMM$request = newReq;

  if (PageEEPROMM$broken) 
    {
      TOS_post(PageEEPROMM$taskFail);
      return SUCCESS;
    }
  else {
#line 650
    if (! PageEEPROMM$buffer[0].clean) {
      PageEEPROMM$selected = 0;
      }
    else {
#line 652
      if (! PageEEPROMM$buffer[1].clean) {
        PageEEPROMM$selected = 1;
        }
      else {
          TOS_post(PageEEPROMM$taskSuccess);
          return SUCCESS;
        }
      }
    }
#line 660
  PageEEPROMM$buffer[PageEEPROMM$selected].unchecked = 0;
  PageEEPROMM$handleRWRequest();

  return SUCCESS;
}

static 
#line 391
void PageEEPROMM$handleRWRequest(void)
#line 391
{
  if (PageEEPROMM$reqPage == PageEEPROMM$buffer[PageEEPROMM$selected].page) {
    switch (PageEEPROMM$request) 
      {
        case PageEEPROMM$R_ERASE: 
          switch (PageEEPROMM$reqOffset) 
            {
              case TOS_EEPROM_ERASE: 
                PageEEPROMM$cmdPhase = PageEEPROMM$P_ERASE;
              PageEEPROMM$execCommand(TRUE, PageEEPROMM$C_ERASE_PAGE, 0, PageEEPROMM$reqPage, 0);
              break;
              case TOS_EEPROM_PREVIOUSLY_ERASED: 

                PageEEPROMM$buffer[PageEEPROMM$selected].erased = TRUE;

              case TOS_EEPROM_DONT_ERASE: 



                PageEEPROMM$buffer[PageEEPROMM$selected].clean = TRUE;
              PageEEPROMM$requestDone(SUCCESS);
              break;
            }
        break;

        case PageEEPROMM$R_SYNC: case PageEEPROMM$R_SYNCALL: 
            if (PageEEPROMM$buffer[PageEEPROMM$selected].clean && PageEEPROMM$buffer[PageEEPROMM$selected].unchecked) 
              {
                PageEEPROMM$checkBuffer(PageEEPROMM$selected);
                return;
              }

        case PageEEPROMM$R_FLUSH: case PageEEPROMM$R_FLUSHALL: 
            if (! PageEEPROMM$buffer[PageEEPROMM$selected].clean) {
              PageEEPROMM$flushBuffer();
              }
            else {
#line 426
              if (PageEEPROMM$request == PageEEPROMM$R_FLUSH || PageEEPROMM$request == PageEEPROMM$R_SYNC) {
                TOS_post(PageEEPROMM$taskSuccess);
                }
              else {

                  uint8_t oreq = PageEEPROMM$request;

                  PageEEPROMM$request = PageEEPROMM$IDLE;
                  PageEEPROMM$syncOrFlushAll(oreq);
                }
              }
#line 436
        break;

        case PageEEPROMM$R_READ: 
          PageEEPROMM$data = PageEEPROMM$reqBuf;
        PageEEPROMM$dataCount = PageEEPROMM$reqBytes;
        PageEEPROMM$cmdPhase = PageEEPROMM$P_READ;
        PageEEPROMM$execRWBuffer(PageEEPROMM$selected ? PageEEPROMM$C_READ_BUFFER1 : PageEEPROMM$C_READ_BUFFER2, 2, PageEEPROMM$reqOffset);
        break;

        case PageEEPROMM$R_READCRC: 
          PageEEPROMM$dataCount = PageEEPROMM$reqBytes;
        PageEEPROMM$cmdPhase = PageEEPROMM$P_READCRC;
        PageEEPROMM$execRWBuffer(PageEEPROMM$selected ? PageEEPROMM$C_READ_BUFFER1 : PageEEPROMM$C_READ_BUFFER2, 2, PageEEPROMM$reqOffset);
        break;

        case PageEEPROMM$R_WRITE: 
          PageEEPROMM$data = PageEEPROMM$reqBuf;
        PageEEPROMM$dataCount = PageEEPROMM$reqBytes;
        PageEEPROMM$cmdPhase = PageEEPROMM$P_WRITE;
        PageEEPROMM$buffer[PageEEPROMM$selected].clean = FALSE;
        PageEEPROMM$buffer[PageEEPROMM$selected].unchecked = 0;
        PageEEPROMM$execRWBuffer(PageEEPROMM$selected ? PageEEPROMM$C_WRITE_BUFFER1 : PageEEPROMM$C_WRITE_BUFFER2, 0, PageEEPROMM$reqOffset);
        break;
      }
    }
  else {
#line 460
    if (! PageEEPROMM$buffer[PageEEPROMM$selected].clean) {
      PageEEPROMM$flushBuffer();
      }
    else {
#line 462
      if (PageEEPROMM$buffer[PageEEPROMM$selected].unchecked) {
        PageEEPROMM$checkBuffer(PageEEPROMM$selected);
        }
      else {

          if (PageEEPROMM$request == PageEEPROMM$R_ERASE) 
            {
              PageEEPROMM$buffer[PageEEPROMM$selected].page = PageEEPROMM$reqPage;
              PageEEPROMM$handleRWRequest();
            }
          else 
            {
              PageEEPROMM$cmdPhase = PageEEPROMM$P_FILL;
              PageEEPROMM$execCommand(TRUE, PageEEPROMM$selected ? PageEEPROMM$C_FILL_BUFFER1 : PageEEPROMM$C_FILL_BUFFER2, 0, PageEEPROMM$reqPage, 0);
            }
        }
      }
    }
}

static 
#line 370
void PageEEPROMM$execCommand(bool wait, uint8_t reqCmd, uint8_t dontCare, 
eeprompage_t page, eeprompageoffset_t offset)
#line 371
{

  PageEEPROMM$cmd[0] = reqCmd;
  PageEEPROMM$cmd[1] = page >> 7;
  PageEEPROMM$cmd[2] = (page << 1) | (offset >> 8);
  PageEEPROMM$cmd[3] = offset;
  PageEEPROMM$cmdCount = 4 + dontCare;

  if (wait && PageEEPROMM$flashBusy) {
    PageEEPROMM$requestFlashStatus();
    }
  else {
#line 382
    PageEEPROMM$sendFlashCommand();
    }
}

static 
#line 174
void PageEEPROMM$requestFlashStatus(void)
#line 174
{
  PageEEPROMM$waiting = TRUE;
  PageEEPROMM$selectFlash();

  ;
  PageEEPROMM$FlashSPI$txByte(PageEEPROMM$C_REQ_STATUS);
  if (PageEEPROMM$FlashIdle$wait() == FAIL) {
    PageEEPROMM$FlashIdle$available();
    }
}

static   
# 113 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/mica2/HPLFlash.nc"
uint8_t HPLFlash$FlashSPI$txByte(uint8_t spiOut)
#line 113
{
  uint8_t spiIn = 0;


  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
    {
      uint8_t clrClkAndData = * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x12 + 0x20) & ~0x28;

      * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x12 + 0x20) = clrClkAndData;
#line 121
       __asm volatile ("sbrc %2,""7""\n""\tsbi 18,3\n""\tsbi 18,5\n""\tsbic 16,2\n""\tori %0,1<<""7""\n" : "=d"(spiIn) : "0"(spiIn), "r"(spiOut));
      * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x12 + 0x20) = clrClkAndData;
#line 122
       __asm volatile ("sbrc %2,""6""\n""\tsbi 18,3\n""\tsbi 18,5\n""\tsbic 16,2\n""\tori %0,1<<""6""\n" : "=d"(spiIn) : "0"(spiIn), "r"(spiOut));
      * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x12 + 0x20) = clrClkAndData;
#line 123
       __asm volatile ("sbrc %2,""5""\n""\tsbi 18,3\n""\tsbi 18,5\n""\tsbic 16,2\n""\tori %0,1<<""5""\n" : "=d"(spiIn) : "0"(spiIn), "r"(spiOut));
      * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x12 + 0x20) = clrClkAndData;
#line 124
       __asm volatile ("sbrc %2,""4""\n""\tsbi 18,3\n""\tsbi 18,5\n""\tsbic 16,2\n""\tori %0,1<<""4""\n" : "=d"(spiIn) : "0"(spiIn), "r"(spiOut));
      * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x12 + 0x20) = clrClkAndData;
#line 125
       __asm volatile ("sbrc %2,""3""\n""\tsbi 18,3\n""\tsbi 18,5\n""\tsbic 16,2\n""\tori %0,1<<""3""\n" : "=d"(spiIn) : "0"(spiIn), "r"(spiOut));
      * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x12 + 0x20) = clrClkAndData;
#line 126
       __asm volatile ("sbrc %2,""2""\n""\tsbi 18,3\n""\tsbi 18,5\n""\tsbic 16,2\n""\tori %0,1<<""2""\n" : "=d"(spiIn) : "0"(spiIn), "r"(spiOut));
      * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x12 + 0x20) = clrClkAndData;
#line 127
       __asm volatile ("sbrc %2,""1""\n""\tsbi 18,3\n""\tsbi 18,5\n""\tsbic 16,2\n""\tori %0,1<<""1""\n" : "=d"(spiIn) : "0"(spiIn), "r"(spiOut));
      * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x12 + 0x20) = clrClkAndData;
#line 128
       __asm volatile ("sbrc %2,""0""\n""\tsbi 18,3\n""\tsbi 18,5\n""\tsbic 16,2\n""\tori %0,1<<""0""\n" : "=d"(spiIn) : "0"(spiIn), "r"(spiOut));}
#line 128
    __nesc_atomic_end(__nesc_atomic); }


  return spiIn;
}

static 
# 278 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/mica/PageEEPROMM.nc"
void PageEEPROMM$flashCommandComplete(void)
#line 278
{
  if (PageEEPROMM$waiting) 
    {
      PageEEPROMM$waiting = PageEEPROMM$flashBusy = PageEEPROMM$buffer[0].busy = PageEEPROMM$buffer[1].busy = FALSE;

      if (PageEEPROMM$cmdPhase == PageEEPROMM$P_COMPARE_CHECK) 
        {
          if (PageEEPROMM$compareOk) {
            PageEEPROMM$buffer[PageEEPROMM$checking].unchecked = 0;
            }
          else {
#line 287
            if (PageEEPROMM$buffer[PageEEPROMM$checking].unchecked < 2) {
              PageEEPROMM$buffer[PageEEPROMM$checking].clean = FALSE;
              }
            else {
                PageEEPROMM$broken = TRUE;
                PageEEPROMM$requestDone(FAIL);
                return;
              }
            }
#line 295
          PageEEPROMM$handleRWRequest();
        }
      else 
        {


          if ((PageEEPROMM$buffer[0].unchecked || PageEEPROMM$buffer[1].unchecked) && 
          !(PageEEPROMM$cmdPhase == PageEEPROMM$P_COMPARE || PageEEPROMM$cmdPhase == PageEEPROMM$P_COMPARE_CHECK)) {
            PageEEPROMM$checkBuffer(PageEEPROMM$buffer[0].unchecked ? 0 : 1);
            }
          else {
            PageEEPROMM$sendFlashCommand();
            }
        }
#line 308
      return;
    }
  switch (PageEEPROMM$cmdPhase) 
    {
      default: 
        PageEEPROMM$requestDone(FAIL);
      break;

      case PageEEPROMM$P_READ: case PageEEPROMM$P_READCRC: case PageEEPROMM$P_WRITE: 
            PageEEPROMM$requestDone(SUCCESS);
      break;

      case PageEEPROMM$P_FLUSH: 
        PageEEPROMM$flashBusy = TRUE;
      PageEEPROMM$buffer[PageEEPROMM$selected].clean = PageEEPROMM$buffer[PageEEPROMM$selected].busy = TRUE;
      PageEEPROMM$buffer[PageEEPROMM$selected].unchecked++;
      PageEEPROMM$buffer[PageEEPROMM$selected].erased = FALSE;
      PageEEPROMM$handleRWRequest();
      break;

      case PageEEPROMM$P_COMPARE: 
        PageEEPROMM$cmdPhase = PageEEPROMM$P_COMPARE_CHECK;
      PageEEPROMM$flashBusy = TRUE;
      PageEEPROMM$buffer[PageEEPROMM$checking].busy = TRUE;




      TOSH_uwait(10);
      PageEEPROMM$requestFlashStatus();
      break;

      case PageEEPROMM$P_FILL: 
        PageEEPROMM$flashBusy = TRUE;
      PageEEPROMM$buffer[PageEEPROMM$selected].page = PageEEPROMM$reqPage;
      PageEEPROMM$buffer[PageEEPROMM$selected].clean = PageEEPROMM$buffer[PageEEPROMM$selected].busy = TRUE;
      PageEEPROMM$buffer[PageEEPROMM$selected].erased = FALSE;
      PageEEPROMM$handleRWRequest();
      break;

      case PageEEPROMM$P_ERASE: 
        PageEEPROMM$flashBusy = TRUE;



      PageEEPROMM$buffer[PageEEPROMM$selected].page = PageEEPROMM$reqPage;
      PageEEPROMM$buffer[PageEEPROMM$selected].clean = TRUE;
      PageEEPROMM$buffer[PageEEPROMM$selected].erased = TRUE;
      PageEEPROMM$requestDone(SUCCESS);
      break;
    }
}

static 
#line 263
void PageEEPROMM$checkBuffer(uint8_t buf)
#line 263
{
  PageEEPROMM$cmdPhase = PageEEPROMM$P_COMPARE;
  PageEEPROMM$checking = buf;
  PageEEPROMM$execCommand(TRUE, buf ? PageEEPROMM$C_COMPARE_BUFFER1 : PageEEPROMM$C_COMPARE_BUFFER2, 0, 
  PageEEPROMM$buffer[buf].page, 0);
}

static 
#line 184
void PageEEPROMM$sendFlashCommand(void)
#line 184
{
  uint8_t in = 0;
#line 185
  uint8_t out = 0;
  uint8_t *ptr = PageEEPROMM$cmd;
  eeprompageoffset_t count = PageEEPROMM$cmdCount;
  uint16_t crc = PageEEPROMM$computedCrc;
  uint8_t lphase = PageEEPROMM$P_SEND_CMD;







  ;

  PageEEPROMM$selectFlash();

  for (; ; ) 
    {
      if (lphase == PageEEPROMM$P_READCRC) 
        {
          crc = crcByte(crc, in);

          --count;
          if (!count) 
            {
              PageEEPROMM$computedCrc = crc;
              break;
            }
        }
      else {
#line 214
        if (lphase == PageEEPROMM$P_SEND_CMD) 
          {
            out = * ptr++;
            count--;
            if (!count) 
              {
                lphase = PageEEPROMM$cmdPhase;
                ptr = PageEEPROMM$data;
                count = PageEEPROMM$dataCount;
              }
          }
        else {
#line 225
          if (lphase == PageEEPROMM$P_READ) 
            {
              * ptr++ = in;
              --count;
              if (!count) {
                break;
                }
            }
          else {
#line 232
            if (lphase == PageEEPROMM$P_WRITE) 
              {
                if (!count) {
                  break;
                  }
                out = * ptr++;
                --count;
              }
            else {
              break;
              }
            }
          }
        }
#line 243
      in = PageEEPROMM$FlashSPI$txByte(out);
    }

  PageEEPROMM$requestDeselect();
}

static 
#line 270
void PageEEPROMM$flushBuffer(void)
#line 270
{
  PageEEPROMM$cmdPhase = PageEEPROMM$P_FLUSH;
  PageEEPROMM$execCommand(TRUE, PageEEPROMM$buffer[PageEEPROMM$selected].erased ? 
  PageEEPROMM$selected ? PageEEPROMM$C_QFLUSH_BUFFER1 : PageEEPROMM$C_QFLUSH_BUFFER2 : 
  PageEEPROMM$selected ? PageEEPROMM$C_FLUSH_BUFFER1 : PageEEPROMM$C_FLUSH_BUFFER2, 0, 
  PageEEPROMM$buffer[PageEEPROMM$selected].page, 0);
}

static 
#line 538
result_t PageEEPROMM$computeCrc(eeprompage_t page, eeprompageoffset_t offset, 
eeprompageoffset_t n, uint16_t crc)
#line 539
{

  if (n == 0) 
    {
      PageEEPROMM$request = PageEEPROMM$R_READCRC;
      PageEEPROMM$computedCrc = crc;
      TOS_post(PageEEPROMM$taskSuccess);
      return SUCCESS;
    }
  else {
    return PageEEPROMM$newRequest(PageEEPROMM$R_READCRC, page, offset, (void *)0, n, crc);
    }
}

static 
# 63 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/StorageManagerM.nc"
void StorageManagerM$checkNextVolume(void)
#line 63
{
  if (StorageManagerM$f.invalid || StorageManagerM$nextVolume == StorageManagerM$header.nvolumes) 
    {
      StorageManagerM$volumes[StorageManagerM$client].id = INVALID_VOLUME_ID;
      StorageManagerM$mountComplete(STORAGE_FAIL);
    }
  else {
    StorageManagerM$check(StorageManagerM$PageEEPROM$read(VOLUME_TABLE_PAGE, sizeof(struct volume_definition_header_t ) + 
    StorageManagerM$nextVolume++ * sizeof(struct volume_definition_t ), 
    &StorageManagerM$volumes[StorageManagerM$client], sizeof StorageManagerM$volumes[StorageManagerM$client]));
    }
}

static 
# 150 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/DelugeMetadataM.nc"
void DelugeMetadataM$verifyNextPage(void)
#line 150
{
  if (DelugeMetadataM$DataRead$verify(DelugeMetadataM$curImage, DelugeMetadataM$imgDesc[DelugeMetadataM$curImage].numPgsComplete) == FAIL) {
    DelugeMetadataM$Timer$start(TIMER_ONE_SHOT, 512);
    }
}

static 
# 117 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/DelugeM.nc"
void DelugeM$checkReboot(void)
#line 117
{
  DelugeImgDesc *imgDesc = DelugeM$Metadata$getImgDesc(DelugeM$nodeDesc.imgNum);


  if (
#line 119
  DelugeM$nodeDesc.uid == imgDesc->uid
   && imgDesc->numPgsComplete == imgDesc->numPgs
   && imgDesc->numPgs) {
    DelugeM$rebootDelay = DELUGE_REBOOT_DELAY;
    }
}

static 
#line 125
void DelugeM$setNextPage(void)
#line 125
{

  DelugeImgDesc *imgDesc;
  int i;

  for (i = 0; i < 3; i++) {
      imgDesc = DelugeM$Metadata$getImgDesc(i);
      if (imgDesc->numPgs != imgDesc->numPgsComplete) {
          DelugeM$PageTransfer$setWorkingPage(i, imgDesc->numPgsComplete);
          DelugeM$advTimers[i].newAdvs = DELUGE_NUM_NEWDATA_ADVS_REQUIRED;
          DelugeM$advTimers[i].overheard = 0;
          DelugeM$resetTimer(i);
          DelugeM$Leds$redOff();
          return;
        }
    }

  DelugeM$Leds$redOn();
  DelugeM$PageTransfer$setWorkingPage(DELUGE_INVALID_IMGNUM, DELUGE_INVALID_PGNUM);
}

static 
#line 109
void DelugeM$resetTimer(int i)
#line 109
{
  if (i < 3 && 
  DelugeM$advTimers[i].periodLog2 != DELUGE_MIN_ADV_PERIOD_LOG2) {
      DelugeM$advTimers[i].periodLog2 = DELUGE_MIN_ADV_PERIOD_LOG2;
      DelugeM$setupAdvTimer(i);
    }
}

static 
#line 86
void DelugeM$setupAdvTimer(int timerNum)
#line 86
{

  int minTimer;

  DelugeM$advTimers[timerNum].timer = (uint32_t )0x1 << (DelugeM$advTimers[timerNum].periodLog2 - 1);
  DelugeM$advTimers[timerNum].timer += DelugeM$Random$rand() & (DelugeM$advTimers[timerNum].timer - 1);
  DelugeM$advTimers[timerNum].overheard = 0;

  minTimer = DelugeM$findMinTimer();

  DelugeM$Timer$stop();
  DelugeM$Timer$start(TIMER_ONE_SHOT, DelugeM$advTimers[minTimer].timer);
}

static   
# 70 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/system/RandomLFSR.nc"
uint16_t RandomLFSR$Random$rand(void)
#line 70
{
  bool endbit;
  uint16_t tmpShiftReg;

#line 73
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 73
    {
      tmpShiftReg = RandomLFSR$shiftReg;
      endbit = (tmpShiftReg & 0x8000) != 0;
      tmpShiftReg <<= 1;
      if (endbit) {
        tmpShiftReg ^= 0x100b;
        }
#line 79
      tmpShiftReg++;
      RandomLFSR$shiftReg = tmpShiftReg;
      tmpShiftReg = tmpShiftReg ^ RandomLFSR$mask;
    }
#line 82
    __nesc_atomic_end(__nesc_atomic); }
  return tmpShiftReg;
}

static 
# 72 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/DelugeM.nc"
int DelugeM$findMinTimer(void)
#line 72
{

  int minTimer = 0;
  int i;

  for (i = 1; i < DelugeM$DELUGE_NUM_TIMERS; i++) {
      if (DelugeM$advTimers[i].timer < DelugeM$advTimers[minTimer].timer) {
        minTimer = i;
        }
    }
  return minTimer;
}

static  
# 168 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/system/TimerM.nc"
result_t TimerM$Timer$stop(uint8_t id)
#line 168
{

  if (id >= NUM_TIMERS) {
#line 170
    return FAIL;
    }
#line 171
  if (TimerM$mState & (0x1L << id)) {
      { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 172
        TimerM$mState &= ~(0x1L << id);
#line 172
        __nesc_atomic_end(__nesc_atomic); }
      if (!TimerM$mState) {
          TimerM$setIntervalFlag = 1;
        }
      return SUCCESS;
    }
  return FAIL;
}

static 
# 160 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/DelugeM.nc"
void DelugeM$realStart(void)
#line 160
{

  int i;

  DelugeM$setNextPage();
  DelugeM$PageTransferControl$start();

  for (i = 1; i < DelugeM$DELUGE_NUM_TIMERS; i++) 
    DelugeM$resetTimer(i);
}

static  
# 179 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/system/AMStandard.nc"
result_t AMStandard$SendMsg$send(uint8_t id, uint16_t addr, uint8_t length, TOS_MsgPtr data)
#line 179
{
  if (!AMStandard$state) {
      AMStandard$state = TRUE;
      if (length > DATA_LENGTH) {
          {
          }
#line 183
          ;
          AMStandard$state = FALSE;
          return FAIL;
        }
      if (!TOS_post(AMStandard$sendTask)) {
          {
          }
#line 188
          ;
          AMStandard$state = FALSE;
          return FAIL;
        }
      else {
          AMStandard$buffer = data;
          data->length = length;
          data->addr = addr;
          data->type = id;
          AMStandard$buffer->group = TOS_AM_GROUP;
          {
          }
#line 198
          ;
          AMStandard$dbgPacket(data);
        }
      return SUCCESS;
    }

  return FAIL;
}

static 
# 184 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/micaz/FramerM.nc"
result_t FramerM$StartTx(void)
#line 184
{
  result_t Result = SUCCESS;
  bool fInitiate = FALSE;

  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 188
    {
      if (FramerM$gTxState == FramerM$TXSTATE_IDLE) {
          if (FramerM$gFlags & FramerM$FLAGS_TOKENPEND) {

              FramerM$gpTxBuf = (uint8_t *)&FramerM$gTxTokenBuf;




              FramerM$gTxProto = FramerM$PROTO_ACK;
              FramerM$gTxLength = sizeof FramerM$gTxTokenBuf;
              fInitiate = TRUE;
              FramerM$gTxState = FramerM$TXSTATE_PROTO;
            }
          else {
#line 202
            if (FramerM$gFlags & FramerM$FLAGS_DATAPEND) {
                FramerM$gpTxBuf = (uint8_t *)FramerM$gpTxMsg;
                FramerM$gTxProto = FramerM$PROTO_PACKET_NOACK;


                FramerM$gTxLength = FramerM$gpTxMsg->length + TOS_HEADER_SIZE + 2 + 3;



                fInitiate = TRUE;
                FramerM$gTxState = FramerM$TXSTATE_PROTO;
              }
            else {
#line 214
              if (FramerM$gFlags & FramerM$FLAGS_UNKNOWN) {
                  FramerM$gpTxBuf = (uint8_t *)&FramerM$gTxUnknownBuf;
                  FramerM$gTxProto = FramerM$PROTO_UNKNOWN;
                  FramerM$gTxLength = sizeof FramerM$gTxUnknownBuf;
                  fInitiate = TRUE;
                  FramerM$gTxState = FramerM$TXSTATE_PROTO;
                }
              }
            }
        }
    }
#line 224
    __nesc_atomic_end(__nesc_atomic); }
#line 224
  if (fInitiate) {
      { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 225
        {

          FramerM$gTxRunningCRC = 0;
          FramerM$gTxByteCnt = (size_t )& ((struct TOS_Msg *)0)->addr;
        }
#line 229
        __nesc_atomic_end(__nesc_atomic); }




      Result = FramerM$ByteComm$txByte(FramerM$HDLC_FLAG_BYTE);
      if (Result != SUCCESS) {
          { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 236
            FramerM$gTxState = FramerM$TXSTATE_ERROR;
#line 236
            __nesc_atomic_end(__nesc_atomic); }
          TOS_post(FramerM$PacketSent);
        }
    }

  return Result;
}

static   
# 110 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/system/UARTM.nc"
result_t UARTM$ByteComm$txByte(uint8_t data)
#line 110
{
  bool oldState;

  {
  }
#line 113
  ;

  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 115
    {
      oldState = UARTM$state;
      UARTM$state = TRUE;
    }
#line 118
    __nesc_atomic_end(__nesc_atomic); }
  if (oldState) {
    return FAIL;
    }
  UARTM$HPLUART$put(data);

  return SUCCESS;
}

static  
# 291 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/micaz/FramerM.nc"
void FramerM$PacketSent(void)
#line 291
{
  result_t TxResult = SUCCESS;

  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 294
    {
      if (FramerM$gTxState == FramerM$TXSTATE_ERROR) {
          TxResult = FAIL;
          FramerM$gTxState = FramerM$TXSTATE_IDLE;
        }
    }
#line 299
    __nesc_atomic_end(__nesc_atomic); }
  if (FramerM$gTxProto == FramerM$PROTO_ACK) {
      { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 301
        FramerM$gFlags ^= FramerM$FLAGS_TOKENPEND;
#line 301
        __nesc_atomic_end(__nesc_atomic); }
    }
  else {
      { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 304
        FramerM$gFlags ^= FramerM$FLAGS_DATAPEND;
#line 304
        __nesc_atomic_end(__nesc_atomic); }
      FramerM$BareSendMsg$sendDone((TOS_MsgPtr )FramerM$gpTxMsg, TxResult);
      { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 306
        FramerM$gpTxMsg = (void *)0;
#line 306
        __nesc_atomic_end(__nesc_atomic); }
    }


  FramerM$StartTx();
}

static 
# 143 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/system/AMStandard.nc"
result_t AMStandard$reportSendDone(TOS_MsgPtr msg, result_t success)
#line 143
{
  AMStandard$state = FALSE;
  AMStandard$SendMsg$sendDone(msg->type, msg, success);
  AMStandard$sendDone();

  return SUCCESS;
}

static 
# 118 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/DelugePageTransferM.nc"
void DelugePageTransferM$startReqTimer(bool first)
#line 118
{
  uint32_t delay;

#line 120
  if (first) {
    delay = DELUGE_MIN_DELAY + DelugePageTransferM$Random$rand() % DELUGE_MAX_REQ_DELAY;
    }
  else {
#line 123
    delay = DELUGE_NACK_TIMEOUT + DelugePageTransferM$Random$rand() % DELUGE_NACK_TIMEOUT;
    }
#line 124
  DelugePageTransferM$Timer$start(TIMER_ONE_SHOT, delay);
}

static   
# 61 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/micaz/TimerJiffyAsyncM.nc"
result_t TimerJiffyAsyncM$TimerJiffyAsync$setOneShot(uint32_t _jiffy)
{
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 63
    {
      TimerJiffyAsyncM$jiffy = _jiffy;
      TimerJiffyAsyncM$bSet = TRUE;
    }
#line 66
    __nesc_atomic_end(__nesc_atomic); }
  if (_jiffy > 0xFF) {
      TimerJiffyAsyncM$Timer$setIntervalAndScale(0xFF, 0x4);
    }
  else {
      TimerJiffyAsyncM$Timer$setIntervalAndScale(_jiffy, 0x4);
    }
  return SUCCESS;
}

static   
# 118 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/micaz/HPLTimer2.nc"
result_t HPLTimer2$Timer2$setIntervalAndScale(uint8_t interval, uint8_t scale)
#line 118
{

  if (scale > 7) {
#line 120
    return FAIL;
    }
#line 121
  scale |= 0x8;
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 122
    {
      * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x25 + 0x20) = 0;
      * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x37 + 0x20) &= ~(1 << 7);
      * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x37 + 0x20) &= ~(1 << 6);
      HPLTimer2$mscale = scale;
      HPLTimer2$minterval = interval;
      * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x24 + 0x20) = 0;
      * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x23 + 0x20) = interval;
      * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x36 + 0x20) |= 1 << 7;
      * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x37 + 0x20) |= 1 << 7;
      * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x25 + 0x20) = scale;
    }
#line 133
    __nesc_atomic_end(__nesc_atomic); }
  return SUCCESS;
}

static 
# 190 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/DelugePageTransferM.nc"
void DelugePageTransferM$writeData(void)
#line 190
{

  if (
#line 191
  DelugePageTransferM$DataWrite$write(DelugePageTransferM$workingImgNum, DelugePageTransferM$calcOffset(DelugePageTransferM$rxQueue[DelugePageTransferM$head].pgNum, DelugePageTransferM$rxQueue[DelugePageTransferM$head].pktNum), 
  DelugePageTransferM$rxQueue[DelugePageTransferM$head].data, DELUGE_PKT_PAYLOAD_SIZE) == FAIL) {
    DelugePageTransferM$size = 0;
    }
}

static  
# 190 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Flash/AT45DB/BlockStorageM.nc"
result_t BlockStorageM$BlockWrite$write(uint8_t id, block_addr_t addr, void *buf, block_addr_t len)
#line 190
{
  result_t ok = BlockStorageM$newRequest(BlockStorageM$S_WRITE, id, addr, buf, len);

  if (ok && addr + len > BlockStorageM$maxAddr[id]) {
    BlockStorageM$maxAddr[id] = addr + len;
    }
  return ok;
}

static  result_t BlockStorageM$BlockWrite$erase(uint8_t id)
#line 199
{
  if (BlockStorageM$admitRequest(BlockStorageM$S_ERASE, id) == FAIL) {
    return FAIL;
    }
  BlockStorageM$check(BlockStorageM$PageEEPROM$erase(BlockStorageM$client, 0, AT45_ERASE));

  return SUCCESS;
}

static 
# 150 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/DelugePageTransferM.nc"
void DelugePageTransferM$setupReqMsg(void)
#line 150
{

  TOS_MsgPtr pMsgBuf = DelugePageTransferM$SharedMsgBuf$getMsgBuf();
  DelugeReqMsg *pReqMsg = (DelugeReqMsg *)pMsgBuf->data;

  if (DelugePageTransferM$state == DelugePageTransferM$S_RX_LOCKING) {
      if (DelugePageTransferM$SharedMsgBuf$isLocked()) {
        return;
        }
#line 158
      DelugePageTransferM$SharedMsgBuf$lock();
      DelugePageTransferM$changeState(DelugePageTransferM$S_RECEIVING);
      pReqMsg->dest = DelugePageTransferM$nodeAddr != TOS_UART_ADDR ? DelugePageTransferM$nodeAddr : TOS_UART_ADDR;
      pReqMsg->sourceAddr = TOS_LOCAL_ADDRESS;
      pReqMsg->imgNum = DelugePageTransferM$workingImgNum;
      pReqMsg->vNum = DelugePageTransferM$DelugeStats$getVNum(DelugePageTransferM$workingImgNum);
      pReqMsg->pgNum = DelugePageTransferM$workingPgNum;
    }

  if (DelugePageTransferM$state != DelugePageTransferM$S_RECEIVING) {
    return;
    }

  if (DelugePageTransferM$suppressReq) {
      DelugePageTransferM$startReqTimer(FALSE);
      DelugePageTransferM$suppressReq = FALSE;
    }
  else {

    if (DelugePageTransferM$remainingAttempts == 0) {
        DelugePageTransferM$changeState(DelugePageTransferM$S_IDLE);
      }
    else 

      {
        nmemcpy(pReqMsg->requestedPkts, DelugePageTransferM$pktsToReceive, DELUGE_PKT_BITVEC_SIZE);
        if (DelugePageTransferM$SendReqMsg$send(pReqMsg->dest, sizeof(DelugeReqMsg ), pMsgBuf) == FAIL) {
          DelugePageTransferM$startReqTimer(FALSE);
          }
      }
    }
}

static 
# 149 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/system/tos.h"
void *nmemcpy(void *to, const void *from, size_t n)
{
  char *cto = to;
  const char *cfrom = from;

  while (n--) * cto++ = * cfrom++;

  return to;
}

static  
# 87 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/system/AMStandard.nc"
bool AMStandard$Control$init(void)
#line 87
{
  result_t ok1;
#line 88
  result_t ok2;

  AMStandard$TimerControl$init();
  ok1 = AMStandard$UARTControl$init();
  ok2 = AMStandard$RadioControl$init();

  AMStandard$state = FALSE;
  AMStandard$lastCount = 0;
  AMStandard$counter = 0;
  {
  }
#line 97
  ;

  return rcombine(ok1, ok2);
}

static 
# 313 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/micaz/FramerM.nc"
void FramerM$HDLCInitialize(void)
#line 313
{
  int i;

#line 315
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 315
    {
      for (i = 0; i < FramerM$HDLC_QUEUESIZE; i++) {
          FramerM$gMsgRcvTbl[i].pMsg = &FramerM$gMsgRcvBuf[i];
          FramerM$gMsgRcvTbl[i].Length = 0;
          FramerM$gMsgRcvTbl[i].Token = 0;
        }
      FramerM$gTxState = FramerM$TXSTATE_IDLE;
      FramerM$gTxByteCnt = 0;
      FramerM$gTxLength = 0;
      FramerM$gTxRunningCRC = 0;
      FramerM$gpTxMsg = (void *)0;

      FramerM$gRxState = FramerM$RXSTATE_NOSYNC;
      FramerM$gRxHeadIndex = 0;
      FramerM$gRxTailIndex = 0;
      FramerM$gRxByteCnt = 0;
      FramerM$gRxRunningCRC = 0;
      FramerM$gpRxBuf = (uint8_t *)FramerM$gMsgRcvTbl[FramerM$gRxHeadIndex].pMsg;
    }
#line 333
    __nesc_atomic_end(__nesc_atomic); }
}

static 
# 53 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/NetProgM.nc"
void NetProgM$writeTOSinfo(void)
#line 53
{
  NetProg_TOSInfo tosInfo;
  uint16_t crc;

#line 56
  NetProgM$IFlash$read((uint8_t *)IFLASH_TOS_INFO_ADDR, &tosInfo, sizeof tosInfo);
  tosInfo.addr = TOS_LOCAL_ADDRESS;
  tosInfo.groupId = TOS_AM_GROUP;
  crc = NetProgM$computeTosInfoCrc(&tosInfo);

  if (tosInfo.crc == crc) {
    return;
    }
#line 63
  tosInfo.crc = crc;
  NetProgM$IFlash$write((uint8_t *)IFLASH_TOS_INFO_ADDR, &tosInfo, sizeof tosInfo);
}

static  
# 49 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/avrmote/InternalFlashC.nc"
result_t InternalFlashC$InternalFlash$write(void *addr, void *buf, uint16_t size)
#line 49
{

  uint8_t *addrPtr = (uint8_t *)addr;
  uint8_t *bufPtr = (uint8_t *)buf;
  uint16_t i;

  if ((uint16_t )addr < InternalFlashC$IFLASH_BOUND_LOW || InternalFlashC$IFLASH_BOUND_HIGH + 2 <= (uint16_t )addr + size) {
    return FAIL;
    }
  for (i = 0; i < size; i++) {
      eeprom_write_byte(addrPtr, *bufPtr);
      addrPtr++;
      bufPtr++;
    }

  while (! !(* (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x1C + 0x20) & (1 << 1))) ;

  return SUCCESS;
}

static   
# 96 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/avrmote/HPLADCC.nc"
result_t HPLADCC$ADC$bindPort(uint8_t port, uint8_t adcPort)
#line 96
{
  if (port < HPLADCC$TOSH_ADC_PORTMAPSIZE) 
    {
      { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 99
        {
          HPLADCC$init_portmap();
          HPLADCC$TOSH_adc_portmap[port] = adcPort;
        }
#line 102
        __nesc_atomic_end(__nesc_atomic); }
      return SUCCESS;
    }
  else {
    return FAIL;
    }
}

static 
#line 64
void HPLADCC$init_portmap(void)
#line 64
{

  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 66
    {
      if (HPLADCC$init_portmap_done == FALSE) {
          int i;

#line 69
          for (i = 0; i < HPLADCC$TOSH_ADC_PORTMAPSIZE; i++) 
            HPLADCC$TOSH_adc_portmap[i] = i;
          HPLADCC$init_portmap_done = TRUE;
        }
    }
#line 73
    __nesc_atomic_end(__nesc_atomic); }
}

static   result_t HPLADCC$ADC$init(void)
#line 76
{
  HPLADCC$init_portmap();

  * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x06 + 0x20) = 0x04;

  * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x06 + 0x20) &= ~(1 << 6);
  * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x06 + 0x20) |= 1 << 4;
  * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x06 + 0x20) |= 1 << 3;
  * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x06 + 0x20) &= ~(1 << 7);

  return SUCCESS;
}

static  
# 103 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/system/AMStandard.nc"
bool AMStandard$Control$start(void)
#line 103
{
  result_t ok0 = AMStandard$TimerControl$start();
  result_t ok1 = AMStandard$UARTControl$start();
  result_t ok2 = AMStandard$RadioControl$start();
  result_t ok3 = AMStandard$ActivityTimer$start(TIMER_REPEAT, 1000);



  AMStandard$state = FALSE;

  AMStandard$PowerManagement$adjustPower();

  return rcombine4(ok0, ok1, ok2, ok3);
}

static   
# 128 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/micaz/HPLCC2420M.nc"
result_t HPLCC2420M$HPLCC2420$write(uint8_t addr, uint16_t data)
#line 128
{
  uint8_t status;



  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 133
    {
      HPLCC2420M$bSpiAvail = FALSE;
      TOSH_CLR_CC_CS_PIN();
      * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x0F + 0x20) = addr;
      while (!(* (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x0E + 0x20) & 0x80)) {
        }
#line 137
      ;
      status = * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x0F + 0x20);
      if (addr > 0x0E) {
          * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x0F + 0x20) = data >> 8;
          while (!(* (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x0E + 0x20) & 0x80)) {
            }
#line 141
          ;
          * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x0F + 0x20) = data & 0xff;
          while (!(* (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x0E + 0x20) & 0x80)) {
            }
#line 143
          ;
        }
      HPLCC2420M$bSpiAvail = TRUE;
    }
#line 146
    __nesc_atomic_end(__nesc_atomic); }
  TOSH_SET_CC_CS_PIN();
  return status;
}

static   
#line 103
uint8_t HPLCC2420M$HPLCC2420$cmd(uint8_t addr)
#line 103
{
  uint8_t status;

  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 106
    {
      TOSH_CLR_CC_CS_PIN();
      * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x0F + 0x20) = addr;
      while (!(* (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x0E + 0x20) & 0x80)) {
        }
#line 109
      ;
      status = * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x0F + 0x20);
    }
#line 111
    __nesc_atomic_end(__nesc_atomic); }
  TOSH_SET_CC_CS_PIN();
  return status;
}

# 167 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/mica/HPLClock.nc"
void __attribute((interrupt))   __vector_15(void)
#line 167
{
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 168
    {
      if (HPLClock$set_flag) {
          HPLClock$mscale = HPLClock$nextScale;
          HPLClock$nextScale |= 0x8;
          * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x33 + 0x20) = HPLClock$nextScale;

          * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x31 + 0x20) = HPLClock$minterval;
          HPLClock$set_flag = 0;
        }
    }
#line 177
    __nesc_atomic_end(__nesc_atomic); }
  HPLClock$Clock$fire();
}

static   
# 109 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/avrmote/HPLADCC.nc"
result_t HPLADCC$ADC$samplePort(uint8_t port)
#line 109
{
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 110
    {
      * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x07 + 0x20) = HPLADCC$TOSH_adc_portmap[port];
      if (HPLADCC$TOSH_adc_portmap[port] == 8 && port == 8) {
        TOSH_SET_PW2_PIN();
        }
#line 114
      * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x06 + 0x20) |= 1 << 7;
      * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x06 + 0x20) |= 1 << 6;
    }
#line 116
    __nesc_atomic_end(__nesc_atomic); }
  return SUCCESS;
}

static  
# 183 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/sensorboards/micasb/PhotoTempM.nc"
void PhotoTempM$getSample(void)
#line 183
{
  static bool photoIsNext;
  bool isDone;

#line 186
  isDone = FALSE;
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 187
    {
      if (PhotoTempM$waitingForSample) {


          isDone = TRUE;
        }
#line 192
      ;
      if (PhotoTempM$photoSensor == PhotoTempM$stateIdle && PhotoTempM$tempSensor == PhotoTempM$stateIdle) {

          isDone = TRUE;
        }
#line 196
      ;


      if (PhotoTempM$photoSensor == PhotoTempM$stateIdle) {
#line 199
        photoIsNext = FALSE;
        }
#line 200
      if (PhotoTempM$tempSensor == PhotoTempM$stateIdle) {
#line 200
        photoIsNext = TRUE;
        }
    }
#line 202
    __nesc_atomic_end(__nesc_atomic); }
#line 201
  ;
  if (isDone) {
      return;
    }
#line 204
  ;
  if (photoIsNext) {

      switch (PhotoTempM$hardwareStatus) {
          case PhotoTempM$sensorIdle: 
            case PhotoTempM$sensorTempReady: 
              PhotoTempM$hardwareStatus = PhotoTempM$sensorPhotoStarting;
          TOSH_SET_PHOTO_CTL_PIN();
          TOSH_MAKE_PHOTO_CTL_OUTPUT();
          TOSH_CLR_TEMP_CTL_PIN();
          TOSH_MAKE_TEMP_CTL_INPUT();
          PhotoTempM$PhotoTempTimer$stop();
          { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 216
            {
              PhotoTempM$waitingForSample = TRUE;
            }
#line 218
            __nesc_atomic_end(__nesc_atomic); }
#line 218
          ;
          photoIsNext = FALSE;
          if (PhotoTempM$PhotoTempTimer$start(TIMER_ONE_SHOT, 10) != SUCCESS) {
              PhotoTempM$hardwareStatus = PhotoTempM$sensorIdle;
              TOS_post(PhotoTempM$getSample);
            }
#line 223
          ;
          return;
          case PhotoTempM$sensorPhotoReady: 
            { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 226
              {
                PhotoTempM$waitingForSample = TRUE;
              }
#line 228
              __nesc_atomic_end(__nesc_atomic); }
#line 228
          ;
          if (PhotoTempM$InternalPhotoADC$getData() == SUCCESS) {
              photoIsNext = FALSE;
            }
          else 
#line 231
            {
              TOS_post(PhotoTempM$getSample);
            }
#line 233
          ;
          return;
          case PhotoTempM$sensorPhotoStarting: 



            case PhotoTempM$sensorTempStarting: 


              return;
        }
#line 243
      ;
    }
#line 244
  ;
  if (!photoIsNext) {

      switch (PhotoTempM$hardwareStatus) {
          case PhotoTempM$sensorIdle: 
            case PhotoTempM$sensorPhotoReady: 
              PhotoTempM$hardwareStatus = PhotoTempM$sensorTempStarting;
          TOSH_CLR_PHOTO_CTL_PIN();
          TOSH_MAKE_PHOTO_CTL_INPUT();
          TOSH_SET_TEMP_CTL_PIN();
          TOSH_MAKE_TEMP_CTL_OUTPUT();
          PhotoTempM$PhotoTempTimer$stop();
          { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 256
            {
              PhotoTempM$waitingForSample = TRUE;
            }
#line 258
            __nesc_atomic_end(__nesc_atomic); }
#line 258
          ;
          photoIsNext = TRUE;
          if (PhotoTempM$PhotoTempTimer$start(TIMER_ONE_SHOT, 10) != SUCCESS) {
              PhotoTempM$hardwareStatus = PhotoTempM$sensorIdle;
              TOS_post(PhotoTempM$getSample);
            }
#line 263
          ;
          return;
          case PhotoTempM$sensorTempReady: 
            { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 266
              {
                PhotoTempM$waitingForSample = TRUE;
              }
#line 268
              __nesc_atomic_end(__nesc_atomic); }
#line 268
          ;
          if (PhotoTempM$InternalTempADC$getData() == SUCCESS) {
              photoIsNext = TRUE;
            }
          else 
#line 271
            {
              TOS_post(PhotoTempM$getSample);
            }
#line 273
          ;
          return;
          case PhotoTempM$sensorTempStarting: 



            case PhotoTempM$sensorPhotoStarting: 


              return;
        }
#line 283
      ;
    }
#line 284
  ;
  photoIsNext = !photoIsNext;
  return;
}

static  
# 64 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/micaz/VoltageM.nc"
result_t VoltageM$StdControl$start(void)
#line 64
{
  result_t result;

#line 66
  result = VoltageM$ADCControl$init();
  result = rcombine(VoltageM$ADCControl$bindPort(TOS_ADC_VOLTAGE_PORT, 
  TOSH_ACTUAL_VOLTAGE_PORT), 
  result);
  return result;
}

static   
#line 93
result_t VoltageM$Voltage$getData(void)
#line 93
{

  uint8_t tmpState;

  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 97
    tmpState = VoltageM$state;
#line 97
    __nesc_atomic_end(__nesc_atomic); }

  if (tmpState != VoltageM$S_IDLE) {
    return FAIL;
    }
  if (VoltageM$ADC$getData() == FAIL) {
    return FAIL;
    }
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 105
    VoltageM$state = VoltageM$S_GET_DATA;
#line 105
    __nesc_atomic_end(__nesc_atomic); }

  return SUCCESS;
}

static   
# 159 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/micaz/HPLCC2420M.nc"
uint16_t HPLCC2420M$HPLCC2420$read(uint8_t addr)
#line 159
{

  uint16_t data = 0;
  uint8_t status;


  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 165
    {
      HPLCC2420M$bSpiAvail = FALSE;
      TOSH_CLR_CC_CS_PIN();
      * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x0F + 0x20) = addr | 0x40;
      while (!(* (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x0E + 0x20) & 0x80)) {
        }
#line 169
      ;
      status = * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x0F + 0x20);
      * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x0F + 0x20) = 0;
      while (!(* (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x0E + 0x20) & 0x80)) {
        }
#line 172
      ;
      data = * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x0F + 0x20);
      * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x0F + 0x20) = 0;
      while (!(* (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x0E + 0x20) & 0x80)) {
        }
#line 175
      ;
      data = (data << 8) | * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x0F + 0x20);
      TOSH_SET_CC_CS_PIN();
      HPLCC2420M$bSpiAvail = TRUE;
    }
#line 179
    __nesc_atomic_end(__nesc_atomic); }
  return data;
}

static   
# 194 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/micaz/HPLTimer1M.nc"
void HPLTimer1M$CaptureT1$setEdge(uint8_t LowToHigh)
#line 194
{


  if (LowToHigh) {
    * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x2E + 0x20) |= 1 << 6;
    }
  else {
#line 200
    * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x2E + 0x20) &= ~(1 << 6);
    }



  * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x36 + 0x20) |= 1 << 5;
  return;
}

static 
# 212 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/DelugeM.nc"
void DelugeM$sendAdvMsg(int imgNum, uint16_t addr)
#line 212
{

  TOS_MsgPtr pMsgBuf = DelugeM$SharedMsgBuf$getMsgBuf();
  DelugeAdvMsg *pMsg = (DelugeAdvMsg *)pMsgBuf->data;
  DelugeImgDesc *imgDesc = DelugeM$Metadata$getImgDesc(imgNum);

  if (!DelugeM$SharedMsgBuf$isLocked()) {
      pMsg->sourceAddr = TOS_LOCAL_ADDRESS;
      pMsg->version = DELUGE_VERSION;
      pMsg->type = DelugeM$imagesLoaded ? DELUGE_ADV_NORMAL : DELUGE_ADV_ERROR;


      if (!DelugeM$isNodeDescValid(&DelugeM$nodeDesc)) {
        nmemset(&DelugeM$nodeDesc, 0xff, sizeof DelugeM$nodeDesc);
        }
#line 226
      nmemcpy(& pMsg->nodeDesc, &DelugeM$nodeDesc, sizeof(DelugeNodeDesc ));


      if (!DelugeM$Metadata$isImgDescValid(imgDesc)) {
          imgDesc->vNum = DELUGE_INVALID_VNUM;
          imgDesc->imgNum = imgNum;
        }
      nmemcpy(& pMsg->imgDesc, imgDesc, sizeof(DelugeImgDesc ));

      pMsg->numImages = 3;
      if (DelugeM$SendAdvMsg$send(addr, sizeof(DelugeAdvMsg ), pMsgBuf) == SUCCESS) {
          {
          }
#line 237
          ;
          DelugeM$Leds$greenToggle();
          DelugeM$SharedMsgBuf$lock();
        }
    }
}

static 
#line 207
bool DelugeM$isNodeDescValid(DelugeNodeDesc *tmpNodeDesc)
#line 207
{
  return tmpNodeDesc->crc == DelugeM$Crc$crc16(tmpNodeDesc, 8)
   || tmpNodeDesc->vNum == DELUGE_INVALID_VNUM;
}

# 33 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/interfaces/Resource.nc"
static  result_t HPLFlash$FlashIdle$available(void){
#line 33
  unsigned char result;
#line 33

#line 33
  result = PageEEPROMM$FlashIdle$available();
#line 33

#line 33
  return result;
#line 33
}
#line 33
# 215 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/system/AMStandard.nc"
TOS_MsgPtr   received(TOS_MsgPtr packet)
#line 215
{
  uint16_t addr = TOS_LOCAL_ADDRESS;

#line 217
  AMStandard$counter++;
  {
  }
#line 218
  ;


  if (
#line 220
  packet->crc == 1 && 
  packet->group == TOS_AM_GROUP && (
  packet->addr == TOS_BCAST_ADDR || 
  packet->addr == addr)) 
    {

      uint8_t type = packet->type;
      TOS_MsgPtr tmp;

      {
      }
#line 229
      ;
      AMStandard$dbgPacket(packet);
      {
      }
#line 231
      ;


      tmp = AMStandard$ReceiveMsg$receive(type, packet);
      if (tmp) {
        packet = tmp;
        }
    }
#line 238
  return packet;
}

static  
# 272 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/DelugeMetadataM.nc"
result_t DelugeMetadataM$Metadata$setupNewImage(DelugeImgDesc *newImgDesc)
#line 272
{

  if (DelugeMetadataM$state != DelugeMetadataM$S_IDLE) {
    return FAIL;
    }
  DelugeMetadataM$curImage = newImgDesc->imgNum;
  DelugeMetadataM$state = DelugeMetadataM$curImage == DELUGE_GOLDEN_IMAGE_NUM ? DelugeMetadataM$S_CLEAR_WP : DelugeMetadataM$S_SETUP;

  nmemcpy(&DelugeMetadataM$imgDesc[DelugeMetadataM$curImage], newImgDesc, sizeof(DelugeImgDesc ));
  DelugeMetadataM$imgDesc[DelugeMetadataM$curImage].numPgsComplete = 0;

  DelugeMetadataM$execute();

  return SUCCESS;
}

static 
# 196 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/Deluge/DelugePageTransferM.nc"
void DelugePageTransferM$suppressMsgs(imgnum_t imgNum, pgnum_t pgNum)
#line 196
{
  if (DelugePageTransferM$state == DelugePageTransferM$S_SENDING || DelugePageTransferM$state == DelugePageTransferM$S_TX_LOCKING) {

      if (
#line 198
      imgNum < DelugePageTransferM$imgToSend
       || (imgNum == DelugePageTransferM$imgToSend
       && pgNum < DelugePageTransferM$pageToSend)) {
          DelugePageTransferM$changeState(DelugePageTransferM$S_IDLE);
          nmemset(DelugePageTransferM$pktsToSend, 0x0, DELUGE_PKT_BITVEC_SIZE);
        }
    }
  else {
#line 205
    if (DelugePageTransferM$state == DelugePageTransferM$S_RECEIVING || DelugePageTransferM$state == DelugePageTransferM$S_RX_LOCKING) {

        if (
#line 206
        imgNum < DelugePageTransferM$workingImgNum
         || (imgNum == DelugePageTransferM$workingImgNum
         && pgNum <= DelugePageTransferM$workingPgNum)) {

            DelugePageTransferM$suppressReq = TRUE;
          }
      }
    }
}

# 97 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/micaz/HPLCC2420InterruptM.nc"
void __attribute((signal))   __vector_7(void)
#line 97
{
  result_t val = SUCCESS;

#line 99
  val = HPLCC2420InterruptM$FIFOP$fired();
  if (val == FAIL) {
      * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x39 + 0x20) &= ~(1 << 6);
      * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x38 + 0x20) |= 1 << 6;
    }
}

static 
# 119 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/CC2420Radio/CC2420RadioM.nc"
void CC2420RadioM$flushRXFIFO(void)
#line 119
{
  CC2420RadioM$FIFOP$disable();
  CC2420RadioM$HPLChipcon$read(0x3F);
  CC2420RadioM$HPLChipcon$cmd(0x08);
  CC2420RadioM$HPLChipcon$cmd(0x08);
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 124
    CC2420RadioM$bPacketReceiving = FALSE;
#line 124
    __nesc_atomic_end(__nesc_atomic); }
  CC2420RadioM$FIFOP$startWait(FALSE);
}

static 
#line 540
void CC2420RadioM$delayedRXFIFO(void)
#line 540
{
  uint8_t len = MSG_DATA_SIZE;
  uint8_t _bPacketReceiving;

  if (!TOSH_READ_CC_FIFO_PIN() && !TOSH_READ_CC_FIFOP_PIN()) {
      CC2420RadioM$flushRXFIFO();
      return;
    }

  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 549
    {
      _bPacketReceiving = CC2420RadioM$bPacketReceiving;

      if (_bPacketReceiving) {
          if (!TOS_post(CC2420RadioM$delayedRXFIFOtask)) {
            CC2420RadioM$flushRXFIFO();
            }
        }
      else 
#line 555
        {
          CC2420RadioM$bPacketReceiving = TRUE;
        }
    }
#line 558
    __nesc_atomic_end(__nesc_atomic); }





  if (!_bPacketReceiving) {
      if (!CC2420RadioM$HPLChipconFIFO$readRXFIFO(len, (uint8_t *)CC2420RadioM$rxbufptr)) {
          { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 566
            CC2420RadioM$bPacketReceiving = FALSE;
#line 566
            __nesc_atomic_end(__nesc_atomic); }
          if (!TOS_post(CC2420RadioM$delayedRXFIFOtask)) {
              CC2420RadioM$flushRXFIFO();
            }
          return;
        }
    }
  CC2420RadioM$flushRXFIFO();
}

static  
#line 168
void CC2420RadioM$PacketSent(void)
#line 168
{
  TOS_MsgPtr pBuf;

  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 171
    {
      CC2420RadioM$stateRadio = CC2420RadioM$IDLE_STATE;
      pBuf = CC2420RadioM$txbufptr;
      pBuf->length = pBuf->length - MSG_HEADER_SIZE - MSG_FOOTER_SIZE;
    }
#line 175
    __nesc_atomic_end(__nesc_atomic); }

  CC2420RadioM$Send$sendDone(pBuf, SUCCESS);
}

static 
#line 113
void CC2420RadioM$sendFailed(void)
#line 113
{
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 114
    CC2420RadioM$stateRadio = CC2420RadioM$IDLE_STATE;
#line 114
    __nesc_atomic_end(__nesc_atomic); }
  CC2420RadioM$txbufptr->length = CC2420RadioM$txbufptr->length - MSG_HEADER_SIZE - MSG_FOOTER_SIZE;
  CC2420RadioM$Send$sendDone(CC2420RadioM$txbufptr, FAIL);
}

# 170 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/micaz/HPLTimer1M.nc"
void __attribute((interrupt))   __vector_12(void)
#line 170
{
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 171
    {
      if (HPLTimer1M$set_flag) {
          HPLTimer1M$mscale = HPLTimer1M$nextScale;
          HPLTimer1M$nextScale |= 0x8;
          * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x2E + 0x20) = HPLTimer1M$nextScale;
          * (volatile unsigned int *)(unsigned int )& * (volatile unsigned char *)(0x2A + 0x20) = HPLTimer1M$minterval;
          HPLTimer1M$set_flag = 0;
        }
    }
#line 179
    __nesc_atomic_end(__nesc_atomic); }
  HPLTimer1M$Timer1$fire();
}

static   
# 221 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/micaz/HPLCC2420InterruptM.nc"
void HPLCC2420InterruptM$SFDCapture$captured(uint16_t time)
#line 221
{
  result_t val = SUCCESS;

  val = HPLCC2420InterruptM$SFD$captured(time);
  if (val == FAIL) {
      HPLCC2420InterruptM$SFDCapture$disableEvents();
    }
  else 
    {
      if (HPLCC2420InterruptM$SFDCapture$isOverflowPending()) {
        HPLCC2420InterruptM$SFDCapture$clearOverflow();
        }
    }
}

# 172 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/micaz/HPLTimer2.nc"
void __attribute((interrupt))   __vector_9(void)
#line 172
{
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 173
    {
      if (HPLTimer2$set_flag) {
          HPLTimer2$nextScale |= 0x8;
          -(* (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x25 + 0x20) = HPLTimer2$nextScale);
          * (volatile unsigned char *)(unsigned int )& * (volatile unsigned char *)(0x23 + 0x20) = HPLTimer2$minterval;
          HPLTimer2$set_flag = 0;
        }
    }
#line 180
    __nesc_atomic_end(__nesc_atomic); }
  HPLTimer2$Timer2$fire();
}

static  
# 393 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/lib/CC2420Radio/CC2420RadioM.nc"
void CC2420RadioM$startSend(void)
#line 393
{

  if (!CC2420RadioM$HPLChipcon$cmd(0x09)) {
      CC2420RadioM$sendFailed();
      return;
    }

  if (!CC2420RadioM$HPLChipconFIFO$writeTXFIFO(CC2420RadioM$txlength + 1, (uint8_t *)CC2420RadioM$txbufptr)) {
      CC2420RadioM$sendFailed();
      return;
    }
}

static 



void CC2420RadioM$tryToSend(void)
#line 410
{
  uint8_t currentstate;

#line 412
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 412
    currentstate = CC2420RadioM$stateRadio;
#line 412
    __nesc_atomic_end(__nesc_atomic); }


  if (currentstate == CC2420RadioM$PRE_TX_STATE) {



      if (!TOSH_READ_CC_FIFO_PIN() && !TOSH_READ_CC_FIFOP_PIN()) {
          CC2420RadioM$flushRXFIFO();
        }

      if (TOSH_READ_RADIO_CCA_PIN()) {
          { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 424
            CC2420RadioM$stateRadio = CC2420RadioM$TX_STATE;
#line 424
            __nesc_atomic_end(__nesc_atomic); }
          CC2420RadioM$sendPacket();
        }
      else {



          if (CC2420RadioM$countRetry-- <= 0) {
              CC2420RadioM$flushRXFIFO();
              CC2420RadioM$countRetry = 8;
              if (!TOS_post(CC2420RadioM$startSend)) {
                CC2420RadioM$sendFailed();
                }
#line 436
              return;
            }
          if (!CC2420RadioM$setBackoffTimer(CC2420RadioM$MacBackoff$congestionBackoff(CC2420RadioM$txbufptr) * 10)) {
              CC2420RadioM$sendFailed();
            }
        }
    }
}

static   
# 393 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/micaz/FramerM.nc"
result_t FramerM$ByteComm$rxByteReady(uint8_t data, bool error, uint16_t strength)
#line 393
{

  switch (FramerM$gRxState) {

      case FramerM$RXSTATE_NOSYNC: 
        if (data == FramerM$HDLC_FLAG_BYTE && FramerM$gMsgRcvTbl[FramerM$gRxHeadIndex].Length == 0) {

            FramerM$gMsgRcvTbl[FramerM$gRxHeadIndex].Token = 0;
            FramerM$gRxByteCnt = FramerM$gRxRunningCRC = 0;
            FramerM$gpRxBuf = (uint8_t *)FramerM$gMsgRcvTbl[FramerM$gRxHeadIndex].pMsg;
            FramerM$gRxState = FramerM$RXSTATE_PROTO;
          }
      break;

      case FramerM$RXSTATE_PROTO: 
        if (data == FramerM$HDLC_FLAG_BYTE) {
            break;
          }
      FramerM$gMsgRcvTbl[FramerM$gRxHeadIndex].Proto = data;
      FramerM$gRxRunningCRC = crcByte(FramerM$gRxRunningCRC, data);
      switch (data) {
          case FramerM$PROTO_PACKET_ACK: 
            FramerM$gRxState = FramerM$RXSTATE_TOKEN;
          break;
          case FramerM$PROTO_PACKET_NOACK: 
            FramerM$gRxState = FramerM$RXSTATE_INFO;
          break;
          default: 
            FramerM$gRxState = FramerM$RXSTATE_NOSYNC;
          break;
        }
      break;

      case FramerM$RXSTATE_TOKEN: 
        if (data == FramerM$HDLC_FLAG_BYTE) {
            FramerM$gRxState = FramerM$RXSTATE_NOSYNC;
          }
        else {
#line 430
          if (data == FramerM$HDLC_CTLESC_BYTE) {
              FramerM$gMsgRcvTbl[FramerM$gRxHeadIndex].Token = 0x20;
            }
          else {
              FramerM$gMsgRcvTbl[FramerM$gRxHeadIndex].Token ^= data;
              FramerM$gRxRunningCRC = crcByte(FramerM$gRxRunningCRC, FramerM$gMsgRcvTbl[FramerM$gRxHeadIndex].Token);
              FramerM$gRxState = FramerM$RXSTATE_INFO;
            }
          }
#line 438
      break;


      case FramerM$RXSTATE_INFO: 
        if (FramerM$gRxByteCnt > FramerM$HDLC_MTU) {
            FramerM$gRxByteCnt = FramerM$gRxRunningCRC = 0;
            FramerM$gMsgRcvTbl[FramerM$gRxHeadIndex].Length = 0;
            FramerM$gMsgRcvTbl[FramerM$gRxHeadIndex].Token = 0;
            FramerM$gRxState = FramerM$RXSTATE_NOSYNC;
          }
        else {
#line 448
          if (data == FramerM$HDLC_CTLESC_BYTE) {
              FramerM$gRxState = FramerM$RXSTATE_ESC;
            }
          else {
#line 451
            if (data == FramerM$HDLC_FLAG_BYTE) {
                if (FramerM$gRxByteCnt >= 2) {

                    uint16_t usRcvdCRC = FramerM$gpRxBuf[FramerM$fRemapRxPos(FramerM$gRxByteCnt - 1)] & 0xff;

#line 455
                    usRcvdCRC = (usRcvdCRC << 8) | FramerM$fRemapRxPos(FramerM$gpRxBuf[FramerM$gRxByteCnt - 2] & 0xff);


                    FramerM$gRxRunningCRC = usRcvdCRC;

                    if (usRcvdCRC == FramerM$gRxRunningCRC) {
                        FramerM$gMsgRcvTbl[FramerM$gRxHeadIndex].Length = FramerM$gRxByteCnt - 2;
                        TOS_post(FramerM$PacketRcvd);
                        FramerM$gRxHeadIndex++;
#line 463
                        FramerM$gRxHeadIndex %= FramerM$HDLC_QUEUESIZE;
                      }
                    else {
                        FramerM$gMsgRcvTbl[FramerM$gRxHeadIndex].Length = 0;
                        FramerM$gMsgRcvTbl[FramerM$gRxHeadIndex].Token = 0;
                      }
                    if (FramerM$gMsgRcvTbl[FramerM$gRxHeadIndex].Length == 0) {
                        FramerM$gpRxBuf = (uint8_t *)FramerM$gMsgRcvTbl[FramerM$gRxHeadIndex].pMsg;
                        FramerM$gRxState = FramerM$RXSTATE_PROTO;
                      }
                    else {
                        FramerM$gRxState = FramerM$RXSTATE_NOSYNC;
                      }
                  }
                else {
                    FramerM$gMsgRcvTbl[FramerM$gRxHeadIndex].Length = 0;
                    FramerM$gMsgRcvTbl[FramerM$gRxHeadIndex].Token = 0;
                    FramerM$gRxState = FramerM$RXSTATE_NOSYNC;
                  }
                FramerM$gRxByteCnt = FramerM$gRxRunningCRC = 0;
              }
            else {
                FramerM$gpRxBuf[FramerM$fRemapRxPos(FramerM$gRxByteCnt)] = data;
                if (FramerM$gRxByteCnt >= 2) {
                    FramerM$gRxRunningCRC = crcByte(FramerM$gRxRunningCRC, FramerM$gpRxBuf[FramerM$gRxByteCnt - 2]);
                  }
                FramerM$gRxByteCnt++;
              }
            }
          }
#line 491
      break;

      case FramerM$RXSTATE_ESC: 
        if (data == FramerM$HDLC_FLAG_BYTE) {

            FramerM$gRxByteCnt = FramerM$gRxRunningCRC = 0;
            FramerM$gMsgRcvTbl[FramerM$gRxHeadIndex].Length = 0;
            FramerM$gMsgRcvTbl[FramerM$gRxHeadIndex].Token = 0;
            FramerM$gRxState = FramerM$RXSTATE_NOSYNC;
          }
        else {
            data = data ^ 0x20;
            FramerM$gpRxBuf[FramerM$fRemapRxPos(FramerM$gRxByteCnt)] = data;
            if (FramerM$gRxByteCnt >= 2) {
                FramerM$gRxRunningCRC = crcByte(FramerM$gRxRunningCRC, FramerM$gpRxBuf[FramerM$gRxByteCnt - 2]);
              }
            FramerM$gRxByteCnt++;
            FramerM$gRxState = FramerM$RXSTATE_INFO;
          }
      break;

      default: 
        FramerM$gRxState = FramerM$RXSTATE_NOSYNC;
      break;
    }

  return SUCCESS;
}

static 
#line 169
uint8_t FramerM$fRemapRxPos(uint8_t InPos)
#line 169
{


  if (InPos < 4) {
    return InPos + (size_t )& ((struct TOS_Msg *)0)->addr;
    }
  else {
#line 174
    if (InPos == 4) {
      return (size_t )& ((struct TOS_Msg *)0)->length;
      }
    else {
#line 177
      return InPos + (size_t )& ((struct TOS_Msg *)0)->addr - 1;
      }
    }
}

static   
# 87 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/system/UARTM.nc"
result_t UARTM$HPLUART$putDone(void)
#line 87
{
  bool oldState;

  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 90
    {
      {
      }
#line 91
      ;
      oldState = UARTM$state;
      UARTM$state = FALSE;
    }
#line 94
    __nesc_atomic_end(__nesc_atomic); }








  if (oldState) {
      UARTM$ByteComm$txDone();
      UARTM$ByteComm$txByteReady(TRUE);
    }
  return SUCCESS;
}

static 
# 520 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/platform/micaz/FramerM.nc"
result_t FramerM$TxArbitraryByte(uint8_t inByte)
#line 520
{
  if (inByte == FramerM$HDLC_FLAG_BYTE || inByte == FramerM$HDLC_CTLESC_BYTE) {
      { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 522
        {
          FramerM$gPrevTxState = FramerM$gTxState;
          FramerM$gTxState = FramerM$TXSTATE_ESC;
          FramerM$gTxEscByte = inByte;
        }
#line 526
        __nesc_atomic_end(__nesc_atomic); }
      inByte = FramerM$HDLC_CTLESC_BYTE;
    }

  return FramerM$ByteComm$txByte(inByte);
}

static   
# 95 "C:/tinyos/cygwin/opt/tinyos-1.x/tos/system/ADCM.nc"
result_t ADCM$HPLADC$dataReady(uint16_t data)
#line 95
{
  uint16_t doneValue = data;
  uint8_t donePort;
  result_t Result;


  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 101
    {
      donePort = ADCM$ReqPort;

      if (((1 << donePort) & ADCM$ContReqMask) == 0) {
          ADCM$HPLADC$sampleStop();
          ADCM$ReqVector &= ~(1 << donePort);
        }

      if (ADCM$ReqVector) {
          do {
              ADCM$ReqPort++;
              ADCM$ReqPort = ADCM$ReqPort == TOSH_ADC_PORTMAPSIZE ? 0 : ADCM$ReqPort;
            }
          while (((
#line 113
          1 << ADCM$ReqPort) & ADCM$ReqVector) == 0);
          ADCM$HPLADC$samplePort(ADCM$ReqPort);
        }
    }
#line 116
    __nesc_atomic_end(__nesc_atomic); }


  {
  }
#line 119
  ;
  Result = ADCM$ADC$dataReady(donePort, doneValue);

  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 122
    {
      if (Result == FAIL && ADCM$ContReqMask & (1 << donePort)) {
          ADCM$HPLADC$sampleStop();
          ADCM$ContReqMask &= ~(1 << donePort);
        }
    }
#line 127
    __nesc_atomic_end(__nesc_atomic); }

  return SUCCESS;
}

static  
# 165 "TestSenseM.nc"
void TestSenseM$sendStatus(void)
#line 165
{
  struct OscopeMsg *pack;

  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 168
    {
      TestSenseM$test = 0;
      pack = (struct OscopeMsg *)TestSenseM$msg[TestSenseM$currentMsg].data;

      pack->type = 1;
      if (TestSenseM$sleeping == 1) {
        pack->data1 = 1;
        }
      else {
#line 176
        pack->data1 = 2;
        }
#line 177
      pack->seqno = TestSenseM$seqno;
      pack->data2 = TestSenseM$gSensorDataVoltage;


      TestSenseM$gSensorDataLight = 0;
      TestSenseM$gSensorDataTemp = 0;
      pack->channel = 1;
      pack->sourceMoteID = TOS_LOCAL_ADDRESS;
    }
#line 185
    __nesc_atomic_end(__nesc_atomic); }
  if (TestSenseM$DataMsg$send(0, sizeof(struct OscopeMsg ), 
  &TestSenseM$msg[TestSenseM$currentMsg])) 
    {
      { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 189
        {
          TestSenseM$currentMsg ^= 0x1;
        }
#line 191
        __nesc_atomic_end(__nesc_atomic); }
    }
}

static  
#line 134
void TestSenseM$SendData(void)
#line 134
{

  struct OscopeMsg *pack;

  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 138
    {
      TestSenseM$test = 0;
      TestSenseM$seqno++;
      pack = (struct OscopeMsg *)TestSenseM$msg[TestSenseM$currentMsg].data;
      pack->type = 0;
      pack->data1 = TestSenseM$gSensorDataLight;
      pack->data2 = TestSenseM$gSensorDataTemp;
      pack->seqno = TestSenseM$seqno;


      TestSenseM$gSensorDataLight = 0;
      TestSenseM$gSensorDataTemp = 0;
      pack->channel = 2;
      pack->sourceMoteID = TOS_LOCAL_ADDRESS;
    }
#line 152
    __nesc_atomic_end(__nesc_atomic); }

  if (TestSenseM$DataMsg$send(0, sizeof(struct OscopeMsg ), 
  &TestSenseM$msg[TestSenseM$currentMsg])) 
    {
      { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 157
        {
          TestSenseM$currentMsg ^= 0x1;
        }
#line 159
        __nesc_atomic_end(__nesc_atomic); }
    }
}

