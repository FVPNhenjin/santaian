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
		//ゼロルート方式(添字が0の場所のnpにルートを設定し、tailの手前まで処理する方式)で読み込みます。
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
		int tc = 1;//Stage1で登場するザコ敵の総数です。配列への格納およびポインタ制御に利用されます。
		int t = 0;//ttekiの格納場所を判断するための変数です。
		int tt = 0;//ttekiデータの種類を示す変数です。
		int ttekidata;//ttekiデータを一時的に保持する変数です。
		int endflg = 0;//ファイルの終端まで読み込んだ時にフラグがたちます。
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
			teki[tc].start = -1;//出現していない敵は-1のまま。0以上で出現していることを示す。
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
	void Stage::Input_Item(){//アイテム画像を登録します。
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
		
		//アイテム画像登録
		r = _chdir("..");
		r = _chdir("..");
		r = _chdir("..");
	}
	void Stage::SetItem(double x,double y,int flame,int powercount,int tencount){
		//ゲーム内で発生したアイテムをプロセス内に登録します。poweritem,tenitemともに最大は50(合計で100)とします。
		//またpoweritemが100以上のときはエクステンドを登録しpoweritemから100を引いた値をパワーアイテム数とします。tenitemもボムを登録する点以外は同様です。
		int p;
		bool bomb = false;
		bool extend = false;
		if(itemcount == 0 && itemtail == 1){
			//一発目の弾幕はdan[1]に配置
			p = 1;
		}else{
			//それ以外はitemtailに配置
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
				//パワーアイテムを登録 
				item[p].x = x + GetRand(30); -15;
				item[p].y = y + GetRand(30); -15;
				item[p].imgp = itemimg[1];
				item[p].itemshu = 1;
				powercount--;
			}else{
				if (tencount > 0){
					//点アイテムを登録
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
			//エクステンドを登録
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
			//ボムを登録
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
		//ゲーム内で発生したアイテムをプロセス内に登録します。poweritem,tenitemともに最大は50(合計で100)とします。
		//またpoweritemが100以上のときはエクステンドを登録しpoweritemから100を引いた値をパワーアイテム数とします。tenitemもボムを登録する点以外は同様です。
		//さらにボス位置±40xyの範囲内にランダムにアイテムを登録します。
		int p;
		bool bomb = false;
		bool extend = false;
		if (itemcount == 0 && itemtail == 1){
			//一発目の弾幕はdan[1]に配置
			p = 1;
		}
		else{
			//それ以外はitemtailに配置
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
				//パワーアイテムを登録 
				item[p].x = bossx + GetRand(40) - 20;
				item[p].y = bossy + GetRand(40) - 20;
				item[p].imgp = itemimg[1];
				item[p].itemshu = 1;
				powercount--;
			}
			else{
				if (tencount > 0){
					//点アイテムを登録
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
			//エクステンドを登録
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
			//ボムを登録
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
		//ボム使用やボス戦などに登場する星アイテムの登録を行います。
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
		//ボム使用やボス戦などに登場するフルパワーアイテムの登録を行います。
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
	void Stage::ExtendPlayerData(int dif,char* name,int cs ,bool prac){//Stageクラスにプレイヤーデータを登録します。
		//数字で難易度、文字列で自機名、ゲーム中のステージ、practiceはPracticeModeの時はTRUE,GameModeの時はFALSEになります。
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
		scene = 0;//最初期段階
		Currenttime = 0;
		BossTalk = false;
	}
	int Stage::PasteDot(){//道中敵のドット絵を描写します。
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
				if (teki[p].tekishu < 5){//赤～緑妖精
					if ((int)(teki[p].x) > 425 || (int)(teki[p].x) < -3 || (int)(teki[p].y) > 486 || (int)(teki[p].y) < -8){
						//範囲外に出たら消滅
						DeleteEnemy(p);
					}
					else{
						// 20x/15y～404x/465yの範囲内ならば普通に描写。
						if (DrawGraph((int)(teki[p].x) - 21, (int)(teki[p].y) - 21, Enemy[teki[p].tekishu][teki[p].imgposi], TRUE) != 0){ r = -1; }
					}
				}
				else{
					if (teki[p].tekishu == 6){//ひまわり妖精
						if ((int)(teki[p].x) > 442 || (int)(teki[p].x) < -21 || (int)(teki[p].y) > 503 || (int)(teki[p].y) < -25){
							//範囲外に出たら消滅
							DeleteEnemy(p);
						}
						else{
							if (DrawGraph((int)(teki[p].x) - 38, (int)(teki[p].y) - 38, Enemy[teki[p].tekishu][teki[p].imgposi], TRUE) != 0){ r = -1; }
						}
					}
					else{//綿毛
						if ((int)(teki[p].x) > 425 || (int)(teki[p].x) < -3 || (int)(teki[p].y) > 486 || (int)(teki[p].y) < -8){
							//範囲外に出たら消滅
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
		//セリフカラー設定や立ち絵への処理
		if (special == 0){
			//通常トークを設定
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
			//特殊なトークを設定
			switch (special){
			case 100:
				//自機とボスが共鳴
				DrawGraph(-10, 210, jikistand, true);
				DrawGraph(bossx, bossy, bossstanddot, true);
				break;
			case 200:
				//ファイナルスペル発動前のラスボスの独白
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
		//最初にセリフデータを読み込む。
		talk.nowtalk = 1;//自機と敵両方表示
		int n;
		char * stx = "";
		char * nowtalk = "";
		char * data = "";
		//キャラ名:表情添字:トーク内容1:トーク内容2
		FileRead_gets(data, 70, Talkfile);
		nowtalk = strtok_s(data, ":", &stx);
		if (nowtalk == "※"){
			//BGM変更などのトークイベントの際にはイベント内容をtalkeventに記録し関数を終了する。
			talkevent = strtok_s(NULL, ":", &stx);
			return;
		}
		n = atoi(strtok_s(NULL, ":", &stx));
		if (n > 100){
			if (n < 200){
				talk.nowtalk = 2;//自機のみ表示
				n -= 100;
			}
			else{
				if (n < 300){
					talk.nowtalk = 3;//ボスのみ表示
					n -= 200;
				}
				else{
					if (n < 400){
						talk.nowtalk = 4;//両方非表示
						n -= 300;
					}
					else{
						talk.nowtalk = 5;//共鳴
						n -= 400;
					}
				}
			}
		}
		//次にデータと文字列を比較し、どの立ち絵を明るく描写するかを決める。
		if (strcmp(nowtalk, jikiname) == 0){
			//自機の場合
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
		//最初にセリフデータを読み込む。

		char * jikiname = jname;
		int n;
		char * stx = "";
		char * nowtalk = "";
		char data[100];
		//キャラ名:表情添字:トーク内容1:トーク内容2
		FileRead_gets(data, 100, Talkfile);
		nowtalk = strtok_s(data, ":", &stx);

		if (strcmp(nowtalk, "※") == 0){
			//BGM変更などのトークイベントの際にはイベント内容をtalkeventに記録し関数を終了する。
			talkevent = strtok_s(NULL, ":", &stx);
			return;
		}
		n = atoi(strtok_s(NULL, ":", &stx));
		talk.nowtalk = 1;
		if (n > 99){//デフォルトで両方表示
			if (n < 200){
				talk.nowtalk = 2;//自機のみ表示
				n -= 100;
			}
			else{
				if (n < 300){
					talk.nowtalk = 3;//ボスのみ表示
					n -= 300;
				}
				else{
					if (n < 400){
						talk.nowtalk = 4;//両方非表示
						n -= 300;
					}
					else{
						if (n < 500){
							talk.nowtalk = 5;//共鳴
							n -= 400;
						}
						else{
							talk.nowtalk = 6;//二人のボスの共鳴
							n -= 500;
						}
					}
				}
			}
		}
		talk.name = nowtalk;
		//次にデータと文字列を比較し、どの立ち絵を明るく描写するかを決める。
		if (strcmp(nowtalk, jikiname) == 0){
			//自機の場合
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
					together += "＆";
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
		case 1://両方表示
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
		case 2://自機のみ表示
			if (talk.lateupdate < 3){
				SetDrawBright(255, 255, 255);
			}
			DrawGraph(-20, jy, talk.jstand, true);
			SetDrawBright(255, 255, 255);
			break;
		case 3://ボスのみ表示
			SetDrawBright(255, 255, 255);
			DrawGraph(200, by1, talk.bossstand1, true);
			break;
		case 4://両方非表示
			break;
		case 5://共鳴
			SetDrawBright(255, 255, 255);
			DrawGraph(-20, jy, talk.jstand, true);
			DrawGraph(200, by1, talk.bossstand1, true);
			break;
		case 6://二人のボスの共鳴
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
		case 1://自機と敵両方表示
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
		case 2://自機のみ表示
			SetDrawBright(255, 255, 255);
			DrawGraph(-10, jy, talk.jstand, true);
			break;
		case 3://敵のみ表示
			SetDrawBright(255, 255, 255);
			DrawGraph(170, by, talk.bossstand1, true);
			break;
		case 4://両方非表示
			break;
		case 5://自機と敵共鳴
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
	void Stage::StartTalk(char* stagename){//指定の会話ファイルを読み込みます。
		int f = 0;
		f = _chdir("data");
		f = _chdir("Stage");
		f = _chdir(stagename);
		Talkfile = FileRead_open("Talk.txt");
		f = _chdir("..");
		f = _chdir("..");
		f = _chdir("..");
	}
	
	int Stage::TalkReady(char * partname, short stdnum[]){//特定のパート（多くは自機別の会話パート）まで会話ファイルの調整を行います。
		char talkpart[100];
		int r = 0;
		if (Talkfile == 0){
			return -1;
		}
		while (strcmp(talkpart,partname) != 0 && r == 0){
			FileRead_gets(talkpart, 100, Talkfile);
			r = FileRead_eof(Talkfile);//指定したパートがエラーの時は終端で終了する。
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
	int Stage::DisplayBossStates(double RestHitpoint,short restphase){/*ボス戦で画面上部にボスの名前と残り体力、残りフェーズ数を表示します。
		spellの数字に応じた分岐は次の通り
		0...通常戦のみのフェーズ　            →　白ゲージ満タンから減少
		1...通常戦後にスペルカード戦（基本）　→　一定割合赤ゲージで表示し、残りを白ゲージで表示。白ゲージが減少。 
		2...通常戦を終えた先のスペルカード戦　→　一定割合の赤ゲージのみ表示し、赤ゲージが減少
		3...スペルカード戦のみのフェーズ　　　→　赤ゲージ満タンから減少
		その他...エラー
		*/
		//体力はゲージで表示されMaxhitpointとの割合に応じてゲージは減少します。restphaseは撃破までの残りフェーズ数です(6ボスのラストスペルは含まない)。*/
		int r = 0;
		if(RestHitpoint > 0 && Maxhitpoint != 0){
			switch(hitpointdisp){
			case 0://全て白表示
				DrawBox(50,22,(int)(RestHitpoint  * 300 / Maxhitpoint) + 50,26,GetColor(255,255,255),true);
				break;
			case 1://一定量赤表示し、残りは白表示
				DrawBox(50,22,120,26,GetColor(255,120,120),true);
				DrawBox(120,22,(int)(RestHitpoint  * 230 / Maxhitpoint) + 120,26,GetColor(255,255,255),true);
				break;
			case 2://一定量赤表示のまま
				DrawBox(50,22,(int)(RestHitpoint  * 70 / Maxhitpoint) + 50,26,GetColor(255,120,120),true);
				break;
			case 3://全て赤表示
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
		//使い魔のデータを登録します。基本的にNextsceneまたはProcess○○において登録されます。
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
		//敵位置における当たり判定を行います。falseの時はセーフ,trueの時はミスになります。
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
		/*雑魚敵ドット絵の変数 common comleft comright left right upleft upright
		redfairy
		bluefairy
		yellowfairy
		greenfairy
		himawarifairy
		kedama 毛玉画像はcommonのみ使用
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
		//雑魚敵ドット絵の変数
	struct TEKI{//最低限必要な敵情報です。そのほかの情報はGameクラス内のメソッドで使います。
	short scene;//敵がどのシーンで登場するかを制御する変数です。Nextsceneでのポインタ制御で必要になります。
	double x;//敵位置のＸ座標。小数点以下も記録するが引数として使う時はint型として呼び出される。
	double y;//敵位置のＹ座標。小数点以下も記録するが引数として使う時はint型として呼び出される。
	double vecx;//Ｘ軸方向への移動速度。1フレーム更新あたりとする。
	double vecy;//Y軸方向への移動速度。1フレーム更新あたりとする。
	short tekishu;//敵の種類を示す変数です。1 = red 2 = blue 3 = yellow 4 = green 5 = himawari 6 = kedamaとなります。
	short imgposi;//敵の移動方向を示す変数です。画像選択において使われます。0.common 1.comleft 2.comright 3.left 4.right 5.upleft 6.upright
	double hitpoint;//敵の体力値を示す変数です。これが0になると撃沈されポインタから外れます。
	int start;//敵が登場した時のフレーム数を保管する変数です。readyが0になるとその時のフレーム数がstartになります。
    int ready;//ProcessStageなどで敵が弾幕を発射するまでのカウントや一時停止してから再度移動するまでのカウントなどを示します。
	int poweritem;//撃沈されたときに落とすパワーアイテム数を示す変数です。Input_Dataメソッドで設定されます。
	//またパワーマックス時に取ると25,000点が加算され、それ以外は
	int tenitem;//撃沈されたときに落とすパワーアイテム数を示す変数です。Input_Dataメソッドで設定されます。
	//ここまでの情報は全てファイルから読み込まれます。
	int np;//次のポインタ
	int pp;//前のポインタ
	};
	TEKI teki[TEKIDATA];
	TEKI tukaima[100];
	struct tTEKI{//必要に応じて使われる敵情報です。
		short usef;//使用する関数のポインタ。calcクラスから獲得する。
		short fugou;//二次、円、楕円関数使用時の符号。-1だと左上寄りになり、1だと右下寄りになります。
		short kanshu;//関数の種類を示す変数。GetX,GetY関数を使用するときに一次～楕円関数を区別します。
		bool counter;//打ち返し弾幕を発射するかどうかを示す変数。trueの時にHitJudgemetで撃破されると0.01だけhitpointが残り、ProcessEnemyで弾幕を発射の後撃破処理をします。
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
	//色情報　赤・青・黄・緑・紫・灰・白・黒
	struct PLAYERDATA{
	   static char* partner;//このゲームで選ばれた自機 Futo Mima Sanae Sakuyaのいずれか
	   static int difficulty;//ゲームの難易度。1.easy 2.normal 3.hard 4.lunatic 5.extra
	   static int jikinum;//自機を区別する番号です。0.布都 1.魅魔 2.早苗 3.咲夜
	   static int choicestage;//選択したステージ。PracticeModeのみ入力される。GameMode時は0。
	   static bool practice;//Practice Modeか否かを示す変数。trueがPractice ModeでfalseがGame Modeとなる。
	   static int currentstage;//現在いるステージを示す変数。1.Stage1A,2.Stage1B … 7.Stage4,8.Stage5,9.Stage6A 10.Stage6B(cr参照)とする。PracticeModeでは0。
	   };
	PLAYERDATA PlayerData;
	struct ITEM{
		double x;
		double y;
		int imggapp;
		int imgp;
		int itemshu;//1 = power, 2 = ten, 3 = hoshi, 4 = bomb, 5 = extendとする。
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
	static int itemimg[7];//1 = power, 2 = ten, 3 = hoshi, 4 = bomb, 5 = extend, 6 = fullとする。
	struct BOSU{
		double x;
		double y;
		double vecx;
		double vecy;
		short hitr;//ボスの当たり判定（円）の半径を示す変数です。
		int start;//ボスが登場した時のフレーム数を保持する変数です。変数sとあわせて時間経過を示します。
		short imgpoji;
		int poweritem;
		int tenitem;
		double hitpoint;
		short phasecount;//ボス戦のフェーズ数を保持する変数です。最初の通常戦で設定され、スペルカード戦が終了するたびに減少します。
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
		static short daen;//XY軸で異なる楕円状の軌道が設定されます。次の引数にY軸の速度が設定されます(vecはX軸のものとする)。
		static short twist;//初期位置から捻じ曲がるように軌道が設定されます。次の引数に捻じ曲げる角度が設定されます。
		static short round;//弾幕が同じ円周に沿って回転しながら広がっていく起動を設定します。次の引数にフレーム単位での回転角度が設定されます(この時の弾幕処理は特殊で、vecxが円の半径の増分、vecyが回転角度の増分となります)。さらにvecは波状円半径の増分になります。
		static short crossround;//弾幕が同じ円周上を交差しながら回転し、広がっていく軌道を設定します。引数とvecx,vecyの役割はroundと同様ですが偶数弾のみ逆回転となります。
		static short cleam;//twistが内向きになる軌道が設定されます。order1に捻じ曲がる角度、order2に初期位置となる円の半径が設定されます(この場合最初に発射されだ波状弾幕を消去しつつ新たなクリーム波状弾幕を設定する仕組みである。さらに引数のx,y座標は収束していく円の中心座標とする)。
		static short point;//指定ポイントを中心とした円へと移動する波状弾幕を設定します。order1には指定ポイント円への角度、order2には指定ポイント円の半径を指定します。
		static short reverse;//波状収束弾幕。初期配置が円周上に設置され、円中央に向かうように弾幕外装する。
	};
	WAVEORDER waveorder;
	struct JIKI{
		double x;
		double y;
		int slow;
		int ok_shot;
	};
	struct TALK{
		char * name;//会話しているキャラクターの名前
		int jstand;//自機の立ち絵のアドレス
		int bossstand1;//メイン立ち絵のアドレス
		int bossstand2;//もう一人の立ち絵のアドレス
		int color;//セリフ文フォントの色1
		int color2;//セリフ文フォントの色2
		string selif1;//セリフ一行目
		string selif2;//セリフ二行目
		short nowtalk;//会話形式 1…自機のみ表示 2…両方表示 3…ボスのみ表示 4…両方非表示 5…共鳴　6…二人のボスの共鳴
		short lateupdate;//立ち絵に影をつけるか、そして描写する順番を示す変数です。1…自機(陽)→ボス2(陰)→ボス1(陰),2…自機(陽)→ボス1(陰)→ボス2(陰),3…ボス2(陽)→ボス1(陰)→自機(陰),4…ボス2(陽)→ボス1(陰)→自機(陰)
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
	//アイテム画像の変数
	static int itemgapp[7];
	//アイテム画像描写位置の調整数//1 = power, 2 = ten, 3 = hoshi, 4 = bomb, 5 = extend, 6 = fullとする。
	static short itemtail;//item配列の終端を示す変数です。ProcessEnemyまたはDeleteItemで変更されます。
	static short itemcount;//ステージに存在するアイテム総数を示す変数です。CreateItemで増加しDeleteItemで減少します。また0になったと同時にClearItemDataを起動します。
	static int TenBonus;//点アイテムを取得した際に加算されるボーナスです。初期値は10000でアイテム取得の度に100ずつ上乗せされます。
	static short tekicount;//出現中の敵の数を示す変数です。NextsceneやProcessEnemyで増加し、DeleteEnemyやステージの進行に応じて減少します。
	static short scene, prescene,lastscene;//全ステージで共通して使われるステージの進行度を示す変数です。
	static int Stagefont,Bossnamefont,Talkfont,Smallfont;//ステージ名、ボス名、曲名、会話文,小さい文字のフォントを保持するフォントハンドルです。Stageコントラクタで設定されます。
	static int Namefont,ClearBonusfont,SpellBonusfont;
	static short Begintime, Endtime, Currenttime;//Stage中のシーンの開始と終了、および現在の時間を管理する変数です。秒単位で計算します。
	static short s;//シーン中の経過時間を秒単位で示す変数です。ProcessEnemyおよびPDにはflameとこの変数との和が使われます。
	static short tail;//teki配列の終端+1を示す変数です。Nextsceneで変更されます。
	static bool Bossbuttle;//中ボス及びボスと戦闘中かどうかを示す変数です。TRUE時にはシーン移動が特殊になります。
	static bool Miss;//自機が被弾してミスエフェクト中かどうかを示す変数です。MissJudgementで判断し、エフェクト終了時に残機があればfalseに戻ります。
	static short missnothit;//ミス後に数秒間だけある無敵時間を保持する変数です。
	static short missflame;//ミス中の操作不能時間をカウントする変数です。ミス時にカウントを開始し2秒経過したら操作可能になります。
	static int Talkcount;//それぞれの会話フェーズにおける会話数を示す変数です。Nextphaseメソッドで設定されTalkメソッドで消費されます。
	static bool TalkSkipCancel;//トークシーン突入時にスキップの条件を満たしていた時にスキップを無効にする変数です。有効にするには一旦ボタンを話した上で再度スキップを入力する必要があります。
	static short ttail;//使い魔の終端ポインタ位置を示す変数です。
	int totalscore;//1フレーム中に発生したスコアを保持する変数です。発生と同時に集計されJikiクラスで加算されます。
	int jikistand;
	static int jstand[15];//ProcessTalkで使用される自機立ち絵データのあるポインタ配列のこと。StageStartにてポインタが割り当てられる。
	static short ChangeBGMtalkcount;//BGMが変わる会話のタイミングを保持する変数です。NextSceneで設定され、JikiクラスからBGMを変更します。
	static short ChangeBGMNumber;//会話中に変わるBGMのナンバーを保持する変数です。NextSceneで設定され、JikiクラスからBGMを変更します。

	static int StageClearscore;
	bool BossTalk;
	int Talkfile;
	static int BeforeJikiStand,BeforeBossStand;//ボス戦前の会話で使われる以前の会話時の立ち絵データを保持する変数です。会話対象が切り替わるとシェード加工されます。
	static short Bosstime;//フェーズ中制限時間(秒単位)をしめす変数です。
	static short Looptime;//フェーズ中のループ時間（秒単位）を示す変数です。
	static short timetoflame;
	static double Maxhitpoint;//各ボス戦での最大体力を保持する変数です。DisplayBossStatesメソッドでは残り体力と最大体力の割合に応じて体力ゲージを表示します。
	//またNextphaseが呼び出される度に毎回変更されます。
	static bool Spell;//スペルカード戦かどうかを示す変数です。trueであればスペルカード戦の状態です。Nextphaseメソッドで変更されます。
	static char* BossName;//ボスの名前を保持する変数です。各サブクラスのNextphaseメソッドで設定され、DisplayBossStatesメソッドで表示されます。
	static char* SpellKardName;//スペルカードの名前を保持する変数です。各サブクラスのNextphaseメソッドで設定され、ボスドットの描写後に描写されます。
	static int SpellBonusScore;//スペルカード戦をノーミスノーボムでクリアした際に加算されるボーナススコアを保持する変数です。ボム使用またはミスによって0になります。
	static int EndBonusScore;//通常戦やスペルカード戦でタイムアップ前にボスを倒したときに加算されるスコアを保持する変数です。倒しきれないと0になり、ボーナス表示もされません。
	static int decreasebonusperflame;//1フレームごとに減少するボーナススコアを示す変数です。0の時は減少しません。 = SpellBonusScore / Bosstime;
	static int PreBonusScore;//スペルカード戦が連続して起こった場合に前回のボーナススコアを保持する変数です。NextSceneで設定され次のスペルカード戦に突入する前にEndSpellKardEffectで表示されます。
	static char* selif1;
	static char* selif2;//トーク時の会話内容を保持する変数です。それぞれのプロセスボスメソッドで設定・使用されます。
	static int jikicolor;
	static int standx;
	static int standy;//自機の立ち絵の描写位置(x,y)をしめす変数です。自機により異なります。
	static bool Bosshit;//ボスの当たり判定を行うか否かを示す変数です。trueの時は各Stageサブクラスで判定が行われます。
	static short BossStandPosition;//トーク時のボスの立ち絵を識別する変数です。-1の時はボスの立ち絵が描写されません。1.common,2.fine,3.question,4.doubt,5.angry,6.surprised,7.amazed(呆れる),8.excited,9.strategy,10.cry
	static short JikiStandPosition;//トーク時の自機の立ち絵を識別する変数です。-1の時は自機の立ち絵が描写されません。1.common,2.fine,3.question,4.doubt,5.angry,6.surprised,7.amazed(呆れる),8.excited,9.strategy
	static int SelifColor;//トーク時のセリフの色を識別する変数です。自機やボスにより変化します。
	static short Shadowflg;//影付きで立ち絵を描写するかどうかを識別する変数です。0の時は自機が、1の時はボスが影付きで描写されます。
	static double appearx;
	static double appeary;
	static int rest;//ボス戦時の残りフェーズ数を示す画像です。Stageコントラクタで読み込まれDisplayBossStatesないしDisplaySpellStatesで描写されます。
	short hitpointdisp;//ボスフェーズの体力表示のフラグです。Nextsceneで設定されます。
	short danshotcount[100];//特定のシーン中に発射される弾幕レパートリ数を示す変数です。Nextsceneで設定され、ProcessEnemyで消費されます。
	bool twicecircle[50];//二回目に円を通るかどうかを示す配列です。二回目に到達したときにtrueとなります。
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
int Stage::itemimg[7] = { 0, 0, 0, 0, 0, 0 };//1 = power, 2 = ten, 3 = full, 4 = bomb, 5 = extend, 6 = hoshiとする。
int Stage::itemgapp[7] = { 6, 6, 6, 7, 7, 7 };	  //1 = power, 2 = ten, 3 = hoshi, 4 = bomb, 5 = extend, 6 = fullとする。
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