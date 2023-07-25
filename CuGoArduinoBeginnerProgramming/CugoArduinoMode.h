// CugoArduinoMode.h
// CugoArduinoBeginnerProgramming用ライブラリ

#ifndef CUGOARDUINOMODE_H
#define CUGOARDUINOMODE_H

#include "Arduino.h"
#include <SPI.h>
#include <Servo.h>
#include "MotorController.h"
#include "CugoArduinoMode.h"

// モータとエンコーダのピン配置設定
#define PIN_MOTOR_L A0  // モータ出力ピン(L)
#define PIN_MOTOR_R A1  // モータ出力ピン(R)
#define PIN_ENCODER_L_A 2  // エンコーダ割り込み入力ピン(L)
#define PIN_ENCODER_L_B 8  // エンコーダ回転方向入力ピン(L)
#define PIN_ENCODER_R_A 3  // エンコーダ割り込み入力ピン(R)
#define PIN_ENCODER_R_B 9  // エンコーダ回転方向入力ピン(R)

// プロポ信号の読み取りピン（L/R/MODE_CAHNGE）
#define PWM_IN_PIN0   5   // プロポスティック入力ピン(L)//digitalRead ピン変化割り込みの設定
#define PWM_IN_PIN1   6   // プロポスティック入力ピン(MODE)//digitalRead ピン変化割り込みの設定
#define PWM_IN_PIN2   7   // プロポスティック入力ピン(R)//digitalRead ピン変化割り込みの設定

//cugo仕様関連
#define wheel_radius_l  0.03858d
#define wheel_radius_r  0.03858d
#define tread  0.380d
#define encoder_resolution  2048.0d
#define MAX_MOTOR_RPM 180 //モータの速度上限値
//↑の仕様が変更される場合は下の変換係数も変更してください。
#define conversion_distance_to_count 8448.660535308492d // 変換係数： encoder_resolution / (2 * wheel_radius_l * PI)の計算結果
#define conversion_count_to_distance 0.000118361958d    // 変換係数： 2 * wheel_radius_l * PI  / encoder_resolution の計算結果

//encoder_resolution / (2 * wheel_radius_l * PI);

// PID 控制器增益調整
// L側
#define L_KP   1.0f   //CuGoV3
#define L_KI   0.02f   //CuGoV3
#define L_KD   0.1f   //CuGoV3

//const float L_KP = 1.0;
//const float L_KI = 0.06;
//const float L_KD = 0.1;

// R側
#define R_KP   1.0f   //CuGoV3
#define R_KI   0.02f   //CuGoV3
#define R_KD   0.1f   //CuGoV3
//const float R_KP = 1.0;
//const float R_KI = 0.06;
//const float R_KD = 0.1;

// 低通濾波器
#define L_LPF   0.2f 
#define R_LPF   0.2f
//const float L_LPF = 0.2;
//const float R_LPF = 0.2;

// PID 位置控制的增益調整
#define L_COUNT_KP  0.04f
#define L_COUNT_KI  0.003f 
#define L_COUNT_KD  0.01f
#define R_COUNT_KP  0.04f
#define R_COUNT_KI  0.003f 
#define R_COUNT_KD  0.01f

#define L_MAX_COUNT_I  9000.0f //速度上限を設定している場合はiは必ず0に
#define R_MAX_COUNT_I  9000.0f //速度上限を設定している場合はiは必ず0に


#define CONTROLL_STOP_count  1000

// Arduinoキットのスタートボタン
#define CMD_BUTTON_PIN A2 


// 動作モード定義
#define RC_MODE 0
#define ARDUINO_MODE 1

//各種閾値
#define ARDUINO_MODE_IN 1700  // ARDUINOモードに入るときの閾値(us) (1100~1900/中央1500)
#define ARDUINO_MODE_OUT 1300  // ARDUINOモードから抜けるときの閾値(us) (1100~1900/中央1500)
#define CUGO_PROPO_MAX_A 2200
#define CUGO_PROPO_MIN_A 800
#define CUGO_PROPO_MAX_B 1900
#define CUGO_PROPO_MIN_B 1100
#define CUGO_PROPO_MAX_C 2200
#define CUGO_PROPO_MIN_C 800
#define CMD_SIZE 60 //　命令數量上限
#define EXCEPTION_NO -32768 //int下限

//モーター設定
#define MOTOR_NUM 2 // モータ接続数（最大4の予定）
#define MOTOR_LEFT 0
#define MOTOR_RIGHT 1

//PIN関連
#define PIN_UP(no)    upTime[no] = micros();
#define PIN_DOWN(no)  time[no] = micros() - upTime[no]
#define PWM_IN_MAX    3

// グローバル変数宣言
extern long int arduino_count_cmd_matrix[CMD_SIZE][2];
extern int arduino_flag_cmd_matrix[CMD_SIZE][4];
extern int init_current_cmd;

extern long int target_count_L;
extern long int target_count_R;
extern long int target_wait_time;
extern int button_push_count;
extern bool button_enable;
extern bool cmd_init;
extern int current_cmd;
extern bool cmd_L_back;
extern bool cmd_R_back;
extern bool cmd_exec;
extern bool count_done;
extern bool wait_done;
extern bool button_done;
extern bool spi_done;
extern bool end_arduino_mode;
extern unsigned long long current_time;
extern unsigned long long prev_time_10ms; 
extern unsigned long long prev_time_100ms; 
extern unsigned long long prev_time_1000ms; 
extern int runMode;
extern bool UDP_CONNECTION_DISPLAY;
extern bool ENCODER_DISPLAY;
extern bool PID_CONTROLL_DISPLAY;
extern bool FAIL_SAFE_DISPLAY;
extern const bool L_reverse;
extern const bool R_reverse;
extern float l_count_prev_i_;
extern float l_count_prev_p_;
extern float r_count_prev_i_;
extern float r_count_prev_p_;
extern float l_count_gain;
extern float r_count_gain;
extern int OLD_PWM_IN_PIN0_VALUE; 
extern int OLD_PWM_IN_PIN1_VALUE; 
extern int OLD_PWM_IN_PIN2_VALUE; 
extern volatile unsigned long upTime[PWM_IN_MAX];
extern volatile unsigned long rcTime[PWM_IN_MAX];
extern volatile unsigned long time[PWM_IN_MAX];



//各種関数
  void init_display();
  void init_SPI();
  void init_KOPROPO(int runMode,int OLD_PWM_IN_PIN0_VALUE,int OLD_PWM_IN_PIN1_VALUE,int OLD_PWM_IN_PIN2_VALUE);
  void init_ARDUINO_CMD();
  void set_arduino_cmd_matrix(long int cmd_0,long  int cmd_1, int cmd_2, int cmd_3,int cmd_4,int cmd_5);
  void send_spi(int mode);
  void view_arduino_cmd_matrix();
  void display_failsafe(bool FAIL_SAFE_DISPLAY,int runMode);
  void display_nothing();
  void spi_cmd(int spi_cmd_value);
  void calc_necessary_rotate(float degree); 
  void calc_necessary_count(float distance); 
  void atamaopen();
  void atamaclose();
  void wait_button();
  void botan();
  void button();
  void display_speed(MotorController motor_controllers[2],bool ENCODER_DISPLAY); 
  void display_target_rpm(MotorController motor_controllers[2],bool ENCODER_DISPLAY);
  void display_PID(MotorController motor_controllers[2],bool PID_CONTROLL_DISPLAY);
  int split(String data, char delimiter, String *dst);
  void motor_direct_instructions(int left, int right,MotorController motor_controllers[2]);
  void rc_mode(volatile unsigned long rcTime[PWM_IN_MAX],MotorController motor_controllers[2]);
  void stop_motor_immediately(MotorController motor_controllers[2]);
  void set_wait_time_cmd();
  void wait_time(int milisec);
  void matsu(int milisec);
  void matu(int milisec);
  void reset_pid_gain(MotorController motor_controllers[2]);
  void set_button_cmd();
  void go_backward(float distance,float max_velocity);
  void sagaru(float distance);
  void sagaru(float distance,float max_velocity);
  void turn_clockwise(float degree,float max_velocity);
  void migimawari(float degree);
  void migimawari(float degree,float max_velocity);
  void migimawari90();
  void migimawari90(float max_velocity);
  void migimawari45();
  void migimawari45(float max_velocity);
  void migimawari180();
  void migimawari180(float max_velocity);
  void go_forward(float distance,float max_velocity);
  void susumu(float distance);
  void susumu(float distance,float max_velocity);
  void turn_counter_clockwise(float degree,float max_velocity);
  void hidarimawari(float degree);
  void hidarimawari(float degree,float max_velocity);
  void hidarimawari90();
  void hidarimawari90(float max_velocity);
  void hidarimawari45();
  void hidarimawari45(float max_velocity);
  void hidarimawari180();
  void hidarimawari180(float max_velocity);
  void reset_arduino_mode_flags();
  void set_go_forward_cmd(MotorController motor_controllers[2]);
  void view_flags();
  void check_achievement_spi_cmd();
  void cmd_end(MotorController motor_controllers[2]);
  void check_achievement_wait_time_cmd(MotorController motor_controllers[2]);
  void cmd_manager_flags_init(MotorController motor_controllers[2]);  
  void check_achievement_go_forward_cmd(MotorController motor_controllers[2]);
  void cmd_manager(MotorController motor_controllers[2]);
  void check_achievement_button_cmd(MotorController motor_controllers[2]);
  void job_100ms(MotorController motor_controllers[2]);
  void job_1000ms();
  void display_detail(MotorController motor_controllers[2]);

  
#endif
