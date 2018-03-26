
#ifndef EFFECT
#define EFFECT
#include "Header.h"

class Effect{
public:
	
	void Effect::Init(){
		ClearEffect();
		int f;
		SEVolume = 127;//後にコンフィグファイルから読み込む
		countitem = 0;
		kkakudo = 0;
		se.select = 1;
		se.decide = 2;		
		se.dan1 = 3;
		se.dan2 = 4;
		se.dan3 = 5;
		se.dan4 = 6;
		se.dan5 = 7;
		se.hit = 8;
		se.spell = 9;
		
		se.talk = 10;
		se.enemyend = 11;
		se.bossend = 12;
		se.cancel = 13;
		se.item = 14;
		se.itemren = 15;
		se.powerup = 16;
		se.powermax = 17;
		se.spellend = 18;
		se.miss = 19;
		se.karakaze = 20;
		se.dan6 = 21;
		se.dan7 = 22;
		se.dan8 = 23;
		// LoadSoudnMemを使った場合　半分黒歴史
		char dir[255];
		GetCurrentDirectory(255, dir);
		f = _chdir("data");
		f = _chdir("SE");
		GetCurrentDirectory(255, dir);
		InitSoundMem();
		//Title
		SoundEffect[se.select] = LoadSoundMem("select.mp3");
		SoundEffect[se.decide] = LoadSoundMem("decided.mp3");
		//danmaku
		
		SoundEffect[se.dan1] = LoadSoundMem("dan1.mp3");
		SoundEffect[se.dan2] = LoadSoundMem("dan2.mp3");
		SoundEffect[se.dan3] = LoadSoundMem("dan3.wav");
		SoundEffect[se.dan4] = LoadSoundMem("dan4.mp3");
		SoundEffect[se.dan5] = LoadSoundMem("dan5.mp3");
		SoundEffect[se.dan6] = LoadSoundMem("dan6.wav");
		SoundEffect[se.dan7] = LoadSoundMem("dan7.wav");
		SoundEffect[se.dan8] = LoadSoundMem("dan8.wav");
		//Stage
		SoundEffect[se.hit] = LoadSoundMem("hit.mp3");
		SoundEffect[se.talk] = LoadSoundMem("talk.mp3");
		SoundEffect[se.spell] = LoadSoundMem("spell.mp3");
		SoundEffect[se.enemyend] = LoadSoundMem("enemyend.mp3");
		SoundEffect[se.bossend] = LoadSoundMem("bossend.mp3");
		SoundEffect[se.cancel] = LoadSoundMem("cancel.mp3");
		SoundEffect[se.item] = LoadSoundMem("item.mp3");
		SoundEffect[se.itemren] = LoadSoundMem("itemren.mp3");
		SoundEffect[se.powerup] = LoadSoundMem("powerup.mp3");
		SoundEffect[se.powermax] = LoadSoundMem("powermax.mp3");
		SoundEffect[se.spellend] = LoadSoundMem("spellend.mp3");
		SoundEffect[se.miss] = LoadSoundMem("miss.mp3");
		SoundEffect[se.karakaze] = LoadSoundMem("karakaze.mp3");
		
		
		/*
		f = _chdir("data");
		f = _chdir("SE");
		
		SoundEffectname[se.dan1] = "./data/SE/dan1.mp3";
		SoundEffectname[se.dan2] = "./data/SE/dan2.mp3";
		SoundEffectname[se.dan3] = "./data/SE/dan3.mp3";
		SoundEffectname[se.dan4] = "./data/SE/dan4.mp3";
		SoundEffectname[se.dan5] = "./data/SE/dan5.mp3";
		//Stage
		SoundEffectname[se.hit] = "./data/SE/hit.mp3";
		SoundEffectname[se.talk] = "./data/SE/talk.mp3";
		SoundEffectname[se.spell] = "./data/SE/spell.mp3";
		SoundEffectname[se.enemyend] = "./data/SE/enemyend.mp3";
		SoundEffectname[se.bossend] = "./data/SE/bossend.mp3";
		SoundEffectname[se.cancel] = "./data/SE/cancel.mp3";
		SoundEffectname[se.item] = "/data/SE/item.mp3";
		SoundEffectname[se.itemren] = "./data/SE/itemren.mp3";
		SoundEffectname[se.powerup] = "./data/SE/powerup.mp3";
		SoundEffectname[se.powermax] = "./data/SE/powermax.mp3";
		SoundEffectname[se.spellend] = "./data/SE/spellend.mp3";
		SoundEffectname[se.miss] = "./data/SE/miss.mp3";
		SoundEffectname[se.karakaze] = "./data/SE/karakaze.mp3";
		//Title
		SoundEffectname[se.select] = "./data/SE/select.mp3";
		SoundEffectname[se.decided] = "./data/SE/decided.mp3";
		for (int se = 0; se < 30; se++) {
			SoundEffect[se] = 0;
		}
		*/
		f = _chdir("..");
		f = _chdir("img");
		f = _chdir("Game");
		f = _chdir("Effect");
		effgraph[2][1] = LoadGraph("Hit1.bmp");
		effgraph[2][2] = LoadGraph("Hit2.bmp");
		effgraph[2][3] = LoadGraph("Hit3.bmp");
		effgraph[2][4] = LoadGraph("Hit4.bmp");
		effgraph[2][5] = LoadGraph("Hit5.bmp");
		effgraph[2][6] = LoadGraph("Hit6.bmp");
		effgraph[2][7] = LoadGraph("Hit7.bmp");
		effgraph[2][8] = LoadGraph("Hit8.bmp");
		effgraph[2][9] = LoadGraph("Hit9.bmp");
		effgraph[2][10] = LoadGraph("Hit10.bmp");
		karakkazewarning = LoadGraph("karakaze.bmp");
		karakkazekakudo = LoadGraph("karakaze.kakudo.bmp");
		f = _chdir("..");
		f = _chdir("..");
		f = _chdir("..");
		f = _chdir("..");
		
	}
	void Effect::Input_Address(Effect * eff){
		se.select = 1;
		se.decide = 2;
		se.dan1 = 3;
		se.dan2 = 4;
		se.dan3 = 5;
		se.dan4 = 6;
		se.dan5 = 7;
		se.hit = 8;
		se.spell = 9;
		se.talk = 10;
		se.enemyend = 11;
		se.bossend = 12;
		se.cancel = 13;
		se.item = 14;
		se.itemren = 15;
		se.powerup = 16;
		se.powermax = 17;
		se.spellend = 18;
		se.miss = 19;
		se.karakaze = 20;
		se.dan6 = 21;
		se.dan7 = 22;
		se.dan8 = 23;
		karakkazekakudo = eff->karakkazekakudo;
		karakkazewarning = eff->karakkazewarning;
		SEVolume = eff->SEVolume;
		kkakudo = 0;
		SoundEffect[se.dan1] = eff->SoundEffect[se.dan1];
		SoundEffect[se.dan2] = eff->SoundEffect[se.dan2];
		SoundEffect[se.dan3] = eff->SoundEffect[se.dan3];
		SoundEffect[se.dan4] = eff->SoundEffect[se.dan4];
		SoundEffect[se.dan5] = eff->SoundEffect[se.dan5];
		SoundEffect[se.dan6] = eff->SoundEffect[se.dan6];
		SoundEffect[se.dan7] = eff->SoundEffect[se.dan7];
		SoundEffect[se.dan8] = eff->SoundEffect[se.dan8];
		SoundEffect[se.hit] = eff->SoundEffect[se.hit];
		SoundEffect[se.talk] = eff->SoundEffect[se.talk];
		SoundEffect[se.spell] = eff->SoundEffect[se.spell];
		SoundEffect[se.select] = eff->SoundEffect[se.select];
		SoundEffect[se.decide] = eff->SoundEffect[se.decide];
		SoundEffect[se.enemyend] = eff->SoundEffect[se.enemyend];
		SoundEffect[se.bossend] = eff->SoundEffect[se.bossend];
		SoundEffect[se.cancel] = eff->SoundEffect[se.cancel];
		SoundEffect[se.item] = eff->SoundEffect[se.item];
		SoundEffect[se.itemren] = eff->SoundEffect[se.itemren];
		SoundEffect[se.powerup] = eff->SoundEffect[se.powerup];
		SoundEffect[se.powermax] = eff->SoundEffect[se.powermax];
		SoundEffect[se.spellend] = eff->SoundEffect[se.spellend];
		SoundEffect[se.miss] = eff->SoundEffect[se.miss];
		SoundEffect[se.karakaze] = eff->SoundEffect[se.karakaze];
	}
	void SetEffect(int x,int y,int ef){
		if (ecount == 0){ ClearEffect(); }
		int e = tail;
		tail++;
		efct[e].x = x;
		efct[e].y = y;
		efct[e].start = 1;
		efct[e].effshu = ef;
		efct[e].pp = e - 1;
		efct[e].np = e + 1;
		ecount++;
	}
	void RequestSE(int senum){
		/*if (SoundEffect[senum] == 0) {
			SoundEffect[senum] = LoadSoundMem(SoundEffectname[senum]);
		}*/
		if (SEVolume > 0) {
			ChangeVolumeSoundMem(SEVolume, SoundEffect[senum]);
			if (CheckSoundMem(SoundEffect[senum])) {
				StopSoundMem(SoundEffect[senum]);
			}
			PlaySoundMem(SoundEffect[senum], DX_PLAYTYPE_BACK, true);

		}
		//PlaySound(SoundEffect[senum], DX_PLAYTYPE_NORMAL);
		//SetVolumeMusic(SEVolume);
	}
	void StartKarakazzeEffect(int kakudo,int time){
		//5秒間空っ風エフェクト発生の表示を描写する。またkakudo(225,135,45)に応じた方向に矢印を描写する。
		time %= 120;
		int eff = 0;
		kkakudo = kakudo;
		if (time < 61){
			//徐々に現れる
			eff = (int)(256 * time / 60 - 1);
		}
		else{
			//徐々に消えていく
			eff = (int)(256 * (120 - time) / 30 - 1);
		}
		if (time % 10 == 0){
			int x = -100;
			x +=GetRand(200);
			int y;
			switch (kakudo){
			case 225:
				x += 404;
				y = x * -1 + 869;
				break;
			case 135:
				x = x + 20;
				y = x  + 445;
				break;
			case 45:
				x += 20;
				y = x * -1 + 35;
				break;
			}
			SetEffect(x, y, 4);
		}
		SetDrawArea(20, 15, 404, 465);
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, eff);
		DrawGraph(0,30, karakkazewarning, true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, eff);
		SetDrawArea(1,1, 640, 480);
	}
	bool KEcheck(){//空っ風エフェクト中かどうかを判断する関数です。エフェクト中はDanmakuRefreshが行われません。
		bool ke;
		if (kkakudo == 0){
			ke = false;
		}
		else{
			ke = true;
		}
		return ke;
	}
	void EndKarakkaze(){
		kkakudo = 0;
	}
	int ProcessEffect(){
		int r = 0;
		int e = efct[0].np;
		SetDrawArea(20, 15, 404, 465);
		while (e < tail && r == 0){
			
			
			switch (efct[e].effshu){
			case 1://自機ショット被弾
				if (DrawGraph(efct[e].x, efct[e].y, effgraph[efct[e].effshu][efct[e].start], true) != 0){ r = -1; }
				efct[e].start++;
				if (efct[e].start > 10){ DeleteEffect(e); }
				break;
			case 2://ザコ敵爆発
				break;
			case 3://ボスドット変化
				break;
			case 4://空っ風エフェクト
				switch (kkakudo){
				case 225:
					efct[e].x -= 4;
					efct[e].y -= 4;
					if (efct[e].x < -99 || efct[e].y < -60){ DeleteEffect(e); }
					break;
				case 135:
					efct[e].x -= 4;
					efct[e].y += 4;
					if (efct[e].x < -99 || efct[e].y > 499){ DeleteEffect(e); }
					break;
				case 45:
					efct[e].x += 4;
					efct[e].y += 4;
					if (efct[e].x > 449 || efct[e].y > 499){ DeleteEffect(e); }
					break;
				}
				SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);
				DrawRotaGraph(efct[e].x, efct[e].y, 1, kkakudo * PI / 180, karakkazekakudo, true, 0);
				SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
				break;
			}
			
			e = efct[e].np;
		}
		SetDrawArea(1, 1, 640, 480);
		if (ecount == 0){ ClearEffect(); }
		return r;
	}
	void DeleteEffect(int e){
		efct[efct[e].np].pp = efct[e].pp;
		efct[efct[e].pp].np = efct[e].np;
	}
	void ClearEffect(){
		for (int e = 0; e < 100; e++){
			efct[e].x = 0;
			efct[e].y = 0;
			efct[e].effshu = 0;
			efct[e].start = 0;
			efct[e].np = 0;
			efct[e].pp = 0;
		}
		efct[0].np = 1;
		tail = 1;
	}
	void RefreshEffect(){
		EFF reff[100];
		ecount = 0;
		int e = efct[0].np;
		while (e < tail){
			reff[e].x = efct[e].x;
			reff[e].y= efct[e].y;
			reff[e].start = efct[e].start;
			reff[e].effshu = efct[e].effshu;
			e = efct[e].np;
			ecount++;
		}
		ClearEffect();
		tail  = ecount + 1;
		for (int ee = 1; ee < tail; ee++){
			efct[ee].x = reff[ee].x;
			efct[ee].y = reff[ee].y;
			efct[ee].start = reff[ee].start;
			efct[ee].effshu = reff[ee].effshu;
			efct[ee].np = ee - 1;
			efct[ee].pp = ee + 1;
		}
	}
	bool CheckSE(int senum){
		bool r;
		r = CheckMusic();
		
		return r;
	}
	void StopSE(int senum){
		//StopSoundMem(SoundEffect[senum]);
	}
	int SEVolume;
	struct SE{
		int dan1;
		int dan2;
		int dan3;
		int dan4;
		int dan5;
		int dan6;
		int dan7;
		int dan8;
		int hit;
		int miss;
		int spell;
		int spellend;
		int select;
		int decide;
		int talk;
		int enemyend;
		int bossend;
		int cancel;
		int item;
		int itemren;
		int powerup;
		int powermax;
		int karakaze;
	};
	SE se;
	int countitem;//取得した累積アイテム数に従ってアイテム取得SEを繰り返すための変数です。
	static int ecount;
private:
	struct EFF{
		int x;
		int y;
		int start;//エフェクト発生から経過したフレーム数を示す変数です。
		int effshu;//エフェクトの種類を示す変数です。1.自機ショット被弾(10,11,12,13),2.雑魚敵爆発 ,3.ボスドット大変化 4.空っ風エフェクト
		int np;
		int pp;
	};
	EFF efct[100];
	int effgraph[10][11];
	char * SoundEffectname[30];
	int SoundEffect[30];
	int karakkazewarning, karakkazekakudo;
	int kkakudo;//空っ風エフェクトの角度を保持する変数です。Startkarakkazeeffectで設定され、ProcessEffectで使用されます。
	static int effgapp[10][10];
	static short tail;//エフェクトテーブルの末端を示す変数です。
	
};
short Effect::tail = 0;
int Effect::ecount = 0;
#endif
