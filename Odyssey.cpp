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


int g_Title;                //タイトル画面の画像

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
/***********************************************
 * プログラムの開始
 ***********************************************/
int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, 
LPSTR lpCmdLine, int nCmdShow )
{
	SetMainWindowText( "マリオオデッセイ" ); // タイトルを設定

	ChangeWindowMode(TRUE); // ウィンドウモードで起動
	if ( DxLib_Init() == -1 ) return -1; // DX ライブラリの初期化処理

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