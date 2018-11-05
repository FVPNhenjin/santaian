//#include "Header.h"
#include "Controlar.h"
#include "Danmaku.h"
#include "Music.h"
#include "Stage.h"


#define PI 3.1415926535

/*class Extra:public Stage{
};*/
class FBD :public Danmaku{
	int ProcessDanmaku(int flame, int scene){
		int r = 0;
		return r;
	}
	int ProcessBossDanmaku(int flame, int scene, int jikinum, int x, int y){
		int r = 0;
		return r;
	}
};
class FinalB :public Stage{
public:
	FBD danmaku;
	FinalB::FinalB(){

	}
	int Nextscene(int newscene, int powercount){
		int r = 0;
		return r;
	}
	int PasteHolizon(int flame){
		int r = 0;
		return r;
	}
	int ProcessStage(int flame, int powercount){
		int r = 0;
		return r;
	}
	int ProcessEnemy(int flame){
		int r = 0;
		return r;
	}
	bool ProcessKagari(int flame){
		bool rr = true;
		return rr;
	}
	bool ProcessKanna(int flame){
		bool rr = true;
		return rr;
	}
	BOSU kagari;
	BOSU kanna;
private:
	static int kagaridot[5];
	static int kagaristand[7];
	static int kannadot[5];
	static int kannastand[7];
};
int FinalB::kagaristand[7] = { 0, 0, 0, 0, 0, 0 };
int FinalB::kagaridot[5] = { 0, 0, 0, 0 };
int FinalB::kannastand[7] = { 0, 0, 0, 0, 0, 0 };
int FinalB::kannadot[5] = { 0, 0, 0, 0 };
class FAD :public Danmaku{
	int ProcessDanmaku(int flame, int scene){
		int r = 0;
		return r;
	}
	int ProcessBossDanmaku(int flame, int scene, int jikinum, int x, int y){
		int r = 0;
		return r;
	}
};
class FinalA :public Stage{
public:
	FAD danmaku;
	FinalA::FinalA(){

	}
	int Nextscene(int newscene, int powercount){
		int r = 0;
		return r;
	}
	int PasteHolizon(int flame){
		int r = 0;
		return r;
	}
	int ProcessStage(int flame, int powercount){
		int r = 0;
		return r;
	}
	int ProcessEnemy(int flame){
		int r = 0;
		return r;
	}
	bool ProcessMinami(int flame){
		bool rr = true;
		return rr;
	}
	BOSU minami;
private:
	static int minamidot[5];
	static int minamistand[7];
};
int FinalA::minamistand[7] = { 0, 0, 0, 0, 0, 0 };
int FinalA::minamidot[5] = { 0, 0, 0, 0 };
class S5D :public Danmaku{
	int ProcessDanmaku(int flame,int scene){
		int r = 0;
		return r;
	}
	int ProcessBossDanmaku(int flame, int scene,int jikinum,int x,int y){
		int r = 0;
		return r;
	}
};
class Stage5 :public Stage{
public:
	S5D danmaku;
	Stage5::Stage5(){

	}
	int Nextscene(int newscene, int powercount){
		int r = 0;
		return r;
	}
	int PasteHolizon(int flame){
		int r = 0;
		return r;
	}
	int ProcessStage(int flame, int powercount){
		int r = 0;
		return r;
	}
	int ProcessEnemy(int flame){
		int r = 0;
		return r;
	}
	bool ProcessKagari(int flame){
		bool rr = true;
		return rr;
	}
	void ContentsRevival(bool fc){
		FinalChoosable = fc;
	}
	BOSU kagari;
	bool last4boss;//前回のステージ4のボス戦で明子、みどりのどちらとタイマンとなったかを示す変数です。true = 明子 false = みどり
private:
	bool FinalChoosable;//5ボス撃破後に二つあるファイナルステージを選択できるかを示す変数です。コントラクタにてレコードを調査して判断します。
	static int kagaridot[5];
	static int kagaristand[7];
	
};
int Stage5::kagaristand[7] = { 0, 0, 0, 0, 0, 0 };
int Stage5::kagaridot[5] = { 0, 0, 0, 0 };
class S4D:public Danmaku{
public:
	int ProcessDanmaku(int flame, int scene){
		int r = 0;
		int p = dan[0].np;
		while (p != tail && dancount != 0){
			if (ddan[p].karakazeready == 0){
				if (ddan[p].ready == 0){
					dan[p].x += dan[p].vecx;
					dan[p].y -= dan[p].vecy;
				}
				else{
					ddan[p].ready--;
				}
			}
			else{
				ddan[p].karakazeready--;
				if (ddan[p].karakazeready == 0){
					EndKarakkazeEffect(p);
				}
			}
			p = dan[p].np;
		}
		if (PasteDanmaku() != 0){ r = -1; }
		if (r == -1){
			r = -1;
		}
		return r;
	}
	int ProcessBossDanmaku(int flame, int scene, int jikinum, int x, int y){
		int r = 0;
		int p = dan[0].np;
		int kansulist[7][6] = { { 0, 0, 0, 0 }, { 1, 6, 4, 3 }, { 1, 4, 6, 2 }, { 3, 4, 5, 6, 3 }, { 2, 6, 5, 4, 2 }, { 2, 1, 5, 6, 3 }, { 3, 1, 5, 4, 2 } };
		while (p != tail && dancount != 0 && r == 0){
			switch (scene){
			case 9://冴月麟　通常1
				dan[p].x += dan[p].vecx;
				dan[p].y += dan[p].vecy;
				if (dan[p].danshu == dshu.mayu){
					if (dan[p].x + dan[p].vecx > 404 || dan[p].x + dan[p].vecx < 20){
						if (p >= boundroot && p < boundroot + 41){
							if (boundable[p - boundroot]){
								double radius = 0;
								radius = sqrt(pow(dan[p].vecx, 2.0) + pow(dan[p].vecy, 2.0));
								double kakudo = Getkakudo_Homing(dan[p].x, dan[p].y, x, y) * PI / 180;
								dan[p].vecx = radius * cos(kakudo) * 0.5;
								dan[p].vecy = radius * sin(kakudo) * 0.5;
								dan[p].imgangle = kakudo;
								boundable[p - boundroot] = false;
							}
						}
					}
				}
				break;
			case 10://冴月麟　スペルカード1
				
				if (ddan[p].usef == 0){
					dan[p].x += dan[p].vecx;
					dan[p].y -= dan[p].vecy;
					if (ddan[p].boundcount != -1){
						dan[p].imgangle = atan2(dan[p].vecy, dan[p].vecx) * PI / 180;
					}
					int k = 0;
					int d = 0;
					double vec,kakudo;//次に関数を使用する場合の初期角度と増分角度(半径は60で固定)
					switch (dan[p].color){
					case 1://red
						switch (ddan[p].boundcount){
						case 0:
							if (dan[p].y < 83){
								d = 1;
								k = 0;
								vec = (315 - 225) / 20;
								kakudo = 225;
							}
							break;
						case 1:
							if (dan[p].x > 381){
								d = 1;
								k = 1;
								vec = (360 + 90 - 315) / 24;
								kakudo = 315;
							}
							break;
						case 2:
							if (dan[p].x < 93){
								d = 1;
								k = 2;
								vec = (270 - 90) / 32;
								kakudo = 90;
							}
							break;
						case 3:
							if (dan[p].x > 271){
								d = 1;
								k = 3;
								vec = (90 - 135 - 360) / 60;
								kakudo = 90;
							}
							break;
						case 4:
							if (dan[p].x > 331){
								kakudo = GetRand(359);
								dan[p].vecx = cos(kakudo * PI / 180);
								dan[p].vecy = sin(kakudo * PI / 180);
								dan[p].imgangle = atan2(dan[p].vecy, dan[p].vecx) * 180 / PI;
								ddan[p].boundcount = -1;
							}
							break;
						}
						break;
					case 2://orange
						switch (ddan[p].boundcount){
						case 0:
							if (dan[p].y < 83){
								d = 2;
								k = 0;
								vec = (225 - 315) / 20;
								kakudo = 315;
							}
							break;
						case 1:
							if (dan[p].x < 43){
								d = 2;
								k = 1;
								vec = (90 - 225) / 24;
								kakudo = 225;
							}
							break;
						case 2:
							if (dan[p].x > 332){
								d = 2;
								k = 2;
								vec = (90 - 270) / 32;
								kakudo = 90;
							}
							break;
						case 3:
							if (dan[p].x > 271){
								d = 2;
								k = 3;
								vec = (90 + 360 - 45) / 60;
								kakudo = 90;
							}
							break;
						case 4:
							if (dan[p].x < 93){
								kakudo = GetRand(359);
								dan[p].vecx = cos(kakudo * PI / 180);
								dan[p].vecy = sin(kakudo * PI / 180);
								dan[p].imgangle = atan2(dan[p].vecy, dan[p].vecx) * 180 / PI;
								ddan[p].boundcount = -1;
							}
							break;
						}
						break;
					case 3://yellow
						switch (ddan[p].boundcount){//ここでのboundcountはこれまでに通過した関数の数を示す。
						case 0:
							if (dan[p].y < 201){
								d = 4;
								k = 0;
								vec = (90 - 315) / 30;
								kakudo = 315;
							}
							break;
						case 1:
							if (dan[p].x > 331){
								d = 4;
								k = 1;
								vec = (360 + 90 - 270) / 32;
								kakudo = 270;
							}
							break;
						case 4:
							if (dan[p].x > 151){
								d = 4;
								k = 4;
								vec = (45 - 90) / 10;
								kakudo = 90;
							}
							break;
						case 5:
							if (dan[p].y < 153){
								kakudo = GetRand(359);
								dan[p].vecx = cos(kakudo * PI / 180);
								dan[p].vecy = sin(kakudo * PI / 180);
								dan[p].imgangle = atan2(dan[p].vecy, dan[p].vecx) * 180 / PI;
								ddan[p].boundcount = -1;
							}
							break;
						}
						break;
					case 4://green
						switch (ddan[p].boundcount){//ここでのboundcountはこれまでに通過した関数の数を示す。
						case 0:
							if (dan[p].y < 203){
								d = 3;
								k = 0;
								vec = (360 + 90 - 225) / 30;
								kakudo = 225;
							}
							break;
						case 1:
							if (dan[p].x < 92){
								d = 3;
								k = 1;
								vec = (90 - 270) / 32;
								kakudo = 270;
							}
							break;
						case 4:
							if (dan[p].x < 272){
								d = 3;
								k = 4;
								vec = (135 - 90) / 10;
								kakudo = 90;
							}
							break;
						case 5:
							if (dan[p].x > 153){
								kakudo = GetRand(359);
								dan[p].vecx = cos(kakudo * PI / 180);
								dan[p].vecy = sin(kakudo * PI / 180);
								ddan[p].boundcount = -1;
							}
							break;
						}
						break;
					case 6://blue
						switch (ddan[p].boundcount){//ここでのboundcountはこれまでに通過した関数の数を示す。
						case 0:
							if (dan[p].x > 122){
								d = 5;
								k = 0;
								vec = (270 - 225) / 10;
								kakudo = 225;
							}
							break;
						case 1:
							if (dan[p].x > 211){
								d = 5;
								k = 1;
								vec = (360 - 90) / 30 * -1;
								kakudo = 90;
							}
							break;
						case 2:
							if (dan[p].y > 362){
								d = 5;
								k = 2;
								vec = (180 - 0) / 24 * -1;
								kakudo = 180;
							}
							break;
						case 4:
							if (dan[p].x > 302){
								d = 5;
								k = 4;
								vec = (315 - 135) / 24 * -1;
								kakudo = 45;
							}
							break;
						case 5:
							if (dan[p].x < 153){
								kakudo = GetRand(359);
								dan[p].vecx = cos(kakudo * PI / 180);
								dan[p].vecy = sin(kakudo * PI / 180);
								ddan[p].boundcount = -1;
							}
							break;
						}
						break;
					case 7://purple
						switch (ddan[p].boundcount){//ここでのboundcountはこれまでに通過した関数の数を示す。
						case 0:
							if (dan[p].x < 303){
								d = 6;
								k = 0;
								vec = (270 - 315) / 10;
								kakudo = 315;
							}
							break;
						case 1:
							if (dan[p].x < 213){
								d = 6;
								k = 1;
								vec = (360 - 90) / 30;
								kakudo = 90;
							}
							break;
						case 2:
							if (dan[p].y > 362){
								d = 6;
								k = 2;
								vec = (180 - 0) / 24;
								kakudo = 0;
							}
							break;
						case 4:
							if (dan[p].x < 103){
								d = 6;
								k = 4;
								vec = (315 - 135) / 24;
								kakudo = 135;
							}
							break;
						case 5:
							if (dan[p].x > 271){
								kakudo = GetRand(359);
								dan[p].vecx = cos(kakudo * PI / 180);
								dan[p].vecy = sin(kakudo * PI / 180);
								ddan[p].boundcount = -1;
							}
							break;
						}
						break;
					}
					if (k != 0 || d != 0){//いずれかが0でなかった場合はその弾幕に関数をつける
						ddan[p].usef = kansulist[d][k] + 6;
						dan[p].vecx = kakudo;
						dan[p].vecy = vec;
					}
				}
				else{
					dan[p].vecx += dan[p].vecy;
					dan[p].imgangle = (dan[p].vecx + 90) * PI / 180;
					if (dan[p].vecx > 360){
						dan[p].vecx -= 360;
					}
					if (dan[p].vecx < 0){
						dan[p].vecx += 360;
					}
					dan[p].x = En[3][ddan[p].usef] * cos(dan[p].vecx * PI / 180) + En[1][ddan[p].usef];
					dan[p].y = En[3][ddan[p].usef] * sin(dan[p].vecx * PI / 180) + En[2][ddan[p].usef];
					bool nouse = false;//関数を今後使用しないかを示す変数です。一定の位置に到達するとtrueとなり、usefが0になります。
					double vx, vy;
					switch (dan[p].color){
					case 1://red
						switch (ddan[p].boundcount){
						case 0:
							if (dan[p].vecx > 314 && dan[p].vecx > 180){
								vx = (382 - 262) / 50;
								vy = (93 - 333) / 50;
								nouse = true;
							}
							break;
						case 1:
							if (dan[p].vecx > 89 && dan[p].vecx < 225){
								vx = (92 - 332) / 32;
								vy = 0;
								nouse = true;
							}
							break;
						case 2:
							if (dan[p].vecx > 269 && dan[p].vecx > 180){
								vx = (272 - 152) / 30;
								vy = 0;;
								nouse = true;
							}
							break;
						case 3:
							if (dan[p].vecx < 136 && dan[p].vecx > 90){
								vx = (332 - 242) / 30;
								vy = (283 - 373) / 30;
								nouse = true;
							}
							break;
						
						}
						break;
					case 2://orange
						switch (ddan[p].boundcount){
						case 0:
							if (dan[p].vecx < 226 && dan[p].vecx > 180){
								vx = (62 - 182) / 50;
								vy = (93 - 333) / 50;
								nouse = true;
							}
							break;
						case 1:
							if (dan[p].vecx < 91 && dan[p].vecx < 225){
								vx = (332 - 92) / 32;
								vy = 0;
								nouse = true;
							}
							break;
						case 2:
							if (dan[p].vecx < 271 && dan[p].vecx > 180){
								vx = (152 - 332) / 30;
								vy = 0;;
								nouse = true;
							}
							break;
						case 3:
							if (dan[p].vecx > 44 && dan[p].vecx < 90){
								vx = (332 - 242) / 30 * -1;
								vy = (283 - 373) / 30;
								nouse = true;
							}
							break;

						}
						break;
					case 3://yellow
						switch (ddan[p].boundcount){
						case 0:
							if (dan[p].vecx < 91 && dan[p].vecx < 180){
								vx = (332 - 152) / 32;
								vy = 0;
								nouse = true;
							}
							break;
						case 1:
							if (dan[p].vecx > 179 && dan[p].vecx < 225){
								ddan[p].boundcount += 1;
								dan[p].vecx = 360;
								dan[p].vecy = (180 - 360) / 24;
								ddan[p].usef = 11;
							}
							break;
						case 2:
							if (dan[p].vecx < 181 && dan[p].vecx > 90){
								ddan[p].boundcount += 1;
								dan[p].vecx = 0;
								dan[p].vecy = (315 - 0) / 32;
								ddan[p].usef = 10;
							}
							break;
						case 3:
							if (dan[p].vecx > 269 && dan[p].vecx < 315){
								vx = (152 - 92) / 10;
								vy = 0;
								nouse = true;
							}
							break;
						case 4:
							if (dan[p].vecx < 46){
								vx = (332 - 182) / 30;
								vy = (273 - 153) / 30;
								nouse = true;
							}
							break;
						}
						break;
					case 4://green
						switch (ddan[p].boundcount){
						case 0:
							if (dan[p].vecx > 89 && dan[p].vecx < 180){
								vx = (92 - 272) / 32;
								vy = 0;
								nouse = true;
							}
							break;
						case 1:
							if ((dan[p].vecx < 1 && dan[p].vecx < 280) || (dan[p].vecx > 350 && dan[p].vecx > 280)){
								ddan[p].boundcount += 1;
								dan[p].vecx = 180;
								dan[p].vecy = (360 - 180) /	24;
								ddan[p].usef = 11;
							}
							break;
						case 2:
							if ((dan[p].vecx > 350 && dan[p].vecx > 90) || (dan[p].vecx > 350 && dan[p].vecx > 270)){
								ddan[p].boundcount += 1;
								dan[p].vecx = 180;
								dan[p].vecy = (180 - 450) / 32;
								ddan[p].usef = 12;
							}
							break;
						case 3:
							if (dan[p].vecx < 275 && dan[p].vecx > 180){
								vx = (272 - 332) / 10;
								vy = 0;
								nouse = true;
							}
							break;
						case 4:
							if (dan[p].vecx > 134){
								vx = (92 - 231) / 30;
								vy = (273 - 153) / 30;
								nouse = true;
							}
							break;
						}
						break;
					case 6://blue
						switch (ddan[p].boundcount){
						case 0:
							if (dan[p].vecx > 269 && dan[p].vecx > 180){
								vx = (212 - 272) / 10 * -1;
								vy = 0;
								nouse = true;
							}
							break;
						case 1:
							if (dan[p].vecx < 181 && dan[p].vecx > 90) {
								vx = 0;
								vy = (363 - 123) / 50 * -1;
								nouse = true;
							}
							break;
						case 2:
							if (dan[p].vecx < 1 || dan[p].vecx == 360){
								ddan[p].boundcount += 1;
								dan[p].vecx = 180;
								dan[p].vecy = (315 - 360) / 10 * -1;
								ddan[p].usef = 12;
							}
							break;
						case 3:
							if (dan[p].vecx > 224 && dan[p].vecx > 180){
								vx = (102 - 142) / 10 * -1;
								vy = (313 - 283) / 10;
								nouse = true;
							}
							break;
						case 4:
							if (dan[p].vecx < 226 && dan[p].vecx > 180){
								vx = (272 - 182) / 20 * -1;
								vy = (243 - 203) / 20 * -1;
								nouse = true;
							}
							break;
						}
						break;
					case 7://purple
						switch (ddan[p].boundcount){
						case 0:
							if (dan[p].vecx < 271 && dan[p].vecx > 180){
								vx = (212 - 272) / 10;
								vy = 0;
								nouse = true;
							}
							break;
						case 1:
							if (dan[p].vecx > 359 || dan[p].vecx == 0) {
								vx = 0;
								vy = (363 - 123) / 50 * -1;
								nouse = true;
							}
							break;
						case 2:
							if (dan[p].vecx > 179 && dan[p].vecx > 90){
								ddan[p].boundcount += 1;
								dan[p].vecx = 360;
								dan[p].vecy = (315 - 360) / 10;
								ddan[p].usef = 10;
							}
							break;
						case 3:
							if (dan[p].vecx < 316 && dan[p].vecx > 270){
								vx = (102 - 142) / 10;
								vy = (313 - 283) / 10;
								nouse = true;
							}
							break;
						case 4:
							if (dan[p].vecx > 314 && dan[p].vecx < 360){
								vx = (272 - 182) / 20;
								vy = (243 - 203) / 20 * -1;
								nouse = true;
							}
							break;
						}
						break;
					}
					if (nouse){
						dan[p].vecx = vx;
						dan[p].vecy = vy;
						ddan[p].usef = 0;
						ddan[p].boundcount += 1;
					}
				}
				
				if (flame % 30 == 0){ DanmakuRefresh(); }
				break;
			case 16://明子＆みどり　前半戦　通常1
				dan[p].x += dan[p].vecx;
				dan[p].y -= dan[p].vecy;
				if (dan[p].danshu == dshu.ring && ddan[p].boundcount == 0) {
					ProcessBound(p);
				}
				break;
			case 17://スペルカード戦1
				dan[p].x += dan[p].vecx;
				dan[p].y -= dan[p].vecy;
				if (dan[p].danshu == dshu.ring && dan[p].color == dcolor.yellow) {
					if ((dan[p].vecx > 0  && dan[p].x >= 212)|| (dan[p].vecx < 0 && dan[p].x <= 212)|| (dan[p].vecy > 0 && dan[p].y <= 243)|| (dan[p].vecy < 0 && dan[p].y >= 243)) {
						int k = (int)(atan2(dan[p].vecy, dan[p].vecx) * 180 / PI) + 180;
						Setdanmaku_Ko((int)(dan[p].x), (int)(dan[p].y), 2, dshu.middle, dcolor.red, 0, k - 35, k + 35, 3);
						DeleteDan(p);
					}
				}
				break;
			case 18://通常２
				if (ddan[p].ready == 0) {
					dan[p].x += dan[p].vecx;
					dan[p].y -= dan[p].vecy;
				}
				else {
					ddan[p].ready -= 1;
					if (ddan[p].ready == 0) {
						ChangeDanmakuExpress(p, p + 1, 1, Getkakudo_Homing(dan[p].x, dan[p].y, x, y), 2);
						dan[p].color = dcolor.blue;
					}
				}
				break;
			case 19://スペルカード戦2
				if (dan[p].danshu == dshu.heart) {
					dan[p].imgangle = 0;
					ddan[p].crossr += dan[p].vecx;//波状円の半径を増加
					ddan[p].crosskakudo += dan[p].vecy;//円周上の回転位置を増分
					dan[p].x = (int)(ddan[p].crossr  * cos(ddan[p].crosskakudo * PI / 180)) + 212;
					dan[p].y = (int)(ddan[p].crossr  * sin(ddan[p].crosskakudo * PI / 180)) + 250;
				}
				else {
					dan[p].x += dan[p].vecx;
					dan[p].y -= dan[p].vecy;
				}
				break;
			case 20://スペルカード戦3
				if (ddan[p].ready == 0) {
					dan[p].x += dan[p].vecx;
					dan[p].y -= dan[p].vecy;
					if (dan[p].danshu == dshu.plate) {
						if (flame % 10 == 0) {
							dan[p].imgangle += 10;
							if (dan[p].imgangle >= 360) {
								dan[p].imgangle -= 360;
							}
						}
						if (dan[p].y + dan[p].vecy > 475) {
							int a;
							a = 2;
						}
						else {
							ProcessBound(p);
						}
					}
				}
				else {
					ddan[p].ready--;
				}
				break;
			case 23://明子orみどり　後半戦　通常4
				if (lastbuttle){
					if (ddan[p].ready == 0) {
						
						if (dan[p].danshu == dshu.plate){
							if (dan[p].color == dcolor.white) {
								dan[p].x += dan[p].vecx;
								dan[p].y -= dan[p].vecy;
								if (flame % 10 == 0) {
									dan[p].imgangle += 10;
									if (dan[p].imgangle >= 360) {
										dan[p].imgangle -= 360;
									}
								}
							}
							else {
								ddan[p].crossr += dan[p].vecx;//波状円の半径を増加		
								ddan[p].crosskakudo += dan[p].vecy;//円周上の回転位置を増分
								if (dan[p].vecy > 0) {
									dan[p].imgangle += 3;
									
									if (dan[p].imgangle >= 360) {
										dan[p].imgangle -= 360;
									}
								}
								else {
									dan[p].imgangle -= 3;
									if (dan[p].imgangle < 0) {
										dan[p].imgangle += 360;
									}
								}
								dan[p].x = (int)(ddan[p].crossr  * cos(ddan[p].crosskakudo * PI / 180)) + x;
								dan[p].y = (int)(ddan[p].crossr  * sin(ddan[p].crosskakudo * PI / 180)) + y;
							}
						}
						else {
							dan[p].x += dan[p].vecx;
							dan[p].y -= dan[p].vecy;
						}
					}
					else {
						ddan[p].ready--;						
					}

				}
				else{
					if (ddan[p].ready == 0) {
						dan[p].x += dan[p].vecx;
						dan[p].y -= dan[p].vecy;
					}
					else {
						ddan[p].ready--;
					}
				}
				break;
			case 24://明子orみどり　後半戦　スペルカード戦4
				if (lastbuttle){
					if (ddan[p].ready == 0) {
						dan[p].x += dan[p].vecx;
						dan[p].y -= dan[p].vecy;
						
 					}
					else {
						ddan[p].ready--;
					}
					if (dan[p].danshu == dshu.bigplate) { 
						int b = ddan[p].boundcount;
						if ((int)(dan[p].x) == (int)(dan[p].x + dan[p].vecx) && (int)(dan[p].y) == (int)(dan[p].y - dan[p].vecy)) {
							dan[p].vecx = 2; 
						    dan[p].vecy = 2; 
						}
						ProcessBound(p); 
						dan[p].imgangle += 3;
						if (ddan[p].boundcount != b) {
							dan[p].vecx += GetRand(2) - 1;
							dan[p].vecy += GetRand(2) - 1;
							if (dan[p].vecx > 4) { dan[p].vecx = 2; }
							if (dan[p].vecy > 4) { dan[p].vecy = 2; }
						}
						int d = dan[0].np;
						while (d != tail) {
							if (dan[d].danshu == dshu.ring) {
								if (pow(dan[p].x - dan[d].x, 2.0) + pow(dan[p].y - dan[d].y, 2.0) < 1089) {
									Setdanmaku_ChainRendan((int)(dan[d].x), (int)(dan[d].y), 1.5, Getkakudo_Homing(dan[d].x, dan[d].y, x, y), dshu.middle, dcolor.purple, 0, 3, 4);
									DeleteDan(d);
								}
							}
							d = dan[d].np;
						}
					}
				}
				else{
					if (ddan[p].ready == 0) {
						dan[p].x += dan[p].vecx;
						dan[p].y -= dan[p].vecy;
					}
					else {
						ddan[p].ready--;
					}
				}
				break;
			case 25://明子orみどり　後半戦　通常5
				if (lastbuttle){
					if (ddan[p].ready < 1) {
						if (ddan[p].usef == 0) {
							dan[p].x += dan[p].vecx;
							dan[p].y -= dan[p].vecy;
							if (dan[p].danshu == dshu.plate) {
								int b = ddan[p].boundcount;
								double k = atan2(dan[p].vecy * -1, dan[p].vecx) * 180 / PI;		
								if (k < 0) {
									k += 360;
								}
								if (dan[p].y - dan[p].vecy < 470) {
									ProcessBound(p);
								}
								if (b != ddan[p].boundcount) {
									daencount++;									
									ddan[p].usef = daencount;										
									
									if (dan[p].y < 16) {										
										dan[p].vecx = k;
										if (k < 270) {								
											dan[p].vecy = -0.5;
										}
										else {											
											dan[p].vecy = 0.5;
										}
									}
									else {
										if (dan[p].x < 20) {
											if (k > 180) {
												dan[p].vecx = k;
												dan[p].vecy = 0.5;
											}
											else {
												dan[p].vecx = 450 - k;
												dan[p].vecy = 0.5;
											}
										}
										else {
											if (k > 270) {
												dan[p].vecx = k;
												dan[p].vecy = -0.5;
											}
											else {
												dan[p].vecx = 270 - k;
												dan[p].vecy = -0.5;
											}
										}
									}
									ddaen[1][ddan[p].usef] = (int)(dan[p].x - 212 * cos(dan[p].vecx * PI / 180));
									ddaen[2][ddan[p].usef] = (int)(dan[p].y - 480 * sin(dan[p].vecx * PI / 180));
								}
							}
						}
						else {
							//plate弾の楕円関数使用処理
							dan[p].vecx += dan[p].vecy;
							if (dan[p].vecx > 360) { dan[p].vecx -= 360; }
							dan[p].x = 212 * cos(dan[p].vecx * PI / 180) + ddaen[1][ddan[p].usef];
							dan[p].y = 480 * sin(dan[p].vecx * PI / 180) + ddaen[2][ddan[p].usef];
							if (dan[p].vecy > 0) {
								dan[p].imgangle += 3;
							}
							else {
								dan[p].imgangle -= 3;
							}
							if (dan[p].x > 400) {								
								dan[p].vecx = 250;
								dan[p].vecy = -0.5;
								ddaen[1][ddan[p].usef] = (int)(dan[p].x - 212 * cos(dan[p].vecx * PI / 180));
								ddaen[2][ddan[p].usef] = (int)(dan[p].y - 480 * sin(dan[p].vecx * PI / 180));
							}
							if (dan[p].x < 20) {
								dan[p].vecx = 280;
								dan[p].vecy = 0.5;
								ddaen[1][ddan[p].usef] = (int)(dan[p].x - 212 * cos(dan[p].vecx * PI / 180));
								ddaen[2][ddan[p].usef] = (int)(dan[p].y - 480 * sin(dan[p].vecx * PI / 180));
							}
						}
					}
					else {
						ddan[p].ready--;
					}
				}
				else{
					dan[p].x += dan[p].vecx;
					dan[p].y -= dan[p].vecy;
				}
				break;
			case 26://明子orみどり　後半戦　スペルカード戦5
				if (lastbuttle){
					if (dan[p].danshu == dshu.plate) {
						ddan[p].crossr += dan[p].vecx;//波状円の半径を増加		
						ddan[p].crosskakudo += dan[p].vecy;//円周上の回転位置を増分
						if (dan[p].vecy > 0) {
							dan[p].imgangle += 3;

							if (dan[p].imgangle >= 360) {
								dan[p].imgangle -= 360;
							}
							if (ddan[p].crosskakudo >= 360) {
								ddan[p].crosskakudo -= 360;
							}
						}
						else {
							if (dan[p].vecy < 0) {
								dan[p].imgangle -= 3;
								if (dan[p].imgangle < 0) {
									dan[p].imgangle += 360;
								}
								if (ddan[p].crosskakudo <= 0) {
									ddan[p].crosskakudo += 360;
								}
							}
						}
						dan[p].x = (int)(ddan[p].crossr  * cos(ddan[p].crosskakudo * PI / 180)) + x;
						dan[p].y = (int)(ddan[p].crossr  * sin(ddan[p].crosskakudo * PI / 180)) + y;
					}else{					
						dan[p].x += dan[p].vecx;
						dan[p].y -= dan[p].vecy;
					}
				}
				else{
					dan[p].x += dan[p].vecx;
					dan[p].y -= dan[p].vecy;
				}
				break;
			case 27://明子orみどり　後半戦　スペルカード戦6
				if (lastbuttle){
					dan[p].x += dan[p].vecx;
					dan[p].y -= dan[p].vecy;
				}
				else{
					if (ddan[p].ready == 0) {
						dan[p].x += dan[p].vecx;
						dan[p].y -= dan[p].vecy;
						if (dan[p].danshu == dshu.kome) {
							if (dan[p].y - dan[p].vecy <= 120) {
								ddan[p].ready = 60;
							}
						}
					}
					else {
						ddan[p].ready--;
						if (ddan[p].ready == 0 && dan[p].danshu == dshu.kome) {
							Setdanmaku_ChainRendan((int)(dan[p].x), (int)(dan[p].y), 3, Getkakudo_Homing(dan[p].x, dan[p].y, (double)(x), (double)(y)), dshu.mayu, dcolor.water, 0, 10, 4);
							DeleteDan(p);
						}
					}
				}
				break;
			}
			p = dan[p].np;
		}
		r = PasteDanmaku();
		return r;
	}
	void ClearDaen() {
		for (int d = 1; d < 15; d++) {
			ddaen[1][d] = 0;
			ddaen[2][d] = 0;
		}
		daencount = 0;
	}
	void SetDessin() {
		bool allrange[10];
		bool flg = false;
		struct dessin {
			int num;
			int x;
			int y;
			int k;
		};
		dessin des[4];
		int rangex[5];
		int rangey[5];
		rangex[1] = 30;
		rangey[1] = 25;
		for (int seek = 2; seek < 5; seek++) {
			rangex[seek] = rangex[seek - 1] + 115;
			rangey[seek] = rangey[seek - 1] + 140;
		}

		Clearkansu();
		for (int b = 1; b < 10; b++) {
			allrange[b] = false;
		}

		for (int d = 1; d < 6; d++) {
			{
				int r = GetRand(19) + 1;
				/*
				1. 1 - 5 - 7, 3 - 5 - 9のいずれか
				2. 2 - 4 - 8, 2 - 6 - 8のいずれか
				3. 1 - 4 - 9,3 - 6 - 7のいずれか
				4. 4 - 8 - 6,6 - 8 - 4のいずれか
				5. 2 - 1 - 4,6 - 9 - 8のいずれか
				6.  6 - 2 - 1,6 - 8 - 7のいずれか
				7.  4 - 5 - 9,4 - 5 - 3のいずれか
				8.  2 - 5 - 7,2 - 5 - 9のいずれか
				9.  1 - 6 - 8,3 - 4 - 8のいずれか
				10.  1 - 2 - 3,7 - 8 - 9のいずれか
				*/
				int pattern[11][7] = { {0,1,5,7,3,5,9},{ 0,2,4,8,2,6,8 },{ 0,1,4,9,3,6,7 },
				  { 0,4,8,6,6,8,4 },{ 0,2,1,4,6,9,8 },{ 0,6,2,1,6,8,7 },{ 0,4,5,9,4,5,3 } ,
				  { 0,2,5,7,2,5,9 },{ 0,1,6,8,3,4,8 },{ 0,1,2,3,7,8,9 } };
				int pat = 1;
				if (r > 10) {
					r -= 10;
					pat = 4;
				}
				for (int count = 1; count < 4; count++) {
					des[count].num = pattern[r][pat];
					pat++;
				}
			}
			bool loop = true;
			while (loop) {
				for (int e = 1; e < 4; e++) {
					allrange[des[e].num] = true;
					des[e].x = GetRand(114) + rangex[(des[e].num % 3 == 0) ? 3 : des[e].num % 3];
					des[e].y = GetRand(139) + rangey[(int)((des[e].num - 1) / 3) + 1];
				}
				if (sqrt(pow(des[1].x - des[2].x, 2.0) + pow(des[1].y - des[2].y, 2.0) > 30) &&
					sqrt(pow(des[2].x - des[3].x, 2.0) + pow(des[2].y - des[3].y, 2.0) > 30) &&
					sqrt(pow(des[1].x - des[3].x, 2.0) + pow(des[1].y - des[3].y, 2.0) > 30)) {
					loop = false;
				}
			}
			/*/デバッグ
			des[1].x = 315;
			des[1].y = 80;
			des[2].x = 100;
			des[2].y = 200;
			des[3].x = 225;
			des[3].y = 380;
			//ここまでデバッグ*/
			int usef;
			usef = DirectInputkansu_en_3point(des[1].x, des[1].y, des[2].x, des[2].y, des[3].x, des[3].y);
			dessan[d].a = (int)(En[1][usef]);
			dessan[d].b = (int)(En[2][usef]);
			dessan[d].r = (int)(En[3][usef]);
			for (int e = 1; e < 4; e++) {
				des[e].k = Getkakudo_Homing(dessan[d].a, dessan[d].b, des[e].x, des[e].y);
				if (des[e].k < 0) { des[e].k += 360; }
			}
			dessan[d].sk = des[1].k;
			dessan[d].mk = des[2].k;
			dessan[d].ek = des[3].k;
			if (des[1].k > des[2].k && des[2].k < des[3].k) {//300 10 50      50 10 200
				if (des[1].k > des[3].k) {
					dessan[d].sk -= 360;
				}
				else {
					dessan[d].ek -= 360;
				}
			}
			if (des[1].k < des[2].k && des[2].k > des[3].k) {//200 310 50     50 200 80   30 300 200
				if (des[1].k > des[3].k) {
					dessan[d].ek += 360;
				}
				else {
					dessan[d].sk += 360;
				}
			}
		}

		dessined = true;
	}
	bool boundable[40];
	short boundroot;
	bool lastbuttle;
	bool dessined;
	int ddaen[5][15];/*[1.a 2.b,3.p,4.q][14]明子戦通常2で使う配列。X半径は100、Y半径は300固定とし、270度の角度から2度ずつ増減するものとする。またループの終わりに初期化する。
						また明子戦スペルカード2でも使用される。この時ProcessAkikoにてArrowRendanで作成された弾幕を即座に楕円関数にのせて運用するものとする。*/
	int daencount;
	struct DESSIN {
		int a;
		int b;
		int r;
		int sk;
		int mk;
		int ek;
	};
	DESSIN dessan[6];
private:
};
class Stage4:public Stage{
public:
	S4D danmaku;
	Stage4::Stage4(){
		lastbuttle = 0;
		int r;
		r = _chdir("data");
		r = _chdir("img");
		r = _chdir("Game");
		r = _chdir("Enemy");
		r = _chdir("Boss");
		rindot[DotAct.common] = LoadGraph("Rin.dot.common.bmp");
		rinstand[StandAct.common] = LoadGraph("Rin.common.bmp");
		rinstand[StandAct.fine] = LoadGraph("Rin.surprised.bmp");
		akikostand[StandAct.common] = LoadGraph("Akiko.common.png");
		akikostand[StandAct.fine] = LoadGraph("Akiko.fine.png");
		akikostand[StandAct.surprised] = LoadGraph("Akiko.surprised.png");
		akikostand[StandAct.excited] = LoadGraph("Akiko.excited.png");
		akikostand[StandAct.strategy] = LoadGraph("Akiko.strategy.png");
		akikostand[StandAct.cry] = LoadGraph("Akiko.cry.png");
		akiko2stand[StandAct.cry] = LoadGraph("Akiko2.cry.png");
		akiko2stand[StandAct.despair] = LoadGraph("Akiko2.despair.png");
		akiko2stand[StandAct.common] = LoadGraph("Akiko2.common.png");
		akiko2stand[StandAct.fine] = LoadGraph("Akiko2.fine.png");
		akiko2stand[StandAct.angry] = LoadGraph("Akiko2.angry.png");
		akiko2stand[StandAct.strategy] = LoadGraph("Akiko2.strategy.png");
		akiko2stand[StandAct.excited] = LoadGraph("Akiko2.excited.png");
		midoristand[StandAct.common] = LoadGraph("Midori.common.png");
		midoristand[StandAct.fine] = LoadGraph("Midori.fine.png");
		midoristand[StandAct.question] = LoadGraph("Midori.question.png");
		midoristand[StandAct.amazed] = LoadGraph("Midori.amazed.png");
		midoristand[StandAct.surprised] = LoadGraph("Midori.surprised.png");
		midoristand[StandAct.excited] = LoadGraph("Midori.excited.png");
		midoristand[StandAct.strategy] = LoadGraph("Midori.strategy.png");
		midoristand[StandAct.cry] = LoadGraph("Midori.cry.png");
		midori2stand[StandAct.common] = LoadGraph("Midori2.common.png");
		midori2stand[StandAct.fine] = LoadGraph("Midori2.fine.png");
		midori2stand[StandAct.angry] = LoadGraph("Midori2.angry.png");
		midori2stand[StandAct.excited] = LoadGraph("Midori2.excited.png");
		midori2stand[StandAct.strategy] = LoadGraph("Midori2.strategy.png");
		midori2stand[StandAct.cry] = LoadGraph("Midori2.cry.png");
		midori2stand[StandAct.despair] = LoadGraph("Midori2.despair.png");
		akikodot[DotAct.common] = LoadGraph("Akiko.dot.common.bmp");
		akikodot[DotAct.act1] = LoadGraph("Akiko.dot.common.bmp");
		midoridot[DotAct.common] = LoadGraph("Midori.dot.common.bmp");
		midoridot[DotAct.act1] = LoadGraph("Midori.dot.act.bmp");
		akikodot[DotAct.common + 2] = LoadGraph("Akiko2.dot.common.bmp");
		midoridot[DotAct.common + 2] = LoadGraph("Midori2.dot.common.bmp");
		midoritukaima = LoadGraph("Tukaima.midori.bmp");
		r = _chdir("..");
		r = _chdir("..");
		r = _chdir("..");
		r = _chdir("..");
		r = _chdir("..");
	}
	int Nextscene(int newscene, int powercount){
		int r = 0;
		Begintime += Currenttime;
		Currenttime = 0;
		s = 0;
		if (newscene == 12){
			Bossbuttle = false;
			if (Begintime > 151){
				newscene++;
				scene++;
				Begintime = 152;
			}
		}
		char * talktitle = 0;
		//if (newscene == 21) { danmaku.eff.SEVolume = 0; }
		switch (newscene){
		case 0:
			s = -1;
			missflame = 300;
			danmaku.ClearDanmaku();
			danmaku.Clearkansu();
			danmaku.Inputkansu("Stage4");
			r = _chdir("data");
			r = _chdir("Stage");
			r = _chdir("Stage4");
			holizon.back = LoadGraph("back.bmp");
			holizon.bossback = LoadGraph("myougi.bmp");
			holizon.spellback1 = LoadGraph("Akiko2.spell.bmp");
			holizon.spellback2 = LoadGraph("midori2.spell.bmp");
			r = _chdir("..");
			r = _chdir("..");
			r = _chdir("..");
			holizon.by = 2000;
			Begintime = 0;
			Endtime = 1;
			lastscene = 27;
			tekicount = 0;
			BossTalk = false;
			Bossbuttle = false;
			rinbuttle = false;
			break;
		case 1:
			kakudo = 0;
			Endtime = 12;
			for (int p = 21; p < 31; p++){
				tteki[p].counter = true;
			}
			break;
		case 2:
			Endtime = 18;
			break;
		case 3:
			Endtime = 39;
			break;
		case 4:
			stoptime = 0;
			Endtime = 52;
			break;
		case 5:
			stoptime = 0;
			Endtime = 65;
			break;
		case 6:
			Endtime = 80;
			kkakudo[1] = 0;
			kkakudo[2] = 182;
			break;
		case 7:
			Endtime = 92;
			break;
		case 8://中ボス登場
			danmaku.ClearDanmaku();
			Bossbuttle = true;//ボス戦を有効に
			rinbuttle = true;
			BossName = "Satuki Rin";//ボス名を設定
			Rin.imgpoji = DotAct.common;//ドット絵を設定(デフォルトで1)
			Rin.hitr = 25;//ボスの当たり判定を設定
			Rin.x = 212;//出現位置を設定
			Rin.y = 100;
			Rin.vecx = 0;
			Rin.vecy = 0;
			if (powercount > 2){//自機の状況により難易度別に分ける
				Rin.hitpoint = 3000;//体力を設定
			}
			else{
				Rin.hitpoint = 1000;
			}
			Endtime = Begintime + 2;
			Bosshit = false;
			Bosstime = 2;
			break;
		case 9://冴月麟　通常戦
			Bosshit = true;//ボスの当たり判定を有効化
			Bosstime = 40;//ボスフェーズ(通常)時間を設定
			Endtime = 98;//ボスフェーズ終了時間を設定
			Looptime = 8;//ループ間隔を設定
			Rin.phasecount = 0;
			hitpointdisp = 1;
			Maxhitpoint = Rin.hitpoint;//最大HPをコピー
			//開始と同時に弾幕を発射する場合はこのタイミングで発動
			danmaku.Setdanmaku_Ko((int)(Rin.x), (int)(Rin.y), 1.5, danmaku.dshu.ring, danmaku.dcolor.white, 0, 191, 351, 10);
			nextrin[1][1] = 92;
			nextrin[1][2] = 160;
			nextrin[2][1] = 152;
			nextrin[2][2] = 100;
			nextrin[3][1] = 212;
			nextrin[3][2] = 160;
			nextrin[4][1] = 272;
			nextrin[4][2] = 100;
			nextrin[5][1] = 332;
			nextrin[5][2] = 160;
			break;
		case 10://冴月麟　スペルカード　
			Spell = true;
			Bosshit = false;
			hitpointdisp = 2;
			Bosstime = 80;
			appearx = 150;
			appeary = 20;
			danmaku.ClearDanmaku();
			eff.RequestSE(eff.se.spell);
			SpellKardName = "風符「幻想の管理者～忘却」";
			Looptime = 6;
			Rin.hitpoint = (int)(5000 / (6 - powercount));
			Maxhitpoint = Rin.hitpoint;
			Rin.vecx = (double)(212 - Rin.x) / 40;
			Rin.vecy = (double)(100 - Rin.y) / 40;
			SpellBonusScore = 2000000;
			decreasebonusperflame = SpellBonusScore / (Bosstime * 60);
			danmaku.DirectInputkansu_en(212, 123, 60);
			danmaku.DirectInputkansu_en(152, 243, 60);
			danmaku.DirectInputkansu_en(272, 243, 60);
			danmaku.DirectInputkansu_en(92, 363, 60);
			danmaku.DirectInputkansu_en(212, 363, 60);
			danmaku.DirectInputkansu_en(332, 363, 60);
			Endtime += 50;
			break;
		case 11://中ボス戦終了
			Bosshit = false;
			Spell = false;
			Maxhitpoint = 0;
			danmaku.ClearDanmaku();
			eff.RequestSE(eff.se.bossend);
			Bosstime = 6;
			holizon.by = 1450;
			Endtime += Begintime + 6;
			SetItem(Rin.x, Rin.y, 0, 120, 20);
			break;
		case 12://シーン8
			rinbuttle = false;
			Bossbuttle = false;
			Endtime = 152;
			break;
		case 13://シーン9
			danmaku.DirectInputkansu_en(92, 213, 60);
			danmaku.DirectInputkansu_en(332, 213, 60);
			danmaku.DirectInputkansu_en(212, 303, 60);
			Endtime = Begintime + 35;
			break;
		case 14://シーン10
			Endtime = Begintime + 25;
			karakaze = false;
			break;
		case 15://大ボス戦　インターバル
			danmaku.eff.EndKarakkaze();
			StartTalk("Stage4");
			
			switch (PlayerData.jikinum){
			case 0:
				talktitle = "布都vs明子＆みどり";
				break;
			case 1:
				talktitle = "魅魔vs明子＆みどり";
				break;
			case 2:
				talktitle = "早苗vs明子＆みどり";
				break;
			case 3:
				talktitle = "咲夜vs明子＆みどり";
				break;
			}
			TalkReady(talktitle,standnum);
			nexttalk = true;
			Bossbuttle = true;
			BossTalk = true;
			rinbuttle = false;
			lastbuttle = 0;
			ChangeBGMNumber = 8;
			Bosstime = 1000;
			appear = 0;
			akiko.imgpoji = DotAct.common;
			midori.imgpoji = DotAct.common;
			ChangeBGMtalkcount = 1;
			Talkcount = 100;//ProcessTalk使用時はTalkcountの出番はないが、BGM変更のスイッチとして利用するものとする。
			BossStandPosition = -1;
			JikiStandPosition = 0;
			break;
		case 16://大ボス戦前半　通常戦1
			FileRead_close(Talkfile);
			danmaku.ClearDanmaku();
			Bossbuttle = true;//ボス戦を有効に
			rinbuttle = false;
			BossTalk = false;
			hitpointdisp = 1;
			BossName = "Akiko & Midori";//ボス名を設定
			akiko.hitr = 25;//ボスの当たり判定を設定
			midori.hitr = 20;

			if (powercount > 2) {//自機の状況により難易度別に分ける
				yonboss.hitpoint = 3000;//体力を設定。なお前半戦の体力は２人の掛け持ちとする。
			}
			else {
				yonboss.hitpoint = 1000;
			}
			Maxhitpoint = yonboss.hitpoint;
			yonboss.phasecount = 2;
			Endtime = Begintime + 66;
			Bosshit = true;
			Bosstime = 66;
			Looptime = 11;
			break;
		case 17://大ボス戦前半　スペルカード1
			Spell = true;
			Bosshit = false;
			hitpointdisp = 2;
			Bosstime = 99;
			danmaku.ClearDanmaku();
			eff.RequestSE(eff.se.spell);
			SpellKardName = "巡礼「同人誌即売会 - 祭 -」";
			Looptime = 16;
			akiko.vecx = (80 - akiko.x) / 80;
			akiko.vecy = (80 - akiko.y) / 80;
			midori.vecx = (212 - midori.x) / 80;
			midori.vecy = (243 - midori.y) / 80;
			appearx = 20;
			appeary = 20;
			yonboss.hitpoint = (int)(5000 / (6 - powercount));
			Maxhitpoint = yonboss.hitpoint;
			SpellBonusScore = 1000000;
			decreasebonusperflame = SpellBonusScore / (Bosstime * 60);
			break;
		case 18://大ボス戦前半　通常戦2
			Bosshit = false;//ボスの当たり判定を無効化
			Bosstime = 55;//ボスフェーズ(通常)時間を設定
			danmaku.ClearDanmaku();
			yonboss.phasecount--;
			eff.RequestSE(eff.se.spellend);
			totalscore += SpellBonusScore;
			totalscore += 500000;
			Spell = false;
			Looptime = 11;
			hitpointdisp = 1;
			akiko.vecx = (double)(62 - akiko.x) / 80;
			akiko.vecy = (double)(120 - akiko.y) / 80;
			midori.vecx = (double)(362 - midori.x) / 80;
			midori.vecy = (double)(250 - midori.y) / 80;
			kkakudo[0] = 0;
			kkakudo[1] = 0;
			if (powercount > 2) {//自機の状況により難易度別に分ける
				yonboss.hitpoint = 3000;//体力を設定。なお前半戦の体力は２人の掛け持ちとする。
			}
			else {
				yonboss.hitpoint = 1000;
			}
			Maxhitpoint = yonboss.hitpoint;
			yonboss.phasecount--;
			SetItem(akiko.x, akiko.y, 1, 10, 10);
			SetItem(midori.x, midori.y, 1, 10, 10);
			PreBonusScore = SpellBonusScore;
			break;
		case 19://大ボス戦前半　スペルカード2
			Spell = true;
			Bosshit = false;
			hitpointdisp = 2;
			Bosstime = 99;
			danmaku.ClearDanmaku();
			eff.RequestSE(eff.se.spell);
			SpellKardName = "欲愛「エニワン　ミーツ　エニワン」";
			Looptime = 15;
			akiko.vecx = (122 - akiko.x) / 80;
			akiko.vecy = (250 - akiko.y) / 80;
			midori.vecx = (302 - midori.x) / 80;
			midori.vecy = (250 - midori.y) / 80;
			appearx = 20;
			appeary = 20;
			kkakudo[1] = 0;
			kkakudo[2] = 0;
			yonboss.hitpoint = (int)(5000 / (6 - powercount));
			Maxhitpoint = yonboss.hitpoint;
			SpellBonusScore = 1500000;
			decreasebonusperflame = SpellBonusScore / (Bosstime * 60);
			
			break;
		case 20://大ボス戦前半　スペルカード3
			Spell = false;
			Bosshit = false;
			hitpointdisp = 3;
			yonboss.phasecount--;
			Bosstime = 99;
			eff.RequestSE(eff.se.spellend);
			danmaku.ClearDanmaku();
			danmaku.DanmakuRefresh();
			totalscore += SpellBonusScore;
			totalscore += 500000;
			SpellKardName = "煩符「パラノイア解放」";
			Looptime = 9;
			akiko.vecx = (212 - akiko.x) / 80;
			akiko.vecy = (150 - akiko.y) / 80;
			midori.vecx = (212 - midori.x) / 80;
			midori.vecy = (80 - midori.y) / 80;
			appearx = 0;
			appeary = 150;
			yonboss.hitpoint = (int)(6000 / (6 - powercount));
			Maxhitpoint = yonboss.hitpoint;
			
			break;
		case 21://大ボス戦前半終了　インターバル
			danmaku.eff.EndKarakkaze();
			totalscore += SpellBonusScore;
			totalscore += 1000000;
			danmaku.ClearDanmaku();
			StartTalk("Stage4");
			/*デバッグ用
			lastbuttle = 1;
			danmaku.lastbuttle = true;
			akiko.x = 100;
			akiko.y = 100;
			midori.x = 300;
			midori.y = 100;
			//ここまでデバッグ*/
			switch (lastbuttle) {			
			case 1:
				talktitle = "vs明子";
				ChangeBGMNumber = 9;
				break;
			case 2:
				talktitle = "vsみどり";
				ChangeBGMNumber = 10;
				break;
			default:
				talktitle = "エラー";
				break;
			}
			TalkReady(talktitle, standnum);
			nexttalk = false;
			Bossbuttle = true;
			BossTalk = true;
			rinbuttle = false;	
			Spell = false;
			Bosstime = 100;
			Maxhitpoint = 0;
			akiko.imgpoji = DotAct.common;
			midori.imgpoji = DotAct.common;
			ChangeBGMtalkcount = 1;
			Talkcount = 100;//ProcessTalk使用時はTalkcountの出番はないが、BGM変更のスイッチとして利用するものとする。
			BossStandPosition = -1;
			JikiStandPosition = 0;
			talk.jstand = jstand[StandAct.common];
			talk.bossstand1 = akikostand[StandAct.common];
			talk.bossstand2 = midoristand[StandAct.common];
			break;
		case 22://大ボス戦後半　トーク
			StartTalk("Stage4");
			nexttalk = false;
			Bosstime = 100;
			Talkcount = 100;
			switch (PlayerData.jikinum) {
			case 0:
				if (lastbuttle == 1) {
					talktitle = "布都vs明子";
				}
				else {
					talktitle = "布都vsみどり";
				}
				break;
			case 1:
				if (lastbuttle == 1) {
					talktitle = "魅魔vs明子";
				}
				else {
					talktitle = "魅魔vsみどり";
				}
				break;
			case 2:
				if (lastbuttle == 1) {
					talktitle = "早苗vs明子";
				}
				else {
					talktitle = "早苗vsみどり";
				}
				break;
			case 3:
				if (lastbuttle == 1) {
					talktitle = "咲夜vs明子";
				}
				else {
					talktitle = "咲夜vsみどり";
				}
				break;
			}
			if (lastbuttle == 2) {
				talk.bossstand1 = midoristand[StandAct.common];
			}
			TalkReady(talktitle, standnum);
			break;
		case 23://大ボス戦後半　通常戦1
			FileRead_close(Talkfile);
			danmaku.ClearDanmaku();
			Bossbuttle = true;//ボス戦を有効に
			rinbuttle = false;
			BossTalk = false;
			Spell = false;
			hitpointdisp = 1;
			Bosshit = true;
			if (lastbuttle == 1) {
				//明子戦				
				if (powercount > 2) {//自機の状況により難易度別に分ける
					akiko.hitpoint = 3000;//体力を設定。
				}
				else {
					akiko.hitpoint = 1000;
				}
				Maxhitpoint = akiko.hitpoint;
				akiko.phasecount = 2;
				Endtime = Begintime + 45;
				akiko.hitr = 20;
				Bosstime = 45;
				Looptime = 11;
			}
			else {
				//みどり戦
				if (powercount > 2) {//自機の状況により難易度別に分ける
					midori.hitpoint = 3000;//体力を設定。
				}
				else {
					midori.hitpoint = 1000;
				}
				Maxhitpoint = midori.hitpoint;
				midori.phasecount = 2;
				midori.hitr = 20;
				Endtime = Begintime + 55;
				Bosstime = 55;
				Looptime = 11;
			}
			break;
		case 24://大ボス戦後半　スペルカード1
			hitpointdisp = 2;
			Bosshit = false;
			Spell = true;
			eff.RequestSE(eff.se.spell);
			SpellBonusScore = 3000000;
			danmaku.ClearDanmaku();
			decreasebonusperflame = SpellBonusScore / 6000;
			if (lastbuttle == 1) {
				//明子戦				
				if (powercount > 2) {//自機の状況により難易度別に分ける
					akiko.hitpoint = 3500;//体力を設定。
				}
				else {
					akiko.hitpoint = 2500;
				}
				SpellKardName = "平符「ディペンディングプレート」";
				Maxhitpoint = akiko.hitpoint;
				Endtime = Begintime + 99;
				appearx = 20;
				appeary = 20;
				Bosstime = 99;
				Looptime = 8;
			}
			else {
				//みどり戦
				if (powercount > 2) {//自機の状況により難易度別に分ける
					midori.hitpoint = 4000;//体力を設定。
				}
				else {
					midori.hitpoint = 2000;
				}
				ClearTukaima();
				SpellKardName = "写符「トレーシングメソッド」";
				Maxhitpoint = midori.hitpoint;
				Endtime = Begintime + 99;
				appearx = 20;
				appeary = 20;
				Bosstime = 99;
				Looptime = 10;
			}
			break;
		case 25://大ボス戦後半　通常戦2
			hitpointdisp = 1;
			Bosshit = false;
			Spell = false;
			
			danmaku.ClearDanmaku();
			if (Bosstime > 0) {
				eff.RequestSE(eff.se.spellend);
			}
			totalscore += SpellBonusScore;
			totalscore += 750000;
			if (lastbuttle == 1) {
				//明子戦				
				if (powercount > 2) {//自機の状況により難易度別に分ける
					akiko.hitpoint = 4000;//体力を設定。
				}
				else {
					akiko.hitpoint = 2200;
				}
				if (SpellBonusScore > 0) {
					SetItem(akiko.x, akiko.y, 0, 20, 30);
				}
				else {
					SetItem(akiko.x, akiko.y, 0, 30, 20);
				}
				akiko.phasecount--;
				akiko.vecx = (62 - akiko.x) / 40;
				akiko.vecy = (90 - akiko.y) / 40;
				danmaku.ClearDaen();
				Maxhitpoint = akiko.hitpoint;
				Endtime = Begintime + 45;
				Bosstime = 66;
				Looptime = 10;
			}
			else {
				//みどり戦
				if (powercount > 2) {//自機の状況により難易度別に分ける
					midori.hitpoint = 5000;//体力を設定。
				}
				else {
					midori.hitpoint = 2500;
				}
				if (SpellBonusScore > 0) {
					SetItem(midori.x, midori.y, 0, 20, 30);
				}
				else {
					SetItem(midori.x, midori.y, 0, 30, 20);
				}
				ClearTukaima();
				midori.phasecount--;
				Maxhitpoint = midori.hitpoint;
				Endtime = Begintime + 90;
				Bosstime = 90;
				Looptime = 12;
				if (midori.x != 212 || midori.y != 100) {
					midori.vecx = (212 - midori.x) / 80;
					midori.vecy = (100 - midori.y) / 80;
				}
			}
			break;
		case 26://大ボス戦後半　スペルカード2
			hitpointdisp = 2;
			Bosshit = false;
			Spell = true;
			eff.RequestSE(eff.se.spell);
			SpellBonusScore = 4000000;
			danmaku.ClearDanmaku();
			decreasebonusperflame = SpellBonusScore / 6000;
			if (lastbuttle == 1) {
				//明子戦				
				if (powercount > 2) {//自機の状況により難易度別に分ける
					akiko.hitpoint = 5500;//体力を設定。
				}
				else {
					akiko.hitpoint = 3000;
				}
				SetItem(akiko.x, akiko.y, 0, 10, 10);
				Maxhitpoint = akiko.hitpoint;
				Endtime = Begintime + 99;
				Bosstime = 99;
				Looptime = 10;
				appearx = 20;
				appeary = 20;
				SpellKardName = "着符「満たされる欲望　- 仮装 -」";
				akiko.vecx = (212 - akiko.x) / 40;
				akiko.vecy = (243 - akiko.y) / 40;
				danmaku.ClearDaen();
			}
			else {
				//みどり戦
				if (powercount > 2) {//自機の状況により難易度別に分ける
					midori.hitpoint = 6000;//体力を設定。
				}
				else {
					midori.hitpoint = 3000;
				}
				SetItem(midori.x, midori.y, 0, 10, 10);
				SpellKardName = "欲改「デザイアインプリンティング」";
				ClearTukaima();
				Maxhitpoint = midori.hitpoint;
				Endtime = Begintime + 99;
				midori.vecx = (212 - midori.x) / 40;
				midori.vecy = (243 - midori.y) / 40;
				appearx = 20;
				appeary = 20;
				Bosstime = 99;
				Looptime = 10;
			}
			break;
		case 27://大ボス戦後半　スペルカード3
			hitpointdisp = 3;
			Bosshit = false;
			Spell = false;
			totalscore += SpellBonusScore;
			totalscore += 750000;
			danmaku.ClearDanmaku();
			if (lastbuttle == 1) {
				//明子戦				
				if (powercount > 2) {//自機の状況により難易度別に分ける
					akiko.hitpoint = 5500;//体力を設定。
				}
				else {
					akiko.hitpoint = 3000;
				}
				akiko.phasecount--;
				if (SpellBonusScore > 0) {
					SetItem(akiko.x, akiko.y, 0, 20, 30);
				}
				else {
					SetItem(akiko.x, akiko.y, 0, 30, 20);
				}
				SpellKardName = "妄創「ディルージョンクリエイト」";
				Maxhitpoint = akiko.hitpoint;
				Endtime = Begintime + 99;
				Bosstime = 99;
				Looptime = 9;
			}
			else {
				//みどり戦
				if (powercount > 2) {//自機の状況により難易度別に分ける
					midori.hitpoint = 6500;//体力を設定。
				}
				else {
					midori.hitpoint = 3900;
				}
				midori.phasecount--;
				if (SpellBonusScore > 0) {
					SetItem(midori.x, midori.y, 0, 20, 30);
				}
				else {
					SetItem(midori.x, midori.y, 0, 30, 20);
				}
				SpellKardName = "禁符「リストリクティッド18」";
				Maxhitpoint = midori.hitpoint;
				Endtime = Begintime + 99;
				Bosstime = 99;
				Looptime = 8;
			}
			break;		
		case 28://大ボス戦終了　大破
			eff.RequestSE(eff.se.bossend);
			totalscore += SpellBonusScore;
			totalscore += 1000000;
			Maxhitpoint = 0;
			danmaku.ClearDanmaku();
			Spell = false;
			Bosshit = false;
			BossTalk = true;
			Talkcount = 100;
			Endtime = 1000;
			Bosstime = 1000;
			StartTalk("Stage4");
			switch (PlayerData.jikinum) {
			case 0:
				if (lastbuttle == 1) {
					talktitle = "布都vs明子";
				}
				else {
					talktitle = "布都vsみどり";
				}
				break;
			case 1:
				if (lastbuttle == 1) {
					talktitle = "魅魔vs明子";
				}
				else {
					talktitle = "魅魔vsみどり";
				}
				break;
			case 2:
				if (lastbuttle == 1) {
					talktitle = "早苗vs明子";
				}
				else {
					talktitle = "早苗vsみどり";
				}
				break;
			case 3:
				if (lastbuttle == 1) {
					talktitle = "咲夜vs明子";
				}
				else {
					talktitle = "咲夜vsみどり";
				}
				break;
			}
			TalkReady("トーク3勝利後", standnum);
			TalkReady(talktitle, standnum);
			if (lastbuttle == 1) {
				talk.bossstand1 = akiko2stand[StandAct.cry];
			}
			else {
				talk.bossstand1 = midori2stand[StandAct.cry];
			}
			BossStandPosition = StandAct.cry;
			StageClearscore = 5000000;
			totalscore += StageClearscore;
			break;
		case 29://Stage4終了
			break;
		}
		if (Bossbuttle == false){ tekicount += CountNewEnemy(newscene,Endtime - Begintime); }
		return r;
	}
	int PasteHolizon(int flame){
		if (DrawBox(19, 14, 405, 466, color.white, FALSE) != 0){
			return -1;
		}
		SetDrawArea(20, 15, 404, 465);
		if (Spell){
			int cl;
			if (rinbuttle){
				cl = GetColor(70, 70, 20);
				DrawBox(20, 15, 404, 465, cl, TRUE);
			}
			else{
				switch (lastbuttle){
				case 0://前半戦
					cl = GetColor(70, 20, 70);
					DrawBox(20, 15, 404, 465, cl, TRUE);
					break;
				case 1://後半・明子戦
					DrawGraph(20, 15, holizon.spellback1,false);
					break;
				case 2://後半・みどり戦
					DrawGraph(20, 15, holizon.spellback2,false);
					break;
				}
			}
			
		}
		else{
			if (rinbuttle == false && Bossbuttle){
				if (flame < 119 && scene == 15){
					if (flame < 61){
						DrawGraph(20, 15, holizon.back, false);
						SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255 * flame / 60);
						DrawBox(20, 15, 403, 464, GetColor(255, 255, 100), true);
						SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
					}
					else{
						DrawGraph(20, 15, holizon.bossback, false);
						SetDrawBlendMode(DX_BLENDMODE_ALPHA, (int)(255 / (flame - 60)) );
						DrawBox(20, 15, 403, 464, GetColor(255, 255, 100), true);
						SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
					}
				}
				else{
					int bright = 255;
					switch (scene) {
					case 15://トーク1
						break;
					case 16:
						break;
					case 18:
						bright = 128;
						break;
					case 21://トーク2
						bright = 128;
						break;
					case 22:
						bright = 64;
					case 23:
						bright = 64;
						break;
					case 25:
						bright = 64;
						break;
					case 27://ボス終了後
						break;						
					}

					SetDrawBright(bright, bright, bright);
					DrawGraph(20, 15, holizon.bossback, false);
					
					if ((scene == 22 && (midori.imgpoji == DotAct.common + 2 || akiko.imgpoji == DotAct.common + 2)) ||(scene == 23 || scene == 25) ){
						SetDrawBlendMode(DX_BLENDGRAPHTYPE_ALPHA, 128);
						if (lastbuttle == 1) {
							DrawBox(20, 15, 404, 465, GetColor(200, 50, 200), true);
						}
						else {
							DrawBox(20, 15, 404, 465, GetColor(50, 200, 200), true);
						}
						SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 128);
					}
					bright = 255;
					SetDrawBright(bright, bright, bright);
				}
				
					
			}else{
				if (scene > 0){
					int c = 150;
					switch (scene){
					case 1:
						c = 50;
						break;
					case 2:
						c = 50 + 100 * flame / 360;
						break;
					case 12:
						if (flame < 360){
							c = 150 - 100 * flame / 360;
						}
						else{
							c = 50;
						}
						break;
					case 14:
						if (flame < 360) {
							c = 50 + 100 * flame / 360;
						}
						else {
							c = 50;
						}
						break;
					}
					if (scene > 2 && scene < 11){
						c = 150;
					}
					if (scene > 12){
						c = 50;
					}
					SetDrawBright(c, c, c);
					DrawRectGraph(20, 15, 0, holizon.by, 388, 450, holizon.back, false, false);
					SetDrawBright(255, 255, 255);
					int f = 10;
					if (scene > 10) {
						f = 2;
					}
					
					if (rinbuttle == false && flame % f == 0 && holizon.by > 0) {
						holizon.by -= 1;
					}
				}
				else{
					DrawBox(20, 15, 404, 465, GetColor(0, 0, 0), true);
				}
			}
		}
		//DrawFormatString(500,390,GetColor(255,255,255),"シーン%d,%d秒経過",scene,flame / 60);
		/*スコア・残機・ボム数・グレーズ・パワー段階などを描写*/
		return 0;
	}
	int ProcessStage(int flame,int powercount){
		int r = 0;
		r = 4;
		totalscore = 0;
		prescene = scene;
		if (flame == 1){
			Currenttime++;
			s++;
			if (missnothit != 0){
				missnothit--;
			}
		}//一秒経過ごとに加算。
		if (scene == 29){//シーン28が終了したらStage4はクリア//シーンごとに成功したら終了。
			r = 5;
		}
		return r;
	}
	int ProcessEnemy(int flame){
		int r = 0;
		int p;
		r = 0;
		/*
		if (tekicount > 0){
			p = teki[0].np; 
		}
		else{
			p = tail;
		}
		*/
		p = teki[0].np;
		if (scene == 2 && flame > 60){
			DrawStringToHandle(50, 150, "Stage4 幻と現の境界路", GetColor(255, 255, 255), Stagefont);
			DrawStringToHandle(120, 165, "～ Enlightenment's Silkroad", GetColor(255, 255, 255), Stagefont);
		}
		while (p != tail){
			if (teki[p].ready == 0){
				switch (teki[p].scene){
				case 1:
					teki[p].x += teki[p].vecx;
					teki[p].y += teki[p].vecy;
					if (p < 11){
						//1ループ目
						if ((flame - teki[p].start) % 30 == 0){
							danmaku.Setdanmaku_Wave((int)(teki[p].x), (int)(teki[p].y), 2, danmaku.dshu.ring, danmaku.dcolor.red, 0, kakudo, 9);
							kakudo += 2;
						}
					}
					else{
						if (p < 21){
							//2ループ目
							int setflame = 0;
							switch (p % 5){
							case 0:
								setflame = 90;
								break;
							case 1:
								setflame = 40;
								break;
							case 2:
								setflame = 10;
								break;
							case 3:
								setflame = 60;
								break;
							case 4:
								setflame = 25;
								break;
							}
							if (flame - 240 - setflame > -1 && (flame - 240 - setflame) % 60 == 0){
								danmaku.Setdanmaku_Wave((int)(teki[p].x), (int)(teki[p].y), 3, danmaku.dshu.ring, danmaku.dcolor.purple, 0, danmaku.Getkakudo_Homing(teki[p].x,teki[p].y,j.x,j.y), 9);
							}

						}
						else{
							//3ループ目
							if (teki[p].hitpoint == 0.01){
								danmaku.Setdanmaku_Wave((int)(teki[p].x), (int)(teki[p].y), 1, danmaku.dshu.middle, danmaku.dcolor.white, 0, danmaku.Getkakudo_Homing(teki[p].x, teki[p].y, j.x, j.y), 5);
								DeleteEnemy(p);
							}
						}
					}
					break;
				case 3:
					switch (teki[p].tekishu){
					case 2://青妖精
					if (tteki[p].usef == 0){
							teki[p].x += teki[p].vecx;
							if ((int)(flame - teki[p].start) % 25 == 0){
								danmaku.Setdanmaku_ChainRendan((int)(teki[p].x), (int)(teki[p].y), 2, danmaku.Getkakudo_Homing(teki[p].x, teki[p].y, j.x, j.y), danmaku.dshu.uroko, danmaku.dcolor.white, 0,1, 0);
							}
						}
						else{
							teki[p].x += teki[p].vecx;
							
							switch (tteki[p].usef){
							case 1://左楕円
								if (teki[p].x >= 212){
									tteki[p].usef = 4;
									teki[p].vecx = -1;
									teki[p].x = 211;
									teki[p].imgposi = DotAct.common;
									tteki[p].kanshu = 2;
									tteki[p].fugou = 1;
								}
								if (teki[p].x > 152){
									teki[p].imgposi = DotAct.comright;
								}
								if ((int)(teki[p].x) == 92 || (int)(teki[p].x) == 152){
									danmaku.Setdanmaku_ChainRendan((int)(teki[p].x), (int)(teki[p].y), 2, danmaku.Getkakudo_Homing(teki[p].x, teki[p].y, j.x, j.y), danmaku.dshu.uroko, danmaku.dcolor.white, 0, 6, 8);
								}
								break;
							case 2://右楕円
								if (teki[p].x <= 212){
									tteki[p].usef = 5;
									teki[p].vecx = 1;
									teki[p].x = 213;
									teki[p].imgposi = DotAct.common;
									tteki[p].kanshu = 2;
									tteki[p].fugou = 1;
								}
								if (teki[p].x > 272){
									teki[p].imgposi = DotAct.comleft;
								}
								if ((int)(teki[p].x) == 332 || (int)(teki[p].x) == 272){
									danmaku.Setdanmaku_ChainRendan((int)(teki[p].x), (int)(teki[p].y), 2, danmaku.Getkakudo_Homing(teki[p].x, teki[p].y, j.x, j.y), danmaku.dshu.uroko, danmaku.dcolor.white, 0, 6, 8);
								}
								break;
							case 4://中央左円
								if (teki[p].x < 182){
									teki[p].imgposi = DotAct.comleft;
								}
								if (teki[p].x <= 152){
									tteki[p].usef = 0;
									teki[p].vecx = -135 / 90;
									teki[p].imgposi = DotAct.left;
									teki[p].x = 152;
								}
								if ((int)(flame - teki[p].start) % 25 == 0){
									danmaku.Setdanmaku_ChainRendan((int)(teki[p].x), (int)(teki[p].y), 2, danmaku.Getkakudo_Homing(teki[p].x, teki[p].y, j.x, j.y), danmaku.dshu.uroko, danmaku.dcolor.white, 0, 1, 0);
								}
								break;
							case 5://中央右円
								if (teki[p].x > 242){
									teki[p].imgposi = DotAct.comright;
								}
								if (teki[p].x >= 272){
									tteki[p].usef = 0;
									teki[p].x = 272;
									teki[p].imgposi = DotAct.right;
									teki[p].vecx = (389 - 272) / 90;
								}
								if ((int)(flame - teki[p].start) % 25 == 0){
									danmaku.Setdanmaku_ChainRendan((int)(teki[p].x), (int)(teki[p].y), 2, danmaku.Getkakudo_Homing(teki[p].x, teki[p].y, j.x, j.y), danmaku.dshu.uroko, danmaku.dcolor.white, 0, 1, 0);
								}
								break;
							}
							if (tteki[p].usef != 0){
								teki[p].y = danmaku.GetY(teki[p].x, tteki[p].usef, tteki[p].kanshu, tteki[p].fugou);
							}
						}
						break;
					case 5://ひまわり妖精
						teki[p].x += teki[p].vecx;
						teki[p].y += teki[p].vecy;
						switch ((int)(teki[p].vecy * 100)){
						case 0:
							if (flame - stoptime == 60){
								teki[p].vecy = -1.86;
							}
							break;
						case 93:
							if (teki[p].y >= 243){
								teki[p].vecy = 0;
								stoptime = flame;
							}
							if ((int)(teki[p].y) == 123){
								danmaku.Setdanmaku_Ko((int)(teki[p].x), (int)(teki[p].y), 3, danmaku.dshu.mayu, danmaku.dcolor.white, 0, 60, 120, 6);
							}
							if ((int)(teki[p].y) == 183 || (int)(teki[p].y) == 63 || (int)(teki[p].y) == 184 || (int)(teki[p].y) == 64){
								danmaku.Setdanmaku_Ko((int)(teki[p].x), (int)(teki[p].y), 3, danmaku.dshu.mayu, danmaku.dcolor.white, 0, 60, 120, 10);
							}
							break;
						case -186:
							if ((int)(teki[p].y + teki[p].vecy) == 243){
								danmaku.Setdanmaku_Wave((int)(teki[p].x), (int)(teki[p].y), 3, danmaku.dshu.ring, danmaku.dcolor.white, 0, 0,90);
							}
							break;
						case 25:
							if ((teki[p].x < 212 && teki[p].x + teki[p].vecx > 212) || (teki[p].x > 212 && teki[p].x - teki[p].vecx < 212)){
								danmaku.Setdanmaku_Wave((int)(teki[p].x), (int)(teki[p].y), 3, danmaku.dshu.kome, danmaku.dcolor.white, 0,danmaku.Getkakudo_Homing(teki[p].x,teki[p].y,j.x,j.y), 30);
							}
							break;
						}
						break;
					}
					break;
				case 4:
					switch (teki[p].tekishu){
					case 1://赤妖精
						if (tteki[p].usef == 0){
							teki[p].x += teki[p].vecx;
							teki[p].y += teki[p].vecy; 
							if (teki[p].y <= 123){
								tteki[p].usef = 2;
								tteki[p].fugou = -1;
								tteki[p].kanshu = 2;
								if (teki[p].x < 212){
									teki[p].vecx = 0.75;
									teki[p].imgposi = 4;
								}
								else{
									teki[p].vecx = -0.75;
									teki[p].imgposi = 3;
								}
							}
						}
						else{
							teki[p].x += teki[p].vecx;
							if (tteki[p].usef != 0){
								teki[p].y = danmaku.GetY(teki[p].x, tteki[p].usef, tteki[p].kanshu, tteki[p].fugou);
							}
							switch (tteki[p].usef){
							case 1:
								if (teki[p].x <= 122){
									tteki[p].usef = 0;
									teki[p].vecx = (20 - 122) / 30;
									teki[p].vecy = 0;
									teki[p].imgposi = 3;
								}
								break;
							case 2:
								if (teki[p].vecx > 0){
									if (teki[p].x >= 272){
										tteki[p].usef = 3;
										tteki[p].fugou = 1;
										teki[p].imgposi = 2;
									}
								}
								else{
									if (teki[p].x <= 152){
										tteki[p].usef = 1;
										tteki[p].fugou = 1;
										teki[p].imgposi = 1;
									}
								}
								break;
							case 3:
								if (teki[p].x >= 302){
									tteki[p].usef = 0;
									teki[p].vecx = (404 - 302) / 30;
									teki[p].vecy = 0;
									teki[p].imgposi = 4;
								}
								break;
							}

						}
						break;
					case 2://青妖精
						if (tteki[p].usef == 0){
							teki[p].x += teki[p].vecx;
							teki[p].y += teki[p].vecy;
							if (teki[p].vecy == 0){
								if (teki[p].vecx < 0){
									if ((int)(teki[p].x) <= 152){
										//円4
										tteki[p].usef = 4;
										tteki[p].kanshu = 2;
										tteki[p].fugou = -1;
										teki[p].vecy = 0;
										teki[p].vecx = -1.5;
										teki[p].imgposi = 1;
									}
								}
								else{
									if ((int)(teki[p].x) >= 272){
										//円5
										tteki[p].usef = 5;
										tteki[p].kanshu = 2;
										tteki[p].fugou = -1;
										teki[p].vecy = 0;
										teki[p].vecx = 1.5;
										teki[p].imgposi = 2;
									}
								}
							}
							else{
								if ((int)(teki[p].y) >= 123 && (int)(teki[p].y) < 183){
									if (teki[p].x > 212){
										//円3
										tteki[p].usef = 3;
										tteki[p].kanshu = 2;
										tteki[p].fugou = 1;
										teki[p].vecy = 0;
										teki[p].vecx = -1.5;
										teki[p].imgposi = 1;
									}
									else{
										//円1
										tteki[p].usef = 1;
										tteki[p].kanshu = 2;
										tteki[p].fugou = 1;
										teki[p].vecy = 0;
										teki[p].vecx = 1.5;
										teki[p].imgposi = 2;
									}
								}
							}
						}
						else{
							teki[p].x += teki[p].vecx;
							if (tteki[p].usef != 0){
								teki[p].y = danmaku.GetY(teki[p].x, tteki[p].usef, tteki[p].kanshu, tteki[p].fugou);
							}
							switch (tteki[p].usef){
							case 1:
								if ((int)(teki[p].x) >= 92){
									tteki[p].usef = 0;
									teki[p].vecy = 0;
									teki[p].vecx = 2;
									teki[p].imgposi = 4;
								}
								break;
							case 3:
								if ((int)(teki[p].x) <= 332){
									tteki[p].usef = 0;
									teki[p].vecy = 0;
									teki[p].vecx = -2;
									teki[p].imgposi = 3;
								}
								break;
							case 4:
								if ((int)(teki[p].x) <= 92){
									tteki[p].usef = 0;
									teki[p].vecx = 0;
									teki[p].vecy = 1.85;
									teki[p].imgposi = 0;
								}
								break;
							case 5:
								if ((int)(teki[p].x) >= 332){
									tteki[p].usef = 0;
									teki[p].vecx = 0;
									teki[p].vecy = 1.85;
									teki[p].imgposi = 0;
								}
								break;
							}
						}
						break;
					case 3://黄妖精
						teki[p].x += teki[p].vecx;
						if ((flame - teki[p].start) % 20 == 0){
							danmaku.Setdanmaku_ChainRendan((int)(teki[p].x), (int)(teki[p].y), 2, 90, danmaku.dshu.middle, danmaku.dcolor.white, 0, 2, 15);
						}
						break;
					case 4://緑妖精
						teki[p].x += teki[p].vecx;
						teki[p].y += teki[p].vecy;
						if ((int)(teki[p].x - 32) % 60 == 0){
							danmaku.Setdanmaku_ChainRendan((int)(teki[p].x), (int)(teki[p].y), 0.75, danmaku.Getkakudo_Homing(teki[p].x, teki[p].y, j.x, j.y), danmaku.dshu.ring, danmaku.dcolor.white, 0, 5, 10);
						}
						break;
					}
					break;
				case 5:
					teki[p].y += teki[p].vecy;
					if (p == 110){
						if (teki[p].y == 105){
							stoptime = flame;
							teki[p].vecy = 0;
						}
						if (stoptime > 0){
							if (flame - stoptime == 480){
								teki[p].vecy = -1.3;
								teki[p].y += teki[p].vecy;
							}
							switch (flame % 60){
							case 0:
								danmaku.Setdanmaku_Ko((int)(teki[p].x), (int)(teki[p].y), 1, danmaku.dshu.tubu, danmaku.dcolor.white, 0, 55, 135, 15);
								break;
							case 8:
								danmaku.Setdanmaku_ChainRendan((int)(teki[p].x), (int)(teki[p].y), 2, danmaku.Getkakudo_Homing(teki[p].x, teki[p].y, j.x, j.y) + 10, danmaku.dshu.kome, danmaku.dcolor.white, 0, 2, 10);
								danmaku.Setdanmaku_ChainRendan((int)(teki[p].x), (int)(teki[p].y), 2, danmaku.Getkakudo_Homing(teki[p].x, teki[p].y, j.x, j.y) + 40, danmaku.dshu.kome, danmaku.dcolor.white, 0, 2, 10);
								danmaku.Setdanmaku_ChainRendan((int)(teki[p].x), (int)(teki[p].y), 2, danmaku.Getkakudo_Homing(teki[p].x, teki[p].y, j.x, j.y) - 20, danmaku.dshu.kome, danmaku.dcolor.white, 0, 2, 10);
								break;
							case 20:
								danmaku.Setdanmaku_Ko((int)(teki[p].x), (int)(teki[p].y), 2.75, danmaku.dshu.tubu, danmaku.dcolor.white, 0, 66, 114, 24);
								break;
							case 28:
								danmaku.Setdanmaku_Wave((int)(teki[p].x) + 5, (int)(teki[p].y), 2, danmaku.dshu.hahen, danmaku.dcolor.white, 0, 0, 9);
								danmaku.Setdanmaku_Wave((int)(teki[p].x) - 5, (int)(teki[p].y), 2, danmaku.dshu.hahen, danmaku.dcolor.white, 0, 0, 9);
								break;
							case 36:
								danmaku.Setdanmaku_Wave((int)(teki[p].x) - 5, (int)(teki[p].y) + 5, 2, danmaku.dshu.hahen, danmaku.dcolor.white, 0, 0, 12);
								danmaku.Setdanmaku_Wave((int)(teki[p].x) - 5, (int)(teki[p].y) - 5, 2, danmaku.dshu.hahen, danmaku.dcolor.white, 0, 0, 12);
								break;
							case 42:
								danmaku.Setdanmaku_Ko((int)(teki[p].x), (int)(teki[p].y), 1, danmaku.dshu.tubu, danmaku.dcolor.white, 0, 25, 105, 10);
								danmaku.Setdanmaku_Ko((int)(teki[p].x), (int)(teki[p].y), 1, danmaku.dshu.tubu, danmaku.dcolor.white, 0, 85, 165, 10);
								break;
							case 50:
								danmaku.Setdanmaku_Ko((int)(teki[p].x), (int)(teki[p].y), 2.75, danmaku.dshu.tubu, danmaku.dcolor.white, 0, 36, 84, 8);
								danmaku.Setdanmaku_Ko((int)(teki[p].x), (int)(teki[p].y), 2.75, danmaku.dshu.tubu, danmaku.dcolor.white, 0, 96, 144, 8);
								break;
							}
						}
					}
					else{
						if ((int)(teki[p].y - 3) % 30 == 0){
							danmaku.Setdanmaku_Wave((int)(teki[p].x), (int)(teki[p].y), 3, danmaku.dshu.ring, danmaku.dcolor.white, 0, danmaku.Getkakudo_Homing(teki[p].x, teki[p].y, j.x, j.y), 20);
						}
					}
					break;
				case 6:
					if (teki[p].tekishu == 6){
						teki[p].x += teki[p].vecx;
						if ((flame - teki[p].start) % 200 == 0){
							if (teki[p].y == 63){
								danmaku.Setdanmaku_Wave((int)(teki[p].x), (int)(teki[p].y), 2, danmaku.dshu.kome, danmaku.dcolor.white, 0, kkakudo[1], 6);
								kkakudo[1] += 16;
							}
							else{
								danmaku.Setdanmaku_Wave((int)(teki[p].x), (int)(teki[p].y), 2, danmaku.dshu.kome, danmaku.dcolor.white, 0, kkakudo[2], 6);
								kkakudo[2] += 16;
							}
						}
					}
					else{
						teki[p].x += teki[p].vecx;
						teki[p].y += teki[p].vecy;
						if (pow(teki[p].x - 152, 2.0) + pow(teki[p].y - 243, 2.0) < 3600 || pow(teki[p].x - 272, 2.0) + pow(teki[p].y - 243, 2.0) < 3600){
							if ((flame - teki[p].start) % 100 == 0){
								danmaku.Setdanmaku_ChainRendan((int)(teki[p].x), (int)(teki[p].y), 1, danmaku.Getkakudo_Homing(teki[p].x, teki[p].y, j.x, j.y), danmaku.dshu.tubu, danmaku.dcolor.white, 0, 1, 0);
								danmaku.Setdanmaku_ChainRendan((int)(teki[p].x), (int)(teki[p].y), 2, danmaku.Getkakudo_Homing(teki[p].x, teki[p].y, j.x, j.y - 5), danmaku.dshu.kunai, danmaku.dcolor.white, 0, 1, 0);
							}
						}
					}
					break;
				case 7:
					switch(teki[p].tekishu){
					case 3:
						switch (tteki[p].usef){
						case 0:
							teki[p].x += teki[p].vecx;
							teki[p].y += teki[p].vecy;
							if (p < 212){
								if ((int)(teki[p].x) == 110 && teki[p].vecx == 1.5){
									tteki[p].usef = 4;
									teki[p].vecx = 135;
									teki[p].vecy = -3;
									teki[p].imgposi = 4;
								}
								if ((int)(teki[p].x) > 374 && teki[p].vecx == 2){
									tteki[p].usef = 3;
									teki[p].vecx = 45;
									teki[p].vecy = -3;
									teki[p].imgposi = 0;
								}
							}
							else{
								if ((int)(teki[p].x) == 314 && teki[p].vecx == -1.5){
									tteki[p].usef = 5;
									teki[p].vecx = 45;
									teki[p].vecy = 3;
									teki[p].imgposi = 3;
								}
								if ((int)(teki[p].x) < 49 && teki[p].vecx == -1.8){
									tteki[p].usef = 1;
									teki[p].vecx = 135;
									teki[p].vecy = 3;
									teki[p].imgposi = 0;
								}
							}
							break;
						case 1://関数使用中はvecxが関数内の角度、vecyが関数中の角度の増分（1フレームあたり)とする。
							teki[p].vecx += teki[p].vecy;
							teki[p].x = cos(teki[p].vecx * PI / 180) * 60 + 92;
							teki[p].y = sin(teki[p].vecx * PI / 180) * 60 + 123;
							if (teki[p].vecx == 225){
								tteki[p].usef = 0;
								teki[p].vecx = 1.05;
								teki[p].vecy = -1.05;
								teki[p].imgposi = 6;
							}
							break;
						case 3:
							teki[p].vecx += teki[p].vecy;
							teki[p].x = cos(teki[p].vecx * PI / 180) * 60 + 332;
							teki[p].y = sin(teki[p].vecx * PI / 180) * 60 + 123;
							if (teki[p].vecx == -45){
								tteki[p].usef = 0;
								teki[p].vecx = -1.05;
								teki[p].vecy = -1.05;
								teki[p].imgposi = 5;
							}
							break;
						case 4:
							teki[p].vecx += teki[p].vecy;
							teki[p].x = cos(teki[p].vecx * PI / 180) * 60 + 152;
							teki[p].y = sin(teki[p].vecx * PI / 180) * 60 + 243;
							if (teki[p].vecx == 45){
								tteki[p].usef = 0;
								teki[p].imgposi = 4;
								teki[p].vecx = 2;
								teki[p].vecy = -1.2;
							}
							break;
						case 5:
							teki[p].vecx += teki[p].vecy;
							teki[p].x = cos(teki[p].vecx * PI / 180) * 60 + 272;
							teki[p].y = sin(teki[p].vecx * PI / 180) * 60 + 243;
							if (teki[p].vecx == 135){
								tteki[p].usef = 0;
								teki[p].vecx = -1.8;
								teki[p].vecy = -1.2;
								teki[p].imgposi = 3;
								teki[p].x = 229;
								teki[p].y = 285;
							}
							break;
						}
						if (p < 212){
							if ((flame - teki[p].start) % 72 == 0 && p == teki[0].np){
								danmaku.Setdanmaku_Wave((int)(teki[p].x), (int)(teki[p].y), 1.5, danmaku.dshu.uroko, danmaku.dcolor.white, 0, 0, 16);
							}
						}
						else{
							if ((flame - teki[p].start - 10) % 72 == 0 && teki[p].pp < 212){
								danmaku.Setdanmaku_Wave((int)(teki[p].x), (int)(teki[p].y), 1.5, danmaku.dshu.uroko, danmaku.dcolor.white, 0, 0, 16);
							}
						}
						break;
					case 5:
						teki[p].y += teki[p].vecy;
						if ((flame - teki[p].start) % 60 == 0){
							switch ((flame - teki[p].start) / 60){
							case 0:
								break;
							case 1:
								danmaku.Setdanmaku_Ko((int)(teki[p].x), (int)(teki[p].y), 1.5, danmaku.dshu.uroko, danmaku.dcolor.white, 0, -60, 240, 6);
								break;
							case 2:
								danmaku.Setdanmaku_Ko((int)(teki[p].x), (int)(teki[p].y), 1.5, danmaku.dshu.uroko, danmaku.dcolor.white, 0, -60, 240, 12);
								break;
							case 3:
								danmaku.Setdanmaku_Ko((int)(teki[p].x), (int)(teki[p].y), 1.5, danmaku.dshu.uroko, danmaku.dcolor.white, 0, -60, 240, 20);
								break;
							}
							if ((flame - teki[p].start) / 60 > 3){
								danmaku.Setdanmaku_Ko((int)(teki[p].x), (int)(teki[p].y), 1.5, danmaku.dshu.uroko, danmaku.dcolor.white, 0, -60, 240, 30);
							}
						}
						break;
					}
					break;
				case 12:
					teki[p].y += teki[p].vecy;
					if ((int)(teki[p].y / 30) < (int)((teki[p].y + teki[p].vecy) / 45)){
						danmaku.Setdanmaku_Wave((int)(teki[p].x), (int)(teki[p].y), 1.5, danmaku.dshu.middle, danmaku.dcolor.red, 0, danmaku.Getkakudo_Homing(teki[p].x, teki[p].y, j.x, j.y), 24);
					}
					break;
				case 13:
					switch (teki[p].tekishu){
					case 2://青妖精
						if (((Currenttime * 60 + flame) - teki[p].start) % 150 == 0){
							danmaku.Setdanmaku_Wave((int)(teki[p].x), (int)(teki[p].y), 1.5, danmaku.dshu.middle, danmaku.dcolor.blue, 0, 0, 6);
						}
						if (tteki[p].usef == 0){
							//直線移動
							teki[p].x += teki[p].vecx;
							teki[p].y += teki[p].vecy;
							if (teki[p].vecx == 0 && teki[p].y >= 213){
								if (teki[p].x < 212){
									tteki[p].usef = danmaku.ck.en - 2;
									teki[p].vecx = 180;
									teki[p].vecy = (135 - 180) / 15;
									teki[p].imgposi = DotAct.comright;
								}
								else{
									tteki[p].usef = danmaku.ck.en - 1;
									teki[p].vecx = 0;
									teki[p].vecy = (45 - 0) / 15;
									teki[p].imgposi = DotAct.comleft;
								}
							}
							else{
								if (teki[p].vecx != 0 && teki[p].vecy != 0){
									if (teki[p].y + teki[p].vecy >= 348){
										if (teki[p].vecx > 0){
											tteki[p].usef = danmaku.ck.en;
											teki[p].vecx = 135;
											teki[p].vecy = (int)(225 / 90 * -1);
											teki[p].imgposi = DotAct.right;
										}
										else{
											tteki[p].usef = danmaku.ck.en;
											teki[p].vecx = 45;
											teki[p].vecy = (int)(225 / 90);
											teki[p].imgposi = DotAct.left;
										}

									}
								}
							}
						}
						else{
							//関数使用
							teki[p].vecx += teki[p].vecy;
							if (teki[p].vecx > 360){
								teki[p].vecx -= 360;
							}
							if (teki[p].vecx < 0){
								teki[p].vecx += 360;
							}
							teki[p].x = danmaku.En[3][tteki[p].usef] * cos(teki[p].vecx * PI / 180) + danmaku.En[1][tteki[p].usef];
							teki[p].y = danmaku.En[3][tteki[p].usef] * sin(teki[p].vecx * PI / 180) + danmaku.En[2][tteki[p].usef];
							int en;
							if (tteki[p].usef == danmaku.ck.en){
								en = 3;
							}
							else{
								if (tteki[p].usef == danmaku.ck.en - 1){
									en = 2;
								}
								else{
									en = 1;
								}
							}
							switch (en){
							case 1:
								if (teki[p].vecx == 135){
									tteki[p].usef = 0;
									teki[p].vecx = (double)((169 - teki[p].x) / 90);
									teki[p].vecy = (double)((345 - teki[p].y) / 90);
								}
								break;
							case 2:
								if (teki[p].vecx == 45){
									tteki[p].usef = 0;
									teki[p].vecx = (double)((254 - teki[p].x) / 90);
									teki[p].vecy = (double)((345 - teki[p].y) / 90);
								}
								break;
							case 3:
								if (teki[p].vecy > 0){
									if (teki[p].vecx < 270 && teki[p].vecx + teki[p].vecy >= 270){
										tteki[p].usef = 0;
										teki[p].vecx = (double)(192 / 90);
										teki[p].vecy = 0;
										teki[p].imgposi = DotAct.right;
									}
									if (teki[p].vecx < 180){
										if (teki[p].vecx > 135){
											teki[p].imgposi = DotAct.upleft;
										}
										else{
											teki[p].imgposi = DotAct.left;
										}
									}
									else{
										if (teki[p].vecx < 225){
											teki[p].imgposi = DotAct.upright;
										}
										else{
											teki[p].imgposi = DotAct.upleft;
										}
									}
								}
								else{
									if (teki[p].vecx > 270 && teki[p].vecx + teki[p].vecy <= 270){
										tteki[p].usef = 0;
										teki[p].vecx = (double)(192 / 90) * -1;
										teki[p].vecy = 0;
										teki[p].imgposi = DotAct.left;
									}
									if (teki[p].vecx < 45){
										teki[p].imgposi = DotAct.upright;
									}
									else{
										if (teki[p].vecx < 360){
											teki[p].imgposi = DotAct.upleft;
										}
										else{
											if (teki[p].vecx < 315){
												teki[p].imgposi = DotAct.left;
											}
										}
									}
								}
								break;
							}
						}
						break;
					case 1://赤妖精
						teki[p].x += teki[p].vecx;
						teki[p].y += teki[p].vecy;
						if (teki[p].y - teki[p].vecy == 15){
							danmaku.Setdanmaku_ChainRendan((int)(teki[p].x), (int)(teki[p].y), 3, danmaku.Getkakudo_Homing(teki[p].x, teki[p].y, j.x, j.y), danmaku.dshu.kunai, danmaku.dcolor.red, 0, 10, 4);
						}
						if ((int)((teki[p].y - 93) / 100) < (int)((teki[p].y + teki[p].vecy - 93) / 100)){
							danmaku.Setdanmaku_ChainRendan((int)(teki[p].x), (int)(teki[p].y), 3, danmaku.Getkakudo_Homing(teki[p].x, teki[p].y, j.x, j.y), danmaku.dshu.kunai, danmaku.dcolor.red, 0, 10, 4);
						}
						break;
					case 6://綿毛
						teki[p].x += teki[p].vecx;
						teki[p].y += teki[p].vecy;
						if (((Currenttime * 60 + flame) - teki[p].start) % 20 == 0 && ((Currenttime * 60 + flame) - teki[p].start) < 60){
							danmaku.Setdanmaku_Ko((int)(teki[p].x), (int)(teki[p].y), 1.5, danmaku.dshu.uroko, danmaku.dcolor.white, 0, 45, 135, 6);
						}
						break;
					}
					break;
				case 14:
					teki[p].x += teki[p].vecx;
					teki[p].y += teki[p].vecy;
					if (teki[p].vecx > 0 && teki[p].imgposi != 4){
						teki[p].imgposi = 4;
					}
					switch (teki[p].tekishu){
					case 1://赤妖精
						if (teki[p].x <= 332 && teki[p].vecx < 0){
							teki[p].start = flame;
							teki[p].vecx = 0;
							danmaku.Setdanmaku_ChainRendan((int)(teki[p].x), (int)(teki[p].y), 3, danmaku.Getkakudo_Homing(teki[p].x, teki[p].y, j.x, j.y), danmaku.dshu.mayu, danmaku.dcolor.red, 0, 7, 5);
						}
						break;
					case 2://青妖精
						if (teki[p].x <= 332 && teki[p].vecx < 0){
							teki[p].start = flame;
							teki[p].vecx = 0;
							double x = 0;
							if (teki[p].y == 33){
								x = j.x + 20;
							}
							else{
								x = j.x - 20;
							}
							danmaku.Setdanmaku_ChainRendan((int)(teki[p].x), (int)(teki[p].y), 3, danmaku.Getkakudo_Homing(teki[p].x, teki[p].y, x, j.y), danmaku.dshu.mayu, danmaku.dcolor.blue, 0, 7, 5);
						}
						break;
					case 4://緑妖精
						if (teki[p].y >= 153 && teki[p].vecx == 0){
							teki[p].ready = 40;
							teki[p].vecx = (404 - teki[p].x) / 240;
							teki[p].vecy = (303 - teki[p].y) / 240;
							danmaku.Setdanmaku_Wave((int)(teki[p].x), (int)(teki[p].y), 0.5, danmaku.dshu.big, danmaku.dcolor.green, 0, danmaku.Getkakudo_Homing(teki[p].x, teki[p].y, j.x, j.y), 30);
						}
						break;
					}
					if ((teki[p].tekishu < 4 && teki[p].vecx == 0) && flame - teki[p].start == 40) {
						teki[p].vecx = 1.2;
					}
					break;
				}

			}
			else{
				teki[p].ready--;
				if (teki[p].ready == 0){ teki[p].start = flame; }
			}
			p = teki[p].np;
		}
		if (tekicount > 0){
			if (PasteDot() != 0){ r = -1; }
		}
		if (danmaku.ProcessDanmaku(flame, scene) != 0){ r = -1; }
		if (flame % 30 == 0){ danmaku.DanmakuRefresh(); }
		if (scene == 14 && karakaze == false){
			if (flame > 510 && flame < 810) {
				eff.StartKarakazzeEffect(225, flame - 510);
			}
			if (Currenttime > 11 && flame > 30) {
				int p = danmaku.dan[0].np;
				while (p != danmaku.tail) {
					danmaku.SetKarakkazeEffect(p, 225);
					p = danmaku.dan[p].np;
				}
				karakaze = true;
			}
		}
		if (scene == 12 && (Currenttime + Begintime > 151)){
			scene++;
		}
		if (r == -1){
			r = -1;
		}
		return r;
	}
	bool Process4Boss(int flame){
		bool rr = true;
		int r = 0;
		prescene = scene;
		if (flame == 1){
			Bosstime--;
		}//一秒経過ごとに加算。
		SetDrawArea(20, 15, 404, 465);
		char * jikiname = 0;
		char * talkevent = 0;
		switch (scene){
		case 15://トーク
			int jy;
			
			talkevent = "";
			int jikicolor;

			switch (PlayerData.jikinum){
			case 0:
				jikiname = "布都";
				jikicolor = GetColor(255, 150, 150);
				jy = 215;
				break;
			case 1:
				jikiname = "魅魔";
				jikicolor = GetColor(220, 220, 100);
				jy = 210;
				break;
			case 2:
				jikiname = "早苗";
				jikicolor = GetColor(150, 150, 255);
				jy = 210;
				break;
			case 3:
				jikiname = "咲夜";
				jikicolor = GetColor(150, 200, 150);
				jy = 210;
				break;
			}
			
			if (nexttalk){
				ProcessTalk2(jikiname, jikicolor, talkevent, "明子", GetColor(200, 50, 210), akikostand, "みどり", GetColor(120, 50, 210), midoristand);
				nexttalk = false;
				if (talkevent != ""){
					
					if (strcmp(talkevent,"BGM変更") == 0){
						Talkcount = 1;
						nexttalk = true;
					}
					if (strcmp(talkevent, "終了") == 0){
						Talkcount = 0;
						nexttalk = true;
					}
					if (strcmp(talkevent,"明子＆みどり登場") == 0){
						appear = 120;
						akiko.x = 0;
						akiko.y = -20;
						midori.x = 400;
						midori.y = -20;
						akiko.vecx = 1;//X120:Y120
						akiko.vecy = 1;
						midori.vecx = -1;
						midori.vecy = 1;
					}
				}
			}
			else{
				if (appear > 0){
					akiko.x += akiko.vecx;
					akiko.y += akiko.vecy;
					midori.x += midori.vecx;
					midori.y += midori.vecy;
					DrawGraph((int)(akiko.x - 30), (int)(akiko.y - 45), akikodot[DotAct.common], true);
					DrawGraph((int)(midori.x - 30), (int)(midori.y - 45), midoridot[DotAct.common], true);
					appear -= 1;
					if (appear == 0){
						appear = -1;
						nexttalk = true;
						appear2 = 300;
						akiko.vecx = 0;
						akiko.vecy = 0;
						midori.vecx = 0;
						midori.vecy = 0;
					}
				}
				
				
			}
			DisplayTalk(jy, 225, 240);
			SetDrawBright(255, 255, 255);
			if (appear2 > 0){
				DisplayIntroBoss(160, "見た目妖怪の人間      闊達の絵師", "三東　明子  今天莉　みどり", GetColor(0, 0,0));
				
				appear2 -= 1;
			}
			break;
		case 16://通常1
			
			timetoflame = ((Currenttime - 1) % Looptime) * 60 + flame;
			switch (timetoflame){
			case 1:
				danmaku.DanmakuRefresh();
				int jkakudo;
				jkakudo = danmaku.Getkakudo_Homing(j.x, j.y, akiko.x, akiko.y);
				danmaku.Setdanmaku_ArrowRendan((int)(akiko.x), (int)(akiko.y), jkakudo + 180, danmaku.dshu.middle, danmaku.dcolor.red, 0, 20, 3, 1);
				danmaku.Setdanmaku_ArrowRendan((int)(akiko.x), (int)(akiko.y), jkakudo + 190, danmaku.dshu.middle, danmaku.dcolor.purple, 0, 20, 3, 1);
				danmaku.Setdanmaku_ArrowRendan((int)(akiko.x), (int)(akiko.y), jkakudo + 170, danmaku.dshu.middle, danmaku.dcolor.purple, 0, 20, 3, 1);
				jkakudo = danmaku.Getkakudo_Homing(j.x, j.y,midori.x, midori.y);
				danmaku.Setdanmaku_ArrowRendan((int)(midori.x), (int)(midori.y), jkakudo + 180, danmaku.dshu.middle, danmaku.dcolor.green, 0, 20, 3, 1);
				danmaku.Setdanmaku_ArrowRendan((int)(midori.x), (int)(midori.y), jkakudo + 190, danmaku.dshu.middle, danmaku.dcolor.water, 0, 20, 3, 1);
				danmaku.Setdanmaku_ArrowRendan((int)(midori.x), (int)(midori.y), jkakudo + 170, danmaku.dshu.middle, danmaku.dcolor.water, 0, 20, 3, 1);
				break;
			case 30:
				danmaku.Setdanmaku_Wave((int)(midori.x), (int)(midori.y), 2, danmaku.dshu.big, danmaku.dcolor.yellow, 0, danmaku.Getkakudo_Homing(midori.x,midori.y,j.x,j.y), 24);
				danmaku.Setdanmaku_Wave((int)(akiko.x), (int)(akiko.y), 2, danmaku.dshu.big, danmaku.dcolor.yellow, 0, 0, 24);
				break;
			case 90:
				danmaku.Setdanmaku_ChainRendan((int)(akiko.x), (int)(akiko.y), 1, 90, danmaku.dshu.big, danmaku.dcolor.red, 0, 1, 1);
				break;
			case 240:
				danmaku.Setdanmaku_Wave((int)(akiko.x), (int)(akiko.y), 2, danmaku.dshu.ring, danmaku.dcolor.red, 0, danmaku.Getkakudo_Homing(akiko.x,akiko.y, j.x, j.y), 10);
				danmaku.Setdanmaku_Wave((int)(midori.x), (int)(midori.y), 2, danmaku.dshu.ring, danmaku.dcolor.red, 0, danmaku.Getkakudo_Homing(midori.x, midori.y, j.x, j.y), 10);
				break;
			case 300:
				if (akiko.x < 212){
					akiko.vecx = 4;
					midori.vecx = -4;
				}
				else{
					akiko.vecx = -4;
					midori.vecx = 4;
				}
				break;
			case 360:
				danmaku.Setdanmaku_Wave((int)(midori.x), (int)(midori.y), 2, danmaku.dshu.big, danmaku.dcolor.yellow, 0, danmaku.Getkakudo_Homing(midori.x, midori.y, j.x, j.y), 24);
				danmaku.Setdanmaku_Wave((int)(akiko.x), (int)(akiko.y), 2, danmaku.dshu.big, danmaku.dcolor.yellow, 0, 0, 24);
				break;
			case 450:
				danmaku.Setdanmaku_ChainRendan((int)(akiko.x), (int)(akiko.y), 1, 90, danmaku.dshu.big, danmaku.dcolor.red, 0, 1, 1);
				break;
			case 600:
				danmaku.Setdanmaku_Wave((int)(akiko.x), (int)(akiko.y), 2, danmaku.dshu.ring, danmaku.dcolor.red, 0, 0, 10);
				danmaku.Setdanmaku_Wave((int)(midori.x), (int)(midori.y), 2, danmaku.dshu.ring, danmaku.dcolor.red, 0, 0, 10);
				break;
			case 620:
				danmaku.Setdanmaku_Wave((int)(akiko.x), (int)(akiko.y), 2, danmaku.dshu.ring, danmaku.dcolor.red, 0, 0, 10);
				danmaku.Setdanmaku_Wave((int)(midori.x), (int)(midori.y), 2, danmaku.dshu.ring, danmaku.dcolor.red, 0, 0, 10);
				break;
			}
			if ((timetoflame > 89 && timetoflame < 240) || (timetoflame > 449 && timetoflame < 576)){
				if ((timetoflame - 90) / 25 == 0){
					danmaku.Setdanmaku_ArrowRendan((int)(midori.x), (int)(midori.y), danmaku.Getkakudo_Homing(j.x, j.y,midori.x, midori.y) + 180, danmaku.dshu.mayu, danmaku.dcolor.blue, 0, 15, 2.4, 1);
				}
				
			}
			int p;
			p = danmaku.dan[0].np;
			while (p < danmaku.tail) {
				int before, after;
				before = (int)(danmaku.dan[p].y) / 90;
				after = (int)(danmaku.dan[p].y + danmaku.dan[p].vecy) / 90;
				if (danmaku.dan[p].danshu == danmaku.dshu.big && danmaku.dan[p].color == danmaku.dcolor.red && after < before){
					danmaku.SetDanmakuSE(7, 0, 0);
					danmaku.Setdanmaku_Wave((int)(danmaku.dan[p].x), (int)(danmaku.dan[p].y), 2, danmaku.dshu.uroko, danmaku.dcolor.red, 0, danmaku.Getkakudo_Homing(danmaku.dan[p].x, j.y, j.x, danmaku.dan[p].y), 15);
				}
				p = danmaku.dan[p].np;
			}
			if ((timetoflame > 299 && timetoflame < 341)){
				akiko.x += akiko.vecx;
				midori.x += midori.vecx;
			}
			if (timetoflame > 449 && timetoflame < 600 && (timetoflame - 450) / 25 == 0){

			}
			break;
		case 17://スペルカード1 巡礼「同人誌即売会 - 祭 - 」
			if (Currenttime > 10) {
				Bosshit = true;
			}
			else {
				Bosshit = false;
			}
			if (Currenttime < 3) {
				
				akiko.x += akiko.vecx;
				akiko.y += akiko.vecy;
				midori.x += midori.vecx;
				midori.y += midori.vecy;
				if ((akiko.y > 79 && akiko.vecy > 0) || (akiko.y < 81 && akiko.vecy < 0)) {
					akiko.vecy = 0;
				}
				if ((akiko.x > 79 && akiko.vecx > 0) || (akiko.x < 81 && akiko.vecx < 0)) {
					akiko.vecx = 0;
				}
				if ((midori.y > 242 && midori.vecy > 0) || (midori.y < 244 && midori.vecy < 0)) {
					midori.vecy = 0;
				}
				if ((midori.x > 211 && midori.vecx > 0) || (midori.x < 213 && midori.vecx < 0)) {
					midori.vecx = 0;
				}
				appeary += 2;
				StartSpellkardEffect(akikostand[StandAct.common],midoristand[StandAct.common],182,(int)(appeary) + 70);
			}
			else {
				timetoflame = ((Currenttime - 3) % Looptime) * 60 + flame;
				switch (timetoflame) {
				case 1:
					danmaku.DanmakuRefresh();
					akiko.vecx = (332 - 80) / 120;
					akiko.vecy = 0;
					midori.vecx = 0;
					midori.vecy = (81 - 243) / 60;
					break;
				case 61:
					midori.vecy *= -1;
					break;
				case 121:
					akiko.vecx = 0;
					akiko.vecy = (407 - 80) / 120;
					midori.vecx = (316 - 212) / 60; 
					midori.vecy = 0;
					break;
				case 181:
					midori.vecx *= -1;
					break;
				case 241:
					akiko.vecx = (80 - 332) / 120;
					akiko.vecy = 0;
					midori.vecx = 0;
					midori.vecy = (90 - 243) / 60 * -1;
					break;
				case 301:
					midori.vecy *= -1;
					break;
				case 361:
					akiko.vecx = 0;
					akiko.vecy = (80 - 407) / 120;
					midori.vecx = (332 - 212) / 60 * -1;
					midori.vecy = 0;
					break;
				case 421:
					akiko.vecx = (80 - akiko.x) / 40;
					akiko.vecy = (80 - akiko.y) / 40;
					midori.vecx = (212 - midori.x) / 40;
					midori.vecy = (243 - midori.y) / 40;
					break;
				case 461:
					akiko.vecx = 0;
					akiko.vecy = 0;
					midori.vecx = 0;
					midori.vecy = 0;
				case 481:
					danmaku.DanmakuRefresh();
					akiko.vecx = (332 - 80) / 120;
					akiko.vecy = 0;
					midori.vecx = 0;
					midori.vecy = (81 - 243) / 60;
					break;
				case 541:
					midori.vecy *= -1;
					break;
				case 601:
					akiko.vecx = 0;
					akiko.vecy = (407 - 80) / 120;
					midori.vecx = (316 - 212) / 60;
					midori.vecy = 0;
					break;
				case 661:
					midori.vecx *= -1;
					break;
				case 721:
					akiko.vecx = (80 - 332) / 120;
					akiko.vecy = 0;
					midori.vecx = 0;
					midori.vecy = (90 - 243) / 60 * -1;
					break;
				case 781:
					midori.vecy *= -1;
					break;
				case 841:
					akiko.vecx = 0;
					akiko.vecy = (80 - 407) / 120;
					midori.vecx = (332 - 212) / 60 * -1;
					midori.vecy = 0;
					break;
				case 901:
					midori.vecx *= -1;
					break;
				}
				akiko.x += akiko.vecx;
				akiko.y += akiko.vecy;
				midori.x += midori.vecx;
				midori.y += midori.vecy;
				if (timetoflame > -1 && timetoflame < 481) {
					if (timetoflame % 20 == 0) {
						danmaku.Setdanmaku_ChainRendan((int)(akiko.x), (int)(akiko.y), 1.5, danmaku.Getkakudo_Homing(akiko.x, akiko.y, 212, 243), danmaku.dshu.ring, danmaku.dcolor.yellow, 0, 4, 2);
					}
					if (timetoflame % 30 == 0) {
						int k;
						int c;
						if ((timetoflame - 1) % 120 == 0) {
							k = danmaku.Getkakudo_Homing(midori.x, midori.y, j.x, j.y);
							c = danmaku.dcolor.pink;
						}
						else {
							k = 0;
							c = danmaku.dcolor.purple;
						}
						danmaku.Setdanmaku_Wave((int)(midori.x), (int)(midori.y), 2, danmaku.dshu.uroko, c, 0, k, 12);
					}
					
				}
				else {
					if (timetoflame % 10 == 0) {					
						for (int ew = 15; ew < 461; ew += 60) {
							danmaku.SetDanmakuSE(1, 0, 0);
							danmaku.Setdanmaku_ChainRendan(20, ew, 2, 0, danmaku.dshu.middle, danmaku.dcolor.orange, 0, 1, 1);
							danmaku.SetDanmakuSE(1, 0, 0);
							danmaku.Setdanmaku_ChainRendan(384, ew + 30, 2, 180, danmaku.dshu.middle, danmaku.dcolor.blue, 0, 1, 1);
						}
					}
					if (timetoflame % 60 == 0) {
						danmaku.Setdanmaku_Wave((int)(akiko.x), (int)(akiko.y), 2, danmaku.dshu.ring, danmaku.dcolor.red, 0, 10, 8);
						danmaku.Setdanmaku_Wave((int)(midori.x), (int)(midori.y), 2, danmaku.dshu.ring, danmaku.dcolor.red, 0, 0, 8);
					}
				}
			}
			break;
		case 18://通常2
			if (Currenttime < 8) {
				Bosshit = false;
			}
			else {
				Bosshit = true;
			}
			if (Currenttime < 3) {
				EndSpellkardEffect(500000, SpellBonusScore);
				akiko.x += akiko.vecx;
				akiko.y += akiko.vecy;
				midori.x += midori.vecx;
				midori.y += midori.vecy;
				if ((akiko.vecx < 0 && akiko.x + akiko.vecx < 62) || (akiko.vecx > 0 && akiko.x + akiko.vecx > 62) ){
					midori.vecx = 0;
					midori.vecy = 0;
					akiko.vecx = 0;
					akiko.vecy = 0;
				}
			}
			else
			{
				akiko.x += akiko.vecx;
				akiko.y += akiko.vecy;
				midori.x += midori.vecx;
				midori.y += midori.vecy;
				timetoflame =((Currenttime - 3) % Looptime) * 60 + flame;
				switch (timetoflame) {
				case 1:
					akiko.vecx = 0;
					midori.vecx = 0;
					akiko.vecy = 0;
					midori.vecy = 0;
					break;
				case 241:
					akiko.vecx = (362 - akiko.x) / 60;
					midori.vecx = (62 - midori.x) / 60;
					break;
				case 300:
					akiko.vecx = 0;
					midori.vecx = 0;
					break;
				case 451:
					akiko.vecx = (212 - akiko.x) / 40;
					midori.vecx = (212 - midori.x) / 40;
					akiko.vecy = (325 - akiko.y) / 40;
					midori.vecy = (65 - midori.y) / 40;
					break;
				case 491:
					akiko.vecx = 0;
					midori.vecx = 0;
					akiko.vecy = 0;
					midori.vecy = 0;
					break;
				case 601:
					akiko.vecx = (double)(62 - akiko.x) / 50;
					akiko.vecy = (double)(120 - akiko.y) / 50;
					midori.vecx = (double)(362 - midori.x) / 50;
					midori.vecy = (double)(250 - midori.y) / 50;
					break;
				case 651:
					akiko.vecx = 0;
					midori.vecx = 0;
					akiko.vecy = 0;
					midori.vecy = 0;
					break;
				}
				if (timetoflame < 241) {
					if (timetoflame % 50 == 0) {
						int mod = (int)(timetoflame / 50);
						int k = 0;
						switch (mod) {						
						case 1:
							k = 4;
							break;
						case 2: 
							k = 7;
							break;
						case 3:
							k = 0;
							break;
						case 4:
							k = danmaku.Getkakudo_Homing(akiko.x,akiko.y,j.x,j.y);
							break;
						}
						danmaku.Setdanmaku_Wave((int)(akiko.x), (int)(akiko.y), 1.5, danmaku.dshu.mayu, danmaku.dcolor.red, 0, k, 30);
					}
					if (timetoflame % 40 == 0) {
						int mod = (int)(timetoflame / 40);
						int two = 0;
						switch (mod) {
						case 1:
							kakudo = danmaku.Getkakudo_Homing(midori.x, midori.y, j.x, j.y);
							break;
						case 2:
							two = 30;
							break;
						case 3:
							two = 60;
							break;
						case 4:
							kakudo = danmaku.Getkakudo_Homing(midori.x, midori.y, j.x, j.y);
							two = 15;
							break;
						case 5:
							break;
						}
						if (two == 0) {
							danmaku.Setdanmaku_ArrowRendan((int)(midori.x), (int)(midori.y), kakudo, danmaku.dshu.kunai, danmaku.dcolor.water, 0, 10, 2, 1.1);
						}
						else {
							danmaku.Setdanmaku_ArrowRendan((int)(midori.x), (int)(midori.y), kakudo + two, danmaku.dshu.kunai, danmaku.dcolor.water, 0, 10, 2, 1.1);
							danmaku.Setdanmaku_ArrowRendan((int)(midori.x), (int)(midori.y), kakudo - two, danmaku.dshu.kunai, danmaku.dcolor.water, 0, 10, 2, 1.1);
						}
					}
				}
				else {
					int count = 0;
					if (timetoflame < 451) {
						if (timetoflame > 300) {
							if (timetoflame % 40 == 0) {
								if (timetoflame / 40 == 11) {
									danmaku.Setdanmaku_Ko((int)(akiko.x), (int)(akiko.y), 4, danmaku.dshu.big, danmaku.dcolor.purple, 0, 45, 225, 15);
								}
								else {
									danmaku.Setdanmaku_Ko((int)(akiko.x), (int)(akiko.y), 2, danmaku.dshu.middle, danmaku.dcolor.red, 0, 45, 225, 15);
								}
							}
							int p;
							switch(timetoflame) {
							case 360:
								danmaku.Setdanmaku_Ko((int)(midori.x), (int)(midori.y), 1, danmaku.dshu.ring, danmaku.dcolor.water, 0, 30, 150, 13);
								break;
							case 390:
								p = danmaku.dan[0].np;
								count = 1;
								while(count < 14 && p < tail){
									if (danmaku.dan[p].danshu == danmaku.dshu.ring && danmaku.dan[p].color == danmaku.dcolor.water) {
										danmaku.ddan[p].ready = count * 10;
										count++;
									}
									p = danmaku.dan[p].np;
								}
								break;
							case 420:
								danmaku.Setdanmaku_Ko((int)(midori.x), (int)(midori.y), 1, danmaku.dshu.ring, danmaku.dcolor.water, 0, 30, 150, 13);
								break;
							case 450:
								p = danmaku.dan[0].np;
								count = 1;
								int loop = 0;
								while (count < 14 && p < tail && loop < DANMAKULIMIT) {
									if (danmaku.dan[p].danshu == danmaku.dshu.ring && danmaku.dan[p].color == danmaku.dcolor.water) {
										danmaku.ddan[p].ready = count * 10;
										count++;
									}
									loop++;
									p = danmaku.dan[p].np;
								}
								break;
							}
						}
					}
					else {

					}
				}
			}
			break;
		case 19://スペルカード2　欲愛「エニワンミーツエニワン」
			if (Currenttime > 10) {
				Bosshit = true;
			}
			else {
				Bosshit = false;
			}
			if (Currenttime < 3) {
				akiko.x += akiko.vecx;
				akiko.y += akiko.vecy;
				midori.x += midori.vecx;
				midori.y += midori.vecy;
				if ((akiko.y + akiko.vecy > 250 && akiko.vecy > 0) || (akiko.y + akiko.vecy < 250 && akiko.vecy < 0)) {
					akiko.vecy = 0;
				}
				if ((akiko.x + akiko.vecx > 122 && akiko.vecx > 0) || (akiko.x + akiko.vecx < 122 && akiko.vecx < 0)) {
					akiko.vecx = 0;
				}
				if ((midori.y + midori.vecy > 250 && midori.vecy > 0) || (midori.y + midori.vecy < 250 && midori.vecy < 0)) {
					midori.vecy = 0;
				}
				if ((midori.x + midori.vecx > 302 && midori.vecx > 0) || (midori.x + midori.vecx < 302 && midori.vecx < 0)) {
					midori.vecx = 0;
				}
				appeary += 2;
				StartSpellkardEffect(akikostand[StandAct.strategy], midoristand[StandAct.strategy], 182, (int)(appeary)+70);
			}		
			else {
				timetoflame = ((Currenttime - 3) % Looptime) * 60 + flame;
				if (timetoflame % 25 == 0) {
					danmaku.SetDanmakuSE(7, 0, 0);
					danmaku.Setdanmaku_Wave((int)(akiko.x), (int)(akiko.y), 1, danmaku.dshu.middle, danmaku.dcolor.red, 0, kkakudo[1], 7);
					danmaku.SetDanmakuSE(7, 0, 0);
					danmaku.Setdanmaku_Wave((int)(midori.x), (int)(midori.y), 1, danmaku.dshu.middle, danmaku.dcolor.red, 0, kkakudo[0], 6);
				}
				switch (timetoflame) {
				case 200:
					danmaku.Setdanmaku_Wave(212, 250, 1.5, danmaku.dshu.heart, danmaku.dcolor.pink, 0, 0, 20, danmaku.worder.round, -0.2);
					break;
				case 240:
					danmaku.Setdanmaku_Wave(212, 250, 1.5, danmaku.dshu.heart, danmaku.dcolor.pink, 0, 0, 20, danmaku.worder.round, 0.2);
					break;
				case 260:
					danmaku.Setdanmaku_Wave(212, 250, 1.5, danmaku.dshu.heart, danmaku.dcolor.pink, 0, 0, 20, danmaku.worder.round, -0.2);
					break;
				case 400:
					danmaku.Setdanmaku_Wave(212, 250, 1.5, danmaku.dshu.heart, danmaku.dcolor.pink, 0, 0, 20, danmaku.worder.round, -0.2);
					break;
				case 440:
					danmaku.Setdanmaku_Wave(212, 250, 1.5, danmaku.dshu.heart, danmaku.dcolor.pink, 0, 0, 20, danmaku.worder.round, 0.2);
					break;
				case 460:
					danmaku.Setdanmaku_Wave(212, 250, 1.5, danmaku.dshu.heart, danmaku.dcolor.pink, 0, 0, 20, danmaku.worder.round, -0.2);
					break;
				case 600:
					danmaku.Setdanmaku_Wave(212, 250, 2, danmaku.dshu.heart, danmaku.dcolor.pink, 0, 0, 10, danmaku.worder.crossround, 0.5);
					break;
				case 640:
					danmaku.Setdanmaku_Wave(212, 250, 2, danmaku.dshu.heart, danmaku.dcolor.pink, 0, 0, 10, danmaku.worder.crossround, -0.5);
					break;
				case 660:
					danmaku.Setdanmaku_Wave(212, 250, 2, danmaku.dshu.heart, danmaku.dcolor.pink, 0, 0, 10, danmaku.worder.crossround, 0.5);
					break;
				case 800:
					danmaku.Setdanmaku_Wave(212, 250, 2, danmaku.dshu.heart, danmaku.dcolor.pink, 0, 0, 10, danmaku.worder.crossround, -0.5);
					break;
				case 840:
					danmaku.Setdanmaku_Wave(212, 250, 2, danmaku.dshu.heart, danmaku.dcolor.pink, 0, 0, 10, danmaku.worder.crossround, 0.5);
					break;
				case 860:
					danmaku.Setdanmaku_Wave(212, 250, 2, danmaku.dshu.heart, danmaku.dcolor.pink, 0, 0, 10, danmaku.worder.crossround, -0.5);
					break;
				}
				if ((timetoflame / 150) % 2 == 0) {// X^2 = Y^2 + r^2 Y = √(r^2 - X^2) r = 75
					int r;
					r = (int)(sqrt(5625 - pow((timetoflame % 150 - 75), 2.0)));					
					kkakudo[1] += r;
					kkakudo[0] -= r;
				}
				else {
					kkakudo[1] = 0;
					kkakudo[0] = 0;
				}
			}
			break;
		case 20://スペルカード3　煩符「パラノイア解放」
			if (Currenttime > 12) {
				Bosshit = true;
			}
			else {
				Bosshit = false;
			}
			if (Currenttime < 6) {
				if (Currenttime < 3) {
					EndSpellkardEffect(500000, SpellBonusScore);
					
				}
				else {
					if (Currenttime == 3 && flame == 2) {
						eff.RequestSE(eff.se.spell);
						Spell = true;
						SpellBonusScore = 2000000;
						decreasebonusperflame = SpellBonusScore / (Bosstime * 60);
					}
					akiko.x += akiko.vecx;
					akiko.y += akiko.vecy;
					midori.x += midori.vecx;
					midori.y += midori.vecy;
					if ((akiko.y + akiko.vecy > 150 && akiko.vecy > 0) || (akiko.y + akiko.vecy < 150 && akiko.vecy < 0)) {
						akiko.vecy = 0;
					}
					if ((akiko.x + akiko.vecx > 212 && akiko.vecx > 0) || (akiko.x + akiko.vecx < 212 && akiko.vecx < 0)) {
						akiko.vecx = 0;
					}
					if ((midori.y + midori.vecy > 80 && midori.vecy > 0) || (midori.y + midori.vecy < 80 && midori.vecy < 0)) {
						midori.vecy = 0;
					}
					if ((midori.x + midori.vecx > 212 && midori.vecx > 0) || (midori.x + midori.vecx < 212 && midori.vecx < 0)) {
						midori.vecx = 0;
					}
					if (Currenttime < 6) {
						appearx += 2;
					}
					StartSpellkardEffect(akikostand[StandAct.excited], midoristand[StandAct.excited], (int)(370 - appearx), 182);
				}
			}
			else {
				akiko.x += akiko.vecx;
				akiko.y += akiko.vecy;
				timetoflame = ((Currenttime - 7) % Looptime) * 60 + flame;
				switch (timetoflame) {
				case 1:
					danmaku.DanmakuRefresh();
					if (akiko.x > j.x) {
						akiko.vecx = (92 - 212) / 30;
					}
					else {
						akiko.vecx = (332 - 212) / 30;
					}
					akiko.vecy = (240 - 150) / 30;
					break;
				case 31:
					akiko.vecx = 0;
					akiko.vecy = 0;
					break;
				case 261:
					akiko.vecx = (212 - akiko.x) / 40;
					akiko.vecy = (150 - akiko.y) / 40;
					break;
				case 301:
					akiko.vecx = 0;
					akiko.vecy = 0;
					break;
				}
				if (timetoflame > 0 && timetoflame < 41) {
					if ((timetoflame - 1) % 6 == 0) {
						danmaku.Setdanmaku_ArrowRendan((int)(akiko.x), (int)(akiko.y), danmaku.Getkakudo_Homing(akiko.x, akiko.y, j.x, j.y), danmaku.dshu.plate, danmaku.dcolor.white, 0, 3, 2, 1.1);
					}
					if ((timetoflame - 1) % 10 == 0) {
						danmaku.Setdanmaku_Wave((int)(midori.x), (int)(midori.y), 3, danmaku.dshu.mayu, danmaku.dcolor.white, 0, danmaku.Getkakudo_Homing(midori.x, midori.y, j.x, j.y), 40);
					}
					
				}
				if (timetoflame > 40 && timetoflame < 221) {
					if ((timetoflame - 40) % 12 == 0) {
						int pos = 1;
						int start = 180;
						if (akiko.x < 212) {
							pos = -1;
							start = 0;
						}
						int roundkakudo = (timetoflame - 40) / 12 * 18 * pos + start;
						if (roundkakudo > 360) {
							roundkakudo -= 360;
						}
						if (roundkakudo < 0) {
							roundkakudo += 360;
						}
						danmaku.Setdanmaku_ChainRendan((int)(akiko.x), (int)(akiko.y), 2, roundkakudo, danmaku.dshu.plate, danmaku.dcolor.white, 0, 1, 0);
					}
					int mmk = -30;
					int mf = 4;
					if (timetoflame > 100 && timetoflame < 161) {
						mmk = 210;
						mf = -4;
						mmk -= (timetoflame - 100) * 4;
					}
					else {
						mmk += (timetoflame - 100) * 4;
					}
					for (int mk = mmk; mk < mmk + 5 * mf; (mf == 4) ? mk += 4 : mk -= 4) {
						danmaku.Setdanmaku_ChainRendan((int)(midori.x + 20 * cos(mk) * PI / 180), (int)(midori.y + 20 * sin(mk) * PI / 180), 1, GetRand(360), danmaku.dshu.kome, danmaku.dcolor.white, 18, 1, 0);
					}
					
				}
			}
			break;
		//後半ボス分岐は各ボスのProcessAkiko,ProcessMidoriにて処理
		}
		danmaku.ProcessBossDanmaku(flame + Currenttime * 60, scene, PlayerData.jikinum, (int)(j.x), (int)(j.y));

		if (BossTalk == false){ r = DisplayBossStates(yonboss.hitpoint, yonboss.phasecount); }
		if (Spell){
			DisplaySpellStates();
		}
		if (scene != 15 || (scene == 15 && appear == -1)){
			DrawGraph((int)(akiko.x - 30), (int)(akiko.y - 45), akikodot[akiko.imgpoji], true);
			DrawGraph((int)(midori.x - 30), (int)(midori.y - 45), midoridot[midori.imgpoji], true);
		}
		return rr;
	}
	bool ProcessAkiko(int flame){
		bool rr = true;
		prescene = scene;
		if (flame == 1){
			Bosstime--;
		}//一秒経過ごとに加算。
		SetDrawArea(20, 15, 404, 465);
		char * jikiname = 0;
		char * talkevent = 0;
		int jy;
		int jikicolor;
		switch (scene){
		case 21://分岐トーク	
			if (Currenttime > 2) {
				talkevent = "";
				switch (PlayerData.jikinum) {
				case 0:
					jikiname = "布都";
					jikicolor = GetColor(255, 150, 150);
					jy = 215;
					break;
				case 1:
					jikiname = "魅魔";
					jikicolor = GetColor(220, 220, 100);
					jy = 210;
					break;
				case 2:
					jikiname = "早苗";
					jikicolor = GetColor(150, 150, 255);
					jy = 210;
					break;
				case 3:
					jikiname = "咲夜";
					jikicolor = GetColor(150, 200, 150);
					jy = 210;
					break;
				}
				if (nexttalk) {
					ProcessTalk2(jikiname, jikicolor, talkevent, "明子", GetColor(200, 50, 210), akikostand, "みどり", GetColor(120, 50, 210), midoristand);
					nexttalk = false;
					if (talkevent != "") {
						if (strcmp(talkevent, "終了") == 0) {
							appear = 100;
							midori.vecx = (400 - midori.x) / 100;
							midori.vecy = (0 - midori.x) / 100;
						}
					}
				}
				else {
					if (appear > 0) {
						midori.x += midori.vecx;
						midori.y += midori.vecy;
						appear -= 1;
						if (appear == 0) {
							appear = -1;
							Talkcount = 0;
							nexttalk = true;
						}
					}
				}
			}
			DrawGraph((int)(akiko.x - 30), (int)(akiko.y - 45), akikodot[DotAct.common], true);
			DrawGraph((int)(midori.x - 30), (int)(midori.y - 45), midoridot[DotAct.common], true);
			if (Currenttime < 3) {
				EndSpellkardEffect(1000000, SpellBonusScore);
				if (Currenttime == 2 && flame == 59) {
					nexttalk = true;
				}
			}
			else {
				DisplayTalk(jy, 225, 240);
				
			}
			SetDrawBright(255, 255, 255);
			break;
		case 22://後半戦　トーク			
			talkevent = "";		
			switch (PlayerData.jikinum) {
			case 0:
				jikiname = "布都";
				jikicolor = GetColor(255, 150, 150);
				jy = 215;
				break;
			case 1:
				jikiname = "魅魔";
				jikicolor = GetColor(220, 220, 100);
				jy = 210;
				break;
			case 2:
				jikiname = "早苗";
				jikicolor = GetColor(150, 150, 255);
				jy = 210;
				break;
			case 3:
				jikiname = "咲夜";
				jikicolor = GetColor(150, 200, 150);
				jy = 210;
				break;
			}
			if (Currenttime == 1 && flame == 1) {
				ProcessTalk(jikiname, jikicolor, talkevent, jy, 225, "明子2", akiko2stand, GetColor(200, 200, 150));
			}			
			if (nexttalk) {
				ProcessTalk(jikiname, jikicolor, talkevent , jy,225 , "明子2", akiko2stand, GetColor(200, 200, 150));
				nexttalk = false;
				if (talkevent != "") {
					if (strcmp(talkevent, "終了") == 0) {
						Talkcount = 0;
					}
					if (strcmp(talkevent, "明子、バンダナを外し、本性を現す。同時にBGMも変化") == 0) {
						appear = 120;
						akiko.vecx = (212 - akiko.x) / 40;
						akiko.vecy = (100 - akiko.y) / 40;
					}

				}
			}
			DrawGraph((int)(akiko.x - 30), (int)(akiko.y - 45), akikodot[akiko.imgpoji], true);
			if (appear < 0) {
				DisplayTalk(jy, 225);
			}
			else {
				if (appear == 60) {
					ProcessTalk(jikiname, jikicolor, talkevent, jy, 225, "明子2", akiko2stand, GetColor(200, 200, 150));
					BossName = "Mitou Akiko";
					akiko.imgpoji = DotAct.common + 2;
				}
				if (appear > 79) {
					akiko.x += akiko.vecx;
					akiko.y += akiko.vecy;
				}
				if (appear < 61) {
					DisplayTalk(jy, 225);
					SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255 * appear / 60);
					DrawBox(20, 15, 403, 464, GetColor(255, 100, 220), true);
					SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
				}
				else {
					DisplayTalk(jy, 225);
					SetDrawBlendMode(DX_BLENDMODE_ALPHA, (int)(255 / (appear - 60)));
					DrawBox(20, 15, 403, 464, GetColor(255, 100, 220), true);
					SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
				}
				appear--;
				if (appear == 0) {
					appear = -2;
					Talkcount = 1;
				}
			}
			SetDrawBright(255, 255, 255);
			break;
		case 23://通常1
			if (Currenttime < 2) {
				Bosshit = false;
			}
			else {
				Bosshit = true;
			}
			timetoflame = (Currenttime % Looptime) * 60 + flame;
			int p;
			if (timetoflame > 100) {
				if (timetoflame < 200) {
					p = timetoflame - 100;
				}
				else {
					p = timetoflame - 200;
				}
			}
			else {
				p = timetoflame;
			}
			if (p % 10 == 0) {
				danmaku.Setdanmaku_ChainRendan(GetRand(330) + 30, 50, 3, GetRand(60) + 60, danmaku.dshu.plate, danmaku.dcolor.white, 60, 1, 0);
			}
			if (timetoflame % 60 == 0) {
				if ((timetoflame % 60) % 2 == 0) {
					danmaku.Setdanmaku_Wave((int)(akiko.x), (int)(akiko.y), 2, danmaku.dshu.uroko, danmaku.dcolor.red, 0, 1, 30);
				}
				else {
					danmaku.Setdanmaku_Wave((int)(akiko.x), (int)(akiko.y), 2, danmaku.dshu.uroko, danmaku.dcolor.red, 0, danmaku.Getkakudo_Homing(akiko.x, akiko.y, j.x, j.y), 30);
				}
			}
			if (timetoflame > 359 && timetoflame < 561) {
				if (timetoflame % 40 == 0) {
					if ((timetoflame / 40) % 2 == 0) {
						danmaku.Setdanmaku_Wave((int)(akiko.x), (int)(akiko.y), 3, danmaku.dshu.plate, danmaku.dcolor.pink, 0, 0, 10, danmaku.worder.round, -1);
					}
					else {
						danmaku.Setdanmaku_Wave((int)(akiko.x), (int)(akiko.y), 3, danmaku.dshu.plate, danmaku.dcolor.purple, 0, 0, 10, danmaku.worder.round, 1);
					}
				}
			}
			break;
		case 24://スペルカード1　平符「ディペンディングプレート」
			if (Currenttime > 10) {
				Bosshit = true;
			}
			else {
				Bosshit = false;
			}
			if (Currenttime < 3) {
				appeary += 2;
				StartSpellkardEffect(akiko2stand[StandAct.strategy]);
			}
			else {
				bool bp = true;
				int d = danmaku.dan[0].np;
				while (d != danmaku.tail) {
					if (danmaku.dan[d].danshu == danmaku.dshu.bigplate) {
						bp = false;
						break;
					}
					d = danmaku.dan[d].np;
				}
				if (bp) {
					danmaku.Setdanmaku_ChainRendan((int)(akiko.x), (int)(akiko.y), 2, 135, danmaku.dshu.bigplate, danmaku.dcolor.white, 0, 1, 1);
					danmaku.Setdanmaku_ChainRendan((int)(akiko.x), (int)(akiko.y), 3, 45, danmaku.dshu.bigplate, danmaku.dcolor.white, 0, 1, 1);
				}
				if ((Currenttime * 60 + flame) % 50 == 0) {
					danmaku.Setdanmaku_Wave((int)(akiko.x), (int)(akiko.y), 3, danmaku.dshu.ring, danmaku.dcolor.yellow, 0, 1, 24);
				}

			}
			break;
		case 25://通常2
			if (Currenttime < 8) {
				Bosshit = false;
			}
			else {
				Bosshit = true;
			}
			if (Currenttime < 3) {
				EndSpellkardEffect(500000, SpellBonusScore);
				akiko.x += akiko.vecx;
				akiko.y += akiko.vecy;
				if (akiko.x + akiko.vecx < 62) {
					akiko.vecx = 0;
					akiko.vecy = 0;
					akiko.x = 60;
				}
			}
			else {
				akiko.x += akiko.vecx;
				timetoflame = ((Currenttime - 3) % Looptime) * 60 + flame;
				switch (timetoflame) {
				case 1:
					danmaku.ClearDaen();
					break;
				case 180:
					for (int d = 80; d < 381; d += 60) {
						danmaku.Setdanmaku_ArrowRendan(20, d, 40, danmaku.dshu.ring, danmaku.dcolor.red, 0, 10, 5, 3);
						danmaku.Setdanmaku_ArrowRendan(404, d, 140, danmaku.dshu.ring, danmaku.dcolor.red, 0, 10, 5, 3);
					}
					break;
				case 240:
					akiko.vecx = (360 - akiko.x) / 60;
					danmaku.Setdanmaku_Wave((int)(akiko.x), (int)(akiko.y), 1, danmaku.dshu.middle, danmaku.dcolor.white, 0, 1, 20);
					danmaku.Setdanmaku_Wave((int)(akiko.x), (int)(akiko.y), 1.5, danmaku.dshu.mayu, danmaku.dcolor.white, 0, danmaku.Getkakudo_Homing(akiko.x, akiko.y, j.x, j.y), 15);
					danmaku.Setdanmaku_Wave((int)(akiko.x), (int)(akiko.y), 0.5, danmaku.dshu.uroko, danmaku.dcolor.white, 0, danmaku.Getkakudo_Homing(akiko.x, akiko.y, j.x, j.y) + 21, 36);
					break;
				case 300:
					akiko.vecx = 0;
					break;
				case 480:
					for (int d = 80; d < 381; d += 60) {
						danmaku.Setdanmaku_ArrowRendan(20, d, 40, danmaku.dshu.ring, danmaku.dcolor.red, 0, 10, 5, 3);
						danmaku.Setdanmaku_ArrowRendan(404, d, 140, danmaku.dshu.ring, danmaku.dcolor.red, 0, 10, 5, 3);
					}
					break;
				case 540:
					akiko.vecx = (60 - akiko.x) / 60;
					danmaku.Setdanmaku_Wave((int)(akiko.x), (int)(akiko.y), 1, danmaku.dshu.middle, danmaku.dcolor.white, 0, 1, 20);
					danmaku.Setdanmaku_Wave((int)(akiko.x), (int)(akiko.y), 1.5, danmaku.dshu.mayu, danmaku.dcolor.white, 0, danmaku.Getkakudo_Homing(akiko.x, akiko.y, j.x, j.y), 15);
					danmaku.Setdanmaku_Wave((int)(akiko.x), (int)(akiko.y), 0.5, danmaku.dshu.uroko, danmaku.dcolor.white, 0, danmaku.Getkakudo_Homing(akiko.x, akiko.y, j.x, j.y) + 21, 36);
					break;
				case 600:
					akiko.vecx = 0;
					break;
				}
				if (timetoflame < 142) {
					if ((timetoflame - 1) % 10 == 0) {
						double k = 281 + (timetoflame - 1) / 10 * 17.5;
						if (k > 360) {
							k -= 360;
						}
						danmaku.Setdanmaku_ChainRendan((int)(akiko.x), (int)(akiko.y), 4, k, danmaku.dshu.plate, danmaku.dcolor.white, 0, 1, 1);
					}
				}
				if (timetoflame > 299 && timetoflame < 481) {
					if ((timetoflame - 1) % 10 == 0) {
						double k = 261 - (timetoflame - 11) / 10 * 17.5;						
						danmaku.Setdanmaku_ChainRendan((int)(akiko.x), (int)(akiko.y), 4, k, danmaku.dshu.plate, danmaku.dcolor.white, 0, 1, 1);
					}
				}
				if (timetoflame > 249 && timetoflame < 291) {
					if (akiko.vecx == 0) {
						akiko.vecx = (360 - akiko.x) / (300 - timetoflame);
					}
					if (timetoflame % 10 == 0) {
						int k = 100 - (timetoflame - 250) / 10 * 4;
						danmaku.SetDanmakuSE(1, 0, 0);
						danmaku.Setdanmaku_ChainRendan((int)(akiko.x), (int)(akiko.y), 2, k, danmaku.dshu.biglazer, danmaku.dcolor.blue, 0, 1, 1);
					}
				}
				if (timetoflame > 549 && timetoflame < 591 && timetoflame % 10 == 0) {
					int k = 80 + (timetoflame - 550) / 10 * 4;
					danmaku.SetDanmakuSE(1, 0, 0);
					danmaku.Setdanmaku_ChainRendan((int)(akiko.x), (int)(akiko.y), 2, k, danmaku.dshu.biglazer, danmaku.dcolor.blue, 0, 1, 1);
				}
			}
			break;
		case 26://スペルカード2　着符「満たされる欲望 - 仮装 - 」
			if (Currenttime > 10) {
				Bosshit = true;
			}
			else {
				Bosshit = false;
			}
			if (Currenttime < 3) {
				appeary += 2;
				StartSpellkardEffect(akiko2stand[StandAct.strategy]);
				akiko.x += akiko.vecx;
				akiko.y += akiko.vecy;
				if ((akiko.vecx > 0) ? akiko.x + akiko.vecx > 212 :  akiko.x + akiko.vecx < 212) {
					akiko.vecx = 0;
					akiko.vecy = 0;
					akiko.x = 212;
					akiko.y = 243;
				}
			}
			else {
				//timetoflame = ((Currenttime - 3) % Looptime) * 60 + flame;
				int p = danmaku.dan[0].np;
				while (danmaku.dan[p].danshu != danmaku.dshu.plate && p != danmaku.tail) {
					p = danmaku.dan[p].np;
				}
				if (p == danmaku.tail) {
					danmaku.Setdanmaku_Wave((int)(akiko.x), (int)(akiko.y), -2, danmaku.dshu.plate, danmaku.dcolor.red, 0, 1, 8, danmaku.worder.capture, 210, -3);
					platetoflame = 0;
				}
				platetoflame++;
				int pp;
				timetoflame = platetoflame % (Looptime * 60);
				switch (timetoflame) {
				case 60:
					p = danmaku.dan[0].np;
					while (p != danmaku.tail) {
						if (danmaku.dan[p].danshu == danmaku.dshu.plate) {
							danmaku.dan[p].vecx = 0;
						}
						p = danmaku.dan[p].np;
					}
				case 120:
					p = danmaku.dan[0].np;
					while (p != danmaku.tail) {
						if (danmaku.dan[p].danshu == danmaku.dshu.plate) {
							danmaku.dan[p].vecy = -5;
							danmaku.dan[p].vecx = 0.5;
						}
						p = danmaku.dan[p].np;
					}
					break;
				case 300:
					for (int k = 10; k < 351; k += 90) {
						danmaku.Setdanmaku_ArrowRendan((int)(akiko.x), (int)(akiko.y), k, danmaku.dshu.middle, danmaku.dcolor.yellow, 0, 5, 3, 0.5);
					}
					break;
				case 360:
					p = danmaku.dan[0].np;
					while (p != danmaku.tail) {
						if (danmaku.dan[p].danshu == danmaku.dshu.plate) {
							danmaku.dan[p].vecy = 7;
							danmaku.dan[p].vecx = -1;
							pp = danmaku.tail;
							danmaku.Setdanmaku_Daenwave((int)(danmaku.dan[p].x), (int)(danmaku.dan[p].y), 0.5, 1, danmaku.dshu.tubu, danmaku.dcolor.white, 0, 1, 10);							
						}
						p = danmaku.dan[p].np;
					}
					break;
				case 380:
					pp = danmaku.tail;
					danmaku.Setdanmaku_Wave(400, 227, 1, danmaku.dshu.middle, danmaku.dcolor.white, 0, danmaku.Getkakudo_Homing(akiko.x, akiko.y, j.x, j.y), 12);
					danmaku.Setdanmaku_Wave(10, 206, 1, danmaku.dshu.middle, danmaku.dcolor.white, 0, danmaku.Getkakudo_Homing(akiko.x, akiko.y, j.x, j.y), 12);
					for (int cp = pp; cp < danmaku.tail; cp++) {
						switch (cp % 3) {
						case 0:
							danmaku.dan[cp].color = danmaku.dcolor.red;
							break;
						case 1:
							danmaku.dan[cp].color = danmaku.dcolor.purple;
							break;
						case 2:
							danmaku.dan[cp].color = danmaku.dcolor.pink;
							break;
						}
					}
					break;
				case 390:		
					pp = danmaku.tail;
					danmaku.Setdanmaku_Wave(170, 475, 1, danmaku.dshu.middle, danmaku.dcolor.white, 0, danmaku.Getkakudo_Homing(akiko.x, akiko.y, j.x, j.y), 12);
					danmaku.Setdanmaku_Wave(253, 5, 1, danmaku.dshu.middle, danmaku.dcolor.white, 0, danmaku.Getkakudo_Homing(akiko.x, akiko.y, j.x, j.y), 12);
					for (int cp = pp; cp < danmaku.tail; cp++) {
						switch (cp % 3) {
						case 0:
							danmaku.dan[cp].color = danmaku.dcolor.red;
							break;
						case 1:
							danmaku.dan[cp].color = danmaku.dcolor.purple;
							break;
						case 2:
							danmaku.dan[cp].color = danmaku.dcolor.pink;
							break;
						}
					}
					break;
				case 540:
					p = danmaku.dan[0].np;
					while (p != danmaku.tail) {
						if (danmaku.dan[p].danshu == danmaku.dshu.plate) {
							danmaku.dan[p].vecy = 5;
							danmaku.dan[p].vecx = -1;
							pp = danmaku.tail;
							danmaku.Setdanmaku_Wave((int)(danmaku.dan[p].x), (int)(danmaku.dan[p].y), 2, danmaku.dshu.ring, danmaku.dcolor.white, 0, danmaku.Getkakudo_Homing(akiko.x, akiko.y, j.x, j.y), 10);
							for (int cp = pp; cp < danmaku.tail; cp++) {
								switch (cp % 3) {
								case 0:
									danmaku.dan[cp].color = danmaku.dcolor.red;
									break;
								case 1:
									danmaku.dan[cp].color = danmaku.dcolor.purple;
									break;
								case 2:
									danmaku.dan[cp].color = danmaku.dcolor.pink;
									break;
								}
							}
						}
						p = danmaku.dan[p].np;
					}
					break;
				}
				
				
				if (timetoflame > 199 && timetoflame < 361) {
					p = danmaku.dan[0].np;
					int stop[8] = { 10,55,100,145,190,235,280,325 };
					bool stoped[8] = { false,false,false ,false ,false,false,false ,false };
					while (p != danmaku.tail) {
						if (danmaku.dan[p].danshu == danmaku.dshu.plate && danmaku.dan[p].vecy == 0) {
							for (int s = 0; s < 8; s++) {
								if (danmaku.ddan[p].crosskakudo == stop[s]) {
									stoped[s] = true;
									break;
								}
							}
						}
						p = danmaku.dan[p].np;
					}
					p = danmaku.dan[0].np;
					while (p != danmaku.tail) {
						if (danmaku.dan[p].danshu == danmaku.dshu.plate) {
							if (danmaku.ddan[p].crossr == 150) {
								danmaku.dan[p].vecx = 0;
							}
							if (timetoflame % 10 == 0) {
								for (int s = 0; s < 8; s++) {
									if (danmaku.ddan[p].crosskakudo > stop[s] && danmaku.ddan[p].crosskakudo + danmaku.dan[p].vecy <= stop[s] && stoped[s] == false) {
										danmaku.dan[p].vecy = 0;
										danmaku.ddan[p].crosskakudo = stop[s];
										danmaku.dan[p].vecx = 0;
									}
								}
							}
							p = danmaku.dan[p].np;
							
						}
						else {
							p = danmaku.dan[p].np;
						}
					}
				}
				if (timetoflame > 360 && timetoflame < 541) {
					p = danmaku.dan[0].np;
					while (p != danmaku.tail) {
						if (danmaku.dan[p].danshu == danmaku.dshu.plate) {
							if (danmaku.dan[p].vecx > 0) {
								if (danmaku.ddan[p].crossr == 150) {
									danmaku.dan[p].vecx *= -1;
								}
							}
							else {
								if (danmaku.ddan[p].crossr == 100) {
									danmaku.dan[p].vecx *= -1;
								}
							}
						}
						p = danmaku.dan[p].np;
					}
				}
				if (timetoflame > 540 && timetoflame < 601) {
					p = danmaku.dan[0].np;
					while (p != danmaku.tail) {
						if (danmaku.dan[p].danshu == danmaku.dshu.plate) {
							if (danmaku.ddan[p].crossr == 92) {
								danmaku.dan[p].vecx = 0;
							}
						}
						p = danmaku.dan[p].np;
					}
				}
			}
			break;
		case 27://スペルカード3　妄創「ディルージョンクリエイト」
			if (Currenttime > 12) {
				Bosshit = true;
			}
			else {
				Bosshit = false;
			}
			if (Currenttime < 6) {
				if (Currenttime < 3) {
					EndSpellkardEffect(750000, SpellBonusScore);

				}
				else {
					if (Currenttime == 3 && flame == 2) {
						eff.RequestSE(eff.se.spell);
						Spell = true;
						SpellBonusScore = 5000000;
						decreasebonusperflame = SpellBonusScore / ((Bosstime - 12) * 60);
						appearx = 82;
						appeary = 350;
						akiko.vecx = (212 - akiko.x) / 40;
						akiko.vecy = (70 - akiko.y) / 40;
					}
					akiko.x += akiko.vecx;
					akiko.y += akiko.vecy;
					if (akiko.y + akiko.vecy < 50) {
						akiko.vecy = 0;
						akiko.vecx = 0;
					}
					appeary -= 4;
					StartSpellkardEffect(akiko2stand[StandAct.angry]);
				}
			}
			else {
				akiko.x += akiko.vecx;
				akiko.y += akiko.vecy;
				timetoflame = ((Currenttime - 7) % Looptime) * 60 + flame;
				switch (timetoflame) {
				case 60://初期位置もしくは右上から左上に移動
					akiko.vecx = (152 - akiko.x) / 30;
					akiko.vecy = (120 - akiko.y) / 30;
					break;
				case 90:
					akiko.vecx = 0;
					akiko.vecy = 0;
					akiko.x = 152;
					akiko.y = 120;
					break;
				case 150://左上→中央
					akiko.vecx = (212 - akiko.x) / 30;
					akiko.vecy = (180 - akiko.y) / 30;
					break;
				case 180:
					akiko.vecx = 0;
					akiko.vecy = 0;
					break;
				case 240://中央→右上
					akiko.vecx = (272 - akiko.x) / 30;
					akiko.vecy = (120 - akiko.y) / 30;
					break;
				case 270:
					akiko.vecx = 0;
					akiko.vecy = 0;
					break;
				case 330://右上→中央
					akiko.vecx = (212 - akiko.x) / 30;
					akiko.vecy = (180 - akiko.y) / 30;
					break;
				case 360:
					akiko.vecx = 0;
					akiko.vecy = 0;
					break;
				case 420://中央→左上
					akiko.vecx = (152 - akiko.x) / 30;
					akiko.vecy = (120 - akiko.y) / 30;
					break;
				case 450:
					akiko.vecx = 0;
					akiko.vecy = 0;
					break;
				case 510://左上→右上
					akiko.vecx = (272 - akiko.x) / 30;
					akiko.vecy = (120 - akiko.y) / 30;
					break;
				case 540:
					akiko.vecx = 0;
					akiko.vecy = 0;
					break;
				}
				int mod;
				mod = timetoflame % 40;
				switch (mod) {
				case 0:
					danmaku.Setdanmaku_Wave((int)(akiko.x), (int)(akiko.y), 4, danmaku.dshu.uroko, danmaku.dcolor.red, 0, 1, 10);
					break;
				case 6:
					danmaku.Setdanmaku_Wave((int)(akiko.x), (int)(akiko.y), 2, danmaku.dshu.middle, danmaku.dcolor.pink, 0, danmaku.Getkakudo_Homing(akiko.x, akiko.y, j.x, j.y), 10);
					break;
				case 12:
					danmaku.Setdanmaku_Wave((int)(akiko.x), (int)(akiko.y), 3, danmaku.dshu.large, danmaku.dcolor.purple, 0, 10, 6);
					break;
				case 18:
					danmaku.Setdanmaku_Wave((int)(akiko.x), (int)(akiko.y), 2, danmaku.dshu.uroko, danmaku.dcolor.pink, 0, danmaku.Getkakudo_Homing(akiko.x, akiko.y, j.x, j.y), 8);
					break;
				case 24:
					danmaku.Setdanmaku_Wave((int)(akiko.x), (int)(akiko.y), 4, danmaku.dshu.ring, danmaku.dcolor.red, 0, danmaku.Getkakudo_Homing(akiko.x, akiko.y, j.x, j.y), 8);
					break;
				case 30:
					//danmaku.Setdanmaku_Wave((int)(akiko.x), (int)(akiko.y), 2, danmaku.dshu.kome, danmaku.dcolor.purple, 0, 1, 36);
					break;
				case 36:
					danmaku.Setdanmaku_Wave((int)(akiko.x), (int)(akiko.y), 3, danmaku.dshu.middle, danmaku.dcolor.purple, 0, danmaku.Getkakudo_Homing(akiko.x, akiko.y, j.x, j.y) + 2, 15);
					break;
				}
			}
			
			break;
		case 28://終了　爆散
			if (Currenttime > 2) {
				talkevent = "";
				switch (PlayerData.jikinum) {
				case 0:
					jikiname = "布都";
					jikicolor = GetColor(255, 150, 150);
					jy = 215;
					break;
				case 1:
					jikiname = "魅魔";
					jikicolor = GetColor(220, 220, 100);
					jy = 210;
					break;
				case 2:
					jikiname = "早苗";
					jikicolor = GetColor(150, 150, 255);
					jy = 210;
					break;
				case 3:
					jikiname = "咲夜";
					jikicolor = GetColor(150, 200, 150);
					jy = 210;
					break;
				}
				if (nexttalk) {
					ProcessTalk(jikiname, jikicolor, talkevent,jy,205, "明子", akiko2stand,GetColor(200, 50, 210));
					nexttalk = false;
					if (talkevent != "") {
						if (strcmp(talkevent, "終了") == 0) {
							Talkcount = 0;
						}
						if (strcmp(talkevent, "リザルト表示") == 0) {
							Talkcount = 1;
							lastscene = 28;
						}
					}
					
				}
				else {
					
				}
			}
			if (Currenttime < 3) {
				EndSpellkardEffect(1000000, SpellBonusScore);
				if (Currenttime == 2 && flame == 59) {
					nexttalk = true;
				}
			}
			else {
				if (Talkcount != 1) {
					DisplayTalk(jy, 225);
				}

			}
			SetDrawBright(255, 255, 255);
			break;
		}
		
		if (scene != 24) {
			danmaku.ProcessBossDanmaku(flame + Currenttime * 60, scene, PlayerData.jikinum, (int)(akiko.x), (int)(akiko.y));
		}
		else {
			danmaku.ProcessBossDanmaku(flame + Currenttime * 60, scene, PlayerData.jikinum, (int)(j.x), (int)(j.y));
		}
		if (BossTalk == false) { rr = DisplayBossStates(akiko.hitpoint, akiko.phasecount); }
		if (Spell) {
			DisplaySpellStates();
		}
		if (scene > 22 && scene < 28) {
			DrawGraph((int)(akiko.x), (int)(akiko.y), akikodot[akiko.imgpoji], true);
			//DrawGraph((int)(midori.x - 30), (int)(midori.y - 45), midoridot[midori.imgpoji], true);
		}
		return rr;
	}
	bool ProcessMidori(int flame){
		bool rr = true;
		prescene = scene;
		char * jikiname = 0;
		char * talkevent = 0;
		int jy;
		int jikicolor;
		if (flame == 1 && Bosshit){
			Bosstime--;
		}//一秒経過ごとに加算。
		SetDrawArea(20, 15, 404, 465);
		switch (scene){
		case 21://分岐トーク
			if (Currenttime > 2) {
				talkevent = "";
				switch (PlayerData.jikinum) {
				case 0:
					jikiname = "布都";
					jikicolor = GetColor(255, 150, 150);
					jy = 215;
					break;
				case 1:
					jikiname = "魅魔";
					jikicolor = GetColor(220, 220, 100);
					jy = 210;
					break;
				case 2:
					jikiname = "早苗";
					jikicolor = GetColor(150, 150, 255);
					jy = 210;
					break;
				case 3:
					jikiname = "咲夜";
					jikicolor = GetColor(150, 200, 150);
					jy = 210;
					break;
				}
				if (nexttalk) {
					ProcessTalk2(jikiname, jikicolor, talkevent, "明子", GetColor(200, 50, 210), akikostand, "みどり", GetColor(120, 50, 210), midoristand);
					nexttalk = false;
					if (talkevent != "") {
						if (strcmp(talkevent, "終了") == 0) {
							appear = 100;
							akiko.vecx = (0 - akiko.x) / 100;
							akiko.vecy = (0 - akiko.y) / 100;
						}
					}
				}
				else {
					if (appear > 0) {						
						akiko.x += akiko.vecx;
						akiko.y += akiko.vecy;
						appear -= 1;
						if (appear == 0) {
							appear = -1;
							Talkcount = 0;
							nexttalk = true;
						}
					}
				}
			}
			DrawGraph((int)(akiko.x - 30), (int)(akiko.y - 45), akikodot[DotAct.common], true);
			DrawGraph((int)(midori.x - 30), (int)(midori.y - 45), midoridot[DotAct.common], true);
			if (Currenttime < 3) {
				EndSpellkardEffect(1000000, SpellBonusScore);
				if (Currenttime == 2 && flame == 59) {
					nexttalk = true;
				}
			}
			else {
				DisplayTalk(jy, 225, 240);
			}
			SetDrawBright(255, 255, 255);
			break;
		case 22://後半戦　トーク
			talkevent = "";
			switch (PlayerData.jikinum) {
			case 0:
				jikiname = "布都";
				jikicolor = GetColor(255, 150, 150);
				jy = 215;
				break;
			case 1:
				jikiname = "魅魔";
				jikicolor = GetColor(220, 220, 100);
				jy = 210;
				break;
			case 2:
				jikiname = "早苗";
				jikicolor = GetColor(150, 150, 255);
				jy = 210;
				break;
			case 3:
				jikiname = "咲夜";
				jikicolor = GetColor(150, 200, 150);
				jy = 210;
				break;
			}
			if (Currenttime == 1 && flame == 1) {
				ProcessTalk(jikiname, jikicolor, talkevent, jy, 225, "みどり2", midori2stand, GetColor(100, 220, 240));
			}
			if (nexttalk) {
				ProcessTalk(jikiname, jikicolor, talkevent, jy, 225, "みどり2", midori2stand, GetColor(100, 220, 240));
				nexttalk = false;
				if (talkevent != "") {
					if (strcmp(talkevent, "終了") == 0) {
						Talkcount = 0;
					}
					if (strcmp(talkevent, "みどり、帽子をかぶり、本性を現す。BGMも変化。") == 0) {
						appear = 120;
						midori.vecx = (212 - midori.x) / 40;
						midori.vecy = (80 - midori.y) / 40;
					}

				}
			}
			if (appear > 0) {
				if (appear > 79) {
					midori.x += midori.vecx;
					midori.y += midori.vecy;
				}
				if (appear < 61) {
					midori.imgpoji = DotAct.common + 2;
					DrawGraph((int)(midori.x - 30), (int)(midori.y - 45), midoridot[DotAct.common + 2], true);
					DisplayTalk(jy, 240);
					SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255 * appear / 60);
					DrawBox(20, 15, 403, 464, GetColor(200, 240, 240), true);
					SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
				}
				else {
					DrawGraph((int)(midori.x - 30), (int)(midori.y - 45), midoridot[DotAct.common], true);
					DisplayTalk(jy, 240);
					SetDrawBlendMode(DX_BLENDMODE_ALPHA, (int)(255 / (appear - 60)));
					DrawBox(20, 15, 403, 464, GetColor(200, 220, 240), true);
					SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
				}
				if (appear == 60) {
					talk.bossstand1 = midori2stand[StandAct.common];
					ProcessTalk(jikiname, jikicolor, talkevent, jy, 240, "みどり2", midori2stand, GetColor(100, 220, 240));
					BossName = "Kontenri Midori";
				}
				appear--;
				if (appear == 0) {
					appear = -2;					
					Talkcount = 1;
				}
			}
			if (appear < 0) {
				if (appear == -2) {
					DrawGraph((int)(midori.x - 30), (int)(midori.y - 45), midoridot[DotAct.common + 2], true);
				}
				else {
					DrawGraph((int)(midori.x - 30), (int)(midori.y - 45), midoridot[DotAct.common], true);
				}
				DisplayTalk(jy, 240);
			}
			SetDrawBright(255, 255, 255);
			break;
		case 23://通常1
			timetoflame = (Currenttime % Looptime) * 60 + flame;
			switch (timetoflame) {
			case 1:
				ttail = 1;
				tukaima[0].np = 1;
				ClearTukaima();
				danmaku.dessined = false;
				danmaku.Setdanmaku_Ko((int)(midori.x), (int)(midori.y), 1.5, danmaku.dshu.mayu, danmaku.dcolor.water, 0, 30, 150, 21);
				break;
			case 21:
				danmaku.Setdanmaku_Ko((int)(midori.x), (int)(midori.y), 1.5, danmaku.dshu.mayu, danmaku.dcolor.blue, 0, 30, 150, 13);
				break;
			case 31:
				danmaku.SetDessin();
				break;
			case 41:
				danmaku.Setdanmaku_Ko((int)(midori.x), (int)(midori.y), 2.5, danmaku.dshu.big, danmaku.dcolor.water, 0, 30, 150, 11);
				break;
			}
			
			if (timetoflame > 29 && danmaku.dessined == false) {
				danmaku.SetDessin();
			}
			if (timetoflame > 99 && timetoflame < 600) {
				int mod = (int)(timetoflame % 100);
				int k;
				int d = timetoflame / 100;
				bool ts = false;
				switch (mod) {
				case 0://
					ts = true;
					k = danmaku.dessan[d].sk;
					break;
				case 40:
					ts = true;
					k = danmaku.dessan[d].mk;
					break;
				case 80:
					ts = true;
					k = danmaku.dessan[d].ek;
					break;
				}
				if (ts) {					
					int a = danmaku.dessan[d].a;
					int b = danmaku.dessan[d].b;
					danmaku.SetDanmakuSE(8, 0, 0);
					SetTukaima(danmaku.dessan[d].r * cos(k * PI / 180) + a, danmaku.dessan[d].r * sin(k * PI / 180) + b, d, k, 0, 0, Currenttime * 60 + flame, 0, 0, 0);
				}
				
			}
			if (timetoflame > 299 && timetoflame < 619) {
				if ((timetoflame - 300) % 40 == 0) {
					danmaku.Setdanmaku_ChainRendan((int)(midori.x), (int)(midori.y), 1, danmaku.Getkakudo_Homing(midori.x, midori.y, j.x, j.y), danmaku.dshu.uroko, danmaku.dcolor.white, 0, 5, 10);
				}
			}
			
			break;
		case 24://スペルカード1　模写「トレーシングメソッド」
			if (Currenttime > 10) {
				Bosshit = true;
			}
			else {
				Bosshit = false;
			}
			if (Currenttime < 3) {
				appeary += 2;
				StartSpellkardEffect(midori2stand[StandAct.strategy]);
			}
			else {
				timetoflame = ((Currenttime - 3) % Looptime) * 60 + flame;
				switch (timetoflame) {
				case 300:
					danmaku.Setdanmaku_Wave((int)(midori.x), (int)(midori.y), 3, danmaku.dshu.mayu, danmaku.dcolor.red, 0, danmaku.Getkakudo_Homing(midori.x, midori.y, j.x, j.y), 12);
					break;
				case 360:
					danmaku.Setdanmaku_Wave((int)(midori.x), (int)(midori.y), 3, danmaku.dshu.mayu, danmaku.dcolor.yellow, 0, 0, 12);
					break;
				case 420:
					danmaku.Setdanmaku_Wave((int)(midori.x), (int)(midori.y), 3, danmaku.dshu.mayu, danmaku.dcolor.green, 0, danmaku.Getkakudo_Homing(midori.x, midori.y, j.x, j.y), 12);
					break;
				case 480:
					danmaku.Setdanmaku_Wave((int)(midori.x), (int)(midori.y), 3, danmaku.dshu.mayu, danmaku.dcolor.blue, 0, 0, 12);
					break;
				case 540:
					danmaku.Setdanmaku_Wave((int)(midori.x), (int)(midori.y), 3, danmaku.dshu.mayu, danmaku.dcolor.purple, 0, danmaku.Getkakudo_Homing(midori.x, midori.y, j.x, j.y), 12);
					break;

				}
				if (timetoflame > 0 && timetoflame < 30 && tekicount == 0) {
					SetTukaima(j.x, j.y, 0, 0, midoritukaima, 30, -1, 10, 0, 0);
				}
				if (timetoflame > 179 && timetoflame < 200 && tekicount < 2) {
					SetTukaima(100,100, 0, 0, midoritukaima, 30, -1, 10, 0, 0);
					SetTukaima(300 ,100, 0, 0, midoritukaima, 30, -1, 10, 0, 0);
				}
			}
			break;
		case 25://通常2
			if (Currenttime < 8) {
				Bosshit = false;
			}
			else {
				Bosshit = true;
			}
			if (Currenttime < 3) {
				EndSpellkardEffect(500000, SpellBonusScore);
				midori.x += midori.vecx;
				midori.y += midori.vecy;
				if (midori.x + midori.vecx < 212) {
					midori.vecx = 0;
					midori.vecy = 0;
				}
			}
			else {
				midori.x += midori.vecx;
				timetoflame = ((Currenttime - 3) % Looptime) * 60 + flame;
				switch (timetoflame) {
				case 1:
					ClearTukaima();
					SetTukaima(midori.x, midori.y, (70 - 212) / 40, (200 - 100) / 40, 0, 0, 1, 10, 0, 0);
					SetTukaima(midori.x, midori.y, (double)(180 - 212) / 40, (200 - 100) / 40, 0, 0, 1, 10, 0, 0);
					SetTukaima(midori.x, midori.y, (212 - 212) / 40, (200 - 100) / 40, 0, 0, 1, 10, 0, 0);
					SetTukaima(midori.x, midori.y, (double)(240 - 212) / 40, (200 - 100) / 40, 0, 0, 1, 10, 0, 0);
					SetTukaima(midori.x, midori.y, (350 - 212) / 40, (200 - 100) / 40, 0, 0, 1, 10, 0, 0);
					SetTukaima(midori.x, midori.y, (70 - 212) / 40, (250 - 100) / 40, 0, 0, 1, 10, 0, 0);
					SetTukaima(midori.x, midori.y, (double)(180 - 212) / 40, (250 - 100) / 40, 0, 0, 1, 10, 0, 0);
					SetTukaima(midori.x, midori.y, (212 - 212) / 40, (250 - 100) / 40, 0, 0, 1, 10, 0, 0);
					SetTukaima(midori.x, midori.y, (double)(240 - 212) / 40, (250 - 100) / 40, 0, 0, 1, 10, 0, 0);
					SetTukaima(midori.x, midori.y, (350 - 212) / 40, (250 - 100) / 40, 0, 0, 1, 10, 0, 0);
					midori.vecx = (152 - midori.x) / 75;
					break;
				case 76:
					midori.vecx = (272 - midori.x) / 150;
					break;
				case 226:
					midori.vecx = (212 - midori.x) / 75;
					break;
				case 300:
					int k;
					k = 1;
					for (int t = 1; t < 11; t++) {
						if (t > 5) { k = danmaku.Getkakudo_Homing(tukaima[t].x, tukaima[t].y, j.x, j.y); }
						danmaku.Setdanmaku_Wave((int)(tukaima[t].x), (int)(tukaima[t].y), 1, danmaku.dshu.large, danmaku.dcolor.white, 0, k, 10);
					}
					midori.vecx = (272 - midori.x) / 75;
					break;
				case 375:
					midori.vecx = (152 - midori.x) / 150;
					break;
				case 525:
					midori.vecx = (212 - midori.x) / 75;
					break;
				case 600:
					midori.vecx = 0;
				}
				if (timetoflame > 59 && timetoflame < 300) {
					SetDrawBlendMode(DX_BLENDMODE_ALPHA, 100);
					int lazy[12] = { 0,200,330,400,450,
						465,
						465,
						465,
						450,
						380,
						320,
						180
					};
					int lazx[12] = { 0,404,
						404,
						404,
						404,
						300,
						212,
						175,
						20,
						20,
						20,
						20

					};
					for (int l = 1; l < 12; l++) {
						DrawLine(lazx[l], lazy[l], (int)(midori.x), (int)(midori.y), GetColor(200, 200, 50), 2);
					}
					SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 100);
					if (timetoflame % 20 == 0) {
						int mod = (int)(timetoflame - 60) / 20 + 1;
						int dshu = danmaku.dshu.ring;
						int kazu = GetRand(2) + 1;
						if (pow(lazx[mod] - j.x, 2.0) + pow(lazy[mod] - j.y, 2.0) < 100) {
							dshu = danmaku.dshu.plate;
							kazu = 1;
						}
						danmaku.Setdanmaku_ChainRendan(lazx[mod],lazy[mod], 3, danmaku.Getkakudo_Homing(lazx[mod],lazy[mod],midori.x,midori.y), dshu, danmaku.dcolor.yellow, 0,kazu, 10);
					}
				}
				if (timetoflame > 359 && timetoflame < 600) {
					if ((timetoflame - 360) % 24 == 0) {
						int t = (timetoflame - 360) / 24 + 1;
						danmaku.SetDanmakuSE(8, 0, 0);						
						danmaku.Setdanmaku_ChainRendan((int)(tukaima[t].x), (int)(tukaima[t].y), 3, danmaku.Getkakudo_Homing(tukaima[t].x, tukaima[t].y,j.x,j.y), danmaku.dshu.big, danmaku.dcolor.blue, 0, 1, 1);
						DeleteTukaima(t);
					}
				}
			}
			break;
		case 26://スペルカード2　改符「デザイアインプリンティング」
			if (Currenttime > 10) {
				Bosshit = true;
			}
			else {
				Bosshit = false;
			}
			if (Currenttime < 3) {
				appeary += 2;
				StartSpellkardEffect(midori2stand[StandAct.strategy]);
				midori.x += midori.vecx;
				midori.y += midori.vecy;
				if (midori.y + midori.vecy >= 243) {
					midori.vecx = 0;
					midori.vecy = 0;
					midori.y = 243;
				}
			}
			else {
				timetoflame = ((Currenttime - 3) % Looptime) * 60 + flame;
				if (timetoflame % 30 == 0) {
					int xx[7] = { 0,15,95,175,255,335 ,212 };
					int mod = (timetoflame / 30) % 5 + 1;
					if (mod > 5) { mod -= 5; }
					double vec = 1.5;
					int color = danmaku.dcolor.red;
					if (timetoflame > 300) {
						vec = 0.5;
						color = danmaku.dcolor.yellow;
					}
					danmaku.Setdanmaku_ChainRendan(xx[mod], 15, vec, danmaku.Getkakudo_Homing(xx[mod], 15, j.x, j.y), danmaku.dshu.uroko, color, 0, 1, 1);
				}
				if (timetoflame % 40 == 0) {
					int ud = (timetoflame / 40) % 2;
					int x, y, k;
					if (ud == 0) {
						x = 20;
						k = 1;
						y = (int)(j.y - 10);
					}
					else {
						x = 404;
						k = 180;
						y = (int)(j.y + 10);
					}
					double vec = 1.5;
					int color = danmaku.dcolor.red;
					if (timetoflame < 300) {
						vec = 0.5;
						color = danmaku.dcolor.yellow;
					}
					danmaku.Setdanmaku_ChainRendan(x, y, vec, k, danmaku.dshu.uroko, color, 0, 10, 1);
				}
				if (timetoflame % 80 == 0) {
					int type = danmaku.dshu.big;
					int kazu = 4;
					if (timetoflame > 300) {
						type = danmaku.dshu.middle;
						kazu = 7;
					}
					danmaku.Setdanmaku_Ko(20, 15, 2, type, danmaku.dcolor.water, 0, 12, 78, kazu);
					danmaku.Setdanmaku_Ko(404, 15, 2, type, danmaku.dcolor.water, 0, 102, 168, kazu);
				}
				if ((timetoflame + 20) % 100 == 0) {
					int type = danmaku.dshu.big;
					int kazu = 8;
					if (timetoflame < 300) {
						type = danmaku.dshu.middle;
						kazu = 20;
					}
					danmaku.Setdanmaku_Wave((int)(midori.x), (int)(midori.y), 1, type, danmaku.dcolor.white, 0, danmaku.Getkakudo_Homing(midori.x, midori.y, j.x, j.y), kazu);
				}
			}
			break;
		case 27://スペルカード3　禁符「リストリクティッド18」
			if (Currenttime > 12) {
				Bosshit = true;
			}
			else {
				Bosshit = false;
			}
			if (Currenttime < 6) {
				if (Currenttime < 3) {
					EndSpellkardEffect(750000, SpellBonusScore);

				}
				else {
					if (Currenttime == 3 && flame == 2) {
						eff.RequestSE(eff.se.spell);
						Spell = true;
						SpellBonusScore = 5000000;
						decreasebonusperflame = SpellBonusScore / ((Bosstime - 12) * 60);
						appearx = 82;
						appeary = 350;
						midori.vecx = (212 - midori.x) / 40;
						midori.vecy = (170 - midori.y) / 40;
					}
					midori.x += midori.vecx;
					midori.y += midori.vecy;
					if (midori.y + midori.vecy > 170) {
						midori.vecy = 0;
						midori.vecx = 0;
						rezar = 1;
						lazrange = 0;
					}
					appeary -= 4;
					StartSpellkardEffect(midori2stand[StandAct.angry]);
				}
			}
			else {
				timetoflame = (Currenttime - 6) % Looptime * 60 + flame;
				//レーザー弾幕処理
				{
					switch ((int)(timetoflame / 60)) {
					case 0:
						if (Currenttime == 6) {
							lazrange = 400 * timetoflame / 60;
						}
						else {
							lazrange = 400;
						}
						if (timetoflame < 30) {
							if (timetoflame < 26) {
								if (timetoflame > 10) {
									rezar += 1;
								}
								else {
									rezar += 0.2;
								}
							}
							else {
								rezar += 2.5;
							}
						}
						else {
							rezar += 5;
						}
						break;
					case 1:
						if (timetoflame == 61) {
							rezar = danmaku.Getkakudo_Homing(midori.x, midori.y, j.x, j.y);
							lazrange = 400;
							danmaku.DanmakuRefresh();
						}
						rezar += 3;
						break;
					case 2:
						rezar += 2.5;
						break;
					case 3:
						rezar += 1;
						break;
					case 4:
						rezar += 0.2;
						break;
					}
					if (rezar > 360) {
						rezar -= 360;
					}
					SetDrawBlendMode(DX_BLENDGRAPHTYPE_ALPHA, 100);
					for (double laz = rezar; laz < rezar + 360; laz += 20) {
						int color = GetColor(10, 200, 240);
						if (timetoflame > 360 && timetoflame < 390) {
							color = GetColor(200, 100, 100);
						}
						DrawLine((int)(midori.x), (int)(midori.y), (int)(cos(laz * PI / 180) * lazrange + midori.x), (int)(sin(laz * PI / 180) * lazrange + midori.y), color, 3);
					}
					SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
					if (danmaku.dancount > 0 && timetoflame == 31) {
						int p = danmaku.dan[0].np;
						while (p != danmaku.tail) {
							if (danmaku.dan[p].danshu == danmaku.dshu.lazer) {
								danmaku.DeleteDan(p);
							}
							p = danmaku.dan[p].np;
						}
					}

					if (timetoflame == 390) {
						for (int laz = 20; laz < 400; laz += 10) {
							int p = danmaku.tail;
							danmaku.Setdanmaku_Wave((int)(midori.x), (int)(midori.y), 0, danmaku.dshu.lazer, danmaku.dcolor.white, 0, (int)(rezar), 18);
							for (double k = rezar; k < rezar + 360; k += 20) {
								danmaku.dan[p].x += cos(k * PI / 180) * laz;
								danmaku.dan[p].y += sin(k * PI / 180) * laz;
								p++;
							}
						}
					}
				}
				//通常弾幕処理
				if (timetoflame % 25 == 0) {
					int k = GetRand(90) + 45;
					int x = GetRand(380) + 20;
					if (x > 181 && x < 241) {
						k = danmaku.Getkakudo_Homing(midori.x, midori.y, j.x, j.y);
					}
					danmaku.Setdanmaku_ChainRendan(x, 15, 3, k, danmaku.dshu.big, danmaku.dcolor.blue, 0, 1, 1);
				}
				if (timetoflame % 40 == 0) {
					int k = 0;
					if (timetoflame % 80 == 0) {
						k = danmaku.Getkakudo_Homing(midori.x, midori.y, j.x, j.y);
					}
					danmaku.Setdanmaku_Wave((int)(midori.x), (int)(midori.y), 1.5, danmaku.dshu.ring, danmaku.dcolor.purple, 0, k, 16);
				}
				if (timetoflame == 120 || timetoflame == 360) {
					int kakudo[7] = { 0,198,204,214,323,335,341 };
					for (int k = 1; k < 7; k++) {
						danmaku.Setdanmaku_ChainRendan((int)(midori.x), (int)(midori.y), 2, kakudo[k], danmaku.dshu.kome, danmaku.dcolor.water, 0, 1, 0);
					}
				}
			}
			break;
		case 28://終了　爆散
			if (Currenttime > 2) {
				talkevent = "";
				switch (PlayerData.jikinum) {
				case 0:
					jikiname = "布都";
					jikicolor = GetColor(255, 150, 150);
					jy = 215;
					break;
				case 1:
					jikiname = "魅魔";
					jikicolor = GetColor(220, 220, 100);
					jy = 210;
					break;
				case 2:
					jikiname = "早苗";
					jikicolor = GetColor(150, 150, 255);
					jy = 210;
					break;
				case 3:
					jikiname = "咲夜";
					jikicolor = GetColor(150, 200, 150);
					jy = 210;
					break;
				}
				if (nexttalk) {
					ProcessTalk(jikiname, jikicolor, talkevent, jy, 205, "みどり", midori2stand, GetColor(200, 50, 210));
					nexttalk = false;
					if (talkevent != "") {
						if (strcmp(talkevent, "終了") == 0) {
							Talkcount = 0;
						}
						if (strcmp(talkevent, "リザルト表示") == 0) {
							Talkcount = 1;
							lastscene = 28;
						}
					}

				}
				else {

				}
			}
			if (Currenttime < 3) {
				EndSpellkardEffect(1000000, SpellBonusScore);
				if (Currenttime == 2 && flame == 59) {
					nexttalk = true;
				}
			}
			else {
				if (Talkcount != 1) {
					DisplayTalk(jy, 225);
				}

			}
			SetDrawBright(255, 255, 255);
			break;
		}
		if (tekicount > 0) {
			ProcessTukaima(Currenttime * 60 + flame);
		}
		danmaku.ProcessBossDanmaku(flame + Currenttime * 60, scene, PlayerData.jikinum, (int)(j.x), (int)(j.y));
		
		if (BossTalk == false) { rr = DisplayBossStates(midori.hitpoint, midori.phasecount); }
		if (Spell) {
			DisplaySpellStates();
		}
		if (scene > 22 && scene < 28) {
			//DrawGraph((int)(akiko.x - 30), (int)(akiko.y - 45), akikodot[akiko.imgpoji], true);
			DrawGraph((int)(midori.x), (int)(midori.y), midoridot[midori.imgpoji], true);
		}
		return rr;
	}
	void ProcessTukaima(int flame) {
		int p = tukaima[0].np;
		if (tekicount > 8) {
			int pp = p;
		}
		while (p != ttail) {
			switch (scene) {
			case 23://通常1
				//vecxはdessinの曲線の番号、vecyは曲線の角度を示す。
				int d;
				d = (int)(tukaima[p].vecx);
				int a;
				a = danmaku.dessan[d].a;
				int b;
				b = danmaku.dessan[d].b;
				int r;
				r = danmaku.dessan[d].r;
				int sk;
				sk = danmaku.dessan[d].sk;
				int mk;
				mk = danmaku.dessan[d].mk;
				int ek;
				ek = danmaku.dessan[d].ek;
				//始点と終点、角度の増減によって螺旋状のような角度の増減を扱う
				if (tukaima[p].vecy == danmaku.dessan[d].sk) {
					double vk = (double)(ek - sk) / 80;
					double dk;
					int aa, bb;
					double k;
					if (flame - tukaima[p].start < 80) {
						dk = sk + vk * (flame - tukaima[p].start);
					}
					else {
						dk = ek;
					}
					if (sk < mk) {
						for (k = sk; k + 1 < dk; k += vk) {
							aa = (int)(cos(k * PI / 180) * r + a) + 20;
							bb = (int)(sin(k * PI / 180) * r + b) + 20;
							DrawCircle(aa, bb, 3, GetColor(50, 100, 200), true);
						}

					}
					else {
						for (k = sk; k - 1 > dk; k += vk) {
							aa = (int)(cos(k * PI / 180) * r + a) + 20;
							bb = (int)(sin(k * PI / 180) * r + b) + 20;
							DrawCircle(aa, bb, 3, GetColor(50, 100, 200), true);
						}
					}
					if ((flame - tukaima[p].start) % 15 == 0 && dk != ek) {
						aa = (int)(cos(k * PI / 180) * r + a) + 20;
						bb = (int)(sin(k * PI / 180) * r + b) + 20;
						danmaku.Setdanmaku_Wave(aa, bb, 1, danmaku.dshu.hahen, danmaku.dcolor.water, 60, danmaku.Getkakudo_Homing(aa, bb, j.x, j.y), 5);
					}
				}
				if (flame - tukaima[p].start < 30) {
					int blend = (int)(256 * (flame - tukaima[p].start) / 30);
					SetDrawBlendMode(DX_BLENDMODE_ALPHA, blend);
					DrawExtendGraph((int)(tukaima[p].x), (int)(tukaima[p].y), (int)(tukaima[p].x) + 70 - (flame - tukaima[p].start), (int)(tukaima[p].y) + 70 - (flame - tukaima[p].start), midoritukaima, true);
					SetDrawBlendMode(DX_BLENDMODE_NOBLEND, blend);
				}
				else {
					DrawGraph((int)(tukaima[p].x), (int)(tukaima[p].y), midoritukaima, true);
				}
				break;
			case 24://スペルカード1　模写「トレーシングメソッド」
				if (tukaima[p].ready == 0) {
					int k;
					switch (p) {
					case 1:
						k = danmaku.Getkakudo_Homing(tukaima[p].x, tukaima[p].y, j.x, j.y);
						tukaima[p].x += cos(k * PI / 180) * 1.5;
						tukaima[p].y += sin(k * PI / 180) * 1.5;
						if ((flame - tukaima[p].start) % 60 == 0) {
							danmaku.Setdanmaku_Wave((int)(tukaima[p].x), (int)(tukaima[p].y), 2, danmaku.dshu.tubu, danmaku.dcolor.water, 90, danmaku.Getkakudo_Homing(tukaima[p].x, tukaima[p].y, j.x, j.y), 15);
						}
						break;
					case 2:
						k = danmaku.Getkakudo_Homing(tukaima[p].x, tukaima[p].y, j.x, j.y);
						tukaima[p].x += cos(k * PI / 180) * 1;
						tukaima[p].y += sin(k * PI / 180) * 1;
						if (flame - tukaima[p].start == 150) {
							tukaima[p].ready = 240;
							danmaku.Setdanmaku_Wave((int)(tukaima[p].x), (int)(tukaima[p].y), 1, danmaku.dshu.ring, danmaku.dcolor.water, 0, danmaku.Getkakudo_Homing(tukaima[p].x, tukaima[p].y, j.x, j.y), 10);
						}
						break;
					case 3:
						k = danmaku.Getkakudo_Homing(tukaima[p].x, tukaima[p].y, j.x, j.y);
						int sa;
						sa = flame - tukaima[p].start;
						if ((sa > 59 && sa < 79) || (sa > 159 && sa < 179)) {
							k += danmaku.Getkakudo_Homing(tukaima[p].x, tukaima[p].y, midori.x, midori.y);
						}
						tukaima[p].x += cos(k * PI / 180) * 1;
						tukaima[p].y += sin(k * PI / 180) * 1;
						if (flame - tukaima[p].start == 150) {
							tukaima[p].ready = 240;
							danmaku.Setdanmaku_Wave((int)(tukaima[p].x), (int)(tukaima[p].y), 2, danmaku.dshu.ring, danmaku.dcolor.water, 0, danmaku.Getkakudo_Homing(tukaima[p].x, tukaima[p].y, j.x, j.y), 10);
						}
						break;
					}
				}
				else {
					tukaima[p].ready--;
					if (tukaima[p].ready == 0) {
						tukaima[p].start = flame;
						if (p > 1) {
							danmaku.Setdanmaku_Wave((int)(tukaima[p].x), (int)(tukaima[p].y), 2, danmaku.dshu.ring, danmaku.dcolor.water, 0, danmaku.Getkakudo_Homing(tukaima[p].x, tukaima[p].y, j.x, j.y), 10);
						}
					}
				}
				DrawGraph((int)(tukaima[p].x), (int)(tukaima[p].y), midoritukaima, true);
				break;
			case 25:
				tukaima[p].x += tukaima[p].vecx;
				tukaima[p].y += tukaima[p].vecy;
				if (p < 6 && tukaima[p].y + tukaima[p].vecy >= 200) {
					tukaima[p].vecx = 0;
					tukaima[p].vecy = 0;
					tukaima[p].y = 200;
				}
				else {
					if (tukaima[p].y + tukaima[p].vecy >= 250) {
						tukaima[p].vecx = 0;
						tukaima[p].vecy = 0;
						tukaima[p].y = 250;
					}
				}
				SetDrawArea(20, 15, 404, 465);
				DrawGraph((int)(tukaima[p].x) - 20, (int)(tukaima[p].y) - 20, midoritukaima, true);
				SetDrawArea(1, 1, 640, 480);
				break;
			}
			p = tukaima[p].np;
		}
	}
	bool ProcessRin(int flame){
		bool rr = true;
		int r = 0;
		prescene = scene;
		if (flame == 1){
			Bosstime--;
		}//一秒経過ごとに加算。
		SetDrawArea(20, 15, 404, 465);
		if (scene != 0){
			switch (scene){
			case 8:
				int blend;
				blend = (int)(256 * (flame + Currenttime * 60) / 120 - 1);
				SetDrawBlendMode(DX_BLENDMODE_ALPHA, blend);
				DrawGraph((int)(Rin.x - 30), (int)(Rin.y - 45), rindot[DotAct.common], true);
				SetDrawBlendMode(DX_BLENDMODE_NOBLEND, blend);
				break;
			case 9://通常1
				if (Currenttime > 3){
					Bosshit = true;
				}
				else{
					Bosshit = false;
				}
				timetoflame = (Currenttime % Looptime) * 60 + flame;
				Rin.x += Rin.vecx;
				Rin.y += Rin.vecy;
				switch (timetoflame){
				case 1://扇状依存なしring弾40way
					danmaku.DanmakuRefresh();
					danmaku.Setdanmaku_Ko((int)(Rin.x), (int)(Rin.y), 1.5, danmaku.dshu.ring, danmaku.dcolor.white, 0, 191, 351, 10);
					break;
				case 20://扇状依存なしring弾80way
					danmaku.Setdanmaku_Ko((int)(Rin.x), (int)(Rin.y), 1.5, danmaku.dshu.ring, danmaku.dcolor.white, 0, 191, 351, 20);
					break;
				case 40://扇状依存なしring弾120way
					danmaku.Setdanmaku_Ko((int)(Rin.x), (int)(Rin.y), 1.5, danmaku.dshu.ring, danmaku.dcolor.white, 0, 191, 351, 30);
					break;
				case 150://自機方向±30度方向へ速度差20wayのmayu弾
					for (int b = 0; b < 41; b++){
						danmaku.boundable[b] = true;
					}
					danmaku.boundroot = danmaku.tail;
					danmaku.Setdanmaku_ArrowRendan((int)(Rin.x), (int)(Rin.y), danmaku.Getkakudo_Homing(j.x, j.y, Rin.x, Rin.y) - 30, danmaku.dshu.mayu, danmaku.dcolor.white, 0, 20, 0.5, 4.3);
					danmaku.Setdanmaku_ArrowRendan((int)(Rin.x), (int)(Rin.y), danmaku.Getkakudo_Homing(j.x, j.y, Rin.x, Rin.y) + 30, danmaku.dshu.mayu, danmaku.dcolor.white, 0, 20, 0.5, 4.3);
					break;
				case 240://波状自機方向自機依存弾幕を展開
					danmaku.Setdanmaku_Pointwave((int)(Rin.x), (int)(Rin.y), 150, danmaku.dshu.middle, danmaku.dcolor.white, 0, danmaku.Getkakudo_Homing(Rin.x, Rin.y,j.x, j.y), (int)(j.x), (int)(j.y), 60, 8);
					break;
				case 300:
					danmaku.Setdanmaku_Pointwave((int)(Rin.x), (int)(Rin.y), 150, danmaku.dshu.large, danmaku.dcolor.white, 0, danmaku.Getkakudo_Homing(Rin.x, Rin.y,j.x, j.y ), (int)(j.x), (int)(j.y), 105, 8);
					break;
				case 360://所定の位置へ移動
					danmaku.Setdanmaku_Pointwave((int)(Rin.x), (int)(Rin.y), 150, danmaku.dshu.big, danmaku.dcolor.white, 0, danmaku.Getkakudo_Homing(Rin.x, Rin.y,j.x, j.y ), (int)(j.x), (int)(j.y), 135, 8);
					int next;
					next = Currenttime / Looptime + 1;
					Rin.vecx = (nextrin[next][1] - Rin.x) / 20;
					Rin.vecy = (nextrin[next][2] - Rin.y) / 20;
					break;
				case 380:
					Rin.vecx = 0;
					Rin.vecy = 0;
					break;
				}
				break;
			case 10://スペルカード戦
				if (Currenttime > 10){
					Bosshit = true;
				}
				else{
					Bosshit = false;
				}
				if (Currenttime < 3){
					int stand;
					if (PlayerData.jikinum == 1){
						stand = StandAct.surprised;
					}
					else{
						stand = StandAct.common;
					}
					Rin.x += Rin.vecx;
					Rin.y += Rin.vecy;
					if ((Rin.y > 99 && Rin.vecy > 0) || (Rin.y < 101 && Rin.vecy < 0)){
						Rin.vecy = 0;
					}
					if ((Rin.x > 211 && Rin.vecx > 0) || (Rin.x < 209 && Rin.vecx < 0)){
						Rin.vecx = 0;
					}
					appeary += 2;
					StartSpellkardEffect(rinstand[stand]);
				}
				else{
					if (flame % 10 == 0){
						danmaku.Setdanmaku_ChainRendan(20, 243, 5, 313, danmaku.dshu.ring, danmaku.dcolor.red, 0, 1, 0);
						danmaku.Setdanmaku_ChainRendan(20, 423, 5, 315, danmaku.dshu.ring, danmaku.dcolor.green, 0, (Currenttime > 7) ? 1 : 0, 0);
						danmaku.Setdanmaku_ChainRendan(404, 303, 5, 225, danmaku.dshu.ring, danmaku.dcolor.purple, 0, (Currenttime > 10) ? 1 : 0, 0);
						danmaku.Setdanmaku_ChainRendan(404, 243, 5, 225, danmaku.dshu.ring, danmaku.dcolor.orange, 0, (Currenttime > 15) ? 1 : 0, 0);
						danmaku.Setdanmaku_ChainRendan(404, 423, 5, 225, danmaku.dshu.ring, danmaku.dcolor.yellow, 0, (Currenttime > 15) ? 1 : 0, 0);
						danmaku.Setdanmaku_ChainRendan(20, 303, 5, 315, danmaku.dshu.ring, danmaku.dcolor.blue, 0, (Currenttime > 15) ? 1 : 0, 0);
					}
				}
				break;
			case 11://終了　爆散
				EndSpellkardEffect(400000, SpellBonusScore);
				if (Currenttime > 2){
					int blend;
					blend = (int)(256 * ((60 - flame) + ( 3 - Currenttime) * 60) / 120 - 1);
					SetDrawBlendMode(DX_BLENDMODE_ALPHA, blend);
					DrawGraph((int)(Rin.x - 30), (int)(Rin.y - 45), rindot[DotAct.common], true);
					SetDrawBlendMode(DX_BLENDMODE_NOBLEND, blend);
				}
				else{
					DrawGraph((int)(Rin.x - 30), (int)(Rin.y - 45), rindot[DotAct.common], true);
				}
				break;
			}
			if (scene != 8 && scene != 11){
				DrawGraph((int)(Rin.x - 30), (int)(Rin.y - 45), rindot[Rin.imgpoji], true);
			}
			danmaku.ProcessBossDanmaku(flame + Currenttime * 60, scene, PlayerData.jikinum, (int)(j.x), (int)(j.y));

			if (BossTalk == false && scene > 8){ r = DisplayBossStates(Rin.hitpoint, Rin.phasecount); }
			if (Spell){
				DisplaySpellStates();
			}
		}
		SetDrawArea(1, 1, 639, 479);
		if ((scene == 9 && prescene == 8) || (scene == 16 && prescene == 17)){
			rr = false;//フェーズの進行度に応じてボス戦が終了する。
		}
		if (r != 0){
			r = -1;
		}
		return rr;
	}
	BOSU Rin;
	BOSU yonboss;
	BOSU akiko;
	BOSU midori;
	double rezar,lazrange;
	int midoritukaima;
	short lastbuttle;//後半ボス戦についての変数です。0.前半戦 1.明子戦 2.みどり戦
	bool akikohitted;//前半戦終了間際で明子が被弾していたかを示すフラグです。Trueの場合は後半戦がみどり戦、falseの場合は明子戦となります。
	bool rinbuttle;
	bool lateupdate;	
private:
	double k;
	short kakudo;
	short radius;
	bool karakaze;
	short nextrin[6][2];
	short stoptime;
	short kkakudo[2];
	short platetoflame;//明子戦においてplate弾が出現してからのフレーム経過時間を示す変数です。自機のミスによるCurrenttimeのズレを防ぐために使われます。
	short standnum[3];//トーク時の立ち絵データの添字を示す変数です。0.自機,1.明子,2.みどり
	static int rinstand[3];
	int akikostand[11];
	int midoristand[11];
	int akiko2stand[12];
	int midori2stand[12];
	static int rindot[4];
	static int akikodot[4];//通常common,通常act,覚醒common,覚醒act
	static int midoridot[4];//通常common,通常act,覚醒common,覚醒act
	
	};
int Stage4::rinstand[3] = { 0, 0, 0 };
int Stage4::rindot[4] = { 0, 0, 0, 0 };
int Stage4::akikodot[4] = { 0, 0, 0, 0 };
int Stage4::midoridot[4] = { 0, 0, 0, 0 };

class S3D:public Danmaku{
public:
	
	int ProcessDanmaku(int flame,int scene){
		int r = 0;
		int p = dan[0].np;
		while(p != tail && dancount != 0){
			if(ddan[p].ready == 0){
				
				dan[p].x += dan[p].vecx;
				dan[p].y -= dan[p].vecy;
			}else{
				ddan[p].ready--;
				
			}
			p = dan[p].np;
		}
		if(PasteDanmaku() != 0){r = -1;}
		if(r == -1){
			r = -1;
		}
		return r;
	};
	int ProcessBossDanmaku(int flame, int scene, int jikinum ,int x, int y){
		int r = 0;
		if (flame % 30 == 0){ DanmakuRefresh(); }
		int p = dan[0].np;
		while (p != tail && dancount != 0 && r == 0){
			switch (scene){
			case 7:
				if (ddan[p].ready == 0){
					dan[p].x += dan[p].vecx;
					dan[p].y -= dan[p].vecy;
				}
				else{
					ddan[p].ready--;
					if (dan[p].danshu == 4 && ddan[p].ready == 0){
						dan[p].vecx = -2 * dan[p].vecx / abs(dan[p].vecx);
						dan[p].vecy = 2 * dan[p].vecy / abs(dan[p].vecy);
						dan[p].imgangle = atan2(dan[p].vecy * -1, dan[p].vecx);
					}
				}
				break;
			case 13:
				dan[p].x += dan[p].vecx;
				dan[p].y -= dan[p].vecy;
				break;
			case 15:
				dan[p].x += dan[p].vecx;
				dan[p].y -= dan[p].vecy;
				break;
			case 20:
				if (jikinum == 1 || jikinum == 2){
					if (dan[p].danshu == dshu.middle){
						dan[p].imgangle = 0;
						ddan[p].crossr += dan[p].vecx;//波状円の半径を増加
						ddan[p].crosskakudo += dan[p].vecy;//円周上の回転位置を増分
						dan[p].x = (int)(ddan[p].crossr  * cos(ddan[p].crosskakudo * PI / 180)) + x;
						dan[p].y = (int)(ddan[p].crossr  * sin(ddan[p].crosskakudo * PI / 180)) + y;
					}
					else{
						dan[p].x += dan[p].vecx;
						dan[p].y -= dan[p].vecy;
					}
				}
				else{
					if (ddan[p].ready == 0){
						dan[p].x += dan[p].vecx;
						dan[p].y -= dan[p].vecy;
					}
					else{
						ddan[p].ready--;
					}
				}
				break;
			case 21:
				if (ddan[p].ready == 0){
					dan[p].x += dan[p].vecx;
					dan[p].y -= dan[p].vecy;
				}
				else{
					ddan[p].ready--;
				}
				break;
			case 22:
				if (jikinum == 1 || jikinum == 2){
					if (dan[p].danshu == dshu.tubu){
						dan[p].imgangle = 0;
						ddan[p].crossr += dan[p].vecx;//波状円の半径を増加
						ddan[p].crosskakudo += dan[p].vecy;//円周上の回転位置を増分
						dan[p].x = (int)(ddan[p].crossr  * cos(ddan[p].crosskakudo * PI / 180)) + 208;
						dan[p].y = (int)(ddan[p].crossr  * sin(ddan[p].crosskakudo * PI / 180)) + 100;
						if (dan[p].x < 0 || dan[p].x > 480 || dan[p].y < 0 || dan[p].y > 480){
							//画面外にはみ出したら削除
							DeleteDan(p);
						}
					}
					else{
						if (ddan[p].ready == 0){
							dan[p].x += dan[p].vecx;
							dan[p].y -= dan[p].vecy;
						}
						else{
							ddan[p].ready--;
						}

					}
				}
				else{
					if (ddan[p].ready == 0){
						dan[p].x += dan[p].vecx;
						dan[p].y -= dan[p].vecy;
					}
					else{
						ddan[p].ready--;
					}
				}
				break;
			case 23:
				if (jikinum == 1 || jikinum == 2){
					if (dan[p].danshu == dshu.ring){
						dan[p].imgangle = 0;
						ddan[p].crossr += dan[p].vecx;//波状円の半径を増加
						ddan[p].crosskakudo += dan[p].vecy;//円周上の回転位置を増分
						dan[p].x = (int)(ddan[p].crossr  * cos(ddan[p].crosskakudo * PI / 180)) + 208;
						dan[p].y = (int)(ddan[p].crossr  * sin(ddan[p].crosskakudo * PI / 180)) + 100;

					}
					else{
						dan[p].x += dan[p].vecx;
						dan[p].y -= dan[p].vecy;
					}
				}
				else{
					if (ddan[p].ready == 0){
						dan[p].x += dan[p].vecx;
						dan[p].y -= dan[p].vecy;
					}
					else{
						ddan[p].ready--;
					}
				}
				break;
			case 24:
				if (jikinum == 1 || jikinum == 2){
					if (dan[p].danshu == dshu.ring){
						dan[p].imgangle = 0;
						ddan[p].crossr += dan[p].vecx;//波状円の半径を増加
						ddan[p].crosskakudo += dan[p].vecy;//円周上の回転位置を増分
						dan[p].x = (int)(ddan[p].crossr  * cos(ddan[p].crosskakudo * PI / 180)) + bj;
						dan[p].y = (int)(ddan[p].crossr  * sin(ddan[p].crosskakudo * PI / 180)) + 100;

					}
					else{
						dan[p].x += dan[p].vecx;
						dan[p].y -= dan[p].vecy;
					}
				}
				else{
					dan[p].x += dan[p].vecx;
					dan[p].y -= dan[p].vecy;
					if (dan[p].danshu == dshu.uroko && boundable){
						ProcessBound(p);
					}
				}
				break;
			case 25:
				if (jikinum == 1 || jikinum == 2){
					if (dan[p].danshu == dshu.ring){
						dan[p].imgangle = 0;
						ddan[p].crossr += dan[p].vecx;//波状円の半径を増加
						ddan[p].crosskakudo += dan[p].vecy;//円周上の回転位置を増分
						dan[p].x = (int)(ddan[p].crossr  * cos(ddan[p].crosskakudo * PI / 180)) + x;
						dan[p].y = (int)(ddan[p].crossr  * sin(ddan[p].crosskakudo * PI / 180)) + y;

					}
					else{
						dan[p].x += dan[p].vecx;
						dan[p].y -= dan[p].vecy;
					}
				}
				else{
					if (ddan[p].ready == 0){
						dan[p].x += dan[p].vecx;
						dan[p].y -= dan[p].vecy;
					}
					else{
						ddan[p].ready--;
					}
				}
				break;
			case 26:
				if (ddan[p].ready == 0){
					dan[p].x += dan[p].vecx;
					dan[p].y -= dan[p].vecy;
				}
				else{
					ddan[p].ready--;
				}
				break;
			}
			p = dan[p].np;
		}
		r = PasteDanmaku();
		return r;
	}
	int sroot;//方向変化する弾幕の先頭添字を保持する変数です。srootからsroot + 30までの範囲にある弾幕は一度だけ方向変化します。弾幕が発射される直前の弾幕tailがsrootに設定されます。
	short bj;
	bool boundable;
};
class Stage3:public Stage{
public:
	S3D danmaku;
	Stage3::Stage3(){
		int r;
		char dir[_MAX_PATH];
		GetCurrentDirectory(_MAX_PATH, dir);
		r = _chdir("data");
		
		r = _chdir("img");
		r = _chdir("Game");
		r = _chdir("Enemy");
		r = _chdir("Boss");
		GetCurrentDirectory(_MAX_PATH, dir);
		orindot[DotAct.common] = LoadGraph("Orin.cat.dot.common.bmp");
		orindot[DotAct.act1] = LoadGraph("Orin.dot.common.bmp");
		orinstand[1] = LoadGraph("Orin.common.png");
		orinstand[2] = LoadGraph("Orin.fine.png");
		orintukaima[1] = LoadGraph("zonbifairy.common.bmp");
		orintukaima[2] = LoadGraph("zonbifairy.comleft.bmp");
		orintukaima[3] = LoadGraph("zonbifairy.comright.bmp");
		orintukaima[4] = LoadGraph("zonbifairy.left.bmp");
		orintukaima[5] = LoadGraph("zonbifairy.right.bmp");
		youmudot[DotAct.common] = LoadGraph("Youmu.dot.common.bmp");
		youmudot[DotAct.left] = LoadGraph("Youmu.dot.left.png");
		youmudot[DotAct.right] = LoadGraph("Youmu.dot.right.png");
		youmudot[DotAct.act1] = LoadGraph("Youmu.dot.act1.bmp");
		youmudot[DotAct.act2] = LoadGraph("Youmu.dot.act2.bmp");
		youmustand[StandAct.common] = LoadGraph("Youmu.common.bmp");
		youmustand[StandAct.fine] = LoadGraph("Youmu.fine.bmp");
		youmustand[StandAct.surprised] = LoadGraph("Youmu.surprised.bmp");
		youmustand[StandAct.excited] = LoadGraph("Youmu.excited.bmp");
		youmustand[StandAct.cry] = LoadGraph("Youmu.cry.bmp");
		yuukastand[StandAct.common] = LoadGraph("Yuuka.common.bmp");
		yuukastand[StandAct.fine] = LoadGraph("Yuuka.fine.bmp");
		yuukastand[StandAct.doubt] = LoadGraph("Yuuka.doubt.bmp");
		//yuukastand[4] = LoadGraph("Yuuka.clame.bmp");
		yuukastand[StandAct.excited] = LoadGraph("Yuuka.excited.bmp");
		yuukastand[StandAct.cry] = LoadGraph("Yuuka.cry.bmp");
		yuukadot[DotAct.common] = LoadGraph("Yuuka.dot.common.bmp");
		yuukadot[DotAct.left] = LoadGraph("Yuuka.dot.left.png");
		yuukadot[DotAct.right] = LoadGraph("Yuuka.dot.right.png");
		r = _chdir("..");
		r = _chdir("..");
		r = _chdir("..");
		r = _chdir("..");
		r = _chdir("..");
	}
	int Stage3::Nextscene(int newscene,int powercount){
		int r = 0;
		Begintime += Currenttime;
		Currenttime = 0;
		s = 0;
		int rest;
		if (newscene == 17){
			if (220 < Begintime){
				newscene += 2;
				scene += 2;
			}
			else{
				if (192 < Begintime){
					Begintime = 198;
					newscene++;
					scene++;
				}
			}
		}
		else{
			if (newscene == 9 && Begintime > 93){
				Begintime = 94;
				newscene++;
				scene++;
			}
		}
		if (newscene == 26 && (PlayerData.jikinum == 1 || PlayerData.jikinum == 2)){
			newscene = 27;
			scene = 27;
		}
		if (newscene == 21 && (PlayerData.jikinum == 0 || PlayerData.jikinum == 3)){
			//デバッグ用
			//newscene = 26;
			//scene = 26;
		}
		switch(newscene){
			case 0://最初に1秒間のラグを空ける。
				s = -1;
				r = _chdir("data");
				r = _chdir("Stage");
				r = _chdir("Stage3");
				holizon.back = LoadGraph("back.bmp");
				if (PlayerData.jikinum == 0 || PlayerData.jikinum == 3){
					holizon.bossback = LoadGraph("Aback.bmp");
				}
				else{
					holizon.bossback = LoadGraph("Bback.bmp");
				}
				r = _chdir("..");
				r = _chdir("..");
				r = _chdir("..");
				holizon.by = 431;
				missflame = 300;
				danmaku.ClearDanmaku();
				danmaku.Clearkansu();
				danmaku.Inputkansu("Stage3");
				Begintime = 0;
				Endtime = 1;
				lastscene = 27;
				BossTalk = false;
				Bossbuttle = false;
				orinbuttle = false;
				break;
			case 1:
				Endtime = 6;
				break;
			case 2:
				teki[0].np = 1;
				tail = 11;
				tekicount = 10;
				Endtime =  Begintime + 5;
				break;
			case 3:
				if (tekicount == 0){
					teki[0].np = 11;
				}
				tail = 18;
				tekicount += 7;
				Endtime = Begintime + 12;
				break;
			case 4:
				if (tekicount == 0){
					teki[0].np = 18;
				}
				tail = 76;
				tekicount += 58;
				Endtime = Begintime + 20;
				for (int tc = 1; tc < 21; tc++){
					twicecircle[tc] = false;
				}
				break;
			case 5:
				if (tekicount == 0){
					teki[0].np = 76;
				}
				for (int d = 0; d < 21; d++){
					danshotcount[d] = 1;
				}
				tail = 96;
				tekicount += 20;
				Endtime = Begintime + 16;
				break;
			case 6://中ボス登場
				Bossbuttle = true;
				Bosshit = false;
				orinbuttle = true;
				Bosstime = 2;
				Begintime = 63;
				Endtime = 65;
				BossName = "Kaenbyou Rin";//ボス名を設定
				orin.imgpoji = DotAct.common;//ドット絵を設定(デフォルトでDotAct.common)
				orin.hitr = 9;//ボスの当たり判定を設定(猫形態時は当たり判定が小さい)
				orin.x = 257;//出現位置を設定
				orin.y = 2;
				orin.hitpoint = 2500 + 600 * PlayerData.jikinum;//体力を設定
				orin.vecy = (155 - 2) / 45;//登場から停止までのベクトルを設定
				orin.vecx = -1;//(212 - 257) / 45
				break;
			case 7://お燐　通常1
				Bosshit = true;//ボスの当たり判定を有効化
				Bosstime = 40;//ボスフェーズ(通常)時間を設定
				Endtime = 98;//ボスフェーズ終了時間を設定
				Looptime = 6;//ループ間隔を設定
				orin.phasecount = 0;
				hitpointdisp = 0;
				Maxhitpoint = orin.hitpoint;//最大HPをコピー
				//開始と同時に弾幕を発射する場合はこのタイミングで発動
				danmaku.sroot = 1;
				upanddown = 0;
				break;
			case 8://中ボス退散
				Maxhitpoint = 0;
				danmaku.ClearDanmaku();
				Bosshit = false;
				orin.vecx = (10 - orin.x) / 60;
				orin.vecy = (50 - orin.y) / 60;
				if (Bosstime != 0){
					totalscore += 200000;
				}
				Bosstime = 3;
				Endtime = Begintime + 3;
				break;
			case 9:
				orinbuttle = false;
				Bossbuttle = false;
				teki[0].np = 96;
				tail = 96;
				for (rest = (90 - Begintime) / 4; rest > -1;rest--){
					tail += 5;
					tekicount += 5;
				}
				Endtime = 90;
				if (tail > 116){
					tail = 116;
					tekicount -= 116 - tail;
				}
				for (int re = 96; re < tail; re++){
					teki[re].ready = (re - 96) * 15;
				}
				break;
			case 10:
				Begintime = 91;
				if (tekicount == 0){
					teki[0].np = 116;
				}
				tail = 138;
				tekicount += 22;
				Endtime = 101;
				break;
			case 11:
				if(tekicount == 0){
					teki[0].np = 138;
				}
				tail = 160;
				tekicount += 22;
				Endtime = 112;
				break;
			case 12:
				if (tekicount == 0){
					teki[0].np = 160;
				}
				tail = 181;
				tekicount += 21;
				Endtime = 130;
				anotherspeedup = false;
				break;
			case 13://お燐　通常2
				Bossbuttle = true;
				Bosshit = false;
				orinbuttle = true;
				yuuka.phasecount = 1;
				hitpointdisp = 1;
				BossName = "Kaenbyou Rin";//ボス名を設定
				orin.imgpoji = DotAct.common;//ドット絵を設定(デフォルトでDotAct.common)
				orin.hitr = 9;//ボスの当たり判定を設定(猫形態時は当たり判定が小さい)
				orin.hitpoint =  (int)(3000 / (6 - powercount));//自機の状況により難易度別に分け、体力を設定
				orin.x = 368;//出現位置を設定
				orin.y = 57;
				orin.vecx = (double)(212 - 368) / 45;
				orin.vecy = (double)(75 - 57) / 45;//登場から停止までのベクトルを設定
				Bosshit = true;//ボスの当たり判定を有効化
				Bosstime = 40;//ボスフェーズ(通常)時間を設定
				Endtime = 174;//ボスフェーズ終了時間を設定
				Looptime = 7;//ループ間隔を設定
				Maxhitpoint = orin.hitpoint;//最大HPをコピー
				//開始と同時に弾幕を発射する場合はこのタイミングで発動
				break;
			case 14://お燐　トーク
				ChangeBGMtalkcount = 10;
				danmaku.ClearDanmaku();
				Endtime = 1000;
				Bosstime = 1000;
				orin.phasecount--;
				Talkcount = 4;
				JikiStandPosition = -1;
				orin.imgpoji = DotAct.act1;
				BossTalk = true;
				SetItem((int)(orin.x), (int)(orin.y), 1, 32, 15);
				break;
			case 15://お燐　スペルカード1枚目
				BossTalk = false;
				Spell = true;
				Bosshit = true;
				hitpointdisp = 2;
				Bosstime = 50;
				appearx = 150;
				appeary = 20;
				eff.RequestSE(eff.se.spell);
				SpellKardName = "猫焔「キャッツウィスプ」";
				Looptime = 6;
				orin.hitpoint = (int)(5000 / ( 6 - powercount));
				Maxhitpoint = orin.hitpoint;
				orin.vecx = (double)(212 - orin.x) / 40;
				orin.vecy = (double)(100 - orin.y) / 40;
				SpellBonusScore = 2000000;
				decreasebonusperflame = SpellBonusScore / (Bosstime * 60);
				Endtime += 50;
				break;
			case 16://中ボス退散
				Maxhitpoint = 0;
				danmaku.ClearDanmaku();
				ClearTukaima();
				eff.RequestSE(eff.se.bossend);
				Bosshit = false;
				Spell = false;
				Bosstime = 3;
				SetItem(orin.x, orin.y, 1, 105, 5);
				totalscore += 300000;
				totalscore += SpellBonusScore;
				Endtime = Begintime + 3;
				break;
			case 17:
				teki[0].np = 181;
				tail = 181;
				if (Begintime < 177){
					Begintime = 177;
				}
				for (rest = (197 - Begintime) / 5; rest > 0; rest--){
					tail += 5;
					tekicount += 5;
				}
				Endtime = 197;
				break;
			case 18:
				if (tekicount == 0){
					teki[0].np = 201;
				}
				tail = 207;
				if (Begintime < 197){
					rest = 22;
					Begintime = 197;
				}
				else{
					rest = 219 - Begintime;
				}
				while (rest > 4){
					if (rest > 10){
						tekicount += 6;
						tail += 6;
						}
					else{
						if (rest > 7){
							tekicount += 4;
							tail += 4;
						}
						else{
							tekicount += 2;
							tail += 2;
						}
					}
					rest -= 11;
				}
				Endtime = 220;
				break;
			case 19://大ボス戦　トーク
				JikiStandPosition = 1;
				danmaku.ClearDanmaku();
				Bossbuttle = true;
				Bosshit = false;
				BossTalk = true;
				orinbuttle = false;
				Endtime = 1000;
				Bosstime = 1000;
				Shadowflg = 1;
				standx = -40;
				standy = 180;
				ChangeBGMNumber = 6;
				switch (PlayerData.jikinum){
				case 0:
					Talkcount = 19;
					ChangeBGMtalkcount = 4;
					break;
				case 1:
					Talkcount = 24;
					ChangeBGMtalkcount = 5;
					break;
				case 2:
					Talkcount = 23;
					ChangeBGMtalkcount = 4;
					break;
				case 3:
					Talkcount = 21;
					ChangeBGMtalkcount = 4;
					break;
				}
				break;
			case 20://幽香＆妖夢　通常1
				BossTalk = false;
				Bosshit = true;//ボスの当たり判定を有効化
				Bosstime = 60;//ボスフェーズ(通常)時間を設定
				Endtime = 98;//ボスフェーズ終了時間を設定
				if (PlayerData.jikinum == 1 || PlayerData.jikinum == 2){
					BossName = "Kazami Yuuka";//ボス名を設定
					yuuka.imgpoji = DotAct.common;//ドット絵を設定(デフォルトでcommon)
					yuuka.hitr = 22;//ボスの当たり判定を設定
					Looptime = 7;//ループ間隔を設定
					yuuka.phasecount = 3;
					hitpointdisp = 1;
					yuuka.x = 208;
					yuuka.y = 100;
					yuuka.hitpoint = 2000 + 500 * powercount;
					Maxhitpoint = yuuka.hitpoint;//最大HPをコピー
					//開始と同時に弾幕を発射する場合はこのタイミングで発動
				}
				else{
					BossName = "Konpaku Youmu";//ボス名を設定
					youmu.imgpoji = DotAct.common;//ドット絵を設定(デフォルトでcommon)
					youmu.hitr = 22;//ボスの当たり判定を設定
					youmu.phasecount = 3;
					hitpointdisp = 1;
					Looptime = 7;
					youmu.x = 208;
					youmu.y = 100;
					youmu.hitpoint = 2000 + 600 * PlayerData.jikinum;
					Maxhitpoint = youmu.hitpoint;
				}
				break;
			case 21://幽香＆妖夢 スペルカード1枚目
				Spell = true;
				Bosshit = false;
				Bosstime = 80;
				danmaku.ClearDanmaku();
				appearx = 150;
				appeary = 40;
				if (PlayerData.jikinum == 1 || PlayerData.jikinum == 2){
					SpellKardName = "妖符「グラマラシーフラワー」";
					Looptime = 16;
					hitpointdisp = 2;
					yuuka.hitpoint = 2500 + 200 * powercount;
					Maxhitpoint = yuuka.hitpoint;
					SpellBonusScore = 2500000;
					decreasebonusperflame = SpellBonusScore / (Bosstime * 60);
					SetItem((int)(yuuka.x), (int)(yuuka.y), 1, 15, 15);
				}
				else{
					SpellKardName = "      命剣「居合混迷剣」";
					Looptime = 6;
					hitpointdisp = 2;
					youmu.hitpoint = 2000 + 800 * powercount;
					Maxhitpoint = youmu.hitpoint;
					SpellBonusScore = 2500000;
					decreasebonusperflame = SpellBonusScore / (Bosstime * 60);
					SetItem(youmu.x, youmu.y, 1, 10, 10);
					youmu.vecx = (double)(25 - youmu.x) / 80;
					youmu.vecy = (double)(250 - youmu.y) / 80;
					SetItem((int)(youmu.x), (int)(youmu.y), 1, 15, 15);
				}
				totalscore += 300000;
				eff.RequestSE(eff.se.spell);
				break;
			case 22://幽香 スペルカード2枚目 , 妖夢　通常2
				danmaku.ClearDanmaku();
				totalscore += SpellBonusScore;
				if (PlayerData.jikinum == 1 || PlayerData.jikinum == 2){
					Spell = true;
					Bosshit = false;
					yuuka.phasecount--;
					hitpointdisp = 3;
					Bosstime = 80;
					appearx = 150;
					appeary = 40;
					SpellKardName = "消符「ステルスブルーミング」";
					Looptime = 9;
					yuuka.hitpoint = 3500 + 200 * powercount;
					Maxhitpoint = yuuka.hitpoint;
					if (SpellBonusScore != 0){
						SetItem((int)(yuuka.x), (int)(yuuka.y), 1, 32, 5);
						PreBonusScore = SpellBonusScore;
					}
					else{
						SetItem((int)(yuuka.x), (int)(yuuka.y), 1, 20, 30);
						PreBonusScore = 0;
					}
					SpellBonusScore = 2500000;
					decreasebonusperflame = SpellBonusScore / (Bosstime * 60);
					eff.RequestSE(eff.se.spell);
				}
				else{
					Bosshit = false;//ボスの当たり判定を無効化
					Bosstime = 80;//ボスフェーズ(通常)時間を設定
					Spell = false;
					Looptime = 16;
					hitpointdisp = 1;
					youmu.vecx = (double)(330 - youmu.x) / 100;
					youmu.vecy = (double)(80 - youmu.y) / 100;
					youmu.hitpoint = 2000 + 600 * PlayerData.jikinum;
					Maxhitpoint = youmu.hitpoint;
					youmu.phasecount--;
					if (SpellBonusScore != 0){
						SetItem((int)(youmu.x), (int)(youmu.y), 1, 32, 5);
						PreBonusScore = SpellBonusScore;
					}
					else{
						SetItem((int)(youmu.x), (int)(youmu.y), 1, 20, 30);
						PreBonusScore = 0;
					}
				}
				totalscore += 300000;
				break;
			case 23://幽香 通常2 , 妖夢 スペルカード2枚目
				danmaku.ClearDanmaku();
				
				if (PlayerData.jikinum == 0 || PlayerData.jikinum == 3){
					Spell = true;
					Bosshit = false;
					Bosstime = 80;
					appearx = 150;
					appeary = 40;
					SpellKardName = "　　　　　「悟りの境地」";
					Looptime = 11;
					hitpointdisp = 2;
					youmu.hitpoint = 2500 + 200 * powercount;
					Maxhitpoint = youmu.hitpoint;
					SpellBonusScore = 2500000;
					decreasebonusperflame = SpellBonusScore / (Bosstime * 60);
					SetItem(youmu.x, youmu.y, 1, 15, 15);
					youmu.vecx = (212 - youmu.x) / 80;
					youmu.vecy = (100 - youmu.y) / 80;
					eff.RequestSE(eff.se.spell);
				}
				else{
					totalscore += SpellBonusScore;
					Bosshit = true;//ボスの当たり判定を有効化
					Bosstime = 60;//ボスフェーズ(通常)時間を設定
					Spell = false;
					yuuka.phasecount--;
					hitpointdisp = 1;
					Looptime = 10;
					yuuka.hitpoint = 2000 + 600 * PlayerData.jikinum;
					Maxhitpoint = yuuka.hitpoint;
					yuuka.vecx = (double)(208 - yuuka.x) / 160;
					if (SpellBonusScore != 0){
						SetItem((int)(yuuka.x), (int)(yuuka.y), 1, 132, 10);
					}
					else{
						SetItem((int)(yuuka.x), (int)(yuuka.y), 1, 120, 25);
					}
				}
				totalscore += 300000;
				break;
			case 24://幽香 スペルカード3枚目 , 妖夢 通常3
				danmaku.ClearDanmaku();
				if (PlayerData.jikinum == 1 || PlayerData.jikinum == 2){
					Spell = true;
					Bosshit = false;
					hitpointdisp = 2;
					Bosstime = 80;
					appearx = 150;
					appeary = 40;
					SpellKardName = "悲花「一期一会～金盞花」";
					Looptime = 11;
					yuuka.hitpoint = 3000 + 500 * powercount;
					Maxhitpoint = yuuka.hitpoint;
					if (SpellBonusScore != 0){
						SetItem((int)(yuuka.x), (int)(yuuka.y), 1, 32, 5);
					}
					else{
						SetItem((int)(yuuka.x), (int)(yuuka.y), 1, 20, 30);
					}
					SpellBonusScore = 2500000;
					decreasebonusperflame = SpellBonusScore / (Bosstime * 60);
					yuuka.vecx = (double)(208 - yuuka.x) / 80;
					yuuka.vecy = (double)(100 - yuuka.y) / 80;
					eff.RequestSE(eff.se.spell);
				}
				else{
					totalscore += SpellBonusScore;
					Bosshit = true;//ボスの当たり判定を有効化
					Bosstime = 60;//ボスフェーズ(通常)時間を設定
					Spell = false;
					Looptime = 10;
					youmu.x = 208;
					youmu.y = 100;
					hitpointdisp = 1;
					youmu.phasecount--;
					youmu.hitpoint = 2000 + 600 * PlayerData.jikinum;
					Maxhitpoint = youmu.hitpoint;
					if (SpellBonusScore != 0){
						SetItem((int)(youmu.x), (int)(youmu.y), 1, 32, 5);
					}
					else{
						SetItem((int)(youmu.x), (int)(youmu.y), 1, 20, 30);
					}
				}
				totalscore += 300000;
				break;
				
			case 25://幽香 スペルカード4枚目 , 妖夢 スペルカード3枚目
				Spell = true;
				Bosshit = false;
				Bosstime = 80;
				danmaku.ClearDanmaku();
				if (PlayerData.jikinum == 1 || PlayerData.jikinum == 2){
					SpellKardName = "「ダンシングブロッサム」";
					Looptime = 9;
					yuuka.phasecount--;
					appearx = 200;
					appeary = -100;
					hitpointdisp = 3;
					yuuka.hitpoint = 5000 + 500 * powercount;
					Maxhitpoint = yuuka.hitpoint;
					PreBonusScore = SpellBonusScore;
					SpellBonusScore = 2500000;
					decreasebonusperflame = SpellBonusScore / (Bosstime * 60);
					SetItem((int)(yuuka.x), (int)(yuuka.y), 1, 15, 115);
					yuuka.vecx = (double)(208 - yuuka.x) / 80;
					yuuka.vecy = (double)(100 - yuuka.y) / 80;
				}
				else{
					SpellKardName = "畜生剣「有為有策の無慈悲」";
					Looptime = 5;
					Bosstime = 85;
					appearx = 70;
					appeary = 400;
					hitpointdisp = 2;
					youmu.imgpoji = DotAct.common;
					youmu.hitpoint = 2000 + 800 * powercount;
					Maxhitpoint = youmu.hitpoint;
					youmu.vecx = (double)(50 - youmu.x) / 100;
					youmu.vecy = (double)(250 - youmu.y) / 100;
					if (SpellBonusScore != 0){
						SetItem((int)(youmu.x), (int)(youmu.y), 1, 32, 105);
					}
					else{
						SetItem((int)(youmu.x), (int)(youmu.y), 1, 20, 130);
					}
					SpellBonusScore = 1200000;
					decreasebonusperflame = SpellBonusScore / (Bosstime * 60);
					
				}
				eff.RequestSE(eff.se.spell);
				totalscore += 300000;
				break;
			case 26://妖夢 スペルカード4枚目
				danmaku.ClearDanmaku();
				appearx = 200;
				appeary = -100;
				Spell = true;
				SpellKardName = "        円環剣「輪廻転生」";
				Looptime = 10;
				Bosstime = 99;
				hitpointdisp = 3;
				youmu.hitpoint = 2000 + 800 * powercount;
				Maxhitpoint = youmu.hitpoint;
				youmu.phasecount--;
				if (SpellBonusScore != 0){
					SetItem((int)(youmu.x), (int)(youmu.y), 1, 10, 30);
				}
				else{
					SetItem((int)(youmu.x), (int)(youmu.y), 1, 40, 10);
				}
				youmu.vecx = (double)(212 - youmu.x) / 100;
				youmu.vecy = (double)(200 - youmu.y) / 100;
				decreasebonusperflame = 1200000 / (Bosstime * 60);
				eff.RequestSE(eff.se.spell);
				break;
			case 27://大ボス戦終了　爆散
				eff.RequestSE(eff.se.bossend);
				totalscore += SpellBonusScore;
				totalscore += 200000;
				Maxhitpoint = 0;
				danmaku.ClearDanmaku();
				Spell = false;
				Bosshit = false;
				BossTalk = true;
				Endtime = 1000;
				Bosstime = 1000;
				switch (PlayerData.jikinum){
				case 0:
					Talkcount = 12;
					break;
				case 1:
					Talkcount = 10;
					Shadowflg = 1;
					break;
				case 2:
					Talkcount = 10;
					Shadowflg = 1;
					break;
				case 3:
					Talkcount = 8;
					break;
				}
				BossStandPosition = StandAct.cry;
				StageClearscore = 3000000;
				totalscore += StageClearscore;
				break;
			case 28:
				DeleteFontToHandle(SpellBonusfont);
				DeleteFontToHandle(ClearBonusfont);
				break;
			default:
				r = -1;
				break;
		}
		teki[teki[0].np].pp = 0;
		return r;
	}
	int Stage3::PasteHolizon(int flame){//フレーム更新ごとにステージ及び枠外の背景を描写します。この後にPD,PSが入ります。
    //384 × 450
		if (DrawBox(19, 14, 405, 466, color.white, FALSE) != 0){
		   return -1;
	   }
	   if (Bossbuttle){
		   if (Spell){
			   int cl;
			   if (orinbuttle){
				   cl = GetColor(75, 50, 20);
			   }
			   else{
				   if (PlayerData.jikinum == 0 || PlayerData.jikinum == 3){
					   cl = GetColor(20, 50, 75);
				   }
				   else{
					   cl = GetColor(75, 75, 40);
				   }
			   }
			   DrawBox(20, 15, 404, 465, cl, TRUE);
		   }
		   else{
			   if (orinbuttle){
				   SetDrawBright(50, 50, 50);
				   DrawRectGraph(20, 15, 0, holizon.by, 384, 450, holizon.back, false, false);
				   SetDrawBright(255, 255, 255);
				   holizon.by -= 1;
				   if (holizon.by == 0){
					   holizon.by = 431;
				   }
			   }
			   else{
				   if (flame < 119 && scene == 19){
					   int c;
					   if (PlayerData.jikinum == 0 || PlayerData.jikinum == 3){
						   c = GetColor(240, 240, 240);
					   }
					   else{
						   c = GetColor(100, 255, 100);
					   }
					   if (flame < 61){
						   SetDrawBright(50, 50, 50);
						   DrawGraph(20, 15, holizon.back, false);
						   SetDrawBright(255, 255, 255);
						   SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255 * flame / 60);
						   DrawBox(20, 15, 403, 464, c, true);
						   SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
					   }
					   else{
						   DrawGraph(20, 15, holizon.bossback, false);
						   SetDrawBlendMode(DX_BLENDMODE_ALPHA, (int)(255 / (flame - 60)));
						   DrawBox(20, 15, 403, 464, c, true);
						   SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
					   }
				   }
				   else{
					   DrawGraph(20, 15, holizon.bossback, false);
				   }
			   }
		   }
	   }
	   else{
		   SetDrawBright(50, 50, 50);
		   DrawRectGraph(20, 15, 0, holizon.by, 384, 450, holizon.back, false, false);
		   SetDrawBright(255,255,255);
		   holizon.by -= 1;
		   if (holizon.by == 0){
			   holizon.by = 431;
		   }
	   }
	   //DrawFormatString(500,390,GetColor(255,255,255),"シーン%d,%d秒経過",scene,flame / 60);
	   /*スコア・残機・ボム数・グレーズ・パワー段階などを描写*/
	   return 0;
	}
	int Stage3::ProcessStage(int flame,int powercount){
		int r;//返り値を示す変数です。基本は1(Game Mode)か11(Practice Mode)ですが何らかのエラーが発生すれば-1になります。
		r = 3;
		totalscore = 0;
		prescene = scene;
		if(flame == 1){
			Currenttime++;
			s++;
			if (missnothit != 0){
				missnothit--;
			}
		}//一秒経過ごとに加算。
		if(scene == 28){//シーン26が終了したらStage3はクリア//シーンごとに成功したら終了。
			r = 0;
		}
		if (r != 13){
			r = r;
		}
		return r;
	};
	int Stage3::ProcessEnemy(int flame){
		int p,r;
		r = 0;
		if(tekicount > 0){
			p = teki[0].np;
		}else{
			p = tail;
		}
		if(scene == 1 && flame > 60){
			if (PlayerData.jikinum == 2 || PlayerData.jikinum == 1){
				DrawStringToHandle(50,150,"Stage3A 異変解決の案内人",GetColor(255,255,255),Stagefont);
				DrawStringToHandle(120,165,"～ Abrupt meeting",GetColor(255,255,255),Stagefont);
			}else{
				DrawStringToHandle(50,150,"Stage3B 異変解決の案内人",GetColor(255,255,255),Stagefont);
				DrawStringToHandle(120,165,"～ Strange encounter",GetColor(255,255,255),Stagefont);
			}
		}
		while(p != tail){
		    if (teki[p].ready == 0){
				switch (scene){
				case 1:
					break;
				case 2://0:07～0:12
					if (teki[p].y > 287){
						teki[p].x += teki[p].vecx;
						teki[p].y = danmaku.GetY(teki[p].x, tteki[p].usef, tteki[p].kanshu, tteki[p].fugou);
					}
					else{
						teki[p].y -= 2;
						short fugou;
						if (tteki[p].usef == 1){
							fugou = -1;
						}
						else{
							fugou = 1;
						}
						teki[p].x = danmaku.GetX(teki[p].y, tteki[p].usef, 3, fugou);
					}
					if ((flame - teki[p].start) % 60 == 0){
						danmaku.Setdanmaku_ChainRendan((int)(teki[p].x), (int)(teki[p].y), 2, danmaku.Getkakudo_Homing(teki[p].x, teki[p].y, j.x, j.y) + 5, 7, danmaku.dcolor.orange, 0, 1, 0);
						danmaku.Setdanmaku_ChainRendan((int)(teki[p].x), (int)(teki[p].y), 2, danmaku.Getkakudo_Homing(teki[p].x, teki[p].y, j.x, j.y) - 5, 7, danmaku.dcolor.orange, 0, 1, 0);
					}
					break;
				case 3://0:13～0:25
					if (p < 11){
						if (teki[p].y > 287){
							teki[p].x += teki[p].vecx;
							teki[p].y = danmaku.GetY(teki[p].x, tteki[p].usef, tteki[p].kanshu, tteki[p].fugou);
						}
						else{
							teki[p].y -= 2;
							short fugou;
							if (tteki[p].usef == 1){
								fugou = -1;
							}
							else{
								fugou = 1;
							}
							teki[p].x = danmaku.GetX(teki[p].y, tteki[p].usef, 3, fugou);
						}
						if ((flame - teki[p].start) % 60 == 0){
							danmaku.Setdanmaku_ChainRendan((int)(teki[p].x), (int)(teki[p].y), 2, danmaku.Getkakudo_Homing(teki[p].x, teki[p].y, j.x, j.y) + 5, 7,danmaku.dcolor.orange, 0, 1, 0);
							danmaku.Setdanmaku_ChainRendan((int)(teki[p].x), (int)(teki[p].y), 2, danmaku.Getkakudo_Homing(teki[p].x, teki[p].y, j.x, j.y) - 5, 7, danmaku.dcolor.orange, 0, 1, 0);
						}
					}
					else{
						teki[p].y += teki[p].vecy;
						if (teki[p].tekishu == 5){
							//ひまわり妖精
							int d = (int)(teki[p].y - 67) * 10 / 44 * 10;
							if (d % 100 == 0 && (d - 100) % 300 == 0){
								danmaku.Setdanmaku_Wave((int)(teki[p].x), (int)(teki[p].y), 2, 13,danmaku.dcolor.red, 0, 0, 30);
							}
						}
						else{
							//黄妖精
							teki[p].x = danmaku.GetX(teki[p].y, tteki[p].usef, tteki[p].kanshu, tteki[p].fugou);
							if ((flame - teki[p].start) % 15 == 0){
								danmaku.Setdanmaku_ChainRendan((int)(teki[p].x), (int)(teki[p].y), 2, danmaku.Getkakudo_Homing(teki[p].x, teki[p].y, j.x, j.y), 4, danmaku.dcolor.yellow, 0, 1, 0);
							}
						}

					}
					break;
				case 4://0:26～0:46
					teki[p].y += teki[p].vecy;
					if (teki[p].tekishu == 4){
						if (tteki[p].usef == 0){
							//直線移動
							teki[p].x += teki[p].vecx;
							if (teki[p].y >= 132 && teki[p].vecy != 0){
								teki[p].y = 132;
								if (teki[p].x == 80){
									tteki[p].usef = 1;
									tteki[p].kanshu = 2;
									tteki[p].fugou = -1;
									teki[p].vecy = 2.2;
								}
								else{
									tteki[p].usef = 2;
									tteki[p].kanshu = 2;
									tteki[p].fugou = 1;
									teki[p].vecy = 2.2;
								}
							}
						}
						else{
							//関数使用
							if (teki[p].y >= 198){
								if (twicecircle[p - 52]){
									if (tteki[p].usef == 1){
										teki[p].vecx = 2.86;

									}
									else{
										teki[p].vecx = -2.86;
									}
									teki[p].y = 198;
									teki[p].vecy = 0;
									tteki[p].usef = 0;
								}
								else{
									twicecircle[p - 52] = true;
									teki[p].vecy *= -1;
									tteki[p].fugou *= -1;
								}
							}
							else{
								if (teki[p].y <= 66){
									teki[p].y = 66;
									teki[p].vecy *= -1;
									tteki[p].fugou *= -1;
								}
								else{
									teki[p].x = danmaku.GetX(teki[p].y, tteki[p].usef, tteki[p].kanshu, tteki[p].fugou);
								}
							}

						}
					}
					else{
						teki[p].x = danmaku.GetX(teki[p].y, tteki[p].usef, tteki[p].kanshu, tteki[p].fugou);
					}
					//弾幕処理
					if (teki[p].tekishu == 4 && (flame - teki[p].start) % 60 == 0 && tteki[p].usef != 0){
						danmaku.Setdanmaku_Ko((int)(teki[p].x), (int)(teki[p].y), 2, 4,danmaku.dcolor.red, 0, danmaku.Getkakudo_Homing(teki[p].x, teki[p].y, j.x, j.y) - 15, danmaku.Getkakudo_Homing(teki[p].x, teki[p].y, j.x, j.y) + 15, 4);
					}
					break;
				case 5://0:47～1:03
					teki[p].x += teki[p].vecx;
					teki[p].y += teki[p].vecy;
					if (tteki[p].usef == 7 || tteki[p].usef == 8){
						if (teki[p].x >= 143 && teki[p].x < 278){
							if (teki[p].vecy == 0){
								if (teki[p].tekishu == 4){
									//緑妖精
									teki[p].y -= teki[p].vecx;
									teki[p].imgposi = 1;
								}
								else{
									//青妖精
									teki[p].y += teki[p].vecx;
									teki[p].imgposi = 2;
								}
								teki[p].vecx = 0;
								teki[p].vecy = 3.2;
							}
							//X増分からY増分に変更する際にY位置を予め変えておく。
							//2ループ目以降はX増分が0になっているため最初のみ意味をなす。


							if (teki[p].tekishu == 4){
								//緑妖精
								if (tteki[p].usef == 8){
									if (teki[p].x <= 215){
										tteki[p].fugou = 1;
										tteki[p].usef = 7;
										teki[p].x = 198.8;
									}
									else{
										tteki[p].fugou = -1;
									}
								}

							}
							else{
								//青妖精
								if (tteki[p].usef == 7){
									if (teki[p].x >= 209){
										tteki[p].fugou = -1;
										tteki[p].usef = 8;
										teki[p].x = 215.2;
									}
									else{
										tteki[p].fugou = 1;
									}
								}

							}
						}
						else{
							if (teki[p].y > 243){
								if (teki[p].tekishu == 4){
									//緑妖精
									teki[p].vecx = -3.2;
									teki[p].x += teki[p].vecy;
									tteki[p].fugou = 1;
									teki[p].imgposi = 3;
								}
								else{
									//青妖精
									teki[p].vecx = 3.2;
									teki[p].x -= teki[p].vecy;
									teki[p].imgposi = 4;
									tteki[p].fugou = 1;
								}
							}
							teki[p].vecy = 0;
						}
					}
					else{
						if (teki[p].y >= 199 && teki[p].y < 288){
							teki[p].vecy = 0;
							if (tteki[p].usef == 9){
								tteki[p].fugou = 1;
								if (teki[p].tekishu == 2){
									//青妖精
									teki[p].vecx = -2.5;
									teki[p].imgposi = 2;
								}
								else{
									//緑妖精
									teki[p].vecx = 2.5;
									teki[p].imgposi = 1;
								}
								if (teki[p].y >= 240){
									tteki[p].fugou = -1;
									tteki[p].usef = 10;
									teki[p].y = 245.5;
								}
							}
						}
						else{
							teki[p].imgposi = 0;
							if (tteki[p].usef == 10){
								if (teki[p].vecx != 0){
									teki[p].vecx = 0;
									teki[p].vecy = 2.5;
								}
								if (teki[p].tekishu == 2){
									tteki[p].fugou = -1;
								}
								else{
									tteki[p].fugou = 1;
								}
							}
						}
					}
					if (teki[p].vecy == 0){
						teki[p].y = danmaku.GetY(teki[p].x, tteki[p].usef, tteki[p].kanshu, tteki[p].fugou);
					}
					else{
						teki[p].x = danmaku.GetX(teki[p].y, tteki[p].usef, tteki[p].kanshu, tteki[p].fugou);
					}
					//弾幕処理
					if (flame - teki[p].start == 90 && danshotcount[p - 74] == 1 && (danshotcount[p - 75] == 1 || p % 5 == 0)){
						int color;
						if (teki[p].tekishu == 2){
							color = danmaku.dcolor.blue;
						}
						else{
							color = danmaku.dcolor.green;
						}
						danmaku.Setdanmaku_ChainRendan((int)(teki[p].x), (int)(teki[p].y), 3, danmaku.Getkakudo_Homing(teki[p].x, teki[p].y, j.x, j.y), 7,color, 0, 6, 6);
						danshotcount[p - 74]--;
					}
					break;
				case 9://1:13～1:33
					teki[p].x += teki[p].vecx;
					if (teki[p].vecy == 0){
						teki[p].y = danmaku.GetY(teki[p].x, tteki[p].usef, tteki[p].kanshu, tteki[p].fugou);
						if (teki[p].tekishu == 1){
							if (teki[p].x < 80){
								teki[p].vecy = (double)((243 - teki[p].y) / 40);
								tteki[p].usef = 0;
							}
							if (teki[p].x > 240 && teki[p].x < 246){
								danmaku.Setdanmaku_ChainRendan((int)(teki[p].x), (int)(teki[p].y), 3, danmaku.Getkakudo_Homing(teki[p].x, teki[p].y, j.x, j.y), 1,danmaku.dcolor.red, 0, 1, 1);
							}
						}
						else{
							if (teki[p].x > 344){
								teki[p].vecy = (double)((111 - teki[p].y) / 40);
								tteki[p].usef = 0;
							}
						}
					}
					else{
						teki[p].y += teki[p].vecy;
					}
					
					break;
				case 10://1:34～1:44
					if (p < 116){
						teki[p].x += teki[p].vecx;
						if (teki[p].vecy == 0){
							teki[p].y = danmaku.GetY(teki[p].x, tteki[p].usef, tteki[p].kanshu, tteki[p].fugou);
							if (teki[p].tekishu == 1){
								if (teki[p].x < 80){
									teki[p].vecy = (double)((243 - teki[p].y) / 40);
									tteki[p].usef = 0;
								}
								if (teki[p].x > 240 && teki[p].x < 246){
									danmaku.Setdanmaku_ChainRendan((int)(teki[p].x), (int)(teki[p].y), 3, danmaku.Getkakudo_Homing(teki[p].x, teki[p].y, j.x, j.y), 1,danmaku.dcolor.green, 0, 1, 1);
								}
							}
							else{
								if (teki[p].x > 344){
									teki[p].vecy = (double)((111 - teki[p].y) / 40);
									tteki[p].usef = 0;
								}
							}
						}
						else{
							teki[p].y += teki[p].vecy;
						}
					}
					else{
						teki[p].x += teki[p].vecx;
						if (teki[p].tekishu == 2){
							teki[p].y += teki[p].vecy;
							if (teki[p].y > 199 && teki[p].vecx == 0){
								teki[p].y = 199;
								danmaku.Setdanmaku_Wave((int)(teki[p].x), (int)(teki[p].y), 1, 6, danmaku.dcolor.green, 0, 0, 36);
								teki[p].vecy = 0.7375;
								if (teki[p].x > 212){
									teki[p].vecx = (20 - teki[p].x) / 240;
									teki[p].imgposi = 1;
								}
								else{
									teki[p].vecx = (404 - teki[p].x) / 240;
									teki[p].imgposi = 2;
								}
							}
							if ((int)(teki[p].y ) == 114){
								danmaku.Setdanmaku_Wave((int)(teki[p].x), (int)(teki[p].y), 1, 6, danmaku.dcolor.green, 0, 0, 36);
							}
							int kidou = 10;
							switch ((int)(teki[p].y)){
							case 287:
								kidou = 0;
								break;
							case 331:
								kidou = 5;
								break;
							case 375:
								kidou = -5;
								break;
							case 429:
								kidou = 0;
								break;
							}
							if (kidou != 10){
								danmaku.Setdanmaku_ChainRendan((int)(teki[p].x), (int)(teki[p].y), 3, danmaku.Getkakudo_Homing(teki[p].x, teki[p].y, j.x, j.y) + kidou, 1, danmaku.dcolor.green, 0, 1, 1);
							}
						}
						else{
							if (teki[p].tekishu == 1){
								if (teki[p].x > 211){
									tteki[p].fugou = 1;
									tteki[p].usef = 14;
								}
								if ((teki[p].x > 79 && teki[p].x < 82) || (teki[p].x > 145 && teki[p].x < 148)){
									danmaku.Setdanmaku_ChainRendan((int)(teki[p].x), (int)(teki[p].y), 3, danmaku.Getkakudo_Homing(teki[p].x, teki[p].y, j.x, j.y), 5, danmaku.dcolor.green, 0, 5, 3);
								}
								if (teki[p].x > 146 && teki[p].x < 278){
									teki[p].imgposi = 2;
								}
								else{
									teki[p].imgposi = 4;
								}
							}
							else{
								if (teki[p].x < 212){
									tteki[p].fugou = 1;
									tteki[p].usef = 13;
								}

								if ((teki[p].x > 276 && teki[p].x < 279) || (teki[p].x > 343 && teki[p].x < 346)){
									danmaku.Setdanmaku_ChainRendan((int)(teki[p].x), (int)(teki[p].y), 3, danmaku.Getkakudo_Homing(teki[p].x, teki[p].y, j.x, j.y), 5, danmaku.dcolor.green, 0, 5, 3);
								}
								if (teki[p].x > 146 && teki[p].x < 278){
									teki[p].imgposi = 1;
								}
								else{
									teki[p].imgposi = 3;
								}
							}
							teki[p].y = danmaku.GetY(teki[p].x, tteki[p].usef, tteki[p].kanshu, tteki[p].fugou);
						}
					}
					break;
				case 11://1:45～1:55
					if (p < 138){
						teki[p].x += teki[p].vecx;
						if (teki[p].tekishu == 2){
							teki[p].y += teki[p].vecy;
							if (teki[p].y > 199 && teki[p].vecx == 0){
								teki[p].vecy = 0.7375;
								if (teki[p].x > 212){
									teki[p].vecx = (20 - teki[p].x) / 240;
								}
								else{
									teki[p].vecx = (404 - teki[p].x) / 240;
								}
							}
						}
						else{
							if (teki[p].tekishu == 1){
								if (teki[p].x > 211){
									tteki[p].fugou = 1;
									tteki[p].usef = 14;
								}
								if (teki[p].x > 146 && teki[p].x < 278){
									teki[p].imgposi = 2;
								}
								else{
									teki[p].imgposi = 4;
								}
							}
							else{
								if (teki[p].x < 212){
									tteki[p].fugou = 1;
									tteki[p].usef = 13;
								}
								if (teki[p].x > 146 && teki[p].x < 278){
									teki[p].imgposi = 1;
								}
								else{
									teki[p].imgposi = 3;
								}
							}
							teki[p].y = danmaku.GetY(teki[p].x, tteki[p].usef, tteki[p].kanshu, tteki[p].fugou);
						}
					}
					else{
						teki[p].x += teki[p].vecx;
						if (teki[p].tekishu == 2){
							teki[p].y += teki[p].vecy;
							if (teki[p].y > 199 && teki[p].vecx == 0){
								teki[p].vecy = 0.7375;
								danmaku.Setdanmaku_Wave((int)(teki[p].x), (int)(teki[p].y), 1, 6,danmaku.dcolor.blue, 0, 0, 36);
								if (teki[p].x > 212){
									teki[p].vecx = (20 - teki[p].x) / 240;
									teki[p].imgposi = 1;
								}
								else{
									teki[p].vecx = (404 - teki[p].x) / 240;
									teki[p].imgposi = 2;
								}
							}
							int kidou = 10;
							switch ((int)(teki[p].y)){
							case 287:
								kidou = 0;
								break;
							case 331:
								kidou = 5;
								break;
							case 375:
								kidou = -5;
								break;
							case 429:
								kidou = 0;
								break;
							}
							if (kidou != 10){
								danmaku.Setdanmaku_ChainRendan((int)(teki[p].x), (int)(teki[p].y), 3, danmaku.Getkakudo_Homing(teki[p].x, teki[p].y, j.x, j.y) + kidou, 1, danmaku.dcolor.blue, 0, 1, 1);
							}
						}
						else{
							if (teki[p].tekishu == 1){
								if (teki[p].x > 211){
									tteki[p].fugou = 1;
									tteki[p].usef = 14;
								}
								if ((teki[p].x > 79 && teki[p].x < 82) || (teki[p].x > 145 && teki[p].x < 148)){
									danmaku.Setdanmaku_ChainRendan((int)(teki[p].x), (int)(teki[p].y), 3, danmaku.Getkakudo_Homing(teki[p].x, teki[p].y, j.x, j.y), 5, danmaku.dcolor.purple, 0, 5, 3);
								}
								if (teki[p].x > 146 && teki[p].x < 278){
									teki[p].imgposi = 2;
								}
								else{
									teki[p].imgposi = 4;
								}
							}
							else{
								if (teki[p].x < 212){
									tteki[p].fugou = 1;
									tteki[p].usef = 13;
								}
								if ((teki[p].x > 276 && teki[p].x < 279) || (teki[p].x > 343 && teki[p].x < 346)){
									danmaku.Setdanmaku_ChainRendan((int)(teki[p].x), (int)(teki[p].y), 3, danmaku.Getkakudo_Homing(teki[p].x, teki[p].y, j.x, j.y), 5, danmaku.dcolor.purple, 0, 5, 3);
								}
								if (teki[p].x > 146 && teki[p].x < 278){
									teki[p].imgposi = 1;
								}
								else{
									teki[p].imgposi = 3;
								}
							}
							teki[p].y = danmaku.GetY(teki[p].x, tteki[p].usef, tteki[p].kanshu, tteki[p].fugou);
						}
					}
					break;
				case 12://1:56～2:16
					if (p < 160){
						teki[p].x += teki[p].vecx;
						if (teki[p].tekishu == 2){
							teki[p].y += teki[p].vecy;
							if (teki[p].y > 199 && teki[p].vecx == 0){
								teki[p].y = 199;
								teki[p].vecy = 0.7375;
								danmaku.Setdanmaku_Wave((int)(teki[p].x), (int)(teki[p].y), 1, 6, danmaku.dcolor.blue, 0, 0, 36);
								if (teki[p].x > 212){
									teki[p].vecx = (20 - teki[p].x) / 240;
									teki[p].imgposi = 1;
								}
								else{
									teki[p].vecx = (404 - teki[p].x) / 240;
									teki[p].imgposi = 2;
								}
							}
							int kidou = 10;
							switch ((int)(teki[p].y)){
							case 287:
								kidou = 0;
								break;
							case 331:
								kidou = 5;
								break;
							case 375:
								kidou = -5;
								break;
							case 429:
								kidou = 0;
								break;
							}
							if (kidou != 10){
								danmaku.Setdanmaku_ChainRendan((int)(teki[p].x), (int)(teki[p].y), 3, danmaku.Getkakudo_Homing(teki[p].x, teki[p].y, j.x, j.y) + kidou, 1, danmaku.dcolor.blue, 0, 1, 1);
							}
						}
						else{
							if (teki[p].tekishu == 1){
								if (teki[p].x > 211){
									tteki[p].fugou = 1;
									tteki[p].usef = 14;
								}
								if (teki[p].x > 146 && teki[p].x < 278){
									teki[p].imgposi = 2;
								}
								else{
									teki[p].imgposi = 4;
								}
							}
							else{
								if (teki[p].x < 212){
									tteki[p].fugou = 1;
									tteki[p].usef = 13;
								}
								if (teki[p].x > 146 && teki[p].x < 278){
									teki[p].imgposi = 1;
								}
								else{
									teki[p].imgposi = 3;
								}
							}
							teki[p].y = danmaku.GetY(teki[p].x, tteki[p].usef, tteki[p].kanshu, tteki[p].fugou);
						}
					}
					else{
						teki[p].y += teki[p].vecy;
						switch (teki[p].tekishu){
						case 2:
							teki[p].x = danmaku.GetX(teki[p].y, tteki[p].usef, tteki[p].kanshu, tteki[p].fugou);
							if (teki[p].y <= 243 && tteki[p].usef == 10){
								tteki[p].usef = 9;
								tteki[p].fugou *= -1;
							}
							if ((int)(teki[p].y) >= 287 && (int)(teki[p].y) < 289){
								danmaku.Setdanmaku_ChainRendan((int)(teki[p].x), (int)(teki[p].y), 3, danmaku.Getkakudo_Homing(teki[p].x, teki[p].y, j.x, j.y) + 15, 1, danmaku.dcolor.orange, 0, 7, 12);
								danmaku.Setdanmaku_ChainRendan((int)(teki[p].x), (int)(teki[p].y), 3, danmaku.Getkakudo_Homing(teki[p].x, teki[p].y, j.x, j.y) - 15, 1, danmaku.dcolor.orange, 0, 7, 12);
							}
							break;
						case 5:
							if (p == 159){
								if ((int)(teki[p].y - 67) % 22 == 0){
									danmaku.Setdanmaku_Wave((int)(teki[p].x), (int)(teki[p].y), 2, 4, danmaku.dcolor.orange, 0, (int)(teki[p].y - 67) / 22 * 7, 12);
								}
							}
							else{
								if (teki[179].hitpoint == -100 && anotherspeedup == false){
									anotherspeedup = true;
									teki[180].vecy *= 2;
								}
								if (teki[180].hitpoint == -100 && anotherspeedup == false){
									anotherspeedup = true;
									teki[179].vecy *= 2;
								}
								if ((int)(teki[p].y - 67) % 88 == 0){
									danmaku.Setdanmaku_Wave((int)(teki[p].x), (int)(teki[p].y), 2, 7, danmaku.dcolor.orange, 0, 0, 15);
								}
							}
							break;
						case 6:
							teki[p].x = danmaku.GetX(teki[p].y, tteki[p].usef, tteki[p].kanshu, tteki[p].fugou);
							/*if (teki[p].y > 243 && (flame - teki[p].start) % 60 == 0){
								if (tteki[p].usef == 5){
									danmaku.Setdanmaku_ChainRendan((int)(teki[p].x), (int)(teki[p].y), 3, danmaku.Getkakudo_Homing(teki[p].x, teki[p].y, j.x, j.y) + 10, 1, 0, 0, 0,1, 1);
								}
								else{
									danmaku.Setdanmaku_ChainRendan((int)(teki[p].x), (int)(teki[p].y), 3, danmaku.Getkakudo_Homing(teki[p].x, teki[p].y, j.x, j.y), 1, 0, 0, 0,1, 1);
								}
							}*/
							break;
						}
					}
					break;
				case 17://    ～3:17
					teki[p].x += teki[p].vecx;
					teki[p].y = danmaku.GetY(teki[p].x, tteki[p].usef, tteki[p].kanshu, tteki[p].fugou);
					if (teki[p].tekishu == 2){
						//青妖精
						if (((int)(teki[p].x) - 80) % 132 == 0){
							danmaku.Setdanmaku_Wave((int)(teki[p].x), (int)(teki[p].y), 2, 4, danmaku.dcolor.blue, 0, ((int)(teki[p].x) - 80) / 132 * 4, 30);
						}
					}
					else{
						//赤妖精
						if ((int)(teki[p].x) == 146){
							danmaku.Setdanmaku_ArrowRendan((int)(teki[p].x), (int)(teki[p].y), danmaku.Getkakudo_Homing(teki[p].x - 10, teki[p].y, j.x, j.y), 5, danmaku.dcolor.red, 0, 7, 5, 0.1);
						}
						if ((int)(teki[p].x) == 275){
							danmaku.Setdanmaku_ArrowRendan((int)(teki[p].x), (int)(teki[p].y), danmaku.Getkakudo_Homing(teki[p].x + 10, teki[p].y, j.x, j.y), 5, danmaku.dcolor.red, 0, 7, 5, 0.1);
						}
					}
					break;
				case 18://3:18～3:40
					switch (teki[p].tekishu){
					case 2://青妖精
						teki[p].x += teki[p].vecx;
						teki[p].y += teki[p].vecy;
						if ((int)(teki[p].y - 79) % 66 == 0){
							if ((int)(teki[p].y - 79) % 132 == 0){
								danmaku.Setdanmaku_Ko((int)(teki[p].x), (int)(teki[p].y), 1, 6, danmaku.dcolor.purple, 0, 45, 135, 6);
							}
							else{
								danmaku.Setdanmaku_Ko((int)(teki[p].x), (int)(teki[p].y), 1, 6, danmaku.dcolor.purple, 0, 45, 135, 3);
							}
						}
						break;
					case 1://赤妖精
						if (teki[p].vecx > 0){
							if (teki[p].x > 211 && tteki[p].usef != 14){
								tteki[p].fugou = 1;
								tteki[p].usef = 14;
								danmaku.Setdanmaku_ArrowRendan((int)(teki[p].x), (int)(teki[p].y), danmaku.Getkakudo_Homing(teki[p].x, teki[p].y, j.x, j.y), 14, danmaku.dcolor.purple, 0, 3, 6, 1.5);
							}
							if (teki[p].x > 146 && teki[p].x < 278){
								teki[p].imgposi = 2;
							}
							else{
								teki[p].imgposi = 4;
							}
						}
						else{
							if (teki[p].x < 212 && tteki[p].usef != 13){
								tteki[p].fugou = 1;
								tteki[p].usef = 13;
								danmaku.Setdanmaku_ArrowRendan((int)(teki[p].x), (int)(teki[p].y), danmaku.Getkakudo_Homing(teki[p].x, teki[p].y, j.x, j.y), 14, danmaku.dcolor.purple, 0, 3, 6, 1.5);
							}
							if (teki[p].x > 146 && teki[p].x < 278){
								teki[p].imgposi = 1;
							}
							else{
								teki[p].imgposi = 3;
							}
						}
						teki[p].x += teki[p].vecx;
						teki[p].y = danmaku.GetY(teki[p].x, tteki[p].usef, tteki[p].kanshu, tteki[p].fugou);
						break;
					case 5://ひまわり妖精
						teki[p].y += teki[p].vecy;
						if (teki[p].start == -1){
							teki[p].start = flame;
						}
						if (teki[p].start == 13){
							teki[p].vecy = 0;
						}
						if(teki[p].start - flame == 73){
							teki[p].vecy = (double)(465 - 111) / 540;
							danmaku.Setdanmaku_Wave((int)(teki[p].x), (int)(teki[p].y), 2, 4, danmaku.dcolor.purple, 0, danmaku.Getkakudo_Homing(teki[p].x, teki[p].y, j.x, j.y), 60);
						}
						break;
					}
					break;

				}
			}
			else{
				teki[p].ready -= 1;
				if (teki[p].ready == 0){
					teki[p].start = flame;
				}
			}
			p = teki[p].np;
		}
		if (tekicount > 0){
			if (PasteDot() != 0){ r = -1; }
		}
		if ((tekicount == 0 && (scene == 17 || scene == 18)) || scene == 9 && Currenttime > 93){
				scene++;
			}
		
		if (danmaku.dancount > 0){
			if (danmaku.ProcessDanmaku(flame, scene) != 0){ r = -1; }
		}
		if (r == -1){
			r = -1;
		}
		return r;
	};
	bool Stage3::ProcessYuuka(int flame){
		bool rr = true;
		int r = 0;
		prescene = scene;
		if (flame == 1){
			Bosstime--;
		}//一秒経過ごとに加算。
		SetDrawArea(20, 15, 404, 465);
		if (scene != 0){
			switch (scene){
			case 19://トーク
				/*
					 
																				 */
				switch (Talkcount){
				case 24:
					BossStandPosition = -1;
					JikiStandPosition = 1;
					selif1 = "さて、おもむくままにここに";
					selif2 = "辿りついたが";
					break;
				case 23:
					if (PlayerData.jikinum == 1){
						selif1 = "やはり留守のようだね。";
						selif2 = "";
					}
					else{
						BossStandPosition = -1;
						JikiStandPosition = 1;
						selif1 = "先ほどの猫さんも言っていましたけど";
						selif2 = "";
					}
					break;
				case 22:
					if (PlayerData.jikinum == 1){
						selif1 = "あら？";
						selif2 = "";
						Shadowflg = 0;
						yuuka.x = -92;
						yuuka.y = -92;
						yuuka.vecx = (208 + 92) / 60;
						yuuka.vecy = (100 + 92) / 60;
						yuuka.imgpoji = 0;
					}
					else{
						selif1 = "やっぱりいないみたいですね。予想通り。";
						selif2 = "";
					}
					break;
				case 21:
					if (PlayerData.jikinum == 1){
						selif1 = "これはまた、見ない顔ね";
						selif2 = "";
						BossStandPosition = 2;
					}
					else{
						JikiStandPosition = 2;
						selif1 = "いい気はしませんが、ここは私が頂く";
						selif2 = "としましょう。";
					}
					break;
				case 20:
					if (PlayerData.jikinum == 1){
						selif1 = "こちらこそ、初めまして。";
						selif2 = "";
						Shadowflg = 1;
						JikiStandPosition = 2;
					}
					else{
						Shadowflg = 0;
						selif1 = "あら？それなら…";
						selif2 = "";
						yuuka.x = -92;
						yuuka.y = -92;
						yuuka.vecx = (208 + 92) / 60;
						yuuka.vecy = (100 + 92) / 60;
						yuuka.imgpoji = DotAct.right;
					}
					break;
				case 19:
					if (PlayerData.jikinum == 1){
						selif1 = "・・・";
						BossStandPosition = 1;
						Shadowflg = 0;
					}
					else{
						BossStandPosition = 1;
						selif1 = "私にも分けてもらえるかしら？";
						selif2 = "";
						
					}
					break;
				case 18:
					if (PlayerData.jikinum == 1){
						selif1 = "・・・";
						Shadowflg = 1;
					}
					else{
						JikiStandPosition = 1;
						Shadowflg = 1;
						selif1 = "あ、どうも。";
						selif2 = "";
					}
					break;
				case 17:
					if (PlayerData.jikinum == 1){
						selif1 = "何しに来たの、こんな時に。";
						selif2 = "";
						Shadowflg = 0;
						BossStandPosition = 4;

					}
					else{
						JikiStandPosition = 3;
						selif1 = "（あの人って妖怪だよね？どうして…）";
						selif2 = "";
					}
					break;
				case 16:
					if (PlayerData.jikinum == 1){
						selif1 = "おやおや、随分な歓迎じゃないか";
						selif2 = "代理人がわざわざ来たってのに。";
						Shadowflg = 1;
					}
					else{
						Shadowflg = 0;
						BossStandPosition = StandAct.fine;
						selif1 = "手持ちの日傘もないし、着慣れない服";
						selif2 = "を着続けるのも癪でね…。";
					}
					break;
				case 15:
					if (PlayerData.jikinum == 1){
						selif1 = "代理人？";
						selif2 = "";
						Shadowflg = 0;
					}
					else{
						BossStandPosition = StandAct.common;
						selif1 = "仕方ないから私自ら動いてるの。";
						selif2 = "";
					}
					break;
				case 14:
					if (PlayerData.jikinum == 1){
						selif1 = "ちょうどあの二人もいないし、";
						selif2 = "私が異変解決してみようとね。";
						Shadowflg = 1;
						JikiStandPosition = 1;
					}
					else{
						Shadowflg = 1;
						JikiStandPosition = StandAct.fine;
						selif1 = "まぁそうですよね。それにあの二人も";
						selif2 = "異変解決に動いてないみたいですし。";
					}
					break;
				case 13:
					if (PlayerData.jikinum == 1){
						selif1 = "あんたなんかに事を丸くおさめる";
						selif2 = "能なんてあるのかしら？";
						Shadowflg = 0;
						BossStandPosition = 2;
					}
					else{
						Shadowflg = 0;
						BossStandPosition = StandAct.fine;
						selif1 = "こうは考えられないかしら？";
						selif2 = "”ミイラ取りがミイラになった”と。";
					}
					break;
				case 12:
					if (PlayerData.jikinum == 1){
						selif1 = "ほう？";
						selif2 = "";
						Shadowflg = 1;
						JikiStandPosition = 3;
					}
					else{
						Shadowflg = 1;
						JikiStandPosition = StandAct.question;
						selif1 = "今回の異変に巻き込まれたって";
						selif2 = "言うんですか？";
					}
					break;
				case 11:
					if (PlayerData.jikinum == 1){
						selif1 = "流れに乗じて大暴れしたいだけじゃ";
						selif2 = "ないの？私と同じように。";
						BossStandPosition = 1;
						Shadowflg = 0;
					}
					else{
						Shadowflg = 0;
						BossStandPosition = StandAct.common;
						selif1 = "その方が自然でしょう、この私が";
						selif2 = "腰を上げざるをえないのだから。";
					}
					break;
				case 10:
					if (PlayerData.jikinum == 1){
						selif1 = "一緒にするな。暴れているが。";
						selif2 = "";
						Shadowflg = 1;
						JikiStandPosition = 8;
					}
					else{
						selif1 = "こればっかりは一筋縄でいかないよ。";
						selif2 = "";
					}
					break;
				case 9:
					if (PlayerData.jikinum == 1){
						selif1 = "うたかたの悪霊には引っ込んでて";
						selif2 = "もらえるかしら？ここは幻想郷よ。";
						BossStandPosition = 2;
						Shadowflg = 0;
					}
					else{
						Shadowflg = 1;
						JikiStandPosition = StandAct.common;
						selif1 = "う～ん、そうなのかなぁ。ところで";
						selif2 = "";
					}
					break;
				case 8:
					if (PlayerData.jikinum == 1){
						selif1 = "ここでは、人間に襲いかかる妖怪は";
						selif2 = "退治してもいいんだよな。";
						JikiStandPosition = 2;
						Shadowflg = 1;
					}
					else{
						JikiStandPosition = StandAct.question;
						selif1 = "その事情をどうして私に？一人で解決";
						selif2 = "することが多いのですが。";
					}
					break;
				case 7:
					if (PlayerData.jikinum == 1){
						selif1 = "異変を大きくする猪口才は";
						selif2 = "どうなってもいいわ。";
						Shadowflg = 0;
					}
					else{
						Shadowflg = 0;
						BossStandPosition = StandAct.fine;
						selif1 = "一人より二人三人いた方がスムーズに";
						selif2 = "異変解決できるじゃない。";
					}
					break;
				case 6:
					if (PlayerData.jikinum == 1){
						selif1 = "いい覚悟だ…。それでは早速";
						selif2 = "";
						Shadowflg = 1;
					}
					else{
						BossStandPosition = StandAct.excited;
						selif1 = "あんたでも少しぐらいは役に立つと";
						selif2 = "思ったのよ。";
					}
					break;
				case 5:
					if (PlayerData.jikinum == 1){
						selif1 = "異変解決の妨げとなる者は誰であろうと";
						selif2 = "容赦はしない。";
						JikiStandPosition = 1;
					}
					else{
						Shadowflg = 1;
						 JikiStandPosition = StandAct.fine;
						selif1 = "共闘のお誘いですか。しかし…";
						selif2 = "";
					}
					break;
				case 4:
					if (PlayerData.jikinum == 1){
						selif1 = "ここで私に倒されるのがあんたの役目だ。";
						selif2 = "";
						Shadowflg = 1;
						JikiStandPosition = 8;
					}
					else{
						Shadowflg = 1;
						JikiStandPosition = 2;
						selif1 = "残念ですが、お断りいたします。";
						selif2 = "私は私のやり方で行くので。";
					}
					break;
				case 3:
					if (PlayerData.jikinum == 1){
						selif1 = "久々に骨のある戦いになりそうね。";
						selif2 = "";
						Shadowflg = 0;
						BossStandPosition = 1;
					}
					else{
						Shadowflg = 0;
						BossStandPosition = StandAct.doubt;
						selif1 = "あら、それはそれは。仕方ないわね。";
						selif2 = "";
					}
					break;
				case 2:
					if (PlayerData.jikinum == 1){
						selif1 = "こんな場所だけど、誰もいないし";
						selif2 = "どうなってもいいわよね。";
					}
					else{
						Shadowflg = 1;
						JikiStandPosition = StandAct.strategy;
						selif1 = "気づかぬうちにあなたも異変に";
						selif2 = "巻き込まれているのですよ！";
					}
					break;
				case 1:
					if (PlayerData.jikinum == 1){
						selif1 = "どうでもいいよ。私が手を下すのだから";
						selif2 = "ありがたく思うことね。";
						JikiStandPosition = 2;
						Shadowflg = 1;
					}
					else{
						JikiStandPosition = 1;
						selif1 = "誰かに相談する前に、まずは";
						selif2 = "自分の頭を冷やしてください。";
					}
					break;
				}
				if ((PlayerData.jikinum == 1 && Talkcount < 22) || (PlayerData.jikinum == 2 && Talkcount < 20)){
					if (yuuka.x < 208){
						yuuka.x += yuuka.vecx;
						yuuka.y += yuuka.vecy;
						yuuka.imgpoji = DotAct.right;
					}
					else{
						yuuka.x = 208;
						yuuka.y = 100;
						yuuka.imgpoji = DotAct.common;
					}
					if (j.slow > 0){
						yuuka.x = 208;
						yuuka.y = 100;
						yuuka.imgpoji = DotAct.common;
					}
					DrawGraph((int)(yuuka.x - 30), (int)(yuuka.y - 45), yuukadot[yuuka.imgpoji], true);
				}
				int bossy, jikiy;
				if (PlayerData.jikinum == 2){
					jikicolor = GetColor(150, 150, 255);
					bossy = 195;
					jikiy = 225;
					
				}
				else{
					jikicolor = GetColor(220, 220, 100);
					bossy = 210;
					jikiy = 215;
				}
				if (BossStandPosition == -1){
					BossTalking(0, GetColor(80, 255, 80), jikicolor, 170, bossy, jikiy,0);
				}
				else{
					BossTalking(yuukastand[BossStandPosition], GetColor(80, 255, 80), jikicolor, 170, bossy, jikiy, 0);
				}
				
				break;
			case 20://通常1
				DrawGraph((int)(yuuka.x - 30), (int)(yuuka.y - 45), yuukadot[yuuka.imgpoji], true);
				if (Currenttime > 0){
					timetoflame = ((Currenttime - 1) % Looptime) * 60 + flame;
					switch (timetoflame){
					case 1:
						danmaku.Setdanmaku_ArrowRendan((int)(yuuka.x), (int)(yuuka.y), 20, danmaku.dshu.ring, danmaku.dcolor.green, 0, 25, 5, 0.5);
						danmaku.Setdanmaku_ArrowRendan((int)(yuuka.x), (int)(yuuka.y), 70, danmaku.dshu.ring, danmaku.dcolor.green, 0, 25, 5, 0.5);
						danmaku.Setdanmaku_ArrowRendan((int)(yuuka.x), (int)(yuuka.y), 110, danmaku.dshu.ring, danmaku.dcolor.green, 0, 25, 5, 0.5);
						danmaku.Setdanmaku_ArrowRendan((int)(yuuka.x), (int)(yuuka.y), 160, danmaku.dshu.ring, danmaku.dcolor.green, 0, 25, 5, 0.5);
						break;
					case 80:
						danmaku.Setdanmaku_Wave(254, 117, 2.2, danmaku.dshu.kome, danmaku.dcolor.red, 0, 0, 5);
						danmaku.Setdanmaku_Wave(162, 117, 2.2, danmaku.dshu.kome, danmaku.dcolor.red, 0, 0, 5);
						danmaku.Setdanmaku_Wave(228, 156, 2.2, danmaku.dshu.kome, danmaku.dcolor.red, 0, 0, 5);
						danmaku.Setdanmaku_Wave(188, 156, 2.2, danmaku.dshu.kome, danmaku.dcolor.red, 0, 0, 5);
						break;
					case 122:
						danmaku.Setdanmaku_Wave(301, 134, 2.2, danmaku.dshu.kome, danmaku.dcolor.orange, 0, 10, 5);
						danmaku.Setdanmaku_Wave(115, 134, 2.2, danmaku.dshu.kome, danmaku.dcolor.orange, 0, 10, 5);
						danmaku.Setdanmaku_Wave(249, 212, 2.2, danmaku.dshu.kome, danmaku.dcolor.orange, 0, 10, 5);
						danmaku.Setdanmaku_Wave(167, 212, 2.2, danmaku.dshu.kome, danmaku.dcolor.orange, 0, 10, 5);
						break;
					case 164:
						danmaku.Setdanmaku_Wave(348, 151, 2.2, danmaku.dshu.kome, danmaku.dcolor.yellow, 0, 20, 5);
						danmaku.Setdanmaku_Wave(68, 151, 2.2, danmaku.dshu.kome, danmaku.dcolor.yellow, 0, 20, 5);
						danmaku.Setdanmaku_Wave(269, 269, 2.2, danmaku.dshu.kome, danmaku.dcolor.yellow, 0, 20, 5);
						danmaku.Setdanmaku_Wave(147, 269, 2.2, danmaku.dshu.kome, danmaku.dcolor.yellow, 0, 20, 5);
						break;
					case 206:
						danmaku.Setdanmaku_Wave(290, 325, 2.2, danmaku.dshu.kome, danmaku.dcolor.water, 0, 20, 5);
						danmaku.Setdanmaku_Wave(126, 325, 2.2, danmaku.dshu.kome, danmaku.dcolor.water, 0, 20, 5);
						break;
					case 260:
						danmaku.Setdanmaku_Wave(310, 381, 2.2, danmaku.dshu.kome, danmaku.dcolor.purple, 0, 20, 5);
						danmaku.Setdanmaku_Wave(106, 381, 2.2, danmaku.dshu.kome, danmaku.dcolor.purple, 0, 20, 5);
						break;
					case 331:
						danmaku.Setdanmaku_Wave(0, 0, 1.5, danmaku.dshu.middle, danmaku.dcolor.yellow, 0, 0, 40, danmaku.worder.crossround, 0.3);
						break;
					case 391:
						danmaku.Setdanmaku_Wave(0, 0, 1.5, danmaku.dshu.middle, danmaku.dcolor.yellow, 0, 0, 40, danmaku.worder.crossround, 0.3);
						break;
					}
				}
				break;
			case 21://スペルカード　1枚目
				DrawGraph((int)(yuuka.x - 30), (int)(yuuka.y - 45), yuukadot[yuuka.imgpoji], true);
				if (Currenttime < 3){
					EndSpellkardEffect(300000, 0);
					StartSpellkardEffect(yuukastand[2]);
					appeary += 1;
				}
				else
				{
					
					timetoflame = ((Currenttime - 3) % Looptime) * 60 + flame;
					int rx, ry;
					switch (timetoflame){
					case 1:
						danmaku.ClearDanmaku();
						break;
					case 61:
						rx = GetRand(160) + 50;
						ry = GetRand(160) + 110;
						danmaku.Setdanmaku_Wave(rx,ry, 1, danmaku.dshu.uroko, danmaku.dcolor.yellow, 30, 0, 12);
						danmaku.Setdanmaku_Wave(rx, ry, 0.5, danmaku.dshu.uroko, danmaku.dcolor.orange, 30, 7, 12);
						danmaku.Setdanmaku_Wave(rx, ry, 0.1, danmaku.dshu.middle, danmaku.dcolor.red, 30, danmaku.Getkakudo_Homing(rx, ry, j.x, j.y), 20);
						break;
					case 121:
						rx = GetRand(160) + 210;
						ry = GetRand(160) + 110;
						danmaku.Setdanmaku_Wave(rx, ry, 1, danmaku.dshu.uroko, danmaku.dcolor.yellow, 30, 0, 12);
						danmaku.Setdanmaku_Wave(rx, ry, 0.5, danmaku.dshu.uroko, danmaku.dcolor.orange, 30, 7, 12);
						danmaku.Setdanmaku_Wave(rx, ry, 0.1, danmaku.dshu.middle, danmaku.dcolor.red, 30, danmaku.Getkakudo_Homing(rx, ry, j.x,j.y), 20);
						break;
					case 181:
						rx = GetRand(160) + 50;
						ry = GetRand(160) + 270;
						danmaku.Setdanmaku_Wave(rx, ry, 1, danmaku.dshu.uroko, danmaku.dcolor.yellow, 30, 0, 12);
						danmaku.Setdanmaku_Wave(rx, ry, 0.5, danmaku.dshu.uroko, danmaku.dcolor.orange, 30, 7, 12);
						danmaku.Setdanmaku_Wave(rx, ry, 0.1, danmaku.dshu.middle, danmaku.dcolor.red, 30, danmaku.Getkakudo_Homing(rx, ry, j.x, j.y), 20);
						break;
					case 241:
						rx = GetRand(160) + 210;
						ry = GetRand(160) + 270;
						danmaku.Setdanmaku_Wave(rx, ry, 1, danmaku.dshu.uroko, danmaku.dcolor.yellow, 30, 0, 12);
						danmaku.Setdanmaku_Wave(rx, ry, 0.5, danmaku.dshu.uroko, danmaku.dcolor.orange, 30, 7, 12);
						danmaku.Setdanmaku_Wave(rx, ry, 0.1, danmaku.dshu.middle, danmaku.dcolor.red, 30, danmaku.Getkakudo_Homing(rx, ry, j.x, j.y), 20);
						break;
					case 361:
						Bosshit = true;
						rx = GetRand(320) + 50;
						ry = GetRand(320) + 110;
						while (sqrt(pow(j.x - rx,2.0)+ pow(j.y - ry,2.0)) < 150)
						{
							rx = GetRand(320) + 50;
							ry = GetRand(320) + 110;
						}
						danmaku.Setdanmaku_Wave(rx, ry, 2, danmaku.dshu.uroko, danmaku.dcolor.pink, 30, 0, 24);
						danmaku.Setdanmaku_Wave(rx, ry, 1, danmaku.dshu.uroko, danmaku.dcolor.purple, 30, 7, 24);
						danmaku.Setdanmaku_Wave(rx, ry, 0.2, danmaku.dshu.middle, danmaku.dcolor.blue, 30, danmaku.Getkakudo_Homing(rx, ry, j.x, j.y), 30);
						break;
					case 451:
						rx = GetRand(320) + 50;
						ry = GetRand(320) + 110;
						while (sqrt(pow(j.x - rx, 2.0) + pow(j.y - ry, 2.0)) < 150){
							rx = GetRand(320) + 50;
							ry = GetRand(320) + 110;
						}
						danmaku.Setdanmaku_Wave(rx, ry, 2, danmaku.dshu.uroko, danmaku.dcolor.pink, 30, 0, 24);
						danmaku.Setdanmaku_Wave(rx, ry, 1, danmaku.dshu.uroko, danmaku.dcolor.purple, 30, 7, 24);
						danmaku.Setdanmaku_Wave(rx, ry, 0.2, danmaku.dshu.middle, danmaku.dcolor.blue, 30, danmaku.Getkakudo_Homing(rx, ry, j.x, j.y), 30);
						break;
					case 541:
						rx = GetRand(320) + 50;
						ry = GetRand(320) + 110;
						while (sqrt(pow(j.x - rx, 2.0) + pow(j.y - ry, 2.0)) < 150){
							rx = GetRand(320) + 50;
							ry = GetRand(320) + 110;
						}
						danmaku.Setdanmaku_Wave(rx, ry, 2, danmaku.dshu.uroko, danmaku.dcolor.pink, 30, 0, 24);
						danmaku.Setdanmaku_Wave(rx, ry, 1, danmaku.dshu.uroko, danmaku.dcolor.purple, 30, 7, 24);
						danmaku.Setdanmaku_Wave(rx, ry, 0.2, danmaku.dshu.middle, danmaku.dcolor.blue, 30, danmaku.Getkakudo_Homing(rx, ry, j.x, j.y), 30);
						break;
					case 661:
						danmaku.Setdanmaku_Ko(120, 465, 0.5, danmaku.dshu.mayu, danmaku.dcolor.water, 0, 180, 360, 10);
						danmaku.Setdanmaku_Ko(180, 465, 0.5, danmaku.dshu.mayu, danmaku.dcolor.water, 0, 180, 360, 10);
						danmaku.Setdanmaku_Ko(240, 465, 0.5, danmaku.dshu.mayu, danmaku.dcolor.water, 0, 180, 360, 10);
						danmaku.Setdanmaku_Ko(300, 465, 0.5, danmaku.dshu.mayu, danmaku.dcolor.water, 0, 180, 360, 10);
						danmaku.Setdanmaku_Ko(360, 465, 0.5, danmaku.dshu.mayu, danmaku.dcolor.water, 0, 180, 360, 10);
						break;
					}
				}
				break;
			case 22://スペルカード　2枚目
				if (yuuka.x == 208){
					DrawGraph((int)(yuuka.x - 30), (int)(yuuka.y - 45), yuukadot[yuuka.imgpoji], true);
				}

				if (Currenttime < 3){
					EndSpellkardEffect(300000, PreBonusScore);
					StartSpellkardEffect( yuukastand[1]);
					appeary += 1;
					yuuka.vecx = 0;
				}
				else
				{
					timetoflame = ((Currenttime - 3) % Looptime) * 60 + flame;
					switch (timetoflame){
					case 1:
						if (yuuka.x < j.x){
							yuuka.vecx = (double)(52 - 208) / 120;
						}else{
							yuuka.vecx = (double)(364 - 208) / 120;
						}
						break;
					case 61:
						danmaku.Setdanmaku_Wave(140, 100, 1.5, danmaku.dshu.uroko, danmaku.dcolor.green, 0, danmaku.Getkakudo_Homing(140, 100, j.x, j.y), 40);
						danmaku.Setdanmaku_Wave(286, 100, 0.5, danmaku.dshu.middle, danmaku.dcolor.green, 0, danmaku.Getkakudo_Homing(140, 100, j.x, j.y) + 20, 20);
						danmaku.Setdanmaku_Wave(286, 100, 1.5, danmaku.dshu.uroko, danmaku.dcolor.green, 0, danmaku.Getkakudo_Homing(140, 100, j.x, j.y), 40);
						danmaku.Setdanmaku_Wave(140, 100, 0.5, danmaku.dshu.middle, danmaku.dcolor.green, 0, danmaku.Getkakudo_Homing(140, 100, j.x, j.y) + 20, 20);
						break;
					case 121:
						yuuka.vecx = 0;
						Bosshit = true;
						danmaku.Setdanmaku_Wave(52, 100, 1.5, danmaku.dshu.uroko, danmaku.dcolor.green, 0, danmaku.Getkakudo_Homing(140, 100, j.x, j.y), 40);
						danmaku.Setdanmaku_Wave(364, 100, 0.5, danmaku.dshu.middle, danmaku.dcolor.green, 0, danmaku.Getkakudo_Homing(140, 100, j.x, j.y) + 20, 20);
						danmaku.Setdanmaku_Wave(364, 100, 1.5, danmaku.dshu.uroko, danmaku.dcolor.green, 0, danmaku.Getkakudo_Homing(140, 100, j.x, j.y), 40);
						danmaku.Setdanmaku_Wave(52, 100, 0.5, danmaku.dshu.middle, danmaku.dcolor.green, 0, danmaku.Getkakudo_Homing(140, 100, j.x, j.y) + 20, 20);
						break;
					case 241:
						yuuka.vecx = (double)(208 - yuuka.x) / 120;
						break;
					case 271:
						danmaku.Setdanmaku_ChainRendan((int)(yuuka.x), (int)(yuuka.y), 3, danmaku.Getkakudo_Homing((int)(yuuka.x), (int)(yuuka.y), j.x, j.y), danmaku.dshu.large, danmaku.dcolor.green, 0, 13, 10);
						break;
					case 301:
						danmaku.Setdanmaku_ChainRendan((int)(yuuka.x), (int)(yuuka.y), 3, danmaku.Getkakudo_Homing((int)(yuuka.x), (int)(yuuka.y), j.x, j.y), danmaku.dshu.large, danmaku.dcolor.green, 0, 13, 10);
						break;
					case 331:
						danmaku.Setdanmaku_ChainRendan((int)(yuuka.x), (int)(yuuka.y), 3, danmaku.Getkakudo_Homing((int)(yuuka.x), (int)(yuuka.y), j.x, j.y), danmaku.dshu.large, danmaku.dcolor.green, 0, 13, 10);
						break;
					case 361:
						yuuka.vecx = 0;
						yuuka.x = 208;
						danmaku.Setdanmaku_Wave(208, 100, 1, danmaku.dshu.tubu, danmaku.dcolor.yellow, 0, 0, 24, danmaku.worder.crossround, 0.2);
						danmaku.Setdanmaku_Wave(208, 100, 2, danmaku.dshu.tubu, danmaku.dcolor.yellow, 0, 0, 20, danmaku.worder.crossround, 0.2);

						break;
					}
					yuuka.x += yuuka.vecx;
				}
				break;
			case 23://通常2
				DrawGraph((int)(yuuka.x - 30), (int)(yuuka.y - 45), yuukadot[yuuka.imgpoji], true);
				if (Currenttime < 8){
					Bosshit = false;
				}
				else{
					Bosshit = true;
				}
				if (Currenttime < 3){
					EndSpellkardEffect(300000, SpellBonusScore);
					yuuka.x += yuuka.vecx;
					if ((yuuka.vecx > 0 && yuuka.x > 208) || (yuuka.vecx < 0 && yuuka.x < 208)){
						yuuka.x = 208;
						yuuka.vecx = 0;
					}
				}
				else
				{
					
					timetoflame = ((Currenttime - 3) % Looptime) * 60 + flame;
					switch (timetoflame){
					case 1:
						yuuka.vecx = (double)(268 - yuuka.x) / 60;
						yuuka.vecy = (double)(220 - yuuka.y) / 60;
						yuuka.imgpoji = DotAct.right;
						danmaku.Setdanmaku_Wave((int)(yuuka.x), (int)(yuuka.y), 1.5, danmaku.dshu.large, danmaku.dcolor.red, 0, 0, 20);
						break;
					case 21:
						danmaku.Setdanmaku_Wave((int)(yuuka.x), (int)(yuuka.y), 1.5, danmaku.dshu.large, danmaku.dcolor.red, 0, 13, 20);
						break;
					case 41:
						danmaku.Setdanmaku_Wave((int)(yuuka.x), (int)(yuuka.y), 1.5, danmaku.dshu.large, danmaku.dcolor.red, 0, 26, 20);
						break;
					case 61:
						yuuka.vecx = (double)(148 - yuuka.x) / 60;
						yuuka.vecy = 0;
						yuuka.imgpoji = DotAct.left;
						danmaku.Setdanmaku_Wave((int)(yuuka.x), (int)(yuuka.y), 1.5, danmaku.dshu.large, danmaku.dcolor.red, 0, 39, 20);
						break;
					case 81:
						danmaku.Setdanmaku_Wave((int)(yuuka.x), (int)(yuuka.y), 1.5, danmaku.dshu.large, danmaku.dcolor.red, 0, 52, 20);
						break;
					case 101:
						danmaku.Setdanmaku_Wave((int)(yuuka.x), (int)(yuuka.y), 1.5, danmaku.dshu.large, danmaku.dcolor.red, 0, 65, 20);
						break;
					case 121:
						danmaku.Setdanmaku_Wave((int)(yuuka.x), (int)(yuuka.y), 1.5, danmaku.dshu.large, danmaku.dcolor.red, 0, 78, 20);
						yuuka.vecx = (double)(208 - yuuka.x) / 60;
						yuuka.vecy = (double)(100 - yuuka.y) / 60;
						yuuka.imgpoji = DotAct.right;
						break;
					case 141:
						danmaku.Setdanmaku_Wave((int)(yuuka.x), (int)(yuuka.y), 1.5, danmaku.dshu.large, danmaku.dcolor.red, 0, 91, 20);
						break;
					case 161:
						danmaku.Setdanmaku_Wave((int)(yuuka.x), (int)(yuuka.y), 1.5, danmaku.dshu.large, danmaku.dcolor.red, 0, 104, 20);
						break;
					case 181:
						danmaku.Setdanmaku_Wave((int)(yuuka.x), (int)(yuuka.y), 1.5, danmaku.dshu.large, danmaku.dcolor.red, 0, 117, 20);
						yuuka.vecx = 0;
						yuuka.vecy = 0;
						yuuka.imgpoji = DotAct.common;
						break;
					case 330:
						danmaku.Setdanmaku_Wave((int)(yuuka.x), (int)(yuuka.y), 2, danmaku.dshu.middle, danmaku.dcolor.purple, 0, 0, 18);
						break;
					case 360:
						danmaku.Setdanmaku_Wave((int)(yuuka.x), (int)(yuuka.y), 2, danmaku.dshu.middle, danmaku.dcolor.purple, 0, 24, 18);
						break;
					case 390:
						danmaku.Setdanmaku_Wave((int)(yuuka.x), (int)(yuuka.y), 2, danmaku.dshu.middle, danmaku.dcolor.purple, 0, 48, 18);
						break;
					case 420:
						danmaku.Setdanmaku_Wave((int)(yuuka.x), (int)(yuuka.y), 2, danmaku.dshu.middle, danmaku.dcolor.purple, 0, 72, 18);
						break;
					case 450:
						danmaku.Setdanmaku_Wave((int)(yuuka.x), (int)(yuuka.y), 2, danmaku.dshu.middle, danmaku.dcolor.purple, 0, 96, 18);
						break;
					case 510:
						danmaku.Setdanmaku_Wave((int)(yuuka.x), (int)(yuuka.y), 1, danmaku.dshu.ring, danmaku.dcolor.purple, 0, 0, 18,danmaku.worder.crossround,0.5);
						break;
					}
					yuuka.x += yuuka.vecx;
					yuuka.y += yuuka.vecy;
				}
				break;
			case 24://スペルカード　3枚目
				DrawGraph((int)(yuuka.x - 30), (int)(yuuka.y - 45), yuukadot[yuuka.imgpoji], true);
				if (Currenttime < 8){
					Bosshit = false;
				}
				else{
					Bosshit = true;
				}
				if (Currenttime < 3){
					EndSpellkardEffect(320000, 0);
					StartSpellkardEffect(yuukastand[2]);
					appeary += 1;
					yuuka.x += yuuka.vecx;
					if ((yuuka.vecx > 0 && yuuka.x > 208) || (yuuka.vecx < 0 && yuuka.x < 208)){
						yuuka.x = 208;
						yuuka.vecx = 0;
					}
					yuuka.y += yuuka.vecy;
					if ((yuuka.vecy > 0 && yuuka.y > 100) || (yuuka.vecy < 0 && yuuka.y < 100)){
						yuuka.y = 100;
						yuuka.vecy = 0;
					}
				}
				else
				{
					timetoflame = ((Currenttime - 3) % Looptime) * 60 + flame;
					switch (timetoflame){
					case 1:
						danmaku.bj = (int)(yuuka.x);
						danmaku.Setdanmaku_Wave((int)(yuuka.x), (int)(yuuka.y), 1, danmaku.dshu.ring, danmaku.dcolor.yellow, 0, 0, 20, danmaku.worder.crossround, 0.1);
						break;
					case 61:
						danmaku.Setdanmaku_Wave((int)(yuuka.x), (int)(yuuka.y), 1, danmaku.dshu.ring, danmaku.dcolor.yellow, 0, 12, 20, danmaku.worder.crossround, 0.1);
						break;
					case 121:
						danmaku.Setdanmaku_Wave((int)(yuuka.x), (int)(yuuka.y), 1, danmaku.dshu.ring, danmaku.dcolor.yellow, 0,  24, 20, danmaku.worder.crossround, 0.1);
						break;
					case 211:
						danmaku.Setdanmaku_ArrowRendan((int)(yuuka.x), (int)(yuuka.y), 25, danmaku.dshu.uroko, danmaku.dcolor.red, 0, 11, 6, 1);
						danmaku.Setdanmaku_ArrowRendan((int)(yuuka.x), (int)(yuuka.y), 70, danmaku.dshu.uroko, danmaku.dcolor.red, 0, 11, 6, 1);
						danmaku.Setdanmaku_ArrowRendan((int)(yuuka.x), (int)(yuuka.y), 115, danmaku.dshu.uroko, danmaku.dcolor.red, 0, 11, 6, 1);
						danmaku.Setdanmaku_ArrowRendan((int)(yuuka.x), (int)(yuuka.y), 160, danmaku.dshu.uroko, danmaku.dcolor.red, 0, 11, 6, 1);
						danmaku.Setdanmaku_ArrowRendan((int)(yuuka.x), (int)(yuuka.y), 205, danmaku.dshu.uroko, danmaku.dcolor.red, 0, 11, 6, 1);
						danmaku.Setdanmaku_ArrowRendan((int)(yuuka.x), (int)(yuuka.y), 250, danmaku.dshu.uroko, danmaku.dcolor.red, 0, 11, 6, 1);
						danmaku.Setdanmaku_ArrowRendan((int)(yuuka.x), (int)(yuuka.y), 295, danmaku.dshu.uroko, danmaku.dcolor.red, 0, 11, 6, 1);
						danmaku.Setdanmaku_ArrowRendan((int)(yuuka.x), (int)(yuuka.y), 340, danmaku.dshu.uroko, danmaku.dcolor.red, 0, 11, 6, 1);
						break;
					case 271:
						danmaku.Setdanmaku_ArrowRendan((int)(yuuka.x), (int)(yuuka.y), 0, danmaku.dshu.uroko, danmaku.dcolor.blue, 0, 11, 6, 1);
						danmaku.Setdanmaku_ArrowRendan((int)(yuuka.x), (int)(yuuka.y), 45, danmaku.dshu.uroko, danmaku.dcolor.blue, 0, 11, 6, 1);
						danmaku.Setdanmaku_ArrowRendan((int)(yuuka.x), (int)(yuuka.y), 90, danmaku.dshu.uroko, danmaku.dcolor.blue, 0, 11, 6, 1);
						danmaku.Setdanmaku_ArrowRendan((int)(yuuka.x), (int)(yuuka.y), 135, danmaku.dshu.uroko, danmaku.dcolor.blue, 0, 11, 6, 1);
						danmaku.Setdanmaku_ArrowRendan((int)(yuuka.x), (int)(yuuka.y), 180, danmaku.dshu.uroko, danmaku.dcolor.blue, 0, 11, 6, 1);
						danmaku.Setdanmaku_ArrowRendan((int)(yuuka.x), (int)(yuuka.y), 225, danmaku.dshu.uroko, danmaku.dcolor.blue, 0, 11, 6, 1);
						danmaku.Setdanmaku_ArrowRendan((int)(yuuka.x), (int)(yuuka.y), 270, danmaku.dshu.uroko, danmaku.dcolor.blue, 0, 11, 6, 1);
						danmaku.Setdanmaku_ArrowRendan((int)(yuuka.x), (int)(yuuka.y), 315, danmaku.dshu.uroko, danmaku.dcolor.blue, 0, 11, 6, 1);
						break;
					case 300:
						switch ((int)(yuuka.x)){
						case 208:
							if (GetRand(2) == 1){
								yuuka.vecx = 1;
								leftmove = -1;
								yuuka.imgpoji = DotAct.right;
							}
							else{
								yuuka.vecx = -1;
								leftmove = 1;
								yuuka.imgpoji = DotAct.left;
							}
							break;
						case 148:
							yuuka.imgpoji = DotAct.right;
							yuuka.vecx = 1;
							leftmove = -1;
							break;
						case 268:
							yuuka.imgpoji = DotAct.left;
							yuuka.vecx = -1;
							leftmove = 1;
							break;
						}
						if (leftmove == 1){
							danmaku.Setdanmaku_Wave(100, 100, 1.5, danmaku.dshu.middle, danmaku.dcolor.orange, 0, danmaku.Getkakudo_Homing(100, 100, j.x, j.y), 20);
							danmaku.Setdanmaku_Wave(100, 100, 3, danmaku.dshu.tubu, danmaku.dcolor.orange, 0, 0, 30);
						}
						else{
							danmaku.Setdanmaku_Wave(324, 100, 1.5, danmaku.dshu.middle, danmaku.dcolor.orange, 0, danmaku.Getkakudo_Homing(324, 100, j.x, j.y), 20);
							danmaku.Setdanmaku_Wave(324, 100, 3, danmaku.dshu.tubu, danmaku.dcolor.orange, 0, 0, 30);
						}
						break;
					case 360:
						yuuka.vecx = 0;
						yuuka.imgpoji = DotAct.common;
						break;
					case 390:
						if (leftmove == 1){
							danmaku.Setdanmaku_Wave(100, 200, 1.5, danmaku.dshu.middle, danmaku.dcolor.orange, 0, danmaku.Getkakudo_Homing(100, 100, j.x, j.y), 20);
							danmaku.Setdanmaku_Wave(100, 200, 3, danmaku.dshu.tubu, danmaku.dcolor.orange, 0, 0, 10);
						}
						else{
							danmaku.Setdanmaku_Wave(324, 200, 1.5, danmaku.dshu.middle, danmaku.dcolor.orange, 0, danmaku.Getkakudo_Homing(324, 100, j.x, j.y), 20);
							danmaku.Setdanmaku_Wave(324, 200, 3, danmaku.dshu.tubu, danmaku.dcolor.orange, 0, 0, 10);
						}
						break;
					case 480:
						if (leftmove == 1){
							danmaku.Setdanmaku_Wave(324, 200, 1.5, danmaku.dshu.middle, danmaku.dcolor.orange, 0, danmaku.Getkakudo_Homing(100, 100, j.x, j.y), 20);
							danmaku.Setdanmaku_Wave(324, 200, 3, danmaku.dshu.tubu, danmaku.dcolor.orange, 0, 0, 10);
						}
						else{
							danmaku.Setdanmaku_Wave(100, 200, 1.5, danmaku.dshu.middle, danmaku.dcolor.orange, 0, danmaku.Getkakudo_Homing(324, 100, j.x, j.y), 20);
							danmaku.Setdanmaku_Wave(100, 200, 3, danmaku.dshu.tubu, danmaku.dcolor.orange, 0, 0, 10);
						}
						break;
					case 570:
						if (leftmove == 1){
							danmaku.Setdanmaku_Wave(324, 400, 1.5, danmaku.dshu.middle, danmaku.dcolor.purple, 0, danmaku.Getkakudo_Homing(100, 100, j.x, j.y), 20);
							danmaku.Setdanmaku_Wave(324, 400, 3, danmaku.dshu.tubu, danmaku.dcolor.purple, 0, 0, 30);
						}
						else{
							danmaku.Setdanmaku_Wave(100, 400, 1.5, danmaku.dshu.middle, danmaku.dcolor.purple, 0, danmaku.Getkakudo_Homing(324, 100, j.x, j.y), 20);
							danmaku.Setdanmaku_Wave(100, 400, 3, danmaku.dshu.tubu, danmaku.dcolor.purple, 0, 0, 30);
						}
						break;
					}
					yuuka.x += yuuka.vecx;
					yuuka.y += yuuka.vecy;
					
				}
				break;
			case 25://スペルカード　4枚目
				DrawGraph((int)(yuuka.x - 30), (int)(yuuka.y - 45), yuukadot[yuuka.imgpoji], true);
				if (Currenttime < 3){
					EndSpellkardEffect(300000, PreBonusScore);
					StartSpellkardEffect( yuukastand[2]);
					switch (Currenttime){
					case 0:
						appeary += 5;
						appearx -= 5;

						break;
					case 1:
						appeary += 0;
						appearx += 1.5;
						break;
					case 2:
						appeary += 5;
						appearx -= 10;
						break;
					}
					yuuka.x += yuuka.vecx;
					if (yuuka.vecx > 0) {
						yuuka.imgpoji = DotAct.right;
					}
					else {
						yuuka.imgpoji = DotAct.left;
					}
					if ((yuuka.vecx > 0 && yuuka.x > 208) || (yuuka.vecx < 0 && yuuka.x < 208)){
						yuuka.x = 208;
						yuuka.imgpoji = DotAct.common;
						yuuka.vecx = 0;
					}
					yuuka.y += yuuka.vecy;
					if ((yuuka.vecy > 0 && yuuka.y > 150) || (yuuka.vecy < 0 && yuuka.y < 150)){
						yuuka.y = 100;
						yuuka.imgpoji = DotAct.common;
						yuuka.vecy = 0;
					}
				}
				else
				{
					if (Currenttime > 5){
						Bosshit = true;
					}
					timetoflame = ((Currenttime - 3) % Looptime) * 60 + flame;
					switch (timetoflame){
					case 1:
						danmaku.Setdanmaku_Wave((int)(yuuka.x), (int)(yuuka.y), 1, danmaku.dshu.ring, danmaku.dcolor.yellow, 0, 0, 24, danmaku.worder.crossround, 0.1);
						break;
					case 76:
						danmaku.Setdanmaku_Wave((int)(yuuka.x), (int)(yuuka.y), 1, danmaku.dshu.ring, danmaku.dcolor.yellow, 0, 0, 24, danmaku.worder.crossround, 0.1);
						break;
					case 121:
						danmaku.Setdanmaku_Ko(20, 15, 1.5, danmaku.dshu.large, danmaku.dcolor.purple, 0, 0, 90, 11);
						break;
					case 151:
						danmaku.Setdanmaku_Wave((int)(yuuka.x), (int)(yuuka.y), 1, danmaku.dshu.ring, danmaku.dcolor.green, 0, 0, 24, danmaku.worder.crossround, 0.1);
						break;
					case 241:
						danmaku.Setdanmaku_Ko(404, 15, 1.5, danmaku.dshu.large, danmaku.dcolor.blue, 0, 90, 180, 11);
						break;
					case 226:
						danmaku.Setdanmaku_Wave((int)(yuuka.x), (int)(yuuka.y), 1, danmaku.dshu.ring, danmaku.dcolor.red, 0, 0, 24, danmaku.worder.crossround, 0.1);
						break;
					case 361:
						danmaku.Setdanmaku_Ko(20, 465, 1.5, danmaku.dshu.large, danmaku.dcolor.purple, 0, 270,360, 11);
						break;
					case 301:
						danmaku.Setdanmaku_Wave((int)(yuuka.x), (int)(yuuka.y), 1, danmaku.dshu.ring, danmaku.dcolor.green, 0, 0, 24, danmaku.worder.crossround, 0.1);
						break;
					case 481:
						danmaku.Setdanmaku_Wave((int)(yuuka.x), (int)(yuuka.y), 1, danmaku.dshu.ring, danmaku.dcolor.green, 0, 0, 24, danmaku.worder.crossround, 0.1);
						danmaku.Setdanmaku_Ko(404, 465, 1.5, danmaku.dshu.large, danmaku.dcolor.blue, 0, 180,270, 11);
						break;
					}
				}
				break;
			case 27://終了　爆散
				if (Currenttime < 3){
					EndSpellkardEffect(300000, SpellBonusScore);
				}
				switch(Talkcount){
					/*
					
					*/
				case 10:
					BossStandPosition = 6;
					if (PlayerData.jikinum == 1){
						selif1 = "どうやら、これまでのようだね。";
						selif2 = "私の勝ちだ。";
						JikiStandPosition = 8;
					}
					else{
						JikiStandPosition = 1;
						selif1 = "これで落ち着きましたか？幽香さん。";
						selif2 = "";
					}
					break;
				case 9:
					if (PlayerData.jikinum == 1){
						selif1 = "ブランク相手に負けるのは悔しいけど";
						selif2 = "しょうがないわね。";
						Shadowflg = 0;
						
					}
					else{
						Shadowflg = 0;
						selif1 = "あー、ちょっと待って。確か殴り合い";
						selif2 = "になってその前は…";
					}
					break;
				case 8:
					if (PlayerData.jikinum == 1){
						selif1 = "私にブランクがあるんじゃなくて";
						selif2 = "今のあんたが弱いのよ。";
						JikiStandPosition = 2;
						Shadowflg = 1;
					}
					else{
						Shadowflg = 1;
						selif1 = "私に共闘を申し込んだのですよ。";
						selif2 = "";
					}
					break;
				case 7:
					if (PlayerData.jikinum == 1){
						selif1 = "何とでも言いなさい。私は関係ないわ。";
						selif2 = "";
						Shadowflg = 0;
					}
					else{
						Shadowflg = 0;
						selif1 = "誰があんたと手を組むだって？！";
						selif2 = "さっきの撤回よ。あんたは関係ないでしょ。";
					}
					break;
				case 6:
					if (PlayerData.jikinum == 1){
						selif1 = "ほう…。では異変解決に戻るとしよう。";
						selif2 = "次は誰が相手になるのかな。";
						JikiStandPosition = 1;
						Shadowflg = 1;
					}
					else{
						Shadowflg = 1;
						selif1 = "確かに関係ありませんよ。あなたは";
						selif2 = "巻き込まれましたが。";
					}
					break;
				case 5:
					if (PlayerData.jikinum == 1){
						selif1 = "この先に手強いやつがいたわ。あんた";
						selif2 = "なんかに倒せるかしら？";
						Shadowflg = 0;
					}
					else{
						Shadowflg = 0;
						selif1 = "関係ないなら外の世界にでも行ってなさい。";
						selif2 = "それで気が済むでしょうから。";
					}
					break;
				case 4:
					if (PlayerData.jikinum == 1){
						selif1 = "倒せるさ、どんなやつだろうと。";
						selif2 = "今は気分がいいからね。";
						JikiStandPosition = 2;
						Shadowflg =	1;
					}
					else{
						Shadowflg = 1;
						selif1 = "え？外の世界って、まさか博麗大結界";
						selif2 = "が解けているのですか？";
					}
					break;
				case 3:
					if (PlayerData.jikinum == 1){
						selif1 = "それが妖怪共を幻想郷に追いやった";
						selif2 = "張本人であっても？";
						Shadowflg = 0;
					}
					else{
						Shadowflg = 0;
						selif1 = "そうそう、間違いないわ。確か。";
						selif2 = "";
					}
					break;
				case 2:
					if (PlayerData.jikinum == 1){
						selif1 = "もちろん、例外無く。";
						selif2 = "";
						Shadowflg = 1;
						JikiStandPosition = 8;
					}
					else{
						Shadowflg = 1;
						selif1 = "ワクワクしたいところですが…";
						selif2 = "とんでもないことになってきましたね。";
					}
					break;
				case 1:
					if (j.slow > 0){
						TalkSkipCancel = true;
					}
					else{
						TalkSkipCancel = false;
					}
					break;
				}
				if (PlayerData.jikinum == 2){
					jikicolor = GetColor(150, 150, 255);
					bossy = 195;
					jikiy = 225;
				}
				else{
					jikicolor = GetColor(220, 220, 100);
					bossy = 210;
					jikiy = 215;
				}
				if (Talkcount > 1){
					BossTalking(yuukastand[BossStandPosition], GetColor(150, 150, 200), jikicolor, 170, bossy, jikiy, 0);
				}
				break;
			}
		}
		danmaku.ProcessBossDanmaku(flame + Currenttime * 60, scene, PlayerData.jikinum, (int)(yuuka.x), (int)(yuuka.y));
		
		if (BossTalk == false){ r = DisplayBossStates(yuuka.hitpoint, yuuka.phasecount); }
		if (Spell){
			DisplaySpellStates();
		}
		SetDrawArea(1, 1, 639, 479);
		if ((scene == 28 && prescene == 27)){
			rr = false;//フェーズの進行度に応じてボス戦が終了する。
		}
		if (r != 0){
			r = -1;
		}
		return rr;
	}
	bool Stage3::ProcessYoumu(int flame){
		bool rr = true;
		int r = 0;
		prescene = scene;
		if (flame == 1){
			Bosstime--;
		}//一秒経過ごとに加算。
		SetDrawArea(20, 15, 404, 465);
		if (scene != 0){
			switch (scene){
			case 19:
				switch (Talkcount){
					/*  */
				case 21:
					JikiStandPosition = 1;
					BossStandPosition = -1;
					selif1 = "相変わらず人の気配がないわね。";
					selif2 = "";
					Shadowflg = 1;
					break;
				case 20:
					selif1 = "あの子は異変解決に出てるって";
					selif2 = "言ってたけど、どうなのかしらね。";
					break;
				case 19:
					if (PlayerData.jikinum == 3){
						selif1 = "異変解決には出てなさそうでしたよ。";
						selif2 = "";
						Shadowflg = 0;
					}
					else{
						JikiStandPosition = 2;
						BossStandPosition = -1;
						selif1 = "お～い、誰かおらぬか～？";
						selif2 = "";
						Shadowflg = 1;
					}
					break;
				case 18:
					if (PlayerData.jikinum == 3){
						selif1 = "うん？あんたは…";
						selif2 = "";
						youmu.x = -50;
						youmu.y = -10;
						youmu.vecx = (212 - youmu.x) / 40;
						youmu.vecy = (100 - youmu.y) / 40;
						
						Shadowflg = 1;
					}
					else{
						JikiStandPosition = 1;
						selif1 = "だめか。忠告があったとはいえ事はそう";
						selif2 = "簡単にはいかないものだな。";
					}
					break;
				case 17:
					if (PlayerData.jikinum == 3){
						BossStandPosition = 1;
						selif1 = "神社も魔女の家も生活感が残っていました";
						selif2 = "し、留守というわけではなさそうです。";
						Shadowflg = 0;

					}
					else{
						JikiStandPosition = 7;
						selif1 = "下手に口約束をするべきではなかったかな。";
						selif2 = "";
					}
					break;
				case 16:
					if (PlayerData.jikinum == 3){
						selif1 = "ということは、つまり…";
						selif2 = "";
						Shadowflg = 1;
					}
					else{
						Shadowflg = 0;
						youmu.x = -50;
						youmu.y = -10;
						youmu.vecx = (212 - youmu.x) / 40;
						youmu.vecy = (100 - youmu.y) / 40;
						
						selif1 = "…";
						selif2 = "";
					}
					break;
				case 15:
					if (PlayerData.jikinum == 3){
						selif1 = "あの二人もまた異変に巻き込まれたの";
						selif2 = "ならそうかもしれないわ。";
						Shadowflg = 1;
					}
					else{
						BossStandPosition = 1;
						
						selif1 = "あんたは確か…。";
						selif2 = "";
					}
					break;
				case 14:
					if (PlayerData.jikinum == 3){
						selif1 = "やっぱりそうみるべきですよね。";
						selif2 = "";
						Shadowflg = 0;
					}
					else{
						JikiStandPosition = 1;
						Shadowflg = 1;
						selif1 = "布都だ。いるじゃないか、誰かが。";
						selif2 = "";
					}
					break;
				case 13:
					if (PlayerData.jikinum == 3){
						selif1 = "紛失するのが物や装飾に限らないと";
						selif2 = "断定すれば必然的に";
						Shadowflg = 0;
					}
					else{
						Shadowflg = 0;
						selif1 = "布都…あぁあの道教の人ね。";
						selif2 = "";
					}
					break;
				case 12:
					if (PlayerData.jikinum == 3){
						selif1 = "一人二人と行方不明者が出てくると。";
						selif2 = "";
						Shadowflg = 1;
					}
					else{
						Shadowflg = 1;
						JikiStandPosition = 2;
						selif1 = "そうお馴染み道教の人だ。異変に動いてる";
						selif2 = "のが私だけじゃなくて安心した。";
					}
					break;
				case 11:
					if (PlayerData.jikinum == 3){
						selif1 = "そして…";
						selif2 = "";
						Shadowflg = 0;
					}
					else{
						selif1 = "ここ最近どこかおかしいことはないか？";
						selif2 = "何かものをなくしたとか装飾が変とか";
					}
					break;
				case 10:
					if (PlayerData.jikinum == 3){
						selif1 = "よりによってそれが根本的に異変解決を";
						selif2 = "する役の二人だったと。";
						Shadowflg = 1;
					}
					else{
						JikiStandPosition = 1;
						selif1 = "髪型がおかしいとか…";
						selif2 = "口調がいつもとは違うとか…。";
					}
					break;
				case 9:
					if (PlayerData.jikinum == 3){
						selif1 = "これはとんでもないことですよ。";
						selif2 = "巫女も魔女もいないとなれば…";
						Shadowflg = 0;
					}
					else{
						Shadowflg = 0;
						BossStandPosition = 2;
						selif1 = "そう、あんたが異変の黒幕ね。";
						selif2 = "　やっと見つけたわ。";
					}
					break;
				case 8:
					if (PlayerData.jikinum == 3){
						selif1 = "私が解決すればいいのよ。あんたも";
						selif2 = "髪型がなんかヘンだし。";
						Shadowflg = 1;
					}
					else{
						Shadowflg = 1;
						JikiStandPosition = 4;
						selif1 = "あ～また変な奴に話しかけてしまったか。";
						selif2 = "";
					}
					break;
				case 7:
					if (PlayerData.jikinum == 3){
						selif1 = "え？あぁ、確かにそうでした。こんなに";
						selif2 = "髪の毛を伸ばした覚えはないです。";
						BossStandPosition = StandAct.surprised;
						Shadowflg = 0;
					}
					else{
						selif1 = "しかもこの場合は、変になった奴に";
						selif2 = "襲撃されているのね。";
					}
					break;
				case 6:
					if (PlayerData.jikinum == 3){
						selif1 = "（自分で気づきなさいよ。）";
						selif2 = "";
						Shadowflg = 1;
					}
					else{
						JikiStandPosition = 2;
						selif1 = "事情を話したところで聞く耳はないか…。";
						selif2 = "";
					}
					break;
				case 5:
					if (PlayerData.jikinum == 3){
						selif1 = "でも異変解決なら";
						selif2 = "";
						Shadowflg = 0;
					}
					else{
						Shadowflg = 0;
						selif1 = "さて覚悟は決めたからしら？あんたが";
						selif2 = "黒幕かどうかは";
					}
					break;
				case 4:
					if (PlayerData.jikinum == 3){
						selif1 = "私だってしたことあります！だから";
						selif2 = "ここで成敗されてちょうだい。";
						Shadowflg = 0;
						BossStandPosition = StandAct.excited;
					}
					else{
						BossStandPosition = StandAct.excited;
						selif1 = "私に斬り刻まれて分かることよ。";
						selif2 = "";
					}
					break;
				case 3:
					if (PlayerData.jikinum == 3){
						selif1 = "あらあら、物騒ね。人のこと言えない";
						selif2 = "けど、相手になってあげるわ。";
						Shadowflg = 1;
					}
					else{
						Shadowflg = 1;
						JikiStandPosition = 9;
						selif1 = "もはや危険人物と化しているな。それならば";
						selif2 = "私も油断できまい。";
					}
					break;
				case 2:
					if (PlayerData.jikinum == 3){
						selif1 = "あなたも同じで、戦いが所望でしょう？";
						selif2 = "";
						Shadowflg = 0;
					}
					else{
						Shadowflg = 0;
						selif1 = "いざ勝負といこうか！";
						selif2 = "";
					}
					break;
				case 1:
					if (PlayerData.jikinum == 3){
						selif1 = "果たして相手になるのかしらね…！";
						selif2 = "";
						Shadowflg = 1;
					}
					else{
						Shadowflg = 1;
						JikiStandPosition = 8;
						selif1 = "さてさて狂人相手なことだし、";
						selif2 = "遠慮なく火でもつけるとしよう。";
					}
					break;
				}
				int bossy, jikiy;
				if (PlayerData.jikinum == 0){
					jikicolor = GetColor(255, 150, 150);
					bossy = 215;
					jikiy = 210;
					
				}
				else{
					jikicolor = GetColor(150, 200, 150);
					bossy = 210;
					jikiy = 215;

				}
				if ((PlayerData.jikinum == 0 && Talkcount < 16) || (PlayerData.jikinum == 3 && Talkcount < 18)){
					if (youmu.x < 212){
						youmu.x += youmu.vecx;
						youmu.y += youmu.vecy;
						youmu.imgpoji = DotAct.right;
					}
					else{
						youmu.x = 212;
						youmu.y = 100;
						youmu.vecx = 0;
						youmu.vecy = 0;
						youmu.imgpoji = DotAct.common;
					}
					if (j.slow > 0){
						youmu.x = 212;
						youmu.y = 100;
						youmu.vecx = 0;
						youmu.vecy = 0;
						youmu.imgpoji = DotAct.common;
					}
					DrawGraph((int)(youmu.x - 30), (int)(youmu.y - 45), youmudot[youmu.imgpoji], true);
				}
				if (BossStandPosition == -1){
					BossTalking(0, GetColor(80, 255, 80), jikicolor, 170, bossy, jikiy, 0);
				}
				else{
					BossTalking(youmustand[BossStandPosition], GetColor(80, 255, 80), jikicolor, 170, bossy, jikiy, 0);
				}
				break;
			case 20://通常1
				DrawGraph((int)(youmu.x - 30), (int)(youmu.y - 45), youmudot[youmu.imgpoji], true);
				if (Currenttime > 0){
					Bosshit = true;
					timetoflame = (Currenttime - 1) % Looptime * 60 + flame;
					switch (timetoflame){
					case 1:
						youmu.vecx = 0;
						youmu.vecy = 0;
						youmu.imgpoji = DotAct.common;
						break;
					case 61:
						danmaku.Setdanmaku_Wave((int)(youmu.x), (int)(youmu.y), 2, danmaku.dshu.middle, danmaku.dcolor.green, 0, danmaku.Getkakudo_Homing(youmu.x, youmu.y, j.x, j.y), 20);
						break;
					case 121:
						danmaku.Setdanmaku_Wave((int)(youmu.x), (int)(youmu.y), 2, danmaku.dshu.middle, danmaku.dcolor.green, 0, danmaku.Getkakudo_Homing(youmu.x, youmu.y, j.x, j.y), 20);
						break;
					case 241:
						if (youmu.x < 252){
							youmu.vecx = (double)(32 - 212) / 60;
							youmu.imgpoji = DotAct.left;
							youmu.vecy = 0;
						}
						else{
							youmu.vecx = (double)(242 - 272) / 60;
							youmu.imgpoji = DotAct.right;
							youmu.vecy = (double)(70 - 160) / 60;
						}
						danmaku.Setdanmaku_Wave((int)(youmu.x), (int)(youmu.y), 2, danmaku.dshu.kome, danmaku.dcolor.green, 0, 0, 18);
						danmaku.Setdanmaku_ChainRendan((int)(youmu.x), (int)(youmu.y), 3, danmaku.Getkakudo_Homing(youmu.x, youmu.y, j.x, j.y), danmaku.dshu.large, danmaku.dcolor.green, 0, 10, 3);
						danmaku.Setdanmaku_ChainRendan((int)(youmu.x), (int)(youmu.y), 3, danmaku.Getkakudo_Homing(youmu.x, youmu.y, j.x, j.y) + 15, danmaku.dshu.large, danmaku.dcolor.green, 0, 10, 3);
						danmaku.Setdanmaku_ChainRendan((int)(youmu.x), (int)(youmu.y), 3, danmaku.Getkakudo_Homing(youmu.x, youmu.y, j.x, j.y) - 15, danmaku.dshu.large, danmaku.dcolor.green, 0, 10, 3);
						break;
					case 301:
						if (youmu.vecy == 0){
							youmu.vecx = (double)(152 - 32) / 60;
							youmu.imgpoji = DotAct.right;
							youmu.vecy = (double)(250 - 100) / 60;
						}
						else{
							youmu.vecx = (double)(212 - 242) / 60;
							youmu.imgpoji = DotAct.left;
							youmu.vecy = (double)(310 - 70) / 60;
						}
						danmaku.Setdanmaku_Wave((int)(youmu.x), (int)(youmu.y), 2, danmaku.dshu.kome, danmaku.dcolor.white, 0, 0, 18);
						danmaku.Setdanmaku_ChainRendan((int)(youmu.x), (int)(youmu.y), 3, danmaku.Getkakudo_Homing(youmu.x, youmu.y, j.x, j.y), danmaku.dshu.large, danmaku.dcolor.green, 0, 10, 3);
						danmaku.Setdanmaku_ChainRendan((int)(youmu.x), (int)(youmu.y), 3, danmaku.Getkakudo_Homing(youmu.x, youmu.y, j.x, j.y) + 15, danmaku.dshu.large, danmaku.dcolor.green, 0, 10, 3);
						danmaku.Setdanmaku_ChainRendan((int)(youmu.x), (int)(youmu.y), 3, danmaku.Getkakudo_Homing(youmu.x, youmu.y, j.x, j.y) - 15, danmaku.dshu.large, danmaku.dcolor.green, 0, 10, 3);
						break;
					case 361:
						if (youmu.vecx == 2){
							youmu.vecx = (double)(272 - youmu.x) / 60;
							youmu.vecy = (double)(160 - youmu.y) / 60;
							youmu.imgpoji = DotAct.right;
						}
						else{
							youmu.vecx = (double)(212 - youmu.x) / 60;
							youmu.imgpoji = DotAct.common;
							youmu.vecy = (double)(100 - youmu.y) / 60;
						}
						danmaku.Setdanmaku_Wave((int)(youmu.x), (int)(youmu.y), 2, danmaku.dshu.kome, danmaku.dcolor.white, 0, 0, 18);
						danmaku.Setdanmaku_ChainRendan((int)(youmu.x), (int)(youmu.y), 3, danmaku.Getkakudo_Homing(youmu.x, youmu.y, j.x, j.y), danmaku.dshu.large, danmaku.dcolor.green, 0, 10, 3);
						danmaku.Setdanmaku_ChainRendan((int)(youmu.x), (int)(youmu.y), 3, danmaku.Getkakudo_Homing(youmu.x, youmu.y, j.x, j.y) + 15, danmaku.dshu.large, danmaku.dcolor.green, 0, 10, 3);
						danmaku.Setdanmaku_ChainRendan((int)(youmu.x), (int)(youmu.y), 3, danmaku.Getkakudo_Homing(youmu.x, youmu.y, j.x, j.y) - 15, danmaku.dshu.large, danmaku.dcolor.green, 0, 10, 3);
						break;
					}
					youmu.x += youmu.vecx;
					youmu.y += youmu.vecy;
					if (timetoflame > 0 && timetoflame < 181 && (timetoflame - 1) % 20 == 0){
						if (timetoflame != 61 && timetoflame != 121){
							danmaku.Setdanmaku_Wave((int)(youmu.x), (int)(youmu.y), 2, danmaku.dshu.middle, danmaku.dcolor.water, 0, (timetoflame - 1) / 20 * 7, 20);
						}
					}
				}
				else{
					youmu.x = 212;
					youmu.y = 100;
				}
				break;
			case 21://スペルカード1
				if (youmu.imgpoji == DotAct.act2){
					double  angle = atan2(youmu.vecy, youmu.vecx);
					DrawRotaGraph((int)(youmu.x), (int)(youmu.y), 1, angle, youmudot[youmu.imgpoji], true);
				}
				else{
					DrawGraph((int)(youmu.x - 30), (int)(youmu.y - 45), youmudot[youmu.imgpoji], true);
				}
				if (Currenttime < 8){
					Bosshit = false;
				}
				else{
					Bosshit = true;
				}
				if (Currenttime < 3){
					EndSpellkardEffect(320000, 0);
					StartSpellkardEffect(youmustand[1]);
					appeary += 1;
					if (youmu.x <= 25){
						youmu.vecx = 0;
						youmu.vecy = 0;
						youmu.x = 25;
						youmu.y = 250;
						youmu.imgpoji = DotAct.act2;
					}
					else{
						youmu.x += youmu.vecx;
						youmu.y += youmu.vecy;
						youmu.imgpoji = DotAct.left;
					}

				}
				else
				{
					int p;
					timetoflame = (Currenttime - 4) % Looptime * 60 + flame;
					switch (timetoflame){
					case 1:
						youmu.imgpoji = DotAct.act1;
						danmaku.Setdanmaku_Wave(52, 80, 0.5, danmaku.dshu.mayu, danmaku.dcolor.blue, 0, 0, 30);
						break;
					case 36:
						danmaku.Setdanmaku_Wave(132, 80, 0.5, danmaku.dshu.mayu, danmaku.dcolor.blue, 0, 0, 30);
						break;
					case 71:
						danmaku.Setdanmaku_Wave(212, 80, 0.5, danmaku.dshu.mayu, danmaku.dcolor.blue, 0, 0, 30);
						break;
					case 106:
						danmaku.Setdanmaku_Wave(292, 80, 0.5, danmaku.dshu.mayu, danmaku.dcolor.blue, 0, 0, 30);
						break;
					case 141:
						danmaku.Setdanmaku_Wave(372, 80, 0.5, danmaku.dshu.mayu, danmaku.dcolor.blue, 0, 0, 30);
						break;
					case 241:
						youmu.imgpoji = DotAct.act2;
						if (youmu.x == 25){
							youmu.vecx = (400 - 25) / 20;
						}
						else{
							youmu.vecx = (25 - 400) / 20;
						}
						break;
					case 261:
						if (youmu.vecx > 0){
							youmu.x = 400;
						}
						else{
							youmu.x = 25;
						}
						youmu.vecx = 0;
						youmu.imgpoji = DotAct.act1;
						p = danmaku.dan[0].np;
						while (p != danmaku.tail){
							if (danmaku.dan[p].danshu == danmaku.dshu.mayu){
								if (danmaku.dan[p].y >= 235 && danmaku.dan[p].y <= 265){
									danmaku.dan[p].vecx = (j.x - danmaku.dan[p].x) / 102.4;
									danmaku.dan[p].vecy = (j.y - danmaku.dan[p].y) / 102.4 * -1;
									danmaku.dan[p].imgangle = danmaku.Getkakudo_Homing(danmaku.dan[p].x, danmaku.dan[p].y, j.x, j.y) * PI / 180;
									danmaku.dan[p].color = danmaku.dcolor.purple;
								}
							}
							p = danmaku.dan[p].np;
						}
						break;
					case 271:
						int ready = 0;
						if (youmu.x == 400){
							for (int x = 30; x < 410; x += 25){
								danmaku.Setdanmaku_ChainRendan(x, 250, 2.5, 90, danmaku.dshu.middle, danmaku.dcolor.yellow, ready, 7, 8);
								danmaku.Setdanmaku_ChainRendan(x, 250, 2.5, 270, danmaku.dshu.middle, danmaku.dcolor.yellow, ready, 7, 8);
								ready += 10;
							}
						}
						else{
							for (int x = 400; x > 25; x -= 25){
								danmaku.Setdanmaku_ChainRendan(x, 250, 2.5, 90, danmaku.dshu.middle, danmaku.dcolor.yellow, ready, 7, 8);
								danmaku.Setdanmaku_ChainRendan(x, 250, 2.5, 270, danmaku.dshu.middle, danmaku.dcolor.yellow, ready, 7, 8);
								ready += 10;
							}
						}

						break;
					}
					youmu.x += youmu.vecx;
				}
				break;
			case 22://通常2
				DrawGraph((int)(youmu.x - 30), (int)(youmu.y - 45), youmudot[youmu.imgpoji], true);
				if (Currenttime < 8){
					Bosshit = false;
				}
				else{
					Bosshit = true;
				}
				if (Currenttime < 3){
					EndSpellkardEffect(300000, SpellBonusScore);
					youmu.x += youmu.vecx;
					youmu.y += youmu.vecy;
					if (youmu.vecy != 0 && youmu.y <= 80){
						youmu.x = 330;
						youmu.y = 80;
						youmu.vecx = 0;
						youmu.vecy = 0;
						youmu.imgpoji = DotAct.common;
					}
					else {
						if (youmu.vecx > 0) {
							youmu.imgpoji = DotAct.right;
						}
						else {
							youmu.imgpoji = DotAct.left;
						}
					}
				}
				else
				{
					timetoflame = ((Currenttime - 4) % Looptime) * 60 + flame;

					switch (timetoflame){
					case 1:
						danmaku.Setdanmaku_ChainRendan((int)(youmu.x), (int)(youmu.y), 3, danmaku.Getkakudo_Homing(youmu.x, youmu.y, j.x, j.y), danmaku.dshu.large, danmaku.dcolor.water, 0, 10, 3);
						danmaku.Setdanmaku_ChainRendan((int)(youmu.x), (int)(youmu.y), 3, danmaku.Getkakudo_Homing(youmu.x, youmu.y, j.x, j.y) + 15, danmaku.dshu.large, danmaku.dcolor.water, 0, 10, 3);
						danmaku.Setdanmaku_ChainRendan((int)(youmu.x), (int)(youmu.y), 3, danmaku.Getkakudo_Homing(youmu.x, youmu.y, j.x, j.y) - 15, danmaku.dshu.large, danmaku.dcolor.water, 0, 10, 3);
						break;
					case 75:
						x = GetRand(162) + 30;
						y = GetRand(190) + 30;
						danmaku.Setdanmaku_Wave(x, y, 3, danmaku.dshu.large, danmaku.dcolor.red, 30, 0, 18);
						break;
					case 150:
						x = GetRand(140) + 240;
						y = GetRand(190) + 30;
						danmaku.Setdanmaku_Wave(x, y, 3, danmaku.dshu.large, danmaku.dcolor.green, 30, 0, 18);
						break;
					case 225:
						x = GetRand(162) + 30;
						y = GetRand(150) + 290;
						danmaku.Setdanmaku_Wave(x, y, 3, danmaku.dshu.large, danmaku.dcolor.blue, 30, 0, 18);
						break;
					case 300:
						x = GetRand(140) + 240;
						y = GetRand(150) + 290;
						danmaku.Setdanmaku_Wave(x, y, 3, danmaku.dshu.large, danmaku.dcolor.purple, 30, 0, 18);
						break;
					case 360:
						youmu.vecx = (80 - 330) / 20;
						youmu.imgpoji = DotAct.left;
						youmu.vecy = (100 - 80) / 20;
						break;
					case 380:
						youmu.vecx = 0;
						youmu.vecy = 0;
						youmu.imgpoji = DotAct.common;
						break;
					case 420:
						youmu.vecx = (280 - 80) / 20;
						youmu.imgpoji = DotAct.right;
						youmu.vecy = (350 - 100) / 20;
						break;
					case 440:
						youmu.vecx = 0;
						youmu.vecy = 0;
						youmu.imgpoji = DotAct.common;
						break;
					case 480:
						youmu.vecx = (330 - youmu.x) / 20;
						youmu.vecy = (80 - youmu.y) / 20;
						youmu.imgpoji = DotAct.right;
						x = GetRand(162) + 30;
						y = GetRand(190) + 30;
						danmaku.Setdanmaku_Wave(x, y, 3, danmaku.dshu.large, danmaku.dcolor.red, 30, 0, 18);
						break;
					case 500:
						youmu.vecx = 0;
						youmu.vecy = 0;
						break;
					case 510:
						danmaku.Setdanmaku_ArrowRendan(x, y, danmaku.Getkakudo_Homing(x, y, j.x, j.y), danmaku.dshu.kunai, danmaku.dcolor.orange, 0, 7, 2, 0.5);
						danmaku.Setdanmaku_ArrowRendan(x, y, danmaku.Getkakudo_Homing(x, y, j.x, j.y) + 120, danmaku.dshu.kunai, danmaku.dcolor.orange, 0, 7, 2, 0.5);
						danmaku.Setdanmaku_ArrowRendan(x, y, danmaku.Getkakudo_Homing(x, y, j.x, j.y) - 120, danmaku.dshu.kunai, danmaku.dcolor.orange, 0, 7, 2, 0.5);
						break;
					case 555:
						x = GetRand(140) + 240;
						y = GetRand(190) + 30;
						danmaku.Setdanmaku_Wave(x, y, 3, danmaku.dshu.large, danmaku.dcolor.green, 30, 0, 18);
						break;
					case 585:
						danmaku.Setdanmaku_ArrowRendan(x, y, danmaku.Getkakudo_Homing(x, y, j.x, j.y), danmaku.dshu.kunai, danmaku.dcolor.yellow, 0, 7, 2, 0.5);
						danmaku.Setdanmaku_ArrowRendan(x, y, danmaku.Getkakudo_Homing(x, y, j.x, j.y) + 120, danmaku.dshu.kunai, danmaku.dcolor.yellow, 0, 7, 2, 0.5);
						danmaku.Setdanmaku_ArrowRendan(x, y, danmaku.Getkakudo_Homing(x, y, j.x, j.y) - 120, danmaku.dshu.kunai, danmaku.dcolor.yellow, 0, 7, 2, 0.5);
						break;
					case 630:
						x = GetRand(162) + 30;
						y = GetRand(150) + 290;
						danmaku.Setdanmaku_Wave(x, y, 3, danmaku.dshu.large, danmaku.dcolor.blue, 30, 0, 18);
						break;
					case 660:
						danmaku.Setdanmaku_ArrowRendan(x, y, danmaku.Getkakudo_Homing(x, y, j.x, j.y), danmaku.dshu.kunai, danmaku.dcolor.water, 0, 7, 2, 0.5);
						danmaku.Setdanmaku_ArrowRendan(x, y, danmaku.Getkakudo_Homing(x, y, j.x, j.y) + 120, danmaku.dshu.kunai, danmaku.dcolor.water, 0, 7, 2, 0.5);
						danmaku.Setdanmaku_ArrowRendan(x, y, danmaku.Getkakudo_Homing(x, y, j.x, j.y) - 120, danmaku.dshu.kunai, danmaku.dcolor.water, 0, 7, 2, 0.5);
						break;
					case 705:
						x = GetRand(140) + 240;
						y = GetRand(150) + 290;
						danmaku.Setdanmaku_Wave(x, y, 3, danmaku.dshu.large, danmaku.dcolor.purple, 30, 0, 18);
						break;
					case 735:
						danmaku.Setdanmaku_ArrowRendan(x, y, danmaku.Getkakudo_Homing(x, y, j.x, j.y), danmaku.dshu.kunai, danmaku.dcolor.pink, 0, 7, 2, 0.5);
						danmaku.Setdanmaku_ArrowRendan(x, y, danmaku.Getkakudo_Homing(x, y, j.x, j.y) + 120, danmaku.dshu.kunai, danmaku.dcolor.pink, 0, 7, 2, 0.5);
						danmaku.Setdanmaku_ArrowRendan(x, y, danmaku.Getkakudo_Homing(x, y, j.x, j.y) - 120, danmaku.dshu.kunai, danmaku.dcolor.pink, 0, 7, 2, 0.5);
						break;
					}
					youmu.x += youmu.vecx;
					youmu.y += youmu.vecy;
				}
				break;
			case 23://スペルカード2
				DrawGraph((int)(youmu.x - 30), (int)(youmu.y - 45), youmudot[youmu.imgpoji], true);
				if (Currenttime < 8){
					Bosshit = false;
				}
				else{
					Bosshit = true;
				}
				if (Currenttime < 3){
					EndSpellkardEffect(320000, 0);
					StartSpellkardEffect(youmustand[1]);
					appeary += 1;
					if ((youmu.vecx < 0 && youmu.x <= 212) || (youmu.vecx > 0 && youmu.x >= 212)){
						youmu.vecx = 0;
						youmu.vecy = 0;
						youmu.x = 212;
						youmu.y = 100;
					}
					else{
						youmu.x += youmu.vecx;
						youmu.y += youmu.vecy;
					}
				}
				else
				{

					timetoflame = ((Currenttime - 4) % Looptime) * 60 + flame;
					int p;
					switch (timetoflame){
					case 1:
						danmaku.Setdanmaku_Wave(217, 50, 0.8, danmaku.dshu.mayu, danmaku.dcolor.water, 0, 0, 30, danmaku.worder.daen, 1.2);
						break;
					case 61:
						danmaku.Setdanmaku_Wave(217, 50, 0.8, danmaku.dshu.mayu, danmaku.dcolor.water, 0, 5, 30, danmaku.worder.daen, 1.2);
						break;
					case 121:
						danmaku.Setdanmaku_Wave(217, 50, 0.8, danmaku.dshu.mayu, danmaku.dcolor.water, 0, 0, 30, danmaku.worder.daen, 1.2);
						break;
					case 181:
						danmaku.Setdanmaku_Wave(217, 50, 0.8, danmaku.dshu.mayu, danmaku.dcolor.water, 0, 5, 30, danmaku.worder.daen, 1.2);
						break;
					case 241:
						danmaku.Setdanmaku_Wave(217, 50, 0.8, danmaku.dshu.mayu, danmaku.dcolor.water, 0, 0, 30, danmaku.worder.daen, 1.2);
						break;
					case 301:
						danmaku.Setdanmaku_Wave(217, 50, 0.8, danmaku.dshu.mayu, danmaku.dcolor.water, 0, 5, 30, danmaku.worder.daen, 1.2);
						break;
					case 420:
						int maxready,xmax, minready,xmin;
						for (xmax = (int)(j.x); xmax + 60 < 400; xmax += 60){
							continue;
						}
						for (xmin = (int)(j.x); xmin - 60 > 30; xmin -= 60){
							continue;
						}
						minready = 0;
						for (int Xmin = xmin; Xmin + 60 < (int)(j.x); Xmin += 60){
							danmaku.Setdanmaku_ArrowRendan(Xmin, 465, 270, danmaku.dshu.ring, danmaku.dcolor.pink, minready, 11, 3, 0.8);
							minready += 15;
						}
						maxready = 0;
						for (int Xmax = xmax; Xmax - 60 > (int)(j.x) - 20; Xmax -= 60){
							danmaku.Setdanmaku_ArrowRendan(Xmax, 465, 270, danmaku.dshu.ring, danmaku.dcolor.pink, maxready, 11, 3, 0.8);
							maxready += 15;
						}
						if (maxready > minready){
							maxready += 15;
							danmaku.Setdanmaku_ArrowRendan((int)(j.x), 465, 270, danmaku.dshu.ring, danmaku.dcolor.pink, maxready, 11, 3, 0.8);
						}
						else{
							minready += 15;
							danmaku.Setdanmaku_ArrowRendan((int)(j.x), 465, 270, danmaku.dshu.ring, danmaku.dcolor.pink, minready, 11, 3, 0.8);
						}
						break;
					case 480:
						p = danmaku.dan[0].np;
						while (p != danmaku.tail){
							if (danmaku.dan[p].danshu == danmaku.dshu.ring && danmaku.ddan[p].ready == 0){
								danmaku.dan[p].vecy *= 1.5;
								danmaku.dan[p].color = danmaku.dcolor.purple;
							}
							p = danmaku.dan[p].np;
						}
						danmaku.Setdanmaku_Wave((int)(youmu.x), (int)(youmu.y), 2, danmaku.dshu.ring, danmaku.dcolor.pink, 0, danmaku.Getkakudo_Homing(youmu.x, youmu.y, j.x, j.y), 30);
						break;
					case 540:
						p = danmaku.dan[0].np;
						while (p != danmaku.tail){
							if (danmaku.dan[p].danshu == danmaku.dshu.ring){
								danmaku.dan[p].vecy *= 1.5;
							}
							p = danmaku.dan[p].np;
						}
						danmaku.Setdanmaku_Wave((int)(youmu.x), (int)(youmu.y), 2, danmaku.dshu.ring, danmaku.dcolor.pink, 0, danmaku.Getkakudo_Homing(youmu.x, youmu.y, j.x, j.y), 30);
						break;
					}
				}
				break;
			case 24://通常3
				if (youmu.imgpoji == DotAct.act2){
					double  angle = atan2(youmu.vecy, youmu.vecx);
					DrawRotaGraph((int)(youmu.x), (int)(youmu.y), 1, angle, youmudot[youmu.imgpoji], true);
				}
				else{
					DrawGraph((int)(youmu.x - 30), (int)(youmu.y - 45), youmudot[youmu.imgpoji], true);
				}
				if (Currenttime < 8){
					Bosshit = false;
				}
				else{
					Bosshit = true;
				}
				if (Currenttime < 3){
					EndSpellkardEffect(300000, SpellBonusScore);
				}
				else
				{
					timetoflame = ((Currenttime - 4) % Looptime) * 60 + flame;
					switch (timetoflame){
					case 1:
						danmaku.boundable = true;
						danmaku.Setdanmaku_ArrowRendan((int)(youmu.x), (int)(youmu.y), 225, danmaku.dshu.uroko, danmaku.dcolor.green, 0, 21, 6, 2.5);
						danmaku.Setdanmaku_ArrowRendan((int)(youmu.x), (int)(youmu.y), 315, danmaku.dshu.uroko, danmaku.dcolor.green, 0, 21, 6, 2.5);
						break;
					case 300:
						youmu.imgpoji = DotAct.act2;
						if (youmu.x > j.x){
							youmu.vecx = (30 - youmu.x) / 10;
						}
						else{
							youmu.vecx = (380 - youmu.x) / 10;
						}
						youmu.vecy = (160 - youmu.y) / 10;
						break;
						if (youmu.x > 212){
							youmu.vecx = (30 - youmu.x) / 10;
						}
						else{
							youmu.vecx = (380 - youmu.x) / 10;
						}
						youmu.vecy = (220 - youmu.y) / 10;
						break;
					case 320:
						if (youmu.x > 212){
							youmu.vecx = (30 - youmu.x) / 10;
						}
						else{
							youmu.vecx = (380 - youmu.x) / 10;
						}
						youmu.vecy = (280 - youmu.y) / 10;
						break;
					case 330:
						if (youmu.x > 212){
							youmu.vecx = (30 - youmu.x) / 10;
						}
						else{
							youmu.vecx = (380 - youmu.x) / 10;
						}
						youmu.vecy = (340 - youmu.y) / 10;
						break;
					case 340:
						youmu.vecx = 0;
						youmu.vecy = 0;
						youmu.imgpoji = DotAct.common;
						break;
					case 400:
						int p;
						int dtail;
						dtail = danmaku.tail - 1;
						for (int a = 1; a < 8; a++){
							p = GetRand(dtail);
							danmaku.Setdanmaku_Wave((int)(danmaku.dan[p].x), (int)(danmaku.dan[p].y), 1, danmaku.dshu.kome, danmaku.dcolor.water, 0, danmaku.Getkakudo_Homing(danmaku.dan[p].x, danmaku.dan[p].y, j.x, j.y), 15);
						}
						break;
					case 420:
						youmu.vecx = (212 - youmu.x) / 80;
						youmu.vecy = (100 - youmu.y) / 80;
						danmaku.boundable = false;
						break;
					case 500:
						youmu.vecx = 0;
						youmu.vecy = 0;
						break;
					}
					youmu.x += youmu.vecx;
					youmu.y += youmu.vecy;
				}
				break;
			case 25://スペルカード3
				if (youmu.imgpoji == DotAct.act2){
					DrawRotaGraph((int)(youmu.x), (int)(youmu.y), 1, 0, youmudot[youmu.imgpoji], true);
				}
				else{
					DrawGraph((int)(youmu.x - 30), (int)(youmu.y - 45), youmudot[youmu.imgpoji], true);
				}
				if (Currenttime < 8){
					Bosshit = false;
				}
				else{
					Bosshit = true;
				}
				if (Currenttime < 3){
					EndSpellkardEffect(320000, 0);
					StartSpellkardEffect(youmustand[StandAct.excited]);
					appeary -= 5;
					if ((youmu.vecy < 0 && youmu.y < 250) || (youmu.vecy > 0 && youmu.y > 250)){
						youmu.vecx = 0;
						youmu.vecy = 0;
						youmu.x = 50;
						youmu.y = 250;
					}
					else{
						youmu.x += youmu.vecx;
						youmu.y += youmu.vecy;
					}
				}
				else
				{
					timetoflame = (Currenttime - 4) % Looptime * 60 + flame;
					switch (timetoflame){
					case 1:
						youmu.imgpoji = DotAct.act1;
						for (int x = 30; x < 400; x += 72){
							danmaku.Setdanmaku_Ko(x, 15, 0.2, danmaku.dshu.mayu, danmaku.dcolor.yellow, 0, 10, 170, 16);
						}
						break;
					case 120:
						if (youmu.x == 50){
							youmu.vecx = (380 - 50) / 80;
						}
						else{
							youmu.vecx = (50 - 380) / 80;
						}
						youmu.imgpoji = DotAct.act2;
						break;
					case 140:
						int p;
						p = danmaku.dan[0].np;
						while (p < danmaku.tail){
							if (danmaku.dan[p].danshu == danmaku.dshu.mayu){
								danmaku.dan[p].vecx *= 10;
								danmaku.dan[p].vecy *= 10;
								danmaku.dan[p].color = danmaku.dcolor.orange;
							}
							p = danmaku.dan[p].np;
						}
						for (int x = 40; x < 400; x += 80){
							danmaku.Setdanmaku_ChainRendan(x, 250, 2.5, 90, danmaku.dshu.uroko, danmaku.dcolor.purple, (x - 40) / 80 * 15, 16, 12);
							danmaku.Setdanmaku_ChainRendan(x, 250, 2.5, 270, danmaku.dshu.uroko, danmaku.dcolor.purple, (x - 40) / 80 * 15, 16, 12);
						}
						break;
					case 151:
						danmaku.Setdanmaku_Wave(212, 243, 0.75, danmaku.dshu.middle, danmaku.dcolor.blue, 0, 0, 20);
						break;
					case 161:
						danmaku.Setdanmaku_Wave(212, 243, 0.75, danmaku.dshu.ring, danmaku.dcolor.water, 0, danmaku.Getkakudo_Homing(212, 243, j.x, j.y), 30);
						break;
					case 171:
						danmaku.Setdanmaku_Wave(212, 243, 3, danmaku.dshu.big, danmaku.dcolor.green, 0, 0, 10);
						break;
					case 181:
						danmaku.Setdanmaku_Wave(212, 243, 3, danmaku.dshu.mayu, danmaku.dcolor.yellow, 0, 10, 9);
						break;
					case 191:
						danmaku.Setdanmaku_Wave(212, 243, 5, danmaku.dshu.kome, danmaku.dcolor.red, 0, danmaku.Getkakudo_Homing(212, 243, j.x, j.y), 15);
						break;
					case 200:
						if (youmu.vecx > 0){
							youmu.x = 380;
						}
						else{
							youmu.x = 50;
						}
						youmu.vecx = 0;
						youmu.imgpoji = DotAct.act1;
						break;
					}
					youmu.x += youmu.vecx;
				}

				break;
			case 26://スペルカード4
				DrawGraph((int)(youmu.x - 30), (int)(youmu.y - 45), youmudot[youmu.imgpoji], true);
				if (Currenttime < 8){
					Bosshit = false;
				}
				else{
					
					Bosshit = true;
				}
				if (Currenttime < 3){
					youmu.imgpoji = DotAct.common;
					EndSpellkardEffect(320000, SpellBonusScore);
					StartSpellkardEffect(youmustand[StandAct.excited]);
					appeary += 1;
					if ((youmu.vecy < 0 && youmu.y < 200) || (youmu.vecy > 0 && youmu.y > 200)){
						youmu.vecx = 0;
						youmu.vecy = 0;
						youmu.x = 212;
						youmu.y = 200;
					}
					else{
						youmu.x += youmu.vecx;
						youmu.y += youmu.vecy;
					}
				}
				else
				{
					if (Currenttime == 4 && flame == 1){ SpellBonusScore = 1200000; }
					timetoflame = (Currenttime - 4) % Looptime * 60 + flame;
					switch (timetoflame){
					case 31:
						danmaku.Setdanmaku_Ko(20, 300, 1.5, danmaku.dshu.large, danmaku.dcolor.purple, 0, 270, 450, 9);
						danmaku.Setdanmaku_Ko(404, 300, 1.5, danmaku.dshu.large, danmaku.dcolor.purple, 0, 90, 270, 9);
						break;
					case 181:
						int a;
						a = 0;
						double rad;
						int k;
						k = danmaku.Getkakudo_Homing(youmu.x, youmu.y, j.x, j.y);
						for (int b = 1; b < 4; b++){
							rad = k * PI / 180;
							danmaku.Setdanmaku_ChainRendan((int)(youmu.x + cos(rad) * 150), (int)(youmu.y + sin(rad) * 150), 2, k + 180, danmaku.dshu.ring, danmaku.dcolor.blue, a, 13, 15);
							a += 10;
							k += 120;
							if (k >= 360){
								k -= 360;
							}
						}
						k += 180;
						for (int b = 1; b < 4; b++){
							rad = k * PI / 180;
							danmaku.Setdanmaku_ChainRendan((int)(youmu.x + cos(rad) * 150), (int)(youmu.y + sin(rad) * 150), 2, k + 180, danmaku.dshu.ring, danmaku.dcolor.red, a, 13, 15);
							a += 10;
							k += 120;
							if (k >= 360){
								k -= 360;
							}
						}
						k += 90;
						for (int b = 1; b < 4; b++){
							rad = k * PI / 180;
							danmaku.Setdanmaku_ChainRendan((int)(youmu.x + cos(rad) * 120), (int)(youmu.y + sin(rad) * 150), 2, k + 180, danmaku.dshu.ring, danmaku.dcolor.orange, a, 13, 15);
							a += 10;
							k += 120;
							if (k >= 360){
								k -= 360;
							}
						}
						k += 180;
						for (int b = 1; b < 4; b++){
							rad = k * PI / 180;
							danmaku.Setdanmaku_ChainRendan((int)(youmu.x + cos(rad) * 120), (int)(youmu.y + sin(rad) * 150), 2, k + 180, danmaku.dshu.ring, danmaku.dcolor.yellow, a, 13, 15);
							a += 10;
							k += 120;
							if (k >= 360){
								k -= 360;
							}
						}
						break;
					case 301:
						danmaku.Setdanmaku_Wave((int)(youmu.x), (int)(youmu.y), 1.5, danmaku.dshu.large, danmaku.dcolor.green, 60, 0, 30, danmaku.worder.reverse, 200);
						break;
					}
					if (timetoflame > 29 && timetoflame < 180){
						int p = timetoflame - 29;//1 ～ 120
						int k = 0;
						double rad;
						for (int c = 0; c < p * 3; c++){
							rad = k * PI / 180;
							DrawGraph((int)(youmu.x + cos(rad) * 150), (int)(youmu.y + sin(rad) * 150), danmaku.danimg[1][1], true);
							k += 3;
						}
					}
					if (timetoflame > 179 && timetoflame < 300){
						int p = timetoflame - 179;//1 ～ 120
						p = 360 - p * 3;
						int k = 360;
						double rad;
						for (int c = 360; c > p; c--){
							rad = k * PI / 180;
							DrawGraph((int)(youmu.x + cos(rad) * 150), (int)(youmu.y + sin(rad) * 150), danmaku.danimg[1][1], true);
							k -= 3;
						}
					}
				}
				break;
			case 27://ボス戦終了　爆散
				if (Currenttime < 3){
					EndSpellkardEffect(300000, SpellBonusScore);
				}
				switch (Talkcount){
					/*
					*/
				case 12:
					BossStandPosition = StandAct.cry;
					if (PlayerData.jikinum == 3){
						selif1 = "";
						selif2 = "";
						JikiStandPosition = 8;
					}
					else{
						JikiStandPosition = 1;
						selif1 = "さてさて、正気に戻ったかな？";
						selif2 = "";
						Shadowflg = 1;
					}
					break;
				case 11:
					if (PlayerData.jikinum == 3){
						selif1 = "";
						selif2 = "";
						JikiStandPosition = 8;
					}
					else{
						JikiStandPosition = 1;
						selif1 = "これだけ炙られれば我にも返りますよ。";
						selif2 = "";
						Shadowflg = 0;
					}
					break;
				case 10:
					if (PlayerData.jikinum == 3){
						selif1 = "";
						selif2 = "";
					}
					else{
						Shadowflg = 1;
						selif1 = "それならばなお良し。私が相手でよかった";
						selif2 = "な。";
						JikiStandPosition = 9;
					}
					break;
				case 9:
					if (PlayerData.jikinum == 3){
						selif1 = "";
						selif2 = "";
						JikiStandPosition = 8;
					}
					else{
						Shadowflg = 0;
						selif1 = "私も失礼しましたし、異変解決に役立ちそう";
						selif2 = "な情報をあげます。";
						Shadowflg = 0;
					}
					break;
				case 8:
					if (PlayerData.jikinum == 3){
						selif1 = "私は別に戦うために動いてはいないけど";
						selif2 = "挑まれたら断れないわよね。";
						BossStandPosition = StandAct.cry;
						JikiStandPosition = 2;
						Shadowflg = 1;

					}
					else{
						JikiStandPosition = 2;
						selif1 = "ありがたく頂戴しよう。何か知っているのか？";
						selif2 = "";
						Shadowflg = 1;
					}
					break;
				case 7:
					if (PlayerData.jikinum == 3){
						selif1 = "え？そうなんですか。";
						selif2 = "";
						Shadowflg = 0;

					}
					else{
						selif1 = "実はあの二人がいなくなったのもあってか";
						selif2 = "結界の一部が緩んでいるんですよ。";
						Shadowflg = 0;
					}
					break;
				case 6:
					if (PlayerData.jikinum == 3){
						selif1 = "戦闘狂はあんただけ。こんなに焦ると";
						selif2 = "異変解決なんてできやしないいわ。";
						Shadowflg = 1;

					}
					else{
						selif1 = "結界…博麗大結界か？";
						selif2 = "";
						Shadowflg = 1;
					}
					break;
				case 5:
					if (PlayerData.jikinum == 3){
						selif1 = "あーやっと、まともな人がいたわ。咲夜さん";
						selif2 = "になら役立てられそう。これ。";
						Shadowflg = 0;
					}
					else{
						selif1 = "ええ。たぶんあの二人もその先に";
						selif2 = "いるんじゃないかと。";
						Shadowflg = 0;
					}
					break;
				case 4:
					if (PlayerData.jikinum == 3){
						selif1 = "役立てるモノって何？";
						selif2 = "";
						JikiStandPosition = 3;
						Shadowflg = 1;
						
					}
					else{
						selif1 = "さり気にとんでもない事実が判明したな。";
						selif2 = "情報提供感謝する。";
						Shadowflg = 1;
					}
					break;
				case 3:
					if (PlayerData.jikinum == 3){
						Shadowflg = 0;
						selif1 = "この先が次のステージにつながっています。";
						selif2 = "行ってみるといいですよ。";
						
					}
					else{
						selif1 = "こちらこそ。外の世界へ行くのですから";
						selif2 = "気をつけてくださいね。";
						Shadowflg = 0;
					}
					break;
				case 2:
					if (PlayerData.jikinum == 3){
						selif1 = "次のステージか。道案内の行き着く先に";
						selif2 = "黒幕がいることを願いましょう。";
						Shadowflg = 1;
						JikiStandPosition = 2;
					}
					else{
						selif1 = "それでは行ってくるか、外の世界へ。";
						selif2 = "";
						Shadowflg = 1;
					}
					break;
				case 1:
					if (j.slow > 0){
						TalkSkipCancel = true;
					}
					else{
						TalkSkipCancel = false;
					}
					break;
				}
				if (PlayerData.jikinum == 0){
					jikicolor = GetColor(255, 150, 150);
					bossy = 215;
					jikiy = 210;

				}
				else{
					jikicolor = GetColor(150, 200, 150);
					bossy = 210;
					jikiy = 215;

				}
				if (Talkcount > 1){
					BossTalking(youmustand[BossStandPosition], GetColor(80, 255, 80), jikicolor, 170, bossy, jikiy, 0);
				}
				break;
			}
		}
		danmaku.ProcessBossDanmaku(flame + Currenttime * 60, scene, PlayerData.jikinum, (int)(j.x), (int)(j.y));
		if (BossTalk == false){ r = DisplayBossStates(youmu.hitpoint, youmu.phasecount); }
		if (Spell){ DisplaySpellStates(); }
		SetDrawArea(1, 1, 639, 479);
		if ((scene == 28 && prescene == 27)){
			rr = false;//フェーズの進行度に応じてボス戦が終了する。
		}
		if (r != 0){
			r = -1;
		}
		return rr;
	}
	bool Stage3::ProcessOrin(int flame){
		bool rr = true;
		int r = 0;
		prescene = scene;
		if (flame == 1){
			Bosstime--;
		}//一秒経過ごとに加算。
		SetDrawArea(20, 15, 404, 465);
		if (scene != 0){
			switch (scene){
			case 6:
				orin.x += orin.vecx;
				orin.y += orin.vecy;
				if (orin.x == 212){
					orin.vecx = 0;
					orin.vecy = 0;
				}
				break;
			case 7:
				if (Currenttime > 1){
					Bosshit = true;
				}
				else{
					Bosshit = false;
				}
				timetoflame = (Currenttime % Looptime) * 60 + flame;
				switch (timetoflame){//X増分66/30F,Y増分45/30F
				case 1:
					orin.x = 212;
					orin.y = 155;
					break;
				case 2:
					danmaku.DanmakuRefresh();
					danmaku.sroot = danmaku.tail;
					if (orin.y < j.y){
						danmaku.Setdanmaku_ArrowRendan((int)(orin.x), (int)(orin.y), 60, 4, danmaku.dcolor.red, 0, 15, 29, 1);
						danmaku.Setdanmaku_ArrowRendan((int)(orin.x), (int)(orin.y), 120, 4, danmaku.dcolor.red, 0, 15, 29, 1);
					}
					else{
						danmaku.Setdanmaku_ArrowRendan((int)(orin.x), (int)(orin.y), 240, 4, danmaku.dcolor.red, 0, 15, 29, 1);
						danmaku.Setdanmaku_ArrowRendan((int)(orin.x), (int)(orin.y), 300, 4, danmaku.dcolor.red, 0, 15, 29, 1);
					}
					
					break;
				case 22:
					int p;
					p = danmaku.dan[0].np;
					while (p < danmaku.tail){
						if (danmaku.dan[p].danshu == danmaku.dshu.uroko && p >= danmaku.sroot){
							danmaku.ddan[p].ready = 15;
						}
						p = danmaku.dan[p].np;
					}
					break;
				case 121:
					//敵位置から見て左側(orin.x < jiki.j.x)にいれば自機側へ移動し、そうでなければ反対側へ移動
					if (orin.x < j.x){
						orin.vecx = 2.2;
						orin.vecy = 1.5;
					}
					else{
						orin.vecx = -2.2;
						orin.vecy = -1.5;
					}
					movable = 30;
					break;
				case 151:
					danmaku.DanmakuRefresh();
					danmaku.sroot = danmaku.tail;
					if (orin.y < j.y){
						danmaku.Setdanmaku_ArrowRendan((int)(orin.x), (int)(orin.y), 60, 4, danmaku.dcolor.yellow, 0, 15, 29, 1);
						danmaku.Setdanmaku_ArrowRendan((int)(orin.x), (int)(orin.y), 120, 4, danmaku.dcolor.yellow, 0, 15, 29, 1);
					}
					else{
						danmaku.Setdanmaku_ArrowRendan((int)(orin.x), (int)(orin.y), 240, 4, danmaku.dcolor.yellow, 0, 15, 29, 1);
						danmaku.Setdanmaku_ArrowRendan((int)(orin.x), (int)(orin.y), 300, 4, danmaku.dcolor.yellow, 0, 15, 29, 1);
					}
					break;
				case 172:
					int pp;
					pp = danmaku.dan[0].np;
					while (pp < danmaku.tail){
						if (danmaku.dan[pp].danshu == danmaku.dshu.uroko && pp >= danmaku.sroot){
							danmaku.ddan[pp].ready = 15;
						}
						pp = danmaku.dan[pp].np;
					}
					break;
				case 271:
					switch (upanddown){
					case 0:
						if (j.slow > 0){
							orin.vecx = 2.2;
							orin.vecy = -1.5;
							upanddown = 2;
						}
						else{
							orin.vecx = -2.2;
							orin.vecy = 1.5;
							upanddown = 1;
						}
						break;
					case 1://上部へ移動
						orin.vecx = 2.2;
						orin.vecy = -1.5;
						upanddown = 2;
						break;
					case 2://下部へ移動
						orin.vecx = -2.2;
						orin.vecy = 1.5;
						upanddown = 1;
						break;
					}
					movable = 30;
					break;
				case 301:
					if (orin.y > 171 || orin.x > 257){
						orin.vecx = -2.2;
						orin.vecy = -1.5;
					}
					else{
						orin.vecx = 2.2;
						orin.vecy = 1.5;
					}
					danmaku.Setdanmaku_Wave((int)(orin.x), (int)(orin.y), 2.5, 6, danmaku.dcolor.green, 0, danmaku.Getkakudo_Homing((int)(orin.x), (int)(orin.y), (int)(j.x), (int)(j.y)), 40);
					movable = 30;
					break;
				case 331:
					orin.vecx = (212 - orin.x) / 20;
					orin.vecy = (155 - orin.y) / 20;
					danmaku.Setdanmaku_ChainRendan((int)(orin.x), (int)(orin.y), 3, danmaku.Getkakudo_Homing((int)(orin.x), (int)(orin.y), (int)(j.x), (int)(j.y)), 5, danmaku.dcolor.green, 0, 10, 2);
					movable = 20;
					break;
				}
				if (movable != 0){
					orin.x += orin.vecx;
					orin.y += orin.vecy;
					movable--;
				}
				break;
			case 8:
				EndSpellkardEffect(200000, 0);
				orin.x += orin.vecx;
				orin.y += orin.vecy;
				break;
			case 13:
				if (Currenttime < 1){
					//登場シーン
					if ((int)(orin.x) != 212){
						orin.x += orin.vecx;
						orin.y += orin.vecy;
					}
					else{
						orin.vecx = 0;
						orin.vecy = 0;
						
					}
				}
				else{
					timetoflame = (Currenttime % Looptime) * 60 + flame;
					//戦闘シーン
					if (Currenttime > 1){
						Bosshit = true;
					}
					else{
						Bosshit = false;
					}
					orin.x += orin.vecx;
					orin.y += orin.vecy;
					timetoflame = ((Currenttime - 1) % Looptime) * 60 + flame;
					switch (timetoflame){
					case 1://45,135度方向へ速度差弾幕を発射
						danmaku.DanmakuRefresh();
						orin.vecx = 0;
						orin.vecy = 0;
						danmaku.Setdanmaku_ArrowRendan((int)(orin.x), (int)(orin.y), 45, 14, danmaku.dcolor.red, 0, 20, 10, 0.5);
						danmaku.Setdanmaku_ArrowRendan((int)(orin.x), (int)(orin.y), 135, 14, danmaku.dcolor.red, 0, 20, 10, 0.5);
						break;
					case 28:
						danmaku.Setdanmaku_Ko(404, 275, 2, 7, danmaku.dcolor.red, 0, 153, 209, 15);
						danmaku.Setdanmaku_Ko(20, 275, 2, 7, danmaku.dcolor.red, 0, 333, 389, 15);
						break;
					case 61://60,120度方向へ速度差弾幕を発射
						danmaku.Setdanmaku_ArrowRendan((int)(orin.x), (int)(orin.y), 60, 14, danmaku.dcolor.red, 0, 20, 10, 0.5);
						danmaku.Setdanmaku_ArrowRendan((int)(orin.x), (int)(orin.y), 120, 14, danmaku.dcolor.red, 0, 20, 10, 0.5);
						break;
					
					case 91://～75,15F間隔で楕円状波状弾幕を発射
						danmaku.Setdanmaku_Daenwave((int)(orin.x), (int)(orin.y), 1, 1.5, 4, danmaku.dcolor.orange, 0, 0, 36);
						break;
					case 100:
						danmaku.Setdanmaku_Ko(404, 410, 2, 7, danmaku.dcolor.red, 0, 153, 209, 15);
						danmaku.Setdanmaku_Ko(20, 410, 2, 7, danmaku.dcolor.red, 0, 333, 389, 15);
						break;
					case 106:
						danmaku.Setdanmaku_Daenwave((int)(orin.x), (int)(orin.y), 1, 1.5, 4, danmaku.dcolor.orange, 0, 2, 36);
						break;
					case 121:
						danmaku.Setdanmaku_Daenwave((int)(orin.x), (int)(orin.y), 1, 1.5, 4, danmaku.dcolor.orange, 0, 4, 36);
						break;
					case 136:
						danmaku.Setdanmaku_Daenwave((int)(orin.x), (int)(orin.y), 1, 1.5, 4, danmaku.dcolor.orange, 0, 6, 36);
						break;
					case 151://左右どちらかへ移動
						if (orin.x < j.x){
							orin.vecx = (double)(332 - 212) / 120;
							leftmove = 1;
						}
						else{
							orin.vecx = (double)(92 - 212) / 120;
							leftmove = -1;
						}
						orin.vecy = (double)(144 - 75) / 120;
						danmaku.Setdanmaku_ArrowRendan((int)(orin.x), (int)(orin.y), atan2(orin.vecx * leftmove, -0.575) * 180 / PI, 12, danmaku.dcolor.yellow, 0, 3, 4, 1);
						break;
					case 181:
						danmaku.Setdanmaku_ArrowRendan((int)(orin.x), (int)(orin.y), atan2(orin.vecx  * leftmove, -0.575) * 180 / PI, 12, danmaku.dcolor.yellow, 0, 3, 4, 1);
						break;
					case 211:
						danmaku.Setdanmaku_ArrowRendan((int)(orin.x), (int)(orin.y), atan2(orin.vecx   * leftmove, -0.575) * 180 / PI, 12, danmaku.dcolor.yellow, 0, 3, 4, 1);
						break;
					case 241:
						danmaku.Setdanmaku_ArrowRendan((int)(orin.x), (int)(orin.y), atan2(orin.vecx * leftmove, -0.575) * 180 / PI, 12, danmaku.dcolor.yellow, 0, 3, 4, 1);
						break;
					case 271://左右から下部へ移動
						if (orin.x > 212){
							orin.vecx = (double)(212 - 332) / 120;
							leftmove = -1;
						}
						else{
							orin.vecx = (double)(212 - 92) / 120;
							leftmove = 1;
						}
						orin.vecy = (double)(213 - 144) / 120;
						danmaku.Setdanmaku_ArrowRendan((int)(orin.x), (int)(orin.y), atan2(orin.vecx * leftmove, 0.575) * 180 / PI, 12, danmaku.dcolor.yellow, 0, 3, 4, 1);
						break;
					case 301:
						danmaku.Setdanmaku_ArrowRendan((int)(orin.x), (int)(orin.y), atan2(orin.vecx * leftmove, 0.575) * 180 / PI, 12, danmaku.dcolor.yellow, 0, 3, 4, 1);
						break;
					case 331:
						danmaku.Setdanmaku_ArrowRendan((int)(orin.x), (int)(orin.y), atan2(orin.vecx * leftmove, 0.575) * 180 / PI, 12, danmaku.dcolor.yellow, 0, 3, 4, 1);
						break;
					case 361:
						danmaku.Setdanmaku_ArrowRendan((int)(orin.x), (int)(orin.y), atan2(orin.vecx * leftmove, 0.575) * 180 / PI, 12, danmaku.dcolor.yellow, 0, 3, 4, 1);
						break;
					case 391://初期位置へ移動
						orin.vecy = (double)(75 - 213) / 30;
						orin.vecx = 0;
						break;
					}
				}

				break;
			case 14:
				//インターバル
				/*
				*/
				Maxhitpoint = 0;
				switch (Talkcount){
				case 4:
					Shadowflg = 0;
					JikiStandPosition = -1;
					BossStandPosition = 1;
					selif1 = "お！やるねぇお姉さん。";
					break;
				case 3:
					BossStandPosition = 2;
					selif1 = "あの二人も異変解決に動いてるみたい";
					selif2 = "だし、問題なさそうだね。";
					break;
				case 2:
					selif1 = "じゃあさ、ここらであたいと力試し";
					selif2 = "していきなよ。";
					break;
				case 1:
					BossStandPosition = 1;
					selif1 = "死体はそのままにしておくからさ。";
					selif2 = "";
					break;
				}
				BossTalking(orinstand[BossStandPosition], GetColor(220, 180, 80), 0, 170, 165, 0, 0);
				break;
			case 15:
				//スペルカード戦
				if (Currenttime > 4){
					Bosshit = true;
				}
				else{
					Bosshit = false;
				}
				if (Currenttime < 3){
					//登場シーン
					if ((orin.vecx > 0 && orin.x > 211) || (orin.vecx < 0 && orin.x < 213)){
						orin.x = 212;
						orin.vecx = 0;
					}
					if ((orin.vecy > 0 && orin.y > 99) || (orin.vecy < 0 && orin.y < 101)){
						orin.y = 100;
						orin.vecy = 0;
					}
					orin.x += orin.vecx;
					orin.y += orin.vecy;
					appeary += 2;
					if (StartSpellkardEffect(orinstand[1]) != 0){ r = -1; }
				}
				else{
					timetoflame = ((Currenttime - 3) % Looptime) * 60 + flame;
					switch (timetoflame){
					case 1://使い魔データを初期化
						ClearTukaima();
						break;
					case 21://両端方向へ使い魔を二匹召喚
						SetTukaima(orin.x, orin.y, (double)((92 - 212) / 30), 0, 4,0, 21, 200, 1, 1);
						SetTukaima(orin.x, orin.y, (double)((332 - 212) / 30), 0, 5,0, 21, 200, 1, 1);
						break;
					case 41://30,150度方向へ使い魔を二匹召喚
						SetTukaima(orin.x, orin.y, (double)(120 * cos(30 * PI / 180) / 30), (double)(60 * sin(30 * PI / 180) / 30) , 3, 0, 41, 200, 1, 1);
						SetTukaima(orin.x, orin.y, (double)(120 * cos(150 * PI / 180) / 30), (double)(60 * sin(150 * PI / 180) / 30),2, 0, 41, 200, 1, 1);
						break;
					case 61://60,120度方向へ使い魔を二匹召喚
						SetTukaima(orin.x, orin.y, (double)(120 * cos(60 * PI / 180) / 30), (double)(60 * sin(60 * PI / 180) / 30) , 3, 0, 61, 200, 1, 1);
						SetTukaima(orin.x, orin.y, (double)(120 * cos(120 * PI / 180) / 30), (double)(60 * sin(120 * PI / 180) / 30), 2, 0, 61, 200, 1, 1);
						break;
					case 81://90度方向へ使い魔を召喚
						SetTukaima(orin.x -15, orin.y, 0, 2, 1,0, 81, 250, 1, 1);
						break;
					}
					r = ProcessTukaima(timetoflame);
				}
				break;
			case 16:
				//終了　爆散
				EndSpellkardEffect(300000, SpellBonusScore);
				break;
			}
			if (scene < 16){
				DrawGraph((int)(orin.x - 30), (int)(orin.y - 45), orindot[orin.imgpoji], true);
				danmaku.ProcessBossDanmaku(flame + Currenttime * 60, scene, PlayerData.jikinum, (int)(j.x), (int)(j.y));
			}
			
			
			if (BossTalk == false && scene > 6){ r = DisplayBossStates(orin.hitpoint, orin.phasecount); }
			if (Spell){
				DisplaySpellStates();
			}
		}
		SetDrawArea(1, 1, 639, 479);
		if ((scene == 9 && prescene == 8) || (scene == 16 && prescene == 17)){
			rr = false;//フェーズの進行度に応じてボス戦が終了する。
		}
		if (r != 0){
			r = -1;
		}
		return rr;

	}
	int Stage3::ProcessTukaima(int flame){
		int r = 0;
		int p = tukaima[0].np;
		while (p != ttail && tekicount != 0){
			tukaima[p].x += tukaima[p].vecx;
			tukaima[p].y += tukaima[p].vecy;
			if (flame - tukaima[p].start == 20 && tukaima[p].vecy == 0){
				danmaku.Setdanmaku_Wave((int)(tukaima[p].x), (int)(tukaima[p].y), 1.5, 4, danmaku.dcolor.red, 0, 0, 40);
			}
			if (flame - tukaima[p].start == 25 && tukaima[p].vecy == 0){
				danmaku.Setdanmaku_Wave((int)(tukaima[p].x), (int)(tukaima[p].y), 1.5, 4, danmaku.dcolor.red, 0, 5, 30);
			}
			if (flame - tukaima[p].start == 30 && tukaima[p].imgposi != 1){
				double vec = tukaima[p].vecx;
				switch (tukaima[p].imgposi){
				case 5:
					danmaku.Setdanmaku_Wave((int)(tukaima[p].x), (int)(tukaima[p].y), 2.5, 4, danmaku.dcolor.red, 0, 10, 20);
					tukaima[p].imgposi = 1;
					tukaima[p].vecx = tukaima[p].vecy;
					tukaima[p].vecy = vec;
					break;
				case 4:
					danmaku.Setdanmaku_Wave((int)(tukaima[p].x), (int)(tukaima[p].y), 2, 4, danmaku.dcolor.red, 0, 10, 20);
					tukaima[p].imgposi = 1;
					tukaima[p].vecx = tukaima[p].vecy;
					tukaima[p].vecy = vec * -1;
					break;
				case 3:
					tukaima[p].imgposi = 2;
					tukaima[p].vecx = tukaima[p].vecy * -1;
					tukaima[p].vecy = vec;
					if (p == 3 || p == 4){
						danmaku.Setdanmaku_Ko((int)(tukaima[p].x), (int)(tukaima[p].y), 2, 7, danmaku.dcolor.green, 0, danmaku.Getkakudo_Homing(tukaima[p].x, tukaima[p].y, j.x, j.y) - 60, danmaku.Getkakudo_Homing(tukaima[p].x, tukaima[p].y, j.x, j.y) + 60, 15);
					}
					else{
						danmaku.Setdanmaku_ArrowRendan((int)(tukaima[p].x), (int)(tukaima[p].y), danmaku.Getkakudo_Homing(tukaima[p].x, tukaima[p].y, j.x + 10, j.y), 5, danmaku.dcolor.red, 0, 10, 5.1, 1.6);
					}
					break;
				case 2:
					tukaima[p].imgposi = 3;
					tukaima[p].vecx = tukaima[p].vecy;
					tukaima[p].vecy = vec * -1;
					if (p == 3 || p == 4){
						danmaku.Setdanmaku_Ko((int)(tukaima[p].x), (int)(tukaima[p].y), 2, 7, danmaku.dcolor.green, 0, danmaku.Getkakudo_Homing(tukaima[p].x, tukaima[p].y, j.x, j.y) - 60, danmaku.Getkakudo_Homing(tukaima[p].x, tukaima[p].y, j.x, j.y) + 60, 15);
					}
					else{
						danmaku.Setdanmaku_ArrowRendan((int)(tukaima[p].x), (int)(tukaima[p].y), danmaku.Getkakudo_Homing(tukaima[p].x, tukaima[p].y, j.x - 10, j.y), 5, danmaku.dcolor.red, 0, 10, 5.1, 1.6);
					}
					break;
				}
			}
			if ((int)(tukaima[p].x) > 425 || (int)(tukaima[p].x) < -3 || (int)(tukaima[p].y) > 486 || (int)(tukaima[p].y) < -8){
				//範囲外に出たら消滅
				DeleteTukaima(p);
			} 
			else{
				
				DrawGraph((int)(tukaima[p].x), (int)(tukaima[p].y), orintukaima[tukaima[p].imgposi], true);
			}
			p = tukaima[p].np;
		}
		
		return r;
	}

	BOSU yuuka;
	BOSU youmu;
	BOSU orin;
	bool orinbuttle;//ボス戦が中ボスのお燐かどうかを示す変数です。falseの時は大ボス戦（幽香or妖夢)を示します。

	private:

	int back;
	int orinspellback;
	int bossback;
	int yuukaspellback;
	int youmuspellback;
	static int yuukadot[5];//0.common ,1.act1,2.act2,3.left ,4.right
	static int youmudot[5];//0.common ,1.act1,2.act2,3.left ,4.right
	static int orindot[4];//0.cat ,1.humancommon
	static int youmustand[11];//1.common,2.fine,
	static int yuukastand[11];//1.common,2.fine,3.lessface,4.clame,5.cheer 6.cry
	static int orinstand[3];//1.common 2.fine
	static int orintukaima[6];//1.common,2.comleft,3.comright,4.left,5.right
	//common,left,right,act1,act2
	short movable;//移動できるフレーム数を示す変数です。0になったら移動しません。
	short upanddown;//上下どちらかに移動するかを示す変数です。0 = 初期値,1 = 上部へ移動,2 = 下部へ移動
	bool anotherspeedup;//二匹のうちどちらかが撃墜されたかを示す変数です。
	short leftmove;	//敵がランダムで左右へ移動する時どちらへ移動したかを示す変数です。1の場合左方向へ移動し、-1の場合は右方向へ移動したことを意味します。
	int x, y;
};
int Stage3::orinstand[3] = { 0, 0, 0 };
int Stage3::yuukastand[11] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
int Stage3::youmustand[11] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
int Stage3::orindot[4] = { 0, 0, 0, 0 };
int Stage3::yuukadot[5] = { 0, 0, 0, 0, 0 };
int Stage3::youmudot[5] = { 0, 0, 0, 0, 0 };
int Stage3::orintukaima[6] = { 0, 0, 0, 0, 0, 0 };
class S2D:public Danmaku{
public:
	int ProcessDanmaku(int flame,int scene){
		int r = 0;
		int p = dan[0].np;
		while(p != tail && p != 0 && dancount != 0){
			if(ddan[p].ready == 0){
				dan[p].x += dan[p].vecx;
				dan[p].y -= dan[p].vecy;
			}else{
				ddan[p].ready--;
			}
			
			p = dan[p].np;
		}
		if(PasteDanmaku() != 0){r = -1;}
		if(r == -1){
			r = -1;
		}
		
		return r;
	};
	int ProcessBossDanmaku(int flame, int scene, int jikinum,int x,int y){
		//主にボス戦において通常とは異なる弾幕の動きを表現するときに使われるオーバーロードです。xとyは敵の座標を示します。
		int r = 0;
		if (flame % 30 == 0){ DanmakuRefresh(); }
		int p = dan[0].np;

		while (p != tail && p != 0 && dancount != 0){
			if (ddan[p].ready == 0){
				
				switch (scene){
				case 9:
					if (jikinum == 1 || jikinum == 3){
						//中ボス小傘通常戦
						if ((int)(sqrt(pow(dan[p].x - x, 2.0) + pow(dan[p].y - y, 2.0))) > 150 && dan[p].danshu == dshu.hahen){
							dan[p].x += dan[p].vecx / 2;//ここでのx,yはjx,jy
							dan[p].y -= dan[p].vecy / 2;
						}
						else{
							if (dan[p].danshu == dshu.hahen){
								dan[p].color = dcolor.water;
								dan[p].x += dan[p].vecx;
								dan[p].y -= dan[p].vecy;
							}
							else{
								dan[p].x += dan[p].vecx;
								dan[p].y -= dan[p].vecy;
							}
							
						}
					}
					else{
						//中ボスミスティア通常戦
						dan[p].x += dan[p].vecx;
						dan[p].y -= dan[p].vecy;
						if (dan[p].danshu == 6){//ここでのx,yはjx,jy
							if ((int)(sqrt(pow(dan[p].x - x, 2.0) + pow(dan[p].y - y, 2.0))) == 60){
								ddan[p].ready = 12;
							}
						}
					}
					break;
				case 10:
					dan[p].x += dan[p].vecx;
					dan[p].y -= dan[p].vecy;
					break;
				case 16:
					if (jikinum == 1 || jikinum == 3){
						//大ボス小傘戦　通常1
						if (dan[p].danshu == dshu.ring && (int)(sqrt(pow(dan[p].x - x, 2.0) + pow(dan[p].y - y, 2.0))) > 150){
							dan[p].x += dan[p].vecx / 2;
							dan[p].y -= dan[p].vecy / 2;
						}
						else{
							dan[p].x += dan[p].vecx;
							dan[p].y -= dan[p].vecy;
						}
					}
					else{
						//大ボスミスティア戦　通常1
						dan[p].x += dan[p].vecx;
						dan[p].y -= dan[p].vecy;
						if (dan[p].danshu == dshu.ring){//ここでのx,yはbossx,bossy
							if ((int)(sqrt(pow(dan[p].x - x, 2.0) + pow(dan[p].y - y, 2.0))) > 102 && dan[p].danshu == dshu.ring && (int)(sqrt(pow(dan[p].x - x, 2.0) + pow(dan[p].y - y, 2.0))) < 106){
								ddan[p].ready = 120;
								dan[p].x += dan[p].vecx;
								dan[p].y -= dan[p].vecy;
								dan[p].vecx *= 1.5;
								dan[p].vecy *= 1.5;
							}
						}
					}
					break;
				case 17:
					dan[p].x += dan[p].vecx;
					dan[p].y -= dan[p].vecy;
					if (dan[p].danshu == dshu.onpu && ddan[p].boundcount < 1){
						if (dan[p].x + dan[p].vecx > 410)
						{
							dan[p].vecx *= -1;
							dan[p].x = 404;
							ddan[p].boundcount++;
						}
						if (dan[p].x - dan[p].vecx < 10)
						{
							dan[p].x = 20;
							ddan[p].boundcount++;
							dan[p].vecx *= -1;
						}
						if (dan[p].y + dan[p].vecy > 475)
						{
							dan[p].y = 465;
							dan[p].vecy *= -1;
							ddan[p].boundcount++;
						}
						if (dan[p].y - dan[p].vecy < 5)
						{
							dan[p].y = 15;
							dan[p].vecy *= -1;
							ddan[p].boundcount++;
						}
					}
					break;
				case 18:
					dan[p].x += dan[p].vecx;
					dan[p].y -= dan[p].vecy;
					if (dan[p].danshu == dshu.uroko){
						int k;
						if (dan[p].x + dan[p].vecx > 410)
						{
							dan[p].vecx *= -1;
							dan[p].x = 404;
							k = (int)(dan[p].imgangle * 180 / PI);
							if (dan[p].vecy < 0){
								k -= 270;
								dan[p].imgangle = (270 - k) * PI / 180;
							}
							else{
								k = 90 - k;
								dan[p].imgangle = (90 + k) * PI / 180;
							}
						}
						if (dan[p].x - dan[p].vecx < 10)
						{
							dan[p].vecx *= -1;
							dan[p].x = 20;
							k = (int)(dan[p].imgangle * 180 / PI);
							if (k >= 180){
								k -= 180;
								dan[p].imgangle = (360 - k) * PI / 180;
							}
							else{
								k = 180 - k;
								dan[p].imgangle = (90 - k) * PI / 180;
							}
						}
						if (dan[p].y - dan[p].vecy < 15)
						{
							dan[p].vecy *= -1;
							k = (int)(dan[p].imgangle * 180 / PI);
							dan[p].imgangle = (360 - k) * PI / 180;
						}
					}
				case 20:
					dan[p].x += dan[p].vecx;
					dan[p].y -= dan[p].vecy;
					if (dan[p].danshu == dshu.big){
						if (GetRand(2) == 2){
							ProcessBound(p);
						}
					}
					break;
				default:
					dan[p].x += dan[p].vecx;
					dan[p].y -= dan[p].vecy;
					break;
				}
				}
			else{
				ddan[p].ready--;
			}
			p = dan[p].np;
		}
		if (PasteDanmaku() != 0){ r = -1; }
		if (r == -1){
			r = -1;
		}
		return r;
	};
};
class Stage2:public Stage{
public:
	S2D danmaku;
	Stage2::Stage2(){
		for(int tc = 1;tc < 9;tc++){
			twicecircle[tc] = false;
		}
		for(int ds = 1;ds < 10;ds++){
			danshot[ds] = false;
		}
		int r;
		r = _chdir("data");
		
		r = _chdir("img");
		r = _chdir("Game");
		r = _chdir("Enemy");
		r = _chdir("Boss");
		mystiatukaima = LoadGraph("Tukaima.mystia.bmp");
		mystiadot[DotAct.common] = LoadGraph("Mystia.dot.common.png");
		mystiadot[DotAct.act1] = LoadGraph("Mystia.dot.act1.bmp");
		mystiastand[2] = LoadGraph("Mystia.fine.bmp");
		mystiastand[10] = LoadGraph("Mystia.cry.bmp");
		mystiastand[9] = LoadGraph("Mystia.strategy.bmp");
		mystiastand[8] = LoadGraph("Mystia.excited.bmp");
		mystiastand[7] = LoadGraph("Mystia.amaged.bmp");
		mystiastand[6] = LoadGraph("Mystia.surprised.bmp");
		mystiastand[1] = LoadGraph("Mystia.common.bmp");
		kogasadot[DotAct.common] = LoadGraph("Kogasa.dot.common.png");
		kogasadot[DotAct.act1] = LoadGraph("Kogasa.dot.act1.png");
		kogasadot[DotAct.left] = LoadGraph("Kogasa.dot.left.png");
		kogasadot[DotAct.right] = LoadGraph("Kogasa.dot.right.png");
		kogasastand[1] = LoadGraph("Kogasa.common.png");
		kogasastand[2] = LoadGraph("Kogasa.fine.png");
		kogasastand[StandAct.doubt] = LoadGraph("Kogasa.doubt.png");
		kogasastand[StandAct.excited] = LoadGraph("Kogasa.excited.png");
		kogasastand[10] = LoadGraph("Kogasa.cry.png");
		r = _chdir("..");
		r = _chdir("..");
		r = _chdir("..");
		r = _chdir("..");
		r = _chdir("..");
		
	}
	int Stage2::Nextscene(int newscene,int powercount){
		int r = 0;
		Begintime += Currenttime;
		Currenttime = 0;
		s = 0;
		if(newscene == 12){
			if(Begintime > 127){
				newscene++;
				scene++;
				Begintime = 127;
				Bossbuttle = false;//ボス戦をfalseに
			}
		}
		switch(newscene){
			case 0://最初に1秒間のラグを空ける。
				missflame = 300;
				s = -1;
				holizon.by = 770;
				r = _chdir("data");
				r = _chdir("Stage");
				r = _chdir("Stage2");
				holizon.back = LoadGraph("back.bmp");
				r = _chdir("..");
				r = _chdir("..");
				r = _chdir("..");
				danmaku.ClearDanmaku();
				danmaku.Clearkansu();
				danmaku.Inputkansu("Stage2");
				Begintime = 0;
				Endtime = 1;
				lastscene = 21;
				BossTalk = false;
				Bossbuttle = false;
				int dsc;
				for(dsc = 1;dsc < 100;dsc++){
					danshotcount[dsc] = 0;
				}
				for (dsc = 0; dsc < 10; dsc++){
					danshot[dsc] = false;
				}
				for (int tc = 1; tc < 9; tc++){
					twicecircle[tc] = false;
				}
				break;
			case 1://シーン1 0:01～0:06
				teki[0].np = 1;
				tail = 17;
				Endtime = 6;
				tekicount = 16;
				break;
			case 2://シーン2 0:07～0:13
				if(tekicount == 0){
					teki[0].np = 17;
				}
				tail = 33;
				Endtime = 13;
				tekicount += 16;
				break;
			case 3:
				if(tekicount == 0){
					teki[0].np = 33;
				}
				tail = 73;
				Endtime = 25;
				tekicount += 40;
				break;
			case 4:
				teki[0].np = 73;
				tail = 78;
				Endtime = 31;
				tekicount += 5;
				break;
			case 5:
				Endtime = 37;
				break;
			case 6:
				Begintime = 37;
				teki[0].np = 78;
				tail = 93;
				Endtime = 50;
				tekicount = 15;
				break;
			case 7:
				if(tekicount == 0){
					teki[0].np = 93;
				}
				tail = 99;
				Endtime = 57;
				tekicount += 6;
				break;
			case 8://中ボス登場　魅魔・咲夜は小傘、早苗・布都はミスティアが中ボス
				Bossbuttle = true;
				Bosshit = false;
				if (PlayerData.jikinum == 1 || PlayerData.jikinum == 3){
					//魅魔・咲夜
					BossName = "Tatara Kogasa";//ボス名を設定
					kogasa.imgpoji = DotAct.common;//ドット絵を設定(デフォルトで1)
					kogasa.hitr = 18;//ボスの当たり判定を設定
					kogasa.x = 192;//出現位置を設定
					kogasa.y = 465;
					if (powercount > 4){//自機の状況により難易度別に分ける
						kogasa.hitpoint = 3500;//体力を設定
					}
					else{
						kogasa.hitpoint = 2500;
					}
					kogasa.vecy = (165 - 465) / 60;//登場から停止までのベクトルを設定
				}else{
					//早苗・布都
					BossName = "Mystia Lorelei";//ボス名を設定
					mystia.imgpoji = DotAct.common;//ドット絵を設定(デフォルトで1)
					mystia.hitr = 18;//ボスの当たり判定を設定
					mystia.x = 15;//出現位置を設定
					mystia.y = 245;
					if (powercount > 4){//自機の状況により難易度別に分ける
						mystia.hitpoint = 3000;//体力を設定
					}
					else{
						mystia.hitpoint = 2000;
					}
					mystia.vecx = (222 - 15) / 60;//登場から停止までのベクトルを設定
					mystia.vecy = (105 - 245) / 60;
				}
				Endtime = 58;
				Bosstime = 1;
				break;
			case 9://中ボス戦通常 0:40
				Bosshit = true;//ボスの当たり判定を有効化
				Bosstime = 40;//ボスフェーズ(通常)時間を設定
				Endtime = 98;//ボスフェーズ終了時間を設定
				if (PlayerData.jikinum == 1 || PlayerData.jikinum == 3){
					Looptime = 5;//ループ間隔を設定
					Maxhitpoint = kogasa.hitpoint;//最大HPをコピー
					//開始と同時に弾幕を発射する場合はこのタイミングで発動
					jikikakudo = (double)(danmaku.Getkakudo_Homing(kogasa.x, kogasa.y, j.x, j.y));
					prejk = jikikakudo;
					dsht = false;
					kogasa.phasecount = 1;
					hitpointdisp = 1;
				}
				else{
					ClearTukaima();
					Looptime = 6;
					Maxhitpoint = mystia.hitpoint;
					mystia.vecx = 0;
					mystia.vecy = 0;
					mkakudo = 90;
					SetTukaima(20, 243, 0, 0.925, 1,180, -1, 10, 1, 0);
					SetTukaima(404, 243, 0, 0.925, 1,180, -1, 10, 1, 0);
					mystia.phasecount = 1;
					hitpointdisp = 1;
				}
				break;
			case 10://中ボス戦スペルカード 1:00
				Spell = true;
				Bosshit = false;
				Bosstime = 60;
				danmaku.ClearDanmaku();
				eff.RequestSE(eff.se.spell);
				appearx = 150;
				appeary = 40;
				if (PlayerData.jikinum == 1 || PlayerData.jikinum == 3){
					SpellKardName = "驚符「レイニーサプライズ」";
					Looptime = 10;
					kogasa.hitpoint = 2000 + 300 * powercount;
					Maxhitpoint = kogasa.hitpoint;
					kogasa.vecx = 0.6;
					kogasa.vecy = -1;
					danmaku.DirectInputkansu_daen(192, 110, 90, 45);
					SpellBonusScore = 1200000;
					decreasebonusperflame = SpellBonusScore / (Bosstime * 60);
					kogasa.phasecount--;
					hitpointdisp = 2;
				}
				else{
					SpellKardName = "速雀「ユーロビートスパロウ」";
					Looptime = 3;
					ClearTukaima();
					if (PlayerData.jikinum == 2){
						if (powercount < 5){
							mystia.hitpoint = 4000;
						}
						else{
							mystia.hitpoint = 3500;
						}
					}
					else
					{
						mystia.hitpoint = 5000;
					}
					kogasa.phasecount--;
					hitpointdisp = 2;
					Maxhitpoint = mystia.hitpoint;
					kakudo = 6;
					SpellBonusScore = 1200000;
					decreasebonusperflame = SpellBonusScore / (Bosstime * 60);
				}
				Endtime = 158;
				break;
			case 11://中ボス戦終了　退散 0:03
				eff.RequestSE(eff.se.spellend);
				Maxhitpoint = 0;
				danmaku.ClearDanmaku();
				Bosshit = false;
				Spell = false;
				Bosstime = 3;
				if (PlayerData.jikinum == 1 || PlayerData.jikinum == 3){
					kogasa.vecx = (10 - kogasa.x) / 60;
					kogasa.vecy = (50 - kogasa.y) / 60;
				}
				else{
					mystia.vecx = (10 - mystia.x) / 60;
					mystia.vecy = (50 - mystia.y) / 60;
				}
				totalscore += 200000;
				totalscore += SpellBonusScore;
				Endtime = Begintime + 3;
				break;
			case 12://シーン8 ～ 2:03
				Bossbuttle = false;//ボス戦をfalseに
				tekicount = 0;
				Endtime = 97;
				if (Endtime - Begintime > 4){
					if (Endtime - Begintime > 9){
						if (Endtime - Begintime > 14){
							teki[0].np = 99;
							tekicount = 3;
						}
						else{
							teki[0].np = 100;
							tekicount = 2;
							teki[100].ready = 0;
							teki[101].ready = 300;
						}
					}
					else{
						teki[0].np = 101;
						tekicount = 1;
						teki[101].ready = 0;
					}
				}
				tail = 102;
				break;
			case 13://シーン9 0:22
				if (tekicount == 0){
					teki[0].np = 102;
				}
				tail = 126;
				Endtime = Begintime + 22;
				tekicount += 24;
				break;
			case 14://シーン10 0:06
				if (tekicount == 0){
					teki[0].np = 126;
				}
				tail = 134;
				Endtime = Begintime + 6;
				tekicount += 8;
				break;
			case 15://大ボス戦インターバル
				Bossbuttle = true;
				BossTalk = true;
				Endtime = 1000;
				Bosstime = 1000;
				Maxhitpoint = 0;
				ChangeBGMNumber = 4;
				JikiStandPosition = 1;
				_chdir("data");
				_chdir("Stage");
				_chdir("Stage2");
				switch (PlayerData.jikinum){
				case 0:
					Talkcount = 25;
					ChangeBGMtalkcount = 4;
					holizon.bossback = LoadGraph("Bback.bmp");
					break;
				case 1:
					Talkcount = 26;
					ChangeBGMtalkcount = 4;
					holizon.bossback = LoadGraph("Aback.bmp");
					break;
				case 2:
					Talkcount = 24;
					ChangeBGMtalkcount = 4;
					holizon.bossback = LoadGraph("Bback.bmp");
					break;
				case 3:
					Talkcount = 22;
					ChangeBGMtalkcount = 3;
					holizon.bossback = LoadGraph("Aback.bmp");
					break;
				}
				_chdir("..");
				_chdir("..");
				_chdir("..");
				if (j.slow > 0){
					TalkSkipCancel = true;
				}
				else{
					TalkSkipCancel = false;
				}
				break;
			case 16://大ボス戦通常1
				BossTalk = false;
				Bosshit = true;//ボスの当たり判定を有効化
				Bosstime = 40;//ボスフェーズ(通常)時間を設定
				Endtime = 98;//ボスフェーズ終了時間を設定
				if (PlayerData.jikinum == 1 || PlayerData.jikinum == 3){
					BossName = "Tatara Kogasa";//ボス名を設定
					kogasa.imgpoji = DotAct.common;//ドット絵を設定(デフォルトでcommon)
					kogasa.hitr = 22;//ボスの当たり判定を設定
					kogasa.phasecount = 2;
					hitpointdisp = 1;
					Looptime = 6;//ループ間隔を設定
					kogasa.x = 208;
					kogasa.y = 100;
					kogasa.hitpoint = 2000 + 500 * powercount;
					Maxhitpoint = kogasa.hitpoint;//最大HPをコピー
					//開始と同時に弾幕を発射する場合はこのタイミングで発動
				}
				else{
					BossName = "Mystia Lorerei";//ボス名を設定
					mystia.imgpoji = DotAct.common;//ドット絵を設定(デフォルトでcommon)
					mystia.hitr = 22;//ボスの当たり判定を設定
					mystia.phasecount = 2;
					hitpointdisp = 1;
					Looptime = 10;
					mystia.x = 208;
					mystia.y = 100;
					mystia.hitpoint = 2000 + 500 * powercount;
					Maxhitpoint = mystia.hitpoint;
					danmaku.Setdanmaku_Wave((int)(mystia.x), (int)(mystia.y), 2.5, danmaku.dshu.ring, danmaku.dcolor.white, 0, 0, 8);
					danmaku.Setdanmaku_Wave((int)(mystia.x), (int)(mystia.y), 2.5, danmaku.dshu.ring, danmaku.dcolor.white, 0, 22, 8);
					danmaku.Setdanmaku_Wave((int)(mystia.x), (int)(mystia.y), 2.5, danmaku.dshu.ring, danmaku.dcolor.white, 10, 0, 8);
					danmaku.Setdanmaku_Wave((int)(mystia.x), (int)(mystia.y), 2.5, danmaku.dshu.ring, danmaku.dcolor.white, 10, 22, 8);
					}
				break;
			case 17://大ボス戦　スペルカード1枚目
				Spell = true;
				Bosshit = false;
				Bosstime = 60;
				danmaku.ClearDanmaku();
				eff.RequestSE(eff.se.spell);
				appearx = 150;
				appeary = 40;
				if (PlayerData.jikinum == 1 || PlayerData.jikinum == 3){
					SpellKardName = "虹符「アナザーレインボー」";
					Looptime = 12;
					kogasa.hitpoint = 2000 + 150 * powercount;
					Maxhitpoint = kogasa.hitpoint;
					hitpointdisp = 2;
					SpellBonusScore = 1800000;
					decreasebonusperflame = SpellBonusScore / (Bosstime * 60);
					SetItem(kogasa.x, kogasa.y, 1, 10, 10);
				}
				else{
					SpellKardName = "歌符「サラウンドボーカル」";
					Looptime = 11;
					ClearTukaima();
					mystia.hitpoint = 2000 + 800 * powercount;
					hitpointdisp = 2;
					Maxhitpoint = mystia.hitpoint;
					SpellBonusScore = 1200000;
					decreasebonusperflame = SpellBonusScore / (Bosstime * 60);
					SetItem(mystia.x, mystia.y, 1, 10, 10);
				}
				totalscore += 200000;
				
				break;
			case 18://大ボス戦通常2
				danmaku.ClearDanmaku();
				eff.RequestSE(eff.se.spellend);
				totalscore += SpellBonusScore;
				totalscore += 200000;
				Spell = false;
				Bosshit = true;//ボスの当たり判定を有効化
				Bosstime = 60;//ボスフェーズ(通常)時間を設定
				Endtime = Begintime + 60;//ボスフェーズ終了時間を設定
				if (SpellBonusScore != 0){
					SetItem((int)(kogasa.x), (int)(kogasa.y), 1, 110, 30);
				}
				else{
					SetItem((int)(kogasa.x), (int)(kogasa.y), 1, 130, 4);
				}
				if (PlayerData.jikinum == 1 || PlayerData.jikinum == 3){
					kogasa.hitpoint = 1500 + 750 * powercount;
					if (PlayerData.jikinum == 1){
						kogasa.hitpoint /= 1.5;
					}
					Looptime = 7;//ループ間隔を設定
					kogasa.phasecount--;
					hitpointdisp = 1;
					Maxhitpoint = kogasa.hitpoint;//最大HPをコピー
					//開始と同時に弾幕を発射する場合はこのタイミングで発動
					kogasa.vecx = (double)(58 - kogasa.x) / 80;
					kogasa.vecy = (double)(100 - kogasa.y) / 80;
					danmaku.DirectInputkansu_daen(208, 100, 150, 80);
				}
				else{
					Looptime = 6;
					mystia.vecx = (212 - mystia.x) / 40;
					mystia.vecy = (100 - mystia.y) / 40;
					mystia.hitpoint = 1500  + 750 * powercount;
					Maxhitpoint = mystia.hitpoint;
					mystia.phasecount--;
					hitpointdisp = 1;
					if (SpellBonusScore > 0){
						SetItem(mystia.x, mystia.y, 1, 10, 20);
					}
					else{
						SetItem(mystia.x, mystia.y, 1, 20, 5);
					}
				}
				break;
			case 19://大ボス戦　スペルカード2枚目
				Spell = true;
				Bosshit = false;
				Bosstime = 80;
				danmaku.ClearDanmaku();
				eff.RequestSE(eff.se.spell);
				appearx = 150;
				appeary = 40;
				if (PlayerData.jikinum == 1 || PlayerData.jikinum == 3){
					SpellKardName = "虹符「インエクスペディエンスレイン」";
					Looptime = 7;
					hitpointdisp = 2;
					kogasa.hitpoint = 2500 + 1000 * powercount;
					Maxhitpoint = kogasa.hitpoint;
					SpellBonusScore = 2200000;
					kogasa.vecx = (double)(208 - kogasa.x) / 80;
					kogasa.vecy = (double)(100 - kogasa.y) / 80;
					decreasebonusperflame = SpellBonusScore / (Bosstime * 60);
					SetItem((int)(kogasa.x), (int)(kogasa.y), 1, 10, 10);
				}
				else{
					SpellKardName = "蛾符「夜蛾の舞う路」";
					Looptime = 15;
					mystia.vecx = (212 - mystia.x) / 40;
					mystia.vecy = (243 - mystia.y) / 40;
					ClearTukaima();
					mystia.hitpoint = 2000 + 800 * powercount;
					Maxhitpoint = mystia.hitpoint;
					SpellBonusScore = 2200000;
					hitpointdisp = 2;
					decreasebonusperflame = SpellBonusScore / (Bosstime * 60);
					SetItem(mystia.x, mystia.y, 1, 10, 10);
				}
				totalscore += 220000;
				break;
			case 20://大ボス戦　スペルカード3枚目
				Spell = true;
				Bosshit = false;
				Bosstime = 80;
				danmaku.ClearDanmaku();
				eff.RequestSE(eff.se.spell);
				appearx = 150;
				appeary = 40;
				totalscore += 220000;
				totalscore += (SpellBonusScore);
				if (PlayerData.jikinum == 1 || PlayerData.jikinum == 3){
					SpellKardName = "幽雨「義理人情の怪」";
					Looptime = 12;
					kogasa.phasecount--;
					hitpointdisp = 3;
					kogasa.hitpoint = 2000 + 750 * powercount;
					Maxhitpoint = kogasa.hitpoint;
					if (SpellBonusScore != 0){
						SetItem((int)(kogasa.x), (int)(kogasa.x), 1, 20, 120);
					}
					else{
						SetItem((int)(kogasa.x), (int)(kogasa.x), 1, 20, 103);
					}
					PreBonusScore = SpellBonusScore;
					SpellBonusScore = 3000000;
					decreasebonusperflame = SpellBonusScore / (Bosstime * 60);
					
				}
				else{
					SpellKardName = "盲符「ブラインドフューチャー」";
					Looptime = 4;
					ClearTukaima();
					mystia.phasecount--;
					hitpointdisp = 3;
					mystia.hitpoint = 2000 + 800 * powercount;
					Maxhitpoint = mystia.hitpoint;
					PreBonusScore = SpellBonusScore;
					SpellBonusScore = 1200000;
					decreasebonusperflame = SpellBonusScore / (Bosstime * 60);
					if (SpellBonusScore > 0){
						SetItem(mystia.x, mystia.y, 1, 10, 20);
					}
					else{
						SetItem(mystia.x, mystia.y, 1, 20, 5);
					}
				}
				
				break;
			case 21://大ボス戦終了　爆散
				totalscore += (SpellBonusScore);
				totalscore += (300000);
				Maxhitpoint = 0;
				danmaku.ClearDanmaku();
				eff.RequestSE(eff.se.bossend);
				Spell = false;
				Bosshit = false;
				BossTalk = true;
				Endtime = 1000;
				Bosstime = 1000;
				switch (PlayerData.jikinum){
				case 0:
					Talkcount = 7;
					Shadowflg = 1;
					break;
				case 1:
					Talkcount = 8;
					Shadowflg = 1;
					break;
				case 2:
					Talkcount = 8;
					Shadowflg = 0;
					break;
				case 3:
					Talkcount = 11;
					Shadowflg = 1;
					break;
				}
				JikiStandPosition = 1;
				BossStandPosition = 1;
				StageClearscore = 2000000;
				if (j.slow > 0){
					TalkSkipCancel = true;
				}
				else{
					TalkSkipCancel = false;
				}
				result = false;
				break;
			case 22://次のステージに移行
				BossTalk = false;
				DeleteFontToHandle(SpellBonusfont);
				DeleteFontToHandle(ClearBonusfont);
				break;
			default:
				r = -1;
				break;
		}
		teki[teki[0].np].pp = 0;
		return r;
	}
	int Stage2::PasteHolizon(int flame){//フレーム更新ごとにステージ及び枠外の背景を描写します。この後にPD,PSが入ります。
    //384 × 450
		if (DrawBox(19, 14, 405, 466, color.white, FALSE) != 0){
			return -1;
		}
		if (Bossbuttle){
			if (Spell){
				int cl;
				if (PlayerData.jikinum == 1 || PlayerData.jikinum == 3){
					cl = GetColor(20, 20, 100);
				}
				else{
					cl = GetColor(50, 20, 40);
				}
				DrawBox(20, 15, 404, 465, cl, TRUE);
			}
			else{
				if (scene > 14){
					//大ボス戦
					if (flame < 119 && scene == 15) {
						if (flame < 61) {
							SetDrawBright(40, 40, 40);
							DrawExtendGraph(20, 15, 404, 465, DerivationGraph(100, holizon.by, 200, 225, holizon.back), false);
							SetDrawBright(255,255,255);
							SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255 * flame / 60);
							DrawBox(20, 15, 403, 464, GetColor(10, 10, 10), true);
							SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
						}
						else {
							DrawGraph(20, 15, holizon.bossback, false);
							SetDrawBlendMode(DX_BLENDMODE_ALPHA, (int)(255 / (flame - 60)));
							DrawBox(20, 15, 403, 464, GetColor(10, 10, 10), true);
							SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
						}
					}
					else {
						DrawGraph(20, 15, holizon.bossback, false);
					}
				}
				else{
					//中ボス戦
					SetDrawBright(40, 40, 40);
					DrawExtendGraph(20, 15, 404, 465, DerivationGraph(100, holizon.by, 200, 225, holizon.back), false);

					SetDrawBright(255, 255, 255);
					if (flame % 6 == 0)
					{
						holizon.by -= 1;
					}
					if (holizon.by == 0) {
						holizon.by = 767;
					}
				}
			}
		}
		else{
			SetDrawBright(40, 40, 40);
			DrawExtendGraph(20, 15, 404, 465, DerivationGraph(100, holizon.by, 200, 225, holizon.back), false);
			
			SetDrawBright(255, 255, 255);
			holizon.by -= 1;
			if (holizon.by == 0){
				holizon.by = 767;
			}
		
		}
	   //DrawFormatString(500,390,GetColor(255,255,255),"トータル%d秒経過",Begintime + Currenttime);
	   /*スコア・残機・ボム数・グレーズ・パワー段階などを描写*/
	   
		
	   return 0;
	}
	int Stage2::ProcessStage(int flame, int powercount){
		int r;//返り値を示す変数です。基本は1(Game Mode)か11(Practice Mode)ですが何らかのエラーが発生すれば-1になります。
		r = 2;
		prescene = scene;
		totalscore = 0;
		if(flame == 1){
			Currenttime++;
			s++;
			if (missnothit != 0){
				missnothit--;
			}
		}//一秒経過ごとに加算。
		if(scene == 22){//シーン が終了したらStage2はクリア//シーンごとに成功したら終了。
			if (PlayerData.choicestage == 0){
				r = 3;
			}
			else{
				r = 3;
			}
		}
		if (r == -1){
			r = -1;
		}
		return r;
	};
	int Stage2::ProcessEnemy(int flame){
		int p,r;
		r = 0;
		if(tekicount > 0){
			p = teki[0].np;
		}else{
			p = tail;
		}
		if(scene == 5){
			if (PlayerData.jikinum % 2 == 1){
				DrawStringToHandle(50,150,"Stage2A 真夜中の喧騒",GetColor(255,255,255),Stagefont);
				DrawStringToHandle(120,165,"～ Cheerful night",GetColor(255,255,255),Stagefont);
			}else{
				DrawStringToHandle(50,150,"Stage2B 真夜中の喧騒",GetColor(255,255,255),Stagefont);
				DrawStringToHandle(120,165,"～ Noisy night",GetColor(255,255,255),Stagefont);
			}
		}
		
		while(p != tail){
		    if(teki[p].ready == 0){
				if(teki[p].start == -1){teki[p].start = flame;}
				switch(scene){
					case 1:
						//移動処理
						if(tteki[p].usef == 0){
							teki[p].x += teki[p].vecx;
							teki[p].y += teki[p].vecy;
							if(p < 9){
								if(teki[p].x >= 317 && teki[p].y == 153){//1～8右円到達
									tteki[p].usef = 2;
									tteki[p].kanshu = 2;
									tteki[p].fugou = 1;
									teki[p].vecy = -1.5;
								}
								if(teki[p].x <= 107 && teki[p].y == 63){//1～8左円到達
									tteki[p].usef = 1;
									tteki[p].kanshu = 2;
									tteki[p].fugou = -1;
									teki[p].vecy = 1.5;
								}
							}else{
								if(teki[p].x <= 107 && teki[p].y == 153){//9～16左円到達
									tteki[p].usef = 1;
									tteki[p].kanshu = 2;
									tteki[p].fugou = -1;
									teki[p].vecy = -1.5;
								}
								if(teki[p].x >= 317 && teki[p].y == 63){//9～16右円到達
									tteki[p].usef = 2;
									tteki[p].kanshu = 2;
									tteki[p].fugou = 1;
									teki[p].vecy = 1.5;
								}
							}
						}else{
							//関数使用
							teki[p].y += teki[p].vecy;
							teki[p].x = danmaku.GetX(teki[p].y,tteki[p].usef,tteki[p].kanshu,tteki[p].fugou);
							if(p < 9){
								if(teki[p].y <= 64){//1～8右円上部到達
									tteki[p].usef = 0;
									teki[p].vecx = -5.25;
									teki[p].vecy = 0;
									teki[p].y = 63;
								}else{
									if(teki[p].y == 150){
										teki[p].vecy = -2;
									}
								}
								if(teki[p].y >= 107 && teki[p].x <= 63){//1～8左円左側到達
									teki[p].vecy = 4.475;
									teki[p].vecx = 0;
									teki[p].x = 62;
									tteki[p].usef = 0;
								}
							}else{
								if(teki[p].y <= 64){//9～16左円上部到達
									teki[p].vecx = 5.25;
									teki[p].vecy = 0;
									teki[p].y = 63;
									tteki[p].usef = 0;
								}else{
									if(teki[p].y == 150){
										teki[p].vecy = -2;
									}
								}
								if(teki[p].y >= 107 && teki[p].x >= 361){//9～16右円右側到達
									teki[p].vecy = 4.475;
									teki[p].vecx = 0;
									teki[p].x = 362;
									tteki[p].usef = 0;
								}
							}
						}
						break;
					case 2:
						if(tteki[p].usef == 0){
							//直線移動
							teki[p].x += teki[p].vecx;
							teki[p].y += teki[p].vecy;
							if(p > 24){
								if(teki[p].x >= 342 && teki[p].y != 153){//9～16右円到達
									tteki[p].usef = 2;
									tteki[p].kanshu = 2;
									tteki[p].fugou = 1;
									teki[p].vecy = -3;
									teki[p].x = 342;
								}
								if(teki[p].x <= 107 && teki[p].y == 63){//9～16左円到達
									teki[p].x = 107;
									tteki[p].usef = 1;
									tteki[p].kanshu = 2;
									tteki[p].fugou = -1;
									teki[p].vecy = 1.5;
								}
							}else{
								if(p > 16){
									if(teki[p].y >= 108 && teki[p].x == 62 && twicecircle[p - 16] == false){//1～8左円到達
										teki[p].y = 108;
										tteki[p].usef = 1;
										tteki[p].kanshu = 2;
										tteki[p].fugou = -1;
										teki[p].vecy = 1.5;
									}
									if(teki[p].x <= 107 && teki[p].y == 63){//1～8左円上部到達
										tteki[p].usef = 1;
										tteki[p].kanshu = 2;
										tteki[p].fugou = -1;
										teki[p].vecy = 1.5;
										twicecircle[p - 16] = true; 
									}
									if(teki[p].x >= 317 && teki[p].y == 153){//1～8右円到達
										tteki[p].usef = 2;
										tteki[p].kanshu = 2;
										tteki[p].fugou = 1;
										teki[p].vecy = -1.5;
									}
								}
							}
						}else{
							//関数使用
							teki[p].y += teki[p].vecy;
							teki[p].x = danmaku.GetX(teki[p].y, tteki[p].usef, tteki[p].kanshu, tteki[p].fugou);
							if(p < 17){
								if(teki[p].y >= 107 && teki[p].x >= 361){//シーン1 9～16右円右側到達
									teki[p].vecy = 4.475;
									teki[p].vecx = 0;
									teki[p].x = 362;
									tteki[p].usef = 0;
								}
							}else{
								if(p > 24){
									if(teki[p].y <= 66 && teki[p].x > 300){//9～16右円上部到達
										tteki[p].usef = 0;
										teki[p].vecx = -5.25;
										teki[p].vecy = 0;
										teki[p].y = 63;
									}else{
										if(teki[p].y <= 150 && teki[p].x > 300){
											teki[p].vecy = -2;
										}
									}
									if(teki[p].x == 107 && teki[p].y == 153){//9～16左円下部到達
										tteki[p].usef = 0;
										teki[p].vecx = 5.25;
										teki[p].vecy = 0;
										teki[p].y = 153;
									}
								}else{
									if(teki[p].x == 107 && teki[p].y == 153){//1～8左円下部到達
										tteki[p].usef = 0;
										teki[p].vecx = 5.25;
										teki[p].vecy = 0;
										teki[p].y = 153;
									}
									if(teki[p].y <= 66 && teki[p].x > 300){//1～8右円上部到達
										tteki[p].usef = 0;
										teki[p].vecx = -5.25;
										teki[p].vecy = 0;
										teki[p].y = 63;
									}else{
										if(teki[p].y <= 150 && teki[p].x > 300){
											teki[p].vecy = -2;
										}
									}
									if(teki[p].y >= 124 && twicecircle[p - 16]){
										tteki[p].usef = 0;
										teki[p].y = 124;
										teki[p].x = 65;
										teki[p].vecx = (404 - 65) / 80;
										teki[p].vecy = (465 - 124) / 80;
									}
								}
							}
						}
						//弾幕処理
						if(p > 16){
							if(p % 2 == 0){
								if(teki[p].start != flame && (teki[p].start - flame) % 200 == 0){
									danmaku.Setdanmaku_Ko((int)(teki[p].x), (int)(teki[p].y), 4, 6, danmaku.dcolor.glay, 0, danmaku.Getkakudo_Homing(teki[p].x, teki[p].y, j.x, j.y) + 10, danmaku.Getkakudo_Homing(teki[p].x, teki[p].y, j.x, j.y) - 10, 2);
								}
							}else{
								if(teki[p].start != flame && (teki[p].start - flame) % 300 == 0){
									danmaku.Setdanmaku_ChainRendan((int)(teki[p].x), (int)(teki[p].y), 4, danmaku.Getkakudo_Homing(teki[p].x, teki[p].y, j.x, j.y), 6, danmaku.dcolor.white, 0, 1, 0);
							    }
							}
						}
						break;
					case 3:
						if(tteki[p].usef == 0){
							//直線移動
							teki[p].x += teki[p].vecx;
							teki[p].y += teki[p].vecy;
							if(p < 43 && p > 32){
								//赤妖精1～10
								if(teki[p].y >= 108 && teki[p].y < 110){
									tteki[p].usef = 1;
									tteki[p].kanshu = 2;
									tteki[p].fugou = -1;
									teki[p].vecx = 0;
									teki[p].vecy = (139.8 - 108) / 20;
									teki[p].imgposi = 2;
									if(danshot[1] == false){
										danmaku.Setdanmaku_Wave((int)(teki[p].x), (int)(teki[p].y), 2, 7, danmaku.dcolor.red, 0, danmaku.Getkakudo_Homing(teki[p].x, teki[p].y, j.x, j.y), 8);
										danshot[1] = true;
									}
								}
								if(teki[p].x >= 180 && teki[p].y < 250){
									tteki[p].usef = 3;
									tteki[p].kanshu = 2;
									tteki[p].fugou = 1;
									teki[p].vecy = 0;
									teki[p].vecx = (212 - 180) / 10;
									if(danshot[2] == false){
										danmaku.Setdanmaku_Wave((int)(teki[p].x), (int)(teki[p].y), 2, 7, danmaku.dcolor.red, 0, danmaku.Getkakudo_Homing(teki[p].x, teki[p].y, j.x, j.y), 8);
										danshot[2] = true;
									}
								}
							}else{
								if(p < 54){
									//赤妖精11～20
									if(teki[p].y <= 318 && teki[p].y > 286){
										tteki[p].usef = 5;
										tteki[p].kanshu = 2;
										tteki[p].fugou = 1;
										teki[p].vecx = 0;
										teki[p].vecy = (286 - 318) / 10;
										teki[p].imgposi = 5;
										if(danshot[3] == false){
											danmaku.Setdanmaku_Wave((int)(teki[p].x), (int)(teki[p].y), 2, 7, danmaku.dcolor.red, 0, danmaku.Getkakudo_Homing(teki[p].x, teki[p].y, j.x, j.y), 8);
											danshot[3] = true;
										}
									}
									if(teki[p].y <= 76 && teki[p].vecy != 0){
										tteki[p].usef = 1;
										tteki[p].kanshu = 2;
										tteki[p].fugou = -1;
										teki[p].vecy = 0;
										teki[p].vecx = (107 - 138) / 10;
										if(danshot[4] == false){
											danmaku.Setdanmaku_Wave((int)(teki[p].x), (int)(teki[p].y), 2, 7, danmaku.dcolor.red, 0, danmaku.Getkakudo_Homing(teki[p].x, teki[p].y, j.x, j.y), 8);
											danshot[4] = true;
										}
									}else{
										if(teki[p].y < 182 && teki[p].y > 179 && danshot[5] == false){
											danmaku.Setdanmaku_Wave((int)(teki[p].x), (int)(teki[p].y), 2, 7, danmaku.dcolor.red, 0, danmaku.Getkakudo_Homing(teki[p].x, teki[p].y, j.x, j.y), 8);
											danshot[5] = true;
										}
									}
								}else{
									if(p < 63){
										//青妖精21～30
										if(teki[p].y >= 108 && teki[p].y < 110){
											tteki[p].usef = 2;
											tteki[p].kanshu = 2;
											tteki[p].fugou = 1;
											teki[p].vecx = 0;
											teki[p].vecy = (139.8 - 108) / 20;
											teki[p].imgposi = 1;
											if(danshot[6] == false){
												danmaku.Setdanmaku_Wave((int)(teki[p].x), (int)(teki[p].y), 2, 7, danmaku.dcolor.blue, 0, danmaku.Getkakudo_Homing(teki[p].x, teki[p].y, j.x, j.y), 8);
												danshot[6] = true;
											}
										}
										if(teki[p].x <= 243 && teki[p].y < 253){
											tteki[p].usef = 3;
											tteki[p].kanshu = 2;
											tteki[p].fugou = 1;
											teki[p].vecy = 0;
											teki[p].vecx = (212 - 243) / 10;
											if(danshot[7] == false){
												danmaku.Setdanmaku_Wave((int)(teki[p].x), (int)(teki[p].y), 2, 7, danmaku.dcolor.blue, 0, danmaku.Getkakudo_Homing(teki[p].x, teki[p].y, j.x, j.y), 8);
												danshot[7] = true;
											}
										}
									}else{
										//青妖精31～40
										if(teki[p].y <= 318 && teki[p].y > 286){
											tteki[p].usef = 4;
											tteki[p].kanshu = 2;
											tteki[p].fugou = -1;
											teki[p].vecx = 0;
											teki[p].vecy = (286 - 318) / 10;
											teki[p].imgposi = 6;
											if(danshot[8] == false){
												danmaku.Setdanmaku_Wave((int)(teki[p].x), (int)(teki[p].y), 2, 7, danmaku.dcolor.blue, 0, danmaku.Getkakudo_Homing(teki[p].x, teki[p].y, j.x, j.y), 8);
												danshot[8] = true;
											}
										}
										if(teki[p].y <= 76 && teki[p].vecy != 0){
											tteki[p].usef = 2;
											tteki[p].kanshu = 2;
											tteki[p].fugou = -1;
											teki[p].vecy = 0;
											teki[p].vecx = (317 - 285) / 10;
											if(danshot[9] == false){
												danmaku.Setdanmaku_Wave((int)(teki[p].x), (int)(teki[p].y), 2, 7, danmaku.dcolor.blue, 0, danmaku.Getkakudo_Homing(teki[p].x, teki[p].y, j.x, j.y), 8);
												danshot[9] = true;
											}
										}else{
											if(teki[p].y < 182 && teki[p].y > 179 && danshot[10] == false){
												danmaku.Setdanmaku_Wave((int)(teki[p].x), (int)(teki[p].y), 2, 7, danmaku.dcolor.blue, 0, danmaku.Getkakudo_Homing(teki[p].x, teki[p].y, j.x, j.y), 8);
												danshot[10] = true;
											}
										}
									}
								}
							}
						}else{
							//関数使用
							if(teki[p].vecx == 0){
								teki[p].y += teki[p].vecy;
								teki[p].x = danmaku.GetX(teki[p].y, tteki[p].usef, tteki[p].kanshu, tteki[p].fugou);
							}else{
								teki[p].x += teki[p].vecx;
								teki[p].y = danmaku.GetY(teki[p].x, tteki[p].usef, tteki[p].kanshu, tteki[p].fugou);
							}
							if(p < 43){
								//赤妖精1～10
								if(teki[p].y >= 137 && teki[p].vecx == 0){
									tteki[p].usef = 0;
									teki[p].vecx = (180.1 - 75.1) / 30;
									teki[p].vecy = (244.8 - 139.8) / 30;
								}
								if(teki[p].x >= 212 && teki[p].vecy == 0){
									tteki[p].usef = 0;
									teki[p].vecx = (404 - 212) / 40;
									teki[p].vecy = 0;
									teki[p].imgposi = 4;
								}
							}else{
								if(p < 53){
									//赤妖精11～20
									if(teki[p].y <= 286 && teki[p].vecx == 0){
										tteki[p].usef = 0;
										teki[p].vecx = (76 - 286) / 60;
										teki[p].vecy = (75 - 285) / 60;

									}
									if(teki[p].y <= 64 && teki[p].vecy == 0){
										tteki[p].usef = 0;
										teki[p].vecx = (20 - 107) / 20;
										teki[p].vecy = 0;
										teki[p].imgposi = 3;
									}
								}else{
									if(p < 63){
										//青妖精21～30
										if(teki[p].y >= 137 && teki[p].vecx == 0){
											tteki[p].usef = 0;
											teki[p].vecx = (243.8 - 348.1) / 30;
											teki[p].vecy = (244.8 - 139.8) / 30;
										}
										if(teki[p].x <= 212 && teki[p].vecy == 0){
											tteki[p].usef = 0;
											teki[p].vecx = (20 - 212) / 40;
											teki[p].vecy = 0;
											teki[p].imgposi = 3;
										}
									}else{
										//青妖精31～40
										if(teki[p].y <= 286 && teki[p].vecx == 0){
											tteki[p].usef = 0;
											teki[p].vecx = (348 - 138) / 60;
											teki[p].vecy = (75 - 285) / 60;
										}
										if(teki[p].y <= 64 && teki[p].vecy == 0){
											tteki[p].usef = 0;
											teki[p].vecx = (404 - 317) / 20;
											teki[p].vecy = 0;
											teki[p].imgposi = 4;
										}
									}
								}
							}
						}
						break;
					case 4:
						teki[p].y += teki[p].vecy;
						if(p == 73 && teki[p].y == 150){
							danmaku.Setdanmaku_Wave((int)(teki[p].x), (int)(teki[p].y), 2, 13, danmaku.dcolor.purple, 0, 0, 30);
							teki[p].vecy = (465 - 150) / 120;
						}
						if((p == 74 || p == 75) && teki[p].y == 135){
							danmaku.Setdanmaku_Ko((int)(teki[p].x), (int)(teki[p].y), 3, 6, danmaku.dcolor.blue, 0, danmaku.Getkakudo_Homing(teki[p].x, teki[p].y, j.x, j.y) + 30, danmaku.Getkakudo_Homing(teki[p].x, teki[p].y, j.x, j.y) - 30, 13);
						}
						if((p == 76 || p == 77) && teki[p].y == 330){
							danmaku.Setdanmaku_ChainRendan((int)(teki[p].x), (int)(teki[p].y), 4, danmaku.Getkakudo_Homing(teki[p].x, teki[p].y, j.x, j.y), 8, danmaku.dcolor.red, 0, 10, 10);
						}
						break;
					case 5:
						if(tekicount != 0){
							teki[p].y += teki[p].vecy;
						}
						break;
					case 6:
						if(tteki[p].usef == 0){
							teki[p].y += teki[p].vecy;
							if(p < 83){
								//青妖精1～5
								if(teki[p].y >= 192 && teki[p].x == 342){
									tteki[p].usef = 8;
									tteki[p].fugou = 1;
									tteki[p].kanshu = 2;
									teki[p].vecx = (42 - 342) / 100;
									teki[p].vecy = 0;
									if(p == 78){
										danmaku.Setdanmaku_Wave((int)(teki[p].x), (int)(teki[p].y), 4, 1, danmaku.dcolor.purple, 0, danmaku.Getkakudo_Homing(teki[p].x, teki[p].y, j.x, j.y), 12);
									}
								}
							}else{
								if(p < 88){
									//赤妖精6～10
									if(teki[p].y >= 192 && teki[p].x == 102){
										tteki[p].usef = 7;
										tteki[p].fugou = 1;
										tteki[p].kanshu = 2;
										teki[p].vecx = (282 - 102) / 75;
										teki[p].vecy = 0;
										if(p == 83){
											danmaku.Setdanmaku_Wave((int)(teki[p].x), (int)(teki[p].y), 4, 1, danmaku.dcolor.purple, 0, danmaku.Getkakudo_Homing(teki[p].x, teki[p].y, j.x, j.y), 12);
										}
									}
								}else{
									//青妖精11～15
									if(teki[p].y >= 192 && teki[p].x == 222){
										tteki[p].usef = 6;
										tteki[p].fugou = 1;
										tteki[p].kanshu = 2;
										teki[p].vecx = (162 - 222) / 50;
										teki[p].vecy = 0;
										if(p == 88){
											danmaku.Setdanmaku_Wave((int)(teki[p].x), (int)(teki[p].y), 4, 1, danmaku.dcolor.purple, 0, danmaku.Getkakudo_Homing(teki[p].x, teki[p].y, j.x, j.y), 12);
										}
									}
								}
							}
						}else{
							if(teki[p].vecx != 0){
								teki[p].x += teki[p].vecx;
								teki[p].y = danmaku.GetY(teki[p].x, tteki[p].usef, tteki[p].kanshu, tteki[p].fugou);
							}else{
								teki[p].y += teki[p].vecy;
								teki[p].x = danmaku.GetX(teki[p].y, tteki[p].usef, tteki[p].kanshu, tteki[p].fugou);
							}
							if(p < 83){
								if(teki[p].x <= 42){
									tteki[p].usef = 0;
									teki[p].x = 42;
									teki[p].vecx = 0;
									teki[p].vecy = -3.54;
								}else{
									if(p == 78 && (flame - teki[p].start) % 20 == 0){
										danmaku.Setdanmaku_ChainRendan((int)(teki[p].x), (int)(teki[p].y), 5, danmaku.Getkakudo_Homing(teki[p].x, teki[p].y, j.x, j.y) + 10, 6, danmaku.dcolor.purple, 0, 1, 0);
									}
								}
							}else{
								if(p < 88){
									if(teki[p].x >= 282){
										tteki[p].usef = 0;
										teki[p].x = 282;
										teki[p].vecx = 0;
										teki[p].vecy = -2.95;
									}else{
										if(p == 83 && (flame - teki[p].start) % 20 == 0){
											danmaku.Setdanmaku_ChainRendan((int)(teki[p].x), (int)(teki[p].y), 5, danmaku.Getkakudo_Homing(teki[p].x, teki[p].y, j.x, j.y) + 10, 6, danmaku.dcolor.purple, 0, 1, 0);
										}
									}
								}else{
									if(teki[p].x <= 162){
										tteki[p].usef = 0;
										teki[p].x = 162;
										teki[p].vecx = 0;
										teki[p].vecy = -2.95;
									}else{
										if(p == 88 && (flame - teki[p].start) % 20 == 0){
											danmaku.Setdanmaku_ChainRendan((int)(teki[p].x), (int)(teki[p].y), 5, danmaku.Getkakudo_Homing(teki[p].x, teki[p].y, j.x, j.y) + 10, 6, danmaku.dcolor.purple, 0, 1, 0);
										}
									}
								}
							}
						}
						break;
					case 7:
						if(tteki[p].usef == 0){
							//直線移動
							teki[p].x += teki[p].vecx;
							teki[p].y += teki[p].vecy;
							if(p < 96){
								//青妖精
								if(teki[p].y == 363 && teki[p].x >= 107){
									tteki[p].usef = 4;
									tteki[p].fugou = 1;
									tteki[p].kanshu = 2;
									teki[p].vecx = (138 - 107) / 20;
									teki[p].imgposi = 6;
								}
								if(teki[p].vecx != 0){
									if(teki[p].y <= 139){
										tteki[p].usef = 2;
										tteki[p].fugou = 1;
										tteki[p].kanshu = 2;
										teki[p].vecx = 0;
										teki[p].vecy = (108 - 139) / 20;
										teki[p].imgposi = 0;
									}
									else{
										if ((flame - teki[p].start) % 30 == 0 && teki[p].y != 363){
											danmaku.Setdanmaku_ChainRendan((int)(teki[p].x), (int)(teki[p].y), 5, danmaku.Getkakudo_Homing(teki[p].x, teki[p].y, j.x, j.y), 7, danmaku.dcolor.water, 0, 1, 0);
										}
									}
								}
							}
							else{
								//赤妖精
								if (teki[p].y == 363 && teki[p].x <= 317){
									tteki[p].usef = 5;
									tteki[p].fugou = 1;
									tteki[p].kanshu = 2;
									teki[p].vecx = (285 - 317) / 20;
									teki[p].imgposi = 5;
								}
								if (teki[p].vecx != 0){
									if (teki[p].x <= 75){
										tteki[p].usef = 1;
										tteki[p].fugou = -1;
										tteki[p].kanshu = 2;
										teki[p].vecx = 0;
										teki[p].vecy = (108 - 139) / 20;
										teki[p].imgposi = 0;
									}
									else{
										if ((flame - teki[p].start) % 30 == 0 && teki[p].y != 363){
											danmaku.Setdanmaku_ChainRendan((int)(teki[p].x), (int)(teki[p].y), 5, danmaku.Getkakudo_Homing(teki[p].x, teki[p].y, j.x, j.y), 7, danmaku.dcolor.orange, 0, 1, 0);
										}
									}
								}
							}
						}
						else{
							//関数使用
							if (teki[p].vecx == 0){
								teki[p].y += teki[p].vecy;
								teki[p].x = danmaku.GetX(teki[p].y, tteki[p].usef, tteki[p].kanshu, tteki[p].fugou);
							}
							else{
								teki[p].x += teki[p].vecx;
								teki[p].y = danmaku.GetY(teki[p].x, tteki[p].usef, tteki[p].kanshu, tteki[p].fugou);
							}
							if (p < 96){
								//青妖精
								if (tteki[p].usef == 4 && teki[p].x >= 107){
									tteki[p].usef = 0;
									teki[p].vecx = (348 - 138) / 60;
									teki[p].vecy = (139 - 349) / 60;
								}
								if (tteki[p].usef == 2 && teki[p].x >= 360){
									tteki[p].usef = 0;
									teki[p].vecx = 0;
									teki[p].vecy = (20 - 108) / 20;
								}
							}
							else{
								//赤妖精
								if (tteki[p].usef == 5 && teki[p].x <= 285){
									tteki[p].usef = 0;
									teki[p].vecx = (75 - 285) / 60;
									teki[p].vecy = (139 - 349) / 60;
								}
								if (tteki[p].usef == 1 && teki[p].x <= 64){
									tteki[p].usef = 0;
									teki[p].vecx = 0;
									teki[p].vecy = (20 - 108) / 20;
								}
							}
						}
						break;
					case 12:
						if (tteki[p].usef == 0){
							teki[p].y += teki[p].vecy;
							if (teki[p].vecy > 0 && teki[p].y >= 243){
								teki[p].y = 243;
								tteki[p].usef = p - 95;
								tteki[p].fugou = 1;
								tteki[p].kanshu = 3;
								teki[p].vecy = 0;
								switch (p){
								case 99:
									teki[p].vecx = -1.6;
									break;
								case 100:
									teki[p].vecx = 1.125;
									break;
								case 101:
									teki[p].vecx = -1.2;
									break;
								}
							}
						}
						else{
							teki[p].x += teki[p].vecx;
							teki[p].y = danmaku.GetY(teki[p].x, tteki[p].usef, tteki[p].kanshu, tteki[p].fugou);
							if (teki[p].y <= 250){
								teki[p].vecx = 0;
								switch (p){
								case 99:
									tteki[p].usef = 0;
									teki[p].vecy = -2.96;
									break;
								case 100:
									tteki[p].usef = 0;
									teki[p].vecy = -3.2;
									break;
								case 101:
									tteki[p].usef = 0;
									teki[p].vecy = -2.23;
									break;
								}
							}
							if (p == 99 && teki[p].x < 96){
								tteki[p].usef = 0;
								teki[p].vecy = -2.23;
							}
						}
						if ((flame - teki[p].start) % 60 == 0){
							danmaku.Setdanmaku_ChainRendan((int)(teki[p].x), (int)(teki[p].y), 2, danmaku.Getkakudo_Homing(teki[p].x, teki[p].y, j.x, j.y), 6, danmaku.dcolor.red, 0, 1, 0);
						}
						break;
					case 13:
						teki[p].x += teki[p].vecx;
						teki[p].y += teki[p].vecy;
						if (p > 121 && p < 126){
							if ((flame - teki[p].start) % 60 == 0){
								if ((flame - teki[p].start) % 120 == 0){
									danmaku.Setdanmaku_Ko((int)(teki[p].x), (int)(teki[p].y), 3, 7, danmaku.dcolor.purple, 0,134,46, 12);
								}
								else{
									danmaku.Setdanmaku_Ko((int)(teki[p].x), (int)(teki[p].y), 3, 7, danmaku.dcolor.purple, 0, 132, 48, 13);
								}
							}
						}
						break;
					case 14:
						teki[p].x += teki[p].vecx;
						teki[p].y += teki[p].vecy;
						if (p == 132){
							if (teki[p].x >= 54){
								teki[p].vecx *= -2;
								teki[p].imgposi = 4;
								danmaku.Setdanmaku_ChainRendan((int)(teki[p].x), (int)(teki[p].y), 7, danmaku.Getkakudo_Homing(teki[p].x, teki[p].y, j.x, j.y), 2, danmaku.dcolor.blue, 0, 10, 5);
							}
						}
						else{
							if (p == 133){
								if (teki[p].x <= 330){
									teki[p].vecx *= -2;
									teki[p].imgposi = 4;
									danmaku.Setdanmaku_ChainRendan((int)(teki[p].x), (int)(teki[p].y), 7, danmaku.Getkakudo_Homing(teki[p].x, teki[p].y, j.x, j.y), 2, danmaku.dcolor.blue, 0, 10, 5);
								}
							}
						}
						break;

				}
			}else{
				teki[p].ready -= 1;
			}
			p = teki[p].np;
		}
		if(tekicount > 0){
			if (PasteDot() != 0){ r = -1; }
			if (scene == 12 && tekicount == 0){
				scene++;
			}

		}		
		if(danmaku.dancount > 0){
			if(danmaku.ProcessDanmaku(flame,scene) != 0){r = -1;}
			if(flame % 30 == 0){danmaku.DanmakuRefresh();}
		}
		if(r == -1){
			r = -1;
		}
		
		return r;
	};
	bool Stage2::ProcessMystia(int flame){
	    bool rr = true;
		int r = 0;
		prescene = scene;
		if(flame == 1){
			Bosstime--;
		}//一秒経過ごとに加算。
		SetDrawArea(20,15,404,465);
		if(scene != 0){			
			switch(scene){
				case 8://中ボス登場
					mystia.y += mystia.vecy;
					mystia.x += mystia.vecx;
					break;
				case 9://中ボス戦　通常1
					mystia.y += mystia.vecy;
					mystia.x += mystia.vecx;
					if (Currenttime % Looptime < 1){
						if (flame == 1){
							SetTukaima(20, 243, 0, 0.925, 180,1, -1, 10, 1, 0);
							SetTukaima(404, 243, 0, 0.925, 180,1, -1, 10, 1, 0);
							danmaku.Setdanmaku_ArrowRendan((int)(mystia.x), (int)(mystia.y), mkakudo, 6, danmaku.dcolor.pink, 0, 3, 4, 2);
							mkakudo = 90;
						}
						if (flame % 4 == 0){
							danmaku.Setdanmaku_ArrowRendan((int)(mystia.x), (int)(mystia.y), mkakudo, 6, danmaku.dcolor.pink, 0, 3, 4, 2);
							mkakudo += 22.5;
						}
					}
					else{
						if (Currenttime % Looptime == 2){
							if (flame == 1){
								danmaku.Setdanmaku_ArrowRendan((int)(mystia.x), (int)(mystia.y), mkakudo, 6, danmaku.dcolor.pink, 0, 3, 4, 2);
								mkakudo = 90;
							}
							if (flame % 4 == 0){
								danmaku.Setdanmaku_ArrowRendan((int)(mystia.x), (int)(mystia.y), mkakudo, 6, danmaku.dcolor.pink, 0, 3, 4, 2);
								mkakudo += 22.5;
							}
						}
					}
					ProcessTukaima(flame + Currenttime * 60);
					break;
				case 10://中ボス戦　スペルカード1
					if (Currenttime < 4){
						//スペルカード宣言
						StartSpellkardEffect( mystiastand[1]);
						appeary += 1;
					}
					else{
						Bosshit = true;
						if (flame + 60 * (s - 4) < 151){
							switch (flame + 60 * (s - 4)){
							case 60:
								danmaku.Setdanmaku_Daenwave((int)(mystia.x), (int)(mystia.y), 5, 2.5, 9, danmaku.dcolor.red, 0, kakudo, 20);
								break;
							case 102:
								danmaku.Setdanmaku_Wave((int)(mystia.x), (int)(mystia.y), 2, 9, danmaku.dcolor.yellow, 0, kakudo, 20);
								break;
							case 132:
								danmaku.Setdanmaku_Daenwave((int)(mystia.x), (int)(mystia.y), 2, 1, 9, danmaku.dcolor.green, 0, kakudo, 20);
								break;
							case 144:
								danmaku.Setdanmaku_Wave((int)(mystia.x), (int)(mystia.y), 1.8, 9, danmaku.dcolor.blue, 0, kakudo, 20);
								break;
							}
							kakudo += 5;
						}
						else{
							if (flame % 10 == 0){
								if (flame % 20 == 0){
									if (flame % 30 == 0){
										if (flame % 40 == 0){
											if (flame % 50 == 0){
												danmaku.Setdanmaku_Wave((int)(mystia.x), (int)(mystia.y), 2.4, 9, danmaku.dcolor.red, 0, kakudo, 20);
											}
											else{
												danmaku.Setdanmaku_Daenwave((int)(mystia.x), (int)(mystia.y), 3, 1.6, 9, danmaku.dcolor.purple, 0, kakudo, 30);
											}
										}
										else{
											danmaku.Setdanmaku_Wave((int)(mystia.x), (int)(mystia.y), 3, 9, danmaku.dcolor.pink, 0, kakudo, 20);
										}
									}
									else{
										danmaku.Setdanmaku_Daenwave((int)(mystia.x), (int)(mystia.y), 3.75, 2.25, 9, danmaku.dcolor.orange, 0, kakudo, 30);
									}
								}
								else{
									danmaku.Setdanmaku_Wave((int)(mystia.x), (int)(mystia.y), 3, 9, danmaku.dcolor.blue, 0, danmaku.Getkakudo_Homing(mystia.x, mystia.y, j.x, j.y), 20);
								}
							}
							kakudo += 7;
						}
					}
					break;
				case 11://中ボス退散
					EndSpellkardEffect(200000,SpellBonusScore);
					if (Currenttime > 1){
						mystia.x += mystia.vecx;
						mystia.y += mystia.vecy;
					}
					break;
				case 15://大ボス戦インターバル
					/*
					
				　　
					
*/
					switch (Talkcount){
					case 25://最初は布都
						JikiStandPosition = 1;
						BossStandPosition = -1;
						selif1 = "さてさて、そろそろ聞き込み調査を";
						selif2 = "始めようか。";
						Shadowflg = 1;
						break;
					case 24:
						if (PlayerData.jikinum == 0){
							JikiStandPosition = 2;
							BossStandPosition = -1;
							selif1 = "こんな獣道でも、得られるものはある。";
							selif2 = "そう思うな。";
							Shadowflg = 1;
						}
						else{
							JikiStandPosition = 1;
							Shadowflg = 1;
							selif1 = "霊夢さんや魔理沙さんが解決に出ていな";
							selif2 = "い以上は私の出番なのでしょうが…";
						}
						break;
					case 23:
						if (PlayerData.jikinum == 0){
							BossStandPosition = -1;
							selif1 = "こんなところで迷子になって";
							selif2 = "";
							Shadowflg = 0;
							mystia.x = -200;
							mystia.y = 200;
						}
						else{
							selif1 = "それでも微々たるものです。";
							selif2 = "";
						}
						break;
					case 22://ここから早苗・布都
						if (PlayerData.jikinum == 0){
							BossStandPosition = 2;
							selif1 = "生きて帰れると思っているの？";
							selif2 = "";
							Shadowflg = 0;
							mystia.vecx = (double)(208 + 200) / 40;
							mystia.vecy = (double)(100 - 200) / 40;
							mystia.imgpoji = 0;
						}
						else{
							selif1 = "改めてその存在感に圧倒されてしまいます。";
							selif2 = "";

						}
						break;
					case 21:
						if (PlayerData.jikinum == 0){
							JikiStandPosition = 1;
							BossStandPosition = 2;
							selif1 = "迷子のつもりはないな、ところで";
							selif2 = "";
							Shadowflg = 1;
						}
						else{
							selif1 = "お？あれは…";
							Shadowflg = 0;
							mystia.x = -200;
							mystia.y = 200;
						}
						break;
					case 20:
						if (PlayerData.jikinum == 0){
							JikiStandPosition = 2;
							BossStandPosition = 2;
							selif1 = "お主ら猛禽にも聞きたいことがある。";
							selif2 = "";
							Shadowflg = 1;
						}
						else{
							Shadowflg = 0;
							BossStandPosition = 1;
							mystia.vecx = (double)(208 + 200) / 40;
							mystia.vecy = (double)(100 - 200) / 40;
							mystia.imgpoji = 0;
							selif1 = "さっきの人間ね。懲りずにまだ彷徨いて";
							selif2 = "いるの？";
						}
						break;
					case 19:
						if (PlayerData.jikinum == 0){
							JikiStandPosition = 1;
							BossStandPosition = 1;
							selif1 = "何でも聞いてよ。";
							selif2 = "";
							Shadowflg = 0;
						}
						else{
							Shadowflg = 1;
							selif1 = "あ、あなたは鳥獣伎楽の人ですね。";
							selif2 = "";
						}
						break;
					case 18:
						if (PlayerData.jikinum == 0){
							JikiStandPosition = 7;
							selif1 = "（襲う割りにえらく親身だな…）";
							selif2 = "";
							Shadowflg = 1;
						}
						else{
							Shadowflg = 0;
							selif1 = "そうそう、幻想郷随一のアーティストの…";

						}
						break;
					case 17:
						if (PlayerData.jikinum == 0){
							JikiStandPosition = 1;
							selif1 = "ここ最近で何かおかしいことはないか？";
							selif2 = "";
							Shadowflg = 1;
						}
						else{
							Shadowflg = 1;
							selif1 = "？";

						}
						break;
					case 16:
						if (PlayerData.jikinum == 0){
							JikiStandPosition = 1;
							BossStandPosition = 7;
							selif1 = "実を言うとね、屋台がどっか";
							selif2 = "いっちゃったの。";
							Shadowflg = 0;
						}
						else{
							Shadowflg = 0;
							BossName = "??????????????????";
							selif1 = "ええっと、言おうとしたけど";
							selif2 = "やっぱり思い出せない…。";
						}
						break;
					case 15:
						if (PlayerData.jikinum == 0){
							JikiStandPosition = 2;
							selif1 = "なるほど、もっともらしいな。";
							selif2 = "";
							Shadowflg = 1;
						}
						else{
							Shadowflg = 1;
							selif1 = "え、えぇ?!";
							selif2 = "";
						}
						break;
					case 14:
						if (PlayerData.jikinum == 0){
							BossStandPosition = 1;
							selif1 = "仕方ないから元の狩りに徹しているわけ。";
							selif2 = "";
							Shadowflg = 0;
						}
						else{
							Shadowflg = 0;
							selif1 = "ここ最近よ、私の名前が思い出";
							selif2 = "せないのは。";
						}
						break;
					case 13:
						if (PlayerData.jikinum == 0){
							JikiStandPosition = 1;
							selif1 = "お主は…確か歌謡の面子ではなかったか？";
							selif2 = "";
							Shadowflg = 1;
						}
						else{
							Shadowflg = 0;
							selif1 = "あんたは思い出せるの？";
							selif2 = "";
						}
						break;
					case 12:
						if (PlayerData.jikinum == 0){
							BossStandPosition = 2;
							selif1 = "やっぱそこついてくるよねぇ～。";
							selif2 = "";
							Shadowflg = 0;
						}
						else{
							Shadowflg = 1;
							selif1 = "東風谷早苗、当然じゃないですか。";
							selif2 = "";

						}
						break;
					case 11:
						if (PlayerData.jikinum == 0){
							JikiStandPosition = 1;
							selif1 = "夜雀は歌声で人を狂わす…それなのに";
							selif2 = "弾幕としての機能だけであれば";
							Shadowflg = 1;
						}
						else{
							Shadowflg = 1;
							selif1 = "そしてあなたは夜雀にして鳥獣伎楽の";
							selif2 = "メンバーミスティア・ローレライさんでしょう？";

						}
						break;
					case 10:
						if (PlayerData.jikinum == 0){
							JikiStandPosition = 1;
							selif1 = "目に見えるものに限らず、自らの能力";
							selif2 = "にも異変があると見るべきだろう。";
							Shadowflg = 1;
						}
						else{
							Shadowflg = 0;
							BossName = "ミスティア・ローレライ";
							selif1 = "ミスティア…そうだったかなぁ…？";
							selif2 = "";

						}
						break;
					case 9:
						if (PlayerData.jikinum == 0){
							BossStandPosition = 7;
							selif1 = "屋台もそうだけど、やっぱり歌声だけは…";
							selif2 = "";
							Shadowflg = 0;
						}
						else{
							Shadowflg = 1;
							selif1 = "まさか、あなた以外にも名前を思い出せ";
							selif2 = "ない人達がいるのですか？";

						}
						break;
					case 8:
						if (PlayerData.jikinum == 0){
							BossStandPosition = 6;
							selif1 = "歌ったり演奏したりするのが私の";
							selif2 = "性分なのにそれができないのは";
							Shadowflg = 0;
						}
						else{
							Shadowflg = 0;
							selif1 = "人じゃないんだけど、私に限らずよ。";
							selif2 = "";

						}
						break;
					case 7:
						if (PlayerData.jikinum == 0){
							BossStandPosition = 7;
							selif1 = "果たして生きていると言えるのかな…。";
							selif2 = "";
							Shadowflg = 0;
						}
						else{
							Shadowflg = 1;
							selif1 = "だれかの名前を忘れるのならともかく、";
							selif2 = "自分の名前を忘れてしまうのは";

						}
						break;
					case 6:
						if (PlayerData.jikinum == 0){
							JikiStandPosition = 1;
							selif1 = "あの魔法使いも同じか。自らを誇示する";
							selif2 = "物がなくなるのが今度の異変というわけか。";
							Shadowflg = 1;
						}
						else{
							Shadowflg = 1;
							selif1 = "異変以外の何者でもありません。";
							selif2 = "";

						}
						break;
					case 5:
						if (PlayerData.jikinum == 0){
							BossStandPosition = 1;
							selif1 = "そういうことね。だからさ…";
							selif2 = "";
							Shadowflg = 0;
						}
						else{
							Shadowflg = 0;
							selif1 = "そうそう、恒例の異変よね～って";
							selif2 = "私の名前を言ってくれたから";

						}
						break;
					case 4:
						if (PlayerData.jikinum == 0){
							BossStandPosition = 8;
							selif1 = "おなかと背中がくっつく前に";
							selif2 = "おとなしく狩られてよ！";
							Shadowflg = 0;
						}
						else{
							Shadowflg = 0;
							selif1 = "お礼に弾幕ごっこでお返しするわ。";
							selif2 = "";

						}
						break;
					case 3:
						if (PlayerData.jikinum == 0){
							JikiStandPosition = 9;
							selif1 = "我は一度死んだ人間だぞ。食すのには";
							selif2 = "向いていないが。";
							Shadowflg = 1;
						}
						else{
							Shadowflg = 1;
							selif1 = "そんなもの、と言いたいとこですが";
							selif2 = "望むところです！";
						}
						break;
					case 2:
						if (PlayerData.jikinum == 0){
							BossStandPosition = 8;
							selif1 = "逆ね、むしろそっちのほうが美味しいの。";
							selif2 = "加工肉みたいなものよ。";
							Shadowflg = 0;
						}
						else{
							Shadowflg = 0;
							selif1 = "勝った方が負けた方を好きにできる、";
							selif2 = "それでいくよ！";
						}
						break;
					case 1:
						if (PlayerData.jikinum == 0){
							JikiStandPosition = 8;
							selif1 = "獣道で面白い情報が入った。御代は";
							selif2 = "きっちり返すとしよう。";
							Shadowflg = 1;
						}
						else{
							Shadowflg = 1;
							selif1 = "言いましたね。名前を忘れても";
							selif2 = "それは忘れないでください。";
						}
						break;
					}
					int jikicolor;
					if ((PlayerData.jikinum == 0 && Talkcount < 23) || (PlayerData.jikinum == 2 && Talkcount < 21)){
						if (mystia.x < 208){
							mystia.x += mystia.vecx;
							mystia.y += mystia.vecy;
						}
						else{
							mystia.x = 208;
							mystia.y = 100;
						}
						DrawGraph((int)(mystia.x - 30), (int)(mystia.y - 45), mystiadot[mystia.imgpoji], true);
					}
					int bossy, jikiy;
					bossy = 150;
					jikiy = 210;
					if (PlayerData.jikinum == 0){
						jikicolor = GetColor(255, 150, 150);
						bossy = 210;
					}
					else{
						jikicolor = GetColor(150, 150, 100);
						jikiy = 210;
						bossy = 240;
					}
					BossTalking(mystiastand[BossStandPosition], GetColor(255, 100, 200), jikicolor, 170, bossy, jikiy, 0);
					break;
				case 16://大ボス戦　通常1
					Bosshit = true;
					timetoflame = (Currenttime % Looptime) * 60 + flame;
					switch (timetoflame){
					case 1:
						danmaku.Setdanmaku_Wave((int)(mystia.x), (int)(mystia.y), 2.5, danmaku.dshu.ring, danmaku.dcolor.pink, 0, 0, 8);
						danmaku.Setdanmaku_Wave((int)(mystia.x), (int)(mystia.y), 2.5, danmaku.dshu.ring, danmaku.dcolor.pink, 0, 22, 8);
						danmaku.Setdanmaku_Wave((int)(mystia.x), (int)(mystia.y), 2.5, danmaku.dshu.ring, danmaku.dcolor.pink, 10, 0, 8);
						danmaku.Setdanmaku_Wave((int)(mystia.x), (int)(mystia.y), 2.5, danmaku.dshu.ring, danmaku.dcolor.pink, 10, 22, 8);
						break;
					case 61:
						danmaku.Setdanmaku_Wave((int)(mystia.x), (int)(mystia.y), 2, danmaku.dshu.kome, danmaku.dcolor.pink, 0, 0, 60);
						break;
					case 101:
						danmaku.Setdanmaku_Wave((int)(mystia.x), (int)(mystia.y), 1.5, danmaku.dshu.middle, danmaku.dcolor.pink, 0, 0, 36);
						break;
					case 481:
						danmaku.Setdanmaku_Wave((int)(mystia.x), (int)(mystia.y), 1.5, danmaku.dshu.middle, danmaku.dcolor.pink, 0, 0, 36);
						break;
					}
					if ((timetoflame - 1) % 40 == 0 && timetoflame > 80 && timetoflame < 402 && Currenttime > 0){
						int tukaimacount = (timetoflame - 41) / 40;
						switch (tukaimacount){
						case 1:
							ClearTukaima();
							SetTukaima(20, 60, 1.28, 0, 1, 0, Currenttime * 60 + flame, 150, 3, 0);
							break;
						case 2:
							SetTukaima(404, 180, -1.28, 0, 1, 0, Currenttime * 60 + flame, 150, 0, 3);
							break;
						case 3:
							SetTukaima(20, 300, 1.28, 0, 1, 0, Currenttime * 60 + flame, 150, 3, 0);
							break;
						case 4:
							SetTukaima(404, 300, -1.28, 0, 1, 0, Currenttime * 60 + flame, 150, 0, 3);
							break;
						case 5:
							SetTukaima(20, 180, 1.28, 0, 1, 0, Currenttime * 60 + flame, 150, 3, 0);
							break;
						case 6:
							SetTukaima(404, 60, -1.28, 0, 1, 0, Currenttime * 60 + flame, 150, 0, 3);
							break;
						}
					}
					if (tekicount > 0){
						r = ProcessTukaima(Currenttime * 60 + flame);
					}
					break;
				case 17://大ボス戦　スペルカード1枚目
					if (Currenttime < 3){
						Bosshit = false;
						StartSpellkardEffect(mystiastand[1]);
						appeary += 1.5;
						if (mystia.y != 80){
							mystia.y -= 1;
						}
						mystia.vecy = 0;
						EndSpellkardEffect(150000, 0);
					}
					else{
						Bosshit = true;
						timetoflame = ((Currenttime - 3) % Looptime) * 60 + flame;
						switch (timetoflame){
						case 1:
							break;
						case 300:
							danmaku.Setdanmaku_Ko(20, 243, 1.5, danmaku.dshu.ring, danmaku.dcolor.orange, 0, 90, 270, 10);
							for (int k = danmaku.tail - 11; k < danmaku.tail; k++){
								danmaku.dan[k].vecx *= -1;
							}
							danmaku.Setdanmaku_Ko(404, 243, 1.5, danmaku.dshu.ring, danmaku.dcolor.orange, 0, 90, 270, 10);
							break;
						case 360:
							if (mystia.y < 100){
								mystia.vecy = 1.25;
							}
							else{
								mystia.vecy = -1.25;
							}
							break;
						}
						mystia.y += mystia.vecy;
						if ((mystia.vecy == 1.25 && mystia.y == 230) || (mystia.vecy == -1.25 && mystia.y == 80)){
							mystia.vecy = 0;
						}
						if ((timetoflame - 1) % 60 == 0){
							int k = 0;
							int c = 0;
							switch (timetoflame % 3){
							case 0:
								k = 0;
								c = danmaku.dcolor.purple;
								break;
							case 1:
								c = danmaku.dcolor.pink;
								k = 5;
								break;
							case 2:
								c = danmaku.dcolor.red;
								k = 7;
								break;
							}
							danmaku.Setdanmaku_Wave((int)(mystia.x), (int)(mystia.y), 2, danmaku.dshu.onpu, c, 0, k, 20);
						}
					}
					break;
				case 18://大ボス戦　通常2
					if (Currenttime < 4){
						Bosshit = false;
						mystia.x += mystia.vecx;
						mystia.y += mystia.vecy;
						if ((int)(mystia.x) == 212){
							mystia.vecx = 0;
							mystia.vecy = 0;
						}
						EndSpellkardEffect(200000, SpellBonusScore);
					}
					else{
						Bosshit = true;
						timetoflame = ((Currenttime - 4) % Looptime) * 60 + flame;
						switch (timetoflame){
						case 301:
							int kakudo = danmaku.Getkakudo_Homing(mystia.x, mystia.y, j.x, j.y);
							for (int k = kakudo; k < kakudo * 6; k += 72){
								danmaku.Setdanmaku_ArrowRendan((int)(mystia.x), (int)(mystia.y), (k % 360), danmaku.dshu.uroko, danmaku.dcolor.yellow, 0, 13, 2, 0.8);
							}
							break;
						}
						if (timetoflame % 60 == 1){
							danmaku.Setdanmaku_Wave((int)(mystia.x), (int)(mystia.y), 2, danmaku.dshu.middle, danmaku.dcolor.pink, 0, (Currenttime - 4) * 8, 20);
						}
					}
					break;
				case 19://大ボス戦　スペルカード2枚目
					if (Currenttime < 3){
						Bosshit = false;
						mystia.x += mystia.vecx;
						mystia.y += mystia.vecy;
						if ((int)(mystia.y) == 243){
							mystia.vecx = 0;
							mystia.vecy = 0;
						}
						appeary += 1;
						EndSpellkardEffect(250000, 0);
						StartSpellkardEffect( mystiastand[1]);
					}
					else{
						Bosshit = true;
						timetoflame = ((Currenttime - 3) % Looptime) * 60 + flame;
						switch (timetoflame){
						case 30:
							SetTukaima(152, 15, 0, 1.5, 0, 0, 0, 300, 5, 0);
							SetTukaima(272, 465, 0, -1.5, 0, 0, 0, 300, 0, 5);
							SetTukaima(20, 303, 1.5, 0, 0, 210, 0, 300, 0, 5);
							SetTukaima(404, 183, -1.5, 0, 0, 210, 0, 300, 5, 0);
							SetTukaima(272, 15, 0, 1.5, 0, 570, 0, 300, 5, 0);
							SetTukaima(152, 465, 0, -1.5, 0, 570, 0, 300, 0, 5);
							SetTukaima(20, 183, 1.5, 0, 0, 570, 0, 300, 5, 0);
							SetTukaima(404, 303, -1.5, 0, 0, 570, 0, 300, 0, 5);
							break;
						}
						if (timetoflame % 150 == 1){
							danmaku.Setdanmaku_Wave((int)(mystia.x), (int)(mystia.y), 2, danmaku.dshu.onpu, danmaku.dcolor.blue, 0, 0, 20);
						}
					}
					if (tekicount > 0){
						r = ProcessTukaima(Currenttime * 60 + flame);
					}
					break;
				case 20://大ボス戦　スペルカード3枚目
					if (Currenttime < 4){
						Bosshit = false;
						StartSpellkardEffect(mystiastand[1]);
						appeary += 1;
					}
					else{
						Bosshit = true;
						timetoflame = ((Currenttime - 4) % Looptime) * 60 + flame;
						switch (timetoflame){
						case 1:
							danmaku.Setdanmaku_Wave((int)(mystia.x), (int)(mystia.y), 2, danmaku.dshu.middle, danmaku.dcolor.pink, 0, danmaku.Getkakudo_Homing(mystia.x, mystia.y, j.x, j.y), 30);
							break;
						case 61:
							d = GetRand(2);
							double rp, rq;
							switch (d){
							case 1:
								rp = 3;
								rq = 1.5;
								break;
							case 2:
								rp = 1.5;
								rq = 3;
								break;
							}
							danmaku.Setdanmaku_Daenwave((int)(mystia.x), (int)(mystia.y), rp, rq, danmaku.dshu.mayu, danmaku.dcolor.pink, 0, 0, 20);
							break;
						case 121:
							switch (d){
							case 1:
								rp = 1.5;
								rq = 3;
								break;
							case 2:
								rp = 3;
								rq = 1.5;
								break;
							}
							danmaku.Setdanmaku_Daenwave((int)(mystia.x), (int)(mystia.y), rp, rq, danmaku.dshu.mayu, danmaku.dcolor.pink, 0, 0, 20);
							break;
						case 181:
							danmaku.Setdanmaku_Wave((int)(mystia.x), (int)(mystia.y), 2, danmaku.dshu.big, danmaku.dcolor.yellow, 0, 0, 6);
							break;
						}
					}
					break;
				case 21://大ボス戦終了
					/*
					*/
					switch (Talkcount){
					case 8:
						BossStandPosition = 10;
						selif1 = "あー負けた負けた。煮るなり焼くなりね。";
						selif2 = "";
						Shadowflg = 0;
						break;
					case 7:
						if (PlayerData.jikinum == 2){
							selif1 = "早速と言いたいところですが、出処が";
							selif2 = "分からない鶏肉は危険極まりありません。";
							Shadowflg = 1;
						}
						else{
							Shadowflg = 1;
							BossStandPosition = 10;
							selif1 = "いや、やはりお代はツケておこう。";
							selif2 = "";
						}
						break;
					case 6:
						if (PlayerData.jikinum == 2){
							selif1 = "産地偽装のリスクもありますから。";
							selif2 = "";
							Shadowflg = 1;
						}
						else{
							selif1 = "言うだけ言っといて黒焦げにしといて";
							selif2 = "締めの決めセリフがそれ？！";
							Shadowflg = 0;
						}
						break;
					case 5:
						if (PlayerData.jikinum == 2){
							selif1 = "結構ひどいけど、あんたも名前忘れる前に";
							selif2 = "この些細な異変を解決することね。";
							Shadowflg = 0;
						}
						else{
							selif1 = "異変解決中はそれだけに集中する。";
							selif2 = "そのあとに精算すればよい。";
							Shadowflg = 1;
						}
						break;
					case 4:
						if (PlayerData.jikinum == 2){
							BossStandPosition = -1;
							selif1 = "些細、ですか。確かにここ最近は大した";
							selif2 = "異変ではありませんでしたが";
							Shadowflg = 1;
						}
						else{
							selif1 = "そうだな、ここは自らを誇示するもの";
							selif2 = "を取り戻して返済しようじゃないか。";
							Shadowflg = 1;
						}
						break;
					case 3:
						if (PlayerData.jikinum == 2){
							selif1 = "今回ばかりは些細とは言いませんよね";
							selif2 = "…この異変。";
							Shadowflg = 1;
						}
						else{
							selif1 = "う～ん、即時払いもできなさそうだし、";
							selif2 = "それで折れちゃうじゃない。";
							Shadowflg = 0;
						}
						break;
					case 2:
						if (PlayerData.jikinum == 2){
							selif1 = "ここまできたら、誰かに任せず自分で";
							selif2 = "解決するのが一番でしょう。";
							Shadowflg = 1;
						}
						else{
							selif1 = "異変となれば必ず黒幕がいる。それを";
							selif2 = "懲らしめてやらせるよ。";
							Shadowflg = 1;
						}
						break;
					case 1:
						if (j.slow > 0){
							TalkSkipCancel = true;
						}
						else{
							TalkSkipCancel = false;
						}
						break;
					}
					bossy = 150;
					jikiy = 210;
					if (PlayerData.jikinum == 0){
						jikicolor = GetColor(255, 150, 150);
						bossy = 210;
					}
					else{
						jikicolor = GetColor(150, 150, 100);
						jikiy = 210;
						bossy = 240;
					}
					if (Talkcount > 1){
						BossTalking(mystiastand[BossStandPosition], GetColor(255, 100, 200), jikicolor, 170, bossy, jikiy, 0);
					}
					if (Currenttime < 4){
						EndSpellkardEffect(300000, SpellBonusScore);
					}
					break;
			}
			if(scene != 15 && scene != 21){
				DrawGraph((int)(mystia.x - 30),(int)(mystia.y - 45),mystiadot[mystia.imgpoji],true);
			}
		}
		int x, y;
		switch (scene){
		case 16:
			x = (int)(mystia.x);
			y = (int)(mystia.y);
			break;
		default:
			x = (int)(j.x);
			y = (int)(j.y);
			break;
		}
		
		danmaku.ProcessBossDanmaku(flame + Currenttime * 60, scene, PlayerData.jikinum, x, y);
		if (BossTalk == false){ r = DisplayBossStates(mystia.hitpoint, mystia.phasecount); }
		if (Spell){ DisplaySpellStates(); }
		if((scene == 12 && prescene == 11)/*||(scene == 22 && prescene == 21)*/){
			rr = false;//フェーズの進行度に応じてボス戦が終了する。
		}
		if(r != 0){
			r = -1;
		}
		return rr;
	}
	bool Stage2::ProcessKogasa(int flame){
		bool rr = true;
		int r = 0;
		if (flame == 1){
			Bosstime--;
		}
		prescene = scene;
		SetDrawArea(20,15,404,465);
		if(scene != 0){			
			switch (scene){
			case 8://中ボス登場
				kogasa.y += kogasa.vecy;
				DrawGraph((int)(kogasa.x - 30), (int)(kogasa.y - 45), kogasadot[kogasa.imgpoji], true);
				break;
			case 9://中ボス戦　通常1
				DrawGraph((int)(kogasa.x - 30), (int)(kogasa.y - 45), kogasadot[kogasa.imgpoji], true);
				timetoflame = (Currenttime % Looptime) * 60 + flame;
				if(timetoflame == 1){
					jikikakudo = (double)(danmaku.Getkakudo_Homing(kogasa.x, kogasa.y, j.x, j.y));
					prejk = jikikakudo;
					dsht = false;
					danmaku.Setdanmaku_Ko((int)(kogasa.x), (int)(kogasa.y), 3, 3, danmaku.dcolor.water, 0, (int)(jikikakudo)-15, (int)(jikikakudo)+15, 6);
					danmaku.Setdanmaku_Wave((int)(kogasa.x), (int)(kogasa.y), 5, 6, danmaku.dcolor.blue, 0, 0, 20);
				}
				if (dsht == false && (flame - 1) % 15 == 0){
					jikikakudo += 22.5;
					danmaku.Setdanmaku_Ko((int)(kogasa.x), (int)(kogasa.y), 3, 3, danmaku.dcolor.water, 0, (int)(jikikakudo) % 360 - 15, (int)(jikikakudo) % 360 + 15, 6);
					if(prejk == jikikakudo - 360){ dsht = true; }
				}
				break;
			case 10://中ボス戦　スペルカード1
				DrawGraph((int)(kogasa.x - 30), (int)(kogasa.y - 45), kogasadot[kogasa.imgpoji], true);
				if (Currenttime < 4){
					//スペルカード宣言
					StartSpellkardEffect( kogasastand[1]);
					kogasa.y += kogasa.vecy;
					appeary += 1;
					if (kogasa.y <= 65){
						kogasa.y = 65;
						kogasa.vecy = 0;
					}

				}
				else{
					kogasa.x += kogasa.vecx;
					double prey = kogasa.y;
					if (kogasa.vecx < 0){
						kogasa.y = danmaku.GetY(kogasa.x, danmaku.ck.daen, 3, 1);
					}
					else{
						kogasa.y = danmaku.GetY(kogasa.x, danmaku.ck.daen, 3, -1);
					}			  //(192,65)
					if (kogasa.y == -9999){
						kogasa.y = prey;
						kogasa.vecx *= -1;
						kogasa.x += kogasa.vecx;
						if (j.y <= kogasa.y + 20){
							danmaku.Setdanmaku_Ko((int)(kogasa.x), 110, 2, 3, danmaku.dcolor.water, 0, 160, 200, 16);
						}
						else{
							danmaku.Setdanmaku_Ko((int)(kogasa.x), 110, 2, 3, danmaku.dcolor.water, 0, 70, 110, 16);
						}
					}
					//弾幕処理
					if (flame < 31){
						if (flame % 4 == 0){
							if (flame % 8 == 0){
								danmaku.Setdanmaku_ChainRendan((int)(kogasa.x), (int)(kogasa.y), 5, danmaku.Getkakudo_Homing(kogasa.x, kogasa.y, j.x, j.y) + 10, 3, danmaku.dcolor.water, 0, 2, 5);
							}
							else{
								danmaku.Setdanmaku_ChainRendan((int)(kogasa.x), (int)(kogasa.y), 5, danmaku.Getkakudo_Homing(kogasa.x, kogasa.y, j.x, j.y) - 10, 3, danmaku.dcolor.water, 0, 2, 5);
							}
						}
					}
					if (flame % 30 == 0){
						danmaku.Setdanmaku_Wave((int)(kogasa.x), (int)(kogasa.y), 3, danmaku.dcolor.blue, 0, 0, danmaku.Getkakudo_Homing(kogasa.x, kogasa.y, j.x, j.y), 6);
					}
					if (kogasa.x > 162 && kogasa.x < 222){
						kakudo = danmaku.Getkakudo_Homing(kogasa.x, kogasa.y, j.x, j.y);
						if (flame % 40 == 0){
							danmaku.Setdanmaku_Wave((int)(kogasa.x), (int)(kogasa.y), 3, 6, danmaku.dcolor.green, 0, kakudo, 30);
							kakudo -= 2;
						}
					}
				}
				if (Currenttime > 3){

					Bosshit = true;
				}
				break;
			case 11://中ボス退散
				DrawGraph((int)(kogasa.x - 30), (int)(kogasa.y - 45), kogasadot[kogasa.imgpoji], true);
				EndSpellkardEffect(200000, SpellBonusScore);
				if (Currenttime > 1){
					kogasa.x += kogasa.vecx;
					kogasa.y += kogasa.vecy;
				}
				break;
			case 15://大ボス戦インターバル
				/*	*/

				switch (Talkcount){
				case 26://26～　は魅魔のみ
					JikiStandPosition = 1;
					BossStandPosition = -1;
					Shadowflg = 1;
					standx = -50;
					standy = 180;
					selif1 = "相も変わらず、有り余る活力が暴走";
					selif2 = "しているね";
					break;
				case 25:
					JikiStandPosition = 1;
					selif1 = "いへんかいけつってこいつらを";
					selif2 = "黙らせればいいのかな？";
					break;
				case 24:
					JikiStandPosition = 2;
					selif1 = "あの二人なら、否定はしないだろうねぇ。";
					selif2 = "";
					break;
				case 23://23から咲夜も追加
					Shadowflg = 0;
					selif1 = "あ、さっきの人。";
					kogasa.x = -92;
					kogasa.y = -92;
					kogasa.vecx = (double)(208 + 92) / 60;
					kogasa.vecy = (double)(100 + 92) / 60;
					kogasa.imgpoji = DotAct.common;
					break;
				case 22:
					if (PlayerData.jikinum == 1){
						BossStandPosition = 1;
						selif1 = "見ない顔ね。あなたも付喪神なの？";
						selif2 = "";
					}
					else{
						Shadowflg = 1;
						JikiStandPosition = 1;
						selif1 = "あの二人の危機意識の低さは";
						selif2 = "知っていても…";
					}
					break;
				case 21:
					if (PlayerData.jikinum == 1){
						JikiStandPosition = 1;
						Shadowflg = 1;
						selif1 = "・・・ちがうよ。";
						selif2 = "";
					}
					else{
						Shadowflg = 1;
						JikiStandPosition = 1;
						selif1 = "流石に、怠慢じゃないかしら？";
						selif2 = "";

					}
					break;
				case 20:
					if (PlayerData.jikinum == 1){
						Shadowflg = 0;
						selif1 = "でもはじめましてでしょ？";
						selif2 = "";
					}
					else{
						Shadowflg = 1;
						JikiStandPosition = 2;
						selif1 = "たとえ私に解決させたところで";
						selif2 = "根本的にはどうにもならない。";
					}
					break;
				case 19:
					if (PlayerData.jikinum == 1){
						Shadowflg = 1;
						selif1 = "あんたこそ誰？";
						selif2 = "";
					}
					else{
						Shadowflg = 1;
						JikiStandPosition = 2;
						selif1 = "所詮はあやかる存在にすぎないわ。";
						selif2 = "";
					}
					break;
				case 18:
					if (PlayerData.jikinum == 1){
						JikiStandPosition = 3;
						Shadowflg = 1;
						selif1 = "付喪神なら相応の寄り代があるもん";
						selif2 = "じゃないか？";
					}
					else{
						Shadowflg = 0;
						JikiStandPosition = 1;
						selif1 = "あやかりと聞いて";
						selif2 = "";
						kogasa.x = -92;
						kogasa.y = -92;
						kogasa.vecx = (208 + 92) / 60;
						kogasa.vecy = (100 + 92) / 60;
						kogasa.imgpoji = DotAct.common;
					}
					break;
				case 17:
					if (PlayerData.jikinum == 1){
						BossStandPosition = 2;
						Shadowflg = 0;
						selif1 = "無くした♪私の商売道具もどっか";
						selif2 = "いちゃったの。";
					}
					else{
						JikiStandPosition = 1;
						BossStandPosition = 1;
						selif1 = "あなたもあの人達に？";
						selif2 = "";
					}
					break;
				case 16:
					if (PlayerData.jikinum == 1){
						BossStandPosition = 1;
						selif1 = "付喪神としてはあいでんてぃてぃに";
						selif2 = "関わることよ。";
					}
					else{
						Shadowflg = 1;
						JikiStandPosition = 1;
						selif1 = "異変解決という名のちゃっかりに、って";
						selif2 = "";
					}
					break;
				case 15:
					if (PlayerData.jikinum == 1){
						JikiStandPosition = 2;
						Shadowflg = 1;
						selif1 = "寄り代のない付喪神・・・";
						selif2 = "私と同じだね。";
					}
					else{
						Shadowflg = 1;
						JikiStandPosition = 1;
						selif1 = "あやかる物もないあんたに言われたく";
						selif2 = "ない。";
					}
					break;
				case 14:
					if (PlayerData.jikinum == 1){
						BossStandPosition = 1;
						Shadowflg = 0;
						selif1 = "え？どういうこと？";
						selif2 = "";
					}
					else{
						Shadowflg = 0;
						JikiStandPosition = 1;
						selif1 = "ふふ、たまには依存から解放されるのも";
						selif2 = "悪くないよ。ところで…";
					}
					break;
				case 13:
					if (PlayerData.jikinum == 1){
						JikiStandPosition = 1;
						Shadowflg = 1;
						selif1 = "精神だけの存在でしかないってこと。";
						selif2 = "";
					}
					else{
						JikiStandPosition = 1;
						selif1 = "あなたでもいいから聞いてくれる？";
						selif2 = "";
					}
					break;
				case 12:
					if (PlayerData.jikinum == 1){
						BossStandPosition = 2;
						Shadowflg = 0;
						selif1 = "やっぱり付喪神じゃないですか～。";
						selif2 = "自我があるっていいでしょう？";
					}
					else{
						Shadowflg = 1;
						JikiStandPosition = 3;
						selif1 = "はい？";
						selif2 = "";
					}
					break;
				case 11:
					if (PlayerData.jikinum == 1){
						JikiStandPosition = 1;
						Shadowflg = 1;
						selif1 = "あー？違う違う、付喪神じゃなくて…";
						selif2 = "";
					}
					else{
						Shadowflg = 0;
						JikiStandPosition = 1;
						selif1 = "最近さ～みんなピリピリし過ぎなのよ";
						selif2 = "ね～、いつにも増して。";
					}
					break;
				case 10:
					if (PlayerData.jikinum == 1){
						Shadowflg = 0;
						BossStandPosition = 1;
						selif1 = "まぁまぁ、でも問題が起こったって私";
						selif2 = "には関係のないことよ。";
					}
					else{
						JikiStandPosition = 1;
						selif1 = "モノをなくしたとか誰かが行方不明とか";
						selif2 = "";

					}
					break;
				case 9:
					if (PlayerData.jikinum == 1){
						BossStandPosition = 1;
						selif1 = "霊夢さんと魔理沙さんに任せれば、";
						selif2 = "どうにかしてくれるわ。";
					}
					else{
						JikiStandPosition = 1;
						selif1 = "ここは幻想郷なのよ？のんびりしてれば";
						selif2 = "いずれどうにでもなるのに。";

					}
					break;
				case 8:
					if (PlayerData.jikinum == 1){
						Shadowflg = 3;
						selif1 = "それがいわゆる”異変解決”って";
						selif2 = "言うのかい？";
					}
					else{
						Shadowflg = 1;
						JikiStandPosition = 2;
						selif1 = "私たちがどうにかしているのよ。";
						selif2 = "";
					}
					break;
				case 7:
					if (PlayerData.jikinum == 1){
						Shadowflg = 0;
						BossStandPosition = 1;
						selif1 = "そう。幻想郷の基礎知識よ。";
						selif2 = "";
					}
					else{
						Shadowflg = 0;
						selif1 = "あの人達なら問題ないでしょ？わざわざ";
						selif2 = "些細な事に顔を出しては異変、異変って。";
					}
					break;
				case 6:
					if (PlayerData.jikinum == 1){
						Shadowflg = 1;
						JikiStandPosition = 2;
						selif1 = "じゃあ私も異変解決をしても";
						selif2 = "いいってことだね。";
					}
					else{
						Shadowflg = 1;
						BossStandPosition = 1;
						selif1 = "…それは平和ボケしているだけ。";
						selif2 = "";

					}
					break;
				case 5:

					if (PlayerData.jikinum == 1){
						Shadowflg = 0;
						BossStandPosition = 1;
						selif1 = "まぁそうだけど？";
						selif2 = "";
					}
					else{
						Shadowflg = 0;
						BossStandPosition = 2;
						selif1 = "そういうことだから、大騒ぎすることも";
						selif2 = "ないの。平常運転ね。";
					}
					break;
				case 4:
					if (PlayerData.jikinum == 1){
						Shadowflg = 1;
						JikiStandPosition = 2;
						selif1 = "私に突っかかってきた以上はそれ";
						selif2 = "なりの覚悟があるんだろうね？";
					}
					else{
						Shadowflg = 1;
						JikiStandPosition = 2;
						selif1 = "空いた口が塞がらないけど敢えて言うわ。";
						selif2 = "";
					}
					break;
				case 3:

					if (PlayerData.jikinum == 1){
						Shadowflg = 0;
						BossStandPosition = 2;
						selif1 = "もっちろん！とびっきりの弾幕で";
						selif2 = "驚かしてあげる。";
					}
					else{
						Shadowflg = 1;
						JikiStandPosition = 5;
						selif1 = "装備・装飾なくて分からず、さらには";
						selif2 = "行方不明者もいる状況のどこが平和?!";
					}
					break;
				case 2:

					if (PlayerData.jikinum == 1){
						Shadowflg = 1;
						JikiStandPosition = 8;
						selif1 = "ならば私の一押しを存分に味わって";
						selif2 = "もらおうか。";
					}
					else{

						Shadowflg = 0;
						BossStandPosition = 1;
						selif1 = "いつも通りよ。こうして今でもあなたを";
						selif2 = "驚かすことが出来るんだから!";
					}
					break;
				case 1:

					if (PlayerData.jikinum == 1){
						Shadowflg = 1;
						JikiStandPosition = 8;
						selif1 = "久しく日の目を見なかった活力を。";
						selif2 = "";
					}
					else{
						Shadowflg = 1;
						JikiStandPosition = 1;
						selif1 = "茄子色の本体がなくとも、";
						selif2 = "事の重大さを分からせてやるわ。";
					}
					break;
				}
				if ((PlayerData.jikinum == 1 && Talkcount < 23) || (PlayerData.jikinum == 3 && Talkcount < 18)){
					if (kogasa.x < 208){
						kogasa.x += kogasa.vecx;
						kogasa.y += kogasa.vecy;
					}
					else{
						kogasa.x = 208;
						kogasa.y = 100;
					}
					DrawGraph((int)(kogasa.x - 30), (int)(kogasa.y - 45), kogasadot[kogasa.imgpoji], true);
				}
				int jikicolor;
				int bossy, jikiy;
				if (PlayerData.jikinum == 1){
					jikicolor = GetColor(255, 200, 255);
					bossy = 225;
					jikiy = 210;
				}
				else{
					jikicolor = GetColor(150, 255, 150);
					bossy = 215;
					jikiy = 207;
				}
				BossTalking(kogasastand[BossStandPosition], GetColor(80, 120, 250), jikicolor, 170, bossy, jikiy, 0);
				break;
			case 16://大ボス戦　通常1
				DrawGraph((int)(kogasa.x - 30), (int)(kogasa.y - 45), kogasadot[kogasa.imgpoji], true);
				if (Currenttime < 1){
				}
				else{
					timetoflame = (Currenttime % Looptime) * 60 + flame;
					switch (timetoflame){
					case 1:
						danmaku.Setdanmaku_Wave((int)(kogasa.x), (int)(kogasa.y), 3, danmaku.dshu.ring, danmaku.dcolor.white, 0, 0, 40);
						break;
					case 31:
						danmaku.Setdanmaku_Wave((int)(kogasa.x), (int)(kogasa.y), 3, danmaku.dshu.ring, danmaku.dcolor.white, 0, 5, 40);
						break;
					case 61:
						danmaku.Setdanmaku_Wave((int)(kogasa.x), (int)(kogasa.y), 3, danmaku.dshu.ring, danmaku.dcolor.white, 0, 10, 40);
						break;
					case 121:
						danmaku.Setdanmaku_ArrowRendan((int)(kogasa.x), (int)(kogasa.y), 0, danmaku.dshu.kome, danmaku.dcolor.green, 0, 21, 16.5, 0.5);
						danmaku.Setdanmaku_ArrowRendan((int)(kogasa.x), (int)(kogasa.y), 180, danmaku.dshu.kome, danmaku.dcolor.green, 0, 21, 16.5, 0.5);
						break;
					case 151:
						danmaku.Setdanmaku_ArrowRendan((int)(kogasa.x), (int)(kogasa.y), 45, danmaku.dshu.kome, danmaku.dcolor.water, 0, 21, 16.5, 0.5);
						danmaku.Setdanmaku_ArrowRendan((int)(kogasa.x), (int)(kogasa.y), 135, danmaku.dshu.kome, danmaku.dcolor.water, 0, 21, 16.5, 0.5);
						break;
					case 181:
						danmaku.Setdanmaku_ArrowRendan((int)(kogasa.x), (int)(kogasa.y), 90, danmaku.dshu.kome, danmaku.dcolor.blue, 0, 21, 16.5, 0.5);
						break;
					}
					if (timetoflame > 210 && timetoflame < 305 && timetoflame % 4 == 3){
						danmaku.Setdanmaku_ChainRendan((int)(kogasa.x), (int)(kogasa.y), 2, ((timetoflame - 207) / 4 - 1) * 8, danmaku.dshu.tubu, danmaku.dcolor.yellow, 0, 1, 1);
					}
					
				}
				break;
			case 17://大ボス戦　スペルカード1枚目
				DrawGraph((int)(kogasa.x - 30), (int)(kogasa.y - 45), kogasadot[kogasa.imgpoji], true);
				if (Currenttime < 2){
					StartSpellkardEffect(kogasastand[1]);
					EndSpellkardEffect(150000, 0);
					appeary += 1;
					if (Currenttime == 0 && flame == 1){
						SetItem(kogasa.x, kogasa.y, flame, 10, 10);
					}
				}
				else{
					if (Currenttime > 6){
						Bosshit = true;
					}

					timetoflame = ((Currenttime - 2) % Looptime) * 60 + flame;
					switch (timetoflame)
					{
					case 1://初期位置(208x,100y)から(358x,145y)へ80Fかけて移動
						kogasa.vecx = (double)(358 - 208) / 80;
						kogasa.vecy = (double)(145 - 100) / 80;
						kogasa.imgpoji = DotAct.right;
						break;
					case 11:
						danmaku.Setdanmaku_Wave((int)(kogasa.x), (int)(kogasa.y), 2.2, danmaku.dshu.kome, danmaku.dcolor.green, 0, danmaku.Getkakudo_Homing(kogasa.x, kogasa.y, j.x, j.y), 30);
						break;
					case 41:
						danmaku.Setdanmaku_Wave((int)(kogasa.x), (int)(kogasa.y), 2.2, danmaku.dshu.kome, danmaku.dcolor.green, 0, danmaku.Getkakudo_Homing(kogasa.x, kogasa.y, j.x, j.y) + 10, 30);
						break;
					case 71:
						danmaku.Setdanmaku_Wave((int)(kogasa.x), (int)(kogasa.y), 2.2, danmaku.dshu.kome, danmaku.dcolor.green, 0, danmaku.Getkakudo_Homing(kogasa.x, kogasa.y, j.x, j.y) + 20, 30);
						break;
					case 81://停止
						kogasa.vecx = 0;
						kogasa.vecy = 0;
						kogasa.imgpoji = DotAct.common;
						break;
					case 121://(358x,145y)から(58x,145y)へ60Fかけて移動
						kogasa.vecx = (double)(58 - 358) / 60;
						kogasa.vecy = 0;
						kogasa.imgpoji = DotAct.left;
						break;
					case 181://停止
						kogasa.vecx = 0;
						kogasa.vecy = 0;
						kogasa.imgpoji = DotAct.common;
						break;
					case 241://(58x,145y)から(208x,190y)へ80Fかけて移動
						danmaku.Setdanmaku_Ko((int)(kogasa.x), (int)(kogasa.y), 2.5, danmaku.dshu.ring, danmaku.dcolor.white, 0, danmaku.Getkakudo_Homing(kogasa.x, kogasa.y, j.x, j.y) - 60, danmaku.Getkakudo_Homing(kogasa.x, kogasa.y, j.x, j.y) + 60, 16);
						danmaku.Setdanmaku_ChainRendan((int)(kogasa.x), (int)(kogasa.y), 5, danmaku.Getkakudo_Homing(kogasa.x, kogasa.y, j.x, j.y) - 20, danmaku.dshu.kome, danmaku.dcolor.blue, 0, 10, 3);
						danmaku.Setdanmaku_ChainRendan((int)(kogasa.x), (int)(kogasa.y), 5, danmaku.Getkakudo_Homing(kogasa.x, kogasa.y, j.x, j.y) + 20, danmaku.dshu.kome, danmaku.dcolor.blue, 0, 10, 3);
						danmaku.Setdanmaku_ArrowRendan((int)(kogasa.x), (int)(kogasa.y), danmaku.Getkakudo_Homing(kogasa.x, kogasa.y, j.x, j.y), danmaku.dshu.kunai, danmaku.dcolor.blue, 0, 10, 2, 0.25);
						kogasa.vecx = (double)(208 - 58) / 80;
						kogasa.vecy = (double)(190 - 145) / 80;
						kogasa.imgpoji = DotAct.right;
						break;
					case 321://(208x,190y)から(358x,190y)へ80Fかけて移動
						danmaku.Setdanmaku_Ko((int)(kogasa.x), (int)(kogasa.y), 2.5, danmaku.dshu.ring, danmaku.dcolor.white, 0, danmaku.Getkakudo_Homing(kogasa.x, kogasa.y, j.x, j.y) - 60, danmaku.Getkakudo_Homing(kogasa.x, kogasa.y, j.x, j.y) + 60, 16);
						danmaku.Setdanmaku_ChainRendan((int)(kogasa.x), (int)(kogasa.y), 5, danmaku.Getkakudo_Homing(kogasa.x, kogasa.y, j.x, j.y) - 20, danmaku.dshu.kome, danmaku.dcolor.water, 0, 10, 3);
						danmaku.Setdanmaku_ChainRendan((int)(kogasa.x), (int)(kogasa.y), 5, danmaku.Getkakudo_Homing(kogasa.x, kogasa.y, j.x, j.y) + 20, danmaku.dshu.kome, danmaku.dcolor.water, 0, 10, 3);
						danmaku.Setdanmaku_ArrowRendan((int)(kogasa.x), (int)(kogasa.y), danmaku.Getkakudo_Homing(kogasa.x, kogasa.y, j.x, j.y), danmaku.dshu.kunai, danmaku.dcolor.water, 0, 10, 2, 0.25);
						kogasa.vecx = (double)(358 - 208) / 80;
						kogasa.vecy = 0;
						break;
					case 401://弾幕発射と同時に停止
						danmaku.Setdanmaku_Ko((int)(kogasa.x), (int)(kogasa.y), 2.5, danmaku.dshu.ring, danmaku.dcolor.white, 0, danmaku.Getkakudo_Homing(kogasa.x, kogasa.y, j.x, j.y) - 60, danmaku.Getkakudo_Homing(kogasa.x, kogasa.y, j.x, j.y) + 60, 16);
						danmaku.Setdanmaku_ChainRendan((int)(kogasa.x), (int)(kogasa.y), 5, danmaku.Getkakudo_Homing(kogasa.x, kogasa.y, j.x, j.y) - 20, danmaku.dshu.kome, danmaku.dcolor.purple, 0, 10, 3);
						danmaku.Setdanmaku_ChainRendan((int)(kogasa.x), (int)(kogasa.y), 5, danmaku.Getkakudo_Homing(kogasa.x, kogasa.y, j.x, j.y) + 20, danmaku.dshu.kome, danmaku.dcolor.purple, 0, 10, 3);
						danmaku.Setdanmaku_ArrowRendan((int)(kogasa.x), (int)(kogasa.y), danmaku.Getkakudo_Homing(kogasa.x, kogasa.y, j.x, j.y), danmaku.dshu.kunai, danmaku.dcolor.purple, 0, 10, 2, 0.25);
						kogasa.vecx = 0;
						kogasa.vecy = 0;
						kogasa.imgpoji = DotAct.common;
						break;
					case 481://(358x,190y)から(58x,100y)へ60Fかけて移動
						kogasa.vecx = (double)(58 - 358) / 60;
						kogasa.vecy = (double)(100 - 190) / 60;
						kogasa.imgpoji = DotAct.left;
						break;
					case 541://(58x,100y)から(208x,100y)へ80Fかけて移動
						kogasa.vecx = (double)(208 - 58) / 80;
						kogasa.vecy = 0;
						kogasa.imgpoji = DotAct.right;
						break;
					case 551:
						danmaku.Setdanmaku_Wave((int)(kogasa.x), (int)(kogasa.y), 2.2, danmaku.dshu.kome, danmaku.dcolor.blue, 0, 0, 30);
						break;
					case 581:
						danmaku.Setdanmaku_Wave((int)(kogasa.x), (int)(kogasa.y), 2.2, danmaku.dshu.kome, danmaku.dcolor.blue, 0, 0, 30);
						break;
					case 611:
						danmaku.Setdanmaku_Wave((int)(kogasa.x), (int)(kogasa.y), 2.2, danmaku.dshu.kome, danmaku.dcolor.blue, 0, 0, 30);
						break;
					case 621://停止
						kogasa.vecx = 0;
						kogasa.vecy = 0;
						kogasa.imgpoji = DotAct.common;
						break;
					}
					if (timetoflame > 126 && timetoflame < 181 && timetoflame % 6 == 1){
						int c;
						switch (timetoflame){//虹色付け
						case 127:
							c = danmaku.dcolor.red;
							break;
						case 133:
							c = danmaku.dcolor.orange;
							break;
						case 139:
							c = danmaku.dcolor.yellow;
							break;
						case 145:
							c = danmaku.dcolor.green;
							break;
						case 151:
							c = danmaku.dcolor.water;
							break;
						case 157:
							c = danmaku.dcolor.blue;
							break;
						case 163:
							c = danmaku.dcolor.purple;
							break;
						case 169:
							c = danmaku.dcolor.pink;
							break;
						case 175:
							c = danmaku.dcolor.white;
							break;
						}
						danmaku.Setdanmaku_ArrowRendan((int)(kogasa.x), (int)(kogasa.y), 90, danmaku.dshu.kome, c, 0, 5, 5, 3);
					}
					if (timetoflame > 486 && timetoflame < 541 && timetoflame % 6 == 1){
						int c;
						switch (timetoflame){//虹色付け
						case 487:
							c = danmaku.dcolor.red;
							break;
						case 493:
							c = danmaku.dcolor.orange;
							break;
						case 499:
							c = danmaku.dcolor.yellow;
							break;
						case 505:
							c = danmaku.dcolor.green;
							break;
						case 511:
							c = danmaku.dcolor.water;
							break;
						case 517:
							c = danmaku.dcolor.blue;
							break;
						case 523:
							c = danmaku.dcolor.purple;
							break;
						case 529:
							c = danmaku.dcolor.pink;
							break;
						case 535:
							c = danmaku.dcolor.white;
							break;
						}
						danmaku.Setdanmaku_ArrowRendan((int)(kogasa.x), (int)(kogasa.y), 90, danmaku.dshu.kome, c, 0, 3, 3, 1.8);
					}
					kogasa.x += kogasa.vecx;
					kogasa.y += kogasa.vecy;
					
				}
				break;
			case 18://大ボス戦　通常2
				DrawGraph((int)(kogasa.x - 30), (int)(kogasa.y - 45), kogasadot[kogasa.imgpoji], true);
				if (Currenttime < 3){
					Bosshit = false;
					EndSpellkardEffect(200000, SpellBonusScore);
					kogasa.x += kogasa.vecx;
					kogasa.y += kogasa.vecy;
					if (kogasa.vecx < 0 && kogasa.x < 58){
						kogasa.x = 58;
					}
					if (kogasa.vecy < 0 && kogasa.y < 100){
						kogasa.y = 100;
					}
				}
				else{
					if (Currenttime == 6){
						Bosshit = true;
					}
					timetoflame = ((Currenttime - 3) % Looptime) * 60 + flame;
					switch (timetoflame)
					{
					case 1:
						kogasa.x = 58;
						kogasa.y = 100;
						kogasa.vecx = (double)(358 - 58) / 120;
						kogasa.imgpoji = DotAct.right;
						break;
					case 31:
						danmaku.Setdanmaku_Ko((int)(kogasa.x), (int)(kogasa.y), 2.5, danmaku.dshu.ring, danmaku.dcolor.water, 0, 30, 150, 16);
						danmaku.Setdanmaku_ArrowRendan((int)(kogasa.x), (int)(kogasa.y), 90, danmaku.dshu.kunai, danmaku.dcolor.green, 0, 10, 2, 0.25);
						break;
					case 61:
						danmaku.Setdanmaku_Ko((int)(kogasa.x), (int)(kogasa.y), 2.5, danmaku.dshu.ring, danmaku.dcolor.water, 0, 30, 150, 16);
						danmaku.Setdanmaku_ArrowRendan((int)(kogasa.x), (int)(kogasa.y), 90, danmaku.dshu.kunai, danmaku.dcolor.green, 0, 10, 2, 0.25);
						break;
					case 91:
						danmaku.Setdanmaku_Ko((int)(kogasa.x), (int)(kogasa.y), 2.5, danmaku.dshu.ring, danmaku.dcolor.water, 0, 30, 150, 16);
						danmaku.Setdanmaku_ArrowRendan((int)(kogasa.x), (int)(kogasa.y), 90, danmaku.dshu.kunai, danmaku.dcolor.green, 0, 10, 2, 0.25);
						break;
					case 121:
						kogasa.vecx = 0;
						kogasa.imgpoji = DotAct.common;
						break;
					case 181:
						kogasa.vecy = (double)(160 - 100) / 50;
						kogasa.vecx = 0;
						kogasa.imgpoji = DotAct.right;
						break;
					case 221:
						kogasa.vecx = (double)(108 - 308) / 100;
						kogasa.vecy = 0;
						kogasa.imgpoji = DotAct.left;
						break;
					case 341:
						kogasa.vecy = (double)(100 - 160) / 50;
						kogasa.vecx = 0;						
						break;
					case 381:
						kogasa.vecx = 0;
						kogasa.y = 100;
						kogasa.imgpoji = DotAct.common;
						break;
					}
					if (timetoflame > 180 && timetoflame < 381){
						if (kogasa.vecx == 0){
							kogasa.y += kogasa.vecy;
							int fugou = -1;
							if (kogasa.x > 208){
								fugou = 1;
							}
							kogasa.x = danmaku.GetX(kogasa.y, danmaku.ck.daen, 3, fugou);

						}
						else{
							kogasa.x += kogasa.vecx;
							kogasa.y = danmaku.GetY(kogasa.x, danmaku.ck.daen, 3, 1);
						}
						if ((timetoflame - 181) % 25 == 0){
							danmaku.Setdanmaku_Wave((int)(kogasa.x), (int)(kogasa.y), 2.2, danmaku.dshu.ring, danmaku.dcolor.blue, 0, danmaku.Getkakudo_Homing(kogasa.x, kogasa.y, j.x, j.y) + 10, 10);
						}
					}
					else{
						kogasa.x += kogasa.vecx;
					}
				}
				break;
			case 19://大ボス戦　スペルカード2枚目
				DrawGraph((int)(kogasa.x - 30), (int)(kogasa.y - 45), kogasadot[kogasa.imgpoji], true);
				if (Currenttime < 4){
					//スペルカード宣言
					StartSpellkardEffect(kogasastand[1]);
					EndSpellkardEffect(150000, 0);
					appeary += 1;
					kogasa.x += kogasa.vecx;
					kogasa.y += kogasa.vecy;
					if (kogasa.vecx > 0) {
						kogasa.imgpoji = DotAct.right;
					}
					else {
						kogasa.imgpoji = DotAct.left;
					}
					if ((kogasa.vecx < 0 && kogasa.x < 208) || (kogasa.vecx > 0 && kogasa.x > 208)){
						kogasa.x = 208;
						kogasa.vecx = 0;
						kogasa.imgpoji = DotAct.common;
					}
					if ((kogasa.vecy < 0 && kogasa.y < 100) || (kogasa.vecy > 0 && kogasa.y >  100)){
						kogasa.y = 100;
						kogasa.vecy = 0;
						kogasa.imgpoji = DotAct.common;
					}

				}
				else{
					if (Currenttime > 6){
						Bosshit = true;
					}

					timetoflame = ((Currenttime - 3) % Looptime) * 60 + flame;
					switch (timetoflame){
					case 2:
						kogasa.imgpoji = DotAct.act1;
						danmaku.Setdanmaku_ChainRendan((int)(j.x), 15, 1.8, 90, danmaku.dshu.kome, danmaku.dcolor.water, 0, 1, 0);
					case 241:
						danmaku.Setdanmaku_Wave((int)(kogasa.x), (int)(kogasa.y), 2.2, danmaku.dshu.large, danmaku.dcolor.water, 0, 0, 40);
						break;
					}
					if (timetoflame % 4 == 0){
						double speed = 1;
						if (timetoflame % 7 == 0){
							speed = 2;
						}
						else{
							if (timetoflame % 5 == 0){
								speed = 1.5;
							}
						}
						danmaku.Setdanmaku_ChainRendan(GetRand(381) + 21, 15, speed, 90, danmaku.dshu.hahen, danmaku.dcolor.water, 0, 1, 0);
					}
					
				}
				break;
			case 20://大ボス戦　スペルカード3枚目
				DrawGraph((int)(kogasa.x - 30), (int)(kogasa.y - 45), kogasadot[kogasa.imgpoji], true);
				int px, py;
				if (Currenttime < 4){
					//スペルカード宣言
					kogasa.imgpoji = DotAct.common;
					StartSpellkardEffect(kogasastand[1]);
					EndSpellkardEffect(200000, PreBonusScore);
					appeary += 1;
				}
				else{
					if (Currenttime > 6){
						Bosshit = true;
					}
					timetoflame = ((Currenttime - 3) % Looptime) * 60 + flame;
					switch (timetoflame){
					case 1:
						kogasa.imgpoji = DotAct.act1;
						px = 404;
						py = 243;
						break;
					case 61:
						px = 404;
						py = 15;
						break;
					case 121:
						px = 208;
						py = 15;
						break;
					case 181:
						px = 20;
						py = 15;
						break;
					case 241:
						px = 20;
						py = 243;
						break;
					case 301:
						danmaku.Setdanmaku_Ko((int)(kogasa.x), (int)(kogasa.y), 2.5, danmaku.dshu.mayu, danmaku.dcolor.white, 0, 0, 180, 31);
						break;
					case 361:
						for (int p = danmaku.tail - 1; p > danmaku.tail - 32; p--){
							danmaku.dan[p].vecx = 5 * cos(danmaku.Getkakudo_Homing(danmaku.dan[p].x, danmaku.dan[p].y, j.x, j.y) * PI / 180);
							danmaku.dan[p].vecy = -5 * sin(danmaku.Getkakudo_Homing(danmaku.dan[p].x, danmaku.dan[p].y, j.x, j.y) * PI / 180);
							danmaku.dan[p].imgangle = danmaku.Getkakudo_Homing(danmaku.dan[p].x, danmaku.dan[p].y, j.x, j.y) * PI / 180;
							danmaku.dan[p].color = danmaku.dcolor.blue;
						}
						px = 20;
						py = 243;
						break;
					case 421:
						px = 30;
						py = 15;
						break;
					case 481:
						px = 208;
						py = 15;
						break;
					case 541:
						px = 404;
						py = 15;
						break;
					case 601:
						px = 404;
						py = 243;
						break;
					case 602:
						danmaku.Setdanmaku_Ko((int)(kogasa.x), (int)(kogasa.y), 2.5, danmaku.dshu.mayu, danmaku.dcolor.white, 0, 0, 180, 31);
						break;
					case 662:
						for (int p = danmaku.tail - 1; p > danmaku.tail - 32; p--){
							danmaku.dan[p].vecx = 5 * cos(danmaku.Getkakudo_Homing(danmaku.dan[p].x, danmaku.dan[p].y, j.x, j.y) * PI / 180);
							danmaku.dan[p].vecy = -5 * sin(danmaku.Getkakudo_Homing(danmaku.dan[p].x, danmaku.dan[p].y, j.x, j.y) * PI / 180);
							danmaku.dan[p].imgangle = danmaku.Getkakudo_Homing(danmaku.dan[p].x, danmaku.dan[p].y, j.x, j.y) * PI / 180;
							danmaku.dan[p].color = danmaku.dcolor.blue;
						}
						break;
					}
				}
				if (timetoflame != 301 && timetoflame % 60 == 1 && timetoflame < 602){
					//発射位置から目標地点（自機位置）までの距離とラジアン角度を計算し、それをベクトル成分化して引数に渡す。
					int kakudo = danmaku.Getkakudo_Homing(px, py, j.x, j.y);
					danmaku.Setdanmaku_Pointwave(px, py, 150, danmaku.dshu.middle, danmaku.dcolor.purple, 0, kakudo, (int)(j.x), (int)(j.y), 60, 18);
				}
				break;
			case 21://大ボス戦終了
				/*
				 
				*/
				switch (Talkcount){
				case 11:
					JikiStandPosition = 1;
					BossStandPosition = 10;
					selif1 = "さあ寄り代のない付喪神のようなもの";
					selif2 = "は帰った帰った。";
					break;
				case 10:
					Shadowflg = 0;
					selif1 = "ひえ～お助けー！";
					selif2 = "";
					break;
				case 9:
					Shadowflg = 1;
					selif1 = "そしてその間に存在意義をなくして";
					selif2 = "消滅するのも時間の問題ね。";
					break;
				case 8:
					if (PlayerData.jikinum == 1){
						selif1 = "あー！強すぎるわ。新入りの付喪神";
						selif2 = "じゃなかったの？";
						Shadowflg = 0;
						BossStandPosition = 10;
					}
					else{
						Shadowflg = 0;
						selif1 = "もっと勘弁です。それに";
						selif2 = "";
					}
					break;
				case 7:
					if (PlayerData.jikinum == 1){
						Shadowflg = 1;
						JikiStandPosition = 1;
						selif1 = "誰が新入りだといった。それに…";
						selif2 = "";
					}
					else{
						selif1 = "存在意義なくしたら私どころじゃ";
						selif2 = "済まないと思うなぁ。";
					}
					break;
				case 6:
					if (PlayerData.jikinum == 1){
						JikiStandPosition = 2;
						selif1 = "私は端からここにいるよ。";
						selif2 = "あんたの方が新入りだ。";
					}
					else{
						Shadowflg = 1;
						selif1 = "む、それはそうね。服装や装飾が";
						selif2 = "ないだけでも、って";
					}
					break;
				case 5:
					if (PlayerData.jikinum == 1){
						Shadowflg = 0;
						selif1 = "おぉ広い広い幻想郷、あなたのような";
						selif2 = "隠れた先駆者でもなんでもござれ。";
					}
					else{
						selif1 = "今はゆっくりしてられないわ。急ぎながら";
						selif2 = "考えましょう。";
					}
					break;
				case 4:
					if (PlayerData.jikinum == 1){
						selif1 = "でも異変解決をするのなら大歓迎ね。";
						selif2 = "私からもお願いするわ。";
					}
					else{
						Shadowflg = 0;
						selif1 = "おはしも言ってられない緊急事態なのね。";
						selif2 = "";
					}
					break;
				case 3:
					if (PlayerData.jikinum == 1){
						Shadowflg = 1;
						JikiStandPosition = 3;
						BossStandPosition = -1;
						selif1 = "古参にボコボコにされたってのに";
						selif2 = "なんで依頼してくるんだろうね。";
					}
					else{
						Shadowflg = 1;
						selif1 = "う～ん、なんとなくだけど…";
						selif2 = "";
					}
					break;
				case 2:
					if (PlayerData.jikinum == 1){
						JikiStandPosition = 1;
						selif1 = "まるで待ち焦がれていたかのようだ。";
						selif2 = "";
					}
					else{
						selif1 = "この異変、あの二人に任せること自体が";
						selif2 = "間違ってる気がしてきた。";
					}
					break;
				case 1://ステージリザルト
					if (j.slow > 0){
						TalkSkipCancel = true;
					}
					else{
						TalkSkipCancel = false;
					}
					break;
				}
				if (PlayerData.jikinum == 1){
					jikicolor = GetColor(255, 200, 255);
					bossy = 225;
					jikiy = 210;
				}
				else{
					jikicolor = GetColor(150, 255, 150);
					bossy = 215;
					jikiy = 207;
				}
				if (Talkcount > 1){
					BossTalking(kogasastand[BossStandPosition], GetColor(150, 150, 200), jikicolor, 170, bossy, jikiy, 0);
				}
				if (Currenttime < 4){
					EndSpellkardEffect(300000, SpellBonusScore);
				}
				break;
			}
		}
		danmaku.ProcessBossDanmaku(flame + Currenttime * 60, scene, PlayerData.jikinum, (int)(kogasa.x), (int)(kogasa.y));
		if (BossTalk == false){ r = DisplayBossStates(kogasa.hitpoint, kogasa.phasecount); }
		if (Spell){ DisplaySpellStates(); }
		if((scene == 12 && prescene == 11)/*||(scene == 22 && prescene == 21)*/){
			rr = false;//フェーズの進行度に応じてボス戦が終了する。
		}
		if(r != 0){
			r = -1;
		}
		return rr;
	}
	int Stage2::ProcessTukaima(int flame){
		//使い魔の動きを処理します。
		int r = 0;
		double angle = 0;
		int p = tukaima[0].np;
		while (p != ttail && tekicount != 0){
			if (tukaima[p].ready == 0){
				switch (scene){ 
				case 9://ミスティア　中ボス　通常1
					tukaima[p].y += tukaima[p].vecy;
					
					if (tukaima[p].x < 212){
						tukaima[p].x = danmaku.GetX(tukaima[p].y, 2, 3, 1);
						if (tukaima[p].y > 262){
							
							if (tukaima[p].y > 312){
								angle = 90;
							}
							else{
								angle = 45;
							}
						}
						else{
							angle = 0;
						}
					}
					else
					{
						tukaima[p].x = danmaku.GetX(tukaima[p].y, 3, 3, -1);
						if (tukaima[p].y > 262){
							
							if (tukaima[p].y > 312){
								angle = 90;
							}
							else{
								angle = 135;
							}
						}
						else{
							angle = 180;
						}
					}
					//弾幕処理
					if (flame % 60 == 0){
						int kakudo;
						if (tukaima[p].x < 212){
							kakudo = danmaku.Getkakudo_Homing(tukaima[p].x, tukaima[p].y, 20, 465);
						}
						else{
							kakudo = danmaku.Getkakudo_Homing(tukaima[p].x, tukaima[p].y, 404, 465);
						}
						danmaku.Setdanmaku_ArrowRendan((int)(tukaima[p].x), (int)(tukaima[p].y), kakudo, 4, danmaku.dcolor.purple, 0, 4, 2, 4);
						danmaku.Setdanmaku_ArrowRendan((int)(tukaima[p].x), (int)(tukaima[p].y), kakudo + 180, 4, danmaku.dcolor.purple, 0, 4, 2, 4);
					}
					break;
				case 16://大ボスミスティア戦　通常1
					tukaima[p].x += tukaima[p].vecx;
					if ((flame - tukaima[p].start) % 90 == 0){
						danmaku.Setdanmaku_ChainRendan((int)(tukaima[p].x), (int)(tukaima[p].y), 2, danmaku.Getkakudo_Homing(tukaima[p].x, tukaima[p].y, j.x, j.y), danmaku.dshu.uroko, danmaku.dcolor.purple, 0, 1, 0);
					}
					if (tukaima[p].vecx > 0){
						angle = 0;
					}
					else{
						angle = 180;
					}
					break;
				case 19:
					tukaima[p].x += tukaima[p].vecx;
					tukaima[p].y += tukaima[p].vecy;
					if (tukaima[p].vecx == 0){
						if (tukaima[p].vecy > 0){
							if ((flame - tukaima[p].start) % 90 == 0){
								danmaku.Setdanmaku_ArrowRendan((int)(tukaima[p].x), (int)(tukaima[p].y), 30, danmaku.dshu.uroko, danmaku.dcolor.yellow,0,5,4,1);
								danmaku.Setdanmaku_ArrowRendan((int)(tukaima[p].x), (int)(tukaima[p].y), 150, danmaku.dshu.uroko, danmaku.dcolor.yellow, 0, 5, 4, 1);
							}
							angle = 90;
						}
						else{
							if ((flame - tukaima[p].start) % 90 == 0){
								danmaku.Setdanmaku_ArrowRendan((int)(tukaima[p].x), (int)(tukaima[p].y), 210, danmaku.dshu.uroko, danmaku.dcolor.yellow, 0, 5, 4, 1);
								danmaku.Setdanmaku_ArrowRendan((int)(tukaima[p].x), (int)(tukaima[p].y), 330, danmaku.dshu.uroko, danmaku.dcolor.yellow, 0, 5, 4, 1);
							}
							angle = 270;
						}
					}
					else{
						if (tukaima[p].vecx > 0){
							if ((flame - tukaima[p].start) % 50 == 0){
								danmaku.Setdanmaku_ChainRendan((int)(tukaima[p].x), (int)(tukaima[p].y), 2.5, 90, danmaku.dshu.uroko, danmaku.dcolor.red, 0, 11, 1);
								danmaku.Setdanmaku_ChainRendan((int)(tukaima[p].x), (int)(tukaima[p].y), 2.5, 270, danmaku.dshu.uroko, danmaku.dcolor.red, 0, 11, 1);
							}
							angle = 0;
						}
						else{
							if ((flame - tukaima[p].start) % 50 == 0){
								danmaku.Setdanmaku_Wave((int)(tukaima[p].x), (int)(tukaima[p].y), 2.5, danmaku.dshu.uroko, danmaku.dcolor.purple, 0, danmaku.Getkakudo_Homing(tukaima[p].x, tukaima[p].y, j.x, j.y), 18);
							}
							angle = 180;
						}
					}
					break;
				}
				
				if ((int)(tukaima[p].x) > 425 || (int)(tukaima[p].x) < -3 || (int)(tukaima[p].y) > 486 || (int)(tukaima[p].y) < -8){
					//範囲外に出たら消滅
					DeleteTukaima(p);
				}
				DrawRotaGraph((int)(tukaima[p].x), (int)(tukaima[p].y), 1.0, angle * PI / 180, mystiatukaima, true);
			}
			else{
				tukaima[p].ready--;
				if (tukaima[p].ready == 0){ tukaima[p].start = flame; }
			}
			
			p = tukaima[p].np;
		}
		
		return r;
	};
	BOSU mystia;
	BOSU kogasa;

private:
	static int mystiadot[2];//0.common ,1.act1,2.act2,3.left ,4.right
	static int kogasadot[5];//0.common ,1.act1,2.act2,3.left ,4.right
	//common,left,right,act1,act2
	static int kogasastand[11];//1.common,2.fine,3.cry
	static int mystiastand[11];//1.common,2.fine
	static int mystiatukaima;
	bool danshot[11];
	bool dsht;
	int kakudo;
	double mkakudo;
	double jikikakudo,prejk;//小傘中ボス戦において最初に発射される扇状10way±45度のhahen弾で使われる自機方向を保持する変数です。
	int d;

};
int Stage2::kogasastand[11] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
int Stage2::mystiastand[11] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
int Stage2::kogasadot[5] = { 0, 0, 0, 0, 0 };
int Stage2::mystiadot[2] = { 0, 0 };
int Stage2::mystiatukaima = 0;
class S1D:public Danmaku{
public:
	void S1D::CreateDanmakuGraph(){
		int f;
		int dimg[DANMAKUCOUNT][4];//1.イメージハンドル 2.Width 3.Height
		int dgraph[DANMAKUCOUNT][11];
		struct palette{
			int r;
			int g;
			int b;
		};
		palette first, second, arpha, firstcolor, secondcolor;
		struct Arpha {
			int r;
			int g;
			int b;
			int a;
		};
		Arpha choose;
		char dir[_MAX_PATH];


		f = GetCurrentDirectory(255, dir);
		char ddir[_MAX_PATH];
		LPTSTR  ldir = NULL;
		GetModuleFileNameA(NULL, ddir, sizeof ddir);
		
		
		int b = SetCurrentDirectory(ddir);
		f = GetCurrentDirectory(255, dir);
		f = _chdir("data");
		f = _chdir("img");
		f = _chdir("Game");
		f = _chdir("danmaku");
		dimg[dshu.tubu][1] = LoadSoftImage("tubu.bmp");
		f = GetSoftImageSize(dimg[dshu.tubu][1], &dimg[dshu.tubu][2], &dimg[dshu.tubu][3]);
		dimg[dshu.kome][1] = LoadSoftImage("kome.bmp");
		f = GetSoftImageSize(dimg[dshu.kome][1], &dimg[dshu.kome][2], &dimg[dshu.kome][3]);
		dimg[dshu.hoshi][1] = LoadSoftImage("hoshi.bmp");
		f = GetSoftImageSize(dimg[dshu.hoshi][1], &dimg[dshu.hoshi][2], &dimg[dshu.hoshi][3]);
		dimg[dshu.hahen][1] = LoadSoftImage("hahen.bmp");
		f = GetSoftImageSize(dimg[dshu.hahen][1], &dimg[dshu.hahen][2], &dimg[dshu.hahen][3]);
		dimg[dshu.uroko][1] = LoadSoftImage("uroko.png");
		f = GetSoftImageSize(dimg[dshu.uroko][1], &dimg[dshu.uroko][2], &dimg[dshu.uroko][3]);
		dimg[dshu.kunai][1] = LoadSoftImage("kunai.bmp");
		f = GetSoftImageSize(dimg[dshu.kunai][1], &dimg[dshu.kunai][2], &dimg[dshu.kunai][3]);

		dimg[dshu.ring][1] = LoadSoftImage("ring.bmp");
		f = GetSoftImageSize(dimg[dshu.ring][1], &dimg[dshu.ring][2], &dimg[dshu.ring][3]);
		dimg[dshu.middle][1] = LoadSoftImage("middle.bmp");
		f = GetSoftImageSize(dimg[dshu.middle][1], &dimg[dshu.middle][2], &dimg[dshu.middle][3]);
		dimg[dshu.twin][1] = LoadSoftImage("twin.bmp");
		f = GetSoftImageSize(dimg[dshu.twin][1], &dimg[dshu.twin][2], &dimg[dshu.twin][3]);
		dimg[dshu.onpu][1] = LoadSoftImage("onpu.bmp");
		f = GetSoftImageSize(dimg[dshu.onpu][1], &dimg[dshu.onpu][2], &dimg[dshu.onpu][3]);
		dimg[dshu.key][1] = LoadSoftImage("key.bmp");
		f = GetSoftImageSize(dimg[dshu.key][1], &dimg[dshu.key][2], &dimg[dshu.key][3]);
		dimg[dshu.knife][1] = LoadSoftImage("knife.bmp");
		f = GetSoftImageSize(dimg[dshu.knife][1], &dimg[dshu.knife][2], &dimg[dshu.knife][3]);

		dimg[dshu.mayu][1] = LoadSoftImage("mayu.bmp");
		f = GetSoftImageSize(dimg[dshu.mayu][1], &dimg[dshu.mayu][2], &dimg[dshu.mayu][3]);
		dimg[dshu.large][1] = LoadSoftImage("large.bmp");
		f = GetSoftImageSize(dimg[dshu.large][1], &dimg[dshu.large][2], &dimg[dshu.large][3]);
		dimg[dshu.big][1] = LoadSoftImage("big.bmp");
		f = GetSoftImageSize(dimg[dshu.big][1], &dimg[dshu.big][2], &dimg[dshu.big][3]);
		dimg[dshu.lazer][1] = LoadSoftImage("lazer.bmp");
		f = GetSoftImageSize(dimg[dshu.lazer][1], &dimg[dshu.lazer][2], &dimg[dshu.lazer][3]);
		dimg[dshu.biglazer][1] = LoadSoftImage("biglazer.bmp");
		f = GetSoftImageSize(dimg[dshu.biglazer][1], &dimg[dshu.biglazer][2], &dimg[dshu.biglazer][3]);
		dimg[dshu.heart][1] = LoadSoftImage("heart.bmp");
		f = GetSoftImageSize(dimg[dshu.heart][1], &dimg[dshu.heart][2], &dimg[dshu.heart][3]);
		dimg[dshu.plate][1] = LoadSoftImage("plate.bmp");
		f = GetSoftImageSize(dimg[dshu.plate][1], &dimg[dshu.plate][2], &dimg[dshu.plate][3]);
		dimg[dshu.bigplate][1] = LoadSoftImage("largeplate.bmp");
		f = GetSoftImageSize(dimg[dshu.bigplate][1], &dimg[dshu.bigplate][2], &dimg[dshu.bigplate][3]);
		f = _chdir("..");
		f = _chdir("..");
		f = _chdir("..");
		f = _chdir("..");
		f = GetPixelSoftImage(dimg[dshu.heart][1], 2, 2, &first.r, &first.g, &first.b, 0);
		f = GetPixelSoftImage(dimg[dshu.heart][1], 7, 7, &second.r, &second.g, &second.b, 0);
		f = GetPixelSoftImage(dimg[dshu.heart][1], 13, 13, &arpha.r, &arpha.g, &arpha.b, 0);
		for (int d = 0; d < DANMAKUCOUNT; d++){
			for (int color = 0; color < 10; color++){
				dgraph[d][color] = MakeARGB8ColorSoftImage(dimg[d][2], dimg[d][3]);
			}
		}
		for (int d = 0; d < DANMAKUCOUNT; d++){
			for (int color = 0; color < 10; color++){
				switch (color){
				case 0://白
					firstcolor.r = 255;
					firstcolor.g = 255;
					firstcolor.b = 255;
					secondcolor.r = 200;
					secondcolor.g = 200;
					secondcolor.b = 200;
					break;
				case 1://赤
					firstcolor.r = 237;
					firstcolor.g = 28;
					firstcolor.b = 36;
					secondcolor.r = 255;
					secondcolor.g = 174;
					secondcolor.b = 201;
					break;
				case 2://橙
					firstcolor.r = 255;
					firstcolor.g = 127;
					firstcolor.b = 39;
					secondcolor.r = 255;
					secondcolor.g = 201;
					secondcolor.b = 14;
					break;
				case 3://黄
					firstcolor.r = 249;
					firstcolor.g = 230;
					firstcolor.b = 0;
					secondcolor.r = 239;
					secondcolor.g = 228;
					secondcolor.b = 176;
					break;
				case 4://緑
					firstcolor.r = 34;
					firstcolor.g = 177;
					firstcolor.b = 76;
					secondcolor.r = 181;
					secondcolor.g = 230;
					secondcolor.b = 29;
					break;
				case 5://水
					firstcolor.r = 0;
					firstcolor.g = 162;
					firstcolor.b = 232;
					secondcolor.r = 153;
					secondcolor.g = 217;
					secondcolor.b = 234;
					break;
				case 6://青
					firstcolor.r = 63;
					firstcolor.g = 72;
					firstcolor.b = 204;
					secondcolor.r = 122;
					secondcolor.g = 146;
					secondcolor.b = 190;
					break;
				case 7://紫
					firstcolor.r = 120;
					firstcolor.g = 54;
					firstcolor.b = 120;
					secondcolor.r = 200;
					secondcolor.g = 191;
					secondcolor.b = 231;
					break;
				case 8://桃
					firstcolor.r = 255;
					firstcolor.g = 128;
					firstcolor.b = 192;
					secondcolor.r = 255;
					secondcolor.g = 204;
					secondcolor.b = 230;
					break;
				case 9://灰
					firstcolor.r = 127;
					firstcolor.g = 127;
					firstcolor.b = 127;
					secondcolor.r = 192;
					secondcolor.g = 192;
					secondcolor.b = 192;
					break;
				case 10://黒
					firstcolor.r = 20;
					firstcolor.g = 20;
					firstcolor.b = 20;
					secondcolor.r = 80;
					secondcolor.g = 80;
					secondcolor.b = 80;
					break;
				}
				for (int x = 0; x < dimg[d][2]; x++){
					for (int y = 0; y < dimg[d][3]; y++){
						GetPixelSoftImage(dimg[d][1], x, y, &choose.r, &choose.g, &choose.b, &choose.a);
						if ((choose.r == first.r && choose.g == first.g && choose.b == first.b) || choose.r == first.r + 1 && choose.g == first.g + 1 && choose.b == first.b + 1){
							//最も濃い色部分
							DrawPixelSoftImage(dgraph[d][color], x, y, firstcolor.r, firstcolor.g, firstcolor.b, 255);
						}
						else{
							if (choose.r == second.r && choose.g == second.g && choose.b == second.b){
								//薄い色部分
								DrawPixelSoftImage(dgraph[d][color], x, y, secondcolor.r, secondcolor.g, secondcolor.b, 255);
							}
							else{
								if (choose.r == arpha.r && choose.g == arpha.g && choose.b == arpha.b){
									//透明色部分
									DrawPixelSoftImage(dgraph[d][color], x, y, firstcolor.r, firstcolor.g, firstcolor.b, 0);
								}
								else{
									//その他の白黒部分
									DrawPixelSoftImage(dgraph[d][color], x, y, choose.r, choose.g, choose.b, 255);
									if (choose.r == 0 && choose.g == 0 && choose.b == 0){
										DrawPixelSoftImage(dgraph[d][color], x, y, choose.r, choose.g, choose.b, 0);
									}
								}
							}
						}
					}
				}
			}
		}
		for (int d = 0; d < DANMAKUCOUNT; d++){
			for (int color = 0; color < 10; color++){
				danimg[d][color] = CreateGraphFromSoftImage(dgraph[d][color]);
			}
		}
		InitSoftImage();
		/*
		int x = 1;
		int y = 1;
		for (int d = 0; d < DANMAKUCOUNT; d++) {
			x = 1;
			for (int color = 0; color < 10; color++) {
				DrawGraph(x, y, danimg[d][color], true);
				x += dimg[d][2];
			}
			y += 20;
		}
		WaitKey();
		*/
	}
	int ProcessDanmaku(int flame,int scene){
		int r = 0;
		int p = dan[0].np;
		while(p != tail && dancount != 0){
			if(ddan[p].ready == 0){
				dan[p].x += dan[p].vecx;
				dan[p].y -= dan[p].vecy;
			}else{
				ddan[p].ready--;
			}
			p = dan[p].np;
		}
		if(PasteDanmaku() != 0){r = -1;}
		if(r == -1){
			r = -1;
		}
		return r;
	};
	int ProcessBossDanmaku(int flame, int scene,int jikinum ,int x,int y){
		int r = 0;
		if (flame % 30 == 0){ DanmakuRefresh(); }
		int p = dan[0].np;
		while (p != tail && dancount != 0){
			if (ddan[p].ready == 0){
				switch (scene){
				case 8:
					dan[p].x += dan[p].vecx;
					dan[p].y -= dan[p].vecy;
					break;
				case 15:
					dan[p].x += dan[p].vecx;
					dan[p].y -= dan[p].vecy;
					if (dan[p].danshu == 1){
						if (dan[p].x + dan[p].vecx <= 20){
							if (refrect[0] == -1){
								refrect[0] = Getkakudo_Homing(dan[p].x, dan[p].y, x, y);
							}
							dan[p].vecx = dan[p].vecx / cos(135 * PI / 180) * cos(refrect[0] * PI / 180) * 0.5;
							dan[p].vecy = dan[p].vecy / sin(135 * PI / 180) * sin(refrect[0] * PI / 180) * 0.5;
						}
						else{
							if (dan[p].x + dan[p].vecx >= 404){
								if (refrect[1] == -1){
									refrect[1] = Getkakudo_Homing(dan[p].x, dan[p].y, x, y);
								}
								dan[p].vecx = dan[p].vecx / cos(45 * PI / 180) * cos(refrect[1] * PI / 180) * 0.5;
								dan[p].vecy = dan[p].vecy / sin(45 * PI / 180) * sin(refrect[1] * PI / 180) * 0.5;
							}
						}
					}
					break;
				case 16:
					if (dan[p].danshu == 12){//ここからアリス弾幕
						if (ddan[p].usef == 0){
							switch ((int)(dan[p].vecx)){
							case -6://usef = ck.daen
								if (dan[p].x + dan[p].vecx <= 16){
									dan[p].x = 16;
									dan[p].vecy = dan[p].vecx;
									dan[p].vecx = 0;
									ddan[p].usef = ck.daen;
									ddan[p].kanshu = 3;
									ddan[p].fugou = -1;
								}
								break;
							case -4://usef = ck.daen - 1
								if (dan[p].x + dan[p].vecx <= 76){
									dan[p].x = 76;
									dan[p].vecy = dan[p].vecx;
									dan[p].vecx = 0;
									ddan[p].usef = ck.daen - 1;
									ddan[p].kanshu = 3;
									ddan[p].fugou = -1;
								}
								break;
							case -2://usef = ck.daen - 2
								if (dan[p].x + dan[p].vecx <= 136){
									dan[p].x = 136;
									dan[p].vecy = dan[p].vecx;
									dan[p].vecx = 0;
									ddan[p].usef = ck.daen - 2;
									ddan[p].kanshu = 3;
									ddan[p].fugou = -1;
								}
								break;

							case 2://usef = ck.daen - 5
								if (dan[p].x + dan[p].vecx >= 260){
									dan[p].x = 268;
									dan[p].vecy = dan[p].vecx * -1;
									dan[p].vecx = 0;
									ddan[p].usef = ck.daen - 5;
									ddan[p].kanshu = 3;
									ddan[p].fugou = 1;
								}
								break;
							case 4://usef = ck.daen - 4
								if (dan[p].x + dan[p].vecx >= 328){
									dan[p].x = 328;
									dan[p].vecy = dan[p].vecx * -1;
									dan[p].vecx = 0;
									ddan[p].usef = ck.daen - 4;
									ddan[p].kanshu = 3;
									ddan[p].fugou = 1;
								}
								break;
							case 6://usef = ck.daen - 3
								if (dan[p].x + dan[p].vecx >= 388){
									dan[p].x = 388;
									dan[p].vecy = dan[p].vecx * -1;
									dan[p].vecx = 0;
									ddan[p].usef = ck.daen - 3;
									ddan[p].kanshu = 3;
									ddan[p].fugou = 1;
								}
								break;
							}
							dan[p].x += dan[p].vecx;
						}
						else{
							if (dan[p].vecx == 0){
								double prex = dan[p].x;
								dan[p].y -= dan[p].vecy;
								dan[p].x = GetX(dan[p].y, ddan[p].usef, ddan[p].kanshu, ddan[p].fugou);
								dan[p].imgangle = Getkakudo_Homing(prex, dan[p].y, dan[p].x, dan[p].y - dan[p].vecy) * PI / 180;
								if (ddan[p].usef < ck.daen - 2){
									if (dan[p].y > GetY(20, ddan[p].usef, ddan[p].kanshu, 1) * 0.7){
										dan[p].vecx = dan[p].vecy;
										dan[p].vecy = 0;
									}
								}
								else{
									if (dan[p].y > GetY(404, ddan[p].usef, ddan[p].kanshu, 1) * 0.7){
										dan[p].vecx = dan[p].vecy * -1;
										dan[p].vecy = 0;
										ddan[p].fugou = 1;
									}
								}
								
							}
							else{
								double prey = dan[p].y;
								dan[p].x += dan[p].vecx;
								dan[p].y = GetY(dan[p].x, ddan[p].usef, ddan[p].kanshu, ddan[p].fugou);
								dan[p].imgangle = Getkakudo_Homing(dan[p].x, prey, dan[p].x - dan[p].vecx, dan[p].y) * PI / 180;
							}
							if (dan[p].x == -9999 || dan[p].y == -9999){
								r = r;
							}
						}
					}//ここまでアリス弾幕
					else{
						if (dan[p].danshu == dshu.uroko){//ここから文弾幕
							ddan[p].crossr += dan[p].vecx;//波状円の半径を増加
							ddan[p].crosskakudo += dan[p].vecy;//円周上の回転位置を増分
							dan[p].x = (int)(ddan[p].crossr  * cos(ddan[p].crosskakudo * PI / 180)) + x;
							dan[p].y = (int)(ddan[p].crossr  * sin(ddan[p].crosskakudo * PI / 180)) + y;
							if (dan[p].vecy > 0){
								dan[p].imgangle = ((int)(ddan[p].crosskakudo) % 360) * PI / 180 + 90;
							}
							else{
								dan[p].imgangle = ((int)(ddan[p].crosskakudo) % 360) * PI / 180 - 90;
							}
						}//ここまで文弾幕
						else{
							dan[p].x += dan[p].vecx;
							dan[p].y -= dan[p].vecy;
						}
					}
					break;
				case 17:
					dan[p].x += dan[p].vecx;
					dan[p].y -= dan[p].vecy;
					break;
				case 18:
					dan[p].x += dan[p].vecx;
					dan[p].y -= dan[p].vecy;
					break;

				}
			}
			else{
				ddan[p].ready--;
			}
			p = dan[p].np;
		}
		if (PasteDanmaku() != 0){ r = -1; }
		if (r == -1){
			r = -1;
		}
		return r;
	};
	int refrect[3];//画面両端で反射する弾幕の角度を保持する変数です。最初の弾幕が反射するときに設定され、以降の弾幕はその角度に準じます。
};
class Stage1:public Stage{
	
public:
	S1D danmaku;
	Stage1::Stage1(){
		int r;
		char dir[_MAX_PATH];
		GetCurrentDirectory(_MAX_PATH, dir);
		r = _chdir("data");
		r = _chdir("img");
		r = _chdir("Game");
		r = _chdir("Enemy");
		r = _chdir("Boss");
		ayadot[DotAct.common] = LoadGraph("Aya.dot.common.png");
		ayadot[DotAct.left] = LoadGraph("Aya.dot.left.png");
		ayadot[DotAct.right] = LoadGraph("Aya.dot.right.png");
		ayastand[1] = LoadGraph("Aya.common.png");
		ayastand[2] = LoadGraph("Aya.fine.png");
		ayastand[StandAct.amazed] = LoadGraph("Aya.amazed.png");
		ayastand[StandAct.doubt] = LoadGraph("Aya.doubt.png");
		alicedot[DotAct.common] = LoadGraph("Alice.dot.common.png");
		alicedot[DotAct.act1] = LoadGraph("Alice.dot.act1.png");
		alicedot[DotAct.left] = LoadGraph("Alice.dot.left.png");
		alicedot[DotAct.right] = LoadGraph("Alice.dot.right.png");
		alicestand[1] = LoadGraph("Alice.common.png");		
		alicestand[2] = LoadGraph("Alice.fine.png");
		alicestand[StandAct.surprised] = LoadGraph("Alice.surprised.png");
		r = _chdir("..");
		r = _chdir("..");
		r = _chdir("..");
		r = _chdir("..");
		r = _chdir("..");
		targetkakudo = 0;
		for(int w = 0;w < 17;w++){
			wait[w] = 0;
		}
		d = 0;
	};
	void Stage1::Init(){
		int r = 0;
		r = _chdir("data");
		r = _chdir("img");
		r = _chdir("Game");
		r = _chdir("Enemy");
		r = _chdir("Zako");
		Enemy[1][0] = LoadGraph("redfairy_common.bmp");
		Enemy[1][1] = LoadGraph("redfairy_comleft.bmp");
		Enemy[1][2] = LoadGraph("redfairy_comright.bmp");
		Enemy[1][3] = LoadGraph("redfairy_left.bmp");
		Enemy[1][4] = LoadGraph("redfairy_right.bmp");
		Enemy[1][5] = LoadGraph("redfairy_upleft.bmp");
		Enemy[1][6] = LoadGraph("redfairy_upright.bmp");
		Enemy[2][0] = LoadGraph("bluefairy_common.bmp");
		Enemy[2][1] = LoadGraph("bluefairy_comleft.bmp");
		Enemy[2][2] = LoadGraph("bluefairy_comright.bmp");
		Enemy[2][3] = LoadGraph("bluefairy_left.bmp");
		Enemy[2][4] = LoadGraph("bluefairy_right.bmp");
		Enemy[2][5] = LoadGraph("bluefairy_upleft.bmp");
		Enemy[2][6] = LoadGraph("bluefairy_upright.bmp");
		Enemy[3][0] = LoadGraph("yellowfairy_common.bmp");
		Enemy[3][1] = LoadGraph("yellowfairy_comleft.bmp");
		Enemy[3][2] = LoadGraph("yellowfairy_comright.bmp");
		Enemy[3][3] = LoadGraph("yellowfairy_left.bmp");
		Enemy[3][4] = LoadGraph("yellowfairy_right.bmp");
		Enemy[3][5] = LoadGraph("yellowfairy_upleft.bmp");
		Enemy[3][6] = LoadGraph("yellowfairy_upright.bmp");
		Enemy[4][0] = LoadGraph("greenfairy_common.bmp");
		Enemy[4][1] = LoadGraph("greenfairy_comleft.bmp");
		Enemy[4][2] = LoadGraph("greenfairy_comright.bmp");
		Enemy[4][3] = LoadGraph("greenfairy_left.bmp");
		Enemy[4][4] = LoadGraph("greenfairy_right.bmp");
		Enemy[4][5] = LoadGraph("greenfairy_upleft.bmp");
		Enemy[4][6] = LoadGraph("greenfairy_upright.bmp");
		Enemy[5][0] = LoadGraph("himawarifairy.common.bmp");
		Enemy[6][0] = LoadGraph("cotton.bmp");
		r = _chdir("..");
		r = _chdir("..");
		r = _chdir("States");
		rest = LoadGraph("restphase.bmp");
		r = _chdir("..");
		r = _chdir("..");
		r = _chdir("..");
		r = _chdir("..");
		Input_Item();
		color.white = GetColor(254, 254, 254);
		color.black = GetColor(0, 0, 0);
		color.red = GetColor(250, 10, 10);
		color.green = GetColor(10, 250, 10);
		color.blue = GetColor(10, 10, 250);
		color.glay = GetColor(100, 100, 100);
		ClearBonusfont = CreateFontToHandle("ＭＳ Ｐゴシック", 20, 0, DX_FONTTYPE_ANTIALIASING);
		SpellBonusfont = CreateFontToHandle("ＭＳ Ｐゴシック", 35, 5, DX_FONTTYPE_ANTIALIASING);
		Stagefont = CreateFontToHandle("HGP行書体", 20, 3, DX_FONTTYPE_ANTIALIASING);
		Bossnamefont = CreateFontToHandle("HGP行書体", 20, 6, DX_FONTTYPE_ANTIALIASING);
		Talkfont = CreateFontToHandle("HGP教科書体", 22, 5, DX_FONTTYPE_ANTIALIASING);
		Smallfont = CreateFontToHandle("MS Pゴシック", 12, DX_FONTTYPE_ANTIALIASING);
		Namefont = CreateFontToHandle("MS ゴシック", 13, DX_FONTTYPE_ANTIALIASING);
	}

	int Stage1::Nextscene(int newscene,int powercount){//ステージの次のシーンへ進めます。引数newsceneは次のシーンを表します。
		int r = 0;
		Begintime += Currenttime;
		Currenttime = 0;
		s = 0;
		if(newscene == 10){
			if(Begintime > 106){
				newscene++;
				scene++;
				Begintime = 107;
				Bossbuttle = false;//ボス戦をfalseに
			}
		}
		if (Bossbuttle){
			danmaku.ClearDanmaku();
		}
		switch(newscene){
		case 0://最初に1秒間のラグを空ける。
			r = _chdir("data");
			r = _chdir("Stage");
			r = _chdir("Stage1");
			holizon.back = LoadGraph("back.bmp");
			r = _chdir("..");
			r = _chdir("..");
			r = _chdir("..");
			holizon.by = 1770;
			s = -1;
			int dsc;
			missflame = 300;
			for(dsc = 1;dsc < 100;dsc++){
				danshotcount[dsc] = 0;
			}
			lastscene = 19;
			BossTalk = false;
			danmaku.ClearDanmaku();
			danmaku.Clearkansu();
			danmaku.Inputkansu("Stage1");
			Begintime = 0;
			Endtime = 1;
			Bossbuttle = false;
			break;
		case 1://0:00～0:12　シーン1
			tekicount = 9;
			Begintime = 0;
			teki[0].np = 1;
			tail = 10;
			Endtime = 12; 
			break;
		case 2://0:13～0:17 シーン2
			Endtime = 17;
			danshotcount[1] = 1;
			break;
		case 3://0:18～0:34 シーン3
			Endtime = 34;
			if(tekicount == 0){
				teki[0].np = 10;
			}
			for(dsc = 2;dsc < 14;dsc++){
				danshotcount[dsc] = 1;
			}
			tekicount += 12;
			tail = 22;
			break;
		case 4://00:35～00:51 シーン4
			Endtime = 51;
			if(tekicount == 0){
				teki[0].np = 22;
			}
			for(dsc = 22;dsc < 25;dsc++){
				danshotcount[dsc] = 1;
				danshotcount[dsc + 6] = 1;
			}
			tekicount += 12;
			tail = 34;
			break;
		case 5://0:52～1:08　シーン5 道中デフォルト
			Endtime = 68;//終了時間の設定
			if(tekicount == 0){//敵が画面にいなければ新たにrootを設定
				teki[0].np = 34;
			}
			tail = 58;//tailを設定
			tekicount += 24;//敵数を加算
			break;
		case 6://1:09～1:18 シーン6
			Endtime = 78;
			if(tekicount == 0){
				teki[0].np = 58;
			}
			tail = 78;
			tekicount += 20;
			break;
		case 7://中ボス登場　ボスデフォルト
			Bossbuttle= true;//ボス戦を有効に
			if (PlayerData.jikinum < 2){//自機により異なる場合は分割する
				BossName = "Alice Margatroid";//ボス名を設定
				alice.imgpoji = DotAct.common;//ドット絵を設定(デフォルトで1)
				alice.hitr = 25;//ボスの当たり判定を設定
				alice.x = 10;//出現位置を設定
				alice.y = 100;
				if(powercount > 2){//自機の状況により難易度別に分ける
					alice.hitpoint = 3000;//体力を設定
				}else{
					alice.hitpoint = 1000;
				}
				alice.vecx = (208 - 10) / 60;//登場から停止までのベクトルを設定
			}else{
				BossName = "Aya Shameimaru";
				aya.imgpoji = DotAct.common;
				aya.x = 400;
				aya.y = 100;
				aya.hitr = 25;
				if ((powercount > 1 && PlayerData.jikinum == 3) || (powercount > 2 && PlayerData.jikinum == 2)){
					aya.hitpoint = 3000;
				}else{
					aya.hitpoint = 1000;
				}
				aya.vecx = (double)(208 - 400) / 60;
			}
			Endtime = Begintime + 1;
			Bosshit = false;
			Bosstime = 1;
			break;
		case 8://中ボス戦　デフォルト
			Bosshit = true;//ボスの当たり判定を有効化
			Bosstime = 23;//ボスフェーズ(通常)時間を設定
			Endtime = 104;//ボスフェーズ終了時間を設定
			hitpointdisp = 0;//体力表示のフラグを設定(この場合0は全て白表示)
			if (PlayerData.jikinum < 2){
				Looptime = 4;//ループ間隔を設定
				Maxhitpoint = alice.hitpoint;//最大HPをコピー
				alice.phasecount = 0;
				danmaku.Setdanmaku_Wave((int)(alice.x), (int)(alice.y), 4, 6, danmaku.dcolor.yellow, 0, 10, 20);//開始と同時に弾幕を発射する場合はこのタイミングで発動
			}else{
				Looptime = 6;
				Maxhitpoint = aya.hitpoint;
				aya.phasecount = 0;
				danmaku.Setdanmaku_Wave((int)(aya.x), (int)(aya.y), 2, 6, danmaku.dcolor.orange, 0, 0, 15);
			}
			break;
		case 9://中ボス戦終了＆退散
			Maxhitpoint = 0;//最大HPを初期化
			Endtime = 106;//退散時の時間を設定
			if (PlayerData.jikinum < 2){
				alice.vecx = (15 - alice.x) / 60;//撃破から退散までのベクトルを設定
				alice.vecy = (50 - alice.y) / 60;
				if (powercount < 4){
					SetItem((int)(alice.x), (int)(alice.y), 1, 25, 10);
				}
				else{
					SetItem((int)(alice.x), (int)(alice.y), 1, 10, 25);
				}
			}else{
				aya.vecx = (15 - aya.x) / 60;
				aya.vecy = (50 - aya.y) / 60;
				if (powercount < 4){
					SetItem((int)(aya.x), (int)(aya.y), 1, 25, 10);
				}
				else{
					SetItem((int)(aya.x), (int)(aya.y), 1, 10, 25);
				}
			}
			Bosstime = 2;//退散に掛かる時間を設定
			r = _chdir("data");
			r = _chdir("Stage");
			r = _chdir("Stage1");
			if (PlayerData.jikinum == 0 || PlayerData.jikinum == 1){
				holizon.back = LoadGraph("Aback.bmp");
			}
			else{
				holizon.back = LoadGraph("Bback.bmp");
			}
			holizon.by = 770;
			r = _chdir("..");
			r = _chdir("..");
			r = _chdir("..");
			break;
		case 10://1:25～1:46 シーン7　中ボス戦後デフォルト
			Bossbuttle = false;//ボス戦をfalseに
			Endtime = 106;
			teki[0].np = 78;
			scenetime = (Endtime - Begintime);//中ボス撃破時間からシーン終了時間までの時間を算出
			d = scenetime % 7 + 1;//シーン時間を元にどの場面から始まるかを計算
			for(int ready = 0;ready < 7;ready++){
				teki[78 + (d % 7)].ready = ready * 120;
				d++;
			}
			tekicount = 7;
			tail = 85;
			break;
		case 11://1:47 ～ 2:05 シーン8 0:18
			teki[0].np = 85;
			Endtime = 125;
			tekicount = 8;
			tail = 93;
			for (int d = teki[0].np; d != tail; d++){
				danshotcount[d - 84] = 1;
			}
			break;
		case 12://2:06 ～ 2:25 シーン9
			if(tekicount == 0){
				teki[0].np = 93;
			}
			tail = 99;
			Endtime = 145;
			tekicount += 6;
			for(int v = 1;v < 6;v++){
				vectorchange[v] = 0;
			}
			break;
		case 13://2:26 ～ 2:34
			if(tekicount == 0){
				teki[0].np = 99;
			}
			tail = 101;
			Endtime = 154;
			tekicount += 2;
			break;
		case 14://トーク
			Bossbuttle = true;
			Endtime = 1000;
			Bosstime = 1000;
			ChangeBGMNumber = 2;
			BossTalk = true;
			switch (PlayerData.jikinum){
				case 0:
					JikiStandPosition = 1;
					Talkcount = 12;
					ChangeBGMtalkcount = 3;
					break;
				case 1:
					JikiStandPosition = 1;
					Talkcount =  9;
					ChangeBGMtalkcount = 2;
					break;
				case 2:
					JikiStandPosition = 1;
					Talkcount = 14;
					ChangeBGMtalkcount = 3;
					break;
				case 3:
					JikiStandPosition = 1;
					Talkcount = 12;
					ChangeBGMtalkcount = 3;
					break;
			}
			
			break;
		case 15://大ボス戦　通常1
			BossTalk = false;
			Bosshit = true;//ボスの当たり判定を有効化
			Bosstime = 40;//ボスフェーズ(通常)時間を設定
			Endtime = 104;//ボスフェーズ終了時間を設定
			hitpointdisp = 1;//体力表示のフラグを設定(この場合1は一部赤表示で残りが白表示)
			if (PlayerData.jikinum < 2){
				BossName = "Alice Margatroid";//ボス名を設定
				alice.imgpoji = DotAct.common;//ドット絵を設定(デフォルトで1)
				alice.phasecount = 1;
				alice.hitr = 25;//ボスの当たり判定を設定
				alice.hitpoint = 2500 + powercount * 500;
				Looptime = 6;//ループ間隔を設定
				Maxhitpoint = alice.hitpoint;//最大HPをコピー
				//開始と同時に弾幕を発射する場合はこのタイミングで発動
			}
			else{
				BossName = "Aya Shameimaru";
				aya.imgpoji = DotAct.common;
				aya.phasecount = 1;
				aya.hitr = 25;	
				aya.x = 208;
				aya.y = 80;
				Looptime = 4;
				aya.hitpoint = 2500 + powercount * 500;
				Maxhitpoint = aya.hitpoint;
			}
			break;
		case 16://大ボス戦　スペルカード1
			Spell = true;
			Bosshit = false;
			hitpointdisp = 2;
			danmaku.ClearDanmaku();
			appearx = 150;
			appeary = 40;
			eff.RequestSE(eff.se.spell);
			if (PlayerData.jikinum < 2){
				SpellKardName = "光符「フォトンドール」";
				Looptime = 4;
				alice.hitpoint = 3000 + powercount * 400;
				danmaku.DirectInputkansu_daen(20, 100, 268, 177);//getX(dan[p].y,danmaku.keisan.ck.daen - 5,3,1)
				danmaku.DirectInputkansu_daen(20, 100, 328, 254);//getX(dan[p].y,danmaku.keisan.ck.daen - 4,3,1)
				danmaku.DirectInputkansu_daen(20, 100, 388, 331);//getX(dan[p].y,danmaku.keisan.ck.daen - 3,3,1)
				danmaku.DirectInputkansu_daen(404, 100, 268, 177);//getX(dan[p].y,danmaku.keisan.ck.daen - 2,3,-1)
				danmaku.DirectInputkansu_daen(404, 100, 328, 254);//getX(dan[p].y,danmaku.keisan.ck.daen - 1,3,-1)
				danmaku.DirectInputkansu_daen(404, 100, 388, 331);//getX(dan[p].y,danmaku.keisan.ck.daen ,3,-1)
				Maxhitpoint = alice.hitpoint;
				SpellBonusScore = 500000;
				decreasebonusperflame = SpellBonusScore / (Bosstime * 60);
				Bosstime = 80;
				Endtime = Begintime + 80;
			}
			else{
				SpellKardName = "風符「ルマーオブウィンド」";
				Looptime = 5;
				if (PlayerData.jikinum == 2){
					if (powercount < 5){
						aya.hitpoint = 4000;
					}
					else{
						aya.hitpoint = 3500;
					}
				}
				else
				{
					aya.hitpoint = 5000;
				}

				Maxhitpoint = aya.hitpoint;
				SpellBonusScore = 500000;
				decreasebonusperflame = SpellBonusScore / (Bosstime * 60);
				Bosstime = 80;
				Endtime = Begintime + 80;
			}
			
			break;
		case 17://大ボス戦　通常2
			totalscore += (SpellBonusScore);
			eff.RequestSE(eff.se.spellend);
			totalscore += (100000);
			Spell = false;
			Bosshit = false;//ボスの当たり判定を有効化
			Bosstime = 40;//ボスフェーズ(通常)時間を設定
			Endtime = Begintime + 40;//ボスフェーズ終了時間を設定
			hitpointdisp = 1;
			if (PlayerData.jikinum < 2){
				alice.hitpoint = 2000 + powercount * 720;
				alice.vecx = 0;
				Looptime = 6;//ループ間隔を設定
				alice.phasecount--;
				Maxhitpoint = alice.hitpoint;//最大HPをコピー
				//開始と同時に弾幕を発射する場合はこのタイミングで発動
				if (powercount < 4){
					SetItem((int)(alice.x), (int)(alice.y), 1, 20, 5);
				}
				else{
					SetItem((int)(alice.x), (int)(alice.y), 1, 1, 20);
				}
			}
			else{
				BossName = "Aya Shameimaru";
				aya.hitr = 25;
				aya.vecx = 0;
				Looptime = 6;
				aya.phasecount--;
				aya.hitpoint = 2000 + powercount * 720;
				Maxhitpoint = aya.hitpoint;
				if (powercount < 4){
					SetItem((int)(aya.x), (int)(aya.y), 1, 20, 5);
				}
				else{
					SetItem((int)(aya.x), (int)(aya.y), 1, 1, 20);
				}
			}
			break;
		case 18://大ボス戦　スペルカード2
			Spell = true;
			Bosshit = false;
			Bosstime = 80;
			danmaku.ClearDanmaku();
			eff.RequestSE(eff.se.spell);
			appearx = 150;
			appeary = 40;
			hitpointdisp = 2;
			if (PlayerData.jikinum < 2){
				SpellKardName = "七彩「レインボーウェーブ」";
				Looptime = 4;
				alice.hitpoint = 5000 + powercount * 300;
				if (alice.x != 208){
					alice.vecx = (double)(208 - alice.x) / 80;
					if (aya.vecx > 0) {
					    alice.imgpoji = DotAct.right;
					}
					else {
						alice.imgpoji = DotAct.left;
					}
				}
				Maxhitpoint = alice.hitpoint;
				SpellBonusScore = 500000;
				decreasebonusperflame = SpellBonusScore / (Bosstime * 60);
			}
			else{
				SpellKardName = "伝符「メディアストリーム」";
				Looptime = 1;
				if (aya.x != 212){
					aya.vecx = (212 - aya.x) / 40;
					if (aya.vecx > 0) {
						aya.imgpoji = DotAct.right;
					}
					else {
						aya.imgpoji = DotAct.left;
					}
				}
				targetkakudo = 270;
				aya.hitpoint = 5000 + powercount * 300;
				Maxhitpoint = aya.hitpoint;
				SpellBonusScore = 500000;
				decreasebonusperflame = SpellBonusScore / (Bosstime * 60);
			}
			Endtime = Begintime + 80;
			break;
		case 19://ボスクリア　勝利後トーク
			totalscore += (SpellBonusScore);
			eff.RequestSE(eff.se.bossend);
			totalscore += (150000);
			Maxhitpoint = 0;
			Spell = false;
			Bosshit = false;
			Endtime = 1000;
			Bosstime = 1000;
			BossTalk = true;
			result = false;
			if (PlayerData.jikinum > 1){
				SetItem((int)(aya.x), (int)(aya.y), 0,0, 20);
			}
			else{
				SetItem((int)(alice.x), (int)(alice.y), 0, 0, 20);
			}
			switch (PlayerData.jikinum){
			case 0:
				Talkcount = 4;
				Shadowflg = 1;
				BossStandPosition = -1;
				JikiStandPosition = 1;
				break;
			case 1:
				Talkcount = 4;
				Shadowflg = 1;
				BossStandPosition = -1;
				JikiStandPosition = 1;
				break;
			case 2:
				Talkcount = 4;
				Shadowflg = 1;
				BossStandPosition = -1;
				JikiStandPosition = 1;
				break;
			case 3:
				Talkcount = 4;
				Shadowflg = 1;
				BossStandPosition = -1;
				JikiStandPosition = 1;
				break;
			}
			StageClearscore = 1000000;
			if (j.slow > 0){
				TalkSkipCancel = true;
			}
			else{
				TalkSkipCancel = false;
			}
			break;
		case 20:
			DeleteFontToHandle(SpellBonusfont);
			DeleteFontToHandle(ClearBonusfont);
			BossTalk = false;
			break;
		default:
			return -1;
			break;
		}
		teki[teki[0].np].pp = 0;
		return r;
	}
	int Stage1::PasteHolizon(int flame){//フレーム更新ごとにステージ及び枠外の背景を描写します。この後にPD,PSが入ります。
    //384 × 450
		if (DrawBox(19, 14, 405, 466, color.white, FALSE) != 0){
			return -1;
		}
		if (Spell){
			int cl;
			if (PlayerData.jikinum < 2){
				cl = GetColor(75, 20, 75);
			}
			else{
				cl = GetColor(20, 100, 20);
			}
			DrawBox(20, 15, 404, 465, cl, TRUE);
		}
		else{
			SetDrawBright(128, 128, 128);
			DrawExtendGraph(20, 15, 404, 465, DerivationGraph(100, holizon.by, 200, 225, holizon.back), false);
			SetDrawBright(255,255,255);
			if (scene > 8 ){
				if (holizon.by < 1){
					holizon.by = 0;
				}
				else{
					if (flame % 3 == 0){
						holizon.by -= 1;
					}
				}
			}else{
				holizon.by -= 1;
			}
			if (scene < 8 && holizon.by == 0){
				holizon.by = 1770;
			}
		}
	   //DrawFormatString(500,390,GetColor(255,255,255),"シーン%d,%d秒経過",scene,Currenttime);
	   /*スコア・残機・ボム数・グレーズ・パワー段階などを描写*/
	   return 0;
	}
	int Stage1::ProcessStage(int flame, int powercount){
		int r = 1;//返り値を示す変数です。基本は1(Game Mode)か11(Practice Mode)ですが何らかのエラーが発生すれば-1になります。
		if(flame == 1){
			Currenttime++;
			s++;
			if (missnothit > 0){
				missnothit--;
			}
		}//一秒経過ごとに加算。
		prescene = scene;
		totalscore = 0;
		if(scene == 20){//シーン19が終了したらStage1はクリア//シーンごとに成功したら終了。
			if (PlayerData.choicestage == 0){
				r = 2;
			}
			else{
				r = 9;
			}
		}
		if (r == -1){
			r = -1;
		}
		return r;
	};
	int Stage1::ProcessEnemy(int flame){
		int p,r;
		r = 0;
		if(tekicount > 0){
			p = teki[0].np;
		}else{
			p = tail;
		}
		if(scene == 2){
			if (PlayerData.jikinum < 2){
				DrawStringToHandle(50,150,"Stage1A 魔女と三人目の少女",GetColor(255,255,255),Stagefont);
				DrawStringToHandle(120,165,"～ Madness incident",GetColor(255,255,255),Stagefont);
			}else{
				DrawStringToHandle(50,150,"Stage1B 妖怪と三人目の少女",GetColor(255,255,255),Stagefont);
				DrawStringToHandle(120,165,"～ Mysterius incident",GetColor(255,255,255),Stagefont);
			}
		}
		while(p != tail){
			if(teki[p].ready == 0){
			    switch(scene){
			    case 1://0:00～0:12
					teki[p].x += teki[p].vecx;
					teki[p].y += teki[p].vecy;
					if(teki[p].start == -1){teki[p].start = flame;}
					// 弾幕処理
					if(flame - teki[p].start == 120 && p != 9){
						danmaku.Setdanmaku_ChainRendan((int)(teki[p].x), (int)(teki[p].y), 2, danmaku.Getkakudo_Homing(teki[p].x, teki[p].y, j.x, j.y), 0, 0, 0, 1, 0);
					}
					break;
				case 2://0:13～0:17
					teki[p].x += teki[p].vecx;
					teki[p].y += teki[p].vecy;
					if(teki[p].start == -1){teki[p].start = flame;}
					// 弾幕処理
					if(p == 9){
						if(teki[p].y > 157 && danshotcount[1] != 0){
							danmaku.Setdanmaku_Wave((int)(teki[p].x), (int)(teki[p].y), 3, 7, danmaku.dcolor.red, 1, 0, 30);
							teki[p].vecy = 0;
							danshotcount[1] -= 1;
						}
					}
					break;
				case 3://00:18～00:34
					teki[p].x += teki[p].vecx;
					if(p > 9){
						teki[p].y = danmaku.GetY((int)(teki[p].x), tteki[p].usef, tteki[p].kanshu);
					}else{
						teki[p].y += teki[p].vecy;
					}
					if(teki[p].vecx > 0){
						if(teki[p].x > 122 && teki[p].x < 123){
							teki[p].vecx /= 2;
						}
					}else{
						if(teki[p].x < 302 && teki[p].x > 301){
							teki[p].vecx /= 2;
						}
					}
					if(teki[p].start == -1){teki[p].start = flame;}
					// 弾幕処理
					if(danshotcount[p - 8] > 0){
						if(teki[p].vecx < 0){
							if(teki[p].x < 122){
								danshotcount[p - 8] -= 1;
								danmaku.Setdanmaku_Ko((int)(teki[p].x), (int)(teki[p].y), 3, 7, danmaku.dcolor.green, 0, danmaku.Getkakudo_Homing(teki[p].x, teki[p].y, j.x, j.y) + 20, danmaku.Getkakudo_Homing(teki[p].x, teki[p].y, j.x, j.y) - 20, 3);
							}
						}else{
							if(teki[p].x > 302){
								danshotcount[p - 8] -= 1;
								danmaku.Setdanmaku_Ko((int)(teki[p].x), (int)(teki[p].y), 3, 7, danmaku.dcolor.green, 0, danmaku.Getkakudo_Homing(teki[p].x, teki[p].y, j.x, j.y) + 20, danmaku.Getkakudo_Homing(teki[p].x, teki[p].y, j.x, j.y) - 20, 3);
							}
						}
					}
					break;
				case 4://00:35～00:48
					if(tteki[p].usef == 0){
						teki[p].x += teki[p].vecx;
						teki[p].y += teki[p].vecy;
					}else{
						if(teki[p].vecx == 0){
							teki[p].y += teki[p].vecy;
							//imgposiをYの範囲に応じて変更 commleft upleft common
							if(teki[p].y > 363){
								teki[p].imgposi = 3;
							}else{
								teki[p].vecy = -1;
								if(teki[p].y > 243){
									teki[p].imgposi = 5;
								}else{
									teki[p].vecy = -0.5;
									teki[p].imgposi = 0;
								}
							}
							teki[p].x = danmaku.GetX((int)(teki[p].y), tteki[p].usef, tteki[p].kanshu, tteki[p].fugou);
						}else{
							teki[p].x += teki[p].vecx;
							//imgposiをXの範囲に応じて変更 common comleft left upleft
							if(teki[p].x > 362){
								teki[p].imgposi = 0;
							}else{
								teki[p].vecx = -1.06667;
								if(teki[p].x > 272){
									teki[p].imgposi = 1;
								}else{
									if(teki[p].x > 92){
										teki[p].imgposi = 3;
									}else{
										teki[p].vecx = -0.53333;
										teki[p].imgposi = 5;
									}
								}
							}
							teki[p].y = danmaku.GetY((int)(teki[p].x), tteki[p].usef, tteki[p].kanshu, tteki[p].fugou);
						}
					}
					if(teki[p].start == -1){teki[p].start = flame;}
					//弾幕処理
					if ((p > 21 && p < 25) || (p > 27 && p < 31)){
						//22～24,28～30の敵は3匹のうち一匹でも60F以上持ちこたえたら波状弾幕を発射する。
						if (flame - teki[p].start == 60 && danshotcount[p] > 0){
							danmaku.Setdanmaku_Wave((int)(teki[p].x), (int)(teki[p].y), 3, 4, danmaku.dcolor.yellow, 0, 0, 10);
							danshotcount[p] = 0;
							int neib1 = 1;
							int neib2 = 2;
							if (p % 3 == 1){
								neib2 = -1;
							}
							else{
								if (p % 3 == 2){
									neib1 *= -1;
									neib2 *= -1;
								}
							}
							if (danshotcount[p + neib1] == 1 && teki[p + neib1].hitpoint != -1){
								danshotcount[p + neib1] = 0;
							}
							if (danshotcount[p + neib2] == 1 && teki[p + neib2].hitpoint != -1){
								danshotcount[p + neib2] = 0;
							}
						}
					}
					if (tteki[p].usef != 0){
						if ((flame - teki[p].start) % 80 == 0){
							danmaku.Setdanmaku_ChainRendan((int)(teki[p].x), (int)(teki[p].y), 2, danmaku.Getkakudo_Homing(teki[p].x, teki[p].y, j.x, j.y), 1, danmaku.dcolor.green, 0, 1, 0);
						}
					}
					if(tekicount == 0){scene++;}
					break;
				case 5://00:52～1:08
					if (teki[p].vecx == 0 && teki[p].vecy == 0){
						//登場と同時に移動方向を自機位置に設定。一次関数を登録とともに180Fで画面反対端へ移動
						if (teki[p].start == -1){ teki[p].start = flame; }
						double dx, dy, a, x, y;
						dx = j.x - teki[p].x;
						dy = j.y - teki[p].y;
						a = dy / dx;
						tteki[p].usef = danmaku.DirectInputkansu_ichiji(a, (int)(teki[p].y - a * teki[p].x));
						if (teki[p].y == 15){
							x = danmaku.GetX(465, tteki[p].usef);
							if (x < 20){
								teki[p].vecx = (20 - teki[p].x) / 180;
							}
							else{
								if (x > 404){
									teki[p].vecx = (404 - teki[p].x) / 180;
								}
								else{
									teki[p].vecy = (465 - teki[p].y) / 180;
								}
							}
						}
						else{
							if (teki[p].x == 404){
								y = danmaku.GetY(20, tteki[p].usef, 0);
								if (y < 15){
									teki[p].vecy = (15 - teki[p].y) / 180;
								}
								else{
									if (y > 465){
										teki[p].vecy = (465 - teki[p].y) / 180;
									}
									else{
										teki[p].vecx = (20 - teki[p].x) / 180;
									}
								}
							}
							else{
								y = danmaku.GetY(404, tteki[p].usef, 0);
								if (y < 15){
									teki[p].vecy = (15 - teki[p].y) / 180;
								}
								else{
									if (y > 465){
										teki[p].vecy = (465 - teki[p].y) / 180;
									}
									else{
										teki[p].vecx = (404 - teki[p].x) / 180;
									}
								}
							}
						}
					}
					if(teki[p].vecy == 0){
						teki[p].x += teki[p].vecx;
						teki[p].y = danmaku.GetY(teki[p].x, tteki[p].usef, 0);
					}else{
						teki[p].y += teki[p].vecy;
						teki[p].x = danmaku.GetX(teki[p].y, tteki[p].usef);
					}
					break;
				case 6://1:09～1:20
					if(teki[p].start == -1){teki[p].start = flame;}
					if (teki[p].vecy == 0){
						teki[p].x += teki[p].vecx;
						teki[p].y = danmaku.GetY(teki[p].x, tteki[p].usef, tteki[p].kanshu, tteki[p].fugou);
						switch (tteki[p].usef){
						case 3:
							if (teki[p].y < 153){
								teki[p].vecx = 0;
								teki[p].vecy = (20 - teki[p].y) / 150;
								tteki[p].fugou = -1;
							}
							break;
						case 4:
							if (teki[p].y < 183){
								teki[p].vecx = 0;
								teki[p].vecy = (20 - teki[p].y) / 150;
								tteki[p].fugou = -1;
							}
							break;
						case 5:
							if (teki[p].y < 153){
								teki[p].vecx = 0;
								teki[p].vecy = (20 - teki[p].y) / 150;
							}
							break;
						case 6:
							if (teki[p].y < 183){
								teki[p].vecx = 0;
								teki[p].vecy = (20 - teki[p].y) / 150;
							}
							break;
						}
					}
					else{
						teki[p].y += teki[p].vecy;
						teki[p].x = danmaku.GetX(teki[p].y, tteki[p].usef, tteki[p].kanshu, tteki[p].fugou);
					}
					if((flame  - teki[p].start) % 350 == 0 && flame  - teki[p].start > 350){
						danmaku.Setdanmaku_ChainRendan((int)(teki[p].x), (int)(teki[p].y), 3, danmaku.Getkakudo_Homing(teki[p].x, teki[p].y, j.x, j.y), 1, danmaku.dcolor.pink, 0, 1, 0);
					}
					break;
				case 10://1:25～1:47
					teki[p].y += teki[p].vecy;
					if(teki[p].y == 155){
						teki[p].vecy = (5 - teki[p].y) / 120;
						danmaku.Setdanmaku_ChainRendan((int)(teki[p].x), (int)(teki[p].y), 2, (int)(danmaku.Getkakudo_Homing(teki[p].x, teki[p].y, j.x, j.y)), 6, danmaku.dcolor.blue, 0, 2, 10);
					}
					if(teki[p].vecy < 0){
						if(teki[p].y == 145){
							danmaku.Setdanmaku_ChainRendan((int)(teki[p].x), (int)(teki[p].y), 2, (int)(danmaku.Getkakudo_Homing(teki[p].x, teki[p].y, j.x, j.y)), 6, danmaku.dcolor.blue, 0, 1, 10);
						}
					}
					break;
				case 11://1:48 ～ 2:01
					if(wait[p - 84] == 0){
						teki[p].y += teki[p].vecy;
						teki[p].x += teki[p].vecx;
						if(teki[p].vecy == 0){
							if(teki[p].x == 162){
								wait[p - 84] = 12;
								teki[p].vecx = -2.2;
								teki[p].vecy = 1.5;
								teki[p].imgposi = 1;
							}
							if(teki[p].x == 222){
									wait[p - 84] = 12;
									teki[p].vecx = 2.2;
									teki[p].vecy = 1.5;
									teki[p].imgposi = 2;
								}
							}else{
								if((int)(teki[p].x) == 96 && teki[p].y < 300){
									teki[p].x = 96;
									wait[p - 84] = 60;
									teki[p].vecx = (330 - 96) / 60;
									teki[p].vecy = (465 - teki[p].y) / 60;
								}
								if((int)(teki[p].x) >= 288 && teki[p].y < 300){
									teki[p].x = 288;
									wait[p - 84] = 60;
									teki[p].vecx = (54 - 288) / 60;
									teki[p].vecy = (465 - teki[p].y) / 60;
								}
							}
					}
					else{
						wait[p - 84]--;
						if (wait[p - 84] == 0 && (teki[p].x == 96 || teki[p].x == 288)){
							if (teki[p].imgposi == 1){
								teki[p].imgposi = 2;
							}
							else{
								if (teki[p].imgposi == 2){
									teki[p].imgposi = 1;
								}
							}
							danmaku.Setdanmaku_ChainRendan((int)(teki[p].x), (int)(teki[p].y), 2, danmaku.Getkakudo_Homing(teki[p].x, teki[p].y, j.x, j.y), 6, danmaku.dcolor.purple, 0, 1, 0);
							danmaku.Setdanmaku_Wave((int)(teki[p].x), (int)(teki[p].y), 2, 6, danmaku.dcolor.purple, 0, 12, 4);
						}
					}
					break;
				case 12:
					if(wait[p - 84] == 0){
							teki[p].y += teki[p].vecy;
							teki[p].x += teki[p].vecx;
							if(teki[p].x == 54){
								wait[p - 84] = 30;
								teki[p].vecx *= -1;
								teki[p].imgposi = 4;
								vectorchange[p - 92]++;
							}
							if(teki[p].x == 330){
								wait[p - 84] = 30;
								teki[p].vecx *= -1;
								teki[p].imgposi = 3;
								vectorchange[p - 92]++;
							}
							if((int)(teki[p].x) == 162 && teki[p].y > 20 && vectorchange[p - 92] == 1){
								teki[p].x = 162;
								wait[p - 84] = 30;
								teki[p].vecx = (288 - 162) / 60;
								teki[p].vecy = (20 - teki[p].y) / 60;
								vectorchange[p - 92]++;
							}
							if((int)(teki[p].x) == 222 && teki[p].y > 20 && vectorchange[p - 92] == 1){
								teki[p].x = 222;
								wait[p - 84] = 30;
								teki[p].vecx = (96 - 222) / 60;
								teki[p].vecy = (20 - teki[p].y) / 60;
								vectorchange[p - 92]++;
							}
					}
					else{
						wait[p - 84]--;
						if (wait[p - 84] == 0 && (teki[p].x == 162 || teki[p].x == 222)){
							if (teki[p].imgposi == 4){
								teki[p].imgposi = 6;
							}
							else{
								if (teki[p].imgposi == 3){
									teki[p].imgposi = 5;
								}
							}
							danmaku.Setdanmaku_ArrowRendan((int)(teki[p].x), (int)(teki[p].y), danmaku.Getkakudo_Homing(teki[p].x, teki[p].y, j.x, j.y), 1, danmaku.dcolor.orange, 0, 2, 1, 1.5);
						}
					}
					if(tekicount == 0){scene++;}
					break;
				case 13:
					if (wait[p - 84] == 0){
						teki[p].y += teki[p].vecy;
						teki[p].x += teki[p].vecx;
						if (teki[p].vecx > 0 && teki[p].vecy < 0 && (int)(teki[p].x) >= 330){
							teki[p].imgposi = 3;
							teki[p].x = 330;
							teki[p].y = 35;
							teki[p].vecx = (162 - 330) / 60;
							teki[p].vecy = 0;
							wait[p - 84] = 30;
						}
						if (teki[p].vecx < 0 && teki[p].vecy < 0 && (int)(teki[p].x) <= 54){
							teki[p].vecx = (222 - 54) / 60;
							teki[p].x = 54;
							teki[p].y = 35;
							teki[p].imgposi = 4;
							teki[p].vecy = 0;
							wait[p - 84] = 30;
						}
						if (teki[p].vecx > 0 && teki[p].vecy == 0 && (int)(teki[p].x) >= 222){
							teki[p].x = 222;
							teki[p].vecx = (330 - 222) / 30;
							teki[p].vecy = (467 - 35) / 30;
							wait[p - 84] = 60;
						}
						if (teki[p].vecx < 0 && teki[p].vecy == 0 && (int)(teki[p].x) <= 162){
							teki[p].x = 162;
							teki[p].vecx = (54 - 162) / 30;
							teki[p].vecy = (467 - 35) / 30;
							wait[p - 84] = 60;
						}
					}
					else{
						wait[p - 84]--;
						if (wait[p - 84] == 0 && teki[p].vecy > 0){
							int color;
							if (teki[p].vecx > 0){
								teki[p].imgposi = 2;
								color = danmaku.dcolor.blue;
							}
							else{
								teki[p].imgposi = 1;
								color = danmaku.dcolor.red;
							}
							danmaku.Setdanmaku_Wave((int)(teki[p].x), (int)(teki[p].y), 3, 7, color, 0, 15, 20);
						}
					}
					if(tekicount == 0){scene++;}
					break;
				default:
					break;
				}
			}else{
			    teki[p].ready -= 1;
				if(scene == 1 && teki[p].ready == 0 && p == 9){
					danmaku.Setdanmaku_Ko((int)(teki[p].x), (int)(teki[p].y), 3, 6, danmaku.dcolor.yellow, 1, 60, 120, 7);
				}
				if(scene == 10 && teki[p].ready == 0 && Endtime - Begintime - Currenttime < 3){
					teki[p].ready = 1000;
				}
			}
			p = teki[p].np;
		}
		if(tekicount > 0){
			if (PasteDot() != 0){ r = -1; }
		}		
		if(danmaku.dancount > 0){
			if(danmaku.ProcessDanmaku(flame,scene) != 0){r = -1;}
			if(flame % 30 == 0){danmaku.DanmakuRefresh();}
		}
		if(r == -1){
			r = -1;
		}
		return r;
	};
	bool Stage1::ProcessAya(int flame){
		bool rr = true;
		int r = 0;
		rr = true;
		prescene = scene;
		if(flame == 1){
				Bosstime--;
		}//一秒経過ごとに加算。
		SetDrawArea(20,15,404,465);
		if(s != -1 && scene != 0){
			switch(scene){
			    case 7://中ボス戦開始、右上側から登場
					aya.imgpoji = DotAct.left;
					aya.x += aya.vecx;
					break;
				case 8://中ボス戦通常
					
					if(Currenttime % Looptime == 0 && flame == 1){//最初に20wayのring弾を発射
						aya.vecx = 0;
						aya.imgpoji = DotAct.common;
						danmaku.Setdanmaku_Wave((int)(aya.x),(int)(aya.y),2,6,0,0,0,15);
					}else{
						if(Currenttime % Looptime == 0 && flame == 30){//次に波状40wayのtubu弾を発射
							danmaku.Setdanmaku_Wave((int)(aya.x), (int)(aya.y), 2, 1, danmaku.dcolor.orange, 0, 0, 40);
							targetkakudo = danmaku.Getkakudo_Homing(aya.x,aya.y,j.x,j.y) + 90;
							d = (int)(sqrt(pow(j.x - aya.x,2.0) + pow(j.y - aya.y,2.0))) - 50;
						}else{
							if((Currenttime % Looptime < 5) && !(Currenttime % Looptime == 4 && flame == 60)){
								//01:00から3:00まで30F間隔でtargetkakudo,+10,+20,+30のポイントに向けて波状12wayのtwin弾を発射。ポイントには75Fで到達。
								if(flame % 30 == 0){
									danmaku.Setdanmaku_Pointwave((int)(aya.x), (int)(aya.y), 75, 8, danmaku.dcolor.green, 0, (int)(targetkakudo), (int)(aya.x + d * cos(targetkakudo * PI / 180)), (int)(aya.y - d * sin(targetkakudo * PI / 180)), 30, 12);
									targetkakudo -= 30;
								}
							}else{
								if(Currenttime % Looptime == 4 && flame == 60){
									d = (int)(sqrt(pow(j.x - aya.x,2.0) + pow(j.y - aya.y,2.0)));
									targetkakudo = danmaku.Getkakudo_Homing(aya.x,aya.y,j.x,j.y);
									danmaku.Setdanmaku_Pointwave((int)(aya.x), (int)(aya.y), 50, 13, danmaku.dcolor.yellow, 0, (int)(targetkakudo), (int)(aya.x + d * cos(targetkakudo * PI / 180)), (int)(aya.y - d * sin(targetkakudo * PI / 180)), 30, 12);
								}
							}
						}
					}
					break;
				case 9://中ボス戦終了　左上側へ退散
					if(Currenttime > 0){
						aya.x += aya.vecx;
						aya.y += aya.vecy;
						aya.imgpoji = DotAct.left;
					}
				    break;
				case 14://大ボス戦インターバル
					/*
					*/
					switch(Talkcount){
						case 14://最初は早苗のみ
							JikiStandPosition = 1;
							BossStandPosition = -1;
							Shadowflg = 1;
							standx = -80;
							standy = 180;
							selif1 = "う～ん、思った以上に事は深刻なよう";
							selif2 = "です。";
							break;
						case 13:
							JikiStandPosition = 2;
							selif1 = "ここは霊夢さんたちに任せる";
							selif2 = "べきでしょうか。";
							break;
						case 12://次からは咲夜パートも追加
							if (PlayerData.jikinum == 2){
								JikiStandPosition = 1;
								selif1 = "いや、そもそも異変解決に動いて";
								selif2 = "いるのかすら怪しいところです。";
							}
							else{
								JikiStandPosition = 1;
								BossStandPosition = -1;
								Shadowflg = 1;
								standx = -10;
								standy = 180;
								selif1 = "まったく、あのふたりは何をして";
								selif2 = "いるのかしら。";
							}
							break;
						case 11:
							if (PlayerData.jikinum == 2){
								Shadowflg = 0;
								selif1 = "あの二人？";
								selif2 = "";
								aya.x = -50;
								aya.y = -50;
								aya.imgpoji = DotAct.right;
								aya.vecx = (208 + 50) / 60;
								aya.vecy = (100 + 50) / 60;
							}else{
								selif1 = "これくらいの異変、私が出るまでも";
								selif2 = "ないのに。";
							}
							break;
						case 10:
							if (PlayerData.jikinum == 2){
								BossStandPosition = 1;
								selif1 = "博麗の巫女と魔法使いのことかしら？";
								selif2 = "";
							}else{
								Shadowflg = 0;
								selif1 = "あ、いましたね。";
								selif2 = "";
								aya.x = -50;
								aya.y = -50;
								aya.imgpoji = DotAct.right;
								aya.vecx = (208 + 50) / 60;
								aya.vecy = (100 + 50) / 60;
							}
							break;
						case 9:
							if (PlayerData.jikinum == 2){
								Shadowflg = 1;
								selif1 = "あ、ブン屋さん。いい記事ができまし";
								selif2 = "たか？";
							}else{
								BossStandPosition = 1;
								selif1 = "貴方も動いてたのですか。";
								selif2 = "";
								}
							break;
						case 8:
							if (PlayerData.jikinum == 2){
								Shadowflg = 0;
								BossStandPosition = StandAct.doubt;
								selif1 = "記事もなにも、商売道具がなければ";
								selif2 = "何もできないわよ。";
							}else{
								Shadowflg = 1;
								JikiStandPosition = 2;
								selif1 = "…湧いて出たわね。正装で。";
								selif2 = "";
							}
							break;
						case 7:
							if (PlayerData.jikinum == 2){
								
								selif1 = "しかも普段着ないような服を";
								selif2 = "切ることになるなんて…";
							}else{
								Shadowflg = 0;
								BossStandPosition = 2;
								selif1 = "勘弁してください。今日はこの服装でしか";
								selif2 = "取材できないのですよ。";
							}
							break;
						case 6:
							if (PlayerData.jikinum == 2){
								Shadowflg = 1;
								JikiStandPosition = 2;
								selif1 = "確かにいつもより派手な服装ですね。";
								selif2 = "";
							}else{
								Shadowflg = 1;
								JikiStandPosition = 9;
								selif1 = "ブン屋なんだし、その格好で写真集でも";
								selif2 = "出してみたらいかがかしら？";
							}
							break;
						case 5:
							if (PlayerData.jikinum == 2){
								JikiStandPosition = 1;
								selif1 = "霊夢さんとか見ませんでしたか？";
								selif2 = "もう異変解決に動いてるはずですが。";
							}else{
								Shadowflg = 0;
								BossStandPosition = StandAct.amazed;
								selif1 = "その予定もないですけど、今日の記事は";
								selif2 = "文面だけのものになりそうです。";
							}
							break;
						case 4:
							if (PlayerData.jikinum == 2){
								Shadowflg = 0;
								BossStandPosition = 2;
								selif1 = "さぁ、見てないわ。それより…";
								selif2 = "";
							}else{
								Shadowflg = 1;
								JikiStandPosition = 2;
								selif1 = "ふーんそう。でも同じ文面なら";
								selif2 = "";
							}
							break;
						case 3:
							if (PlayerData.jikinum == 2){
								BossStandPosition = 1;
								selif1 = "今の私は気が立ってるわ。あなたでも";
								selif2 = "いいから相手になってくれない？";
							}else{
								JikiStandPosition = 2;
								selif1 = "私よりもいい記事が書けるネタがあるわ。";
								selif2 = "だから私の邪魔をしないで。";
							}
							break;
						case 2:
							if (PlayerData.jikinum == 2){
								Shadowflg = 1;
								JikiStandPosition = 1;
								selif1 = "え？まぁいいですけど。";
								selif2 = "";
							}else{
								Shadowflg = 0;
								BossStandPosition = 2;
								selif1 = "まぁそうおっしゃらず。私も貴方も、";
								selif2 = "この異変に巻き込まれてますからね！";
							}
							break;
						case 1:
							if (PlayerData.jikinum == 2){
								JikiStandPosition = 1;
								selif1 = "（いいのかなぁ、これで）";
								selif2 = "";
							}else{
								JikiStandPosition = 9;
								Shadowflg = 1;
								selif1 = "では力ずくで。";
								selif2 = "";
							}
							break;
					}
					int jikicolor;
					int bossy, jikiy;
					if (PlayerData.jikinum == 2){
						jikicolor = GetColor(200, 200, 250);
						jikiy = 210;
						bossy = 195;
					}
					else{
						jikicolor = GetColor(150, 200, 150);
						jikiy = 210;
						bossy = 210;
					}
					if (BossStandPosition == -1){
						BossTalking(0, GetColor(255, 80, 80), jikicolor, 170, bossy, jikiy, 0);
					}
					else{
						BossTalking(ayastand[BossStandPosition], GetColor(255, 80, 80), jikicolor, 170, bossy, jikiy, 0);
					}
					if (PlayerData.jikinum == 2){
						if (Talkcount < 11){
							if (aya.x < 208){
								aya.x += aya.vecx;
								aya.y += aya.vecy;
							}
							else{
								aya.imgpoji = DotAct.common;
								aya.x = 208;
								aya.y = 80;
							}
						}
					}
					else{
						if (Talkcount < 10){
							if (aya.x < 208){
								aya.x += aya.vecx;
								aya.y += aya.vecy;
							}
							else{
								aya.imgpoji = DotAct.common;
								aya.x = 208;
								aya.y = 80;
							}
						}
					}
				    break;
			    case 15://大ボス戦 通常1
					timetoflame = (Currenttime % Looptime) * 60 + flame;
					switch (timetoflame){
					case 1:
						for (int k = 60; k < 121; k += 15){
							if (k == 75 || k == 105){
								danmaku.Setdanmaku_Pointwave((int)(aya.x), (int)(aya.y), 50, 13, danmaku.dcolor.orange, 0, (int)(targetkakudo), (int)(aya.x + 100 * cos(k * PI / 180)), (int)(aya.y - 100 * sin(k * PI / 180)), 30, 12);
							}
							else{
								danmaku.Setdanmaku_Pointwave((int)(aya.x), (int)(aya.y), 50, 13, danmaku.dcolor.orange, 0, (int)(targetkakudo), (int)(aya.x + 50 * cos(k * PI / 180)), (int)(aya.y - 50 * sin(k * PI / 180)), 30, 12);
							}
						}
						break;
					case 60:
						danmaku.Setdanmaku_ChainRendan((int)(aya.x), (int)(aya.y), 2, danmaku.Getkakudo_Homing(aya.x, aya.y, j.x, j.y), danmaku.dshu.kunai, danmaku.dcolor.orange, 0, 10, 15);
						break;
					case 70:
						danmaku.Setdanmaku_ChainRendan((int)(aya.x), (int)(aya.y), 2, danmaku.Getkakudo_Homing(aya.x, aya.y, j.x, j.y) + 10, danmaku.dshu.uroko, danmaku.dcolor.yellow, 0, 10, 15);
						danmaku.Setdanmaku_ChainRendan((int)(aya.x), (int)(aya.y), 2, danmaku.Getkakudo_Homing(aya.x, aya.y, j.x, j.y) - 10, danmaku.dshu.uroko, danmaku.dcolor.yellow, 0, 10, 15);
						break;
					case 150:
						danmaku.Setdanmaku_Ko((int)(aya.x), (int)(aya.y), 2, danmaku.dshu.kunai, danmaku.dcolor.orange, 0, 45, 135, 19);
						break;
					}
				    break;
				case 16://大ボス戦 スペルカード1
					if (Currenttime < 2){
						StartSpellkardEffect(ayastand[1]);
						appeary++;
						if ((int)(aya.x) != 212){
							aya.x += aya.vecx;
						}
						else{
							aya.x = 212;
						}
					}
					else{
						Bosshit = true;
						timetoflame = ((Currenttime - 2) % Looptime) * 60 + flame;
						switch (timetoflame){
						case 1:
							danmaku.Setdanmaku_Wave((int)(aya.x), (int)(aya.y), 1.5, danmaku.dshu.uroko, danmaku.dcolor.yellow, 0, 0, 20, danmaku.worder.round, -0.2);
							break;
						case 10:
							danmaku.Setdanmaku_Wave((int)(aya.x), (int)(aya.y), 1.5, danmaku.dshu.uroko, danmaku.dcolor.yellow, 0, 0, 20, danmaku.worder.round, 0.2);
							break;
						case 20:
							danmaku.Setdanmaku_Wave((int)(aya.x), (int)(aya.y), 1.5, danmaku.dshu.uroko, danmaku.dcolor.yellow, 0, 0, 20, danmaku.worder.round, -0.2);
							break;
						case 30:
							danmaku.Setdanmaku_Wave((int)(aya.x), (int)(aya.y), 1.5, danmaku.dshu.uroko, danmaku.dcolor.yellow, 0, 0, 20, danmaku.worder.round, 0.2);
							break;
						case 40:
							danmaku.Setdanmaku_Wave((int)(aya.x), (int)(aya.y), 1.5, danmaku.dshu.uroko, danmaku.dcolor.yellow, 0, 0, 20, danmaku.worder.round, -0.2);
							break;
						case 120:
							danmaku.Setdanmaku_ChainRendan((int)(aya.x), (int)(aya.y), 3.5, danmaku.Getkakudo_Homing(aya.x, aya.y, 20, 243), danmaku.dshu.big, danmaku.dcolor.red, 0, 1, 0);
							danmaku.Setdanmaku_ChainRendan((int)(aya.x), (int)(aya.y), 3.5, danmaku.Getkakudo_Homing(aya.x, aya.y, 404, 243), danmaku.dshu.big, danmaku.dcolor.red, 0, 1, 0);
							break;
						case 180:
							danmaku.Setdanmaku_Ko(404, 243, 2, danmaku.dshu.kunai, danmaku.dcolor.red, 0, 45, 315, 31);
							danmaku.Setdanmaku_Ko(20, 243, 2, danmaku.dshu.kunai, danmaku.dcolor.red, 0, 225, 495, 31);
							break;
						}
					}
				    break;
				case 17://大ボス戦 通常2
					if (Currenttime < 3){
						EndSpellkardEffect(100000, SpellBonusScore);
					}
					else{
						Bosshit = true;
						timetoflame = ((Currenttime - 3) % Looptime) * 60 + flame;
						aya.x += aya.vecx;
						switch (timetoflame){
						case 1:
							aya.vecx = 0;
							aya.imgpoji = DotAct.common;
							switch ((int)(aya.x)){
							case 92:
								danmaku.Setdanmaku_ArrowRendan((int)(aya.x), (int)(aya.y), 30, danmaku.dshu.kunai, danmaku.dcolor.green, 15, 10, 10, 1);
								break;
							case 212:
								danmaku.Setdanmaku_ArrowRendan((int)(aya.x), (int)(aya.y), 135, danmaku.dshu.kunai, danmaku.dcolor.green, 15, 10, 10, 1);
								break;
							case 332:
								danmaku.Setdanmaku_ArrowRendan((int)(aya.x), (int)(aya.y), 150, danmaku.dshu.kunai, danmaku.dcolor.green, 15, 10, 10, 1);
								break;
							}
							break;
						case 15:
							switch ((int)(aya.x)){
							case 92:
								danmaku.Setdanmaku_ArrowRendan((int)(aya.x), (int)(aya.y), 90, danmaku.dshu.kunai, danmaku.dcolor.green, 15, 10, 10, 1);
								break;
							case 212:
								danmaku.Setdanmaku_ArrowRendan((int)(aya.x), (int)(aya.y), 45, danmaku.dshu.kunai, danmaku.dcolor.green, 15, 10, 10, 1);
								break;
							case 332:
								danmaku.Setdanmaku_ArrowRendan((int)(aya.x), (int)(aya.y), 90, danmaku.dshu.kunai, danmaku.dcolor.green, 15, 10, 10, 1);
								break;
							}
							break;
						case 30:
							switch ((int)(aya.x)){
							case 92:
								danmaku.Setdanmaku_ArrowRendan((int)(aya.x), (int)(aya.y), 45, danmaku.dshu.kunai, danmaku.dcolor.yellow, 15, 10, 10, 1);
								break;
							case 212:
								danmaku.Setdanmaku_ArrowRendan((int)(aya.x), (int)(aya.y), 105, danmaku.dshu.kunai, danmaku.dcolor.yellow, 15, 10, 10, 1);
								break;
							case 332:
								danmaku.Setdanmaku_ArrowRendan((int)(aya.x), (int)(aya.y), 135, danmaku.dshu.kunai, danmaku.dcolor.yellow, 15, 10, 10, 1);
								break;
							}
							break;
						case 45:
							switch ((int)(aya.x)){
							case 92:
								danmaku.Setdanmaku_ArrowRendan((int)(aya.x), (int)(aya.y), 75, danmaku.dshu.kunai, danmaku.dcolor.yellow, 15, 10, 10, 1);
								break;
							case 212:
								danmaku.Setdanmaku_ArrowRendan((int)(aya.x), (int)(aya.y), 75, danmaku.dshu.kunai, danmaku.dcolor.yellow, 15, 10, 10, 1);
								break;
							case 332:
								danmaku.Setdanmaku_ArrowRendan((int)(aya.x), (int)(aya.y), 105, danmaku.dshu.kunai, danmaku.dcolor.yellow, 15, 10, 10, 1);
								break;
							}
							break;
						case 60:
							switch ((int)(aya.x)){
							case 92:
								danmaku.Setdanmaku_ArrowRendan((int)(aya.x), (int)(aya.y), 60, danmaku.dshu.kunai, danmaku.dcolor.red, 15, 10, 10, 1);
								targetkakudo = 145;
								break;
							case 212:
								danmaku.Setdanmaku_ArrowRendan((int)(aya.x), (int)(aya.y), 90, danmaku.dshu.kunai, danmaku.dcolor.red, 15, 10, 10, 1);
								targetkakudo = 190;
								break;
							case 332:
								danmaku.Setdanmaku_ArrowRendan((int)(aya.x), (int)(aya.y), 120, danmaku.dshu.kunai, danmaku.dcolor.red, 15, 10, 10, 1);
								targetkakudo = 235;
								break;
							}
							break;
						case 301:
							switch ((int)(aya.x)){
							case 92:
								aya.imgpoji = DotAct.right;
								aya.vecx = 2;
								break;
							case 212:
								if (aya.x < j.x){
									aya.imgpoji = DotAct.left;
									aya.vecx = -2;
								}
								else{
									aya.imgpoji = DotAct.right;
									aya.vecx = 2;
								}
								break;
							case 332:
								aya.imgpoji = DotAct.left;
								aya.vecx = -2;
								break;
							}
							break;
						}
						if (timetoflame > 149 && timetoflame < 191){
							danmaku.Setdanmaku_ChainRendan((int)(aya.x), (int)(aya.y), 2, targetkakudo, danmaku.dshu.kunai, danmaku.dcolor.yellow, 0, 1, 0);
							targetkakudo -= 5;
						}
						if (timetoflame > 190 && timetoflame < 231){
							danmaku.Setdanmaku_ChainRendan((int)(aya.x), (int)(aya.y), 2, targetkakudo, danmaku.dshu.kunai, danmaku.dcolor.orange, 0, 2, 0);
							targetkakudo += 5;
						}
						if (timetoflame > 230 && timetoflame < 271){
							danmaku.Setdanmaku_ChainRendan((int)(aya.x), (int)(aya.y), 2, targetkakudo, danmaku.dshu.kunai, danmaku.dcolor.red, 0, 1, 0);
							targetkakudo -= 5;
						}
					}
				    break;
				case 18://大ボス戦 スペルカード2
					if (Currenttime < 2){
						StartSpellkardEffect(ayastand[1]);
						appeary++;
						if ((int)(aya.x) != 212) {
							aya.x += aya.vecx;
						}
						else {
							aya.x = 212;
						}
					}
					else{
						Bosshit = true;
						
						timetoflame = ((Currenttime - 2) % Looptime) * 60 + flame;
						switch (timetoflame){
						case 1:
							//danmaku.Setdanmaku_Wave((int)(aya.x), (int)(aya.y), 1.5, danmaku.dshu.uroko, danmaku.dcolor.white, 0, 0, 30);
							break;
						case 15:
							danmaku.Setdanmaku_Wave((int)(aya.x), (int)(aya.y), 1.5, danmaku.dshu.uroko, danmaku.dcolor.green, 0, 5, 30);
							break;
						case 30:
							//danmaku.Setdanmaku_Wave((int)(aya.x), (int)(aya.y), 1.5, danmaku.dshu.uroko, danmaku.dcolor.white, 0, 25, 40);
							break;
						case 45:
							danmaku.Setdanmaku_Wave((int)(aya.x), (int)(aya.y), 1.5, danmaku.dshu.middle, danmaku.dcolor.green, 0, danmaku.Getkakudo_Homing(aya.x, aya.y, j.x, j.y), 30);
							break;
						}
						if ((timetoflame % 10) == 0){
							danmaku.Setdanmaku_ChainRendan((int)(aya.x), (int)(aya.y), 2, targetkakudo, danmaku.dshu.big, danmaku.dcolor.red, 0, 1, 0);
							targetkakudo += 20;
						}
					}
				    break;
				case 19://大ボス戦終了　爆散
					/*
					
*/
					switch (Talkcount){
					case 4:
						if (PlayerData.jikinum == 2){
							selif1 = "あの人が狼狽えるほどの異変なので";
							selif2 = "しょうか。";
						}
						else{
							selif1 = "ふ～ん、あの妖怪でもこの異変から";
							selif2 = "逃れられてないのね。";
						}
						break;
					case 3:
						if (PlayerData.jikinum == 2){
							selif1 = "最初は誰かに任せるつもりでしたが…。";
							selif2 = "";
						}
						else{
							selif1 = "これは手当たり次第に探っていこう";
							selif2 = "かしら？";
						}
						break;
					case 2:
						if (PlayerData.jikinum == 2){
							selif1 = "もう少しばかり協力しましょうか。";
							JikiStandPosition = 2;
						}
						else{
							selif1 = "それでいいところであの二人に";
							selif2 = "異変解決させることにしましょう。";
							JikiStandPosition = 9;
						}
						break;
					case 1:
						if (j.slow > 0){
							TalkSkipCancel = true;
						}
						else{
							TalkSkipCancel = false;
						}
						break;
					}
					if (PlayerData.jikinum == 0){
						jikicolor = GetColor(200, 200, 250);
						jikiy = 225;
					}
					else{
						jikicolor = GetColor(150, 200, 150);
						jikiy = 210;
					}
					if (Talkcount > 1){
						BossTalking(0, GetColor(150, 150, 200), jikicolor, 170, 0, jikiy, 0);
					}
					if (SpellBonusScore != 0 && Bosstime > 997){
						EndSpellkardEffect(150000, SpellBonusScore);
					}
				    break;
			}
			if(scene != 14 && scene != 19){
				DrawGraph((int)(aya.x - 30),(int)(aya.y - 45),ayadot[aya.imgpoji],true);
				
			}
			if (scene == 14){
				if (PlayerData.jikinum == 2){
					if (Talkcount < 11){
						DrawGraph((int)(aya.x - 30), (int)(aya.y - 45), ayadot[aya.imgpoji], true);
					}
				}
				else{
					if (Talkcount < 10){
						DrawGraph((int)(aya.x - 30), (int)(aya.y - 45), ayadot[aya.imgpoji], true);
					}
				}
			}
		}
		danmaku.ProcessBossDanmaku(flame + Currenttime * 60, scene, PlayerData.jikinum, (int)(aya.x), (int)(aya.y));
		if (BossTalk == false){ r = DisplayBossStates(aya.hitpoint, aya.phasecount); }
		if (Spell){ DisplaySpellStates(); }
		SetDrawArea(1,1,639,479);
		if((scene == 10 && prescene == 9)/*||(scene == 10 && prescene == 9)*/){//フェーズの進行度に応じてボス戦が終了する。
			rr = false;
		}
		if(r != 0){
			r = -1;
		}
		return rr;
	}
	bool Stage1::ProcessAlice(int flame){
		bool rr = true;
		int r = 0;
		prescene = scene;
		if (flame == 1){
			Bosstime--;
		}
		//一秒経過ごとに加算。
		SetDrawArea(20,15,404,465);
		if (scene != 0){
			switch (scene){
			case 7://中ボス戦開始、左上側から登場
				alice.x += alice.vecx;
				if (alice.x >= 208){
					alice.vecx = 0;
					alice.x = 208;
				}
				DrawGraph((int)(alice.x - 30), (int)(alice.y - 45), alicedot[alice.imgpoji], true);
				break;
			case 8://中ボス戦通常
				if (Currenttime % Looptime == 0 && flame == 1){//最初に20wayのring弾を発射
					alice.vecx = 0;
					danmaku.Setdanmaku_Wave((int)(alice.x), (int)(alice.y), 4, 6, danmaku.dcolor.yellow, 0, 10, 20);
				}
				else{
					if (Currenttime % Looptime == 0 && flame == 30){//次に自機に向けて8連射のuroko弾を発射
						danmaku.Setdanmaku_ChainRendan((int)(alice.x), (int)(alice.y), 3, (int)(danmaku.Getkakudo_Homing(alice.x, alice.y, j.x, j.y)), 4, danmaku.dcolor.blue, 0, 8, 7);
						danmaku.Setdanmaku_Wave((int)(alice.x), (int)(alice.y), 4, 6, danmaku.dcolor.red, 0, danmaku.Getkakudo_Homing(alice.x, alice.y, j.x, j.y), 30);
					}
					else{
						if ((Currenttime % Looptime == 2 && flame > 30) || (Currenttime % Looptime == 3)){
							if (flame == 31){
								alice.vecx = (j.x - alice.x) / 60;
							}
							else{
								alice.x += alice.vecx;
							}
						}
					}
				}
				DrawGraph((int)(alice.x - 30), (int)(alice.y - 45), alicedot[alice.imgpoji], true);
				break;
			case 9://中ボス戦終了　左上側へ退散
				if (Currenttime > 0){
					alice.x += alice.vecx;
					alice.y += alice.vecy;
				}
				DrawGraph((int)(alice.x - 30), (int)(alice.y - 45), alicedot[alice.imgpoji], true);
				break;
			case 14://大ボス戦インターバル

				/*
				*/
				switch (Talkcount){
				case 12://12～11は布都のみ
					JikiStandPosition = 1;
					BossStandPosition = -1;
					Shadowflg = 1;
					standx = -10;
					standy = 180;
					selif1 = "この程度の異変なら我が動かずとも、";
					selif2 = "博麗の巫女や魔法使いが動くはずだが…";
					break;
				case 11:
					JikiStandPosition = 2;
					selif1 = "しかし、それにしては長引いている。";
					selif2 = "";
					break;
				case 10:
					Shadowflg = 0;
					alice.x = -50;
					alice.y = -50;
					alice.vecx = (double)(208 + 50) / 80;
					alice.vecy = (double)(100 + 50) / 80;
					alice.imgpoji = DotAct.common;
					selif1 = "そうね。";
					selif2 = "";
					break;
				case 9://ここからは布都・魅魔
					if (PlayerData.jikinum == 0){
						BossStandPosition = 1;
						selif1 = "日常生活に支障をきたす前に";
						selif2 = "さっさと異変解決してもらいたいわ";

					}
					else{
						JikiStandPosition = 1;
						BossStandPosition = -1;
						Shadowflg = 1;
						standx = -40;
						standy = 180;
						selif1 = "ふふ、久々の新鮮な空気だ。";
						selif2 = "";

					}
					break;
				case 8:
					if (PlayerData.jikinum == 0){
						Shadowflg = 1;
						selif1 = "お主も異変の被害者か？";
						selif2 = "";
					}
					else{
						JikiStandPosition = 2;
						selif1 = "こうなるとひと暴れしたくなるねぇ";
					}
					break;
				case 7:
					if (PlayerData.jikinum == 0){
						Shadowflg = 0;
						BossStandPosition = 1;
						selif1 = "私の人形たちがいなくなってしまったわ。	";
						selif2 = "今は独り身が頼りね。";
					}
					else{
						Shadowflg = 0;
						selif1 = "・・・";
						alice.x = -50;
						alice.y = -50;
						alice.vecx = (double)(208 + 50) / 80;
						alice.vecy = (double)(100 + 50) / 80;
						alice.imgpoji = DotAct.common;
					}
					break;
				case 6:
					if (PlayerData.jikinum == 0){
						Shadowflg = 1;
						JikiStandPosition = 2;
						selif1 = "むぅ、そうか。では例の二人は？";
						selif2 = "";
					}
					else{
						BossStandPosition = StandAct.surprised;
						selif1 = "お久しぶり・・・なのかしら？";
						selif2 = "";
						if (alice.x < 208){
							alice.x += alice.vecx;
							alice.y += alice.vecy;
						}
						else{
							alice.x = 208;
							alice.y = 80;
						}
					}
					break;
				case 5:

					if (PlayerData.jikinum == 0){
						Shadowflg = 0;
						BossStandPosition = 1;
						selif1 = "異変解決に行ったきり見てないわ。";
						selif2 = "";
					}
					else{
						Shadowflg = 1;
						JikiStandPosition = 1;
						selif1 = "さっき仕掛けてきたじゃないか。";
						selif2 = "";
					}
					break;
				case 4:

					if (PlayerData.jikinum == 0){
						Shadowflg = 1;
						JikiStandPosition = 2;
						selif1 = "なるほど。それならばさっそく…";
						selif2 = "";
					}
					else{
						Shadowflg = 0;
						BossStandPosition = 2;
						selif1 = "こんな時にあんたが湧いて出てくる";
						selif2 = "なんて、文字通り異変ね。";
					}
					break;
				case 3:

					if (PlayerData.jikinum == 0){
						JikiStandPosition = 1;
						selif1 = "お主が黒幕でないことを改めさせ";
						selif2 = "てもらうぞ。";
					}
					else{
						Shadowflg = 1;
						JikiStandPosition = 3;
						selif1 = "どういうことだい。";
						selif2 = "";
					}
					break;
				case 2:

					if (PlayerData.jikinum == 0){
						Shadowflg = 0;
						BossStandPosition = 2;
						selif1 = "あんたなんかに異変解決の任が";
						selif2 = "務まるかしら？";
					}
					else{

						Shadowflg = 0;
						BossStandPosition = 1;
						selif1 = "異変解決は私の担当じゃないけど、";
						selif2 = "ここでお返しをさせてもらうわ！";
					}
					break;
				case 1:

					if (PlayerData.jikinum == 0){
						Shadowflg = 1;
						JikiStandPosition = 1;
						selif1 = "これも確認のためだ。やましいこと";
						selif2 = "がなければ何も恐れることはない。";
					}
					else{
						Shadowflg = 1;
						JikiStandPosition = 2;
						selif1 = "やるのかい、望むところだ。";
						selif2 = "";
					}
					break;
				}
				int jikicolor;
				int bossy, jikiy;
				if (PlayerData.jikinum == 0){
					jikicolor = GetColor(255, 150, 150);
					bossy = 195;
					jikiy = 225;
				}
				else{
					jikicolor = GetColor(220, 220, 100);
					bossy = 225;
					jikiy = 210;
				}
				if (BossStandPosition > -2 && BossStandPosition < 11){
					BossTalking(alicestand[BossStandPosition], GetColor(150, 150, 200), jikicolor, 170, bossy, jikiy, 0);
				}
				if (PlayerData.jikinum == 0){
					if (Talkcount < 10){
						if (alice.x < 208){
							alice.x += alice.vecx;
							alice.y += alice.vecy;
						}
						else{
							alice.x = 208;
							alice.y = 100;
						}
					}
				}
				else{
					if (Talkcount < 7){
						if (alice.x < 208){
							alice.x += alice.vecx;
							alice.y += alice.vecy;
						}
						else{
							alice.x = 208;
							alice.y = 100;
						}
					}
				}
				if (j.slow > 0){
					alice.x = 208;
					alice.y = 100;
				}
				break;
			case 15://大ボス戦 通常1
				DrawGraph((int)(alice.x - 30), (int)(alice.y - 45), alicedot[alice.imgpoji], true);
				if (Currenttime > 0){
					if (flame == 1 && Currenttime == 1){
						alice.x = 208;
						alice.y = 100;
					}
					timetoflame = ((Currenttime - 1) % Looptime) * 60 + flame;
					switch (timetoflame){
					case 1:
						danmaku.DanmakuRefresh();
						danmaku.Setdanmaku_Ko((int)(alice.x), (int)(alice.y), 2.0, 7, danmaku.dcolor.red, 0, 90 - 30, 90 + 30, 10);
						break;
					case 21:
						danmaku.Setdanmaku_Ko((int)(alice.x), (int)(alice.y), 2.0, 7, danmaku.dcolor.orange , 0, 135 - 30, 135 + 30, 10);
						break;
					case 41:
						danmaku.Setdanmaku_Ko((int)(alice.x), (int)(alice.y), 2.0, 7, danmaku.dcolor.yellow, 0, 180 - 30, 180 + 30, 10);
						break;
					case 61:
						danmaku.Setdanmaku_Ko((int)(alice.x), (int)(alice.y), 2.0, 7, danmaku.dcolor.green, 0, 225 - 30, 225 + 30, 10);
						break;
					case 81:
						danmaku.Setdanmaku_Ko((int)(alice.x), (int)(alice.y), 2.0, 7, danmaku.dcolor.water, 0, 270 - 30, 270 + 30, 10);
						break;
					case 101:
						danmaku.Setdanmaku_Ko((int)(alice.x), (int)(alice.y), 2.0, 7, danmaku.dcolor.blue, 0, 315 - 30, 315 + 30, 10);
						break;
					case 121:
						danmaku.Setdanmaku_Ko((int)(alice.x), (int)(alice.y), 2.0, 7, danmaku.dcolor.purple, 0, 360 - 30, 360 + 30, 10);
						break;
					case 141:
						danmaku.Setdanmaku_Ko((int)(alice.x), (int)(alice.y), 2.0, 7, danmaku.dcolor.pink, 0, 45 - 30, 45 + 30, 10);
						break;
					case 181:
						danmaku.Setdanmaku_ArrowRendan((int)(alice.x), (int)(alice.y), danmaku.Getkakudo_Homing(alice.x, alice.y, j.x, j.y), 1, danmaku.dcolor.yellow, 0, 8, 4, 1.6);
						break;
					case 211:
						danmaku.refrect[0] = -1;
						danmaku.refrect[1] = -1;
						danmaku.Setdanmaku_ArrowRendan((int)(alice.x), (int)(alice.y), 45, 1, danmaku.dcolor.red, 0, 8, 7, 1);
						danmaku.Setdanmaku_ArrowRendan((int)(alice.x), (int)(alice.y), 135, 1, danmaku.dcolor.blue, 0, 8, 7, 1);
						break;
					case 271:
						danmaku.Setdanmaku_Wave((int)(alice.x), (int)(alice.y), 4, 7, danmaku.dcolor.blue, 0, 0, 24);
						break;
					case 301:
						danmaku.Setdanmaku_Wave((int)(alice.x), (int)(alice.y), 2, 7, danmaku.dcolor.red, 0, danmaku.Getkakudo_Homing(alice.x, alice.y, j.x, j.y), 40);
						break;
					}
				}
				break;
			case 16://大ボス戦 スペルカード1
				DrawGraph((int)(alice.x - 30), (int)(alice.y - 45), alicedot[alice.imgpoji], true);
				if (Currenttime < 2){
					appeary += 2;
					if (StartSpellkardEffect(alicestand[1]) != 0){ r = -1; }
				}
				else{
					Bosshit = true;
					timetoflame = ((Currenttime - 2) % Looptime) * 60 + flame;
					switch (timetoflame){
					case 1:
						alice.imgpoji = DotAct.act1;
						danmaku.Setdanmaku_ArrowRendan((int)(alice.x), (int)(alice.y), 0, 12, danmaku.dcolor.red, 0, 3, 6, 2);
						danmaku.Setdanmaku_ArrowRendan((int)(alice.x), (int)(alice.y), 180, 12, danmaku.dcolor.red, 0, 3, 6, 2);
						break;
					case 91:
						danmaku.Setdanmaku_ArrowRendan((int)(alice.x), (int)(alice.y), 0, 12, danmaku.dcolor.red, 0, 3, 6, 2);
						danmaku.Setdanmaku_ArrowRendan((int)(alice.x), (int)(alice.y), 180, 12, danmaku.dcolor.red, 0, 3, 6, 2);
						break;
					case 121:
						alice.imgpoji = DotAct.common;
						danmaku.Setdanmaku_ChainRendan((int)(alice.x), (int)(alice.y), 3, danmaku.Getkakudo_Homing(alice.x, alice.y, j.x, j.y), 1, danmaku.dcolor.green, 0, 10, 2);
						danmaku.Setdanmaku_ChainRendan((int)(alice.x), (int)(alice.y), 3, danmaku.Getkakudo_Homing(alice.x, alice.y, j.x, j.y) + 20, 1, danmaku.dcolor.blue, 0, 10, 2);
						danmaku.Setdanmaku_ChainRendan((int)(alice.x), (int)(alice.y), 3, danmaku.Getkakudo_Homing(alice.x, alice.y, j.x, j.y) - 20, 1, danmaku.dcolor.blue, 0, 10, 2);
						break;
					case 181:
						danmaku.Setdanmaku_Wave((int)(alice.x), (int)(alice.y), 4, 13, danmaku.dcolor.orange, 0, 0, 40);
						break;
					}
				}
				break;
			case 17://大ボス戦 通常2
				DrawGraph((int)(alice.x - 30), (int)(alice.y - 45), alicedot[alice.imgpoji], true);
				if (Currenttime * 60 + flame < 181){
					EndSpellkardEffect(100000, SpellBonusScore);
					Bosshit = false;
				}
				else{
					Bosshit = true;
					timetoflame = ((Currenttime - 3) % Looptime) * 60 + flame;
					switch (timetoflame){
					case 1:
						alice.imgpoji = DotAct.common;
						danmaku.Setdanmaku_ChainRendan((int)(alice.x), (int)(alice.y), 2.5, danmaku.Getkakudo_Homing(alice.x, alice.y, j.x, j.y) + 30, 1, danmaku.dcolor.orange, 0, 20, 4);
						danmaku.Setdanmaku_ChainRendan((int)(alice.x), (int)(alice.y), 2.5, danmaku.Getkakudo_Homing(alice.x, alice.y, j.x, j.y) - 30, 1, danmaku.dcolor.orange, 0, 20, 4);
						break;
					case 61:
						danmaku.Setdanmaku_ArrowRendan((int)(alice.x), (int)(alice.y), danmaku.Getkakudo_Homing(alice.x, alice.y, j.x, j.y), 1, danmaku.dcolor.red, 0, 20, 5, 1.8);
						break;
					case 151:
						danmaku.Setdanmaku_Wave((int)(alice.x), (int)(alice.y), 4, 13, danmaku.dcolor.green, 0, danmaku.Getkakudo_Homing(alice.x, alice.y, j.x, j.y), 30);
						break;
					case 211:
						danmaku.Setdanmaku_Wave((int)(alice.x), (int)(alice.y), 4, 7, danmaku.dcolor.blue, 0, danmaku.Getkakudo_Homing(alice.x, alice.y, j.x, j.y), 40);
						break;
					case 271:
						switch ((int)(alice.x)){
						case 88:
							alice.vecx = 3;
							alice.imgpoji = DotAct.right;
							break;
						case 208:
							if (alice.x < j.x){
								alice.vecx = 3;
								alice.imgpoji = DotAct.right;
							}
							else{
								alice.vecx = -3;
								alice.imgpoji = DotAct.left;
							}
							break;
						case 328:
							alice.vecx = -3;
							alice.imgpoji = DotAct.left;
							break;
						}
						break;
					}
					alice.x += alice.vecx;
					if (alice.vecx != 0 && (alice.x == 88 || alice.x == 208 || alice.x == 328)){
						alice.vecx = 0;
						alice.imgpoji = DotAct.common;
					}
				}
				break;
			case 18://大ボス戦 スペルカード2
				DrawGraph((int)(alice.x - 30), (int)(alice.y - 45), alicedot[alice.imgpoji], true);
				if (Currenttime * 60 + flame < 121){
					appeary += 2;
					if (StartSpellkardEffect(alicestand[1]) != 0){ r = -1; }
					if ((alice.vecx > 0 && alice.x < 208) || (alice.vecx < 0 && alice.x > 208)){
						alice.x += alice.vecx;
					}
					else{
						alice.x = 208;
					}
				}
				else{
					Bosshit = true;
					timetoflame = ((Currenttime - 2) % Looptime) * 60 + flame;
					switch (timetoflame){
					case 1:
						danmaku.Setdanmaku_Ko((int)(alice.x), (int)(alice.y), 2, danmaku.dshu.uroko, danmaku.dcolor.red, 0, 90 - 18, 90 + 18, 7);
						break;
					case 11:
						danmaku.Setdanmaku_Ko((int)(alice.x), (int)(alice.y), 2, danmaku.dshu.uroko, danmaku.dcolor.orange, 0, 114 - 18, 114 + 18, 7);
						break;
					case 21:
						danmaku.Setdanmaku_Ko((int)(alice.x), (int)(alice.y), 2, danmaku.dshu.uroko, danmaku.dcolor.yellow, 0, 138 - 18, 138 + 18, 7);
						break;
					case 31:
						danmaku.Setdanmaku_Ko((int)(alice.x), (int)(alice.y), 2, danmaku.dshu.uroko, danmaku.dcolor.green, 0, 162 - 18, 162 + 18, 7);
						break;
					case 41:
						danmaku.Setdanmaku_Ko((int)(alice.x), (int)(alice.y), 2, danmaku.dshu.uroko, danmaku.dcolor.water, 0, 186 - 18, 186 + 18, 7);
						break;
					case 51:
						danmaku.Setdanmaku_Ko((int)(alice.x), (int)(alice.y), 2, danmaku.dshu.uroko, danmaku.dcolor.blue, 0, 210 - 18, 210 + 18, 7);
						break;
					case 61:
						danmaku.Setdanmaku_Ko((int)(alice.x), (int)(alice.y), 2, danmaku.dshu.uroko, danmaku.dcolor.purple, 0, 234 - 18, 234 + 18, 7);
						break;
					case 71:
						danmaku.Setdanmaku_Ko((int)(alice.x), (int)(alice.y), 2, danmaku.dshu.uroko, danmaku.dcolor.pink, 0, 258 - 18, 258 + 18, 7);
						break;
					case 81:
						danmaku.Setdanmaku_Ko((int)(alice.x), (int)(alice.y), 2, danmaku.dshu.uroko, danmaku.dcolor.pink, 0, 302 - 18, 302 + 18, 7);
						break;
					case 91:
						danmaku.Setdanmaku_Ko((int)(alice.x), (int)(alice.y), 2, danmaku.dshu.uroko, danmaku.dcolor.purple, 0, 326 - 18, 326 + 18, 7);
						break;
					case 101:
						danmaku.Setdanmaku_Ko((int)(alice.x), (int)(alice.y), 2, danmaku.dshu.uroko, danmaku.dcolor.blue, 0, 350 - 18, 350 + 18, 7);
						break;
					case 111:
						danmaku.Setdanmaku_Ko((int)(alice.x), (int)(alice.y), 2, danmaku.dshu.uroko, danmaku.dcolor.water, 0, 374 - 18, 374 + 18, 7);
						break;
					case 121:
						danmaku.Setdanmaku_Ko((int)(alice.x), (int)(alice.y), 2, danmaku.dshu.uroko, danmaku.dcolor.green, 0, 38 - 18, 38 + 18, 7);
						break;
					case 131:
						danmaku.Setdanmaku_Ko((int)(alice.x), (int)(alice.y), 2, danmaku.dshu.uroko, danmaku.dcolor.yellow, 0, 62 - 18, 62 + 18, 7);
						break;
					case 141:
						danmaku.Setdanmaku_Ko((int)(alice.x), (int)(alice.y), 2, danmaku.dshu.uroko, danmaku.dcolor.orange, 0, 84 - 18, 84 + 18, 7);
						break;
					case 151:
						danmaku.Setdanmaku_Ko((int)(alice.x), (int)(alice.y), 2, danmaku.dshu.uroko, danmaku.dcolor.red, 0, 90 - 18, 90 + 18, 7);
						break;
					case 181:
						alice.imgpoji = DotAct.act1;
						danmaku.Setdanmaku_ArrowRendan((int)(alice.x), (int)(alice.y), 345, danmaku.dshu.kome, danmaku.dcolor.red, 0, 24, 8, 1.2);
						break;
					case 186:
						danmaku.Setdanmaku_ArrowRendan((int)(alice.x), (int)(alice.y), 20, danmaku.dshu.kome, danmaku.dcolor.orange, 0, 24, 8, 1.2);
						break;
					case 191:
						danmaku.Setdanmaku_ArrowRendan((int)(alice.x), (int)(alice.y), 55, danmaku.dshu.kome, danmaku.dcolor.yellow, 0, 24, 8, 1.2);
						break;
					case 196:
						danmaku.Setdanmaku_ArrowRendan((int)(alice.x), (int)(alice.y), 90, danmaku.dshu.kome, danmaku.dcolor.green, 0, 24, 8, 1.2);
						break;
					case 201:
						danmaku.Setdanmaku_ArrowRendan((int)(alice.x), (int)(alice.y), 125, danmaku.dshu.kome, danmaku.dcolor.water, 0, 24, 8, 1.2);
						break;
					case 206:
						danmaku.Setdanmaku_ArrowRendan((int)(alice.x), (int)(alice.y), 160, danmaku.dshu.kome, danmaku.dcolor.blue, 0, 24, 8, 1.2);
						break;
					case 211:
						danmaku.Setdanmaku_ArrowRendan((int)(alice.x), (int)(alice.y), 195, danmaku.dshu.kome, danmaku.dcolor.purple, 0, 24, 8, 1.2);
						break;
					case 221:
						alice.imgpoji = DotAct.common;
						danmaku.Setdanmaku_Wave((int)(alice.x), (int)(alice.y), 0.8, danmaku.dshu.large, danmaku.dcolor.pink, 0, danmaku.Getkakudo_Homing(alice.x, alice.y, j.x, j.y), 60);
						break;
					}
				}
				break;
			case 19://大ボス戦終了　爆散
				switch (Talkcount){
					/*

					*/
				case 4:
					EndSpellkardEffect(150000, SpellBonusScore);
					if (PlayerData.jikinum == 0){
						selif1 = "やはりあやつも本調子ではないようだ。";
						selif2 = "";
					}
					else{
						BossStandPosition = -1;
						Shadowflg = 1;
						JikiStandPosition = 2;
						selif1 = "ま、最初の相手としてはまずまずだけど、";
						selif2 = "";
					}
					break;
				case 3:
					if (PlayerData.jikinum == 0){
						selif1 = "今のうちにどうにかしないと。";
					}
					else{
						JikiStandPosition = 2;
						selif1 = "次はコンディションを整えて挑んで";
						selif2 = "くるんだねぇ。";
					}
					break;
				case 2:
					if (PlayerData.jikinum == 0){
						JikiStandPosition = 2;
						selif1 = "幻想郷伝統の異変解決、それに我が追随";
						selif2 = "する時が来たか…。";
					}
					else{
						selif1 = "ではここからは私がイヘンカイケツ";
						selif2 = "をするとしよう。";
					}
					break;
				case 1://ステージリザルト
					if (j.slow > 0){
						TalkSkipCancel = true;
					}
					else{
						TalkSkipCancel = false;
					}
					break;
				}

				if (PlayerData.jikinum == 0){
					jikicolor = GetColor(255, 150, 150);
					bossy = 195;
					jikiy = 225;
				}
				else{
					jikicolor = GetColor(220, 220, 100);
					bossy = 225;
					jikiy = 210;
				}
				if (Talkcount > 1){
					BossTalking(alicestand[BossStandPosition], GetColor(150, 150, 200), jikicolor, 170, bossy, jikiy, 0);
				}
				if (SpellBonusScore != 0 && Talkcount > 1){
					EndSpellkardEffect(150000, SpellBonusScore);
				}
				break;
			default:
				r = -1;
				break;
			}
			if (scene == 14){
				if (PlayerData.jikinum == 0){
					if (Talkcount < 10){
						DrawGraph((int)(alice.x - 30), (int)(alice.y - 45), alicedot[alice.imgpoji], true);
					}
				}
				else{
					if (Talkcount < 7){
						DrawGraph((int)(alice.x - 30), (int)(alice.y - 45), alicedot[alice.imgpoji], true);
					}
				}
			}
		}
		danmaku.ProcessBossDanmaku(flame + Currenttime * 60, scene, PlayerData.jikinum, (int)(j.x), (int)(j.y));
		if (BossTalk == false){ r = DisplayBossStates(alice.hitpoint, alice.phasecount); }
		if (Spell){ DisplaySpellStates(); }
		SetDrawArea(1,1,639,479);
		if((scene == 10 && prescene == 9) || (scene == 20 && prescene == 19)){
			rr = false;//フェーズの進行度に応じてボス戦が終了する。
		}
		if(r != 0){
			r = -1;
		}
		return rr;
	};
	
	BOSU alice;
	BOSU aya;


private:
	int wait[17];//フレーム単位で敵を待機させるときに使われる配列です。
	int vectorchange[6];//敵が移動方向をいくつ変えたかを示す変数です。
	char* SpellkardName[2];
	int SpellkardBonusscore[2];
	int SpellkardClearscore[2];
	static int ayadot[4];
	static int alicedot[4];
	//common,left,right,act1,act2
	static int ayastand[8];//1.common,2.fine,
	static int alicestand[8];//1.common,2.fine
	int targetkakudo;
	int d,scenetime;
	
};
int Stage1::alicestand[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
int Stage1::ayastand[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
int Stage1::alicedot[4] = { 0, 0, 0, 0 };
int Stage1::ayadot[4] = { 0, 0, 0, 0 };


