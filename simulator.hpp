#ifndef simulator_hpp
#define simulator_hpp

#include "Vintersector.h"
#include "verilated.h"

#define FIXED_POINT_FRACTIONAL_BITS 8
#define MAX_QUEUE_SZ 50


typedef int32_t fixed_point_t;

typedef struct {
    fixed_point_t min_t;
    fixed_point_t max_t;
    fixed_point_t bmin0;
    fixed_point_t bmin1;
    fixed_point_t bmin2;
    fixed_point_t bmax0;
    fixed_point_t bmax1;
    fixed_point_t bmax2;
    fixed_point_t ray_org0;
    fixed_point_t ray_org1;
    fixed_point_t ray_org2;
    fixed_point_t ray_inv_dir0;
    fixed_point_t ray_inv_dir1;
    fixed_point_t ray_inv_dir2;
    int ray_dir_sign0;
    int ray_dir_sign1;
    int ray_dir_sign2;
} intersector_input_t;

typedef struct {
    float tmin;
    float tmax;
} intersector_output_t;

inline float fixed_to_float(fixed_point_t input) {
  return ((float)input / (float)(1 << FIXED_POINT_FRACTIONAL_BITS));
}

inline fixed_point_t float_to_fixed(float input, bool supress_warning = false) {
  if (input > 2147483647) {
    if (!supress_warning) {
      // printf("warning large number detected, setting to max value\n");
    }
    return (fixed_point_t)2147483647;
  }
  if (input < -2147483648) {
    return (fixed_point_t)-2147483648;
  }
  return (fixed_point_t)(round(input * (1 << FIXED_POINT_FRACTIONAL_BITS)));
}

class Simulator {
public:
  
  Simulator();
  ~Simulator();
  void append_to_queue(intersector_input_t);
  void step();
  intersector_output_t pop_queue();
  uint64_t get_timestamp();
  

//   void attach_ram(RAM* ram);

//   void load_bin(const char* program_file);
//   void load_ihex(const char* program_file);
  
//   bool is_busy() const;

//   bool csr_req_active() const;

//   void reset();
    
//   void wait(uint32_t cycles);
  
//   void set_csr(int core_id, int addr, unsigned value);
//   void get_csr(int core_id, int addr, unsigned *value);

//   void run();  
//   int get_last_wb_value(int reg) const;  

//   void print_stats(std::ostream& out);


private:
    VerilatedContext *contextp;
    Vintersector *vinter_obj;
    intersector_input_t in_queue[MAX_QUEUE_SZ];
    std::deque<intersector_input_t> input_deque;
    std::deque<intersector_output_t> output_deque;
    uint64_t timestamp;


//   typedef struct {
//     int cycles_left;  
//     std::array<uint8_t, GLOBAL_BLOCK_SIZE> block;
//     uint32_t addr;
//     uint32_t tag;
//   } dram_req_t;

//   std::unordered_map<int, std::stringstream> print_bufs_;

//   void eval();  

//   void eval_dram_bus();
//   void eval_io_bus();
//   void eval_csr_bus();
  
//   std::list<dram_req_t> dram_rsp_vec_;
//   bool dram_rsp_active_;

//   bool dram_rsp_ready_;  
//   bool csr_req_ready_;
//   bool csr_req_active_;
//   uint32_t* csr_rsp_value_;

//   RAM *ram_;
//   VVortex *vortex_;
// #ifdef VCD_OUTPUT
//   VerilatedVcdC *trace_;
// #endif
};

#endif