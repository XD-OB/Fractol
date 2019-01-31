# Macros for mlx_hook function

 NOEVENTMASK 0L
 KEYPRESSMASK (1L<<0)
 KEYRELEASEMASK (1L<<1)
 BUTTONPRESSMASK (1L<<2)
 BUTTONRELEASEMASK (1L<<3)
 ENTERWINDOWMASK (1L<<4)
 LEAVEWINDOWMASK (1L<<5)
 POINTERMOTIONMASK (1L<<6)
 POINTERMOTIONHINTMASK (1L<<7)
 BUTTON1MOTIONMASK (1L<<8)
 BUTTON2MOTIONMASK (1L<<9)
 BUTTON3MOTIONMASK (1L<<10)
 BUTTON4MOTIONMASK (1L<<11)
 BUTTON5MOTIONMASK (1L<<12)
 BUTTONMOTIONMASK (1L<<13)
 KEYMAPSTATEMASK (1L<<14)
 EXPOSUREMASK (1L<<15)
 VISIBILITYCHANGEMASK (1L<<16)
 STRUCTURENOTIFYMASK (1L<<17)
 RESIZEREDIRECTMASK (1L<<18)
 SUBSTRUCTURENOTIFYMASK (1L<<19)
 SUBSTRUCTUREREDIRECTMASK (1L<<20)
 FOCUSCHANGEMASK (1L<<21)
 PROPERTYCHANGEMASK (1L<<22)
 COLORMAPCHANGEMASK (1L<<23)
 OWNERGRABBUTTONMASK (1L<<24)

 KEYPRESS 2
 KEYRELEASE 3
 BUTTONPRESS 4
 BUTTONRELEASE 5
 MOTIONNOTIFY 6
 ENTERNOTIFY 7
 LEAVENOTIFY 8
 FOCUSIN 9
 FOCUSOUT 10
 KEYMAPNOTIFY 11
 EXPOSE 12
 GRAPHICSEXPOSE 13
 NOEXPOSE 14
 VISIBILITYNOTIFY 15
 CREATENOTIFY 16
 DESTROYNOTIFY 17
 UNMAPNOTIFY 18
 MAPNOTIFY 19
 MAPREQUEST 20
 REPARENTNOTIFY 21
 CONFIGURENOTIFY 22
 CONFIGUREREQUEST 23
 GRAVITYNOTIFY 24

# Mouse button keycodes

 BUT1_KEY 1
 BUT2_KEY 2
 BUT3_KEY 3
 SCROLLUP_KEY 4
 SCROLLDOWN_KEY 5
 SCROLLLEFT_KEY 6
 SCROLLRIGHT_KEY 7

# Keyboard keys

# Letters keys
 A_KEY 0
 B_KEY 11
 C_KEY 8
 D_KEY 2
 E_KEY 14
 F_KEY 3
 G_KEY 5
 H_KEY 4
 I_KEY 34
 J_KEY 38
 K_KEY 40
 L_KEY 37
 M_KEY 46
 N_KEY 45
 O_KEY 31
 P_KEY 35
 Q_KEY 12
 R_KEY 15
 S_KEY 1
 T_KEY 17
 U_KEY 32
 V_KEY 9
 W_KEY 13
 X_KEY 7
 Y_KEY 16
 Z_KEY 6

# Numbers (not numeric keypad ones)

 K1_KEY 18
 K2_KEY 19
 K3_KEY 20
 K4_KEY 21
 K5_KEY 23
 K6_KEY 22
 K7_KEY 26
 K8_KEY 28
 K9_KEY 25
 K0_KEY 29

# Special characters
SP_KEY is the space ( ) key
BQ_KEY is the back quote (`) and tilde (~) key
MN_KEY is the minus (-) and underscore (_) key
PL_KEY is the plus (+) and equal (=) key
SBO_KEY is the square bracket opening ([) and brace opening ({) key
SBC_KEY is the square bracket closing (]) and brace closing (}) key
BSL_KEY is the backslash (\) and pipe (|) key
SC_KEY is the semicolon (;) and colon (:) key
SQ_KEY is the simple quote (') and double quote (") key
CM_KEY is the comma (,) and angle bracket opening (<) key
PT_KEY is the point (.) and angle bracket closing (>) key
SL_KEY is the slash (/) and question mark (?) key

 SP_KEY 49
 BQ_KEY 50
 MN_KEY 27
 PL_KEY 24
 SBO_KEY 33
 SBC_KEY 30
 BSL_KEY 42
 SC_KEY 41
 SQ_KEY 39
 CM_KEY 43
 PT_KEY 47
 SL_KEY 44

# Functions keys, you might use fn key to use them
# I didn't find the F11_KEY value

 F1_KEY 122
 F2_KEY 120
 F3_KEY 99
 F4_KEY 118
 F5_KEY 96
 F6_KEY 97
 F7_KEY 98
 F8_KEY 100
 F9_KEY 101
 F10_KEY 109
 F11_KEY
 F12_KEY 111
 F13_KEY 105
 F14_KEY 107
 F15_KEY 113
 F16_KEY 106
 F17_KEY 64
 F18_KEY 79
 F19_KEY 80

# Arrow keys
 UP_KEY 126
 DOWN_KEY 125
 RIGHT_KEY 124
 LEFT_KEY 123

# Special keys
CL_KEY is the caps lock key
LSFT_KEY and RLFT_KEY are the left shift and right shift keys
LCTRL_KEY and RCTRL_KEY are the left control and right control keys
LOPT_KEY and ROPT_KEY are the left option and right option keys
LCMD_KEY and RCMD_KEY are the left command and right command keys
LDEL_KEY and RDEL_KEY are the left delete and right delete keys
RTN_KEY is the return key
EJ_KEY is the eject key and doesn't react
PUP_KEY and PDOWN_KEY are the page up and page down keys
CLR_KEY is the clear key

 ESC_KEY 53
 TAB_KEY 48
 CL_KEY 272
 LSFT_KEY 257
 LCTRL_KEY 256
 LOPT_KEY 261
 LCMD_KEY 259
 LDEL_KEY 51
 RTN_KEY 36
 RSFT_KEY 258
 RCTRL_KEY 269
 ROPT_KEY 262
 RCMD_KEY 260
 EJ_KEY
 FN_KEY 279
 RDEL_KEY 117
 HOME_KEY 115
 END_KEY 119
 PUP_KEY 116
 PDOWN_KEY 121
 CLR_KEY 71


# Numeric keyboard keys, preceded by NK
NKEQ_KEY is the equal (=) key
KSL_KEY is the slash (/) key
NKWC_KEY is the wildcard (*) key
NKMN_KEY is the minus (-) key
NKPL_KEY is the plus (+) key
NKPT_KEY is the point (.) key
NKNTR_KEY is the enter key

 NK1_KEY 83
 NK2_KEY 84
 NK3_KEY 85
 NK4_KEY 86
 NK5_KEY 87
 NK6_KEY 88
 NK7_KEY 89
 NK8_KEY 91
 NK9_KEY 92
 NK0_KEY 82
 NKEQ_KEY 81
 NKSL_KEY 75
 NKWC_KEY 67
 NKMN_KEY 78
 NKPL_KEY 69
 NKPT_KEY 65
 NKNTR_KEY 76
