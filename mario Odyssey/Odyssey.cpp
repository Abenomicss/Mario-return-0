#include "DxLib.h"
#include <stdlib.h>


/***********************************************
 * 列挙体の宣言
 ***********************************************/
typedef enum GAME_MODE{
 GAME_TITLE = 0,
 GAME_INIT,
 GAME_MAIN,
 GAME_OVER,
 GAME_CLEAR,
 GAME_END,
 GAME_HELP,
};
/***********************************************
 * 変数の宣言
 ***********************************************/
int	g_OldKey;				// 前回の入力キー
int	g_NowKey;				// 今回の入力キー
int	g_KeyFlg;				// 入力キー情報
int g_PlayerImage;			//プレイヤーイメージ
int g_YosiImage;			//乗り物イメージ

float px=250,py = 250;	//プレイヤー位置座標
float speed = 0.5;		//プレイヤーの横移動のスピード

float speedtime = 0;	//プレイヤーのよこ移動の加速してる時間
float keytime = 0;		//プレイヤーのたて移動の押される時間
float gravityspeed = -1;//重力
int g_GameState = GAME_TITLE; // ゲームモード
/***********************************************
 * 関数のプロトタイプ宣言
 ***********************************************/
void GameInit(void);		//ゲーム初期化処理
void GameMain(void);		//ゲームメイン処理


void DrawGameTitle(void);	//ゲームタイトル処理
void DrawHelp(void);        //ゲームヘルプ処理
void DrawEnd(void);			//ゲームエンド処理
void DrawGameClear(void); //ゲームクリア処理
void DrawGameOver(void); //ゲームオーバー処理
void PlayerMove(void);		//プレイヤー移動関係
int LoadImages(void);	//画像読込み
/***********************************************
 * プログラムの開始
 ***********************************************/
int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, 
LPSTR lpCmdLine, int nCmdShow )
{
	SetMainWindowText( "マリオオデッセイ" ); // タイトルを設定

	ChangeWindowMode(TRUE); // ウィンドウモードで起動
	if ( DxLib_Init() == -1 ) return -1; // DX ライブラリの初期化処理

	if (-1 == LoadImages()) return -1;

	SetDrawScreen( DX_SCREEN_BACK ); // 描画先画面を裏にする

	
		// ゲームループ
	while ( ProcessMessage() == 0 && g_GameState != 99 && !(g_KeyFlg & PAD_INPUT_START)){
			 // 入力キー取得
			 g_OldKey = g_NowKey;
			 g_NowKey = GetJoypadInputState( DX_INPUT_KEY_PAD1 );
			 g_KeyFlg = g_NowKey & ~g_OldKey;

			 ClearDrawScreen(); // 画面の初期化

	 switch (g_GameState){

		 case 0:
			 DrawGameTitle(); //ゲームタイトル描画処理
			 break;
		case 1:
			 GameInit(); //ゲーム初期処理
			 break;
		 case 2:
			 GameMain(); //ゲームメイン描画処理
			 break;
		 case 3:
			 DrawGameOver(); //ゲームオーバー描画処理
			 break;
		 case 4:
			 DrawGameClear(); //ゲームCLEAR処理
			 break;
		 case 5:
			 DrawEnd(); //ゲームエンド描画処
			 break;
		 case 6:
			 DrawHelp();//ゲームヘルプ
			 break;
			 }
	 ScreenFlip(); // 裏画面の内容を表画面に反映
			 }
	 DxLib_End(); // DX ライブラリ使用の終了処理

	 return 0; // ソフトの終了
	}

/***********************************************
 * ゲームタイトル表示（メニュー画面）
 ***********************************************/
void DrawGameTitle(void)
{
	PlayerMove();

}
/***********************************************
 * ゲーム初期処理
 ***********************************************/
void GameInit(void)
{

}
/***********************************************
 * ゲームヘルプ描画処理
 ***********************************************/
void DrawHelp(void)
{

}
/***********************************************
 * ゲームエンド描画処理
 ***********************************************/
void DrawEnd(void)
{

}
/***********************************************
 * ゲームメイン
 ***********************************************/
void GameMain(void)
{

}
/***********************************************
 * プレイヤー移動関係
 ***********************************************/
void PlayerMove(void)
{
	DrawFormatString(290, 150, 0xFF0000, "加速度:%3f",speedtime);
	DrawFormatString(290, 100, 0xFF0000, "押さてれる時間:%3f",keytime);

	DrawRotaGraph(px-8,py-6,1,0,g_PlayerImage,TRUE);
	DrawRotaGraph(px,py,2,0,g_YosiImage,TRUE);
	//加速
	if ( g_NowKey & PAD_INPUT_RIGHT){
		px+= 1 + speed * speedtime;
		speedtime+=0.1;
	}
	


	
	if ( g_NowKey & PAD_INPUT_LEFT){
		px-= 1 + speed * speedtime;
		speedtime+=0.1;
	}


	//減速
	if (!(g_NowKey & PAD_INPUT_RIGHT) && !(g_NowKey & PAD_INPUT_LEFT)) {

	if (!(g_NowKey & PAD_INPUT_RIGHT)) {
		px+= 1 + speed * speedtime;
		if(speedtime>0){
			speedtime -= 0.5;
		}
	}

	if (!(g_NowKey & PAD_INPUT_LEFT)) {
		px-= 1 + speed * speedtime;
		if(speedtime>0){
			speedtime -= 0.5;
		}
	}

	}
	//ジャンプ
	if ( g_NowKey & PAD_INPUT_A){
		keytime+=0.1;
		py-= 5 + gravityspeed * keytime;

	}

	if (!( g_NowKey & PAD_INPUT_A)){
		py+= 5 + gravityspeed * keytime;

		

		if(keytime>0){
			keytime-=0.1;
		}
		
	}

	if(py>250){
			keytime=0;
			py=250;
		}
	/*if (!(g_NowKey & PAD_INPUT_RIGHT) && !(g_NowKey & PAD_INPUT_LEFT)) {

		if(speedtime>0){
			speedtime = 0;
		}
		

	}*/
}

/************************************************
*ゲームクリア処理　
**********************************************/
void DrawGameClear(void)
{

}
/***********************************************
 * ゲームオーバー画面処理
 ***********************************************/
void DrawGameOver(void)
{

}
/***********************************************
 * 画像読込み
 ***********************************************/
int LoadImages(){
	if((g_PlayerImage = LoadGraph("image/mario.png")) == -1) return -1;
	if((g_YosiImage = LoadGraph("image/yosi.png")) == -1) return -1;
	return 0;
}