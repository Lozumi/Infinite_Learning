typedef struct cmd_vel { float linear, angular; cmd_vel() {} } CmdVel;
extern void init(float, float, int, int);
extern void navigateTo(float, float, float);
extern CmdVel update(float, float, float);
