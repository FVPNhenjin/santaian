#include "Header.h"
#include "th3i.h"
#include <vector>
using namespace std;

class Jiki{
public:
	Stage1 s1;
	Stage2 s2;
	Stage3 s3;
	Stage4 s4;
	Stage5 s5;
	FinalA f6a;
	FinalB f6b;
	//Extra ex;
	Music ongaku;
	
	Controlar ctrl;
#define SHOTLIMIT 400
	Jiki::Jiki(){
		int r;
		char dir[_MAX_PATH];
		GetCurrentDirectory(_MAX_PATH, dir);
		r = _chdir("data");
		r = _chdir("img");
		r = _chdir("Game");
		r = _chdir("Jiki");
		int i, j;
		for (i = 0; i < 4; i++){
			for (j = 0; j < 4; j++){
				dot[i][j] = 0;
				shotdot[i][j] = 0;
			}
		}
		ClearShot();
		sakuyaopkakudo = 0;
		tail = 1;
		dot[0][0] = LoadGraph("Futocommon.bmp");
		dot[1][0] = LoadGraph("Mimacommon.bmp");
		dot[2][0] = LoadGraph("Sanaecommon.bmp");
		dot[3][0] = LoadGraph("Sakuyacommon.bmp");
		dot[0][1] = LoadGraph("Futoleft.bmp");
		dot[1][1] = LoadGraph("Mimaleft.bmp");
		dot[2][1] = LoadGraph("Sanaeleft.bmp");
		dot[3][1] = LoadGraph("Sakuyaleft.bmp");
		dot[0][2] = LoadGraph("Futoright.bmp");
		dot[1][2] = LoadGraph("Mimaright.bmp");
		dot[2][2] = LoadGraph("Sanaeright.bmp");
		dot[3][2] = LoadGraph("Sakuyaright.bmp");
		jikistand[0][1] = LoadGraph("Futo.common.png");
		jikistand[0][2] = LoadGraph("Futo.fine.png");
		jikistand[0][4] = LoadGraph("Futo.doubt.png");
		jikistand[0][6] = LoadGraph("Futo.surprised.png");
		jikistand[0][7] = LoadGraph("Futo.amaged.png");
		jikistand[0][8] = LoadGraph("Futo.excited.png");
		jikistand[0][9] = LoadGraph("Futo.strategy.png");
		jikistand[1][1] = LoadGraph("Mima.common.png");
		jikistand[1][2] = LoadGraph("Mima.fine.png");
		jikistand[1][3] = LoadGraph("Mima.question.png");
		jikistand[1][8] = LoadGraph("Mima.excited.png");
		jikistand[1][9] = LoadGraph("Mima.strategy.png");
		jikistand[2][1] = LoadGraph("Sanae.common.png");
		jikistand[2][2] = LoadGraph("Sanae.fine.png");
		jikistand[2][3] = LoadGraph("Sanae.question.png");
		jikistand[2][6] = LoadGraph("Sanae.surprised.png");
		jikistand[2][9] = LoadGraph("Sanae.strategy.png");
		jikistand[3][1] = LoadGraph("Sakuya.common.png");
		jikistand[3][2] = LoadGraph("Sakuya.fine.png");
		jikistand[3][3] = LoadGraph("Sakuya.question.png");
		jikistand[3][5] = LoadGraph("Sakuya.angry.png");
		jikistand[3][9] = LoadGraph("Sakuya.strategy.png");
		r = _chdir("shot");
		shotdot[0][0] = LoadGraph("Futo_shot1.bmp");//高
		shotdot[0][1] = LoadGraph("Futo_shot2.bmp");//高
		shotdot[0][2] = LoadGraph("Futo_shot3.bmp");//低
		shotdot[0][3] = LoadGraph("Futo_option.bmp");
		futoop2 = LoadGraph("Futo_option2.bmp");
		shotdot[1][0] = LoadGraph("Mima_shot1.bmp");//高
		shotdot[1][1] = LoadGraph("Mima_shot2.bmp");//高
		shotdot[1][2] = LoadGraph("Mima_shot3.bmp");//低
		shotdot[1][4] = LoadGraph("Mima_shot4.bmp");//低
		shotdot[1][3] = LoadGraph("Mima_option.bmp");
		shotdot[2][0] = LoadGraph("Sanae_shot1.bmp");//低・高
		shotdot[2][1] = LoadGraph("Sanae_shot2.bmp");//低・高
		shotdot[2][2] = LoadGraph("Sanae_shot3.bmp");//低・高
		shotdot[2][3] = LoadGraph("Sanae_option.bmp");
		shotdot[3][0] = LoadGraph("Sakuya_shot1.bmp");//低・高
		shotdot[3][1] = LoadGraph("Sakuya_shot2.bmp");//低・高
		shotdot[3][3] = LoadGraph("Sakuya_option.bmp");
		r = _chdir("..");
		r = _chdir("..");
		r = _chdir("..");
		r = _chdir("..");
		r = _chdir("..");
		RefreshStop = false;
		doublebuttle = false;
		Init();
	}
	void Jiki::Init(){
		s1.Init();
		s2.Input_Address(&s1);
		s3.Input_Address(&s1);
		s4.Input_Address(&s1);
		//s5.Input_Address(&s1);
		//f6a.Input_Address(&s1);
		//f6b.Input_Address(&s1);
		//ex.Input_Address(&s1);
		s1.danmaku.CreateDanmakuGraph();
		s2.danmaku.Input_Address(&s1.danmaku);
		s3.danmaku.Input_Address(&s1.danmaku);
		s4.danmaku.Input_Address(&s1.danmaku);
		//s5.danmaku.Input_Address(&s1.danmaku);
		//f6a.danmaku.Input_Address(&s1.danmaku);
		//f6b.danmaku.Input_Address(&s1.danmaku);
		//ex.danmaku.Input_Address(&s1.danmaku);
		s1.eff.Init();
		s2.eff.Input_Address(&s1.eff);
		s3.eff.Input_Address(&s1.eff);
		s4.eff.Input_Address(&s1.eff);
		//s5.eff.Input_Address(&s1.eff);
		//f6a.eff.Input_Address(&s1.eff);
		//f6b.eff.Input_Address(&s1.eff);
		//ex.eff.Input_Address(&s1.eff);
		s1.danmaku.eff.Input_Address(&s1.eff);
		s2.danmaku.eff.Input_Address(&s1.eff);
		s3.danmaku.eff.Input_Address(&s1.eff);
		s4.danmaku.eff.Input_Address(&s1.eff);
		//s5.danmaku.eff.Input_Address(&s1.eff);
		//f6a.danmaku.eff.Input_Address(&s1.eff);
		//f6b.danmaku.eff.Input_Address(&s1.eff);
		//ex.danmaku.eff.Input_Address(&s1.eff);
	}
	void Jiki::ClearShot(){
		int p;
		for (p = 0; p < SHOTLIMIT; p++){
			shot[p].x = 0.0;
			shot[p].y = 0.0;
			shot[p].vecx = 0.0;
			shot[p].vecy = 0.0;
			shot[p].power = 0.0;
			shot[p].flamebetween = 0;
			shot[p].imgangle = 0;
			shot[p].imggapp = 0;
			shot[p].imgp = 0;
			shot[p].np = 0;
			shot[p].pp = 0;
			shott[p].homingx = 0.0;
			shott[p].homingy = 0.0;
			shott[p].homingp = 0;
			shott[p].sethoming = false;
			shott[p].slow = false;
			shott[p].changed = 0;
			shott[p].beamed = false;
			shott[p].slowcancel = false;
			shott[p].hit = false;
		}
		shotcount = 0;
		shot[0].np = 1;
		tail = 1;
	}
	void Jiki::LoadShot(){
		int r;
		r = _chdir("data");
		r = _chdir("Stage");
		int file = FileRead_open("shotdata.txt");
		int endf, f;
		int j, p, sh, prep;
		char* ctx = "";
		int prej = 0;
		prep = 1;
		TCHAR data[70];
		endf = 0;
		while (endf == 0){
			f = FileRead_gets(data, 70, file);
			if (FileRead_eof(file) != 0){ endf = 100; }
			j = atoi(strtok_s(data, ",", &ctx));
			p = atoi(strtok_s(NULL, ",", &ctx));
			if (prep != p || prej != j){
				if (prej != j){
					shotdata[prej][prep][0].x = sh;
				}
				else{
					shotdata[j][prep][0].x = sh;
				}
			}
			prej = j;
			prep = p;
			sh = atoi(strtok_s(NULL, ",", &ctx));
			shotdata[j][p][sh].x = atof(strtok_s(NULL, ",", &ctx));
			shotdata[j][p][sh].y = atof(strtok_s(NULL, ",", &ctx));
			shotdata[j][p][sh].vecx = atof(strtok_s(NULL, ",", &ctx));
			shotdata[j][p][sh].vecy = atof(strtok_s(NULL, ",", &ctx));
			shotdata[j][p][sh].power = atof(strtok_s(NULL, ",", &ctx));
			shotdata[j][p][sh].imgp = shotdot[jikinum][atoi(strtok_s(NULL, ",", &ctx))];
			shotdata[j][p][sh].imggapp = atoi(strtok_s(NULL, ",", &ctx));
			shotdata[j][p][sh].imgangle = atoi(strtok_s(NULL, ",", &ctx));
			shotdata[j][p][sh].flamebetween = atoi(strtok_s(NULL, ",", &ctx));
			shotdata[j][p][sh].shotbetween = atoi(strtok_s(NULL, ",", &ctx));
		}
		shotdata[j][prep][0].x = sh;
		f = FileRead_close(file);
		r = _chdir("..");
		r = _chdir("..");
	}
	int Jiki::ProcessJiki(int flame, bool talk){
		int r = 0;
		ctrl.GetCondition();
		int d, dy, op;
		double sl, opx, opy;
		int keepgraze = grazecount;
		d = 0;
		op = 0;
		dy = 0;//初期値はcommon

		if (ctrl.GetButton("slow") > 0){
			j.slow = true;
			switch (jikinum){//低速移動時に補正
			case 0:
				sl = 0.7;
				break;
			case 1:
				sl = 0.4;
				break;
			case 2:
				sl = 0.6;
				break;
			case 3:
				sl = 0.5;
				break;
			}
		}
		else{
			sl = 1;//高速移動時は補正なし
			j.slow = false;
		}
		if (ctrl.GetButton("left") > 0){
			j.x = (int)(j.x - (j.vecx * sl));
			dy = 1;
		}
		if (ctrl.GetButton("right") > 0){
			j.x = (int)(j.x + (j.vecx * sl));
			dy = 2;
		}
		if (ctrl.GetButton("up") > 0){
			j.y = (int)(j.y - (j.vecy * sl));
		}
		if (ctrl.GetButton("down") > 0){
			j.y = (int)(j.y + (j.vecy * sl));
		}
		if (j.x < 40){ j.x = 40; }
		if (j.x > 386){ j.x = 386; }
		if (j.y < 33){ j.y = 33; }
		if (j.y > 445){ j.y = 445; }

		d = dot[jikinum][dy];//画像配置
		if (jikinum == 0 && j.slow == true){
			op = futoop2;
		}
		else{
			op = shotdot[jikinum][3];
		}
		if (ctrl.GetButton("ok_shot") > 0 && talk == false){
			SetShot(flame);
		}
		if (jikinum == 3 && j.slow == false && slowkakudo != 75){
			int migi = 0;
			int hidari = 0;
			hidari = ctrl.GetButton("left");
			migi = ctrl.GetButton("right");
			if (hidari > 0){
				sakuyaopkakudo -= 3;
			}
			else{
				if (migi > 0){
					sakuyaopkakudo += 3;
				}
				else{
					if (sakuyaopkakudo != 0){
						if (sakuyaopkakudo > 0){
							sakuyaopkakudo -= 3;
						}
						else{
							sakuyaopkakudo += 3;
						}
					}
				}
			}
			if (sakuyaopkakudo < 3 && sakuyaopkakudo > -3){ sakuyaopkakudo = 0; }
			if (sakuyaopkakudo > 45){ sakuyaopkakudo = 45; }
			if (sakuyaopkakudo < -45){ sakuyaopkakudo = -45; }
		}
		if (shotcount > 0){
			if (flame % 20 == 0){ ShotRefresh(); }
			if (ProcessShot(flame) != 0){ r = -1; }
		}
		opx = 25;//～10
		opy = 0;//～-20
		if (jikinum == 3){
			double x, y, opx2, opx3, opy2, opy3;

			if (j.slow == true){
				//低速ボタンの押し時間に応じてオプションを前面に出す。
				int s = ctrl.GetButton("slow");
				if (s < 3){
					slowkakudo = 15;
				}
				else{
					if (s < 5){
						slowkakudo = 27;
					}
					else{
						if (s < 7){
							slowkakudo = 39;
						}
						else{
							if (s < 9){
								slowkakudo = 51;
							}
							else{
								if (s < 11){
									slowkakudo = 63;
								}
								else{
									slowkakudo = 75;
								}
							}
						}
					}
				}
				x = opx * cos(slowkakudo * PI / 180) - opy * sin(slowkakudo * PI / 180);
				y = opx * sin(slowkakudo * PI / 180) + opy * cos(slowkakudo * PI / 180);
				opx2 = j.x - x * cos(sakuyaopkakudo * PI / 180) + y * sin(sakuyaopkakudo * PI / 180);
				opy2 = j.y - x * sin(sakuyaopkakudo * PI / 180) - y * cos(sakuyaopkakudo * PI / 180);
				opx3 = j.x + x * cos(sakuyaopkakudo * PI / 180) + y * sin(sakuyaopkakudo * PI / 180);
				opy3 = j.y + x * sin(sakuyaopkakudo * PI / 180) - y * cos(sakuyaopkakudo * PI / 180);
				if (DrawGraph(j.x - 12, j.y - 20, d, true) != 0 || DrawRotaGraph((int)(opx2), (int)(opy2), 1.0, sakuyaopkakudo * PI / 180, op, true, 0) != 0 || DrawRotaGraph((int)(opx3), (int)(opy3), 1.0, sakuyaopkakudo * PI / 180, op, true, 0) != 0){ r = -1; }
			}
			else{
				if (slowkakudo != 0){
					//低速移動時に前出させたオプションは段階を経て元の位置に戻す。
					if (slowkakudo == 15){
						slowkakudo = 0;
					}
					else{
						slowkakudo -= 12;
					}
					x = opx * cos(slowkakudo * PI / 180) - opy * sin(slowkakudo * PI / 180);
					y = opx * sin(slowkakudo * PI / 180) + opy * cos(slowkakudo * PI / 180);
					opx2 = j.x - x * cos(sakuyaopkakudo * PI / 180) + y * sin(sakuyaopkakudo * PI / 180);
					opy2 = j.y - x * sin(sakuyaopkakudo * PI / 180) - y * cos(sakuyaopkakudo * PI / 180);
					opx3 = j.x + x * cos(sakuyaopkakudo * PI / 180) + y * sin(sakuyaopkakudo * PI / 180);
					opy3 = j.y + x * sin(sakuyaopkakudo * PI / 180) - y * cos(sakuyaopkakudo * PI / 180);
					if (DrawGraph(j.x - 12, j.y - 20, d, true) != 0 || DrawRotaGraph((int)(opx2), (int)(opy2), 1.0, sakuyaopkakudo * PI / 180, op, true, 0) != 0 || DrawRotaGraph((int)(opx3), (int)(opy3), 1.0, sakuyaopkakudo * PI / 180, op, true, 0) != 0){ r = -1; }
				}
				else{
					//低速移動でもオプションを前出させてもない場合はオプションの傾きに応じて描画する。
					opx2 = opx * cos(sakuyaopkakudo * PI / 180) + opy * -1 * sin(sakuyaopkakudo * PI / 180);
					opy2 = opx * sin(sakuyaopkakudo * PI / 180) + opy * cos(sakuyaopkakudo * PI / 180);
					if (DrawGraph(j.x - 12, j.y - 20, d, true) != 0 || DrawRotaGraph((int)(j.x + opx2), (int)(j.y + opy2), 1.0, sakuyaopkakudo * PI / 180, op, true, 0) != 0 || DrawRotaGraph((int)(j.x - opx2), (int)(j.y - opy2), 1.0, sakuyaopkakudo * PI / 180, op, true, 0) != 0){ r = -1; }
				}

			}

		}
		else{
			//咲夜以外の自機のオプション位置は固定
			if (DrawGraph(j.x - 12, j.y - 20, d, true) != 0 || DrawGraph((int)(j.x - opx - 7), (int)(j.y + opy - 7), op, true) != 0 || DrawGraph((int)(j.x + opx - 7), (int)(j.y + opy - 7), op, true) != 0){ r = -1; }
		}
		grazecount = keepgraze;
		if (r == -1){
			r = -1;
		}

		return r;
	}
	void Jiki::InputName(bool practice){
		sakuyaopkakudo = 0;
		slowkakudo = 0;
		j.x = 212;
		j.y = 410;
		j.bombcount = 2;
		j.extendcount = 2;
		if (practice){
			j.power = 128;
			j.powercount = 5;
		}
		else{
			if (Data.currentstage == 1){
				j.power = 0;
				j.powercount = 1;
			}
		}
		j.slow = false;
		if (Data.partner == "Futo"){
			j.hitr = 2;
			j.vecx = 4;
			j.vecy = 4;
			jikinum = 0;
		}
		else{
			j.hitr = 3;
		}
		if (Data.partner == "Mima"){
			j.vecx = 6.5;
			j.vecy = 6.5;
			jikinum = 1;
			j.itemr = 35;
		}
		else{
			j.itemr = 30;
		}
		if (Data.partner == "Sanae"){
			j.vecx = 5;
			j.vecy = 5;
			jikinum = 2;
			j.grazer = 25;
		}
		else{
			j.grazer = 20;
		}
		if (Data.partner == "Sakuya"){
			j.vecx = 5.5;
			j.vecy = 5.5;
			jikinum = 3;
		}

	}
	void Jiki::SetShot(int flame){
		int shotkazu, shotsu, p, preshotcount;
		shotsu = 0;
		if (shotcount == 0 && tail == 0){
			//一発目の弾幕はshot[0].npに配置
			p = shot[0].np;
		}
		else{
			//それ以外はtailに配置
			p = tail;
		}
		if (p == 0){
			p = 0;
		}

		if (j.slow && jikinum != 3){
			jikinum += 4;
		}
		preshotcount = shotcount;
		shotkazu = (int)(shotdata[jikinum][j.powercount][0].x);
		if (shotcount + shotkazu > SHOTLIMIT){
			ShotRefresh();
		}
		while (shotkazu != 0){
			if (/*(*/flame % shotdata[jikinum][j.powercount][shotkazu].shotbetween == 0/* || (flame + 1) % shotdata[jikinum][j.powercount][shotkazu].shotbetween == 0)*/){
				shot[p].imggapp = shotdata[jikinum][j.powercount][shotkazu].imggapp;
				shot[p].imgp = shotdata[jikinum][j.powercount][shotkazu].imgp;
				if (shot[p].imgp == shotdot[3][1] && (slowkakudo != 0 || sakuyaopkakudo != 0)){
					double x, y;
					x = shotdata[jikinum][j.powercount][shotkazu].x * cos(slowkakudo * PI / 180) - shotdata[jikinum][j.powercount][shotkazu].y * sin(slowkakudo * PI / 180);
					y = shotdata[jikinum][j.powercount][shotkazu].x * sin(slowkakudo * PI / 180) + shotdata[jikinum][j.powercount][shotkazu].y * cos(slowkakudo * PI / 180);
					if (shotdata[jikinum][j.powercount][shotkazu].x > 0){
						shot[p].x = j.x + x * cos(sakuyaopkakudo * PI / 180) + y * sin(sakuyaopkakudo * PI / 180);
						shot[p].y = j.y + x * sin(sakuyaopkakudo * PI / 180) - y * cos(sakuyaopkakudo * PI / 180);
					}
					else{
						shot[p].x = j.x + x * cos(sakuyaopkakudo * PI / 180) - y * sin(sakuyaopkakudo * PI / 180);
						if (sakuyaopkakudo < 0){
							shot[p].y = j.y - y * sin(sakuyaopkakudo * PI / 180) - y * cos(sakuyaopkakudo * PI / 180);
						}
						else{
							shot[p].y = j.y + y * sin(sakuyaopkakudo * PI / 180) + y * cos(sakuyaopkakudo * PI / 180);
						}
					}
					if (sakuyaopkakudo != 0){
						shot[p].vecy = shotdata[jikinum][j.powercount][shotkazu].vecx * sin(sakuyaopkakudo * PI / 180) * -1 + shotdata[jikinum][j.powercount][shotkazu].vecy * cos(sakuyaopkakudo * PI / 180);
						shot[p].vecx = shotdata[jikinum][j.powercount][shotkazu].vecx * cos(sakuyaopkakudo * PI / 180) * -1 - shotdata[jikinum][j.powercount][shotkazu].vecy * sin(sakuyaopkakudo * PI / 180);
						shot[p].imgangle = (int)(atan2(shot[p].vecx, shot[p].vecy * -1) * 180 / PI);
					}
					else{
						shot[p].vecx = shotdata[jikinum][j.powercount][shotkazu].vecx;
						shot[p].vecy = shotdata[jikinum][j.powercount][shotkazu].vecy;
						shot[p].imgangle = shotdata[jikinum][j.powercount][shotkazu].imgangle;
					}
				}
				else{
					shot[p].x = j.x + shotdata[jikinum][j.powercount][shotkazu].x;
					shot[p].y = j.y + shotdata[jikinum][j.powercount][shotkazu].y;
					shot[p].vecx = shotdata[jikinum][j.powercount][shotkazu].vecx;
					shot[p].vecy = shotdata[jikinum][j.powercount][shotkazu].vecy;
					shot[p].imgangle = shotdata[jikinum][j.powercount][shotkazu].imgangle;
				}
				shot[p].flamebetween = shotdata[jikinum][j.powercount][shotkazu].flamebetween;
				shot[p].power = shotdata[jikinum][j.powercount][shotkazu].power;
				if (shot[p].imgp == shotdot[2][2] && j.slow && ((shotdata[jikinum][j.powercount][shotkazu].x > 0 && shotdata[jikinum][j.powercount][shotkazu].vecx < 0) || (shotdata[jikinum][j.powercount][shotkazu].x < 0 && shotdata[jikinum][j.powercount][shotkazu].vecx > 0))){
					shott[p].changed = 0;
					shott[p].slow = true;
				}
				shot[p].pp = p - 1;
				shot[p].np = p + 1;
				shotsu++;
				shotcount++;
				p++;
			}
			shotkazu--;
		}
		tail += shotsu;
		AddScore(1);
		if (jikinum > 3){
			jikinum -= 4;
		}

	}
	int Jiki::ProcessShot(int flame){
		int p = shot[0].np;
		int r = 0;
		while (p != tail && r == 0 && shotcount > 0){
			if (shot[p].imgp == shotdot[1][2]){
				if (j.slow == false || ctrl.GetButton("ok_shot") == 0){ shott[p].slowcancel = true; }
				if (shott[p].slowcancel == false){
					shot[p].x = j.x;
				}
				/*
				if (j.slow && ctrl.GetButton("slow") % 360 == 0){
				ClearShot();
				ctrl.SetButtonInit();
				break;n
				}*/
			}


			if (shot[p].imgp == shotdot[1][4] && j.slow && j.powercount > 2){//パワーカウントが第三段階以上でかつ低速移動中で影ビームの処理時
				if (ctrl.GetButton("left") == 0 && ctrl.GetButton("right") == 0){
					//スライド移動していない時は残留ビームは発生しない
					if (shott[p].beamed){
						Deleteshot(p);
					}

				}
				else{//スライド移動中								 
					//第三段階以降はすべての赤ビームから残留する。
					if ((ctrl.GetButton("left") % 13 == 0 || ctrl.GetButton("right") % 13 == 0) && shott[p].beamed == false && ctrl.GetButton("slow") > 240 && ctrl.GetButton("ok_shot") > 240 && ((int)(j.x - shot[p].x) % 16 == 0 || (int)(j.x - shot[p].x - 1) % 17 == 0) && shotcount < 494){
						int beam = tail;
						double by = j.y - 60;
						while (by > 15){
							shot[beam].x = j.x;
							shot[beam].y = by;
							shot[beam].vecx = shot[p].vecx;
							shot[beam].vecy = shot[p].vecy;
							shot[beam].imgp = shot[p].imgp;
							shot[beam].imgangle = shot[p].imgangle;
							shot[beam].imggapp = shot[p].imggapp;
							shot[beam].power = shot[p].power;
							shot[beam].flamebetween = shot[p].flamebetween;
							shot[beam].pp = beam - 1;
							shott[beam].beamed = true;
							shot[beam].np = beam + 1;
							beam++;
							by -= 60;
							shotcount++;
						}
						tail = beam;
						Deleteshot(p);
					}
				}
				preleft = ctrl.GetButton("left");
				preright = ctrl.GetButton("right");
				if (ctrl.GetButton("ok_shot") == 0){
					Deleteshot(p);
				}

			}
			if (shot[p].imgp == shotdot[1][4] && j.powercount != 2 && shott[p].beamed){
				if (abs((int)(j.x - shot[p].x)) > 60){
					Deleteshot(p);
				}
			}
			shot[p].x += shot[p].vecx;
			shot[p].y += shot[p].vecy;
			if (shot[p].x + shot[p].imggapp < 20 || shot[p].y + shot[p].imggapp < 0 || shot[p].x - shot[p].imggapp > 404 || shot[p].y - shot[p].imggapp > 465){
				//画面から完全にはみ出したら消去
				Deleteshot(p);
			}
			else{
				if (shot[p].imgp == shotdot[2][2]){//低速時はX軸の移動方向が変わる。また貼り付け位置が特殊。
					if (shott[p].slow){
						if (shott[p].changed == 15){
							shot[p].vecx *= -1;
							shott[p].changed = 0;
							if (shot[p].vecx > 0){
								shot[p].imgangle = 150;
							}
							else{
								shot[p].imgangle = 390;
							}
						}
						else{
							shott[p].changed++;
						}
						shot[p].x += shot[p].vecx;
						shot[p].y += shot[p].vecy;

					}
					if (j.slow == false){
						shott[p].slow = false;
					}

					if (DrawRotaGraph((int)(shot[p].x - shot[p].imggapp), (int)(shot[p].y), 1.0, (shot[p].imgangle - 90) * PI / 180, shot[p].imgp, true, 0) != 0){
						r = -1;
					}
				}
				else{
					if (shot[p].imgp == shotdot[2][1]){//上記同様貼り付け位置が特殊なため。
						if (DrawRotaGraph((int)(shot[p].x - shot[p].imggapp), (int)(shot[p].y), 1.0, (shot[p].imgangle) * PI / 180, shot[p].imgp, true, 0) != 0){
							r = -1;
						}
					}
					else{
						if (DrawRotaGraph((int)(shot[p].x - shot[p].imggapp), (int)(shot[p].y - shot[p].imggapp), 1.0, shot[p].imgangle * PI / 180, shot[p].imgp, true, 0) != 0){
							r = -1;
						}
					}
				}
			}
			p = shot[p].np;
		}
		if (r == -1){
			r = -1;
		}
		return r;
	}
	void Jiki::Deleteshot(int p){
		shot[shot[p].pp].np = shot[p].np;
		shot[shot[p].np].pp = shot[p].pp;
		shotcount--;
	}
	void Jiki::ShotRefresh(){
		double refdouble[SHOTLIMIT][8];
		int refint[SHOTLIMIT][7];
		bool refbool[SHOTLIMIT][6];
		int p, pp, endf;
		p = 1;
		pp = shot[0].np;
		while (pp != tail && p < SHOTLIMIT){
			refdouble[p][1] = shot[pp].x;
			refdouble[p][2] = shot[pp].y;
			refdouble[p][3] = shot[pp].vecx;
			refdouble[p][4] = shot[pp].vecy;
			refdouble[p][5] = shot[pp].power;
			refdouble[p][6] = shott[pp].homingx;
			refdouble[p][7] = shott[pp].homingy;
			refint[p][1] = shot[pp].imgangle;
			refint[p][2] = shot[pp].imgp;
			refint[p][3] = shot[pp].imggapp;
			refint[p][4] = shot[pp].flamebetween;
			refint[p][5] = shott[pp].homingp;
			refint[p][6] = shott[pp].changed;
			refbool[p][1] = shott[pp].sethoming;
			refbool[p][2] = shott[pp].slow;
			refbool[p][3] = shott[pp].slowcancel;
			refbool[p][4] = shott[pp].beamed;
			refbool[p][5] = shott[pp].whichset;
			p++;
			pp = shot[pp].np;
		}
		ClearShot();
		if (p != 1){
			shotcount = p - 1;
			endf = 0;
			tail = p;
			pp = 1;
		}
		else{
			endf = 100;
			tail = 1;
		}
		while (endf == 0){
			shot[pp].x = refdouble[pp][1];
			shot[pp].y = refdouble[pp][2];
			shot[pp].vecx = refdouble[pp][3];
			shot[pp].vecy = refdouble[pp][4];
			shot[pp].power = refdouble[pp][5];
			shott[pp].homingx = refdouble[pp][6];
			shott[pp].homingy = refdouble[pp][7];
			shot[pp].imgangle = refint[pp][1];
			shot[pp].imgp = refint[pp][2];
			shot[pp].imggapp = refint[pp][3];
			shot[pp].flamebetween = refint[pp][4];
			shott[pp].homingp = refint[pp][5];
			shott[pp].changed = refint[pp][6];
			shott[pp].sethoming = refbool[pp][1];
			shott[pp].slow = refbool[pp][2];
			shott[pp].slowcancel = refbool[pp][3];
			shott[pp].beamed = refbool[pp][4];
			shott[pp].whichset = refbool[pp][5];
			shot[pp].pp = pp - 1;
			shot[pp].np = pp + 1;
			pp++;
			if (pp == tail){ endf = 100; }
		}
	}
	void Jiki::ClearStates(){
		int p;
		for (p = 0; p < 10; p++){
			totalscore[p] = 0;
		}
		totalgraze = 0;
		ClearCount();
		LoadStates();
	}
	void ClearCount(){
		int p;
		for (p = 0; p < 10; p++){
			countscore[p] = 0;
		}
		grazecount = 0;
	}
	void NextStage(){//ストーリーモードにおいてスコアとグレーズ数を引き継ぐとともに初期化します。
		for (int s = 0; s < 10; s++){
			totalscore[s] += countscore[s];
			if (totalscore[s] > 9){
				totalscore[s + 1] += totalscore[s] / 10;
				totalscore[s] = (int)(totalscore[s] % 10);
			}
		}
		//totalgraze += grazecount;
		ClearCount();
	}
	int Jiki::DisplayStates(int ten){
		int r = 0;
		SetDrawArea(1, 1, 639, 479);
		int dx, ex, bm, c;
		if (DrawString(450, 200, "ボム数", GetColor(200, 200, 40), GetColor(180, 40, 40)) != 0 || DrawString(450, 180, "残機", GetColor(200, 200, 40), GetColor(180, 40, 40)) != 0 || DrawString(450, 150, "Score", GetColor(200, 200, 40), GetColor(180, 40, 40)) != 0 || DrawString(450, 250, "Graze", GetColor(200, 200, 40), GetColor(180, 40, 40)) != 0 || DrawString(450, 300, "Power", GetColor(200, 200, 40), GetColor(180, 40, 40)) != 0){
			r = -1;
		}
		if (j.power == 128){
			c = GetColor(240, 240, 100);
		}
		else{
			c = GetColor(255, 255, 255);
		}
		if (DrawFormatString(500, 300, c, "%d/128", j.power) != 0){ r = -1; }
		dx = 500;
		int extendcount = j.extendcount;
		int bombcount = j.bombcount;
		while (dx < 611){
			if (extendcount> 0){
				ex = 0;
				extendcount--;
			}
			else{
				ex = 1;
			}
			if (bombcount > 0){
				bm = 0;
				bombcount--;
			}
			else{
				bm = 1;
			}
			if (DrawGraph(dx, 180, zankiicon[ex], false) != 0 || DrawGraph(dx, 200, bombicon[bm], false) != 0){
				r = -1;
			}
			dx += 11;
		}
		dx = 617;
		c = 0;
		int d;
		/*while(dx < 630){
		d = countscore[p] + totalscore[p] + c;
		if (d > 9){
		c = 1;
		d -= 10;
		}
		if(DrawGraph(dx,150,num[d],false) != 0){
		dx = 1000;
		r = -1;
		}
		p--;
		dx += 13;
		}*/
		for (int p = 0; p < 10; p++){
			d = countscore[p] + totalscore[p] + c;
			if (p == 10){
				p = 10;
			}
			if (d > 9){
				c = d / 10;
				d = (int)(d % 10);
			}
			else{
				c = 0;
			}
			if (DrawGraph(dx, 150, num[d], false) != 0){
				dx = 1000;
				r = -1;
			}
			dx -= 13;
		}
		int goukeigraze = grazecount + totalgraze;
		if (DrawFormatString(500, 250, GetColor(255, 255, 255), "%d", goukeigraze) != 0){
			r = -1;
		}
		if (DrawFormatString(450, 350, GetColor(100, 100, 225), "点　%d", ten) != 0){
			r = -1;
		}
		if (r == -1){
			r = -1;
		}
		return r;
	}
	void Jiki::DisplayStageResult(int ClearBonus, int GrazeBonus){//ステージ中に稼いだスコアとグレーズを表示します。
		int StageClearFont = CreateFontToHandle(NULL, 36, 5, DX_FONTTYPE_EDGE);
		DrawStringToHandle(80, 40, "Stage Clear!!", GetColor(255, 100, 100), StageClearFont, GetColor(100, 100, 100), false);
		int stagescore = 0;
		for (int p = 0; p < 10; p++){
			stagescore += (totalscore[p] + countscore[p]) * (int)(pow(10.0, p));
		}
		stagescore -= ClearBonus + grazecount * GrazeBonus;
		DrawFormatString(60, 100, GetColor(255, 255, 255), "StageClearBonus     = %10d", ClearBonus);
		DrawFormatString(60, 125, GetColor(255, 255, 255), "StageScore          = %10d", stagescore);
		DrawFormatString(60, 150, GetColor(255, 255, 255), "Graze %4d * %4d   = %10d", grazecount, GrazeBonus, grazecount * GrazeBonus);
		DrawFormatString(60, 175, GetColor(255, 255, 255), "―――――――――――――――――");
		stagescore += grazecount * GrazeBonus + ClearBonus;
		DrawFormatString(60, 200, GetColor(255, 255, 255), "Total               = %10d", stagescore);
		DeleteFontToHandle(StageClearFont);
	}
	void Jiki::LoadStates(){
		int r;
		r = _chdir("data");
		r = _chdir("img");
		r = _chdir("Game");
		r = _chdir("States");
		bombicon[0] = LoadGraph("bomb.bmp");
		bombicon[1] = LoadGraph("bomb_empty.bmp");
		zankiicon[0] = LoadGraph("zanki.bmp");
		zankiicon[1] = LoadGraph("zanki_empty.bmp");
		num[0] = LoadGraph("Num_0.bmp");
		num[1] = LoadGraph("Num_1.bmp");
		num[2] = LoadGraph("Num_2.bmp");
		num[3] = LoadGraph("Num_3.bmp");
		num[4] = LoadGraph("Num_4.bmp");
		num[5] = LoadGraph("Num_5.bmp");
		num[6] = LoadGraph("Num_6.bmp");
		num[7] = LoadGraph("Num_7.bmp");
		num[8] = LoadGraph("Num_8.bmp");
		num[9] = LoadGraph("Num_9.bmp");
		r = _chdir("..");
		r = _chdir("..");
		r = _chdir("..");
		r = _chdir("..");

	}
	void Jiki::AddScore(int score){
		int p, s, d;
		int keepgraze = grazecount;
		p = 0;
		s = score;
		d = 0;
		if (score > 10000){
			d = 0;
		}
		while (s > 0 && p < 11){

			d = s % 10;
			countscore[p] += d;
			s = (int)(s / 10);
			p++;
		}
		for (p = 0; p < 11; p++){
			if (countscore[p] > 9){
				countscore[p + 1] += countscore[p] / 10;
				countscore[p] = (int)(countscore[p] % 10);
			}
		}
		grazecount = keepgraze;
	}
	void Jiki::AddGraze(int graze){
		if (graze > 0){
			grazecount += graze;
		}
	}

	int Jiki::ProcessGame(int flamecount){
		int r = 0;
		int cr;
		Stage *stage = 0;
		Danmaku *danmaku = 0;
		if (Data.currentstage == 0){
			//Practice Mode
			cr = Data.choicestage;
			r = 2;
		}
		else{
			//Game Mode
			cr = Data.currentstage;
			r = 1;
		}
		switch (cr){
		case 1://Stage1
			stage = &s1;
			danmaku = &s1.danmaku;
			cr = s1.ProcessStage(flamecount, j.powercount);
			if (stage->PasteHolizon(flamecount + stage->s * 60) != 0){
				r = -1;
			}

			if (s1.scene == 2 && s1.Currenttime < 4){//BGM名を下段に表示
				ongaku.DisplayMusicName(1, s1.Currenttime * 60 + flamecount);
			}
			if (s1.scene == 15 && s1.Currenttime < 4){//BGM名を下段に表示
				ongaku.DisplayMusicName(2, s1.Currenttime * 60 + flamecount);
			}
			
			if (cr == 2){
				if (Data.currentstage != 0){
					Data.currentstage++;
					if (StageStart(cr) != 0){
						r = -1;
					}
				}
				else{
					cr = 100;
				}
			}
			break;
		case 2://Stage2
			stage = &s2;
			danmaku = &s2.danmaku;
			cr = s2.ProcessStage(flamecount, j.powercount);
			if (stage->PasteHolizon(flamecount + stage->s * 60) != 0){
				r = -1;
			}

			if (s2.scene == 5 && s2.Currenttime < 4){//BGM名を下段に表示
				ongaku.DisplayMusicName(3, s2.Currenttime * 60 + flamecount);
			}
			if (s2.scene == 16 && s2.Currenttime < 4){//BGM名を下段に表示
				ongaku.DisplayMusicName(4, s2.Currenttime * 60 + flamecount);
			}
			
			if (cr == 3){
				if (Data.currentstage != 0){
					Data.currentstage++;
					if (StageStart(cr) != 0){
						r = -1;
					}
				}
				else{
					cr = 100;
				}
			}
			break;
		case 3://Stage3
			stage = &s3;
			danmaku = &s3.danmaku;
			cr = s3.ProcessStage(flamecount, j.powercount);
			if (stage->PasteHolizon(flamecount + stage->s * 60) != 0){
				r = -1;
			}

			if (s3.scene == 1 && s3.Currenttime < 4){//BGM名を下段に表示
				ongaku.DisplayMusicName(5, s3.Currenttime * 60 + flamecount);
			}
			if (s3.scene == 20 && s3.Currenttime < 4){//BGM名を下段に表示
				ongaku.DisplayMusicName(6, s3.Currenttime * 60 + flamecount);
			}
			RefreshStop = false;
			
			if (cr == 4){
				if (Data.currentstage != 0){
					Data.currentstage++;
					if (StageStart(cr) != 0){
						r = -1;
					}
				}
				else{
					cr = 100;
				}
			}
			break;
		case 4://Stage4
			stage = &s4;
			danmaku = &s4.danmaku;
			cr = s4.ProcessStage(flamecount, j.powercount);
			if (stage->PasteHolizon(flamecount + stage->s * 60) != 0){
				r = -1;
			}

			if (s4.scene == 2 && s4.Currenttime < 4){//BGM名を下段に表示
				ongaku.DisplayMusicName(7, s4.Currenttime * 60 + flamecount);
			}
			if (s4.scene == 16 && s4.Currenttime < 4){//BGM名を下段に表示
				ongaku.DisplayMusicName(8, s4.Currenttime * 60 + flamecount);
			}
			if (s4.scene == 21 && s4.Currenttime < 4){//BGM名を下段に表示
				if (s4.lastbuttle == 1){
					ongaku.DisplayMusicName(9, s4.Currenttime * 60 + flamecount);
				}
				else{
					ongaku.DisplayMusicName(10, s4.Currenttime * 60 + flamecount);
				}
			}
			
			if (cr == 5){
				if (Data.currentstage != 0){
					Data.currentstage++;
					if (s4.lastbuttle == 1 || Data.currentstage == 0){
						s5.last4boss = true;//プラクティスモードの時は問答無用で明子パターンの会話になる。
					}
					else{
						s5.last4boss = false;
					}
					if (StageStart(cr) != 0){
						r = -1;
					}
				}
				else{
					cr = 100;
				}
			}
			break;
		case 5://Stage5
			
			stage = &s5;
			danmaku = &s5.danmaku;
			cr = s5.ProcessStage(flamecount, j.powercount);
			if (stage->PasteHolizon(flamecount + stage->s * 60) != 0){
				r = -1;
			}
			if (s5.scene == 1 && (continuecount == 0 && FinalChoice)){
				s5.ContentsRevival(TRUE);
			}
			else{
				s5.ContentsRevival(FALSE);
			}
			
			if (cr == 6 || cr == 7){
				if (Data.currentstage != 0){
					Data.currentstage++;
					if (StageStart(cr) != 0){
						r = -1;
					}
				}
				else{
					cr = 100;
				}
			}
			break;
		case 6://Stage6A
			break;
		case 7://Stage6B
			break;
		case 8://Extra
			break;
		}
		if (DisplayStates(stage->TenBonus) != 0){
			return -1;
		}
		stage->j.slow = ctrl.GetButton("slow");
		stage->j.ok_shot = ctrl.GetButton("ok_shot");
		stage->j.x = j.x;
		stage->j.y = j.y;

		SetDrawArea(20, 15, 404, 465);
		if (stage->s != -1 && stage->scene != 0){
			if (stage->Miss){
				int rr = MissEffect(stage);
				if (rr != 0){//エラーまたはゲームオーバーなら返り値を変更
					r = rr;
				}
			}
			else{
				if (stage->BossTalk == false){
					if (ProcessJiki(flamecount + stage->s * 60, false) != 0){
						r = -1;
					}
				}
				else{
					if ((ctrl.GetButton("slow") > 0 && ctrl.GetButton("ok_shot") == 0) || (ctrl.GetButton("ok_shot") == 1 && stage->TalkSkipCancel == false)){
						if (stage == &s1 || stage == &s2 || stage == &s3){
							stage->Talkcount--;
						}
						else{
							if (stage->appear < 1){
								stage->nexttalk = true;
								stage->appear2 = 0;
							}
						}
						s1.eff.RequestSE(s1.eff.se.talk);
					}
					if (stage->JikiStandPosition != -1){
						stage->jikistand = jikistand[jikinum][stage->JikiStandPosition];
					}
					else{
						stage->jikistand = 0;
					}
					if (stage->scene == stage->lastscene && stage->Talkcount == 1){
						int grazebonus = 0;
						switch (cr){
						case 1:
							grazebonus = 1000;
							break;
						case 2:
							grazebonus = 1250;
							break;
						case 3:
							grazebonus = 1500;
							break;
						case 4:
							grazebonus = 1750;
							break;
						case 5:
							grazebonus = 2000;
							break;
						case 6:
							grazebonus = 2500;
							break;
						case 7:
							grazebonus = 3000;
							break;
						case 8:
							grazebonus = 3000;
							break;
						}
						if (stage->result == false){
							stage->result = true;
							AddScore(stage->StageClearscore);
							AddScore(grazecount * grazebonus);
						}
						DisplayStageResult(stage->StageClearscore, grazebonus);
					}

					if (stage->TalkSkipCancel && ctrl.GetButton("slow") == 0){
						stage->TalkSkipCancel = false;
					}
					if (stage->Talkcount == stage->ChangeBGMtalkcount && stage->lastscene != stage->scene){
						int m, RequestBGM;
						if (Data.currentstage == 0){
							//Practice Mode
							m = Data.choicestage;
						}
						else{
							//Game Mode
							m = Data.currentstage;
						}
						RequestBGM = 0;
						switch (m){
						case 1:
							RequestBGM = ongaku.MusicList.Boss1;
							break;
						case 2:
							RequestBGM = ongaku.MusicList.Boss2;
							break;
						case 3:
							RequestBGM = ongaku.MusicList.Boss3;
							break;
						case 4:
							switch (s4.lastbuttle){
							case 0:
								RequestBGM = ongaku.MusicList.Boss4;
								break;
							case 1:
								RequestBGM = ongaku.MusicList.Boss41;
								break;
							case 2:
								RequestBGM = ongaku.MusicList.Boss42;
								break;
							}
							break;
							/*	case 5:
								RequestBGM = ongaku.MusicList.Boss5;
								break;
								case 6:
								RequestBGM = ongaku.MusicList.Boss6A;
								break;
								case 7:
								RequestBGM = ongaku.MusicList.BossEx;
								break;		   */
						}
						if (ongaku.CurrentBGM != RequestBGM){
							if (ongaku.RequestMusic(stage->ChangeBGMNumber) != 0){
								r = -1;
							}
							else{
								stage->Talkcount = 100;
							}
						}
					}
					if (ProcessJiki(flamecount + stage->s * 60, true) != 0){
						r = -1;
					}
				}
			}
			
			if (stage->itemcount > 0){
				SetDrawArea(20, 15, 404, 465);
				if (ProcessItem(flamecount + (stage->Begintime + stage->Currenttime) * 60, stage) != 0 && r == 0){
					r = -1;
				}
				if (flamecount % 5 == 0 && s1.eff.CheckSE(s1.eff.se.itemren)){
					if (s1.eff.countitem > 0){
						s1.eff.countitem = 0;
					}
					else{
						s1.eff.StopSE(s1.eff.se.itemren);
					}
				}
			}
			if (stage->Bossbuttle == false){
				if (stage->ProcessEnemy(flamecount + stage->s * 60) == -1){
					r = -1;
				}
			}
		}
		if (stage->Bossbuttle == false){//ボスと戦闘中でない時
			if (stage->Endtime - stage->Begintime < stage->Currenttime && r != 0){
				if (stage->scene == 0){
					stage->scene = 1;//デバッグ用
				}
				else{
					stage->scene++;
					if (jikinum == 0){
						CheckOffHoming();
					}
				}
				//最終時間を超えたら次のシーンへ移行。
			}
			else{
				if (jikinum == 0){
					CheckHoming(stage);
				}
			}
			HitJudgement(flamecount + (stage->Begintime + stage->Currenttime) * 60, stage);
			if (stage->Miss == false && ((stage->tekicount > 0 && MissJudgement(stage) == true) || (danmaku->dancount > 0 && MissJudgement(danmaku) == true))){
				//被弾時の対応
				/*stage->Miss = true;
				danmaku->ClearDanmaku();
				ClearShot();
				j.extendcount--;
				j.bombcount = 2;
				stage->missflame = 0;*/
			}
			if (stage->eff.ecount > 0){
				stage->eff.ProcessEffect();
			}
		}
		else{//ボスと戦闘時
			if (cr != 100){
				Stage::BOSU *boss = &s1.alice;;
				SetDrawArea(20, 15, 404, 465);
				doublebuttle = false;
				switch (cr){
				case 1:
					if (jikinum < 2){
						boss = &s1.alice;
						s1.ProcessAlice(flamecount);
					}
					else{
						s1.ProcessAya(flamecount);
						boss = &s1.aya;
					}
					break;
				case 2:
					if (jikinum % 2 == 0){
						boss = &s2.mystia;
						s2.ProcessMystia(flamecount);
						TukaimaHitJudgement(flamecount, stage);
					}
					else{
						boss = &s2.kogasa;
						s2.ProcessKogasa(flamecount);
					}
					break;
				case 3:
					if (s3.orinbuttle){
						boss = &s3.orin;
						if (stage->scene == 7){
							RefreshStop = true;
						}
						s3.ProcessOrin(flamecount);
						TukaimaHitJudgement(flamecount, stage);
					}
					else{
						if (jikinum == 0 || jikinum == 3){
							boss = &s3.youmu;
							s3.ProcessYoumu(flamecount);
						}
						else{
							boss = &s3.yuuka;
							s3.ProcessYuuka(flamecount);
						}
					}
					break;
				case 4:
					if (s4.rinbuttle){
						boss = &s4.Rin;
						s4.ProcessRin(flamecount);
					}
					else{
						switch (s4.lastbuttle){
						case 0://前半戦
							doublebuttle = true;
							s4.Process4Boss(flamecount);
							break;
						case 1://明子戦
							boss = &s4.akiko;
							s4.ProcessAkiko(flamecount);
							break;
						case 2://みどり戦
							boss = &s4.midori;
							s4.ProcessMidori(flamecount);
							break;
						}
					}
					break;
				case 5:
					//boss = &s5.kagari;
					break;
				case 6:
					break;
				case 7:
					break;
				}
				if (doublebuttle == false){

					if (jikinum == 0 && stage->Bosshit){
						BossCheckHoming((int)(boss->x), (int)(boss->y));
					}
					if (stage->Bosshit){
						BossHitJudgement(boss, flamecount);
					}
					if ((stage->BossTalk && stage->Talkcount == 0) || ((stage->Maxhitpoint != 0 && boss->hitpoint < 1) || stage->Bosstime == 0)){
						stage->scene++;
					}

				}
				else{
					//明子＆みどり戦　なお皆見＆炬戦は炬を使い魔として扱うものとする。
					if (jikinum == 0 && stage->Bosshit){
						BossCheckHoming((int)(s4.akiko.x), (int)(s4.akiko.y));
						BossCheckHoming((int)(s4.midori.x), (int)(s4.midori.y));
					}
					double akikohp, midorihp,totalhp;
					akikohp = 0;
					midorihp = 0;
					totalhp = s4.yonboss.hitpoint;
					if (stage->Bosshit){
						BossHitJudgement(&s4.yonboss,&s4.akiko, flamecount);
						akikohp -= (totalhp - s4.yonboss.hitpoint);
						totalhp = s4.yonboss.hitpoint;
						BossHitJudgement(&s4.yonboss,&s4.midori, flamecount);
						midorihp -= (totalhp - s4.yonboss.hitpoint);
					}
					//明子＆みどり戦はいずれも体力は共有。後半戦は直前にショットが当たっていないボスと戦う事になる。
					//撃沈の判定は（二人の体力合計）< 初期一人分の体力 で共倒れの場合はみどりが残る。
					if ((stage->BossTalk && stage->Talkcount == 0) || ((stage->Maxhitpoint != 0 && s4.yonboss.hitpoint < 1) || stage->Bosstime == 0)){
						stage->scene++;
						if (stage->scene == 21){
							if (akikohp > midorihp){
								s4.lastbuttle = 1;
							}
							else{
								s4.lastbuttle = 2;
							}
						}
					}
				}
				
				if (stage->Miss == false && (MissJudgement(danmaku) == true || BossMissJudgement(boss->x, boss->y, boss->hitr, stage) == true)){
					//被弾時の対応
					if (debuging == false) {
						stage->Miss = true;
						boss->hitpoint = (int)(boss->hitpoint * 0.75);
						stage->Maxhitpoint = (int)(stage->Maxhitpoint * 0.75);
						danmaku->ClearDanmaku();
						ClearShot();
						j.extendcount--;
						j.bombcount = 2;
						stage->missflame = 0;
						stage->SpellBonusScore = 0;
					}
				}
				if (flamecount % 30 == 0 && RefreshStop == false){
					danmaku->DanmakuRefresh();
				}
			}
		}
		SetDrawArea(1, 1, 639, 479);
		if (stage->prescene != stage->scene){
			stage->s = 0;
			if (stage->Nextscene(stage->scene, j.powercount) == -1){
				r = -1;
			}
		}
		AddGraze(GrazeJudgement(danmaku));
		AddScore(stage->totalscore);
		switch (cr){
		case 0:
			r = 0;
			break;
		case 8:
			r = 8;
			break;
		case 9:
			r = 9;
			break;
		case 100:
			r = 100;
			break;
		}

		return r;
	}
	int Jiki::ProcessReplay(int flamecount){
		int r = 0;
		return r;
	}
	void Jiki::SetContinue(){
		j.extendcount = 2;
		j.bombcount = 2;
		j.power = 0;
		j.powercount = 1;
		j.x = 180;
		j.y = 410;
		continuecount++;
	}
	void Jiki::Set_partner(char* name){
		Data.partner = name;
	}
	void Jiki::Set_difficulty(int dif){//難易度を設定します。Easy = 1,Normal = 2, Hard = 3, Lunatic = 4, Extra = 5とします。
		Data.difficulty = dif;
		Data.currentstage = 1;
	}
	void Jiki::Set_choicestage(int cs){
		Data.choicestage = cs;
		Data.currentstage = 0;
	}
	void Jiki::ClearData(){
		Data.partner = "";
		Data.difficulty = 0;
		Data.choicestage = 0;
		Data.currentstage = 0;
	}
	int  Jiki::StageStart(int choice){
		int r = 0;
		bool practice;
		if (choice < 10){//Game Mode
			practice = false;
		}
		else{//PracticeMode
			practice = true;
			choice -= 10;
		}
		if (jikinum == 0){

		}
		InputName(practice);
		ClearShot();
		LoadShot();
		Stage * stage;
		switch (choice){
		case 1://Stage1
			s1.ExtendPlayerData(Data.difficulty, Data.partner, Data.choicestage, practice);
			s1.Input_Data("Stage1", 3);
			s1.eff.ClearEffect();
			s1.danmaku.eff.ClearEffect();
			if (s1.Nextscene(s1.scene, j.powercount) != 0 || ongaku.RequestMusic(1) != 0){
				r = -1;
			}
			stage = &s1;
			break;
		case 2://Stage2
			s2.ExtendPlayerData(Data.difficulty, Data.partner, Data.choicestage, practice);
			s2.Input_Data("Stage2", 5);
			s2.eff.ClearEffect();
			s2.danmaku.eff.ClearEffect();
			if (s2.Nextscene(s2.scene, j.powercount) != 0 || ongaku.RequestMusic(3) != 0){
				r = -1;
			}
			stage = &s2;
			break;
		case 3://Stage3
			s3.ExtendPlayerData(Data.difficulty, Data.partner, Data.choicestage, practice);
			s3.Input_Data("Stage3", 6);
			s3.eff.ClearEffect();
			s3.danmaku.eff.ClearEffect();
			if (s3.Nextscene(s3.scene, j.powercount) != 0 || ongaku.RequestMusic(5) != 0){
				r = -1;
			}
			stage = &s3;
			break;
		case 4://Stage4
			s4.ExtendPlayerData(Data.difficulty, Data.partner, Data.choicestage, practice);
			s4.Input_Data("Stage4", 7);
			s4.eff.ClearEffect();
			s4.danmaku.eff.ClearEffect();
			if (s4.Nextscene(s4.scene, j.powercount) != 0 || ongaku.RequestMusic(7) != 0){
				r = -1;
			}
			stage = &s4;
			break;
		case 5://Stage5
			break;
		case 6://Stage6A
			break;
		case 7://Stage6B
			break;
		}
		for (int j = 0; j < 16; j++){
			stage->jstand[j] = jikistand[jikinum][j];
		}
		return r;
	}
	int Jiki::ProcessItem(int flame, Stage * stage){
		int r = 0;
		int time, p;
		p = stage->item[0].np;
		while (p != stage->itemtail && p != 0 && r == 0){
			if (stage->item[p].homing){//自機へホーミングするとき
				if (pow(stage->item[p].y - j.y, 2.0) + pow(stage->item[p].x - j.x, 2.0) > pow(j.itemr, 2.0)){
					p = p;
				}
				double dx = stage->item[p].x - j.x;
				double dy = stage->item[p].y - j.y;
				double angle = atan2(dy, dx);
				if (pow(dx, 2.0) + pow(dy, 2.0) > 225){
					stage->item[p].x += cos(angle) * -15;
					stage->item[p].y += sin(angle) * -15;
				}
				else{
					stage->item[p].x += dx;
					stage->item[p].y += dy;
				}
			}
			else{//画面下に落下するとき
				double vecy = 0;
				time = flame - stage->item[p].start;
				if (stage->item[p].itemshu == 6 && stage->missflame != 120){
					double vecx = 0;
					switch (stage->itemtail - p){
					case 1:
						if (stage->missflame < 40){
							vecy = (double)(40 - j.y) * 2 / 3 / 40;
							vecx = (double)(40 - j.x) * 2 / 3 / 40;
						}
						else{
							if (stage->missflame < 60){
								vecy = (double)(40 - j.y) / 3 / 20;
								vecx = (double)(40 - j.x) / 3 / 20;
							}
							else{
								if (stage->missflame < 80){
									vecy = 1;
								}
								else{
									vecy = 2;
								}

							}
						}
						break;
					case 2:
						vecx = 0;
						if (stage->missflame < 40){
							vecy = (double)(40 - j.y) * 2 / 3 / 40;
						}
						else{
							if (stage->missflame < 60){
								vecy = (double)(200 - j.y) / 3 / 20;
							}
							else{
								if (stage->missflame < 80){
									vecy = 1;
								}
								else{
									vecy = 2;
								}
							}
						}
						break;
					case 3:
						if (stage->missflame < 40){
							vecy = (double)(40 - j.y) * 2 / 3 / 40;
							vecx = (double)(340 - j.x) * 2 / 3 / 40;
						}
						else{
							if (stage->missflame < 60){
								vecy = (double)(40 - j.y) / 3 / 20;
								vecx = (double)(340 - j.x) / 3 / 20;
							}
							else{
								if (stage->missflame < 80){
									vecy = 1;
								}
								else{
									vecy = 2;
								}

							}
						}
						break;
					}
					stage->item[p].x += vecx;
					stage->item[p].y += vecy;
				}
				else{
					if ((stage->missflame == 120 || stage->itemtail - p > 10)){
						if (time < 20){
							//いったん上昇
							vecy = -2;
						}
						else{
							if (time < 40){
								//ゆっくり上昇
								vecy = -1;
							}
							else{
								if (time < 60){
									//ゆっくり下降
									vecy = 1;
								}
								else{
									//そのまま落下
									vecy = 2;
								}
							}
						}
						stage->item[p].y += vecy;
					}
					else{
						if (stage->item[p].itemshu != 6){
							if (stage->missflame < 40){
								vecy = 2;
							}
							else{
								if (stage->missflame < 60){
									vecy = 1;
								}
								else{
									if (stage->missflame < 80){
										vecy = -1;
									}
									else{
										vecy = -2;
									}

								}
							}
							stage->item[p].y -= vecy;
						}
					}
				}
				if (pow(stage->item[p].y - j.y, 2.0) + pow(stage->item[p].x - j.x, 2.0) < pow(j.itemr, 2.0)){
					stage->item[p].homing = true;
				}
				if (j.powercount == 5 && j.y < 101){
					stage->item[p].homing = true;
				}
			}
			if (stage->Miss){
				stage->item[p].homing = false;
			}
			if (stage->item[p].y - stage->item[p].imggapp > 465){
				stage->DeleteItem(p);
			}
			else{
				if (pow(stage->item[p].y - j.y, 2.0) + pow(stage->item[p].x - j.x, 2.0) < 25 && stage->Miss == false){
					CorrectItem(p, stage,flame);
				}
				else{
					if (DrawGraph((int)(stage->item[p].x - stage->item[p].imggapp), (int)(stage->item[p].y - stage->item[p].imggapp), stage->item[p].imgp, true) != 0){
						r = -1;
					}
				}
			}
			if (stage->itemcount == 0 || p == 0){ p = stage->itemtail; }
			p = stage->item[p].np;
		}
		if (stage->itemcount > 0 && (flame % 60 == 0 || stage->itemtail > ITEM_LIMIT - 50 || stage->itemcount > ITEM_LIMIT - 50)){ stage->RefreshItem(); }
		if (r == -1){
			r = -1;
		}
		return r;
	}
	void Jiki::CorrectItem(int p, Stage * stage,int flame){
		switch (stage->item[p].itemshu){
		case 1://パワーアイテム
			if (j.power == 128){
				AddScore(25000);
			}
			else{
				j.power++;
				if (j.power == 128){
					s1.eff.RequestSE(s1.eff.se.powermax);
				}
			}
			s1.eff.countitem++;
			if (s1.eff.countitem > 0 && s1.eff.CheckSE(s1.eff.se.itemren) == false){
				s1.eff.RequestSE(s1.eff.se.itemren);
			}
			break;
		case 2://点アイテム
			AddScore(stage->TenBonus);
			stage->TenBonus += 100;
			s1.eff.countitem++;
			if (s1.eff.countitem > 0 && s1.eff.CheckSE(s1.eff.se.itemren) == false){
				s1.eff.RequestSE(s1.eff.se.itemren);
			}
			break;
		case 3://星
			s1.eff.countitem++;
			if (s1.eff.countitem > 0 && s1.eff.CheckSE(s1.eff.se.itemren) == false){
				s1.eff.RequestSE(s1.eff.se.itemren);
			}
			break;
		case 4://ボム
			j.bombcount++;
			AddScore(25000);
			break;
		case 5://エクステンド
			j.extendcount++;
			AddScore(100000);
			break;
		case 6://フルパワーアイテム
			j.power = 128;
			j.powercount = 5;
			break;
		}
		if (j.power == 16 || j.power == 32 || j.power == 64){
			s1.eff.RequestSE(s1.eff.se.powerup);
		}
		if (j.power < 16){
			j.powercount = 1;
		}
		else{
			if (j.power < 32){
				j.powercount = 2;
			}
			else{
				if (j.power < 64){
					j.powercount = 3;
				}
				else{
					if (j.power < 128){
						j.powercount = 4;
					}
					else{
						j.powercount = 5;
					}
				}
			}
		}
		stage->DeleteItem(p);
	}
	void Jiki::CheckHoming(Stage *stage){//ホーミング弾に対する処理の必要性を判断し、正ならその処理をします。
		int searchr = 0;
		int p = stage->teki[0].np;
		int shotp, shortestp;
		double shortestr, r;

		if (jikinum == 0 && shotcount > 0){
			//ホーミング弾のサーチ範囲はパワー段階に応じて広くなる。
			searchr = 155 + (j.powercount - 1) * 25;
		}
		shotp = shot[0].np;
		while (searchr != 0 && shotp != tail && shotcount > 0){
			if (shot[shotp].imgp == shotdot[0][1] && shott[shotp].sethoming == false){
				p = stage->teki[0].np;
			}
			else{
				p = stage->tail;
				if (shott[shotp].sethoming && shott[shotp].homingp > -1){
					double dx = shot[shotp].x - stage->teki[shott[shotp].homingp].x;
					double dy = shot[shotp].y - stage->teki[shott[shotp].homingp].y;
					double angle = atan2(dy, dx);
					if (sqrt(pow(dx, 2.0) + pow(dy, 2.0)) > 8){
						shot[shotp].vecx = cos(angle) * -8;
						shot[shotp].vecy = sin(angle) * -8;
					}
					else{
						//レンジ8以内まで追跡したらhit確実とする。
						shott[shotp].hit = true;
					}
				}
			}
			shortestr = 1000;
			while (p != stage->tail){
				r = sqrt(pow(shot[shotp].x - stage->teki[p].x, 2.0) + pow(shot[shotp].y - stage->teki[p].y, 2.0));
				if (r < shortestr && r < searchr && stage->teki[p].ready == 0){//ショットに最も近く、かつサーチ範囲内の時
					shortestp = p;
					shortestr = r;
				}
				p = stage->teki[p].np;
			}
			if (shortestr != 1000){
				shott[shotp].homingp = shortestp;
				shott[shotp].sethoming = true;
				double dx = shot[shotp].x - stage->teki[shott[shotp].homingp].x;
				double dy = shot[shotp].y - stage->teki[shott[shotp].homingp].y;
				double angle = atan2(dy, dx);
				if (sqrt(pow(dx, 2.0) + pow(dy, 2.0)) > 8){
					shot[shotp].vecx = cos(angle) * -8;
					shot[shotp].vecy = sin(angle) * -8;
				}
			}
			shotp = shot[shotp].np;
		}
	}
	void Jiki::CheckOffHoming(){//ホーミング弾のホーミング状態を解除します。
		int p = shot[0].np;
		while (p != tail && shotcount > 0){
			if (shott[p].sethoming == true){
				shott[p].sethoming = false;
				shott[p].hit = false;
			}
			p = shot[p].np;
		}
	}
	void Jiki::BossCheckHoming(int bossx, int bossy){
		int shotendf;
		double searchr;
		int shotp;
		if (jikinum == 0 && shotcount > 0){
			shotendf = 0;
			//ホーミング弾のサーチ範囲はパワー段階に応じて広くなる。
			searchr = pow(155 + (j.powercount - 1) * 25, 2.0);
			shotp = shot[0].np;
		}
		else{
			shotendf = 100;
		}
		while (shotendf == 0){
			if (shot[shotp].imgp == shotdot[0][1] && shott[shotp].sethoming == false){//サーチ位置がまだ特定されていないとき
				if (pow(shot[shotp].x - bossx, 2.0) + pow(shot[shotp].y - bossy, 2.0) < searchr){
					shott[shotp].sethoming = true;
				}
			}
			else{
				if (shott[shotp].sethoming){
					double dx = shot[shotp].x - bossx;
					double dy = shot[shotp].y - bossy;
					double angle = atan2(dy, dx);
					if (sqrt(pow(dx, 2.0) + pow(dy, 2.0)) > 7.5){
						shot[shotp].vecx = cos(angle) * -7.5;
						shot[shotp].vecy = sin(angle) * -7.5;
					}
				}
			}
			shotp = shot[shotp].np;
			if (shotp == tail || shotcount == 0){ shotendf = 100; }
		}
	}
	void Jiki::BossCheckHoming(int bx1, int by1, int bx2, int by2){
		int shotendf;
		double searchr;
		int shotp;
		if (jikinum == 0 && shotcount > 0){
			shotendf = 0;
			//ホーミング弾のサーチ範囲はパワー段階に応じて広くなる。
			searchr = pow(155 + (j.powercount - 1) * 25, 2.0);
			shotp = shot[0].np;
		}
		else{
			shotendf = 100;
		}
		while (shotendf == 0){
			if (shot[shotp].imgp == shotdot[0][1] && shott[shotp].sethoming == false){//サーチ位置がまだ特定されていないとき
				if (pow(shot[shotp].x - bx1, 2.0) + pow(shot[shotp].y - by1, 2.0) < searchr){
					shott[shotp].sethoming = true;
					shott[shotp].whichset = true;
				}
				if (pow(shot[shotp].x - bx2, 2.0) + pow(shot[shotp].y - by2, 2.0) < searchr){
					shott[shotp].sethoming = true;
					shott[shotp].whichset = false;
				}
			}
			else{
				if (shott[shotp].sethoming){
					double dx = shot[shotp].x - bx1;
					double dy = shot[shotp].y - by1;
					if (shott[shotp].whichset == false){
						dx = shot[shotp].x - bx2;
						dy = shot[shotp].y - by2;
					}
					double angle = atan2(dy, dx);
					if (sqrt(pow(dx, 2.0) + pow(dy, 2.0)) > 7.5){
						shot[shotp].vecx = cos(angle) * -7.5;
						shot[shotp].vecy = sin(angle) * -7.5;
					}
				}
			}
			shotp = shot[shotp].np;
			if (shotp == tail || shotcount == 0){ shotendf = 100; }
		}
	}
	void Jiki::HitJudgement(int flame, Stage *stage){
		//自機のショットが敵に当たるかどうかを判断する関数です。ショットが当たると敵のHPを減らし、0になれば撃沈の処理をします。また当たればtrueを返して終了します。
		int p = stage->teki[0].np;
		int shotp;
		if (stage->tekicount == 0){
			p = stage->tail;
		}
		int shotendf = 0;
		int judger;
		int hitr = 4;//ショットのあたり判定は特殊なものを除き半径4の円で行うものとする。
		bool hit;//ショットが敵にヒットしたかどうかを示す変数です。ショットごとに異なる判定方法で判断します。
		double dx, dy;
		while (p != stage->tail && p < TEKIDATA){
			if (stage->teki[p].tekishu < 5){
				//青～緑妖精
				judger = 10;
			}
			else{
				if (stage->teki[p].tekishu == 5){
					//ひまわり妖精
					judger = 24;
				}
				else{
					//綿毛
					judger = 10;
				}
			}
			shotp = shot[0].np;
			while (shotp != tail && shotcount > 0 && stage->teki[p].ready == 0){
				hit = false;
				if (shot[shotp].imgp == shotdot[1][2] || shot[shotp].imgp == shotdot[1][4]){
					if (shot[shotp].y + 69 > stage->teki[p].y){
						/*/低速魅魔のビーム弾は円と範囲で判定 &&
						if ((stage->teki[p].x > shot[shotp].x - shot[shotp].imggapp && stage->teki[p].x < shot[shotp].x - shot[shotp].imggapp + 17) || (stage->teki[p].x < shot[shotp].x && stage->teki[p].x + judger > shot[shotp].x - shot[shotp].imggapp) || (stage->teki[p].x >= shot[shotp].x && stage->teki[p].x - judger < shot[shotp].x - shot[shotp].imggapp + 17)){
						//敵判定円の左右端がショットの右端・左端線にまたがっているとき
						if (stage->teki[p].y > shot[shotp].y - shot[shotp].imggapp && stage->teki[p].y < shot[shotp].y - shot[shotp].imggapp + 69){
						//敵判定円の中心がショットの上下端の間にあるとき
						hit = true;
						if (shot[shotp].imgp == shotdot[1][4] && j.powercount > 2 && shott[shotp].beamed == false){
						shot[shotp].power *= 0.9;//残留していない影ビームは一度命中するたびにパワーが減少する。
						}
						}
						}*/
						int judge = 1;
						int rr;
						struct corner{
							double x;
							double y;
						};
						corner l1, l2, l3, l4;
						rr = 71;
						l1.x = shot[shotp].x;
						l1.y = shot[shotp].y;
						l2.x = shot[shotp].x + 17;
						l2.y = shot[shotp].y;
						l3.x = shot[shotp].x + 17;
						l3.y = shot[shotp].y + 69;
						l4.x = shot[shotp].x;
						l4.y = shot[shotp].y + 69;
						e1.clear();
						e2.clear();
						e3.clear();
						e4.clear();
						e1.push_back((int)(l2.x - l1.x));
						e1.push_back((int)(l2.y - l1.y));
						e2.push_back((int)(l3.x - l2.x));
						e2.push_back((int)(l3.y - l2.y));
						e3.push_back((int)(l4.x - l3.x));
						e3.push_back((int)(l4.y - l3.y));
						e4.push_back((int)(l1.x - l4.x));
						e4.push_back((int)(l1.y - l4.y));
						int  k1, k2;
						corner * c = 0;
						double k, pn;
						while (judge < 4){
							switch ((int)(judge)){
							case 1:
								//角による判定
								
								for (int jj = 1; jj < 5; jj++){
									switch (jj){
									case 1:
										c = &l1;
										break;
									case 2:
										c = &l2;
										break;
									case 3:
										c = &l3;
										break;
									case 4:
										c = &l4;
										break;
									}
									if (pow((c->x - stage->teki[p].x), 2.0) + pow((c->y - stage->teki[p].y), 2.0) < pow(judger, 2.0)){
										hit = true;
									}
								}
								break;
							case 2:
								//レーザー内の判定
								jr1.clear();
								jr2.clear();
								jr1.push_back((int)(stage->teki[p].x - l1.x));
								jr1.push_back((int)(stage->teki[p].y - l1.y));
								jr2.push_back((int)(stage->teki[p].x - l3.x));
								jr2.push_back((int)(stage->teki[p].x - l3.x));
								double out, in;
								out = OuterMulti(e1, jr1);
								in = InnerMulti(e1, jr1);
								k1 = (int)(atan2(out, in) * 180 / PI);
								out = OuterMulti(e3, jr2);
								in = InnerMulti(e3, jr2);
								k2 = (int)(atan2(out, in) * 180 / PI);
								if (k1 >= 0 && k1 <= 90 && k2 >= 0 && k2 <= 90){
									hit = true;
								}
								break;
							case 3:
								//レーザーの四辺での判定
								for (int jj = 1; jj < 5; jj++){
									l.clear();
									jr1.clear();
									switch (jj){
									case 1:
										l = e1;
										jr1.push_back((int)(l1.x - stage->teki[p].x));
										jr1.push_back((int)(l1.y - stage->teki[p].y));
										break;
									case 2:
										l = e2;
										jr1.push_back((int)(l2.x - stage->teki[p].x));
										jr1.push_back((int)(l2.y - stage->teki[p].y));
										break;
									case 3:
										l = e3;
										jr1.push_back((int)(l3.x - stage->teki[p].x));
										jr1.push_back((int)(l3.y - stage->teki[p].y));
										break;
									case 4:
										l = e4;
										jr1.push_back((int)(l4.x - stage->teki[p].x));
										jr1.push_back((int)(l4.y - stage->teki[p].y));
										break;
									}
									double pw, in;
									in = InnerMulti(l, jr1);
									pw = PowMulti(l);
									k = in / pw;
									if (k > 0 && k < 1){
										pn = PowMulti(jr1) - pow(in, 2.0) / pw;
										if (pn < pow(judger, 2.0)){
											hit = true;
										}
									}
								}
								break;
							}
							judge++;
						}
						if (hit == true && shot[shotp].imgp == shotdot[1][4] && j.powercount > 2 && shott[shotp].beamed == false){
							shot[shotp].power *= 0.9;//残留していない影ビームは一度命中するたびにパワーが減少する。
						}
					}
				}
				else{
					if (shot[shotp].imgp == shotdot[2][0] || shot[shotp].imgp == shotdot[2][2]){
						//早苗ワイド弾は中心と両端を中心とした三つの円で判定
						double /*dot1,dot2,*/sx, sy, ex, ey;
						sx = shot[shotp].x + cos(shot[shotp].imgangle * PI / 180) * (shot[shotp].imggapp);
						sy = shot[shotp].y + sin(shot[shotp].imgangle * PI / 180) * (shot[shotp].imggapp);
						ex = shot[shotp].x - cos(shot[shotp].imgangle * PI / 180) * (shot[shotp].imggapp);
						ey = shot[shotp].y - sin(shot[shotp].imgangle * PI / 180) * (shot[shotp].imggapp);
						dx = pow(stage->teki[p].x - sx, 2.0);
						dy = pow(stage->teki[p].y - sy, 2.0);
						if (dx + dy < pow(hitr + judger, 2.0)){
							hit = true;
						}
						else{
							dx = pow(stage->teki[p].x - ex, 2.0);
							dy = pow(stage->teki[p].y - ey, 2.0);
							if (dx + dy < pow(hitr + judger, 2.0)){
								hit = true;
							}
							else{
								dx = pow(stage->teki[p].x - shot[shotp].x, 2.0);
								dy = pow(stage->teki[p].y - shot[shotp].y, 2.0);
								if (dx + dy < pow(hitr + judger, 2.0)){
									hit = true;
								}
							}
						}
						/*dx = sx - ex;
						dy = sy - ey;
						dot1 = dx * (teki[p].x - sx) + dy * (teki[p].y - sy);
						if(dot1 < 0){
						if(pow(sx - teki[p].x,2.0) + pow(sy - teki[p].y,2.0) < hitr){
						hit = true;
						}
						}else{
						dot2 = pow(dx,2.0) + pow(dy,2.0);
						if(dot1 > dot2){
						if(pow(ex - teki[p].x,2.0) + pow(ey - teki[p].y,2.0) < pow(hitr,2.0)){
						hit = true;
						}
						}else{
						double dot3 = pow(teki[p].x,2.0) + pow(teki[p].y,2.0);
						if(dot3 - (dot1/dot2) * dot1 < pow(hitr,2.0)){
						hit = true;
						}
						}
						}
						*/
					}
					else{
						//その他のショットは円で判定
						dx = pow(stage->teki[p].x - shot[shotp].x, 2.0);
						dy = pow(stage->teki[p].y - shot[shotp].y, 2.0);
						if (shot[shotp].imgp == shotdot[0][2] && stage->teki[p].tekishu == 5){
							//低速布都の炎弓弾は判定が大きめ
							hitr = 6;
							judger = 30;
						}
						if (dx + dy < pow(hitr + judger, 2.0) || (shot[shotp].imgp == shotdot[0][1] && shott[shotp].hit)){
							hit = true;
						}
					}
				}
				if (hit && stage->teki[p].hitpoint > 0){
					//ショットが命中
					if (j.slow){
						if (flame % 5 == 0){
							s1.eff.RequestSE(s1.eff.se.hit);
						}
					}
					else{
						if (flame % 2 == 0){
							s1.eff.RequestSE(s1.eff.se.hit);
						}
					}
					if (shot[shotp].imgp != shotdot[1][2] && shot[shotp].imgp != shotdot[1][4]){
						Deleteshot(shotp);
					}
					stage->teki[p].hitpoint -= shot[shotp].power;
					if (stage->teki[p].hitpoint < 1 && stage->teki[p].hitpoint != -100){
						//敵撃墜
						stage->teki[p].hitpoint = -100;
						s1.eff.RequestSE(s1.eff.se.enemyend);
						stage->SetItem(stage->teki[p].x, stage->teki[p].y, flame, stage->teki[p].poweritem, stage->teki[p].tenitem);
						if (stage->tteki[p].counter){
							stage->teki[p].hitpoint = 0.01;
						}
						else{
							stage->DeleteEnemy(p);
						}
						if (jikinum == 0 && shotcount > 0){
							int shotendf = 0;
							int shotp = shot[0].np;
							while (tail != shotp && shotcount > 0){
								if (p == shott[shotp].homingp){
									shott[shotp].homingp = -1;
								}
								shotp = shot[shotp].np;
							}
						}
						shotendf = 100;
					}
				}
				shotp = shot[shotp].np;
			}
			p = stage->teki[p].np;
		}
	}
	void Jiki::BossHitJudgement(Stage::BOSU * boss,int flame){
		//ボスの当たり判定を行い、当たったショットのダメージの合計を返り値として返します。
		int shotp = shot[0].np;
		double totaldamage = 0;
		bool hit = false;
		int hitr = 4;
		while (shotp != tail && shotcount > 0){
			if (shot[shotp].imgp == shotdot[1][2] || shot[shotp].imgp == shotdot[1][4]){
				//低速魅魔のビーム弾は円と範囲で判定
				/*/低速魅魔のビーム弾は円と範囲で判定
				if (boss->y > shot[shotp].y - shot[shotp].imggapp && boss->y < shot[shotp].y - shot[shotp].imggapp + 69){
					//敵判定円の中心がショットの上限・下限の間にあるとき
					if (boss->x < shot[shotp].x - shot[shotp].imggapp){
						//敵判定円の中心がビームの左端よりも左にあるとき
						if (boss->x + boss->hitr > shot[shotp].x - shot[shotp].imggapp){
							hit = true;//判定円の半径が判定X軸と交差するとき
						}
					}
					else{
						if (shot[shotp].x - shot[shotp].imggapp + 17 > boss->x || boss->x - boss->hitr < shot[shotp].x - shot[shotp].imggapp + 17){
							hit = true;//ショット内に敵がいるか判定円の半径がショット位置+69の判定X軸と交差するとき
						}
					}
				}*/
				int judge = 1;
				int rr;
				struct corner{
					double x;
					double y;
				};
				corner l1, l2, l3, l4;
				rr = 71;
				l1.x = shot[shotp].x;
				l1.y = shot[shotp].y;
				l2.x = shot[shotp].x + 17;
				l2.y = shot[shotp].y;
				l3.x = shot[shotp].x + 17;
				l3.y = shot[shotp].y + 69;
				l4.x = shot[shotp].x;
				l4.y = shot[shotp].y + 69;
				e1.clear();
				e2.clear();
				e3.clear();
				e4.clear();
				e1.push_back((int)(l2.x - l1.x));
				e1.push_back((int)(l2.y - l1.y));
				e2.push_back((int)(l3.x - l2.x));
				e2.push_back((int)(l3.y - l2.y));
				e3.push_back((int)(l4.x - l3.x));
				e3.push_back((int)(l4.y - l3.y));
				e4.push_back((int)(l1.x - l4.x));
				e4.push_back((int)(l1.y - l4.y));
				int  k1, k2;
				corner * c = 0;
				double k, pn;
				while (judge < 4){
					switch ((int)(judge)){
					case 1:
						//角による判定
						
						for (int jj = 1; jj < 5; jj++){
							switch (jj){
							case 1:
								c = &l1;
								break;
							case 2:
								c = &l2;
								break;
							case 3:
								c = &l3;
								break;
							case 4:
								c = &l4;
								break;
							}
							if (pow((c->x - boss->x), 2.0) + pow((c->y - boss->y), 2.0) < pow(boss->hitr, 2.0)){
								hit = true;
							}
						}
						break;
					case 2:
						//レーザー内の判定
						jr1.clear();
						jr2.clear();
						jr1.push_back((int)(boss->x - l1.x));
						jr1.push_back((int)(boss->y - l1.y));
						jr2.push_back((int)(boss->x - l3.x));
						jr2.push_back((int)(boss->y - l3.y));
						double out, in;
						out = OuterMulti(e1, jr1);
						in = InnerMulti(e1, jr1);
						k1 = (int)(atan2(out, in) * 180 / PI);
						out = OuterMulti(e3, jr2);
						in = InnerMulti(e3, jr2);
						k2 = (int)(atan2(out, in) * 180 / PI);
						if (k1 >= 0 && k1 <= 90 && k2 >= 0 && k2 <= 90){
							hit = true;
						}
						break;
					case 3:
						//レーザーの四辺での判定
						for (int jj = 1; jj < 5; jj++){
							l.clear();
							jr1.clear();
							switch (jj){
							case 1:
								l = e1;
								jr1.push_back((int)(l1.x - boss->x));
								jr1.push_back((int)(l1.y - boss->y));
								break;
							case 2:
								l = e2;
								jr1.push_back((int)(l2.x - boss->x));
								jr1.push_back((int)(l2.y - boss->y));
								break;
							case 3:
								l = e3;
								jr1.push_back((int)(l3.x - boss->x));
								jr1.push_back((int)(l3.y - boss->y));
								break;
							case 4:
								l = e4;
								jr1.push_back((int)(l4.x - boss->x));
								jr1.push_back((int)(l4.y - boss->y));
								break;
							}
							double pw, in;
							in = InnerMulti(l, jr1);
							pw = PowMulti(l);
							k = in / pw;
							if (k > 0 && k < 1){
								pn = PowMulti(jr1) - pow(in, 2.0) / pw;
								if (pn < pow(boss->hitr, 2.0)){
									hit = true;
								}
							}
						}
						break;
					}
					judge++;
				}
				if (hit == true && shot[shotp].imgp == shotdot[1][4] && j.powercount > 2 && shott[shotp].beamed == false){
					shot[shotp].power *= 0.9;//残留していない影ビームは一度命中するたびにパワーが減少する。
				}
			}
			else{
				if (shot[shotp].imgp == shotdot[2][0] || shot[shotp].imgp == shotdot[2][2]){
					//早苗ワイド弾は中心と両端を中心とした三つの円で判定
					double /*dot1,dot2,*/sx, sy, ex, ey, dx, dy;
					sx = shot[shotp].x + cos(shot[shotp].imgangle * PI / 180) * (shot[shotp].imggapp);
					sy = shot[shotp].y + sin(shot[shotp].imgangle * PI / 180) * (shot[shotp].imggapp);
					ex = shot[shotp].x - cos(shot[shotp].imgangle * PI / 180) * (shot[shotp].imggapp);
					ey = shot[shotp].y - sin(shot[shotp].imgangle * PI / 180) * (shot[shotp].imggapp);
					dx = pow(boss->x - sx, 2.0);
					dy = pow(boss->y - sy, 2.0);
					if (dx + dy < pow(hitr + boss->hitr, 2.0)){
						hit = true;
					}
					else{
						dx = pow(boss->x - ex, 2.0);
						dy = pow(boss->y - ey, 2.0);
						if (dx + dy < pow(hitr + boss->hitr, 2.0)){
							hit = true;
						}
						else{
							dx = pow(boss->x - shot[shotp].x, 2.0);
							dy = pow(boss->y - shot[shotp].y, 2.0);
							if (dx + dy < pow(hitr + boss->hitr, 2.0)){
								hit = true;
							}
						}
					}
					/*dx = sx - ex;
					dy = sy - ey;
					dot1 = dx * (teki[p].x - sx) + dy * (teki[p].y - sy);
					if(dot1 < 0){
					if(pow(sx - teki[p].x,2.0) + pow(sy - teki[p].y,2.0) < hitr){
					hit = true;
					}
					}else{
					dot2 = pow(dx,2.0) + pow(dy,2.0);
					if(dot1 > dot2){
					if(pow(ex - teki[p].x,2.0) + pow(ey - teki[p].y,2.0) < pow(hitr,2.0)){
					hit = true;
					}
					}else{
					double dot3 = pow(teki[p].x,2.0) + pow(teki[p].y,2.0);
					if(dot3 - (dot1/dot2) * dot1 < pow(hitr,2.0)){
					hit = true;
					}
					}
					}
					*/
				}
				else{
					//その他のショットは円で判定
					double dx, dy;
					dx = pow(boss->x - shot[shotp].x, 2.0);
					dy = pow(boss->y - shot[shotp].y, 2.0);
					if (shot[shotp].imgp == shotdot[0][2]){
						//低速布都の炎弓弾は判定が大きめ
						hitr = 6;
					}
					if (dx + dy < pow(hitr + boss->hitr, 2.0)){
						hit = true;
					}
				}
			}
			if (hit){
				//ショットが命中
				totaldamage += shot[shotp].power;
				if (j.slow){
					if (flame % 5 == 0){
						s1.eff.RequestSE(s1.eff.se.hit);
					}
				}
				else{
					if (flame % 2 == 0){
						s1.eff.RequestSE(s1.eff.se.hit);
					}
				}
				if (shot[shotp].imgp != shotdot[1][2] && shot[shotp].imgp != shotdot[1][4]){
					Deleteshot(shotp);
				}
				else{
					if (shot[shotp].imgp == shotdot[1][4] && j.powercount > 2 && shott[shotp].beamed == false){
						shot[shotp].power *= 0.9;//残留していない影ビームは一度命中するたびにパワーが減少する。
					}
				}
			}
			hit = false;
			shotp = shot[shotp].np;
		}
		
		boss->hitpoint -= totaldamage;
	};
	void Jiki::BossHitJudgement(Stage::BOSU * total, Stage::BOSU * boss, int flame){
		int shotp = shot[0].np;
		double totaldamage = 0;
		bool hit = false;
		int hitr = 4;
		while (shotp != tail && shotcount > 0){
			if (shot[shotp].imgp == shotdot[1][2] || shot[shotp].imgp == shotdot[1][4]){
				//低速魅魔のビーム弾は円と範囲で判定
				/*/低速魅魔のビーム弾は円と範囲で判定
				if (boss->y > shot[shotp].y - shot[shotp].imggapp && boss->y < shot[shotp].y - shot[shotp].imggapp + 69){
				//敵判定円の中心がショットの上限・下限の間にあるとき
				if (boss->x < shot[shotp].x - shot[shotp].imggapp){
				//敵判定円の中心がビームの左端よりも左にあるとき
				if (boss->x + boss->hitr > shot[shotp].x - shot[shotp].imggapp){
				hit = true;//判定円の半径が判定X軸と交差するとき
				}
				}
				else{
				if (shot[shotp].x - shot[shotp].imggapp + 17 > boss->x || boss->x - boss->hitr < shot[shotp].x - shot[shotp].imggapp + 17){
				hit = true;//ショット内に敵がいるか判定円の半径がショット位置+69の判定X軸と交差するとき
				}
				}
				}*/
				int judge = 1;
				int rr;
				struct corner{
					double x;
					double y;
				};
				corner l1, l2, l3, l4;
				rr = 71;
				l1.x = shot[shotp].x;
				l1.y = shot[shotp].y;
				l2.x = shot[shotp].x + 17;
				l2.y = shot[shotp].y;
				l3.x = shot[shotp].x + 17;
				l3.y = shot[shotp].y + 69;
				l4.x = shot[shotp].x;
				l4.y = shot[shotp].y + 69;
				e1.clear();
				e2.clear();
				e3.clear();
				e4.clear();
				e1.push_back((int)(l2.x - l1.x));
				e1.push_back((int)(l2.y - l1.y));
				e2.push_back((int)(l3.x - l2.x));
				e2.push_back((int)(l3.y - l2.y));
				e3.push_back((int)(l4.x - l3.x));
				e3.push_back((int)(l4.y - l3.y));
				e4.push_back((int)(l1.x - l4.x));
				e4.push_back((int)(l1.y - l4.y));
				int  k1, k2;
				corner * c = 0;
				double k, pn;
				while (judge < 4){
					switch ((int)(judge)){
					case 1:
						//角による判定
						
						for (int jj = 1; jj < 5; jj++){
							switch (jj){
							case 1:
								c = &l1;
								break;
							case 2:
								c = &l2;
								break;
							case 3:
								c = &l3;
								break;
							case 4:
								c = &l4;
								break;
							}
							if (pow((c->x - boss->x), 2.0) + pow((c->y - boss->y), 2.0) < pow(boss->hitr, 2.0)){
								hit = true;
							}
						}
						break;
					case 2:
						//レーザー内の判定
						jr1.clear();
						jr2.clear();
						jr1.push_back((int)(boss->x - l1.x));
						jr1.push_back((int)(boss->y - l1.y));
						jr2.push_back((int)(boss->x - l3.x));
						jr2.push_back((int)(boss->y - l3.y));
						double out, in;
						out = OuterMulti(e1, jr1);
						in = InnerMulti(e1, jr1);
						k1 = (int)(atan2(out, in) * 180 / PI);
						out = OuterMulti(e3, jr2);
						in = InnerMulti(e3, jr2);
						k2 = (int)(atan2(out, in) * 180 / PI);
						if (k1 >= 0 && k1 <= 90 && k2 >= 0 && k2 <= 90){
							hit = true;
						}
						break;
					case 3:
						//レーザーの四辺での判定
						for (int jj = 1; jj < 5; jj++){
							l.clear();
							jr1.clear();
							switch (jj){
							case 1:
								l = e1;
								jr1.push_back((int)(l1.x - boss->x));
								jr1.push_back((int)(l1.y - boss->y));
								break;
							case 2:
								l = e2;
								jr1.push_back((int)(l2.x - boss->x));
								jr1.push_back((int)(l2.y - boss->y));
								break;
							case 3:
								l = e3;
								jr1.push_back((int)(l3.x - boss->x));
								jr1.push_back((int)(l3.y - boss->y));
								break;
							case 4:
								l = e4;
								jr1.push_back((int)(l4.x - boss->x));
								jr1.push_back((int)(l4.y - boss->y));
								break;
							}
							double pw, in;
							in = InnerMulti(l, jr1);
							pw = PowMulti(l);
							k = in / pw;
							if (k > 0 && k < 1){
								pn = PowMulti(jr1) - pow(in, 2.0) / pw;
								if (pn < pow(boss->hitr, 2.0)){
									hit = true;
								}
							}
						}
						break;
					}
					judge++;
				}
				if (hit == true && shot[shotp].imgp == shotdot[1][4] && j.powercount > 2 && shott[shotp].beamed == false){
					shot[shotp].power *= 0.9;//残留していない影ビームは一度命中するたびにパワーが減少する。
				}
			}
			else{
				if (shot[shotp].imgp == shotdot[2][0] || shot[shotp].imgp == shotdot[2][2]){
					//早苗ワイド弾は中心と両端を中心とした三つの円で判定
					double /*dot1,dot2,*/sx, sy, ex, ey, dx, dy;
					sx = shot[shotp].x + cos(shot[shotp].imgangle * PI / 180) * (shot[shotp].imggapp);
					sy = shot[shotp].y + sin(shot[shotp].imgangle * PI / 180) * (shot[shotp].imggapp);
					ex = shot[shotp].x - cos(shot[shotp].imgangle * PI / 180) * (shot[shotp].imggapp);
					ey = shot[shotp].y - sin(shot[shotp].imgangle * PI / 180) * (shot[shotp].imggapp);
					dx = pow(boss->x - sx, 2.0);
					dy = pow(boss->y - sy, 2.0);
					if (dx + dy < pow(hitr + boss->hitr, 2.0)){
						hit = true;
					}
					else{
						dx = pow(boss->x - ex, 2.0);
						dy = pow(boss->y - ey, 2.0);
						if (dx + dy < pow(hitr + boss->hitr, 2.0)){
							hit = true;
						}
						else{
							dx = pow(boss->x - shot[shotp].x, 2.0);
							dy = pow(boss->y - shot[shotp].y, 2.0);
							if (dx + dy < pow(hitr + boss->hitr, 2.0)){
								hit = true;
							}
						}
					}
					/*dx = sx - ex;
					dy = sy - ey;
					dot1 = dx * (teki[p].x - sx) + dy * (teki[p].y - sy);
					if(dot1 < 0){
					if(pow(sx - teki[p].x,2.0) + pow(sy - teki[p].y,2.0) < hitr){
					hit = true;
					}
					}else{
					dot2 = pow(dx,2.0) + pow(dy,2.0);
					if(dot1 > dot2){
					if(pow(ex - teki[p].x,2.0) + pow(ey - teki[p].y,2.0) < pow(hitr,2.0)){
					hit = true;
					}
					}else{
					double dot3 = pow(teki[p].x,2.0) + pow(teki[p].y,2.0);
					if(dot3 - (dot1/dot2) * dot1 < pow(hitr,2.0)){
					hit = true;
					}
					}
					}
					*/
				}
				else{
					//その他のショットは円で判定
					double dx, dy;
					dx = pow(boss->x - shot[shotp].x, 2.0);
					dy = pow(boss->y - shot[shotp].y, 2.0);
					if (shot[shotp].imgp == shotdot[0][2]){
						//低速布都の炎弓弾は判定が大きめ
						hitr = 6;
					}
					if (dx + dy < pow(hitr + boss->hitr, 2.0)){
						hit = true;
					}
				}
			}
			if (hit){
				//ショットが命中
				totaldamage += shot[shotp].power;
				if (j.slow){
					if (flame % 5 == 0){
						s1.eff.RequestSE(s1.eff.se.hit);
					}
				}
				else{
					if (flame % 2 == 0){
						s1.eff.RequestSE(s1.eff.se.hit);
					}
				}
				if (shot[shotp].imgp != shotdot[1][2] && shot[shotp].imgp != shotdot[1][4]){
					Deleteshot(shotp);
				}
				else{
					if (shot[shotp].imgp == shotdot[1][4] && j.powercount > 2 && shott[shotp].beamed == false){
						shot[shotp].power *= 0.9;//残留していない影ビームは一度命中するたびにパワーが減少する。
					}
				}
			}
			hit = false;
			shotp = shot[shotp].np;
		}

		total->hitpoint -= (int)(totaldamage);
	}
	int GrazeJudgement(Danmaku * d){//カスリ判定を行い、カスリ数を返り値として返します。
		int gcount = 0;
		int p = d->dan[0].np;
		while (p != tail && p != 0){
			//X < √{r² - (Y - b)²} + a
			if (d->dan[p].danshu == 15 || d->dan[p].danshu == 16){
				//レーザー弾幕の判定
				int wide, height;//wideは横幅、heightは縦幅
				double area[13][3], fifx, fify;
				GetGraphSize(d->danimg[d->dan[p].danshu][d->dan[p].color], &wide, &height);
				height /= 2;
				area[1][1] = sqrt(pow(height, 2.0)) * cos(d->dan[p].imgangle) + d->dan[p].x;
				area[1][2] = sqrt(pow(height, 2.0)) * sin(d->dan[p].imgangle) + d->dan[p].y;
				area[10][1] = sqrt(pow(height, 2.0) + pow(wide, 2.0)) * cos(d->dan[p].imgangle) + d->dan[p].x;
				area[10][2] = sqrt(pow(height, 2.0) + pow(wide, 2.0))* sin(d->dan[p].imgangle) + d->dan[p].y;
				fifx = (area[10][1] - area[1][1]) / 10;
				fify = (area[10][2] - area[1][2]) / 10;
				for (int f = 2; f < 10; f++){
					area[f][1] = fifx * f + d->dan[p].x;
					area[f][2] = fify * f + d->dan[p].y;
				}
				for (int f = 1; f < 11; f++){
					if (pow(area[f][1] - j.x, 2.0) + pow(area[f][2] - j.y, 2.0) < pow(j.grazer, 2.0)){
						gcount++;
					}
				}
			}
			else{
				if (pow(d->dan[p].x - j.x, 2.0) + pow(d->dan[p].y - j.y, 2.0) < pow(j.grazer + d->danhit[d->dan[p].danshu], 2.0) && d->dan[p].graze == false){
					gcount++;
					d->dan[p].graze = true;
				}
			}
			p = d->dan[p].np;
		}
		return gcount;
	}
	bool Jiki::MissJudgement(Stage * stage){
		//敵位置における当たり判定を行います。falseの時はセーフ,trueの時はミスになります。
		int p = stage->teki[0].np;
		int r;
		while (p != stage->tail && stage->missnothit == 0){
			if (stage->teki[p].tekishu < 5){//赤～緑妖精
				r = 7;
			}
			else{
				if (stage->teki[p].tekishu == 5){//ひまわり妖精
					r = 9;
				}
				else{//綿毛
					r = 5;
				}
			}
			if (sqrt(pow(stage->teki[p].x - j.x, 2.0) + pow(stage->teki[p].y - j.y, 2.0)) < r + j.hitr){
				return true;
			}
			p = stage->teki[p].np;
		}
		return false;
	}
	bool MissJudgement(Danmaku * d){
		//自機に対するあたり判定を行います。falseの時はセーフで、trueが返されたらミスとなります。
		int p = d->dan[0].np;
		double judge = 0;
		while (p != d->tail && d->dancount > 0){
			//Y =√{r² - (X - a)²} + b
			if (d->dan[p].danshu == 15 || d->dan[p].danshu == 16){
				//レーザー弾幕の判定
				int wide, height;//wideは横幅、heightは縦幅
				GetGraphSize(d->danimg[d->dan[p].danshu][d->dan[p].color], &wide, &height);
				wide /= 2;
				double area[13][3],fifx,fify;
				
				area[1][1] = sqrt(pow(height, 2.0)) * cos(d->dan[p].imgangle) + d->dan[p].x;
				area[1][2] = sqrt(pow(height, 2.0)) * sin(d->dan[p].imgangle)  + d->dan[p].y;
				area[10][1] = sqrt(pow(height, 2.0) + pow(wide, 2.0)) * cos(d->dan[p].imgangle)+ d->dan[p].x;
				area[10][2] = sqrt(pow(height, 2.0) + pow(wide, 2.0)) * sin(d->dan[p].imgangle) + d->dan[p].y;
				fifx = (area[10][1] - area[1][1]) / 10;
				fify = (area[10][2] - area[1][2]) / 10;
				for (int f = 2; f < 10; f++){
					area[f][1] = fifx * f + area[1][1];
					area[f][2] = fify * f + area[1][2];
				}
				for (int f = 1; f < 11; f++){
					area[f][1] -= fifx * 5;
					area[f][2] -= fify * 5;
				}
				for (int f = 1; f < 11; f++){
					double r = pow(area[f][1] - j.x, 2.0) + pow(area[f][2] - j.y, 2.0);
					if (r < pow(j.hitr + height / 2 ,2.0)){
						return true;
						DrawString(450, 100, "Miss!!", GetColor(255, 255, 255), 0);
					}
				}
			}
			else{
				//その他の弾幕の判定
				judge = sqrt(pow((int)(d->dan[p].x) - j.x, 2.0) + pow((int)(d->dan[p].y) - j.y, 2.0));
				if (judge < j.hitr + d->danhit[d->dan[p].danshu]){
					d->ClearDanmaku();
					return true;
				}
			}
			
			p = d->dan[p].np;
		}
		return false;
	}
	int Jiki::MissEffect(Stage *stage){
		int r = 0;
		stage->missflame++;
		if (stage->missflame == 2){
			if (j.extendcount < 0){

				stage->SetFullItem(j.x, j.y);
			}
			else{
				int up;
				if (j.y > 350){
					up = -100;
				}
				else{
					up = 0;
				}
				stage->SetItem(j.x, j.y + up, 0, 10, 0);
			}
		}
		if (stage->missflame == 120){//ミスしてから2秒後に操作可能となる。
			stage->Miss = false;
			stage->SpellBonusScore = 0;
			stage->missnothit = 180;
			//stage->Currenttime += 1;
			j.x = 180;
			j.y = 410;
			j.powercount--;
			if (j.power < 16){
				j.power = 0;
				j.powercount = 1;
			}
			else{
				if (j.power < 32){
					j.power = 15;
				}
				else{
					if (j.power < 64){
						j.power = 31;
					}
					else{
						if (j.power < 128){
							j.power = 63;
						}
						else{
							j.power = 96;
						}
					}
				}
			}
			if (j.extendcount < 0){ r = 8; }//残機がマイナスになったらゲームオーバー
		}
		return r;
	}
	bool Jiki::BossMissJudgement(double bx, double by, int br, Stage * stage){
		if (stage->missnothit == 0 && sqrt(pow(bx - j.x, 2.0) + pow(by - j.y, 2.0)) < br + j.hitr){
			return true;
		}
		return false;
	}
	double Jiki::InnerMulti(const vector<int>&a,const vector<int>&b){
		return a[0] * b[0] + a[1] * b[1];
	}
	double Jiki::OuterMulti(const vector<int>&a, const vector<int>&b){
		return a[0] * b[1] - a[1] * b[0];
	}
	double Jiki::PowMulti(const vector<int>&a){
		return a[0] * a[0] + a[1] * a[1];
	}
	void Jiki::TukaimaCheckHoming(Stage* stage){//ホーミング弾に対する処理の必要性を判断し、正ならその処理をします。
		int searchr = 0;
		int p = stage->tukaima[0].np;
		int endf, shotp, shortestp;
		double shortestr = 0;
		double r = 0;

		if (jikinum == 0 && shotcount > 0){
			//ホーミング弾のサーチ範囲はパワー段階に応じて広くなる。
			searchr = 155 + (j.powercount - 1) * 25;
		}
		shotp = shot[0].np;
		while (shotp != tail && shotcount > 0 && stage->tekicount > 0){
			if (shot[shotp].imgp == shotdot[0][1] && shott[shotp].sethoming == false){
				endf = 0;
				p = stage->tukaima[0].np;
			}
			else{
				endf = 100;
				if (shott[shotp].sethoming && shott[shotp].homingp > 0){
					double dx = shot[shotp].x - stage->tukaima[shott[shotp].homingp].x;
					double dy = shot[shotp].y - stage->tukaima[shott[shotp].homingp].y;
					double angle = atan2(dy, dx);
					if (sqrt(pow(dx, 2.0) + pow(dy, 2.0)) > 8){
						shot[shotp].vecx = cos(angle) * -8;
						shot[shotp].vecy = sin(angle) * -8;
					}
					else{
						//レンジ8以内まで追跡したらhit確実とする。
						shott[shotp].hit = true;
					}
				}
			}
			shortestr = 1000;
			while (endf == 0){
				r = sqrt(pow(shot[shotp].x - stage->tukaima[p].x, 2.0) + pow(shot[shotp].y - stage->tukaima[p].y, 2.0));
				if (r < shortestr && r < searchr && stage->tukaima[p].ready == 0 && stage->tukaima[p].imgposi != 0){//ショットに最も近く、かつサーチ範囲内の時
					shortestp = p;
					shortestr = r;
				}
				p = stage->tukaima[p].np;
				if (p == stage->ttail){ endf = 100; }
			}
			if (shortestr != 1000){
				shott[shotp].homingp = shortestp;
				shott[shotp].sethoming = true;
				double dx = shot[shotp].x - stage->tukaima[shott[shotp].homingp].x;
				double dy = shot[shotp].y - stage->tukaima[shott[shotp].homingp].y;
				double angle = atan2(dy, dx);
				if (sqrt(pow(dx, 2.0) + pow(dy, 2.0)) > 8){
					shot[shotp].vecx = cos(angle) * -8;
					shot[shotp].vecy = sin(angle) * -8;
				}
			}
			shotp = shot[shotp].np;
		}
	}
	void Jiki::TukaimaHitJudgement(int flame, Stage *stage){
		//自機のショットが敵に当たるかどうかを判断する関数です。ショットが当たると敵のHPを減らし、0になれば撃沈の処理をします。また当たればtrueを返して終了します。
		int p = stage->tukaima[0].np;
		int shotp;
		int endf;
		if (stage->tekicount > 0 && shotcount > 0){
			endf = 0;
		}
		else{
			endf = 100;
		}
		int shotendf = 0;
		int judger;
		int hitr = 4;//ショットのあたり判定は特殊なものを除き半径4の円で行うものとする。
		bool hit;//ショットが敵にヒットしたかどうかを示す変数です。ショットごとに異なる判定方法で判断します。
		double dx, dy;
		while (endf == 0){
			judger = 10;
			shotp = shot[0].np;
			while (shotp != tail && shotcount > 0 && stage->tukaima[p].ready == 0){
				hit = false;
				if (shot[shotp].imgp == shotdot[1][2] || shot[shotp].imgp == shotdot[1][4]){
					//低速魅魔のビーム弾は円と範囲で判定 && 
					if ((stage->tukaima[p].x > shot[shotp].x - shot[shotp].imggapp && stage->tukaima[p].x < shot[shotp].x - shot[shotp].imggapp + 17) || (stage->tukaima[p].x < shot[shotp].x && stage->tukaima[p].x + judger > shot[shotp].x - shot[shotp].imggapp) || (stage->tukaima[p].x >= shot[shotp].x && stage->tukaima[p].x - judger < shot[shotp].x - shot[shotp].imggapp + 17)){
						//敵判定円の左右端がショットの右端・左端線にまたがっているとき
						if (stage->tukaima[p].y > shot[shotp].y - shot[shotp].imggapp && stage->tukaima[p].y < shot[shotp].y - shot[shotp].imggapp + 69){
							//敵判定円の中心がショットの上下端の間にあるとき
							hit = true;
						}
					}
				}
				else{
					if (shot[shotp].imgp == shotdot[2][0] || shot[shotp].imgp == shotdot[2][2]){
						//早苗ワイド弾は中心と両端を中心とした三つの円で判定
						double /*dot1,dot2,*/sx, sy, ex, ey;
						sx = shot[shotp].x + cos(shot[shotp].imgangle * PI / 180) * (shot[shotp].imggapp);
						sy = shot[shotp].y + sin(shot[shotp].imgangle * PI / 180) * (shot[shotp].imggapp);
						ex = shot[shotp].x - cos(shot[shotp].imgangle * PI / 180) * (shot[shotp].imggapp);
						ey = shot[shotp].y - sin(shot[shotp].imgangle * PI / 180) * (shot[shotp].imggapp);
						dx = pow(stage->tukaima[p].x - sx, 2.0);
						dy = pow(stage->tukaima[p].y - sy, 2.0);
						if (dx + dy < pow(hitr + judger, 2.0)){
							hit = true;
						}
						else{
							dx = pow(stage->tukaima[p].x - ex, 2.0);
							dy = pow(stage->tukaima[p].y - ey, 2.0);
							if (dx + dy < pow(hitr + judger, 2.0)){
								hit = true;
							}
							else{
								dx = pow(stage->tukaima[p].x - shot[shotp].x, 2.0);
								dy = pow(stage->tukaima[p].y - shot[shotp].y, 2.0);
								if (dx + dy < pow(hitr + judger, 2.0)){
									hit = true;
								}
							}
						}
						/*dx = sx - ex;
						dy = sy - ey;
						dot1 = dx * (teki[p].x - sx) + dy * (teki[p].y - sy);
						if(dot1 < 0){
						if(pow(sx - teki[p].x,2.0) + pow(sy - teki[p].y,2.0) < hitr){
						hit = true;
						}
						}else{
						dot2 = pow(dx,2.0) + pow(dy,2.0);
						if(dot1 > dot2){
						if(pow(ex - teki[p].x,2.0) + pow(ey - teki[p].y,2.0) < pow(hitr,2.0)){
						hit = true;
						}
						}else{
						double dot3 = pow(teki[p].x,2.0) + pow(teki[p].y,2.0);
						if(dot3 - (dot1/dot2) * dot1 < pow(hitr,2.0)){
						hit = true;
						}
						}
						}
						*/
					}
					else{
						//その他のショットは円で判定
						dx = pow(stage->tukaima[p].x - shot[shotp].x, 2.0);
						dy = pow(stage->tukaima[p].y - shot[shotp].y, 2.0);
						if (shot[shotp].imgp == shotdot[0][2]){
							//低速布都の炎弓弾は判定が大きめ
							hitr = 6;
							judger = 30;
						}
						if (dx + dy < pow(hitr + judger, 2.0) || (shot[shotp].imgp == shotdot[0][1] && shott[shotp].hit)){
							hit = true;
						}
					}
				}
				if (hit && stage->tukaima[p].hitpoint > 0){
					//ショットが命中
					if (shot[shotp].imgp != shotdot[1][2] && shot[shotp].imgp != shotdot[1][4]){
						Deleteshot(shotp);
					}
					stage->tukaima[p].hitpoint -= shot[shotp].power;
					if (stage->tukaima[p].hitpoint < 1 && stage->tukaima[p].hitpoint != -100){
						//敵撃墜
						stage->tukaima[p].hitpoint = -100;
						stage->SetItem(stage->tukaima[p].x, stage->tukaima[p].y, flame, stage->tukaima[p].poweritem, stage->tukaima[p].tenitem);
						stage->DeleteTukaima(p);
						shotendf = 100;
					}
				}
				shotp = shot[shotp].np;
			}
			p = stage->tukaima[p].np;
			if (p == stage->ttail){ endf = 100; }
		}
	}

	void Jiki::LoadRecord(){
		if (1){//各自機の記録内に全面クリアの記録があった場合
			FinalChoice = true;
		}
		else{
			FinalChoice = false;
		}
	}

	struct jiki{
		int x;
		int y;
		double vecx;//X軸方向への移動速度を示す変数です。自機によって異なります。
		double vecy;//Y軸方向への移動速度を示す変数です。自機によって異なります。
		int hitr;//当たり判定に使われる変数です。自機によって異なります。
		int grazer;//グレーズ（カスリ）判定に使われる変数です。自機によって異なります。
		int itemr;//アイテム回収判定に使われる変数です。自機によって異なります。
		int dotimg;//ドット絵の画像変数です。
		int bombstand;//ボム発動時の立ち絵を示す画像変数です。
		int powercount;//パワー段階を示す変数です。
		int power;//パワーアイテムのカウント数です。128を上限とし、16,32,64,128の時にパワーアップします。
		int bombcount;//ボム所持数を示す変数です。
		int extendcount;//残機数を示す変数です。
		bool slow;//低速移動中か否かを示す変数です。True = 低速移動 False = 高速移動

	};
	jiki j;
	struct PlayerData{
		char* partner;//このゲームで選ばれた自機 Futo Mima Sanae Sakuyaのいずれか
		int difficulty;//ゲームの難易度。1.easy 2.normal 3.hard 4.lunatic 5.extra
		int choicestage;//選択したステージ。PracticeModeのみ入力される。GameMode時は0。
		int currentstage;//現在いるステージを示す変数。1.Stage1 … 9.Stage6A 10.Stage6B(cr参照)とする。PracticeModeでは0。
	};
	PlayerData Data;
	
	short tail;
	struct sh{
		double x;
		double y;
		double vecx;
		double vecy;
		int imgp;
		int imgangle;
		int imggapp;
		double power;
		int pp;
		int np;
		int flamebetween;

	};

	sh shot[SHOTLIMIT];//rootはshot[0].np、tailはshot[p].np = 0となるpの次のポインタとする。
	struct sht{
		bool slow;//早苗ワイド弾のみ使われる、低速時に発射したかどうかを示す変数です。
		bool slowcancel;//魅魔ビーム弾のみ使われる、低速から高速に切り替えたかを示す変数です。一度切り替えられるとビーム弾は自機に合わせて移動しなくなります。
		bool beamed;//魅魔ビーム弾のみ使われる、自機のスライドによる残留ビームか否かを示す変数です。trueの場合はそのビームを基に新しく残留ビームは作られません。
		int changed;//早苗ワイド弾のみ使われる、方向転換してからのフレーム数を示す変数です。2未満のときは方向転換しません。
		double homingx;
		double homingy;
		int homingp;//ホーミング先のポインタを示す変数です。Stageクラスのteki[]構造体の添え字になります。またボスへホーミングする場合は1000(二体いる場合はより遠いほうが2000になります。
		bool sethoming;//ホーミング先を設定したかどうかのフラグです。trueで設定済み
		bool whichset;
		bool hit;//布都ホーミング弾のみ使われる、ショットが確実に敵に当たるかどうかを示す変数です。CheckHomingにおいて一定範囲内までチェイスすればtrueになります。
	};
	sht shott[SHOTLIMIT];
	int shotdot[4][5];
	short continuecount;//ゲーム中のコンティニュー数をカウントする変数です。コンティニューの有無によって進めるステージが変化します。
	short shotcount;
	short jikinum;//ゲーム中の自機を識別する変数です。0.布都　1.魅魔　2.早苗　3.咲夜
	int jikistand[4][15];//[jikijum][1.common,2.fine,3.question,4.doubt,5.angry,6.surprised,7.amazed(呆れる),8.excited,9.strategy]
	bool FinalChoice;//ラストステージを選択できるかどうかを示す変数です。LoadRecordにてClear(全面クリア)の記録があった時のみファイナル分岐を選択できます。
	bool  debuging;
private:

	int dot[4][4];
	//       common,left,right,bomb1
	//futo
	//mima
	//sanae
	//sakyya
	//自機
	struct sd{
		double x;
		double y;//このx,yはショットの貼り付け位置ではなくj.x,j.yを中心とした調整数を示す。したがってshot[p].x = j.x + shotdata[0][1].xという形式をとる。
		double vecx;
		double vecy;
		double power;
		int imgp;
		int imggapp;
		int imgangle;
		int flamebetween;
		int shotbetween;//ショットを発射するかどうかを判断する変数です。shot構造体にコピーされることはなく、SetShot関数でフレーム数との商の余りが0の時に発射を決定します。

	};
	sd shotdata[8][6][15];
	//最初の添え字は自機区分(+4は低速時のショットデータを示す)、次の添え字はパワー段階、次の添え字はショットデータを示す。したがって次のショットデータがなければSetshotは終了する。また[x][0].xは一回に発射されるショットの総数を示す。
	short preleft, preright;//前回処理時の左右方向入力状態を保持する変数です。魅魔ビーム弾の処理時に使われます。
	/*      shot1,shot2,shot3,option
	//futo
	//1.矢(高速ショットでいずれもまっすぐ進む。正面から発射。1way(正面)→3way(+正面±5x)→5way	→→7way(+∓30度))
	//2.火(高速ショットでホーミング機能がある。オプションから発射。2way→4way→→6way→8way)
	//3.赤矢(低速ショット。正面から発射。パワーに応じて速度と火力がアップするが範囲が狭い。4/f→2/f→→→1/f)
	//op.皿(低速時:黒　高速時は青)

	//mima
	//1.ミサイル(火力が高い高速ショット。1way(正面発射のみ)→2way(正面発射二つ±5x)→3way(正面一つ、±80度発射)→4way(正面二つ、±80度発射)→5way(正面三つx,±5x,±80度発射))
	//2.魂弾(高速ショット。オプションから発射され、パワーに応じて火力が上がる。)
	//3.ビーム(低速ショットで正面から発射される。範囲は狭いがパワーに応じて火力が増える。したがって低高速切り替えによるマリス砲が可能。)
	//4.残留ビーム(低速ショットで正面から発射されるが赤ビームとかぶっている。自機が左右に移動するまでパワーは0だが左右に動くことで出現しパワーを得る。
	また赤ビームと違って自機に合わせて左右に移動することはない。パワー第二段階から出現。)
	//op.霊魂(低高速やパワーによる変化はなし。)

	//sanae
	//1.広域ワイド弾(高速時は最大で正面+±20度方向の3way、低速時は最大で正面x2wayまで増える。正面1way→→正面2way→→→)
	//2.緑弾(威力は低いが低高速ともに正面から2wayで発射される。パワーに応じて火力が少し上がる。)
	//3.ワイド弾(オプションから発射される。高速時は最大で10way、低速時は最大で4wayでジグザグに進む。
	2way(±50度)→4way(±50度+±75度)→6way(正面2way+±50度+±75度)→8way(正面2way+∓10度+±20度(自機後方へ発射)+±50度)→10way(正面+∓40度+±10度+±20度+±50度)
	,2way(∓50度)→→→4way(∓50度+正面から±30度)→)
	//op.御印(神霊廟時と同じオプション。)

	//sakuya
	//1.青ナイフ(いずれもまっすぐ進み、正面から発射される。移動方向低速の影響を受けない。1way→2way→→3way→4way)
	//2.紫ナイフ(基本はまっすぐ進むが左右移動に応じて発射方向が変わる。また低速移動になると発射方向が固定される。オプションから発射。2way→4way→6way→→8way)
	//3.なし
	//op.マジカル☆咲夜ちゃんスター(妖々夢時と同じオプション。基本は両隣りだが移動方向と垂直に位置が変化し、低速になると移動方向の正面前に位置が変わる。)*/
	int futoop2;//低速移動時のオプション画像の変数。布都のみ。
	double sakuyaopkakudo;//左右移動時にオプションの位置が変わるため傾きの角度を保持する変数。咲夜のみ。
	short slowkakudo;
	char* JikiName;//ゲーム中の自機の名前です。Stage1～6Bクラスから受け取ります。


	int bombicon[2];//0.count 1.empty 
	int zankiicon[2];//0.count 1.empty
	int num[10];//スコア表示に使われる数字画像を示す変数です。添え字が数字に当たります。
	int totalscore[10];//ゲーム中で稼いだスコアの合計を示す変数です。添え字は桁目を示し、10以上になると繰り上がります。またこの数字がレコードに載ります。
	int totalgraze;//ゲーム中のカスリ数合計を示す変数です。countgrazeの総和
	int countscore[10];//ステージごとに計算されたスコアを保持する変数です。レコードには載りません。
	int grazecount;
	bool RefreshStop;//DanmakuRefreshをストップさせる変数です。trueの場合にDanmakuRefreshは行われません。この時は各ステージのProcess○○で行われます。
	bool doublebuttle;//ボス戦が2対1で行われるかどうかを示す変数です。trueの時は敵の当たり判定や処理が異なります。
	vector<int>e1;
	vector<int>e2;
	vector<int>e3;
	vector<int>e4;
	vector<int>jr1;
	vector<int>jr2;
	vector<int>jn;
	vector<int>l;
	
};
class Game{
public:
	Jiki jiki;
	Controlar ctrl;
	
	int cr;//ゲームの進行状況を大まかに示した変数。
	    /*
		0.Titleへ戻る
		1.Game Mode
		2.Practice Mode
		3.Replay Mode
		8.Gameover
		9.Set Record
		10.Porse
		100.Ending StuffRoll?※Jikiへ移動させるか検討中
		*/
	Game::Game(){//Gameクラスのコントラクタです。
		//ここで初期値の設定やゲームオーバー・エンディング・スタッフロール等で使う画像などを読み込みます。
	   jiki.ClearData();
	   cr = 0;
	   goselect = 1;
	   int r;
	   white = GetColor(254,254,254);
	   r = _chdir("data");
	   r = _chdir("img");
	   r = _chdir("Game");
	   goimg = LoadGraph("Gameover.bmp");
	   r = _chdir("..");
	   r = _chdir("..");
	   r = _chdir("..");
	}
	int Game::play(){
		//ゲームプレイ時に必ず通る関数です。ここからゲーム進行に応じて分岐します。
		//ゲームプレイ中はここでフレームを回し(60fpsとする)、playの終了とともにTitleへ戻ります(エラーがなければ0を返します)。
		int r = 1;//返り値を示す変数。基本はGameクラス内のループを抜ける = Titleに戻ると0になりますが何らかのエラーが起こると-1になります。 
		int sum;//フレームカウント。ゲームプレイ中はGameクラスでfpsの計測をする。sumはフレームカウントの合計とする。
		int Endflg = 0;//ゲームオーバーやポーズなどによるゲーム終了を制御する変数です。これが100になることでタイトルに戻ります。
		int Begintime,Resttime,Nexttime,s;//fpsの計測に必要な変数です。
		float fps = 0.0;
		s = 0;
		fps = 0;
		sum = 0;
		int precr = cr;
		while(Endflg == 0){
			flamecount = 1;
		    Begintime = GetNowCount();
	        Resttime = 0;
		    while(ClearDrawScreen() == 0 && ProcessMessage() == 0 &&  flamecount < 61 && Endflg == 0 && GetNowCount() - Begintime < 1000 && r != -1){
				DrawGraph(0, 0, foundation, false);
				ctrl.GetCondition();
				if(ctrl.GetButton("porse") > 0 && cr != 10){
					porsecr = cr;
					cr = 10;
					porseflame = flamecount;
					porseselect = 1;
					if(jiki.ongaku.PorseMusic() != 0){Endflg = -1;}
				}
				switch (cr){
				case 0://タイトルに戻る
					Endflg = 100;
					r = 0;
					break;
				case 1://Game Mode
					cr = jiki.ProcessGame(flamecount);
					break;
				case 2://Practice Mode
					cr = jiki.ProcessGame(flamecount);
					break;
				case 8://ゲームオーバー
					cr = Gameover(precr);
					break;
				case 9://レコード登録
					break;
				case 10://ポーズ
					cr = porse();
					break;
				case 100://エンディング・スタッフロール等
					break;
				default://それ以外
					r = -1;
					break;
				}
				if(cr != 8){
					precr = cr;
				}
			    if(flamecount % 3 == 0 && flamecount != 0){
				    Resttime = GetNowCount() - Begintime - (50 * (flamecount - 1) / 3); 
				}
				sum++;
		        if(/*DrawFormatString(500,410,white,"flamecount  %d",s) != 0 || */DrawFormatString(500,430,white,"fps  %f",fps) != 0/* || DrawFormatString(500,450,white,"Resttime  %d",Resttime) != 0*/){
			        Endflg = -1;
			    }
			    flamecount++;
				
			    if(ScreenFlip() != 0 || r == -1){
					Endflg = -1;
				}
		    }
			s = flamecount - 1;
			
		    Nexttime = GetNowCount();
		    Resttime = Nexttime - Begintime;
		    fps = 1000.f/((Nexttime - Begintime)/(float)60);
		}
		return r;
	};
	int Game::porse(){
	    int r = 10;
		int white = GetColor(255,255,255);
		int glay = GetColor(100,100,100);
		int porsecolor = white;
		int sy = 220;
		char* select;
		if(ctrl.GetButton("cancel_bomb") == 1){
			jiki.s1.eff.RequestSE(jiki.s1.eff.se.cancel);
			r = porsecr;
			if (jiki.ongaku.PorseCancel() != 0){ r = -1; }
		}
		if(ctrl.GetButton("up") == 1){
			jiki.s1.eff.RequestSE(jiki.s1.eff.se.select);
			porseselect -= 1;
			if(porseselect == 0){porseselect = 3;}
		}
		if(ctrl.GetButton("down") == 1){
			jiki.s1.eff.RequestSE(jiki.s1.eff.se.select);
			porseselect += 1;
			if(porseselect == 4){porseselect = 1;}
		}
		if(ctrl.GetButton("ok_shot") == 1){
			jiki.s1.eff.RequestSE(jiki.s1.eff.se.decide);
			switch (porseselect){
			case 1://ゲームを続ける
				flamecount = porseflame;
				r = porsecr;
				if (jiki.ongaku.PorseCancel() != 0){ r = -1; }
				break;
			case 2://タイトルへ戻る。
				r = 0;
				jiki.ClearData();
				break;
			case 3:
				r = jiki.StageStart(jiki.Data.choicestage);

				break;
			}

		}
		while(sy != 280 && r != porsecr){
			select = 0;
			switch(sy){
			    case 220:
				    select = "ゲームを続ける";
				    break;
			    case 240:
				    select = "タイトルに戻る";
				    break;
			    case 260:
				    select = "最初から始める";
			        break;
				default:
				    r = -1;
				    break;
			}
			if((sy - 200) / 20 == porseselect){
				porsecolor = white;
			}else{
				porsecolor = glay;
			}
			if(DrawString(200,sy,select,porsecolor) != 0){r = -1;}
		    sy += 20;
		}
		return r;
	}
	int Game::Gameover(int precr){
		int r = 8;
		if(CheckSoundMem(jiki.ongaku.CurrentBGM) == 1){
			if(jiki.ongaku.PorseMusic() != 0){
				return -1;
			}
		}
		if(ctrl.GetButton("up") == 1 && goselect != 1){
			goselect--;
		}
		if(ctrl.GetButton("down") == 1 && goselect != 4){
			goselect++;
		}
		if(ctrl.GetButton("ok_shot") == 1){
			switch(goselect){
				case 1://コンティニューする
					r = precr;
					int ccr;
					if(precr > 10){
						ccr = precr - 10;
					}else{
						ccr = precr;
					}
					jiki.SetContinue();
					jiki.ongaku.PorseCancel();
					break;
				case 2://タイトルに戻る。
					r = jiki.ongaku.RequestMusic(0);
					jiki.ClearData();
					r = 0;
					break;
				case 3://リプレイデータを保存する。
					break;
				case 4://最初からはじめる。
					r = jiki.StageStart(jiki.Data.choicestage);
					break;
			}
		}
		char* selection;
		int go;
		int font;
		DrawGraph(0,0,goimg,false);
		int goy = 200;
		for(go = 1;go < 5;go++){
			if(go == goselect){
				font = GetColor(255,255,255);
			}else{
				font = GetColor(100,100,100);
			}
			selection = "";
			switch(go){
				case 1:
					selection = "コンティニューする";
					break;
				case 2:
					selection = "タイトルに戻る";
					break;
				case 3:
					selection = "リプレイデータを保存する";
					break;
				case 4:
					selection = "最初からやり直す";
					break;
			}
			DrawString(100,goy,selection,font,false);
			goy += 20;
		}
		if (r == -1){
			r = -1;
		}
		return r;
	}
	void Game::Set_partner(char* name, int back){
		jiki.Set_partner(name);
		foundation = back;
	}

		
private:
	int white;
	int porseselect;//ポーズ中の選択肢を示す変数です。1.ゲームを続ける 2.タイトルに戻る 3.最初から始める
	int porsecr;//ポーズした時のゲームの進行具合を保持する変数です。ポーズした時にcrからコピーされ、解除されるとcrに戻ります。
	int porseflame,flamecount;
	int goselect;
	int goimg;//ゲームオーバー画面の背景画像を保持する変数です。Gameコントラクタで読み込まれ、Gameoverで使われます。
	int foundation;//基本背景
	
};
class Title{
public:
	Game gm;
	Title::Title(){
		int r;
		char dir[255];
		GetCurrentDirectory(255, dir);
		r = _chdir("data");
		r = _chdir("img");
		r = _chdir("Title");
	    holizon.home = LoadGraph("Title.bmp");
		holizon.foundation = LoadGraph("FoundationBack.bmp");
		holizon.titlestand = LoadGraph("TitleStand.bmp");
		holizon.choosedif = LoadGraph("Choose difficulty.bmp");
		holizon.choosestage = LoadGraph("Choosestage.bmp");
		holizon.choosepartner = LoadGraph("Choose your partner.bmp");
		holizon.select = LoadGraph("Select.bmp");
		holizon.decided = LoadGraph("Decided.bmp");
		holizon.Futo1 = LoadGraph("Futo1.bmp");
		holizon.Mima1 = LoadGraph("Mima1.bmp");
		holizon.Sanae1 = LoadGraph("Sanae1.bmp");
		holizon.Sakuya1 = LoadGraph("Sakuya1.bmp");
		holizon.Futo2 = LoadGraph("Futo2.bmp");
		holizon.Mima2 = LoadGraph("Mima2.bmp");
		holizon.Sanae2 = LoadGraph("Sanae2.bmp");
		holizon.Sakuya2 = LoadGraph("Sakuya2.bmp");
		holizon.Futo3 = LoadGraph("FoundationFutoBack.bmp");
		holizon.Mima3 = LoadGraph("FoundationMimaBack.bmp");
		holizon.Sanae3 = LoadGraph("FoundationSanaeBack.bmp");
		holizon.Sakuya3 = LoadGraph("FoundationSakuyaBack.bmp");
		holizon.music = LoadGraph("Music Room.bmp");
		holizon.option = LoadGraph("Option.bmp");
		/* 
		holizon.home2 = LoadGraph("Title2.bmp");
		
		
		*/
		//背景画像読み込み
		r = _chdir("..");
		r = _chdir("..");
		r = _chdir("..");
		
		cr = 1;
		select = 1;
		decided = 0;
	}	
	int Title::th3i(){
    /*
	int talk;
	*/
	gm.jiki.ongaku.SetMusicPlayable(true);//デバッグ用
	int Begintime,Resttime,Nexttime;
	int Current;//現在のゲームの状態を表します。0～タイトル周辺　1～Game Mode　2～Practice Mode 
	           //3～ゲームその他の状態(ポーズ、ゲームオーバーなど) 4～Ending Staff Roll 
	int oldCurrent;//変更される前の保存用の変数。これが変化したらMusicを変更する。
	int f,Endflg;
	int flamecount,sum,s,prefps;
	float fps = 0.0;
	int white = GetColor(254,254,254);
	int black = GetColor(0,0,0);
	f = 0;
	s = 0;
	sum = 0;
	prefps = 0;
	Endflg = 0;
	Current = 0;
	sx = 419;
	sy = 239;
	Begintime = GetNowCount();
	if (CheckHitKey(KEY_INPUT_M) == 1){
		gm.jiki.s1.eff.SEVolume = 0;
		gm.jiki.s2.eff.SEVolume = 0;
		gm.jiki.s3.eff.SEVolume = 0;
		gm.jiki.s4.eff.SEVolume = 0;
		//gm.jiki.s5.eff.SEVolume = 0;
		//gm.jiki.s6a.eff.SEVolume = 0;
		//gm.jiki.s6b.eff.SEVolume = 0;
		gm.jiki.ongaku.BGMVolume = 0;
		gm.jiki.debuging = true;
	}
	else {
		gm.jiki.debuging = false;
	}
	if (SetDrawScreen(DX_SCREEN_BACK) != 0 || gm.jiki.ongaku.RequestMusic(0) != 0){
	     Endflg = -1;
		 DrawFormatString(100,100,white,"失敗");
		 WaitKey();
	     return -1; 
	     }
	
	while(Endflg == 0){
        flamecount = 1;
		Begintime = GetNowCount();
	    Resttime = 0;
		while(ClearDrawScreen() == 0 && ProcessMessage() == 0 && flamecount < 61 && Endflg == 0 && GetNowCount() - Begintime < 1000){
			/*
			　タイトル周辺ではこの間でフレームを回す。
			*/ 
			DrawGraph(0, 0, holizon.foundation, false);
			oldCurrent = Current;
			gm.ctrl.GetCondition();
			switch(Current){
			case 0://タイトル周辺 Titleクラス内で処理をする。
				if(s > 0){
					Current = Home();
				}else{
					DrawExtendGraph(0,115,259,469,holizon.titlestand,true);
					DrawGraph(0,0,holizon.home,true);					
				}
				break;
				//以下はGameクラス内でフレームを回すためリセットされる。
			case 1://Game Mode
				Current = gm.play();//ゲームの進行状況によって変化する。
				sx = 419;
				sy = 239;
				select = 1;
				break;
			case 2://Practice Mode
				Current = gm.play();//ゲームの進行状況によって変化する。
				sx = 419;
				sy = 269;
				select = 2;
				break;
			case 100://通常終了
				Endflg = 100;
				break;
			default://それ以外は強制終了
				Endflg = -1;
				flamecount = 61;
				break;
			}
			if(oldCurrent != Current){//ゲーム状況が変化。変化していない時はBGMは鳴り続けている。
		    	//TRUE時は音楽は止まっている。	
			    if(Current == 0){
					cr = 1;
					if (gm.jiki.ongaku.RequestMusic(0) != 0){//タイトルへ進んだ時にタイトル曲を流す。
						Endflg = -1;
					}
				};
			}else{
				/*if(DrawFormatString(2,10,white,"flamecount  %d",s) != 0 || DrawFormatString(2,30,white,"fps  %f",fps) != 0 || DrawFormatString(2,50,white,"Resttime  %d",Resttime) != 0){
			        Endflg = -1;
			    }*/
			}
			if(flamecount % 3 == 0 && flamecount != 0 && oldCurrent == Current){
				Resttime = GetNowCount() - Begintime - (50 * (flamecount - 1) / 3); 
				if(Resttime > 0 && Resttime < 1500){ WaitTimer(Resttime);}
			}
			flamecount++;
			if(ScreenFlip() != 0){Endflg = -1;} 
		}
		s += flamecount - 1;
		Nexttime = GetNowCount();
		Resttime = Nexttime - Begintime;
		fps = 1000.f/((Nexttime - Begintime)/(float)(60));
		/*
		if(Resttime > 0){
		    WaitTimer(Resttime);
		};
		*/
		
		
	}
	
	return 0;
	};
	int Title::Home(){//タイトル内での処理をします。
	    int r = 0;//返り値(Current)を表します。初期値は0(タイトル周辺のまま)でゲーム進行により1,2などに変化します。
		
		if((cr > 10 && cr < 15) || (cr > 20 && cr < 25)){
		   r = ChooseYourPartner(yoyaku);
		}else{
		   switch(cr){
		   case 1://タイトル画面
			    /*select詳細
			    1 Game Mode cr = 2へ
			    2 Practice Mode cr = 4へ
			    3 Replay cr = 7へ
			    4 Result　cr = 8へ
			    5 Music Room cr = 9へ
			    6 Option cr = 10へ
			    7 Exit cr = 100へ(ゲーム終了)
			    */
			    if(decided == 0){
			        if(gm.ctrl.GetButton("down") == 1 ){
					    if(select < 7){
					        select += 1;
				            sy += 30;
					    }else{
						    select = 1;
						    sy = 239;
				        }
						gm.jiki.s1.eff.RequestSE(gm.jiki.s1.eff.se.select);
				    }
				    if(gm.ctrl.GetButton("up") == 1){
					    if(select > 1){
					        select -= 1;
				            sy -= 30;
					    }else{
						    select = 7;
						    sy = 419;
					    }
						gm.jiki.s1.eff.RequestSE(gm.jiki.s1.eff.se.select);
				    }
					
				}
				if(gm.ctrl.GetButton("ok_shot") == 1 && decided == 0){
					decided = 30;
					gm.jiki.s1.eff.RequestSE(gm.jiki.s1.eff.se.decide);
					switch(select){
					case 1://Game Mode
						yoyaku = 2;
					    break;
					case 2://Practice Mode
						yoyaku = 4;
						break;
					/*
					case 3://Replay
					    yoyaku = 7;
						break;
						*//*
					case 4://Result
					    yoyaku = 8;
						break;
					*/
					case 5://Music Room
						yoyaku = 9;
						break;
					
					case 6://Option
					    yoyaku = 10;
						break;
					case 7://Exit
						yoyaku = 100;
						break;
					default:
						return -1;
						break;
					}
				}
				if(decided == 0){
					if(DrawGraph(sx,sy,holizon.select,TRUE) != 0  ){ r = -1;};
				}else{
					if(decided % 4 < 2){
						if(DrawGraph(sx,sy,holizon.decided,TRUE) != 0  ){ r = -1;};
					}
					decided -= 1;
					if(decided == 0){
						switch(yoyaku){
						case 2://Game Mode
							cr = 2;
							select = 1;
							yoyakudif = 2;//初期値はNormal
							preselect.title = 1;
							presx.title = sx;
						    presy.title = sy;
						    sx = 112;
						    sy = 236;
							break;
						case 4://Practice Mode
							cr = 4;
							select = 1;
							yoyakudif = 2;//初期値はNormal
							preselect.title = 2;
							presx.title = sx;
						    presy.title = sy;
						    sx = 112;
						    sy = 236;
							break;
						case 9://Music Room
							cr = 9;
							select = 0;
							preselect.title = 5;
							presx.title = sx;
						    presy.title = sy;
							play = -2;//最初はタイトル曲であろうと最初から再生し、一時停止しない。
							sx = 20;
							sy = 120;
							musicup = 0;
							musicdown = 9;
							break;
						case 10://Option
							cr = 10;
							select = 1;
							preselect.title = 6;
							presx.title = sx;
							presy.title = sy;
							sx = 35;
							sy = 255;
							break;
						case 100://Exit
							r = 100;
							break;
						default:
							return -1;
							break;
						}
						
					}
				}
				DrawGraph(0,0,holizon.home,true);
				DrawExtendGraph(0, 115, 259, 469, holizon.titlestand, true);
				break;
		   case 2://Game Mode　難易度選択
			    /*select詳細
			    1 Normal cr = 3へ
			    Cancel cr = 1へ
			    */
				if(gm.ctrl.GetButton("ok_shot") && decided == 0){
				    decided = 30;
					gm.jiki.s1.eff.RequestSE(gm.jiki.s1.eff.se.decide);
				    switch(select){
				       case 1://Normal 
					       yoyaku = 3;
						   yoyakudif = 2;
					       break;
				       /*
				       case 2://Hard
				           yoyaku = 4;
						   yoyakudif = 3;
					       break;
					   case 3://Extra
					       yoyaku = 20;
						   yoyakudif = 5;
					       break;
				                     */
				       default:
					       return -1;
					       break;
				    }
				}
				if(decided == 0){
					if(DrawGraph(sx,sy,holizon.select,TRUE) != 0  ){ r = -1;}
				}else{
					if (decided % 4 < 2){
					    if(DrawGraph(sx,sy,holizon.decided,TRUE) != 0  ){ r = -1;};
				    }
				    decided -= 1;
				    if(decided == 0){
					    switch(yoyaku){
						case 3://Normal Mode
							cr = 3;
							preselect.difficulty = 1;
							presx.difficulty = sx;
					        presy.difficulty = sy;
							gm.jiki.Set_difficulty(2);
							partner = 1;//初期選択時は布都
							break;
						/*
						case 4:
						case 20:
						*/
						default:
							return -1;
							break;
						}
					}
				}
     		    if(DrawGraph(0,0,holizon.choosedif,TRUE) != 0  ){ r = -1;}
				if(gm.ctrl.GetButton("cancel_bomb") == 1 && decided == 0){
				    cr = 1;
					sx = presx.title;
					sy = presy.title;
					select = preselect.title;
					gm.jiki.s1.eff.RequestSE(gm.jiki.s1.eff.se.cancel);
				}

				break;
		   case 3://　　〃　　　自機選択
			    /*select詳細
			    1 Futo cr = 11へ     2 Mima cr = 12へ
			    
			    3 Sanae cr = 13へ    4 Sakuya cr = 14へ
			    
			    Cancel cr = 2へ
			    */
				if(decided == 0){
					if(gm.ctrl.GetButton("down") == 1 || gm.ctrl.GetButton("up") == 1){
						if(partner > 2){
							partner -= 2;
						}else{
							partner += 2;
						}
						gm.jiki.s1.eff.RequestSE(gm.jiki.s1.eff.se.select);
					}
				    
					    
					if(gm.ctrl.GetButton("right") == 1 || gm.ctrl.GetButton("left") == 1){
						if(partner % 2 == 0){
							partner -= 1;
						}else{
							partner += 1;
						}
						gm.jiki.s1.eff.RequestSE(gm.jiki.s1.eff.se.select);
					}
					
					   
					
				}
				if(gm.ctrl.GetButton("ok_shot") == 1 && decided == 0){
				    decided = 30;
					gm.jiki.s1.eff.RequestSE(gm.jiki.s1.eff.se.decide);
					switch(partner){
					case 1://布都
						yoyaku = 11;
						yoyakupartner = 1;
						Holizonpartner = holizon.Futo1;
						break;
					case 2://魅魔
						yoyaku = 12;
						yoyakupartner = 2;
						Holizonpartner = holizon.Mima1;
						break;
					case 3://早苗
						yoyaku = 13;
						yoyakupartner = 3;
						Holizonpartner = holizon.Sanae1;
						break;
					case 4://咲夜
						yoyaku = 14;
						yoyakupartner = 4;
						Holizonpartner = holizon.Sakuya1;
						break;
					}
				}
				if(DrawGraph(0,0,holizon.choosepartner,TRUE) != 0  ){ r = -1;};
				if(decided == 0){
				    switch(partner){
				    case 1://布都選択時
					    sx = 13;
					    sy = 118;
					    if(DrawGraph(sx,sy,holizon.Futo1,TRUE) != 0  ){ r = -1;};
					    break;
				    case 2://魅魔
					    sx = 324;
					    sy = 118;
					    if(DrawGraph(sx,sy,holizon.Mima1,TRUE) != 0  ){ r = -1;};
					    break;
				    case 3://早苗
						sx = 13;
						sy = 289;
						if(DrawGraph(sx,sy,holizon.Sanae1,TRUE) != 0  ){ r = -1;};
					    break;
				    case 4://咲夜
						sx = 324;
						sy = 289;
						if(DrawGraph(sx,sy,holizon.Sakuya1,TRUE) != 0  ){ r = -1;};
						break;
				    default:
					    return -1;
					    break;
				
				   }
				}else{
					if (decided % 4 < 2){
					    if(DrawGraph(sx,sy,Holizonpartner,TRUE) != 0  ){ r = -1;};
				    }
				    decided -= 1;
					if(decided == 0){
					    cr = yoyaku;
						preselect.partner = yoyakupartner;
						presx.partner = sx;
					    presy.partner = sy;
					}
				}
				if(gm.ctrl.GetButton("cancel_bomb") == 1){
				    cr = 2;
					sx = presx.difficulty;
					sy = presy.difficulty;
				    select = preselect.difficulty;
					gm.jiki.s1.eff.RequestSE(gm.jiki.s1.eff.se.cancel);
				}

			    break;
		   case 4://Practice Mode 難易度選択
			    /*select詳細
			    3 Normal cr = 5へ
			    Cancel cr = 1へ
			    */
			    if(gm.ctrl.GetButton("ok_shot") && decided == 0){
				   decided = 30;
				   gm.jiki.s1.eff.RequestSE(gm.jiki.s1.eff.se.decide);
				   switch(select){
				       case 1://Normal 
					       yoyaku = 3;
						   yoyakudif = 2;
					       break;
				       /*
				       case 2://Hard
				           yoyaku = 4;
						   yoyakudif = 3;
					       break;
				       case 3://Extra
					       yoyakudif = 5;
					       yoyaku = 20;
					       break;
				       */
				       default:
					       return -1;
					       break;
				       }
				}
				if(decided == 0){
					if(DrawGraph(sx,sy,holizon.select,TRUE) != 0  ){ r = -1;}
				}else{
					if (decided % 4 < 2){
				    if(DrawGraph(sx,sy,holizon.decided,TRUE) != 0  ){ r = -1;};
				    }
				    decided -= 1;
				    if(decided == 0){
				        switch(yoyaku){
					    case 3://Normal Mode
						    cr = 5;
							gm.jiki.Set_difficulty(yoyakudif);
						    preselect.difficulty = 1;
				            presx.difficulty = sx;
				            presy.difficulty = sy;
				            sx = 14;
				            sy = 19;
						    partner = 1;//初期選択時は布都
						    break;
					    /*
					    case 4:
					    case 20:
					    */
					    default:
						    return -1;
						    break;
					    }
				    }
				}
			    if(DrawGraph(0,0,holizon.choosedif,TRUE) != 0  ){ r = -1;}
				if(gm.ctrl.GetButton("cancel_bomb") == 1 && decided == 0){
					cr = 1;
					sx = presx.title;
					sy = presy.title;
					select = preselect.title;
					gm.jiki.s1.eff.RequestSE(gm.jiki.s1.eff.se.cancel);
				}
				if(r == -1){
					r = 0;
				}
				break;
		   case 5://Practice Mode 自機選択
		    	/*select詳細
			    1 Futo cr = 11へ     2 Mima cr = 12へ
			    
			    3 Sanae cr = 13へ    4 Sakuya cr = 14へ
			    
			    Cancel cr = 4へ
			    */
				if(decided == 0){
					if(gm.ctrl.GetButton("down") == 1 || gm.ctrl.GetButton("up") == 1){
						if(partner > 2){
							partner -= 2;
						}else{
							partner += 2;
						}
						gm.jiki.s1.eff.RequestSE(gm.jiki.s1.eff.se.select);
					}
				    
					    
					if(gm.ctrl.GetButton("right") == 1 || gm.ctrl.GetButton("left") == 1){
						if(partner % 2 == 0){
							partner -= 1;
						}else{
							partner += 1;
						}
						gm.jiki.s1.eff.RequestSE(gm.jiki.s1.eff.se.select);
					}
				}
				if(gm.ctrl.GetButton("ok_shot") == 1){
				    decided = 30;
					gm.jiki.s1.eff.RequestSE(gm.jiki.s1.eff.se.decide);
					switch(partner){
					case 1://布都
						yoyaku = 21;
						yoyakupartner = 1;
						Holizonpartner = holizon.Futo1;
						break;
					case 2://魅魔
						yoyaku = 22;
						yoyakupartner = 2;
						Holizonpartner = holizon.Mima1;
						break;
					case 3://早苗
						yoyaku = 23;
						yoyakupartner = 3;
						Holizonpartner = holizon.Sanae1;
						break;
					case 4://咲夜
						yoyaku = 24;
						yoyakupartner = 4;
						Holizonpartner = holizon.Sakuya1;
						break;
					}
				}
				if (DrawGraph(0, 0, holizon.choosepartner, TRUE) != 0){ r = -1; };
				if(decided == 0){
				    switch(partner){
				    case 1://布都選択時
					    sx = 13;
					    sy = 118;
					    if(DrawGraph(sx,sy,holizon.Futo1,TRUE) != 0  ){ r = -1;};
					    break;
				    case 2://魅魔
					    sx = 324;
					    sy = 118;
					    if(DrawGraph(sx,sy,holizon.Mima1,TRUE) != 0  ){ r = -1;};
					    break;
				    case 3://早苗
					    sx = 13;
					    sy = 289;
					    if(DrawGraph(sx,sy,holizon.Sanae1,TRUE) != 0  ){ r = -1;};
					    break;
		   		    case 4://咲夜
						sx = 324;
						sy = 289;
						if(DrawGraph(sx,sy,holizon.Sakuya1,TRUE) != 0  ){ r = -1;};
					    break;
				    default:
						return -1;
						break;
				
				    }
				}else{
					if (decided % 4 < 2){
					    if(DrawGraph(sx,sy,Holizonpartner,TRUE) != 0  ){ r = -1;};
				    }
				    decided -= 1;
					if(decided == 0){
					    cr = yoyaku;
						choosestage = 1;
						preselect.partner = yoyakupartner;
						presx.partner = sx;
					    presy.partner = sy;
					}
				}
				if(gm.ctrl.GetButton("cancel_bomb") == 1){
				    cr = 4;
					sx = presx.difficulty;
					sy = presy.difficulty;
					select = preselect.difficulty;
					gm.jiki.s1.eff.RequestSE(gm.jiki.s1.eff.se.cancel);
				}
				break;
		   case 6://Practice Mode ChooseStage
			   DrawGraph(1, 1, holizon.chooseback, true);
			   DrawGraph(1,1,holizon.choosestage,true);
			   if(gm.ctrl.GetButton("cancel_bomb") == 1){
				   cr = 5;
				   sx = presx.partner;
				   sy = presy.partner;
				   select = preselect.partner;
				   gm.jiki.s1.eff.RequestSE(gm.jiki.s1.eff.se.cancel);
			   }
			   if(gm.ctrl.GetButton("ok_shot") == 1){
				    decided = 30;
					gm.jiki.s1.eff.RequestSE(gm.jiki.s1.eff.se.decide);
			   }
			   if(decided == 0){
				   switch(choosestage){
				       case 1:
						   if(gm.ctrl.GetButton("down") == 1){
							   choosestage += 1;
							   gm.jiki.s1.eff.RequestSE(gm.jiki.s1.eff.se.select);
						   }
						   if(gm.ctrl.GetButton("up") == 1){
							   choosestage = 7;
							   gm.jiki.s1.eff.RequestSE(gm.jiki.s1.eff.se.select);
						   }
						   if(gm.ctrl.GetButton("right") == 1 || gm.ctrl.GetButton("left") == 1){
							   choosestage += 4;
							   gm.jiki.s1.eff.RequestSE(gm.jiki.s1.eff.se.select);
						   }
						   break;
					   case 5:
						   if(gm.ctrl.GetButton("down") == 1){
							   choosestage += 1;
							   gm.jiki.s1.eff.RequestSE(gm.jiki.s1.eff.se.select);
						   }
						   if(gm.ctrl.GetButton("up") == 1){
							   choosestage = 4;
							   gm.jiki.s1.eff.RequestSE(gm.jiki.s1.eff.se.select);
						   }
						   if(gm.ctrl.GetButton("right") == 1 || gm.ctrl.GetButton("left") == 1){
							   choosestage -= 4;
							   gm.jiki.s1.eff.RequestSE(gm.jiki.s1.eff.se.select);
						   }
						   break;
					   case 7:
						   if(gm.ctrl.GetButton("down") == 1){
							   choosestage = 5;
							   gm.jiki.s1.eff.RequestSE(gm.jiki.s1.eff.se.select);
						   }
						   if(gm.ctrl.GetButton("up") == 1){
							   choosestage -= 1;
							   gm.jiki.s1.eff.RequestSE(gm.jiki.s1.eff.se.select);
						   }
						   if(gm.ctrl.GetButton("right") == 1 || gm.ctrl.GetButton("left") == 1){
							   choosestage -= 4;
							   gm.jiki.s1.eff.RequestSE(gm.jiki.s1.eff.se.select);
						   }
						   break;
					   case 4:
						   if(gm.ctrl.GetButton("down") == 1){
							   choosestage = 5;
							   gm.jiki.s1.eff.RequestSE(gm.jiki.s1.eff.se.select);
						   }
						   if(gm.ctrl.GetButton("up") == 1){
							   choosestage -= 1;
							   gm.jiki.s1.eff.RequestSE(gm.jiki.s1.eff.se.select);
						   }
						   if(gm.ctrl.GetButton("right") == 1){
							   choosestage = 1;
							   gm.jiki.s1.eff.RequestSE(gm.jiki.s1.eff.se.select);
						   }
						   if(gm.ctrl.GetButton("left") == 1){
							   choosestage = 7;
							   gm.jiki.s1.eff.RequestSE(gm.jiki.s1.eff.se.select);
						   }
					       break;
					   default:
						   if(gm.ctrl.GetButton("down") == 1){
							   choosestage += 1;
							   gm.jiki.s1.eff.RequestSE(gm.jiki.s1.eff.se.select);
						   }
						   if(gm.ctrl.GetButton("up") == 1){
							   choosestage -= 1;
							   gm.jiki.s1.eff.RequestSE(gm.jiki.s1.eff.se.select);
						   }
						   if(gm.ctrl.GetButton("right") == 1 || gm.ctrl.GetButton("left") == 1){
							   if(choosestage < 4){
								   choosestage += 4;
							   }else{
								   choosestage = 2;
							   }
							   gm.jiki.s1.eff.RequestSE(gm.jiki.s1.eff.se.select);
						   }
						   break;
				   }
				   switch(choosestage){
					   case 1:
						   sx = 75;
						   sy = 105;
						   break;
					   case 2:
						   sx = 75;
						   sy = 170;
						   break;
					   case 3:
						   sx = 75;
						   sy = 235;
						   break;
					   case 4:
						   sx = 75;
						   sy = 300;
						   break;
					   case 5:
						   sx = 330;
						   sy = 105;
						   break;
					   case 6:
						   sx = 330;
						   sy = 170;
						   break;
					   case 7:
						   sx = 330;
						   sy = 235;
						   break;
				   }
				   DrawGraph(sx,sy,holizon.select,TRUE);
			   }else{
				   if (decided % 4 < 2){
					    if(DrawGraph(sx,sy,holizon.decided,TRUE) != 0  ){ r = -1;};
				    }
				    decided -= 1;
					if(decided == 0){
						if (StopSoundMem(gm.jiki.ongaku.CurrentBGM) == 0){
							gm.jiki.Set_choicestage(choosestage);
							gm.jiki.StageStart(choosestage + 10);
							gm.jiki.ClearStates();
							gm.cr = 2;
							r = 2;
						}else{
							r = -1;
						}
					}
			   }
			   break;
		   case 9://Music Room
				/*select詳細
				cancel タイトル画面 cr = 1へ
				ok_shot 選択中の音楽を再生 0～23の範囲とする。
				ok_shot → ok_shot 再生中の音楽を一時停止、再び再生。
				*/
			   if(gm.ctrl.GetButton("ok_shot") == 1){
				   //音楽再生。ただし選択再生中に同じ音楽を選択されたら一時停止する。
				   if(select != play){
					   if (CheckSoundMem(gm.jiki.ongaku.CurrentBGM) == 1){ r = gm.jiki.ongaku.PorseMusic(); }
					   r = gm.jiki.ongaku.RequestMusic(select);
					   play = select;
				   }else{
					   if (CheckSoundMem(gm.jiki.ongaku.CurrentBGM) == 1){
						   r = gm.jiki.ongaku.PorseMusic();
					   }else{
						   r = gm.jiki.ongaku.PorseCancel();
					   }
				   }
			   }
			   if(gm.ctrl.GetButton("down") == 1){
			       if(select < 23){
			           select += 1;
				       
				   }else{
				       select = 0;
					   musicup = 0;
					   musicdown = 9;
					   
				   }
				   gm.jiki.s1.eff.RequestSE(gm.jiki.s1.eff.se.select);
			   }
			   if(gm.ctrl.GetButton("up") == 1){
				   if(select > 0){
				       select -= 1;
				   }else{
				       select = 23;
					   musicup = 14;
					   musicdown = 23;
				   }
				   gm.jiki.s1.eff.RequestSE(gm.jiki.s1.eff.se.select);
			   }
			   if(musicup > select){
				   musicup = select;
				   musicdown -= 1;
			   }
			   if(musicdown < select){
				   musicdown = select;
				   musicup += 1;
			   }
			   if (DrawGraph(0, 0, holizon.music, TRUE) != 0 || gm.jiki.ongaku.DisplayMusicList(select, musicup, musicdown) != 0){ r = -1; };
			   if(gm.ctrl.GetButton("cancel_bomb") == 1){
				   //再生中の音楽を停止させ、タイトル画面に戻る。
				   if (CheckSoundMem(gm.jiki.ongaku.CurrentBGM) == 1){ r = StopSoundMem(gm.jiki.ongaku.CurrentBGM); }
				   if (gm.jiki.ongaku.RequestMusic(0) != 0){ return -1; }
				   cr = 1;
				   sx = presx.title;
				   sy = presy.title;
				   select = preselect.title;
				   gm.jiki.s1.eff.RequestSE(gm.jiki.s1.eff.se.cancel);
			   }
			   break;
		   case 10://Option
			   /*select詳細
			   1.BGM Volume BGMの音量を左右で変更する　上限が128 下限が0
			   2.SE Volume BGMの音量を左右で変更する　上限が128 下限が0
			   3.Key Config ゲームパッドのキー設定を行う ⇒cr = 11
			   4.Exit タイトルに戻る ⇒cr = 1
			   */
			   DrawGraph(1, 1, holizon.foundation, false);
			   DrawGraph(1, 1, holizon.option, true);
			   if (decided == 0){
				   if (gm.ctrl.GetButton("up") == 1){
					   if (select == 1){
						   select = 4;
						   sy = 374;
					   }
					   else{
						   select--;
						   sy -= 40;
					   }
				   }
				   if (gm.ctrl.GetButton("down") == 1){
					   if (select == 4){
						   select = 1;
						   sy = 255;
					   }
					   else{
						   select++;
						   sy += 40;
					   }
				   }
				   short ChangeVolume;
				   ChangeVolume = 0;
				   if (gm.ctrl.GetButton("left") == 1){
					   ChangeVolume = -1;
				   }
				   if (gm.ctrl.GetButton("right") == 1){
					   ChangeVolume = 1;
				   }
				   if (ChangeVolume != 0){
					   int *volume;
					   switch (select){
					   case 1:
						   volume = &gm.jiki.ongaku.BGMVolume;
						   if (ChangeVolume == -1){
							   //音量減少
							   if (*volume == 128){
								   *volume -= 8;
							   }
							   else{
								   if (*volume != 12){
									   *volume -= 12;
								   }
							   }
						   }
						   else{
							   //音量増加
							   if (*volume == 120){
								   *volume += 8;
							   }
							   else{
								   if (*volume != 128){
									   *volume += 12;
								   }
							   }
						   }
						   ChangeVolumeSoundMem(gm.jiki.ongaku.BGMVolume, gm.jiki.ongaku.CurrentBGM);
						   break;
					   case 2:
						   volume = &gm.jiki.s1.eff.SEVolume;
						   if (ChangeVolume == -1){
							   //音量減少
							   if (*volume == 128){
								   *volume -= 8;
							   }
							   else{
								   if (*volume != 12){
									   *volume -= 12;
								   }
							   }
						   }
						   else{
							   //音量増加
							   if (*volume == 120){
								   *volume += 8;
							   }
							   else{
								   if (*volume != 128){
									   *volume += 12;
								   }
							   }
						   }
						  break;
					   }
					   
				   }
				   if (gm.ctrl.GetButton("up") == 1 || gm.ctrl.GetButton("down") == 1 || ChangeVolume != 0){
					   gm.jiki.s1.eff.RequestSE(gm.jiki.s1.eff.se.select);
				   }

				   if (gm.ctrl.GetButton("ok_shot") == 1){
					   decided = 30;
					   gm.jiki.s1.eff.RequestSE(gm.jiki.s1.eff.se.decide);
				   }
				   DrawGraph(sx, sy, holizon.select, TRUE);
				   
			   }else{
				   if (decided % 4 < 2){
					   if (DrawGraph(sx, sy, holizon.decided, TRUE) != 0){ r = -1; };
				   }
				   decided -= 1;
				   if (decided == 0){
					   switch (select){
					   case 3://Key Config
						   break;
					   case 4://Exit
						   cr = 1;
						   sx = presx.title;
						   sy = presy.title;
						   select = preselect.title;
						   break;
					   }
				   }
			   }
			   int volume;
			   if (gm.jiki.ongaku.BGMVolume == 128){
				   volume = 10;
			   }
			   else{
				   volume = gm.jiki.ongaku.BGMVolume / 12 - 1;
			   }
			   DrawFormatString(260, 265, GetColor(255, 255, 255), "%d", volume);
			   if (gm.jiki.s1.eff.SEVolume == 128){
				   volume = 10;
			   }
			   else{
				   volume = gm.jiki.s1.eff.SEVolume / 12 - 1;
			   }
			   DrawFormatString(260, 305, GetColor(255, 255, 255), "%d", volume);
			   break;
		   default:
			   return -1;
			   break;
		    }
		}
	if(precr < cr && cr != 9){//Title内から状況が変化したとき。ただしキャンセル選択時は除く。
	    select = 1;//選択の初期化。ただしChooseyourpartnerは別の選択とする。
	}
	precr = cr;
	return r;	
	};
	int Title::ChooseYourPartner(int yoyaku){
		int r = 0;
		int f = 0;
		switch(yoyaku){
		case 11://布都
			Holizonpartner = holizon.Futo2;
			decidedpartner = "Futo";
			f = holizon.Futo3;
			break;
		case 12://魅魔
			Holizonpartner = holizon.Mima2;
			decidedpartner = "Mima";
			f = holizon.Mima3;
			break;
		case 13://早苗
			Holizonpartner = holizon.Sanae2;
			decidedpartner = "Sanae";
			f = holizon.Sanae3;
			break;
		case 14://咲夜
			Holizonpartner = holizon.Sakuya2;
			decidedpartner = "Sakuya";
			f = holizon.Sakuya3;
			break;
			//以下Practice Mode
		case 21://布都
			Holizonpartner = holizon.Futo2;
			decidedpartner = "Futo";
			f = holizon.Futo3;
			break;
		case 22://魅魔
			Holizonpartner = holizon.Mima2;
			decidedpartner = "Mima";
			f = holizon.Mima3;
			break;
		case 23://早苗
			Holizonpartner = holizon.Sanae2;
			decidedpartner = "Sanae";
			f = holizon.Sanae3;
			break;
		case 24://咲夜
			Holizonpartner = holizon.Sakuya2;
			decidedpartner = "Sakuya";
			f = holizon.Sakuya3;
			break;
		}
		if(gm.ctrl.GetButton("ok_shot") == 1){
			gm.jiki.s1.eff.RequestSE(gm.jiki.s1.eff.se.decide);
			gm.Set_partner(decidedpartner,f);
			if(yoyaku < 20){//Game ModeならStage1へ移動
				if (StopSoundMem(gm.jiki.ongaku.CurrentBGM) == 0){
					r = 1;
				}else{
					r = -1;
				}
				gm.jiki.StageStart(1);
				gm.jiki.ClearStates();
				gm.cr = 1;
			}else{//Practice ModeならChooseStageへ移動
				cr = 6;
				holizon.chooseback = f;
			}
			
		}
		if (DrawGraph(0, 0, f, false) != 0)	{ r = -1; }
		if(DrawGraph(0,0,Holizonpartner,TRUE) != 0){r = -1;}
		if(gm.ctrl.GetButton("cancel_bomb") == 1){
		    if(yoyaku < 20){
			    cr = 3;
		    }else{
			    cr = 5;
		    }
			partner = preselect.partner;
			sx = presx.partner;
			sy = presy.partner;
			gm.jiki.s1.eff.RequestSE(gm.jiki.s1.eff.se.cancel);
		}
	    return r;
	}
	int Title::ChooseStage(){
		int r = 0;
		return 0;
	}
private:
	struct back{//タイトル周辺の背景画像を保有する構造体です。
	    int home;//タイトル画面 1
		int foundation;//基本背景。この背景の描写後に画面が描写される。Gameクラスでも使用される。
		int titlestand;//タイトル画面に登場するキャラクターの立ち絵
		int choosedif;//難易度選択時の画面 2
		int choosepartner;//自機選択時の画面 3
		int choosestage;//PracticeModeでのステージ選択時の画面
		int chooseback;//ステージ選択画面の背景、選択した自機に応じて変わる。
		int Futo1;
		int Mima1;
		int Sanae1;
		int Sakuya1;
		int Futo2;//布都を選択したときの機能詳細画面 11
		int Mima2;//魅魔        〃                   12
		int Sanae2;//早苗       〃                   13
		int Sakuya2;//咲夜      〃                   14
		int Futo3;
		int Mima3;
		int Sanae3;
		int Sakuya3;
		int home2;//難易度・自機・練習ステージ選択、リプレイ画面の背景
		int music;//Music Room画面
		int option;//オプション画面
		int select;//選択を示す矢印
		int decided;//選択を決定した時の矢印。点滅する。
	};
	back holizon;
	struct pre{
	    int title;
		int difficulty;
		int partner;
		int stage;
	};
	pre presx,presy;//Home内でキャンセルにより前画面に戻った時にあらかじめ選択した場所に選択させる変数です。
	pre preselect;
	int cr;//Current = 0(タイトル周辺)時、Titleクラス内で処理する場合の詳細なゲームの状況を示す変数。初期値は1(タイトル画面)
	int precr;
	int select;//タイトル周辺の選択候補を示す変数です。具体的内容はcrにより変化します。
	int sx,sy;//セレクト矢印の描写場所を示す変数です。sxがX軸、syがY軸になります。
	int choosestage;//Practice Modeで選択されるステージを示す変数です。1 = Stage1, 2 = Stage2...6 = Stage6A, 7 = Stage6B
	int partner;//選択した自機を示す変数。1布都,2魅魔,3早苗,4咲夜とする。
	int decided;//選択を決定した瞬間かを示す変数。1以上で偶数時点灯奇数時消灯で点滅を演出する。
	int yoyaku;//選択決定時に矢印が点滅するが、その時保存する変数。点滅終了後yoyakuをもとにゲームが進行する。
	int yoyakudif;//選択した難易度を保持する変数です。Chooseyourpartnerに移動するときにGameクラスに登録されます。
	int yoyakupartner;//選択した自機の名前を保持する変数です。
	char* decidedpartner;//ChooseYourPartnerで入力され、Gameクラスに登録される文字変数です。
	int Holizonpartner;//選択した自機の画像を保持する変数です。ChooseYourPartnerでは背景、自機選択中では決定後の点滅する画像になります。
	int musicup,musicdown;//表示する音楽名の上限と下限を示す変数です。常にmusicdown - musicup = 9になる。またselectの変化に応じて増減します。
	int play;//現在再生中の音楽を保持する変数です。selectから移されます。
};





