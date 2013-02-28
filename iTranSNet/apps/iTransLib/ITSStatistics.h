#ifndef _STATISTIC_H_
#define _STATISTIC_H_
enum {
  
    AM_ITSSTATISTICSMSG = 30,

};
/*


#define REPORT_TIME_INTVL 600
#define MAX_NUM_ROAD 3
#define MAX_NUM_VEHICLES 6


typedef struct TrafficMsg {
  uint8_t vid;
  uint8_t rid;
  uint8_t jnc;
  uint8_t dir;
  uint8_t sta;
  uint8_t loc;
  uint16_t seq;
} __attribute__ ((packed)) TrafficMsg;





typedef struct StatisticMsg {
  uint8_t sid;
  uint16_t seq;
  uint8_t sta[10];
} __attribute__ ((packed)) StatisticMsg;



typedef struct {
  uint8_t numvs;
  uint8_t vids[MAX_NUM_VEHICLES];
  uint8_t lids[MAX_NUM_VEHICLES];
  uint8_t errs[MAX_NUM_VEHICLES];
} Statistics;


*/

#define MAX_NUM_VEHICLES 6


typedef struct ITSStatisticsMsg {
  uint8_t sid;
  uint16_t seq;
  uint8_t numvs;
  uint8_t vids[MAX_NUM_VEHICLES];
  uint8_t locs[MAX_NUM_VEHICLES];
  uint8_t errs[MAX_NUM_VEHICLES];
} __attribute__ ((packed)) ITSStatisticsMsg;


/*
typedef struct Statistics{

} __attribute__ ((packed)) Statistics;
*/
#endif
