#ifndef CONTLORAR
#include "Header.h"
#define CONTLORAR
class Controlar{
public:
	Controlar::Controlar(){//ジョイパッド入力の初期設定を行います。
		setcrl.ok_shot = PAD_INPUT_4;
		setcrl.cancel_bomb = PAD_INPUT_3;
		setcrl.slow = PAD_INPUT_5;
		setcrl.porse = PAD_INPUT_12;
		setcrl.up = PAD_INPUT_UP;
		setcrl.down = PAD_INPUT_DOWN;
		setcrl.left = PAD_INPUT_LEFT;
		setcrl.right = PAD_INPUT_RIGHT;
	}
	void Controlar::GetCondition(){
		
		if((GetJoypadInputState( DX_INPUT_PAD1 ) & setcrl.ok_shot) > 0 || (GetJoypadInputState( DX_INPUT_KEY ) & PAD_INPUT_1) > 0){
			crl.ok_shot += 1;
		}else{
		    crl.ok_shot = 0;
		}
		if((GetJoypadInputState( DX_INPUT_PAD1 ) & setcrl.cancel_bomb) > 0 || (GetJoypadInputState( DX_INPUT_KEY ) & PAD_INPUT_2)  > 0){
			crl.cancel_bomb += 1;
		}else{
			crl.cancel_bomb = 0;
		}
		if((GetJoypadInputState( DX_INPUT_PAD1 ) & setcrl.slow) > 0 || GetAsyncKeyState(VK_SHIFT) & 0x8000 ){
			crl.slow += 1;
		}else{
			crl.slow = 0;
		}
		if((GetJoypadInputState( DX_INPUT_PAD1 ) & setcrl.porse) > 0 || GetAsyncKeyState(VK_CONTROL) & 0x8000){
			crl.porse += 1;
		}else{
			crl.porse = 0;
		}
		if((GetJoypadInputState( DX_INPUT_KEY_PAD1 ) & setcrl.up) > 0){
			crl.up += 1;
		}else{
			crl.up = 0;
		}
        if((GetJoypadInputState( DX_INPUT_KEY_PAD1 ) & setcrl.down) > 0){
			crl.down += 1;
		}else{
			crl.down = 0;
		}
		if((GetJoypadInputState( DX_INPUT_KEY_PAD1 ) & setcrl.left) > 0){
			crl.left += 1;
		}else{
			crl.left = 0;
		}
		if((GetJoypadInputState( DX_INPUT_KEY_PAD1 ) & setcrl.right) > 0){
			crl.right += 1;
		}else{
			crl.right = 0;
		}
	}
	int Controlar::SetButton(char* button,int hopebutton){//Titleのoptionからジョイパッドの入力ボタンを変更します。
		//ボタンは方向キーを除き1～12までとしbuttonは変更される4つのボタン(ok_shot,cancel_bomb,slow,porse)、hopebuttonは変更後のボタンを示します。
		switch(hopebutton){
		case 1:
			hopebutton = PAD_INPUT_1;
			break;
		case 2:
			hopebutton = PAD_INPUT_2;
			break;
		case 3:
			hopebutton = PAD_INPUT_3;
			break;
		case 4:
			hopebutton = PAD_INPUT_4;
			break;
		case 5:
			hopebutton = PAD_INPUT_5;
			break;
		case 6:
			hopebutton = PAD_INPUT_6;
			break;
		case 7:
			hopebutton = PAD_INPUT_7;
			break;
		case 8:
			hopebutton = PAD_INPUT_8;
			break;
		case 9:
			hopebutton = PAD_INPUT_9;
			break;
		case 10:
			hopebutton = PAD_INPUT_10;
			break;
		case 11:
			hopebutton = PAD_INPUT_11;
			break;
		case 12:
			hopebutton = PAD_INPUT_12;
			break;
		default:
			return -1;

		}
		if(button == "ok_shot"){ setcrl.ok_shot = hopebutton;}
		if(button == "cancel_bomb"){ setcrl.cancel_bomb = hopebutton;}
		if(button == "slow"){ setcrl.slow = hopebutton;}
		if(button == "porse"){ setcrl.porse = hopebutton;}
		return 0;
	}
	int Controlar::GetButton(char* button){
		int r = 0;
	    if(button == "ok_shot"){ r = crl.ok_shot;}
		if(button == "cancel_bomb"){ r = crl.cancel_bomb;}
		if(button == "slow"){ r = crl.slow;}
		if(button == "porse"){ r = crl.porse;}
		if(button == "up"){ r = crl.up;}
		if(button == "down"){ r = crl.down;}
		if(button == "left"){ r = crl.left;}
		if(button == "right"){ r = crl.right;}
	    return r;
	}
	void Controlar::SetButtonInit(){
		crl.ok_shot = 0;
		crl.cancel_bomb = 0;
		crl.up = 0;
		crl.down = 0;
		crl.left = 0;
		crl.right = 0;
		crl.slow = 0;
		crl.porse = 0;
	}
	bool Inputjoypad;//ジョイパッドが接続されているかを示す正負です。TRUE = 接続 FALSE = 未接続
private:
	struct control{
	    static int ok_shot;
		static int cancel_bomb;
		static int slow;
		static int porse;
		static int up;
		static int left;
		static int down;
		static int right;
	};
	struct Setting{
	    static int ok_shot;
		static int cancel_bomb;
		static int slow;
		static int porse;
		static int up;
		static int left;
		static int down;
		static int right;
	};
	Setting setcrl;
    control crl;//ジョイパッド及びキーボードが入力されているかどうかを示す構造体です。0 = 未入力 1 = 入力中 1以上 長押し状態
	
	
};

int Controlar::control::cancel_bomb = 0;
int Controlar::control::down = 0;
int Controlar::control::left = 0;
int Controlar::control::ok_shot = 0;
int Controlar::control::porse = 0;
int Controlar::control::right = 0;
int Controlar::control::slow = 0;
int Controlar::control::up = 0;
int Controlar::Setting::cancel_bomb = 0;
int Controlar::Setting::down = 0;
int Controlar::Setting::left = 0;
int Controlar::Setting::ok_shot = 0;
int Controlar::Setting::porse = 0;
int Controlar::Setting::slow = 0;
int Controlar::Setting::right = 0;
int Controlar::Setting::up = 0;

#endif