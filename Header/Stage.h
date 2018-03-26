//#include "Header.h"
#include "Effect.h"
#include <string>
using namespace std;
#include "Danmaku.h"
#ifndef STAGE
#define STAGE


class Stage{
	
	
public:
#define ITEM_LIMIT  500
#define TEKIDATA  2000
	Effect eff;
	void Stage::Input_Address(Stage * stage){
		Enemy[1][0] = stage->Enemy[1][0];
		Enemy[1][1] = stage->Enemy[1][1];
		Enemy[1][2] = stage->Enemy[1][2];
		Enemy[1][3] = stage->Enemy[1][3];
		Enemy[1][4] = stage->Enemy[1][4];
		Enemy[1][5] = stage->Enemy[1][5];
		Enemy[1][6] = stage->Enemy[1][6];
		Enemy[2][0] = stage->Enemy[2][0];
		Enemy[2][1] = stage->Enemy[2][1];
		Enemy[2][2] = stage->Enemy[2][2];
		Enemy[2][3] = stage->Enemy[2][3];
		Enemy[2][4] = stage->Enemy[2][4];
		Enemy[2][5] = stage->Enemy[2][5];
		Enemy[2][6] = stage->Enemy[2][6];
		Enemy[3][0] = stage->Enemy[3][0];
		Enemy[3][1] = stage->Enemy[3][1];
		Enemy[3][2] = stage->Enemy[3][2];
		Enemy[3][3] = stage->Enemy[3][3];
		Enemy[3][4] = stage->Enemy[3][4];
		Enemy[3][5] = stage->Enemy[3][5];
		Enemy[3][6] = stage->Enemy[3][6];
		Enemy[4][0] = stage->Enemy[4][0];
		Enemy[4][1] = stage->Enemy[4][1];
		Enemy[4][2] = stage->Enemy[4][2];
		Enemy[4][3] = stage->Enemy[4][3];
		Enemy[4][4] = stage->Enemy[4][4];
		Enemy[4][5] = stage->Enemy[4][5];
		Enemy[4][6] = stage->Enemy[4][6];
		Enemy[5][0] = stage->Enemy[5][0];
		Enemy[6][0] = stage->Enemy[6][0];
		rest = stage->rest;
		itemimg[1] = stage->itemimg[1];
		itemimg[2] = stage->itemimg[2];
		itemimg[3] = stage->itemimg[3];
		itemimg[4] = stage->itemimg[4];
		itemimg[5] = stage->itemimg[5];
		itemimg[6] = stage->itemimg[6];
		color.white = stage->color.white;
		color.black = stage->color.black;
		color.red = stage->color.red;
		color.green = stage->color.green;
		color.blue = stage->color.blue;
		color.glay = stage->color.glay;
		ClearBonusfont = stage->ClearBonusfont;
		SpellBonusfont = stage->SpellBonusfont;
		Stagefont = stage->Stagefont;
		Bossnamefont = stage->Bossnamefont;
		Talkfont = stage->Talkfont;
		Smallfont = stage->Smallfont;
		Namefont = stage->Namefont;
	}
	void Stage::ClearEnemyData(){
		int p;
		for (p = 0; p < TEKIDATA; p++){
			teki[p].hitpoint = 0;
			teki[p].imgposi = 0;
			teki[p].np = 0;
			teki[p].pp = 0;
			teki[p].ready = 0;
			teki[p].scene = 0;
			teki[p].start = 0;
			teki[p].tekishu = 0;
			teki[p].vecx = 0;
			teki[p].vecy = 0;
			teki[p].x = 0;
			teki[p].y = 0;
			teki[p].poweritem = 0;
			teki[p].tenitem = 0;
			tteki[p].fugou = 0;
			tteki[p].kanshu = 0;
			tteki[p].usef = 0;
			tteki[p].counter = false;
		}
		tekicount = 0;
		ClearTukaima();
		ClearItemData();
		Bosshit = false;
		Bossbuttle = false;
		Spell = false;
		SpellKardName = "";
		teki[0].np = 1;
		tail = 1;
		BossStandPosition = -1;
	}
	void Stage::DeleteEnemy(int p){
		teki[teki[p].pp].np = teki[p].np;
		teki[teki[p].np].pp = teki[p].pp;
		tekicount--;
		if (tekicount == 0){
			p = 0;
		}
	}
	void Stage::Input_Data(char* stagename, int itemaverage){
		//�[�����[�g����(�Y����0�̏ꏊ��np�Ƀ��[�g��ݒ肵�Atail�̎�O�܂ŏ����������)�œǂݍ��݂܂��B
		ClearEnemyData();
		ClearItemData();
		if (PlayerData.practice){
			TenBonus = 10000;
		}
		else{
			if (stagename == "Stage1"){
				TenBonus = 10000;
			}
		}
		
		char* ctx = "";
		TCHAR data[70] = "";
		int datalen = sizeof(data);
		int tc = 1;//Stage1�œo�ꂷ��U�R�G�̑����ł��B�z��ւ̊i�[����у|�C���^����ɗ��p����܂��B
		int t = 0;//tteki�̊i�[�ꏊ�𔻒f���邽�߂̕ϐ��ł��B
		int tt = 0;//tteki�f�[�^�̎�ނ������ϐ��ł��B
		int ttekidata;//tteki�f�[�^���ꎞ�I�ɕێ�����ϐ��ł��B
		int endflg = 0;//�t�@�C���̏I�[�܂œǂݍ��񂾎��Ƀt���O�������܂��B
		int f;
		f = _chdir("data");
		f = _chdir("Stage");
		f = _chdir(stagename);
		int file = FileRead_open("Data.csv");
		Miss = false;
		while (endflg == 0){
			ZeroMemory(data,datalen);
			f = FileRead_gets(data, 70, file);

			if (FileRead_eof(file) != 0){ endflg = 100; }
			teki[tc].scene = atoi(strtok_s(data, ",", &ctx));
			teki[tc].x = atof(strtok_s(NULL, ",", &ctx));
			teki[tc].y = atof(strtok_s(NULL, ",", &ctx));
			teki[tc].vecx = atof(strtok_s(NULL, ",", &ctx));
			teki[tc].vecy = atof(strtok_s(NULL, ",", &ctx));
			teki[tc].tekishu = atoi(strtok_s(NULL, ",", &ctx));
			teki[tc].imgposi = atoi(strtok_s(NULL, ",", &ctx));
			teki[tc].hitpoint = atoi(strtok_s(NULL, ",", &ctx));
			teki[tc].ready = atoi(strtok_s(NULL, ",", &ctx));
			teki[tc].start = -1;//�o�����Ă��Ȃ��G��-1�̂܂܁B0�ȏ�ŏo�����Ă��邱�Ƃ������B
			teki[tc].poweritem = atoi(strtok_s(NULL, ",", &ctx));
			teki[tc].tenitem = atoi(strtok_s(NULL, ",", &ctx));
			if (teki[tc].poweritem == 0 && teki[tc].tenitem == 0){
				teki[tc].poweritem = GetRand(itemaverage - 1);
				teki[tc].tenitem = GetRand(itemaverage - 1);
				if (tc % 2 == 1){
					while (teki[tc].tenitem + teki[tc].poweritem + teki[tc - 1].tenitem + teki[tc - 1].poweritem < itemaverage){
						teki[tc].poweritem = GetRand(itemaverage - 1);
						teki[tc].tenitem = GetRand(itemaverage - 1);
					}
				}
			}
			tt = atoi(strtok_s(NULL, ",", &ctx));
			t = 4;
			while (tt != 0){
				if (tt > t - 1){
					ttekidata = atoi(strtok_s(NULL, ",", &ctx));
					switch (t){
					case 1:
						tteki[tc].kanshu = ttekidata;
						break;
					case 2:
						tteki[tc].fugou = ttekidata;
						break;
					case 4:
						tteki[tc].usef = ttekidata;
						
						break;
					default:
						break;
					}
					tt -= t;
				}

				t /= 2;
			}
			
			teki[tc].pp = tc - 1;
			teki[tc].np = tc + 1;
			tc++;
		}
		f = FileRead_close(file);
		f = _chdir("..");
		f = _chdir("..");
		f = _chdir("..");
		SetTransColor(0, 0, 0);
	}
	int Stage::CountNewEnemy(int newscene,int time){
		int count = 0;
		time *= 60;
		if (tekicount == 0){
			for (int p = 1; p < 501; p++){
				if (teki[p].scene == newscene){
					teki[0].np = p;
					teki[p].pp = 0;
					tail = p;
					break;
				}
			}
		}
		while (teki[tail].scene == newscene && newscene != 0){
			if (teki[tail].ready < time){
				count++;
			}
			else{
				if (tekicount == 0){
					teki[0].np = tail + 1;
				}
				else{
					tekicount += 1;
					DeleteEnemy(tail);
				}
			}
			tail++;
		}
		return count;
	}
	void Stage::RefreshItem(){
		ITEM refitem[ITEM_LIMIT];
		int p = item[0].np;
		int pp = 1;
		while(p < itemtail && pp < itemtail + 1){
			refitem[pp].homing = item[p].homing;
			refitem[pp].imggapp = item[p].imggapp;
			refitem[pp].imgp = item[p].imgp;
			refitem[pp].itemshu = item[p].itemshu;
			refitem[pp].start = item[p].start;
			refitem[pp].x = item[p].x;
			refitem[pp].y = item[p].y;
			pp++;
			p = item[p].np;
		}
		if (pp > itemtail + 1){
			itemtail = 1;
		}
		ClearItemData();
		item[0].np = 1;
		itemtail = pp;
		itemcount = pp - 1;
		p = 1;
		while(p != itemtail){
			item[p].homing = refitem[p].homing;
			item[p].imggapp = refitem[p].imggapp;
			item[p].imgp = refitem[p].imgp;
			item[p].itemshu = refitem[p].itemshu;
			item[p].start = refitem[p].start;
			item[p].x = refitem[p].x;
			item[p].y = refitem[p].y;
			item[p].np = p + 1;
			item[p].pp = p - 1;
			p++;
		}
		p = 1;
		if (itemcount == 0){
			p = 1;
		}
	}
	void Stage::Input_Item(){//�A�C�e���摜��o�^���܂��B
		int r;
		itemimg[0] = 0;
		itemimg[1] = 0;
		itemimg[2] = 0;
		itemimg[3] = 0;
		itemimg[4] = 0;
		itemimg[5] = 0;
		itemimg[6] = 0;
		r = _chdir("data");
		r = _chdir("img");
		r = _chdir("item");
		itemimg[2] = LoadGraph("ten.bmp");
		itemimg[1] = LoadGraph("power.bmp");
		itemimg[5] = LoadGraph("extend.bmp");
		itemimg[4] = LoadGraph("bomb.bmp");
		//itemimg[6] = LoadGraph("hoshi.bmp");
		itemimg[3] = LoadGraph("full.bmp");
		
		//�A�C�e���摜�o�^
		r = _chdir("..");
		r = _chdir("..");
		r = _chdir("..");
	}
	void Stage::SetItem(double x,double y,int flame,int powercount,int tencount){
		//�Q�[�����Ŕ��������A�C�e�����v���Z�X���ɓo�^���܂��Bpoweritem,tenitem�Ƃ��ɍő��50(���v��100)�Ƃ��܂��B
		//�܂�poweritem��100�ȏ�̂Ƃ��̓G�N�X�e���h��o�^��poweritem����100���������l���p���[�A�C�e�����Ƃ��܂��Btenitem���{����o�^����_�ȊO�͓��l�ł��B
		int p;
		bool bomb = false;
		bool extend = false;
		if(itemcount == 0 && itemtail == 1){
			//�ꔭ�ڂ̒e����dan[1]�ɔz�u
			p = 1;
		}else{
			//����ȊO��itemtail�ɔz�u
			p = itemtail;
		}
		if(powercount > 150 || tencount > 150){
			powercount = 0;
			tencount = 0;
		}
		if (powercount > 99){
			powercount -= 100;
			extend = true;
		}
		if (tencount > 99){
			tencount -= 100;
			bomb = true;
		}
		if (itemtail + tencount + powercount >= ITEM_LIMIT - 50){
			RefreshItem();
		}
		while(powercount != 0 || tencount != 0){
			if(powercount > 0){				
				//�p���[�A�C�e����o�^ 
				item[p].x = x + GetRand(30); -15;
				item[p].y = y + GetRand(30); -15;
				item[p].imgp = itemimg[1];
				item[p].itemshu = 1;
				powercount--;
			}else{
				if (tencount > 0){
					//�_�A�C�e����o�^
					item[p].x = x + GetRand(30); -15;
					item[p].y = y + GetRand(30); -15;
					item[p].imgp = itemimg[2];
					item[p].itemshu = 2;
					tencount--;
				}
			}
			
			item[p].imggapp = itemgapp[item[p].itemshu];
			if(item[p].x - item[p].imggapp < 20){
				item[p].x = 20;
			}
			if(item[p].x + item[p].imggapp > 404){
				item[p].x = 380;
			}
			item[p].start = flame;
			item[p].pp = p - 1;
			item[p].np = p + 1;
			p++;
			itemcount++;
		}
		if (extend){
			//�G�N�X�e���h��o�^
			item[p].x = x;
			item[p].y = y - 10;
			item[p].itemshu = 5;
			item[p].imgp = itemimg[5];
			item[p].imggapp = itemgapp[item[p].itemshu];
			if (item[p].x - item[p].imggapp < 20){
				item[p].x = 20;
			}
			if (item[p].x + item[p].imggapp > 404){
				item[p].x = 380;
			}
			item[p].start = flame;
			item[p].pp = p - 1;
			item[p].np = p + 1;
			p++;
			itemcount++;
		}
		if (bomb){
			//�{����o�^
			item[p].x = x;
			item[p].y = y;
			item[p].imgp = itemimg[4];
			item[p].itemshu = 4;
			item[p].imggapp = itemgapp[item[p].itemshu];
			if (item[p].x - item[p].imggapp < 20){
				item[p].x = 20;
			}
			if (item[p].x + item[p].imggapp > 404){
				item[p].x = 380;
			}
			item[p].start = flame;
			item[p].pp = p - 1;
			item[p].np = p + 1;
			p++;
			itemcount++;
		}
		itemtail = p;
	}
	void Stage::SetItem(int bossx, int bossy, int flame, int powercount, int tencount){
		//�Q�[�����Ŕ��������A�C�e�����v���Z�X���ɓo�^���܂��Bpoweritem,tenitem�Ƃ��ɍő��50(���v��100)�Ƃ��܂��B
		//�܂�poweritem��100�ȏ�̂Ƃ��̓G�N�X�e���h��o�^��poweritem����100���������l���p���[�A�C�e�����Ƃ��܂��Btenitem���{����o�^����_�ȊO�͓��l�ł��B
		//����Ƀ{�X�ʒu�}40xy�͈͓̔��Ƀ����_���ɃA�C�e����o�^���܂��B
		int p;
		bool bomb = false;
		bool extend = false;
		if (itemcount == 0 && itemtail == 1){
			//�ꔭ�ڂ̒e����dan[1]�ɔz�u
			p = 1;
		}
		else{
			//����ȊO��itemtail�ɔz�u
			p = itemtail;
		}
		if ((powercount > 150 && powercount > 50) || (tencount > 150 && tencount > 50)){
			powercount = 0;
			tencount = 0;
		}
		if (powercount > 99){
			powercount -= 100;
			extend = true;
		}
		if (tencount > 99){
			tencount -= 100;
			bomb = true;
		}
		if (itemtail + tencount + powercount >= ITEM_LIMIT - 50){
			RefreshItem();
		}
		while (powercount != 0 || tencount != 0){
			if (powercount > 0){
				//�p���[�A�C�e����o�^ 
				item[p].x = bossx + GetRand(40) - 20;
				item[p].y = bossy + GetRand(40) - 20;
				item[p].imgp = itemimg[1];
				item[p].itemshu = 1;
				powercount--;
			}
			else{
				if (tencount > 0){
					//�_�A�C�e����o�^
					item[p].x = bossx + GetRand(40) - 20;
					item[p].y = bossy + GetRand(40) - 20;
					item[p].imgp = itemimg[2];
					item[p].itemshu = 2;
					tencount--;
				}
			}

			item[p].imggapp = itemgapp[item[p].itemshu];
			if (item[p].x - item[p].imggapp < 20){
				item[p].x = 20;
			}
			if (item[p].x + item[p].imggapp > 404){
				item[p].x = 380;
			}
			item[p].start = flame;
			item[p].pp = p - 1;
			item[p].np = p + 1;
			p++;
			itemcount++;
		}
		if (extend){
			//�G�N�X�e���h��o�^
			item[p].x = bossx;
			item[p].y = bossy - 10;
			item[p].itemshu = 5;
			item[p].imgp = itemimg[5];
			item[p].imggapp = itemgapp[item[p].itemshu];
			if (item[p].x - item[p].imggapp < 20){
				item[p].x = 20;
			}
			if (item[p].x + item[p].imggapp > 404){
				item[p].x = 380;
			}
			item[p].start = flame;
			item[p].pp = p - 1;
			item[p].np = p + 1;
			p++;
			itemcount++;
		}
		if (bomb){
			//�{����o�^
			item[p].x = bossx;
			item[p].y = bossy;
			item[p].imgp = itemimg[4];
			item[p].itemshu = 4;
			item[p].imggapp = itemgapp[item[p].itemshu];
			if (item[p].x - item[p].imggapp < 20){
				item[p].x = 20;
			}
			if (item[p].x + item[p].imggapp  > 404){
				item[p].x = 380;
			}
			item[p].start = flame;
			item[p].pp = p - 1;
			item[p].np = p + 1;
			p++;
			itemcount++;
		}
		itemtail = p;
	}
	void Stage::SetItem(double x,double y,int flame,int hoshicount){
		//�{���g�p��{�X��Ȃǂɓo�ꂷ�鐯�A�C�e���̓o�^���s���܂��B
		int p = itemtail;
		if (itemtail + hoshicount >= ITEM_LIMIT){
			RefreshItem();
		}
		while(hoshicount != 0){
			item[p].x = x;
			item[p].y = y;
			item[p].imgp = itemimg[3];
			item[p].itemshu = 3;
			item[p].imggapp = itemgapp[item[p].itemshu];
			hoshicount -= 1;
			itemcount++;
			item[p].start = flame;
			item[p].pp = p - 1;
			item[p].np = p + 1;
			itemtail = p + 1;
			p++;
			itemcount++;
			if(itemcount == 1){
				item[0].np = p;
			}
		}
	}
	void Stage::SetFullItem(double x,double y){
		//�{���g�p��{�X��Ȃǂɓo�ꂷ��t���p���[�A�C�e���̓o�^���s���܂��B
		int p = itemtail;
		int fullcount = 3;
		while(fullcount != 0){
			item[p].x = x;
			item[p].y = y;
			item[p].imgp = itemimg[3];
			item[p].itemshu = 6;
			item[p].imggapp = itemgapp[5];
			fullcount -= 1;
			itemcount++;
			item[p].start =1;
			item[p].pp = p - 1;
			item[p].np = p + 1;
			itemtail = p + 1;
			p++;
		}
	}
	void Stage::DeleteItem(int p){
		item[item[p].pp].np = item[p].np;
		item[item[p].np].pp = item[p].pp;
		itemcount--;
		if (itemcount == 0){
			ClearItemData();
		}
	}
	void Stage::ClearItemData(){
		int p;
		for (p = 0; p < ITEM_LIMIT; p++){
			item[p].y = 0;
			item[p].x = 0;
			item[p].imggapp = 0;
			item[p].imgp = 0;
			item[p].itemshu = 0;
			item[p].start = 0;
			item[p].homing = false;
			item[p].np = 0;
			item[p].pp = 0;
		}
		itemtail = 1;
		item[0].np = 1;
		itemcount = 0;
	}//
	void Stage::ExtendPlayerData(int dif,char* name,int cs ,bool prac){//Stage�N���X�Ƀv���C���[�f�[�^��o�^���܂��B
		//�����œ�Փx�A������Ŏ��@���A�Q�[�����̃X�e�[�W�Apractice��PracticeMode�̎���TRUE,GameMode�̎���FALSE�ɂȂ�܂��B
		PlayerData.difficulty = dif;
		PlayerData.partner = name;
		PlayerData.currentstage = cs;
		PlayerData.practice = prac;
		if(prac){
			PlayerData.choicestage = PlayerData.currentstage - 10;
		}else{
			PlayerData.choicestage = 0;
		}
		if (name == "Futo"){
			PlayerData.jikinum = 0;
		}
		if (name == "Mima"){
			PlayerData.jikinum = 1;
		}
		if (name == "Sanae"){
			PlayerData.jikinum = 2;
		}
		if (name == "Sakuya"){
			PlayerData.jikinum = 3;
		}
		scene = 0;//�ŏ����i�K
		Currenttime = 0;
		BossTalk = false;
	}
	int Stage::PasteDot(){//�����G�̃h�b�g�G��`�ʂ��܂��B
		int p;
		if (tekicount > 0){
			p = teki[0].np;
		}
		else{
			p = tail;
		}
		int r = 0;
		
		while (p != tail && r == 0){
			if (teki[p].ready == 0){
				if (teki[p].tekishu < 5){//�ԁ`�Ηd��
					if ((int)(teki[p].x) > 425 || (int)(teki[p].x) < -3 || (int)(teki[p].y) > 486 || (int)(teki[p].y) < -8){
						//�͈͊O�ɏo�������
						DeleteEnemy(p);
					}
					else{
						// 20x/15y�`404x/465y�͈͓̔��Ȃ�Ε��ʂɕ`�ʁB
						if (DrawGraph((int)(teki[p].x) - 21, (int)(teki[p].y) - 21, Enemy[teki[p].tekishu][teki[p].imgposi], TRUE) != 0){ r = -1; }
					}
				}
				else{
					if (teki[p].tekishu == 6){//�Ђ܂��d��
						if ((int)(teki[p].x) > 442 || (int)(teki[p].x) < -21 || (int)(teki[p].y) > 503 || (int)(teki[p].y) < -25){
							//�͈͊O�ɏo�������
							DeleteEnemy(p);
						}
						else{
							if (DrawGraph((int)(teki[p].x) - 38, (int)(teki[p].y) - 38, Enemy[teki[p].tekishu][teki[p].imgposi], TRUE) != 0){ r = -1; }
						}
					}
					else{//�Ȗ�
						if ((int)(teki[p].x) > 425 || (int)(teki[p].x) < -3 || (int)(teki[p].y) > 486 || (int)(teki[p].y) < -8){
							//�͈͊O�ɏo�������
							DeleteEnemy(p);
						}
						else{
							if (DrawGraph((int)(teki[p].x) - 21, (int)(teki[p].y) - 21, Enemy[teki[p].tekishu][teki[p].imgposi], TRUE) != 0){ r = -1; }
						}
					}
				}
			}
			p = teki[p].np;
		}
		if (r == -1){
			WaitKey();
			r = -1;
		}
		return r;
	}
	virtual int Stage::PasteHolizon(int flame) = 0;
	virtual int Stage::ProcessEnemy(int flame) = 0;
	virtual int Stage::Nextscene(int newscene, int powercount) = 0;
	void Stage::BossTalking(int bossstanddot, int bossselifcolor, int jikiselifcolor, int bossx, int bossy, int jikiy,int special){
		//�Z���t�J���[�ݒ�◧���G�ւ̏���
		if (special == 0){
			//�ʏ�g�[�N��ݒ�
			if (JikiStandPosition != -1){
				if (Shadowflg == 0){
					SetDrawBright(100, 100, 100);
					DrawGraph(-10, 210, jikistand, true);
					SetDrawBright(255, 255, 255);
				}
				else{
					DrawGraph(-10, 210, jikistand, true);
				}
			}

			if (BossStandPosition != -1){
				if (Shadowflg == 1){
					SetDrawBright(100, 100, 100);
					DrawGraph(bossx, bossy, bossstanddot, true);
					SetDrawBright(255, 255, 255);
				}
				else{
					DrawGraph(bossx, bossy, bossstanddot, true);
				}
			}
		}
		else{
			//����ȃg�[�N��ݒ�
			switch (special){
			case 100:
				//���@�ƃ{�X������
				DrawGraph(-10, 210, jikistand, true);
				DrawGraph(bossx, bossy, bossstanddot, true);
				break;
			case 200:
				//�t�@�C�i���X�y�������O�̃��X�{�X�̓Ɣ�
				break;
			}
		}
		DrawBox(25, 400, 400, 460, GetColor(80, 80, 80), true);
		DrawBox(26, 401, 399, 459, GetColor(0, 0, 0), true);
		if (special != 100){
			if (Shadowflg == 0){
				SelifColor = bossselifcolor;
			}
			else{
				SelifColor = jikiselifcolor;
			}
			//
			DrawStringToHandle(28, 406, selif1, SelifColor, Talkfont);
			if (selif2 != ""){
				DrawStringToHandle(28, 430, selif2, SelifColor, Talkfont);
			}
		}
		else{
			SelifColor = bossselifcolor;
			DrawStringToHandle(28, 406, selif1, SelifColor, Talkfont);
			SelifColor = jikiselifcolor;
			DrawStringToHandle(28, 430, selif2, SelifColor, Talkfont);
		}
	}
	void Stage::ProcessTalk(char * jikiname,int jikicolor, char * &talkevent,
		int stdnum[],int jy, int by1, char * bossname1, int bossstand1[], int bosscolor1){
		//�ŏ��ɃZ���t�f�[�^��ǂݍ��ށB
		talk.nowtalk = 1;//���@�ƓG�����\��
		int n;
		char * stx = "";
		char * nowtalk = "";
		char * data = "";
		//�L������:�\��Y��:�g�[�N���e1:�g�[�N���e2
		FileRead_gets(data, 70, Talkfile);
		nowtalk = strtok_s(data, ":", &stx);
		if (nowtalk == "��"){
			//BGM�ύX�Ȃǂ̃g�[�N�C�x���g�̍ۂɂ̓C�x���g���e��talkevent�ɋL�^���֐����I������B
			talkevent = strtok_s(NULL, ":", &stx);
			return;
		}
		n = atoi(strtok_s(NULL, ":", &stx));
		if (n > 100){
			if (n < 200){
				talk.nowtalk = 2;//���@�̂ݕ\��
				n -= 100;
			}
			else{
				if (n < 300){
					talk.nowtalk = 3;//�{�X�̂ݕ\��
					n -= 200;
				}
				else{
					if (n < 400){
						talk.nowtalk = 4;//������\��
						n -= 300;
					}
					else{
						talk.nowtalk = 5;//����
						n -= 400;
					}
				}
			}
		}
		//���Ƀf�[�^�ƕ�������r���A�ǂ̗����G�𖾂邭�`�ʂ��邩�����߂�B
		if (strcmp(nowtalk, jikiname) == 0){
			//���@�̏ꍇ
			talk.color = jikicolor;
			talk.lateupdate = 1;
			if (jstand[n] < 1){
				n = 1;
			}
			stdnum[0] = n;
		}
		else{
			talk.lateupdate = 0;
			talk.color = bosscolor1;
			if (bossstand1[n] < 1){
				n = 1;
			}
			stdnum[1] = n;
		}
		talk.selif1 = strtok_s(NULL, ":", &stx);
		talk.selif2 = strtok_s(NULL, ":", &stx);
	}
	
	void Stage::ProcessTalk2(char * jname, int jikicolor, char * &talkevent
		, char * bossname1, int bosscolor1, int bossstand1[]
		, char * bossname2, int bosscolor2, int bossstand2[]){
		//�ŏ��ɃZ���t�f�[�^��ǂݍ��ށB

		char * jikiname = jname;
		int n;
		char * stx = "";
		char * nowtalk = "";
		char data[100];
		//�L������:�\��Y��:�g�[�N���e1:�g�[�N���e2
		FileRead_gets(data, 100, Talkfile);
		nowtalk = strtok_s(data, ":", &stx);

		if (strcmp(nowtalk, "��") == 0){
			//BGM�ύX�Ȃǂ̃g�[�N�C�x���g�̍ۂɂ̓C�x���g���e��talkevent�ɋL�^���֐����I������B
			talkevent = strtok_s(NULL, ":", &stx);
			return;
		}
		n = atoi(strtok_s(NULL, ":", &stx));
		talk.nowtalk = 1;
		if (n > 99){//�f�t�H���g�ŗ����\��
			if (n < 200){
				talk.nowtalk = 2;//���@�̂ݕ\��
				n -= 100;
			}
			else{
				if (n < 300){
					talk.nowtalk = 3;//�{�X�̂ݕ\��
					n -= 300;
				}
				else{
					if (n < 400){
						talk.nowtalk = 4;//������\��
						n -= 300;
					}
					else{
						if (n < 500){
							talk.nowtalk = 5;//����
							n -= 400;
						}
						else{
							talk.nowtalk = 6;//��l�̃{�X�̋���
							n -= 500;
						}
					}
				}
			}
		}
		talk.name = nowtalk;
		//���Ƀf�[�^�ƕ�������r���A�ǂ̗����G�𖾂邭�`�ʂ��邩�����߂�B
		if (strcmp(nowtalk, jikiname) == 0){
			//���@�̏ꍇ
			talk.color = jikicolor;
			if (jstand[n] < 1){
				n = 1;
			}
			talk.jstand = jstand[n];
			switch (talk.lateupdate){
			case 3:
				talk.lateupdate = 1;
				break;
			case 4:
				talk.lateupdate = 2;
				break;
			}
		}
		else{
			if (strcmp(nowtalk, bossname1) == 0){
				talk.color = bosscolor1;
				if (bossstand1[n] < 1){
					n = 1;
				}
				talk.bossstand1 = bossstand1[n];
				talk.lateupdate = 3;

			}
			else{
				if (strcmp(nowtalk, bossname2) == 0){
					talk.color = bosscolor2;
					if (bossstand2[n] < 1){
						n = 1;
					}
					talk.bossstand2 = bossstand2[1];
					talk.lateupdate = 4;
				}
				else{
					string together;
					talk.bossstand1 = bossstand1[n];
					together = jikiname;
					together += "��";
					together += bossname1;
					if (together == nowtalk){
						talk.jstand = jstand[n];
						talk.color = bosscolor1;
						talk.color2 = jikicolor;
						talk.nowtalk = 5;
					}
					else{
						talk.bossstand2 = bossstand2[n];
						talk.nowtalk = 6;
						talk.color = bosscolor1;
						talk.color2 = bosscolor2;
					}
				}

			}
		}
		talk.selif1 = strtok_s(NULL, ":", &stx);
		if (strcmp(stx, "") != 0){
			talk.selif2 = strtok_s(NULL, ":", &stx);
		}
		else{
			talk.selif2 = "";
		}
		n = 0;
	}
	void Stage::DisplayTalk(int jy,int by1,int by2){
		SetDrawBright(100, 100, 100);
		switch (talk.nowtalk){
		case 1://�����\��
			switch (talk.lateupdate){
			case 1:
				if (talk.bossstand2 != 0){
					DrawGraph(230, by2, talk.bossstand2, true);
				}
				DrawGraph(150, by1, talk.bossstand1, true);
				SetDrawBright(255, 255, 255);
				DrawGraph(-20, jy, talk.jstand, true);
				break;
			case 2:
				DrawGraph(150, by1, talk.bossstand1, true);
				DrawGraph(230, by2, talk.bossstand2, true);
				SetDrawBright(255, 255, 255);
				DrawGraph(-20, jy, talk.jstand, true);
				break;
			case 4:
				DrawGraph(-20, jy, talk.jstand, true);
				DrawGraph(150, by1, talk.bossstand1, true);
				SetDrawBright(255, 255, 255);
				DrawGraph(230, by2, talk.bossstand2, true);
				break;
			case 3:
				DrawGraph(-20, jy, talk.jstand, true);
				if (talk.bossstand2 != 0){
					DrawGraph(230, by2, talk.bossstand2, true);
				}
				SetDrawBright(255, 255, 255);
				DrawGraph(150, by1, talk.bossstand1, true);
				break;
			}
			break;
		case 2://���@�̂ݕ\��
			if (talk.lateupdate < 3){
				SetDrawBright(255, 255, 255);
			}
			DrawGraph(-20, jy, talk.jstand, true);
			SetDrawBright(255, 255, 255);
			break;
		case 3://�{�X�̂ݕ\��
			SetDrawBright(255, 255, 255);
			DrawGraph(200, by1, talk.bossstand1, true);
			break;
		case 4://������\��
			break;
		case 5://����
			SetDrawBright(255, 255, 255);
			DrawGraph(-20, jy, talk.jstand, true);
			DrawGraph(200, by1, talk.bossstand1, true);
			break;
		case 6://��l�̃{�X�̋���
			DrawGraph(-10, jy, talk.jstand, true);
			SetDrawBright(255, 255, 255);
			DrawGraph(230, by2, talk.bossstand2, true);
			DrawGraph(150, by1, talk.bossstand1, true);
			break;
		}
		
		DrawBox(25, 400, 400, 460, GetColor(80, 80, 80), true);
		DrawBox(26, 401, 399, 459, GetColor(0, 0, 0), true);
		
		if (talk.nowtalk < 5){
			DrawFormatStringToHandle(28, 406, talk.color, Talkfont, "%s", talk.selif1.c_str());
			if (selif2 != NULL){
				DrawFormatStringToHandle(28, 430, talk.color, Talkfont, "%s", talk.selif2.c_str());
			}
		}
		else{
			DrawFormatStringToHandle(28, 406, talk.color, Talkfont, "%s", talk.selif1.c_str());
			DrawFormatStringToHandle(28, 430, talk.color2, Talkfont, "%s", talk.selif2.c_str());
		}
		
	}
	void Stage::DisplayTalk(int jy, int by){
		SetDrawBright(100, 100, 100);
		switch (talk.nowtalk){
		case 1://���@�ƓG�����\��
			if (talk.lateupdate == 1){
				DrawGraph(170, by, talk.bossstand1, true);
				SetDrawBright(255, 255, 255);
				DrawGraph(-10, jy, talk.jstand, true);				
			}
			else{
				DrawGraph(-10, jy, talk.jstand, true);
				SetDrawBright(255, 255, 255);
				DrawGraph(170, by, talk.bossstand1, true);
			}
			break;
		case 2://���@�̂ݕ\��
			SetDrawBright(255, 255, 255);
			DrawGraph(-10, jy, talk.jstand, true);
			break;
		case 3://�G�̂ݕ\��
			SetDrawBright(255, 255, 255);
			DrawGraph(170, by, talk.bossstand1, true);
			break;
		case 4://������\��
			break;
		case 5://���@�ƓG����
			SetDrawBright(255, 255, 255);
			DrawGraph(-10, jy, talk.jstand, true);
			DrawGraph(170, by, talk.bossstand1, true);
			break;
		}
		if (talk.nowtalk < 5){
			DrawFormatStringToHandle(28, 406, talk.color, Talkfont, "%s", talk.selif1.c_str());
			if (selif2 != NULL){
				DrawFormatStringToHandle(28, 430, talk.color, Talkfont, "%s", talk.selif2.c_str());
			}
		}
		else{
			DrawFormatStringToHandle(28, 406, talk.color, Talkfont, "%s", talk.selif1.c_str());
			DrawFormatStringToHandle(28, 430, talk.color2, Talkfont, "%s", talk.selif2.c_str());
		}

	}
	void Stage::DisplayIntroBoss(int bossx,char * doublename,char * BossName,int color){
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 200);
		size_t len;
		if ( strlen(doublename) * 12 > strlen(BossName) * 20){
			len = strlen(doublename) * 12;
		}
		else{
			len = strlen(BossName) * 20;
		}
		int l = (int)(len);
		DrawBox(bossx - 2, 348, bossx + l + 2, 402, GetColor(100, 100, 100), true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND,0);
		DrawStringToHandle(bossx, 350, doublename, GetColor(200,200,200), Smallfont);
		DrawStringToHandle(bossx, 380, BossName, color, Bossnamefont);
	}
	void Stage::StartTalk(char* stagename){//�w��̉�b�t�@�C����ǂݍ��݂܂��B
		int f = 0;
		f = _chdir("data");
		f = _chdir("Stage");
		f = _chdir(stagename);
		Talkfile = FileRead_open("Talk.txt");
		f = _chdir("..");
		f = _chdir("..");
		f = _chdir("..");
	}
	
	int Stage::TalkReady(char * partname, short stdnum[]){//����̃p�[�g�i�����͎��@�ʂ̉�b�p�[�g�j�܂ŉ�b�t�@�C���̒������s���܂��B
		char talkpart[100];
		int r = 0;
		if (Talkfile == 0){
			return -1;
		}
		while (strcmp(talkpart,partname) != 0 && r == 0){
			FileRead_gets(talkpart, 100, Talkfile);
			r = FileRead_eof(Talkfile);//�w�肵���p�[�g���G���[�̎��͏I�[�ŏI������B
		}
		if (r != 0){
			r = -1;
		}
		for (int s = 0; s < 3; s++){
			stdnum[s] = 0;
		}
		return r;
	}
	void Stage::EndTalk(){
		int f = FileRead_close(Talkfile);
		Talkfile = 0;
	};
	
	int Stage::StartSpellkardEffect(int bossstand){
		int r = 0;
		SetDrawBlendMode(DX_BLENDGRAPHTYPE_ALPHA, 180);
		if (DrawGraph((int)(appearx), (int)(appeary), bossstand, true) != 0){ r = -1; }
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND,0);
		if (DrawFormatStringToHandle(404 - (int)(strlen(SpellKardName)) * 8 + 25, 420, GetColor(200, 200, 200), Namefont, "%20s", SpellKardName) != 0){ r = -1; }
		return r;
	}
	int Stage::StartSpellkardEffect(int bossstand1,int bossstand2,int bx2,int by2) {
		int r = 0;
		SetDrawBlendMode(DX_BLENDGRAPHTYPE_ALPHA, 180);
		if (DrawGraph((int)(appearx), (int)(appeary), bossstand1, true) != 0) { r = -1; }
		if (DrawGraph((int)(bx2), (int)(by2), bossstand2, true) != 0) { r = -1; }
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		if (DrawFormatStringToHandle(404 - (int)(strlen(SpellKardName)) * 8 + 25, 420, GetColor(200, 200, 200), Namefont, "%20s", SpellKardName) != 0) { r = -1; }
		return r;
	}
	void Stage::EndSpellkardEffect(int clearscore ,int bonusscore){
		DrawStringToHandle(100, 40, "Clear Bonus", GetColor(200, 200, 20), ClearBonusfont);
		DrawFormatStringToHandle(210, 40,  GetColor(200, 200, 20), ClearBonusfont,"%d",clearscore);
		if (bonusscore != 0){
			DrawStringToHandle(100, 80, "Spellkard Bonus!!", GetColor(200, 20, 20), ClearBonusfont);
			DrawFormatStringToHandle(120, 120, GetColor(200, 20, 20), SpellBonusfont,"%d",bonusscore);
		}
		
	}
	int Stage::DisplayBossStates(double RestHitpoint,short restphase){/*�{�X��ŉ�ʏ㕔�Ƀ{�X�̖��O�Ǝc��̗́A�c��t�F�[�Y����\�����܂��B
		spell�̐����ɉ���������͎��̒ʂ�
		0...�ʏ��݂̂̃t�F�[�Y�@            ���@���Q�[�W���^�����猸��
		1...�ʏ���ɃX�y���J�[�h��i��{�j�@���@��芄���ԃQ�[�W�ŕ\�����A�c��𔒃Q�[�W�ŕ\���B���Q�[�W�������B 
		2...�ʏ����I������̃X�y���J�[�h��@���@��芄���̐ԃQ�[�W�̂ݕ\�����A�ԃQ�[�W������
		3...�X�y���J�[�h��݂̂̃t�F�[�Y�@�@�@���@�ԃQ�[�W���^�����猸��
		���̑�...�G���[
		*/
		//�̗͂̓Q�[�W�ŕ\������Maxhitpoint�Ƃ̊����ɉ����ăQ�[�W�͌������܂��Brestphase�͌��j�܂ł̎c��t�F�[�Y���ł�(6�{�X�̃��X�g�X�y���͊܂܂Ȃ�)�B*/
		int r = 0;
		if(RestHitpoint > 0 && Maxhitpoint != 0){
			switch(hitpointdisp){
			case 0://�S�Ĕ��\��
				DrawBox(50,22,(int)(RestHitpoint  * 300 / Maxhitpoint) + 50,26,GetColor(255,255,255),true);
				break;
			case 1://���ʐԕ\�����A�c��͔��\��
				DrawBox(50,22,120,26,GetColor(255,120,120),true);
				DrawBox(120,22,(int)(RestHitpoint  * 230 / Maxhitpoint) + 120,26,GetColor(255,255,255),true);
				break;
			case 2://���ʐԕ\���̂܂�
				DrawBox(50,22,(int)(RestHitpoint  * 70 / Maxhitpoint) + 50,26,GetColor(255,120,120),true);
				break;
			case 3://�S�Đԕ\��
				DrawBox(50,22,(int)(RestHitpoint  * 300 / Maxhitpoint) + 50,26,GetColor(250,120,120),true);
				break;
			default:
				r = -1;
				break;
			}
			DrawFormatString(20,30,GetColor(255,255,255),"%s",BossName);
			DrawFormatString(360,20,GetColor(255,255,255),"%d",Bosstime);
			int xx = 20;
			for (restphase; restphase > 0; restphase--){
				DrawGraph(xx, 50, rest, true);
				xx += 10;
			}
		}
		return r;
	}
	void Stage::DisplaySpellStates(){
		SetDrawArea(20, 15, 404, 465);
		int len = (int)(strlen(SpellKardName)) * 8;
		DrawFormatStringToHandle(404 -  len + 25, 40, GetColor(200, 200, 200), Namefont, "%20s", SpellKardName);
		if (Spell && Currenttime > 3){
			if (SpellBonusScore != 0){
				DrawFormatStringToHandle(230, 60, GetColor(255, 255, 255), Smallfont,"BONUS %d",SpellBonusScore);
			}
			else{
				DrawStringToHandle(230, 60, "BONUS FAILED",  GetColor(255, 255, 255), Smallfont);
			}
			
		}
		if (Bosshit){
			if (SpellBonusScore > 0){
				SpellBonusScore -= decreasebonusperflame;
			}
			else{
				SpellBonusScore = 0;
			}
		}
	}
	void Stage::SetTukaima(double x, double y, double vecx, double vecy,int imgposi,int ready ,int start,int hitpoint,int tenitem,int poweritem){
		//�g�����̃f�[�^��o�^���܂��B��{�I��Nextscene�܂���Process�����ɂ����ēo�^����܂��B
		int p = ttail;
		tukaima[p].x = x;
		tukaima[p].y = y;
		tukaima[p].vecx = vecx;
		tukaima[p].vecy = vecy;
		tukaima[p].imgposi = imgposi;
		tukaima[p].ready = ready;
		tukaima[p].start = start;
		tukaima[p].hitpoint = hitpoint;
		tukaima[p].tenitem = tenitem;
		tukaima[p].poweritem = poweritem;
		tukaima[p].pp = p - 1;
		tukaima[p].np = p + 1;
		ttail = p + 1;
		tekicount++;
	}
	void Stage::ClearTukaima(){
		for (int t = 0; t < 100; t++){
			tukaima[t].hitpoint = 0;
			tukaima[t].imgposi = 0;
			tukaima[t].np = 0;
			tukaima[t].poweritem = 0;
			tukaima[t].pp = 0;
			tukaima[t].ready = 0;
			tukaima[t].tekishu = 0;
			tukaima[t].tenitem = 0;
			tukaima[t].scene = 0;
			tukaima[t].start = 0;
			tukaima[t].vecx = 0;
			tukaima[t].vecy = 0;
			tukaima[t].x = 0;
			tukaima[t].y = 0;
		}
		tukaima[0].np = 1;
		tekicount = 0;
		ttail = 1;
	};
	void Stage::DeleteTukaima(int t){
		tukaima[tukaima[t].pp].np = tukaima[t].np;
		tukaima[tukaima[t].np].pp = tukaima[t].pp;
		tekicount--;
		if (tekicount == 0){
			tekicount = 0;
		}
	}
	bool Stage::TukaimaMissJudgement(double jx,double jy,double jr){
		//�G�ʒu�ɂ����铖���蔻����s���܂��Bfalse�̎��̓Z�[�t,true�̎��̓~�X�ɂȂ�܂��B
		int p = tukaima[0].np;
		int r;
		int endflg = 0;
		while (endflg == 0 && missnothit == 0){
			r = 7;
			if (sqrt(pow(tukaima[p].x - jx, 2.0) + pow(tukaima[p].y - jy, 2.0)) < r + jr){
				return true;
			}
			p = tukaima[p].np;
			if (p >= ttail){ endflg = 100; }
		}
		return false;
	}
	/*
	|
	|
	|
	|
	*/
	
	static int  Enemy[7][7];
		/*�G���G�h�b�g�G�̕ϐ� common comleft comright left right upleft upright
		redfairy
		bluefairy
		yellowfairy
		greenfairy
		himawarifairy
		kedama �ыʉ摜��common�̂ݎg�p
		*/
	struct TEKISHU{
		static short redfairy;
		static short bluefairy;
		static short yellowfairy;
		static short greenfairy;
		static short himawari;
		static short watage;
	};
	TEKISHU tekishu;
		//�G���G�h�b�g�G�̕ϐ�
	struct TEKI{//�Œ���K�v�ȓG���ł��B���̂ق��̏���Game�N���X���̃��\�b�h�Ŏg���܂��B
	short scene;//�G���ǂ̃V�[���œo�ꂷ�邩�𐧌䂷��ϐ��ł��BNextscene�ł̃|�C���^����ŕK�v�ɂȂ�܂��B
	double x;//�G�ʒu�̂w���W�B�����_�ȉ����L�^���邪�����Ƃ��Ďg������int�^�Ƃ��ČĂяo�����B
	double y;//�G�ʒu�̂x���W�B�����_�ȉ����L�^���邪�����Ƃ��Ďg������int�^�Ƃ��ČĂяo�����B
	double vecx;//�w�������ւ̈ړ����x�B1�t���[���X�V������Ƃ���B
	double vecy;//Y�������ւ̈ړ����x�B1�t���[���X�V������Ƃ���B
	short tekishu;//�G�̎�ނ������ϐ��ł��B1 = red 2 = blue 3 = yellow 4 = green 5 = himawari 6 = kedama�ƂȂ�܂��B
	short imgposi;//�G�̈ړ������������ϐ��ł��B�摜�I���ɂ����Ďg���܂��B0.common 1.comleft 2.comright 3.left 4.right 5.upleft 6.upright
	double hitpoint;//�G�̗̑͒l�������ϐ��ł��B���ꂪ0�ɂȂ�ƌ�������|�C���^����O��܂��B
	int start;//�G���o�ꂵ�����̃t���[������ۊǂ���ϐ��ł��Bready��0�ɂȂ�Ƃ��̎��̃t���[������start�ɂȂ�܂��B
    int ready;//ProcessStage�ȂǂœG���e���𔭎˂���܂ł̃J�E���g��ꎞ��~���Ă���ēx�ړ�����܂ł̃J�E���g�Ȃǂ������܂��B
	int poweritem;//�������ꂽ�Ƃ��ɗ��Ƃ��p���[�A�C�e�����������ϐ��ł��BInput_Data���\�b�h�Őݒ肳��܂��B
	//�܂��p���[�}�b�N�X���Ɏ���25,000�_�����Z����A����ȊO��
	int tenitem;//�������ꂽ�Ƃ��ɗ��Ƃ��p���[�A�C�e�����������ϐ��ł��BInput_Data���\�b�h�Őݒ肳��܂��B
	//�����܂ł̏��͑S�ăt�@�C������ǂݍ��܂�܂��B
	int np;//���̃|�C���^
	int pp;//�O�̃|�C���^
	};
	TEKI teki[TEKIDATA];
	TEKI tukaima[100];
	struct tTEKI{//�K�v�ɉ����Ďg����G���ł��B
		short usef;//�g�p����֐��̃|�C���^�Bcalc�N���X����l������B
		short fugou;//�񎟁A�~�A�ȉ~�֐��g�p���̕����B-1���ƍ�����ɂȂ�A1���ƉE�����ɂȂ�܂��B
		short kanshu;//�֐��̎�ނ������ϐ��BGetX,GetY�֐����g�p����Ƃ��Ɉꎟ�`�ȉ~�֐�����ʂ��܂��B
		bool counter;//�ł��Ԃ��e���𔭎˂��邩�ǂ����������ϐ��Btrue�̎���HitJudgemet�Ō��j������0.01����hitpoint���c��AProcessEnemy�Œe���𔭎˂̌㌂�j���������܂��B
	};
	tTEKI tteki[TEKIDATA];
	struct COLOR{
	    static int red;
		static int yerrow;
		static int green;
		static int blue;
		static int purple;
		static int glay;
		static int black;
		static int white;
	};
	COLOR color;
	//�F���@�ԁE�E���E�΁E���E�D�E���E��
	struct PLAYERDATA{
	   static char* partner;//���̃Q�[���őI�΂ꂽ���@ Futo Mima Sanae Sakuya�̂����ꂩ
	   static int difficulty;//�Q�[���̓�Փx�B1.easy 2.normal 3.hard 4.lunatic 5.extra
	   static int jikinum;//���@����ʂ���ԍ��ł��B0.�z�s 1.���� 2.���c 3.���
	   static int choicestage;//�I�������X�e�[�W�BPracticeMode�̂ݓ��͂����BGameMode����0�B
	   static bool practice;//Practice Mode���ۂ��������ϐ��Btrue��Practice Mode��false��Game Mode�ƂȂ�B
	   static int currentstage;//���݂���X�e�[�W�������ϐ��B1.Stage1A,2.Stage1B �c 7.Stage4,8.Stage5,9.Stage6A 10.Stage6B(cr�Q��)�Ƃ���BPracticeMode�ł�0�B
	   };
	PLAYERDATA PlayerData;
	struct ITEM{
		double x;
		double y;
		int imggapp;
		int imgp;
		int itemshu;//1 = power, 2 = ten, 3 = hoshi, 4 = bomb, 5 = extend�Ƃ���B
		int start;
		bool homing;
		int pp;
		int np;

	};
	ITEM item[ITEM_LIMIT];
	struct Stage_item{
		static int ten;
		static int power;
		static int bomb;
		static int extend;
		static int hoshi;
		static int full;
	};
	static int itemimg[7];//1 = power, 2 = ten, 3 = hoshi, 4 = bomb, 5 = extend, 6 = full�Ƃ���B
	struct BOSU{
		double x;
		double y;
		double vecx;
		double vecy;
		short hitr;//�{�X�̓����蔻��i�~�j�̔��a�������ϐ��ł��B
		int start;//�{�X���o�ꂵ�����̃t���[������ێ�����ϐ��ł��B�ϐ�s�Ƃ��킹�Ď��Ԍo�߂������܂��B
		short imgpoji;
		int poweritem;
		int tenitem;
		double hitpoint;
		short phasecount;//�{�X��̃t�F�[�Y����ێ�����ϐ��ł��B�ŏ��̒ʏ��Őݒ肳��A�X�y���J�[�h�킪�I�����邽�тɌ������܂��B
	};
	struct DOTACT{
		static short common;
		static short left;
		static short right;
		static short comleft;
		static short comright;
		static short upleft;
		static short upright;
		static short act1;
		static short act2;
	};
	DOTACT DotAct;
	struct STANDACT{
		static short common;
		static short fine;
		static short angry;
		static short doubt;
		static short surprised;
		static short question;
		static short amazed;
		static short excited;
		static short strategy;
		static short cry;
	};
	STANDACT StandAct;
	struct WAVEORDER{
		static short daen;//XY���ňقȂ�ȉ~��̋O�����ݒ肳��܂��B���̈�����Y���̑��x���ݒ肳��܂�(vec��X���̂��̂Ƃ���)�B
		static short twist;//�����ʒu����P���Ȃ���悤�ɋO�����ݒ肳��܂��B���̈����ɔP���Ȃ���p�x���ݒ肳��܂��B
		static short round;//�e���������~���ɉ����ĉ�]���Ȃ���L�����Ă����N����ݒ肵�܂��B���̈����Ƀt���[���P�ʂł̉�]�p�x���ݒ肳��܂�(���̎��̒e�������͓���ŁAvecx���~�̔��a�̑����Avecy����]�p�x�̑����ƂȂ�܂�)�B�����vec�͔g��~���a�̑����ɂȂ�܂��B
		static short crossround;//�e���������~������������Ȃ����]���A�L�����Ă����O����ݒ肵�܂��B������vecx,vecy�̖�����round�Ɠ��l�ł��������e�̂݋t��]�ƂȂ�܂��B
		static short cleam;//twist���������ɂȂ�O�����ݒ肳��܂��Border1�ɔP���Ȃ���p�x�Aorder2�ɏ����ʒu�ƂȂ�~�̔��a���ݒ肳��܂�(���̏ꍇ�ŏ��ɔ��˂��ꂾ�g��e�����������V���ȃN���[���g��e����ݒ肷��d�g�݂ł���B����Ɉ�����x,y���W�͎������Ă����~�̒��S���W�Ƃ���)�B
		static short point;//�w��|�C���g�𒆐S�Ƃ����~�ւƈړ�����g��e����ݒ肵�܂��Border1�ɂ͎w��|�C���g�~�ւ̊p�x�Aorder2�ɂ͎w��|�C���g�~�̔��a���w�肵�܂��B
		static short reverse;//�g������e���B�����z�u���~����ɐݒu����A�~�����Ɍ������悤�ɒe���O������B
	};
	WAVEORDER waveorder;
	struct JIKI{
		double x;
		double y;
		int slow;
		int ok_shot;
	};
	struct TALK{
		char * name;//��b���Ă���L�����N�^�[�̖��O
		int jstand;//���@�̗����G�̃A�h���X
		int bossstand1;//���C�������G�̃A�h���X
		int bossstand2;//������l�̗����G�̃A�h���X
		int color;//�Z���t���t�H���g�̐F1
		int color2;//�Z���t���t�H���g�̐F2
		string selif1;//�Z���t��s��
		string selif2;//�Z���t��s��
		short nowtalk;//��b�`�� 1�c���@�̂ݕ\�� 2�c�����\�� 3�c�{�X�̂ݕ\�� 4�c������\�� 5�c���@6�c��l�̃{�X�̋���
		short lateupdate;//�����G�ɉe�����邩�A�����ĕ`�ʂ��鏇�Ԃ������ϐ��ł��B1�c���@(�z)���{�X2(�A)���{�X1(�A),2�c���@(�z)���{�X1(�A)���{�X2(�A),3�c�{�X2(�z)���{�X1(�A)�����@(�A),4�c�{�X2(�z)���{�X1(�A)�����@(�A)
	};
	TALK talk;
	struct BACK{
		int back;
		int by;
		int ex;
		int bossback;
		int spellback1;
		int spellback2;
		int finalback;
	};
	BACK holizon;
	JIKI j;
	//�A�C�e���摜�̕ϐ�
	static int itemgapp[7];
	//�A�C�e���摜�`�ʈʒu�̒�����//1 = power, 2 = ten, 3 = hoshi, 4 = bomb, 5 = extend, 6 = full�Ƃ���B
	static short itemtail;//item�z��̏I�[�������ϐ��ł��BProcessEnemy�܂���DeleteItem�ŕύX����܂��B
	static short itemcount;//�X�e�[�W�ɑ��݂���A�C�e�������������ϐ��ł��BCreateItem�ő�����DeleteItem�Ō������܂��B�܂�0�ɂȂ����Ɠ�����ClearItemData���N�����܂��B
	static int TenBonus;//�_�A�C�e�����擾�����ۂɉ��Z�����{�[�i�X�ł��B�����l��10000�ŃA�C�e���擾�̓x��100����悹����܂��B
	static short tekicount;//�o�����̓G�̐��������ϐ��ł��BNextscene��ProcessEnemy�ő������ADeleteEnemy��X�e�[�W�̐i�s�ɉ����Č������܂��B
	static short scene, prescene,lastscene;//�S�X�e�[�W�ŋ��ʂ��Ďg����X�e�[�W�̐i�s�x�������ϐ��ł��B
	static int Stagefont,Bossnamefont,Talkfont,Smallfont;//�X�e�[�W���A�{�X���A�Ȗ��A��b��,�����������̃t�H���g��ێ�����t�H���g�n���h���ł��BStage�R���g���N�^�Őݒ肳��܂��B
	static int Namefont,ClearBonusfont,SpellBonusfont;
	static short Begintime, Endtime, Currenttime;//Stage���̃V�[���̊J�n�ƏI���A����ь��݂̎��Ԃ��Ǘ�����ϐ��ł��B�b�P�ʂŌv�Z���܂��B
	static short s;//�V�[�����̌o�ߎ��Ԃ�b�P�ʂŎ����ϐ��ł��BProcessEnemy�����PD�ɂ�flame�Ƃ��̕ϐ��Ƃ̘a���g���܂��B
	static short tail;//teki�z��̏I�[+1�������ϐ��ł��BNextscene�ŕύX����܂��B
	static bool Bossbuttle;//���{�X�y�у{�X�Ɛ퓬�����ǂ����������ϐ��ł��BTRUE���ɂ̓V�[���ړ�������ɂȂ�܂��B
	static bool Miss;//���@����e���ă~�X�G�t�F�N�g�����ǂ����������ϐ��ł��BMissJudgement�Ŕ��f���A�G�t�F�N�g�I�����Ɏc�@�������false�ɖ߂�܂��B
	static short missnothit;//�~�X��ɐ��b�Ԃ������閳�G���Ԃ�ێ�����ϐ��ł��B
	static short missflame;//�~�X���̑���s�\���Ԃ��J�E���g����ϐ��ł��B�~�X���ɃJ�E���g���J�n��2�b�o�߂����瑀��\�ɂȂ�܂��B
	static int Talkcount;//���ꂼ��̉�b�t�F�[�Y�ɂ������b���������ϐ��ł��BNextphase���\�b�h�Őݒ肳��Talk���\�b�h�ŏ����܂��B
	static bool TalkSkipCancel;//�g�[�N�V�[���˓����ɃX�L�b�v�̏����𖞂����Ă������ɃX�L�b�v�𖳌��ɂ���ϐ��ł��B�L���ɂ���ɂ͈�U�{�^����b������ōēx�X�L�b�v����͂���K�v������܂��B
	static short ttail;//�g�����̏I�[�|�C���^�ʒu�������ϐ��ł��B
	int totalscore;//1�t���[�����ɔ��������X�R�A��ێ�����ϐ��ł��B�����Ɠ����ɏW�v����Jiki�N���X�ŉ��Z����܂��B
	int jikistand;
	static int jstand[15];//ProcessTalk�Ŏg�p����鎩�@�����G�f�[�^�̂���|�C���^�z��̂��ƁBStageStart�ɂă|�C���^�����蓖�Ă���B
	static short ChangeBGMtalkcount;//BGM���ς���b�̃^�C�~���O��ێ�����ϐ��ł��BNextScene�Őݒ肳��AJiki�N���X����BGM��ύX���܂��B
	static short ChangeBGMNumber;//��b���ɕς��BGM�̃i���o�[��ێ�����ϐ��ł��BNextScene�Őݒ肳��AJiki�N���X����BGM��ύX���܂��B

	static int StageClearscore;
	bool BossTalk;
	int Talkfile;
	static int BeforeJikiStand,BeforeBossStand;//�{�X��O�̉�b�Ŏg����ȑO�̉�b���̗����G�f�[�^��ێ�����ϐ��ł��B��b�Ώۂ��؂�ւ��ƃV�F�[�h���H����܂��B
	static short Bosstime;//�t�F�[�Y����������(�b�P��)�����߂��ϐ��ł��B
	static short Looptime;//�t�F�[�Y���̃��[�v���ԁi�b�P�ʁj�������ϐ��ł��B
	static short timetoflame;
	static double Maxhitpoint;//�e�{�X��ł̍ő�̗͂�ێ�����ϐ��ł��BDisplayBossStates���\�b�h�ł͎c��̗͂ƍő�̗͂̊����ɉ����đ̗̓Q�[�W��\�����܂��B
	//�܂�Nextphase���Ăяo�����x�ɖ���ύX����܂��B
	static bool Spell;//�X�y���J�[�h�킩�ǂ����������ϐ��ł��Btrue�ł���΃X�y���J�[�h��̏�Ԃł��BNextphase���\�b�h�ŕύX����܂��B
	static char* BossName;//�{�X�̖��O��ێ�����ϐ��ł��B�e�T�u�N���X��Nextphase���\�b�h�Őݒ肳��ADisplayBossStates���\�b�h�ŕ\������܂��B
	static char* SpellKardName;//�X�y���J�[�h�̖��O��ێ�����ϐ��ł��B�e�T�u�N���X��Nextphase���\�b�h�Őݒ肳��A�{�X�h�b�g�̕`�ʌ�ɕ`�ʂ���܂��B
	static int SpellBonusScore;//�X�y���J�[�h����m�[�~�X�m�[�{���ŃN���A�����ۂɉ��Z�����{�[�i�X�X�R�A��ێ�����ϐ��ł��B�{���g�p�܂��̓~�X�ɂ����0�ɂȂ�܂��B
	static int EndBonusScore;//�ʏ���X�y���J�[�h��Ń^�C���A�b�v�O�Ƀ{�X��|�����Ƃ��ɉ��Z�����X�R�A��ێ�����ϐ��ł��B�|������Ȃ���0�ɂȂ�A�{�[�i�X�\��������܂���B
	static int decreasebonusperflame;//1�t���[�����ƂɌ�������{�[�i�X�X�R�A�������ϐ��ł��B0�̎��͌������܂���B = SpellBonusScore / Bosstime;
	static int PreBonusScore;//�X�y���J�[�h�킪�A�����ċN�������ꍇ�ɑO��̃{�[�i�X�X�R�A��ێ�����ϐ��ł��BNextScene�Őݒ肳�ꎟ�̃X�y���J�[�h��ɓ˓�����O��EndSpellKardEffect�ŕ\������܂��B
	static char* selif1;
	static char* selif2;//�g�[�N���̉�b���e��ێ�����ϐ��ł��B���ꂼ��̃v���Z�X�{�X���\�b�h�Őݒ�E�g�p����܂��B
	static int jikicolor;
	static int standx;
	static int standy;//���@�̗����G�̕`�ʈʒu(x,y)�����߂��ϐ��ł��B���@�ɂ��قȂ�܂��B
	static bool Bosshit;//�{�X�̓����蔻����s�����ۂ��������ϐ��ł��Btrue�̎��͊eStage�T�u�N���X�Ŕ��肪�s���܂��B
	static short BossStandPosition;//�g�[�N���̃{�X�̗����G�����ʂ���ϐ��ł��B-1�̎��̓{�X�̗����G���`�ʂ���܂���B1.common,2.fine,3.question,4.doubt,5.angry,6.surprised,7.amazed(�����),8.excited,9.strategy,10.cry
	static short JikiStandPosition;//�g�[�N���̎��@�̗����G�����ʂ���ϐ��ł��B-1�̎��͎��@�̗����G���`�ʂ���܂���B1.common,2.fine,3.question,4.doubt,5.angry,6.surprised,7.amazed(�����),8.excited,9.strategy
	static int SelifColor;//�g�[�N���̃Z���t�̐F�����ʂ���ϐ��ł��B���@��{�X�ɂ��ω����܂��B
	static short Shadowflg;//�e�t���ŗ����G��`�ʂ��邩�ǂ��������ʂ���ϐ��ł��B0�̎��͎��@���A1�̎��̓{�X���e�t���ŕ`�ʂ���܂��B
	static double appearx;
	static double appeary;
	static int rest;//�{�X�펞�̎c��t�F�[�Y���������摜�ł��BStage�R���g���N�^�œǂݍ��܂�DisplayBossStates�Ȃ���DisplaySpellStates�ŕ`�ʂ���܂��B
	short hitpointdisp;//�{�X�t�F�[�Y�̗͕̑\���̃t���O�ł��BNextscene�Őݒ肳��܂��B
	short danshotcount[100];//����̃V�[�����ɔ��˂����e�����p�[�g�����������ϐ��ł��BNextscene�Őݒ肳��AProcessEnemy�ŏ����܂��B
	bool twicecircle[50];//���ڂɉ~��ʂ邩�ǂ����������z��ł��B���ڂɓ��B�����Ƃ���true�ƂȂ�܂��B
	bool result, nexttalk;
	short appear, appear2;
	

};
int  Stage::Enemy[7][7] = {{0,0,0,0,0,0,0},{0,0,0,0,0,0,0},{0,0,0,0,0,0,0},{0,0,0,0,0,0,0},{0,0,0,0,0,0,0},{0,0,0,0,0,0,0},{0,0,0,0,0,0,0}};
short Stage::TEKISHU::redfairy = 1;
short Stage::TEKISHU::bluefairy = 2;
short Stage::TEKISHU::yellowfairy = 3;
short Stage::TEKISHU::greenfairy = 4;
short Stage::TEKISHU::himawari = 5;
short Stage::TEKISHU::watage = 6;
int Stage::itemimg[7] = { 0, 0, 0, 0, 0, 0 };//1 = power, 2 = ten, 3 = full, 4 = bomb, 5 = extend, 6 = hoshi�Ƃ���B
int Stage::itemgapp[7] = { 6, 6, 6, 7, 7, 7 };	  //1 = power, 2 = ten, 3 = hoshi, 4 = bomb, 5 = extend, 6 = full�Ƃ���B
int Stage::PLAYERDATA::choicestage = 0;
int Stage::PLAYERDATA::currentstage = 0;
int Stage::PLAYERDATA::difficulty = 0;
bool Stage::PLAYERDATA::practice = false;
char* Stage::PLAYERDATA::partner = "";
int Stage::PLAYERDATA::jikinum = 0;
int Stage::COLOR::black = 0;
int Stage::COLOR::blue = 0;
int Stage::COLOR::glay = 0;
int Stage::COLOR::green = 0;
int Stage::COLOR::purple = 0;
int Stage::COLOR::red = 0;
int Stage::COLOR::white = 0;
int Stage::COLOR::yerrow = 0;
int Stage::Smallfont = 0;
int Stage::ClearBonusfont = 0;
int Stage::SpellBonusfont = 0;
int Stage::Stagefont = 0;
int Stage::Namefont = 0;
int Stage::Bossnamefont = 0;
int Stage::Talkfont = 0;
int Stage::BeforeBossStand = 0;
int Stage::BeforeJikiStand = 0;
short Stage::ChangeBGMtalkcount = 0;
short Stage::ChangeBGMNumber = 0;
short Stage::DOTACT::common = 0;
short Stage::DOTACT::left = 3;
short Stage::DOTACT::right = 4;
short Stage::DOTACT::act1 = 1;
short Stage::DOTACT::act2 = 2;
short Stage::DOTACT::comleft = 1;
short Stage::DOTACT::comright = 2;
short Stage::DOTACT::upleft = 5;
short Stage::DOTACT::upright = 6;
short Stage::STANDACT::common = 1;
short Stage::STANDACT::fine = 2;
short Stage::STANDACT::question = 3;
short Stage::STANDACT::doubt = 4;
short Stage::STANDACT::angry = 5;
short Stage::STANDACT::surprised = 6;
short Stage::STANDACT::amazed = 7;
short Stage::STANDACT::excited = 8;
short Stage::STANDACT::strategy = 9;
short Stage::STANDACT::cry = 10;
short Stage::WAVEORDER::daen = 1;
short Stage::WAVEORDER::twist = 2;
short Stage::WAVEORDER::round = 3;
short Stage::WAVEORDER::crossround = 4;
short Stage::WAVEORDER::reverse = 5;
short Stage::WAVEORDER::cleam = 1;
short Stage::WAVEORDER::point = 2;
short Stage::Looptime = 0;
short Stage::timetoflame = 0;
double Stage ::appearx = 0;
double Stage::appeary = 0;
short Stage ::Begintime = 0;
bool Stage ::Bossbuttle = false;
bool Stage::Bosshit = false;
char* Stage::BossName = "";
short Stage ::Bosstime = 0;
short Stage ::Currenttime = 0;
int Stage::decreasebonusperflame = 0;
short Stage ::Endtime = 0;
short Stage ::itemcount= 0;
short Stage ::itemtail = 0;
int Stage::jikicolor = 0;
short Stage::JikiStandPosition = 0;
short Stage ::BossStandPosition = 0;
short Stage ::missflame = 0;
short Stage ::missnothit = 0;
bool Stage::Miss = false;
double Stage ::Maxhitpoint = 0;
int Stage ::PreBonusScore = 0;
short Stage::lastscene = 0;
short Stage ::prescene = 0;
int Stage ::rest = 0;
short Stage ::s = 0;
short Stage ::scene = 0;
char* Stage ::selif1 = "";
char* Stage::selif2 = "";
short Stage ::Shadowflg = 0;
bool Stage ::Spell = false;
int Stage ::SpellBonusScore = 0;
int Stage::EndBonusScore = 0;
short Stage ::tail = 0;
char* Stage ::SpellKardName = "";
int Stage ::StageClearscore = 0;
int Stage::standx = 0;
int Stage::standy = 0; 
int Stage ::Talkcount = 0;
bool Stage ::TalkSkipCancel = false;
short Stage ::tekicount = 0;
int Stage ::TenBonus = 0;
short Stage ::ttail = 0;
int Stage ::SelifColor = 0;
int Stage::jstand[15] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

#endif