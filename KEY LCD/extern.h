#ifndef __EXTERN_H
#define __EXTERN_H

extern void KeyPadInitialize(void);
extern unsigned char GetKeyPressed(void);
extern void delay(int count);
extern void lcdinit(void);
extern void lcdstring(char *str);
extern void lcdchar(unsigned char data,unsigned char type);

#endif
