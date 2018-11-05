#ifndef MUSIC
#define MUSIC
//#include "Header.h"
class Music{
public:
	
	Music::Music(){
		CurrentBGM = 0;
		BGMVolume = 127;//後にコンフィグファイルから読み込む
		white = GetColor(254,254,254);
		glay = GetColor(100,100,100);
		MusicName.Title = "未来からの風刺～Treason to the law";
		MusicName.Stage1 = "Unexpected Combination";
		MusicName.Boss1 = "ミスティカル風聞疾趨";
		MusicName.Stage2 ="Maidens of midnight";
		MusicName.Boss2 = "妖怪少女達の秘密な戯れ";
		MusicName.Stage3 = "Inquisitive investigation";
		MusicName.Boss3 = "幻想セッション～外の世界へ";
		MusicName.Stage4 ="Wistful Allurement";
		MusicName.Boss4 = "デザイアギャザーズ～Needs And Imagine";
		MusicName.Boss41 = "時の風";
		MusicName.Boss42 = "スターボウドリーム";
		MusicName.Stage5 ="Incomplete Plot";
		MusicName.Boss5 = "告発の鍵師～Dreamy pilot";
		MusicName.Stage6A ="木苺魔法店～Unforbidden insanity";
		MusicName.Boss6A ="混沌の坩堝～The witch of mash up";
		MusicName.Final6A ="Border land";
		MusicName.EndingA = "儚き夢の走馬灯～Phantasmagoria";
		MusicName.Stage6B = "木苺魔法店～Erased talent";
		MusicName.Boss6B = "職人ゲーム～Subculture survival";
		MusicName.Final6B = "東方参碓案～Misunderstood border";
		MusicName.EndingB = "風の神社";
		MusicName.StuffRoll = "Crescent dream";
		MusicName.Nouse1 = "幻想セッション～外の世界へ（未使用ver）";
		MusicName.Nouse2 = "スターボウドリーム（未使用ver）";
		
		
	}
	void Music::InputMusic(char* musicname){

	}
	int Music::RequestMusic(int request){//リクエストに応じたBGMを再生します。
		int r = 0;//返り値を示す変数です。音楽再生に成功したら0,失敗したら-1が返ってきます。
		r = _chdir("data");
		r = _chdir("music");
		//FILE *file;
		//fopen_s(&file, "test.txt", "w");
		//fclose(file);
		if(CurrentBGM != 0 && CheckSoundMem(CurrentBGM) == 1){
			r = StopSoundMem(CurrentBGM);
		}
		SetVolumeMusic(BGMVolume);
		switch(request){
		case 0:
		    if(MusicList.Title < 1){
		        MusicList.Title = LoadSoundMem("No.0.wav");//BGM読み込み
		    }
			if(PlaySoundMem(MusicList.Title,DX_PLAYTYPE_LOOP,TRUE) == 0){
				CurrentBGM = MusicList.Title;
			}else{
				r = -1;
			}
			break;
		case 1:
			if (MusicList.Stage1 < 1){
			    MusicList.Stage1 = LoadSoundMem("No.1.wav");
			}
			if(PlaySoundMem(MusicList.Stage1,DX_PLAYTYPE_LOOP,TRUE) == 0){
				CurrentBGM = MusicList.Stage1;
			}else{
				r = -1;
			}

			break;
		case 2:
			if (MusicList.Boss1 < 1){
			    MusicList.Boss1 = LoadSoundMem("No.2.wav");
			}
			if(PlaySoundMem(MusicList.Boss1,DX_PLAYTYPE_LOOP,TRUE) == 0){
				CurrentBGM = MusicList.Boss1;
			}else{
				r = -1;
			}
			break;
		case 3:
			if (MusicList.Stage2 < 1){
			    MusicList.Stage2 = LoadSoundMem("No.3.wav");
			}
			if(PlaySoundMem(MusicList.Stage2,DX_PLAYTYPE_LOOP,TRUE) == 0){
				CurrentBGM = MusicList.Stage2;
			}else{
				r = -1;
			}
			break;
		case 4:
			if (MusicList.Boss2 < 1){
			    MusicList.Boss2 = LoadSoundMem("No.4.wav");
			}
			if(PlaySoundMem(MusicList.Boss2,DX_PLAYTYPE_LOOP,TRUE) == 0){
				CurrentBGM = MusicList.Boss2;
			}else{
				r = -1;
			}
			break;
		case 5:
			if (MusicList.Stage3 < 1){
			    MusicList.Stage3 = LoadSoundMem("No.5.wav");
			}
			if(PlaySoundMem(MusicList.Stage3,DX_PLAYTYPE_LOOP,TRUE) == 0){
				CurrentBGM = MusicList.Stage3;
			}else{
				r = -1;
			}
			break;
		case 6:
			if (MusicList.Boss3 < 1){
			    MusicList.Boss3 = LoadSoundMem("No.6.wav");
			}
			if(PlaySoundMem(MusicList.Boss3,DX_PLAYTYPE_LOOP,TRUE) == 0){
				CurrentBGM = MusicList.Boss3;
			}else{
				r = -1;
			}

			break;
		case 7:
			if (MusicList.Stage4 < 1){
			    MusicList.Stage4 = LoadSoundMem("No.7.wav");
			}
			if(PlaySoundMem(MusicList.Stage4,DX_PLAYTYPE_LOOP,TRUE) == 0){
				CurrentBGM = MusicList.Stage4;
			}else{
				r = -1;
			}
			break;
		case 8:
			if (MusicList.Boss4 < 1){
				MusicList.Boss4 = LoadSoundMem("No.8.wav");
			}
			if (PlaySoundMem(MusicList.Boss4, DX_PLAYTYPE_LOOP, TRUE) == 0){
				CurrentBGM = MusicList.Boss4;
			}
			else{
				r = -1;
			}
			break;
		
		case 9:
			if (MusicList.Boss41 < 1){
				MusicList.Boss41 = LoadSoundMem("No.9.wav");
			}
			if (PlaySoundMem(MusicList.Boss41, DX_PLAYTYPE_LOOP, TRUE) == 0){
				CurrentBGM = MusicList.Boss41;
			}
			else{
				r = -1;
			}
			break;
		case 10:
			if (MusicList.Boss42 < 1){
				MusicList.Boss42 = LoadSoundMem("No.10.wav");
			}
			if (PlaySoundMem(MusicList.Boss42, DX_PLAYTYPE_LOOP, TRUE) == 0){
				CurrentBGM = MusicList.Boss42;
			}
			else{
				r = -1;
			}
			break;
		case 11:
			if (MusicList.Stage5 < 1){
				MusicList.Stage5 = LoadSoundMem("No.11.wav");
			}
			if (PlaySoundMem(MusicList.Stage5, DX_PLAYTYPE_LOOP, TRUE) == 0){
				CurrentBGM = MusicList.Stage5;
			}
			else{
				r = -1;
			}
			break;
		case 12:
			if (MusicList.Boss5 < 1){
				MusicList.Boss5 = LoadSoundMem("No.12.wav");
			}
			if (PlaySoundMem(MusicList.Boss5, DX_PLAYTYPE_LOOP, TRUE) == 0){
				CurrentBGM = MusicList.Boss5;
			}
			else{
				r = -1;
			}
			
			break;
		case 13:
			if (MusicList.Stage6A < 1){
				MusicList.Stage6A = LoadSoundMem("No.13.wav");
			}
			if (PlaySoundMem(MusicList.Stage6A, DX_PLAYTYPE_LOOP, TRUE) == 0){
				CurrentBGM = MusicList.Stage6A;
			}else{
			    r = -1;
			}
			
			break;
		case 14:
			if (MusicList.Boss6A < 1){
				MusicList.Boss6A = LoadSoundMem("No.14.wav");
			}
			if (PlaySoundMem(MusicList.Boss6A, DX_PLAYTYPE_LOOP, TRUE) == 0){
				CurrentBGM = MusicList.Boss6A;
			}else{
				r = -1;
			}
			break;
		case 15:
			if (MusicList.Final6A < 1){
				MusicList.Final6A = LoadSoundMem("No.15.wav");
			}
			if (PlaySoundMem(MusicList.Final6A, DX_PLAYTYPE_LOOP, TRUE) == 0){
				CurrentBGM = MusicList.Final6A;
			}else{
			    r = -1;
			}
			
			break;
		case 16:
			if (MusicList.EndingA < 1){
				MusicList.EndingA = LoadSoundMem("No.16.wav");
			}
			if (PlaySoundMem(MusicList.EndingA, DX_PLAYTYPE_LOOP, TRUE) == 0){
				CurrentBGM = MusicList.EndingA;
			}else{
				r = -1;
			}
			break;
		case 17:
			if (MusicList.Stage6B < 1){
				MusicList.Stage6B = LoadSoundMem("No.17.wav");
			}
			if (PlaySoundMem(MusicList.Stage6B, DX_PLAYTYPE_LOOP, TRUE) == 0){
				CurrentBGM = MusicList.Stage6B;
			}
			else{
				r = -1;
			}
			break;
		case 18:
			if (MusicList.Boss6B < 1){
				MusicList.Boss6B = LoadSoundMem("No.18.wav");
			}
			if (PlaySoundMem(MusicList.Boss6B, DX_PLAYTYPE_LOOP, TRUE) == 0){
				CurrentBGM = MusicList.Boss6B;
			}
			else{
				r = -1;
			}
			break;
		case 19:
			if (MusicList.Final6B < 1){
				MusicList.Final6B = LoadSoundMem("No.19.wav");
			}
			if (PlaySoundMem(MusicList.Final6B, DX_PLAYTYPE_LOOP, TRUE) == 0){
				CurrentBGM = MusicList.Final6B;
			}else{
			    r = -1;
			}
			break;
		case 20:
			if (MusicList.EndingB < 1){
				MusicList.EndingB = LoadSoundMem("No.20.wav");
			}
			if (PlaySoundMem(MusicList.EndingB, DX_PLAYTYPE_LOOP, TRUE) == 0){
				CurrentBGM = MusicList.EndingB;
			}else{
			    r = -1;
			}
			break;
		case 21:
			if (MusicList.StuffRoll < 1){
				MusicList.StuffRoll = LoadSoundMem("No.21.wav");
			}
			if (PlaySoundMem(MusicList.StuffRoll, DX_PLAYTYPE_LOOP, TRUE) == 0){
				CurrentBGM = MusicList.EndingB;
			}
			else{
				r = -1;
			}
			break;
		case 22:
			if (MusicList.Nouse1 < 1){
				MusicList.Nouse1 = LoadSoundMem("No.22.wav");
			}
			if (PlaySoundMem(MusicList.Nouse1, DX_PLAYTYPE_LOOP, TRUE) == 0){
				CurrentBGM = MusicList.Nouse1;
			}
			else{
				r = -1;
			}
			break;
		case 23:
			if (MusicList.Nouse2 < 1){
				MusicList.Nouse2 = LoadSoundMem("No.23.wav");
			}
			if (PlaySoundMem(MusicList.Nouse2, DX_PLAYTYPE_LOOP, TRUE) == 0){
				CurrentBGM = MusicList.Nouse2;
			}
			else{
				r = -1;
			}
			break;
		}
		r = _chdir("..");
		r = _chdir("..");
		r = ChangeVolumeSoundMem(BGMVolume, CurrentBGM);//デバッグ用
		if (r == -1){
			r = -1;
		}
		if (playable == false){
			StopSoundMem(CurrentBGM);
			r = 0;
		}
		return r;
	}
	int PorseMusic(){//ポーズした時にBGMを停止します。porseは再生中のBGMを表し、MusicListから選ばれます。
		if (StopSoundMem(CurrentBGM) == 0){
			return 0;
		}
		else{
			return -1;
		}
	}
	int PorseCancel(){//ポーズで停止させたBGMを再生させます。
		if (PlaySoundMem(CurrentBGM, DX_PLAYTYPE_LOOP, false) == 0){
			return 0;
		}
		else{
			return -1;
		}
	}
	int DisplayMusicList(int select,int musicup,int musicdown){
	    int r = 0;
		int mlistcount = musicup;
		int c = glay;
		int sx = 19;
		int sy = 119;
		char* name = 0;
		while(mlistcount <= musicdown){
			switch(mlistcount){
				case 0:
					name = MusicName.Title;
					break;
				case 1:
					name = MusicName.Stage1;
					break;
				case 2:
					name = MusicName.Boss1;
					break;
				case 3:
					name = MusicName.Stage2;
					break;
				case 4:
					name = MusicName.Boss2;
					break;
				case 5:
					name = MusicName.Stage3;
					break;
				case 6:
					name = MusicName.Boss3;
					break;
				case 7:
					name = MusicName.Stage4;
					break;
				case 8:
					name = MusicName.Boss4;
					break;
				case 9:
					name = MusicName.Boss41;
					break;
				case 10:
					name = MusicName.Boss42;
					break;
				case 11:
					name = MusicName.Stage5;
					break;
				case 12:
					name = MusicName.Boss5;
					break;
				case 13:
					name = MusicName.Stage6A;
					break;
				case 14:
					name = MusicName.Boss6A;
					break;
				case 15:
					name = MusicName.Final6A;
					break;
				case 16:
					name = MusicName.EndingA;
					break;
				case 17:
					name = MusicName.Stage6B;
					break;
				case 18:
					name = MusicName.Boss6B;
					break;
				case 19:
					name = MusicName.Final6B;
					break;
				case 20:
					name = MusicName.EndingB;
					break;
				case 21:
					name = MusicName.StuffRoll;
					break;
				case 22:
					name = MusicName.Nouse1;
					break;
				case 23:
					name = MusicName.Nouse2;
					break;
			}
			if(select == mlistcount){c = white;}
			if(DrawFormatString(sx,sy,c,"No.%d %s",mlistcount,name) != 0){return -1;}
		    sy += 15;
			mlistcount++;
			c = glay;
		}
		
		return r;
	}
	void DisplayMusicName(int request ,int flame){
		char* requestname = "";
		switch (request){
		case 1:
			requestname = MusicName.Stage1;
			break;
		case 2:
			requestname = MusicName.Boss1;
			break;
		case 3:
			requestname = MusicName.Stage2;
			break;
		case 4:
			requestname = MusicName.Boss2;
			break;
		case 5:
			requestname = MusicName.Stage3;
			break;
		case 6:
			requestname = MusicName.Boss3;
			break;
		case 7:
			requestname = MusicName.Stage4;
			break;
		case 8:
			requestname = MusicName.Boss4;
			break;
		case 9:
			requestname = MusicName.Boss41;
			break;
		case 10:
			requestname = MusicName.Boss42;
			break;
		case 11:
			requestname = MusicName.Stage5;
			break;
		case 12:
			requestname = MusicName.Boss5;
			break;
		case 13:
			requestname = MusicName.Stage6A;
			break;
		case 14:
			requestname = MusicName.Boss6A;
			break;
		case 15:
			requestname = MusicName.Final6A;
			break;
		case 16:
			requestname = MusicName.EndingA;
			break;
		case 17:
			requestname = MusicName.Stage6B;
			break;
		case 18:
			requestname = MusicName.Boss6B;
			break;
		case 19:
			requestname = MusicName.Final6B;
			break;
		case 20:
			requestname = MusicName.ExtraStage;
			break;
		case 21:
			requestname = MusicName.ExBoss1;
			break;
		case 22:
			requestname = MusicName.ExBoss2;
			break;
		}
		int len = (int)(strlen(requestname)) * 10 + 40;
		DrawFormatString(404 - len, 450, GetColor(255, 255, 255), "BGM %s",requestname);
	}
	void SetMusicVolume(int vol){//Optionで設定された音量を適用します。
		BGMVolume = vol;
		
	}
	void SetMusicPlayable(bool play){
		playable = play;
	}
	struct ongaku{
		int Title;
		int Stage1;
		int Boss1;
		int Stage2;
		int Boss2;
		int Stage3;
		int Boss3;
		int Stage4;
		int Boss4;
		int Boss41;
		int Boss42;
		int Stage5;
		int Boss5;
		int Stage6A;
		int Boss6A;
		int Final6A;
		int EndingA;
		int Stage6B;
		int Boss6B;
		int Final6B;
		int EndingB;
		int ExtraStage;
		int ExtraBoss1;
		int ExtraBoss2;
		int StuffRoll;
		int Nouse1;
		int Nouse2;

	};
	ongaku MusicList;
	static int CurrentBGM;//現在再生中の音楽を示す変数です。MusicRoomなどでの音楽の変更を制御します
	static int BGMVolume;//BGMの音量を示す変数です。0が最小で256が最大となります。ポーズがかかる時に音量が半分になりポーズがキャンセルすると音量が元に戻ります。
private:
	struct name{
		static char* Title;
		static char* Stage1;
		static char* Boss1;
		static char* Stage2;
		static char* Boss2;
		static char* Stage3;
		static char* Boss3;
		static char* Stage4;
		static char* Boss4;
		static char* Boss41;
		static char* Boss42;
		static char* Stage5;
		static char* Boss5;
		static char* Stage6A;
		static char* Boss6A;
		static char* Final6A;
		static char* EndingA;
		static char* Stage6B;
		static char* Boss6B;
		static char* Final6B;
		static char* EndingB;
		static char* ExtraStage;
		static char* ExBoss1;
		static char* ExBoss2;
		static char* StuffRoll;
		static char* Nouse1;
		static char* Nouse2;
		static char* MusicRoom;
		static char* Game;

	};
	name MusicName;
	static bool playable;
	int white, glay;//Music Roomのミュージックリストを表示する際に使用するカラー変数です。選択中の音楽名が白くなり、その他は灰色になります。
	int StartTime;
};

int Music::BGMVolume = 128;
int Music::CurrentBGM = 0;
bool  Music::playable = true;
char* Music::name::Title = "";
char* Music::name::Stage1 = "";
char* Music::name::Boss1 = "";
char* Music::name::Stage2 = "";
char* Music::name::Boss2 = "";
char* Music::name::Stage3 = "";
char* Music::name::Boss3 = "";
char* Music::name::Stage4 = "";
char* Music::name::Boss4 = "";
char* Music::name::Boss41 = "";
char* Music::name::Boss42 = "";
char* Music::name::Stage5 = "";
char* Music::name::Boss5 = "";
char* Music::name::Stage6A = "";
char* Music::name::Boss6A = "";
char* Music::name::Final6A = "";
char* Music::name::EndingA = "";
char* Music::name::Stage6B = "";
char* Music::name::Boss6B = "";
char* Music::name::Final6B = "";
char* Music::name::EndingB = "";
char* Music::name::ExtraStage = "";
char* Music::name::ExBoss1 = "";
char* Music::name::ExBoss2 = "";
char* Music::name::StuffRoll = "";
char* Music::name::Nouse1 = "";
char* Music::name::Nouse2 = "";
char* Music::name::Game = "";
#endif
