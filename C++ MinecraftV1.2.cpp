#include <bits/stdc++.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#define getch(); _getch();
using namespace std;
const int MAX_PLAYER=64;
const string nextversion="起床战争16人局";
string random_list[MAX_PLAYER]={"管理员","RAngle","Xiaogege1023","Sapnap1023","Terrablade","Shamiko","haojihui233"};
string name,place="村庄";//玩家名字，玩家地点
//村庄 平原 森林 洞穴 沙漠 从林 雪地 地狱 末地 
//边境之地 
int maxhealth=20,health=20,basicmagic=10,magic=10,maxmagic=basicmagic,basicattack=2,attack=basicattack,attack2=basicattack,defense=0,money=0,experience=0,level=1,basicspeed=2,speed=basicspeed;//玩家基础数据
int xp_orb=0; //压缩经验球 
int credit=50;//信誉值，玩家无法看见 
int weapon1=0,weapon2=0,tool1=0,tool2=0,attackdis1=2,attackdis2=8;//武器，工具 
int armor1=0,armor2=0,armor3=0,armor4=0; //头盔 胸甲 护腿 靴子 
string weapon1name[50]={"空手","木剑","石剑","金剑","铁剑","钻石剑","下界合金剑","流浪者之利剑","远古之剑","源古剑","寒冰之剑","寒霜剑"}; 
int weapon1attack[50]={0,4,5,4,6,7,8,7,9,0,0,0};
string weapon2name[10]={"无","护盾","弓","","狙击者·弓"}; 
int weapon2attack[10]={0,0,4,0,6,0,0};
int weapon2attackdis[10]={0,0,8,0,10};
int arrow[10]={0,0};//箭矢 
string arrowname[10]={"无","箭"};//箭矢名 
string tool1name[50]={"无","木斧","石斧","金斧","铁斧","钻石斧","下界合金斧","流浪者之重斧","远古之斧","源古斧","寒冰之斧","寒霜斧"}; 
int tool1speed[50]={12,20,25,60,40,46,58,42,60,0,0,0};
string tool2name[50]={"无","木稿","石稿","金稿","铁稿","钻石稿","下界合金稿","流浪者之钝稿","远古之稿","源古稿","寒冰之稿","寒霜稿"}; 
int tool2speed[50]={0,30,36,70,48,56,65,36,68,0,0,0};
string armor1name[50]={"无","皮革头盔","锁链头盔","金头盔","铁头盔","钻石头盔","下界合金头盔","流浪者之旅帽","远古头盔","源古头盔","寒冰头盔","寒霜头盔"};
string armor2name[50]={"无","皮革胸甲","锁链胸甲","金胸甲","铁胸甲","钻石胸甲","下界合金胸甲","流浪者之外甲","远古胸甲","源古胸甲","寒冰胸甲","寒霜胸甲"};
string armor3name[50]={"无","皮革护腿","锁链护腿","金护腿","铁护腿","钻石护腿","下界合金护腿","流浪者之护腿","远古护腿","源古护腿","寒冰护腿","寒霜护腿"};
string armor4name[50]={"无","皮革靴子","锁链靴子","金靴子","铁靴子","钻石靴子","下界合金靴子","流浪者之护履","远古靴子","源古靴子","寒冰靴子","寒霜靴子"};
int armor1defense[50]={0,2,3,2,4,4,5,4,6,0,0,0};
int armor2defense[50]={0,3,4,4,5,7,8,6,8,0,0,0};
int armor3defense[50]={0,3,4,3,5,6,7,5,8,0,0,0};
int armor4defense[50]={0,1,2,2,3,3,4,3,6,0,0,0}; 
//0空手 
bool nether=false,ender=false,farland=false;//地狱门&末地门 建造/发现 边境之地 

bool jungle_temple=false,desert_temple=false,woodland_mansion=false,stronghold=false,nether_fortress=false,bastion_remnants=false,end_city=false; 
//丛林神庙  沙漠神殿  林地府邸  要塞  下界要塞  猪灵堡垒  末地城 
int time_last[10]={},time_now; 
int hard,hard_max[10]={0,1,1,1,1,1,1,1};//难度

bool dead=false,defend=false,blessing=false;//敌人死亡 防御状态 notch祝福 
bool help=false; 
bool crafttable=false,furnace=false,smithtable=false,crafttable2=false;//工作台 熔炉 锻造台 中级工作台 
bool undeadattack=false;//亡灵入侵
int attacklevel=0; 
int diamondapple=0;//钻石苹果 
int magicup=1;
int badguy=0,weaponcheck=0,blesscold=0;
int task1=0;//task1:旅行家 收集10橡木 
string version="1.2",ver="1.2";
int choose;//工具
int saving=0,reading=0,cheat=0;
long long bag[10001]={};//背包 
int l[MAX_PLAYER];
inline void show(){
	system("start chrome.exe https://www.luogu.com.cn/user/559506");
	return ;
}
inline void cleanmirrow(){
	system("cls");
	return ;
}
string itemname[1000]={"",
	"橡木","丛林木","针叶木","绯红菌柄","橡木木板","从林木木板","针叶木木板","绯红木板",
	"工作台","木棍","木剑","木斧","木稿","圆石","石剑","石斧",
	"石稿","熔炉","煤炭","铁矿石","铁锭","铁剑","铁斧","铁镐",
	"铁头盔","铁胸甲","铁护腿","铁靴子","护盾","弓","金矿石","金锭",
	"金剑","金斧","金稿","苹果","金苹果","线","金头盔","金胸甲",//40
	"金护腿","金靴子","青金石","钻石","钻石剑","钻石斧","钻石镐","钻石头盔",
	"钻石胸甲","钻石护腿","钻石靴子","钻石块","钻石苹果","锻造台","远古残骸","下界合金碎片",
	"下界合金锭","下界合金剑","下界合金斧","下界合金稿","下界合金头盔","下界合金胸甲","下界合金护腿","下界合金靴子",
	"黑曜石","重击技能书","三连击技能书","穿云箭技能书","反弹技能书","疯狂技能书","魔力护盾技能书","力量技能书",
	"魔力精通技能书","闪避技能书","连击技能书","健康技能书", "空气斩技能书","冲刺技能书","治疗技能书","冥想技能书",//80
	"脆弱化技能书","以攻为守技能书","伤害吸收技能书","防守姿态技能书","战斗姿态技能书","冲锋姿态技能书","透察技能书","铁皮技能书",
	"节能技能书","吸血技能书","生死约技能书","最后一搏技能书","减速术技能书","疾跑技能书","愤怒技能书","魔力源泉技能书",
	"冰冻技能书","嘲讽技能书","虚弱技能书","禁锢技能书","淬魔技能书","创造技能书","破坏技能书","创世技能书",
	"流浪者之利剑","流浪者之重斧","流浪者之钝稿","流浪者之旅帽 ","流浪者之外甲","流浪者之护腿","流浪者之护履","狙击者·弓", 
	"皮革头盔","皮革胸甲","皮革护腿","皮革靴子","锁链头盔","锁链胸甲","锁链护腿","锁链靴子",//120
	"末影珍珠","烈焰棒","烈焰粉","末影之眼","金粒","下界石英","中级工作台","远古精华",
	"远古锭","远古之剑","远古之斧","远古之稿","远古头盔","远古胸甲","远古护腿","远古靴子",
	"源古锭","源古剑","源古斧","源古稿","源古头盔","源古胸甲","源古护腿","源古靴子",
	"寒冰锭","寒冰之剑","寒冰之斧","寒冰之稿","寒冰头盔","寒冰胸甲","寒冰护腿","寒冰靴子",
	"寒霜锭","寒霜剑","寒霜斧","寒霜稿","寒霜头盔","寒霜胸甲","寒霜护腿","寒霜靴子",
	"寒冰精华","","","","","","","",
	"","","","","","","","",
	"","","","","","","","",
};//物品名 
int itemtype[1000]={0,//物品种类  0，普通物品/材料  1，主手  2，副手  3,斧子  4，稿子  5，头  6，身  7，腿  8，脚  9，药水  10，箭矢  
	0,0,0,0,0,0,0,0,//8
	0,0,1,3,4,0,1,3,
	4,0,0,0,0,1,3,4,
	5,6,7,8,2,2,0,0,
	1,3,4,0,0,0,5,6,//40
	7,8,0,0,1,3,4,5,
	6,7,8,0,0,0,0,0,
	0,1,3,4,5,6,7,8,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,//80
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	1,3,4,5,6,7,8,2, 
	5,6,7,8,5,6,7,8,//120
	0,0,0,0,0,0,0,0,
	0,1,3,4,5,6,7,8,
	0,1,3,4,5,6,7,8,
	0,1,3,4,5,6,7,8,
	0,1,3,4,5,6,7,8,
};
int itemlevel[1000]={0,//物品等级 
	0,0,0,0,0,0,0,0,//8
	0,0,1,1,1,0,2,2,
	2,0,0,0,0,4,4,4,
	4,4,4,4,1,2,0,0,
	3,3,3,0,0,0,3,3,//40
	3,3,0,0,5,5,5,5,
	5,5,5,0,0,0,0,0,
	0,6,6,6,6,6,6,6,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,//80
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	7,7,7,7,7,7,7,4, 
	1,1,1,1,2,2,2,2,//120
	0,0,0,0,0,0,0,0,
	0,8,8,8,8,8,8,8,
	0,9,9,9,9,9,9,9,
	0,10,10,10,10,10,10,10,
	0,11,11,11,11,11,11,11,
};
int item_sell_num[1000]={0, //出售数量 
	32,32,32,32,128,128,128,128,//8
	0,0,0,0,0,64,0,0,
	0,0,16,16,12,2,2,2,
	1,1,1,1,0,0,16,12,
	2,2,2,8,1,4,1,1,//40
	1,1,16,2,1,2,2,2,//48
	1,2,1,2,1,0,1,1,//56
	1,1,1,1,1,1,1,1,//64
	2,1,1,1,1,1,1,1,//72
	1,1,1,1,1,1,1,1,//80
	1,1,1,1,1,1,1,1,
	1,1,1,1,1,1,1,1,
	1,1,1,1,1,1,1,1,
	1,1,1,1,1,1,1,1,
	2,2,2,2,2,2,2,2,//120
	4,2,4,2,64,16,0,1,
	1,1,1,1,1,1,1,1,
	1,1,1,1,1,1,1,1,
	1,1,1,1,1,1,1,1,
	1,1,1,1,1,1,1,1, 
};
int item_sell_price[1000]={0,//出售价格 
	1,1,1,1,1,1,1,1,//8
	0,0,0,0,0,1,0,0,
	0,0,1,3,3,1,1,1,
	1,2,2,1,0,0,4,5,
	1,2,2,2,3,1,2,3,//40
	3,2,3,1,1,3,3,5,//48
	4,7,2,9,12,0,1,1,//56
	5,6,6,6,7,8,8,7,//64
	1,5,5,5,5,5,5,5,//72
	5,5,5,5,5,5,5,5,//80
	5,5,5,5,5,5,5,5,
	5,5,5,5,5,5,5,5,
	5,5,5,5,5,5,5,5,
	5,3,4,3,4,4,3,6,
	1,1,1,1,1,1,1,1,//120
	1,1,1,1,3,2,0,1,
	4,8,12,12,20,32,28,16,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
};
string posionname[1000]={"",//当作者发现药水的英文事POTION而不是POSION时，想改已经来不及力（悲 作者真是sb（ 
	"治疗药水","魔力药水","治疗药水II","魔力药水II","治疗药水III","魔力药水III","治疗药水IV","魔力药水IV",
	"速度药水","力量药水","速度药水II","力量药水II","速度药水III","力量药水III","","", 
	"","","","","","","","",
};
struct item{
	string itemname;
	int type;
	int level;
	int sell_num;
	int sell_price; 
}item[10000]; 
/*物品编号：
  
  1橡木  2从林木  3针叶木  4绯红菌柄  5橡木木板  6从林木木板  7针叶木木板  8绯红木板  
  9工作台  10木棍  11木剑  12木斧  13木稿  14圆石  15石剑  16石斧 
  17石稿  18熔炉  19煤炭  20铁矿石  21铁锭  22铁剑  23铁斧  24铁镐
  25铁头盔  26铁胸甲  27铁护腿  28铁靴子  29护盾  30弓  31金矿石  32金锭
  33金剑  34金斧  35金稿  36苹果  37金苹果  38线  39金头盔  40金胸甲 
  41金护腿  42金靴子  43青金石  44钻石  45钻石剑  46钻石斧  47钻石镐  48钻石头盔
  49钻石胸甲  50钻石护腿  51钻石靴子  52钻石块  53钻石苹果  54锻造台  55远古残骸  56下界合金碎片 
  57下界合金锭  58下界合金剑  59下界合金斧  60下界合金稿  61下界合金头盔  62下界合金胸甲  63下界合金护腿  64下界合金靴子
  65黑曜石  66重击技能书  67三连击技能书  68穿云箭技能书  69反弹技能书  70疯狂技能书  71魔力护盾技能书  72力量技能书
  73魔力精通技能书  74闪避技能书  75连击技能书  76健康技能书  77空气斩技能书  78冲刺技能书  79治疗技能书  80冥想技能书
  81脆弱化技能书  82以攻为守技能书  83伤害吸收技能书  84防守姿态技能书  85战斗姿态技能书  86冲锋姿态技能书  87透察技能书  88铁皮技能书
  89节能技能书  90吸血技能书  91生死约技能书  92最后一搏技能书  93减速术技能书  94疾跑技能书  95愤怒技能书  96魔力源泉技能书
  97冰冻技能书  98嘲讽技能书  99虚弱技能书  100禁锢技能书  101淬魔技能书  102创造技能书  103破坏技能书  104创世技能书
  105流浪者之利剑  106流浪者之重斧  107流浪者之钝稿  108流浪者之旅帽  109流浪者之外甲  110流浪者之护腿  111流浪者之护履  112狙击者 ·弓 
  113皮革头盔  114皮革胸甲  115皮革护腿  116皮革靴子  117锁链头盔  118锁链胸甲  119锁链护腿  120锁链靴子 
  121末影珍珠  122烈焰棒  123烈焰粉  124末影之眼  125金粒  126下界石英  127中级工作台  128远古精华 
  129远古锭  130远古之剑  131远古之斧  132远古之稿  133远古头盔  134远古胸甲  135远古护腿  136远古靴子
  137源古锭  138源古剑  139源古斧  140源古稿  141源古头盔  142源古胸甲  143源古护腿  144源古靴子
  145寒冰锭  146寒冰之剑  147寒冰之斧  148寒冰之稿  149寒冰头盔  150寒冰胸甲  151寒冰护腿  152寒冰靴子
  153寒霜锭  154寒霜剑  155寒霜斧  156寒霜稿  157寒霜头盔  158寒霜胸甲  159寒霜护腿  160寒霜靴子 
  161寒冰精华 
  
  Potion Name 药水编号 
  
  1001治疗药水  1002魔力药水  1003治疗药水II  1004魔力药水II  1005治疗药水III  1006魔力药水III  1007治疗药水IV  1008魔力药水IV 
  1009速度药水  1010力量药水  1011速度药水II  1012力量药水II  1013速度药水III  1014力量药水III  1015速度药水IV  1016力量药水IV 
  
 */
int enemyskill[100]={};
int enemyskillcold[100]={};
int skill[100]={0,//技能等级 
	1,0,0,0,0,0,0,0, 
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0};
int skillmax[100]={0,//技能最高级 
	1,3,3,3,3,2,3,2,
	5,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	3,0,0,0,0,0,0,0};
int skillcold[100]={0,//技能冷却 
	0,2,2,3,2,3,1,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	6,0,0,0,0,0,0,0,
	
	4,6,0,0,0,0,0,0};
//Enemyskill
int skillcoldnow[100]={};//战斗时，当前技能冷却 
int skillmagic[100]={0,//技能消耗魔力 
	5,6,6,7,6,6,8,0, 
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	15,0,0,0,0,0,0,0};
string skillname[100]={"",//技能名 
	/*C*/ "侦察","重击","三连击","穿云箭","反弹","疯狂","魔力护盾","力量",
	"魔力精通","闪避","连击","健康", /*B*/ "空气斩","冲刺","治疗","冥想",
	"脆弱化","以攻为守","伤害吸收","防守姿态","战斗姿态","冲锋姿态","透察","铁皮",
	"节能", /*A*/ "吸血","生死约","最后一搏","减速术","疾跑","愤怒","魔力源泉",
	/*S*/ "冰冻","嘲讽","虚弱","禁锢","淬魔","创造","破坏","创世",
	/*敌人技能*/"减速箭","巨力重拳","狭小场地10","",
}; 
bool skilltake[100]={0,1};
int skilltakemax=3,skilltakenow=1;
struct skill{//技能函数 
	string skillname;
	char rarity;
	bool skilltake;
	int level_now;
	int level_max;
	int cold[20];
	int cold_now;
	int magic[20]; 
	int num[20],levelup[20][20][3],xp_orb[20],level[20];
	/*
	  
	  skillname:技能名
	  rarity:稀有度
	  skilltake:技能是否装备 
	  level_max:等级上限
	  magic[i]:第i级消耗魔力
	  cold[i]:第i级冷却 
	  num[i]:第i次升级所需的物品数量 
	  levelup[i][j][1]:第i个升级所需第j个物品编号 
	  levelup[i][j][2]:第i个升级所需第j个物品数量 
	  xp_orb[i]第i次升级所需的经验球数量
	  level[i]第i次升级需要的等级
	  
	  写得很详细，有bug也好改（） 也方便某些人看我的代码 
	  
	 */ 
}sk[10000];
inline void color(string s,int front_color,int back_color){//Colorrrrr
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|back_color*16|FOREGROUND_INTENSITY|front_color);//csdn
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|1|14);
	cout<<s;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|7);
	return;
} 
/*color
  0 = 黑色 8 = 灰色
  1 = 蓝色 9 = 淡蓝色
  2 = 绿色 10 = 淡绿色
  3 = 浅绿色 11 = 淡浅绿色
  4 = 红色 12 = 淡红色
  5 = 紫色 13 = 淡紫色
  6 = 黄色 14 = 淡黄色
  7 = 白色 15 = 亮白色
 */
string tips[300]={"",//SB
	"要致富，先撸树！","Creeper？ aw man",
	"So we back in the mine","你知道吗，作者是0303！",
	"附魔师可以为你增加魔力，却不能附魔","一刀999，打怪爆神装！",
	"cout<<tips[7];","你知道吗？这是一款用C++写的游戏",
	"你的近战攻击距离很短♂","tips功能是1.11.4版本加入的哦！",
	/*10*/
	"在商店里可以购买技能书","附魔师可以压缩你的经验——但是收费。",
	"有弓没有箭？去村庄商店看看吧。","做坏事是会有报应的。",
	"打字不要打一半，尤其是","作弊是一种可耻的行为！",
	"战斗时如果选择了不能使用的选项会浪费一回合。","tips:tips:tips:tips:tip",
	"你知道吗？tips很多都是废话","你知道游戏里有多少条tips吗？",
	/*20*/
	"你知道攻击伤害浮动的比例是多少吗？","你在摸鱼吗？",
	"本游戏仅在HFOJ上发布，转载请标明作者","cxh是个蒟蒻",
	"看tips干嘛","有一些矿石需要高级的稿子才能挖掘。",
	"有没有一把稿子能挖各种矿洞里的矿呢？","绿宝石就是拿来花的！",
	"【这条tips已被删除】", "不是所有的地方都能砍树",
	/*30*/
	"在战斗使用技能，给敌人致命一击！","钻石苹果...钻石块...",
	"既然懒得挖矿，干脆去洞穴探险吧！","今天你写作业了吗？",
	"你羊了吗？","该给你写点什么tips好呢...(思考)",
	"return 0;","如果你是新手，不妨看看新手教程。",
	"有人能帮我写剩下的内容吗（","今夕是何年？",
	/*40*/
	"Whatever you choose is your choise.","Trust yourself.",
	"(smile).","WHAT DID YOU DO WHAT ARE YOU DOING WHAT WILL YOU DO",
	"Create the world by yourself.","meit doog a evah.",
	"Nothing serious","Just do it.",
	"sus","love or be loved",
	/*50*/
	"治疗药水会根据你的生命上限回复血量。","治疗药水的回复量是有上限的", 
	"流浪商人收购一些东西，如果你有，不妨卖掉它们。","你的攻击伤害并不是固定的。",
	"你知道吗？其实面对难缠的敌人，你可以逃跑。","你移动的距离不能大于你的速度！",
	"并非遇见所有敌人都可以逃跑。","逃跑有概率失败。",
	"你可以在背包查看物品的信息。","挖矿可以获得经验。",
	/*60*/ 
	"附魔师对于技能有着独特的了解。","Welcome to 1.12(.2)！",
	"新版本，新tips！","传说在遥远的丛林里，隐藏着一座远古的神庙...",
	"技能可不是你一个人的特殊能力！","你知道本游戏第一个S级技能怎么获得吗？",
	"为什么没有苦力怕呢？","对于大部分BOSS来说，一般都会拥有技能。",
	"打怪除了绿宝石，还可能有装备和材料！","I love you！",
	/*70*/
	"Never gonna give you up!","你知道tips功能加入来自哪里吗？",
	"Never gonna let you down~","tips绝对不会骗人！give u up~",
	"你说得对，但是MINECRAFT是由Mojang开发的一款沙盒游戏","石头有什么用？",
	"流浪商人收购石头？真是不可理喻。","每个版本都会添加新的tips！",
	"抽奖有风险。","如果你的运气好，不妨试试村庄里的抽奖机！",
	/*80*/ 
	"记得保存哦！","长时间使用电子产品对眼睛不好！",
	"6","完了，编不出tips了",
	"Wow~ You can really dance~","现在是什么版本？",
	"强大的敌人一般有更好的掉落物","你见过末影人吗？",
	"会不会有地方需要探险才能发现呢？","废弃的地狱传送门可能遍布在世界的各处...",
	/*90*/
	"绿宝石珍贵吗？不珍贵。","每个玩家都自带一个技能！",
	"死亡并不可怕...","实际上，绝大多数情况下死亡不会掉落东西",
	"流浪商人会出售一些独特的物品...","平原有一位旅行家，但似乎他被困在那了...",
	"有时候，副手武器能帮你大忙。","弓不仅可以通过打怪获得，还能自己制造！",
	"多去其他地方逛逛，总有惊喜。","哼，哼，啊啊啊啊啊啊",
	/*100*/ 
	"bdsm","存档文件可以保存到别处使用",
	"Bark","我对【】说话！",
	"升级可以在商店里出售更多东西。","技能的获得方式有很多种！",
	"在村庄里有一座旅馆，去休息可以恢复生命","RP++",
	"不要修改你的存档文件！","猪灵有时候不会攻击你。why？",
	/*110*/
	"你在期待什么？","新的版本，新的bug！（划",
	"在此对所有支持本游戏的玩家表示感谢！","如有bug请反馈。",
	"地狱的深处藏有坚固的矿石...","村庄里曾有一位恶霸肆意妄为...",
	"真的有人会看这些吗？","如果有人能帮我写游戏——哪怕是tips也好！",
	"树上有苹果，拿下来！","钻石苹果是一种神奇的物品，能增加你的生命。",
	/*120*/
	"你知道吗，我不知道","zhi yin ni tai mei",
	"商店会收购物品，但不收购垃圾（","战斗时你每回合都会回复魔力！",
	"升级可以增加可出售的物品数量！","有时怪物会掉落技能书。",
	"一般来说，越强的怪掉落物越好！...虽然也可能没有","A Super Tip has spawn somewhere！",
	"商店里总会有一本技能书。","升级技能有时需要压缩经验球！", 
};

inline void HideCursor(){//隐藏光标 
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO CursorInfo;
	GetConsoleCursorInfo(handle, &CursorInfo);//获取控制台光标信息
	CursorInfo.bVisible = false; //隐藏控制台光标
	SetConsoleCursorInfo(handle, &CursorInfo);//设置控制台光标状态
}

inline void gotoxy(int x,int y){
	COORD pos;//这里的pos是一个结构体
	pos.X=x;//横坐标
	pos.Y=y;//纵坐标
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);//移动光标
}

inline void destroy(int time,int speed){//进度条 
	for(int i=0;i<100;i++){//为什么函数名叫destroy? 
		system("cls");
		cout<<"进度：已完成 "<<i<<" %"<<endl;
		Sleep(time/speed/300);
		if(i%3==0) SetConsoleTitle("Working."); 
		Sleep(time/speed/300);
		if(i%3==1) SetConsoleTitle("Working..");
		Sleep(time/speed/300);
		if(i%3==2) SetConsoleTitle("Working..."); 
	}
	system("cls"); 
	cout<<"进度：已完成 "<<100<<" %"<<endl;
	Sleep(500);
	system("cls"); 
	return;
}

inline void say(string word,int time){//说话内容 停顿 
	for(int i=0;i<=word.length();i++){
		cout<<word[i];//输出字符 
		Sleep(time);//停顿time ms 
	}
	return;
} 

int levelup(int xp){//升级 返回升的等级数 
	if(xp<level*100){
		experience=xp;
		return 0;
	} 
	else{
		xp-=level*100;
		level++;
		return 1+levelup(xp);
	}
}

struct craft{
	int num1,amount1;
	int num2,amount2;
	int num3,amount3;
	int num4,amount4;
	int condition1,condition2;
	bool con(){//一个条件检测 
		switch(condition1){
		case 0:
			return true;    
			break;
		case 1:
			if(crafttable) return true;
			else return false; 
			break;
		case 2:
			if(furnace) return true;
			else return false; 
			break;
		case 3:
			if(smithtable) return true;
			else return false; 
			break;
		case 4:
			if(crafttable2) return true;
			else return false; 
			break;
		}
		return 0;
	}
	
	bool con2(){//还是一个条件检测 
		switch(condition2){
		case 0:
			return true;    
			break;
		case 1:
			if(crafttable) return true;
			else return false; 
			break;
		case 2:
			if(furnace) return true;
			else return false; 
			break;
		case 3:
			if(smithtable) return true;
			else return false; 
			break;
		case 4:
			if(crafttable2) return true;
			else return false; 
			break;
		}
		return 0;
	}
}craft[10000];

inline void add_craft(int c_num,int c_num1,int c_amount1,int c_num2,int c_amount2,int c_num3,int c_amount3,int c_num4,int c_amount4,int c_condition1,int c_condition2){//添加合成配方 
	craft[c_num].num1=c_num1;//物品1编号 
	craft[c_num].num2=c_num2;
	craft[c_num].num3=c_num3;
	craft[c_num].num4=c_num4;
	craft[c_num].amount1=c_amount1;//物品1数量 
	craft[c_num].amount2=c_amount2;
	craft[c_num].amount3=c_amount3;
	craft[c_num].amount4=c_amount4;
	craft[c_num].condition1=c_condition1;//条件1 
	craft[c_num].condition2=c_condition2;
	return;
}

inline void create(){//合成
	SetConsoleTitle("--合成--");
//合成配方 
	int asswecan=1;
	add_craft(asswecan++,5,4,1,1,0,0,0,0,0,0);//木板 
	add_craft(asswecan++,6,4,2,1,0,0,0,0,0,0);
	add_craft(asswecan++,7,4,3,1,0,0,0,0,0,0);
	add_craft(asswecan++,8,4,4,1,0,0,0,0,0,0);
	add_craft(asswecan++,9,1,5,4,0,0,0,0,0,0);//工作台 
	add_craft(asswecan++,9,1,6,4,0,0,0,0,0,0);
	add_craft(asswecan++,9,1,7,4,0,0,0,0,0,0);
	add_craft(asswecan++,9,1,8,4,0,0,0,0,0,0);
	add_craft(asswecan++,10,4,5,2,0,0,0,0,0,0);//木棍 
	add_craft(asswecan++,10,4,6,2,0,0,0,0,0,0);
	add_craft(asswecan++,10,4,7,2,0,0,0,0,0,0);
	add_craft(asswecan++,10,4,8,2,0,0,0,0,0,0);
	add_craft(asswecan++,11,1,5,2,10,1,0,0,1,0);//木剑 
	add_craft(asswecan++,11,1,6,2,10,1,0,0,1,0);
	add_craft(asswecan++,11,1,7,2,10,1,0,0,1,0);
	add_craft(asswecan++,11,1,8,2,10,1,0,0,1,0);
	add_craft(asswecan++,12,1,5,3,10,2,0,0,1,0);//木斧 
	add_craft(asswecan++,12,1,6,3,10,2,0,0,1,0);
	add_craft(asswecan++,12,1,7,3,10,2,0,0,1,0);
	add_craft(asswecan++,12,1,8,3,10,2,0,0,1,0);
	add_craft(asswecan++,13,1,5,3,10,2,0,0,1,0);//木稿 
	add_craft(asswecan++,13,1,6,3,10,2,0,0,1,0);
	add_craft(asswecan++,13,1,7,3,10,2,0,0,1,0);
	add_craft(asswecan++,13,1,8,3,10,2,0,0,1,0);
	add_craft(asswecan++,15,1,14,2,10,1,0,0,1,0);//石剑
	add_craft(asswecan++,16,1,14,3,10,2,0,0,1,0);//石斧 
	add_craft(asswecan++,17,1,14,3,10,2,0,0,1,0);//石稿 
	add_craft(asswecan++,18,1,14,8,0,0,0,0,1,0);//熔炉 
	add_craft(asswecan++,21,1,19,1,20,1,0,0,2,0);//铁锭
	add_craft(asswecan++,22,1,21,2,10,1,0,0,1,0);//铁剑
	add_craft(asswecan++,23,1,21,3,10,2,0,0,1,0);//铁斧  
	add_craft(asswecan++,24,1,21,3,10,2,0,0,1,0);//铁稿
	add_craft(asswecan++,25,1,21,5,0,0,0,0,1,0);//铁头盔 
	add_craft(asswecan++,26,1,21,8,0,0,0,0,1,0);//铁胸甲 
	add_craft(asswecan++,27,1,21,7,0,0,0,0,1,0);//铁护腿  
	add_craft(asswecan++,28,1,21,4,0,0,0,0,1,0);//铁靴子
	add_craft(asswecan++,29,1,21,1,5,6,0,0,1,0);//盾牌 
	add_craft(asswecan++,29,1,21,1,6,6,0,0,1,0);
	add_craft(asswecan++,29,1,21,1,7,6,0,0,1,0);
	add_craft(asswecan++,29,1,21,1,8,6,0,0,1,0);
	add_craft(asswecan++,30,1,38,3,10,3,0,0,1,0);//弓 
	add_craft(asswecan++,32,1,19,1,31,1,0,0,2,0);//金锭
	add_craft(asswecan++,32,1,125,9,0,0,0,0,1,0);//金锭 
	add_craft(asswecan++,33,1,32,2,10,1,0,0,1,0);//金剑
	add_craft(asswecan++,34,1,32,3,10,2,0,0,1,0);//金斧  
	add_craft(asswecan++,35,1,32,3,10,2,0,0,1,0);//金稿
	add_craft(asswecan++,37,1,36,1,32,8,0,0,1,0);//金苹果 
	add_craft(asswecan++,38,1,32,5,0,0,0,0,1,0);//金头盔 
	add_craft(asswecan++,39,1,32,8,0,0,0,0,1,0);//金胸甲 
	add_craft(asswecan++,40,1,32,7,0,0,0,0,1,0);//金护腿  
	add_craft(asswecan++,41,1,32,4,0,0,0,0,1,0);//金靴子1 
	add_craft(asswecan++,44,9,52,8,0,0,0,0,0,0);//钻石块->钻石
	add_craft(asswecan++,52,1,44,9,0,0,0,0,1,0);//钻石块
	add_craft(asswecan++,45,1,44,2,10,1,0,0,1,0);//钻石剑
	add_craft(asswecan++,46,1,44,3,10,2,0,0,1,0);//钻石斧  
	add_craft(asswecan++,47,1,44,3,10,2,0,0,1,0);//钻石稿
	add_craft(asswecan++,48,1,44,5,0,0,0,0,1,0);//钻石头盔 
	add_craft(asswecan++,49,1,44,8,0,0,0,0,1,0);//钻石胸甲 
	add_craft(asswecan++,50,1,44,7,0,0,0,0,1,0);//钻石护腿  
	add_craft(asswecan++,51,1,44,4,0,0,0,0,1,0);//钻石靴子 
	add_craft(asswecan++,53,1,52,2,37,1,0,0,1,0);//钻石苹果 
	add_craft(asswecan++,54,1,5,4,21,2,0,0,1,0);//锻造台 
	add_craft(asswecan++,54,1,6,4,21,2,0,0,1,0);
	add_craft(asswecan++,54,1,7,4,21,2,0,0,1,0);
	add_craft(asswecan++,54,1,8,4,21,2,0,0,1,0);
	add_craft(asswecan++,56,1,19,1,55,1,0,0,2,0);//下界合金碎片 
	add_craft(asswecan++,57,1,56,4,32,4,0,0,1,0);//下界合金锭
	add_craft(asswecan++,58,1,45,1,57,1,0,0,3,0);//下界合金剑
	add_craft(asswecan++,59,1,46,1,57,1,0,0,3,0);//下界合金斧  
	add_craft(asswecan++,60,1,47,1,57,1,0,0,3,0);//下界合金稿
	add_craft(asswecan++,61,1,48,1,57,1,0,0,3,0);//下界合金头盔 
	add_craft(asswecan++,62,1,49,1,57,1,0,0,3,0);//下界合金胸甲 
	add_craft(asswecan++,63,1,50,1,57,1,0,0,3,0);//下界合金护腿  
	add_craft(asswecan++,64,1,51,1,57,1,0,0,3,0);//下界合金靴子
	add_craft(asswecan++,127,1,9,1,21,4,44,4,1,0);//中级工作台 
	add_craft(asswecan++,129,1,128,3,21,6,32,6,4,0);//远古锭
	add_craft(asswecan++,130,1,129,2,10,1,0,0,4,0);//远古之剑
	add_craft(asswecan++,131,1,129,3,10,1,0,0,4,0);//远古之斧 
	add_craft(asswecan++,132,1,129,3,10,1,0,0,4,0);//远古之稿 
	add_craft(asswecan++,133,1,129,5,0,0,0,0,4,0);//远古头盔 
	add_craft(asswecan++,134,1,129,8,0,0,0,0,4,0);//远古胸甲 
	add_craft(asswecan++,135,1,129,7,0,0,0,0,4,0);//远古护腿 
	add_craft(asswecan++,136,1,129,4,0,0,0,0,4,0);//远古靴子 
	while(1){
		system("cls");
		cout<<"以下是你可以合成的物品列表。"<<endl;
		cout<<"输入合成编号以合成。"<<endl<<endl;
		for(int i=1;i<=100;i++){
			if(craft[i].num1!=0&&craft[i].con()&&craft[i].con2()){
				if(bag[craft[i].num2]>=craft[i].amount2&&bag[craft[i].num3]>=craft[i].amount3&&bag[craft[i].num4]>=craft[i].amount4){
					cout<<"编号"<<i<<": ";
					switch(craft[i].condition1){
					case 2:
						cout<<"熔炼 ";
						break;
					case 3:
						cout<<"锻造 ";
						break;
					default:
						cout<<"合成 ";    
						break;  
					}
					cout<<item[craft[i].num1].itemname<<"x"<<craft[i].amount1<<" 需要 ";
					cout<<item[craft[i].num2].itemname<<"x"<<craft[i].amount2<<" ";
					if(craft[i].amount3>0) cout<<","<<item[craft[i].num3].itemname<<"x"<<craft[i].amount3<<" ";
					if(craft[i].amount4>0) cout<<","<<item[craft[i].num4].itemname<<"x"<<craft[i].amount4<<" ";
					cout<<endl;
				}
			}
		}
		cout<<endl<<"输入 0 返回"<<endl;
		cin>>choose;
		int i=choose;
		if(choose==0) return;
		else{
			if(craft[i].num1!=0&&craft[i].con()&&craft[i].con2()){
				if(bag[craft[i].num2]>=craft[i].amount2&&bag[craft[i].num3]>=craft[i].amount3&&bag[craft[i].num4]>=craft[i].amount4){
					if(bag[craft[i].num2]>=2*craft[i].amount2&&bag[craft[i].num3]>=2*craft[i].amount3&&bag[craft[i].num4]>=2*craft[i].amount4){
						cout<<"你要";
						switch(craft[i].condition1){
						case 2:
							cout<<"熔炼";
							break;
						case 3:
							cout<<"锻造";
							break;
						default:
							cout<<"合成"; 
							break;  
						}
						cout<<"多少次？"<<endl;
						cin>>choose;    
						if(bag[craft[i].num2]<choose*craft[i].amount2||bag[craft[i].num3]<choose*craft[i].amount3||bag[craft[i].num4]<choose*craft[i].amount4){
							cout<<"材料不足！"<<endl;
							getch();
						}else{
							cout<<item[craft[i].num1].itemname<<" 合成成功！"<<"( 共计 "<<craft[i].amount1*choose<<" 个 )"<<endl;
							bag[craft[i].num1]+=choose*craft[i].amount1;
							bag[craft[i].num2]-=choose*craft[i].amount2;
							bag[craft[i].num3]-=choose*craft[i].amount3;
							bag[craft[i].num4]-=choose*craft[i].amount4;
							getch();
						}
					}else{
						cout<<item[craft[i].num1].itemname<<" 合成成功！"<<endl;
						bag[craft[i].num1]+=craft[i].amount1;
						bag[craft[i].num2]-=craft[i].amount2;
						bag[craft[i].num3]-=craft[i].amount3;
						bag[craft[i].num4]-=craft[i].amount4;
						getch();
					}
				}else{
					cout<<"请勿乱输！"<<endl;
				}
			}else{
				cout<<"请勿乱输！"<<endl;
				getch();
			}
		} 
	}
} 

inline void reset(){//战斗初始化 
	attack=basicattack+weapon1attack[weapon1];
	attack2=basicattack+weapon2attack[weapon2];
	attackdis2=weapon2attackdis[weapon2]; 
	defense=armor1defense[armor1]+armor2defense[armor2]+armor3defense[armor3]+armor4defense[armor4];
	maxmagic=basicmagic;
	magic=min(basicmagic,magic);
	speed=basicspeed;
	for(int i=1;i<=100;i++) enemyskill[i]=0;
	return;
}

struct drp{
	int drop_num;  
	int rand1,rand2;
	int drop_amount1,drop_amount2;  
}d[114514];

inline void add_drop(int num,int drop_num,int rand1,int rand2,int drop_amount1,int drop_amount2){//编号 物品编号 概率(rand2/rand1) 数量(amount1~amount1+amount2) 
	d[num].drop_num=drop_num;
	d[num].rand1=rand1;
	d[num].rand2=rand2;
	d[num].drop_amount1=drop_amount1;
	d[num].drop_amount2=drop_amount2;
	return;
}

inline void drop_clear(){
	for(int i=1;i<=114;i++){
		d[i].drop_num=0;
		d[i].drop_amount1=0;
		d[i].drop_amount2=0;
		d[i].rand1=0;
		d[i].rand2=0;
	}
	return;
}

inline void drop(string name){//掉落物        
	if(!dead) return;
	drop_clear();
	if(name=="铁傀儡"){
		add_drop(1,21,1,1,2,2);
	}
	if(name=="僵尸"){
		add_drop(1,22,10,1,1,0);
		add_drop(2,15,5,1,1,0);
		add_drop(3,113,20,1,1,0);
		add_drop(4,114,20,1,1,0);
		add_drop(5,115,20,1,1,0);
		add_drop(6,116,20,1,1,0);
		add_drop(7,117,40,1,1,0);
		add_drop(8,118,40,1,1,0);
		add_drop(9,119,40,1,1,0);
		add_drop(10,120,40,1,1,0);
	} 
	if(name=="骷髅"){
		choose=1+rand()%3;
		cout<<"获得 "<<choose<<" 个箭！"<<endl;
		arrow[1]+=choose;
		getch();
		add_drop(1,30,20,1,1,0);
		add_drop(2,113,20,1,1,0);
		add_drop(3,114,20,1,1,0);
		add_drop(4,115,20,1,1,0);
		add_drop(5,116,20,1,1,0);
		add_drop(6,117,40,1,1,0);
		add_drop(7,118,40,1,1,0);
		add_drop(8,119,40,1,1,0);
		add_drop(9,120,40,1,1,0);
	}
	if(name=="流浪者"){
		choose=2+rand()%3;
		cout<<"获得 "<<choose<<" 个箭！"<<endl;
		arrow[1]+=choose;
		getch();
		add_drop(1,30,16,1,1,0);
		add_drop(2,117,24,1,1,0);
		add_drop(3,118,24,1,1,0);
		add_drop(4,119,24,1,1,0);
		add_drop(5,120,24,1,1,0);
		add_drop(6,108,36,1,1,0);
		add_drop(7,109,36,1,1,0);
		add_drop(8,110,36,1,1,0);
		add_drop(9,111,36,1,1,0);
	}
	if(name=="强壮僵尸"){
		add_drop(1,22,8,1,1,0);
		add_drop(2,15,4,1,1,0);
		add_drop(3,113,16,1,1,0);
		add_drop(4,114,16,1,1,0);
		add_drop(5,115,16,1,1,0);
		add_drop(6,116,16,1,1,0);
		add_drop(7,117,32,1,1,0);
		add_drop(8,118,32,1,1,0);
		add_drop(9,119,32,1,1,0);
		add_drop(10,120,32,1,1,0);
		add_drop(11,66,10,1,1,0);
		add_drop(12,72,33,1,1,0);
	}
	if(name=="狙击骷髅"){
		choose=3+rand()%3;
		cout<<"获得 "<<choose<<" 个箭！"<<endl;
		arrow[1]+=choose;
		getch();
		add_drop(1,112,3,1,1,0);
		add_drop(2,30,2,1,1,0);
		add_drop(3,117,16,1,1,0);
		add_drop(4,118,16,1,1,0);
		add_drop(5,119,16,1,1,0);
		add_drop(6,120,16,1,1,0);
		add_drop(7,68,5,1,1,0);
	}
	if(name=="尸壳"){
		add_drop(1,22,9,1,1,0);
		add_drop(2,15,4,1,1,0);
		add_drop(3,113,18,1,1,0);
		add_drop(4,114,18,1,1,0);
		add_drop(5,115,18,1,1,0);
		add_drop(6,116,18,1,1,0);
		add_drop(7,117,36,1,1,0);
		add_drop(8,118,36,1,1,0);
		add_drop(9,119,36,1,1,0);
		add_drop(10,120,36,1,1,0);
	} 
	if(name=="蜘蛛"){
		add_drop(1,38,1,1,1,0);
		add_drop(2,74,100,1,1,0);
	} 
	if(name=="雪怪"){
		add_drop(1,22,2,1,1,0);
		add_drop(2,45,4,1,1,0);
		add_drop(3,25,16,1,1,0);
		add_drop(4,26,16,1,1,0);
		add_drop(5,27,16,1,1,0);
		add_drop(6,28,16,1,1,0);
		add_drop(7,48,20,1,1,0);
		add_drop(8,49,20,1,1,0);
		add_drop(9,50,20,1,1,0);
		add_drop(10,51,20,1,1,0);
		add_drop(11,97,32,1,1,0);
	} 
	if(name=="末影人"){
		add_drop(1,121,2,1,1,0);
		add_drop(2,74,50,1,1,0);
	} 
	if(name=="僵尸猪人"){
		choose=1+rand()%3;
		cout<<"获得 "<<choose<<" 个金粒！"<<endl;
		bag[125]+=choose;
		getch();
		add_drop(1,33,8,1,1,0);
		add_drop(2,39,20,1,1,0);
		add_drop(3,40,20,1,1,0);
		add_drop(4,41,20,1,1,0);
		add_drop(5,42,20,1,1,0);
	}
	if(name=="猪灵"){
		choose=1+rand()%3;
		cout<<"获得 "<<choose<<" 个金粒！"<<endl;
		bag[125]+=choose;
		getch();
		add_drop(1,33,8,1,1,0);
		add_drop(2,39,20,1,1,0);
		add_drop(3,40,20,1,1,0);
		add_drop(4,41,20,1,1,0);
		add_drop(5,42,20,1,1,0);
	}
	if(name=="远古僵尸1"){
		add_drop(1,22,6,1,1,0);
		add_drop(2,15,2,1,1,0);
		add_drop(3,113,10,1,1,0);
		add_drop(4,114,10,1,1,0);
		add_drop(5,115,10,1,1,0);
		add_drop(6,116,10,1,1,0);
		add_drop(7,117,20,1,1,0);
		add_drop(8,118,20,1,1,0);
		add_drop(9,119,20,1,1,0);
		add_drop(10,128,3,1,1,0);
		add_drop(11,66,100,1,1,0);
	}
	if(name=="远古骷髅1"){
		choose=2+rand()%4;
		cout<<"获得 "<<choose<<" 个箭！"<<endl;
		arrow[1]+=choose;
		getch();
		add_drop(1,128,3,1,1,0);
		add_drop(2,30,16,1,1,0);
		add_drop(3,113,10,1,1,0);
		add_drop(4,114,10,1,1,0);
		add_drop(5,115,10,1,1,0);
		add_drop(6,116,10,1,1,0);
		add_drop(7,117,20,1,1,0);
		add_drop(8,118,20,1,1,0);
		add_drop(9,119,20,1,1,0);
		add_drop(10,68,100,1,1,0);
	}
	if(name=="远古蜘蛛1"){
		add_drop(1,128,3,1,1,0);
		add_drop(2,38,1,1,1,0); 
		add_drop(3,74,25,1,1,0);
	}
	if(name=="丛林守护者1"){
		add_drop(1,128,3,1,8,4);
		choose=1+rand()%7;
		cout<<"获得 "<<item[129+choose].itemname<<" x1！"<<endl;
		bag[129+choose]+=choose;
		getch();
		add_drop(2,66,1,1,1,2);
		add_drop(3,72,2,1,1,0);
	}
	if(name=="寒冰僵尸"){
		add_drop(1,22,6,1,1,0);
		add_drop(2,15,2,1,1,0);
		add_drop(3,113,10,1,1,0);
		add_drop(4,114,10,1,1,0);
		add_drop(5,115,10,1,1,0);
		add_drop(6,116,10,1,1,0);
		add_drop(7,117,20,1,1,0);
		add_drop(8,118,20,1,1,0);
		add_drop(9,119,20,1,1,0);
		add_drop(10,161,3,1,1,0);
		add_drop(11,66,100,1,1,0);
	}
	if(name=="寒冰骷髅"){
		choose=2+rand()%4;
		cout<<"获得 "<<choose<<" 个箭！"<<endl;
		arrow[1]+=choose;
		getch();
		add_drop(1,161,3,1,1,0);
		add_drop(2,30,16,1,1,0);
		add_drop(3,113,10,1,1,0);
		add_drop(4,114,10,1,1,0);
		add_drop(5,115,10,1,1,0);
		add_drop(6,116,10,1,1,0);
		add_drop(7,117,20,1,1,0);
		add_drop(8,118,20,1,1,0);
		add_drop(9,119,20,1,1,0);
		add_drop(10,68,100,1,1,0);
	}
	if(name=="寒冰蜘蛛"){
		add_drop(1,161,3,1,1,0);
		add_drop(2,38,1,1,1,0); 
		add_drop(3,74,25,1,1,0);
	}
	for(int i=1;i<=100;i++){
		if(d[i].drop_num==0) break;
		if(1+rand()%d[i].rand1<=d[i].rand2){
			choose=d[i].drop_amount1+rand()%d[i].drop_amount2;
			cout<<"获得 "<<item[d[i].drop_num].itemname<<" x"<<choose<<" ！"<<endl;
			bag[d[i].drop_num]+=choose;
			getch();
		}
	}
	return;
}

inline void fight(string MN,int MH,int MA,int Mrand,int MD,int MS,int dis,int Adis,int xp,int Mmoney){//战斗 敌人名 敌人生命 敌人攻击 逃跑率（0为无法逃跑） 敌人防御 敌人速度 当前距离 敌人攻击距离 经验值 绿宝石 
	SetConsoleTitle("Fight!");
	dead=false;
	bool back=true;
	int enemyskilluse=0;
	int heavy_attack=0;
	bool healthy=false;
	int posioncold=0,attackback=0,insane=0,frozen=0,player_frozen=0,magicshield=0,recover;
	int powertime=0,powerlevel=0,speedtime=0,speedlevel=0;
	int player_slowdown=99999,enemy_slowdown=0; 
	system("cls");
	for(int i=1;i<=100;i++) sk[i].cold_now=0;//初始化技能冷却 
	for(int i=1;i<=100;i++) enemyskillcold[i]=0;//初始化敌人技能冷却 
	if(skill[8]>0&&sk[8].skilltake==1){
		cout<<"被动技能 力量 触发：增加 "<<skill[8]<<" 攻击！"<<endl;
		attack+=skill[8];
		Sleep(2000);
	}
	if(skill[9]>0&&sk[9].skilltake==1){
		cout<<"被动技能 魔力精通 触发：增加 "<<2+skill[9]<<" 魔力上限！"<<endl;
		maxmagic+=2+skill[9];
		Sleep(2000);
	}
	if(skill[12]>0&&sk[12].skilltake==1&&health>=maxhealth*0.7){
		cout<<"被动技能 健康 触发：增加 "<<1+skill[12]*3<<" 防御！"<<endl;
		defense+=1+skill[12]*3;
		healthy=true; 
		Sleep(2000);
	}
	while(!dead){
		system("cls");
		if(MH<=0){
			reset();
			cout<<MN<<" 战败！"<<endl;//我方胜利 
			Sleep(1500);
			cout<<"你胜利了！"<<endl;
			Sleep(1000);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|2);
			cout<<"获得经验 "<<xp<<" 点"<<endl; 
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|7);
			experience+=xp;
			Sleep(1000);
			int levelnow=level;
			if(levelup(experience)>0) cout<<"你升级了！"<<endl;
			Sleep(500);
			cout<<"当前等级："<<level<<endl;
			dead=true;
			Sleep(1000);
			if(Mmoney>0) cout<<"你获得 "<<Mmoney<<" 颗绿宝石"<<endl;
			money+=Mmoney;
			getch();
			system("cls");
			return;
		}
		if(health<=0){
			if(blessing){//祝福，复活 保留1/4血 
				cout<<"Notch之祝福生效！"<<endl;
				Sleep(2000);
				health=0;
				health+=maxhealth/4;
				blessing=false;
				cout<<"你回复25%生命值，继续战斗！"<<endl; 
				getch();
				system("cls");
			}else{
				reset();
				cout<<"你死了！"<<endl;
				place="村庄"; 
				Sleep(3000);
				health=2;
				system("cls");
				return;
			}
		}
		for(int i=1;i<=100;i++) if(skillcoldnow[i]>0) skillcoldnow[i]--;
		for(int i=1;i<=100;i++) if(enemyskillcold[i]>0) enemyskillcold[i]--;
		if(posioncold>0) posioncold--;
		magic+=min(maxmagic/10,maxmagic-magic);
		powertime-=min(powertime,1);
		if(powertime==0&&powerlevel!=0){
			attack-=powerlevel;
			powerlevel=0;
		} 
		speedtime-=min(speedtime,1);
		if(speedtime==0&&speedlevel!=0){
			speed-=speedlevel;
			speedlevel=0;
		}
		player_slowdown--;
		if(player_slowdown==0) speed+=enemyskill[41];
		//color
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|4);
		cout<<"你的血量 （"<<health<<"/"<<maxhealth<<"）  敌人血量："<<MH<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|1);
		cout<<"魔力："<<magic<<"/"<<maxmagic<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|7);                
		cout<<"攻击："<<attack<<endl;
		cout<<"防御："<<defense<<endl;
		cout<<"速度："<<speed<<endl;
		cout<<"当前你和敌人的距离为"<<dis<<endl<<endl;
		cout<<"现在是你的回合！"<<endl;
		cout<<"你要？"<<endl;
		cout<<"1，攻击（使用当前主手武器）  2，使用副手装备  3，使用药水  4，跳过本回合  5，技能  6，移动"<<endl;
		if(player_frozen>0){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|2|1);
			player_frozen--;
			cout<<"你被敌人冰冻，无法行动！"<<endl;
			int damage=1+enemyskill[33];
			cout<<"你受到了 "<<damage<<" 点伤害！"<<endl;
			health-=damage;
			cout<<"你还剩 "<<health<<" 点血量！"<<endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|7);
			getch();
			system("cls");
			choose=0;
		}else cin>>choose;
		switch(choose){
		case 1:
			if(dis<=attackdis1){
				cout<<"你使用 "<<weapon1name[weapon1]<<" 对 "<<MN<<" 进行攻击！"<<endl;
				Sleep(500);
				int damage=max((attack-MD/5)*(100+rand()%20-rand()%20)/100,2); //浮动伤害 
				cout<<MN<<" 受到了 ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|4);cout<<damage<<" 点伤害！"<<endl;SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|7);
				Sleep(500);
				MH-=damage;
				if(sk[11].skilltake&&rand()%4==0){
					cout<<"连击 技能触发！"<<endl;
					Sleep(500);
					cout<<"你对敌人再次使用 "<<weapon1name[weapon1]<<" 打出攻击！"<<endl;
					getch();
					damage=max(2+skill[11]-MD/5,2);
					cout<<MN<<" 受到了 ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|4);cout<<damage<<" 点伤害！"<<endl;SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|7);
					MH-=damage;
					Sleep(500);
				}
				cout<<"当前 "<<MN<<" 还有 ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|4);cout<<MH<<" 点生命！"<<endl;SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|7);
				Sleep(500);
				getch();
				
				system("cls");
			}else{
				cout<<"距离太远，无法攻击！"<<endl;   
				Sleep(2000);
				cout<<"你跳过了本回合"<<endl;
				getch();
				system("cls");
			} 
			break;
		case 2:
			if(weapon2==0){
				cout<<"副手未装备武器！" <<endl;
				Sleep(2000);
				cout<<"你跳过了本回合"<<endl;
				getch();
				system("cls");
			}
			if(weapon2!=0&&weapon2%2==0){//弓 
				cout<<"你要使用什么箭矢？"<<endl;
				cout<<"（若未显示则无可用箭矢）"<<endl;
				for(int i=1;i<=10;i++){
					if(arrow[i]!=0){
						cout<<i<<"，"<<arrowname[i]<<" （剩余 "<<arrow[i]<<" 支）"<<endl;
					}
				}
				cin>>choose;
				switch(choose){
				case 1:
					if(arrow[1]<=0){
						cout<<"请勿乱输！"<<endl;
						Sleep(2000);
						cout<<"你跳过了本回合"<<endl;
						getch();
						system("cls");
					}else{
						if(dis<=attackdis2){
							cout<<"你使用 "<<weapon2name[weapon2]<<" 对 "<<MN<<" 进行攻击！"<<endl;
							arrow[1]--;
							Sleep(500);
							int damage=max((attack2-MD/5)*(100+rand()%20-rand()%20)/100,2); //浮动伤害 
							cout<<MN<<" 受到了 ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|4);cout<<damage<<" 点伤害！"<<endl;SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|7);
							Sleep(500);
							MH-=damage;
							cout<<"当前 "<<MN<<" 还有 ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|4);cout<<MH<<" 点生命！"<<endl;SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|7);
							getch();         
							system("cls");
						}else{
							cout<<"距离太远，无法攻击！"<<endl;
							Sleep(2000);
							cout<<"你跳过了本回合"<<endl;
							getch(); 
							system("cls");
						}
					}
					break;  
				}
			}
			if(weapon2%2==1){
				cout<<"你举起盾牌！下次受到伤害时你的防御大幅增加！"<<endl;//盾牌 
				getch();
				defend=true;//防御状态
				system("cls"); 
			}
			break;  
		case 3:
			if(posioncold>0){
				cout<<"药水冷却中！"<<endl;
				Sleep(1000);
				cout<<"你跳过了本回合"<<endl;
				getch();
				system("cls");
			}else{
				cout<<"输入编号以使用药水！"<<endl;
				cout<<"显示顺序为 药水编号-药水名-数量"<<endl<<endl;
				cout<<"若未显示则为无药水"<<endl<<endl;
				for(int i=1001;i<=1020;i++){
					if(bag[i]>=1) cout<<"药水编号 "<<i<<" "<<posionname[i-1000]<<" 数量："<<bag[i]<<" 个"<<endl;
					else continue;
				}
				cin>>choose;
				if(bag[choose]<1){
					cout<<"你没有此药水！"<<endl;
					Sleep(1000);
					cout<<"你跳过了本回合"<<endl;
					getch();
					system("cls"); 
					break;
				}
				switch(choose){
					case 1001://治疗药水1 
					posioncold=2;
					bag[1001]--; 
					cout<<"你使用了治疗药水！"<<endl;
					recover=min(5,maxhealth/5);
					Sleep(1000); 
					cout<<"你回复了 ";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|4);
					cout<<recover<<" 点生命！"<<endl;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|7);
					Sleep(1000);
					health+=min(recover,maxhealth-health);
					cout<<"你还剩 ";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|4);
					cout<<health<<" 点生命！"<<endl;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|7);
					getch();
					system("cls");
					break;
					case 1002://魔力药水1 
					posioncold=2;
					bag[1002]--;
					cout<<"你使用了魔力药水！"<<endl;
					recover=min(4,maxmagic*10/3);
					Sleep(1000);
					cout<<"你回复了 ";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|1);
					cout<<recover<<" 点魔力！"<<endl;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|7);
					Sleep(1000);
					magic+=min(recover,maxmagic-magic);
					cout<<"你现在有 ";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|1);
					cout<<magic<<" 点魔力！"<<endl;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|7);
					getch();
					system("cls");
					break;  
					case 1009://速度药水1 
					posioncold=2;
					bag[1010]--; 
					speedlevel=1;
					speedtime=2+1; 
					cout<<"你使用了速度药水！"<<endl;
					speed+=speedlevel;
					Sleep(1000); 
					cout<<"你增加了 ";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|4);
					cout<<"1 点速度！"<<endl;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|7);
					Sleep(1000);
					cout<<"持续 2 回合！";
					getch();
					system("cls");
					break;
					case 1010://力量药水1 
					posioncold=2;
					bag[1009]--; 
					powerlevel=1;
					powertime=2+1; 
					cout<<"你使用了力量药水！"<<endl;
					attack+=powerlevel;
					Sleep(1000); 
					cout<<"你增加了 ";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|4);
					cout<<"1 点攻击！"<<endl;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|7);
					Sleep(1000);
					cout<<"持续 2 回合！";
					getch();
					system("cls");
					break;
				}
			}   
			break;
			case 4://跳过
			cout<<"你跳过了本回合"<<endl;
			getch();
			system("cls"); 
			break;
		case 5:
			cout<<"输入编号以使用技能！"<<endl;
			cout<<"显示顺序为 技能编号-技能名-等级-冷却-魔力"<<endl<<endl;
			for(int i=1;i<=100;i++){
				if(skill[i]>=1&&sk[i].skilltake==true){ 
					cout<<"技能编号 "<<i<<" ";
					if(sk[i].rarity=='C') SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|7); //C级技能 白色 
					if(sk[i].rarity=='B') SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|1);//B 蓝 
					if(sk[i].rarity=='A') SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|5);//A 紫 
					if(sk[i].rarity=='S') SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|6);//S 黄
					cout<<sk[i].skillname;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|4);//红 
					cout<<" LV：";
					if(skill[i]==sk[i].level_max) cout<<"MAX";
					else cout<<skill[i];
					if(sk[i].magic[skill[i]]==0&&sk[i].cold[skill[i]]==0){//判断被动技能 
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|3);//浅蓝 
						cout<<" <被动技能>";
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|4);//红 
						cout<<" （不可使用！）"<<endl;
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|7);//白 
					} 
					if(sk[i].magic[max(skill[i],1)]!=0){
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|3);//浅蓝 
						cout<<" 冷却：";
						cout<<sk[i].cold[skill[i]];
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|1);//蓝 
						cout<<" 消耗魔力：";
						cout<<sk[i].magic[skill[i]]<<endl;
					}
				}
				else continue;
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|7);//白
			cin>>choose;
			if(skill[choose]<1||sk[choose].skilltake==false){
				cout<<"你没有此技能！"<<endl;
				Sleep(1000);
				cout<<"你跳过了本回合"<<endl;
				getch();
				system("cls"); 
				break;
			} 
			if(magic<sk[choose].magic[skill[choose]]){
				cout<<"魔力不足！"<<endl;
				getch();
				system("cls");
				break;
			}
			if(sk[choose].cold_now>0){
				cout<<"技能冷却中！"<<endl;
				getch();
				system("cls");
				break;
			}
			magic-=sk[choose].magic[skill[choose]];
			sk[choose].cold_now=sk[choose].cold[skill[choose]];
			if(sk[choose].magic!=0) cout<<"你使用了 "<<sk[choose].skillname<<endl,Sleep(750);
			switch(choose){
				case 1://侦察 
				cout<<"敌人名称："<<MN<<endl; 
				cout<<"敌人攻击：";
				if(MA>5+MA*2) cout<<"?"<<endl;
				else cout<<MA<<endl;
				cout<<"敌人攻击距离：";
				if(Adis>3+level*2) cout<<"?"<<endl;
				else cout<<Adis<<endl;  
				cout<<"敌人防御：";
				if(MD>10+MA*3) cout<<"?"<<endl;
				else cout<<MD<<endl;
				cout<<"敌人速度：";
				if(MS>3+MS/5) cout<<"?"<<endl;
				else cout<<MS<<endl;  
				Sleep(1000);
				getch();
				system("cls");
				break;
				case 2://重击 
				if(dis<=attackdis1){
					cout<<"你对敌人重重一击！"<<endl;
					int damage=max(attack+1+skill[2]*1-MD/5,3+skill[2]); 
					cout<<MN<<" 受到了 ";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|4);
					cout<<damage<<" 点伤害！" <<endl;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|7);
					MH-=damage;
					Sleep(1000);
					cout<<"当前 "<<MN<<" 还有 ";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|4);
					cout<<MH<<" 点生命值！" <<endl;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|7); 
					Sleep(1000);
					getch();
					system("cls");
				}else{
					cout<<"距离太远，无法攻击！"<<endl;   
					Sleep(2000);
					cout<<"你跳过了本回合"<<endl;
					getch();
					system("cls");
				}
				break;
				case 3://三连击 
				if(dis<=attackdis1){
					cout<<"你对敌人连续三次攻击！"<<endl;
					int damage=max((attack*(35+skill[3]*5)/100-MD/5),1); 
					for(int i=1;i<=3;i++){
						cout<<MN<<" 受到了 ";
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|4);
						cout<<damage<<" 点伤害！" <<endl;
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|7);
						MH-=damage;
						Sleep(300);
					}
					Sleep(1000);
					cout<<"当前 "<<MN<<" 还有 ";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|4);
					cout<<MH<<" 点生命值！" <<endl; 
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|7);
					Sleep(1000);
					getch();
					system("cls");
				}else{
					cout<<"距离太远，无法攻击！"<<endl;   
					Sleep(2000);
					cout<<"你跳过了本回合"<<endl;
					getch();
					system("cls");
				}
				break;
				case 4://穿云箭 
				if(dis<=10){
					cout<<"你对敌人射出迅猛一箭！"<<endl;
					int damage=3+skill[4]*2; 
					cout<<MN<<" 受到了 ";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|4);
					cout<<damage<<" 点伤害！" <<endl;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|4);
					MH-=damage;
					Sleep(1000);
					cout<<"当前 "<<MN<<" 还有 ";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|4);
					cout<<MH<<" 点生命值！" <<endl; 
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|7);
					Sleep(1000);
					getch();
					system("cls");
				}else{
					cout<<"距离太远，无法攻击！"<<endl;   
					Sleep(2000);
					cout<<"你跳过了本回合"<<endl;
					getch();
					system("cls");
				}
				break;
				case 5://反弹 
				if(attackback==0){
					attackback=1; 
					cout<<"下次被攻击时将反弹伤害！"<<endl;
					Sleep(1000);
					getch();
					system("cls");
				}else{
					cout<<"你已激活反弹！"<<endl;
					getch();
					cout<<"你跳过了本回合"<<endl;
					getch();
					system("cls");
				}
				break;
				case 6://疯狂 
				if(insane==0){
					insane=1; 
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|4);
					cout<<"你减少了防御，但增加了攻击！"<<endl;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|7);
					defense-=6+skill[6]*3;
					attack+=skill[6];
					Sleep(1000);
					getch();
					system("cls");
				}else{
					cout<<"你取消了疯狂"<<endl;
					defense+=6+skill[6]*3;
					attack-=skill[6];
					insane=0;
					getch();
					system("cls");
				}
				break;
				case 7://魔力护盾 
				if(magicshield<5){
					defense+=1+skill[7];
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|1);
					cout<<"你将魔力凝结成护盾！"<<endl;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|7);
					cout<<"你增加了 "<<1+skill[7]<<" 点防御！"<<endl;
					cout<<"你已经使用了 "<<magicshield<<" 次，最多可使用 5 次"<<endl; 
					magicshield++;
					Sleep(1000);
					getch();
					system("cls");
				}else{
					cout<<"你已使用了 5 次技能了！"<<endl;
					Sleep(1000);
					cout<<"你跳过了本回合"<<endl;
					getch();
					system("cls"); 
				}           
				break;
				case 8://力量 
				cout<<"此技能为被动技能！"<<endl;    
				Sleep(1000);
				cout<<"你跳过了本回合"<<endl;
				getch();
				system("cls");              
				break;
				case 9://魔力精通 
				cout<<"此技能为被动技能！"<<endl;    
				Sleep(1000);
				cout<<"你跳过了本回合"<<endl;
				getch();
				system("cls");              
				break;
				case 10://闪避 
				cout<<"此技能为被动技能！"<<endl;    
				Sleep(1000);
				cout<<"你跳过了本回合"<<endl;
				getch();
				system("cls");              
				break;
				case 33://冰冻
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|2|1);
				cout<<"你使用极寒的力量裹挟着狂风将敌人冰冻！"<<endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|7);
				frozen=floor(2+skill[33]*0.6); 
				Sleep(1000);
				getch();
				system("cls");  
				break;
			}
			break;  
		case 6:
			cout<<"1，向前移动  2，向后移动";//移动 
			if(Mrand>0&&Mrand<=100) cout<<"  3，逃跑"<<endl; 
			else cout<<endl;
			cin>>choose;
			switch(choose){
			case 1:
				cout<<"移动多少格？"<<endl;
				cin>>choose;
				if(choose<=speed&&choose>=0){
					if(dis>=choose) dis-=choose;
					else dis=0;
					cout<<name<<" 向 "<<MN<<" 逼近了！"<<endl;
					Sleep(1000);
					cout<<"当前你和敌人的距离为"<<dis<<endl;
					getch();
					system("cls");
					if(enemyskill[43]==1&&dis>10){
						cout<<"然而，在这狭小的场地里根本无法拉开距离..."<<endl;
						getch();
						dis=10;
						cout<<"当前你和敌人的距离为"<<dis<<endl;
						getch();
					}
				}else{
					cout<<"请勿乱输！移动距离必须小于等于速度！"<<endl;
					getch();
					system("cls"); 
				}           
				break;
			case 2:
				cout<<"移动多少格？"<<endl;
				cin>>choose;
				if(choose<=speed&&choose>=0){
					dis+=choose;
					cout<<name<<" 后退了！"<<endl;
					Sleep(1000);
					cout<<"当前你和敌人的距离为"<<dis<<endl;
					getch();
					system("cls");
					if(enemyskill[43]==1&&dis>10){
						cout<<"然而，在这狭小的场地里根本无法拉开距离..."<<endl;
						getch();
						dis=10;
						cout<<"当前你和敌人的距离为"<<dis<<endl;
						getch();
					}
				}else{
					cout<<"请勿乱输！移动距离必须小于等于速度！"<<endl;
					getch();
					system("cls"); 
				}
				break;
			case 3:
				if(Mrand==0||Mrand>100){
					cout<<"请勿乱输!"<<endl;
					getch();
					system("cls");
				}else{
					if(rand()%100<Mrand){
						cout<<"逃跑成功！"<<endl;
						getch();
						system("cls");
						return;
					}else{
						cout<<"逃跑失败！"<<endl;
						getch();
						system("cls");
					}
				}
				break;  
			}
			break;
		} 
		if(help){
			cout<<"一名士兵向敌人射了一箭！"<<endl;
			int damage=max(6-MD/5,2); 
			cout<<MN<<" 受到了 ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|4);
			cout<<damage<<" 点伤害！" <<endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|4);
			MH-=damage;
			Sleep(1000);
			cout<<"当前 "<<MN<<" 还有 ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|4);
			cout<<MH<<" 点生命值！" <<endl; 
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|7);
			Sleep(1000);
			getch();
		}
		if(MH<=0){
			reset();
			cout<<MN<<" 战败！"<<endl;//我方胜利 
			Sleep(1500);
			cout<<"你胜利了！"<<endl;
			Sleep(1000);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|2);
			cout<<"获得经验 "<<xp<<" 点"<<endl; 
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|7);
			experience+=xp;
			Sleep(1000);
			int levelnow=level;
			if(levelup(experience)>0) cout<<"你升级了！"<<endl;
			Sleep(500);
			cout<<"当前等级："<<level<<endl;
			dead=true;
			Sleep(1000);
			if(Mmoney>0) cout<<"你获得 "<<Mmoney<<" 颗绿宝石"<<endl;
			money+=Mmoney;
			getch();
			system("cls");
			return;
		}
		system("cls");
		if(!healthy&&health>=maxhealth*0.7&&skill[12]>0&&sk[12].skilltake==1){
			cout<<"被动技能 健康 触发：增加 "<<1+skill[12]*3<<" 防御！"<<endl;
			defense+=1+skill[12]*3;
			healthy=true; 
			Sleep(2000);
		}
		if(healthy&&health<maxhealth*0.7&&skill[12]>0&&sk[12].skilltake==1){
			defense-=1+skill[12]*3;
			healthy=false; 
		}
		/******************敌人回合*****************/ 
		
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|4);
		cout<<"你的血量 （"<<health<<"/"<<maxhealth<<"）  敌人血量："<<MH<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|1);
		cout<<"魔力："<<magic<<"/"<<maxmagic<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|7);
		cout<<"攻击："<<attack<<endl;
		cout<<"防御："<<defense<<endl;
		cout<<"速度："<<speed<<endl;
		cout<<"当前你和敌人的距离为"<<dis<<endl<<endl;
		cout<<MN<<" 的回合！"<<endl; 
		if(frozen>0){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|2|1);
			frozen--;
			cout<<"敌人被冰冻，无法行动！"<<endl;
			int damage=1+skill[33]*2;
			cout<<"敌人受到了 "<<damage<<" 点伤害！"<<endl;
			MH-=damage;
			cout<<"敌人还剩 "<<MH<<" 点血量！"<<endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|7);
			getch();
			system("cls");
			continue;
		}
		for(int i=100;i>1;i--){//技能 
			if(enemyskilluse==1) break;
			if(enemyskillcold[i]==0&&enemyskill[i]>0){
				switch(i){
					case 2://重击 
					if(dis<=Adis){
						enemyskillcold[2]=skillcold[2]+1;
						cout<<MN<<" 使用了 "<<skillname[2]<<endl;
						Sleep(1000);
						cout<<MN<<"对你重重一击！"<<endl;
						int damage=max(MA+1+skill[2]*1-defense/5,3+skill[2]); 
						cout<<"你受到了 ";
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|4);
						cout<<damage<<" 点伤害！" <<endl;
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|7);
						health-=damage;
						Sleep(1000);
						cout<<"当前你还有 ";
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|4);
						cout<<health<<" 点生命值！" <<endl;
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|7); 
						Sleep(1000);
						getch();
						enemyskilluse=1;
					}
					break;
					case 4://穿云箭 
					if(dis<=10){
						enemyskillcold[4]=skillcold[4]+1;
						cout<<MN<<" 使用了 "<<skillname[4]<<endl;
						Sleep(1000);
						cout<<"敌人射出迅猛一箭！"<<endl;
						int damage=3+enemyskill[4]*2; 
						cout<<name<<" 受到了 ";
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|4);
						cout<<damage<<" 点伤害！" <<endl;
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|7);
						health-=damage;
						Sleep(1000);
						cout<<"当前 "<<name<<" 还有 ";
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|4);
						cout<<health<<" 点生命值！" <<endl;
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|7); 
						Sleep(1000);
						getch();
						enemyskilluse=1;
					}
					break;
					case 33://冰冻
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|2|1);
					cout<<"敌人使用极寒之力将你冰冻！"<<endl;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|7);
					player_frozen=floor(2+enemyskill[33]*0.6); 
					Sleep(1000);
					getch();
					system("cls");  
					break;
					case 41://减速箭 
					if(dis<=10){
						enemyskillcold[41]=skillcold[41]+1;
						cout<<MN<<" 使用了 "<<skillname[41]<<endl;
						Sleep(1000);
						cout<<"敌人射出了一支减速箭！"<<endl;
						int damage=3+enemyskill[41]; 
						player_slowdown=3;
						speed-=enemyskill[41];
						cout<<"你减速了！"<<endl; 
						cout<<name<<" 受到了 ";
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|4);
						cout<<damage<<" 点伤害！" <<endl;
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|7);
						health-=damage;
						Sleep(1000);
						cout<<"当前 "<<name<<" 还有 ";
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|4);
						cout<<health<<" 点生命值！" <<endl;
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|7); 
						Sleep(1000);
						getch();
						enemyskilluse=1;
					}
					break;
					case 42://巨力重拳 
					if(heavy_attack==2){
						if(dis<=4){
							enemyskillcold[42]=skillcold[42]+1;
							cout<<MN<<" 使用了 "<<skillname[42]<<endl;
							Sleep(1000);
							cout<<MN<<"抬起巨大的双拳，用尽全力对着你重重一击！！！"<<endl;
							int damage=max(MA*2-defense/5,MA/2); 
							getch();
							cout<<"巨大的蛮力垂直对你砸下！！！"<<endl;
							Sleep(1000);
							getch();
							cout<<"你受到了 ";
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|4);
							cout<<damage<<" 点伤害！" <<endl;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|7);
							health-=damage;
							Sleep(1000);
							cout<<"当前你还有 ";
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|4);
							cout<<health<<" 点生命值！" <<endl;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|7); 
							Sleep(1000);
							getch();
							heavy_attack=0;
							enemyskilluse=1;
						}else{
							enemyskillcold[42]=skillcold[42]+1;
							cout<<MN<<" 使用了 "<<skillname[42]<<endl;
							Sleep(1000);
							cout<<MN<<"抬起巨大的双拳，用尽全力对着面前重重一击！！！"<<endl;
							getch();
							cout<<"巨大的蛮力垂直砸下！！！"<<endl;
							Sleep(1000);
							getch();
							cout<<"然而，"<<MN<<"并没有命中你。"<<endl;
							Sleep(1000);
							getch();
							heavy_attack=0;
							enemyskilluse=1;
						}
					} 
					if(heavy_attack==1){
						enemyskillcold[42]=0;
						heavy_attack=2;
						cout<<MN<<"  似乎已经准备好了什么..."<<endl;
						Sleep(1000);
						cout<<MN<<" 周围充满了狂躁的力量..."<<endl;
						Sleep(1000);
						getch();
						enemyskilluse=1;
					}
					if(dis<=Adis+1&&heavy_attack==0&&enemyskillcold[42]==0){
						enemyskillcold[42]=0;
						heavy_attack=1;
						cout<<MN<<"  似乎在准备着什么..."<<endl;
						Sleep(1000);
						cout<<MN<<" 周围似乎充满了力量..."<<endl;
						Sleep(1000);
						getch();
						enemyskilluse=1;
					}
					break;
				}
			}
		}   
		if(health<=0){
			if(blessing){//祝福，复活 保留1/4血 
				cout<<"Notch之祝福生效！"<<endl;
				Sleep(2000);
				health=0;
				health+=maxhealth/4;
				blessing=false;
				cout<<"你回复25%生命值，继续战斗！"<<endl; 
				getch();
				system("cls");
			}else{
				reset();
				cout<<"你死了！"<<endl;
				place="村庄"; 
				Sleep(3000);
				health=2;
				system("cls");
				return;
			}
		}
		if(enemyskilluse==1){
			enemyskilluse=0;
			continue;
		}
		if(Adis<5){//近战怪物AI 
			if(dis<=Adis){
				if(Mrand==101) cout<<MN<<"抬起巨大的拳头砸向你！"<<endl;
				else cout<<MN<<" 对 "<<name<<" 进行攻击！"<<endl; 
				Sleep(500);
				int damage=0;
				if(sk[10].skilltake&&skill[10]>0&&1+rand()&100<=skill[10]+2){
					cout<<"闪避 技能触发！"<<endl;
					Sleep(500);
					if(rand()%2==1) cout<<"你身形向旁一闪，避开了敌人的攻击！"<<endl;
					else cout<<"你眼疾手快，闪避开了攻击！"<<endl;
					getch();
				}else{
					if(defend){ 
						defend=false;
						damage=max((MA-defense/5)*(100+rand()%20-rand()%20)*60/10000,1+MA/5);
					}else damage=max((MA-defense/5)*(100+rand()%20-rand()%20)/100,1+MA/5);;//浮动伤害 
					if(attackback==1){
						attackback=0;
						cout<<"你将伤害反弹给敌人！"<<endl;
						getch();
						int backdamage=max(damage*(1+skill[5])/10,2);
						damage-=backdamage; 
						cout<<"敌人受到了 ";
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|4);
						cout<<backdamage<<" 点伤害！"<<endl;
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|7);
						getch();
					}
					health-=damage;
					cout<<"你受到了 ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|4);cout<<damage<<" 点伤害！"<<endl;SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|7);
					Sleep(500);
					cout<<"你还剩 ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|4);cout<<health<<" 点生命！"<<endl;SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|7);
					getch();
					system("cls");  
				}
			}else{
				if(dis>=MS) dis-=MS;
				else dis=0;
				if(Mrand==101) cout<<MN<<" 拖着沉重的身体，向你袭来..."<<endl; 
				else cout<<MN<<" 向 "<<name<<" 逼近了！"<<endl;
				Sleep(500);
				cout<<"当前你和敌人的距离为"<<dis<<endl;
				getch();
				system("cls");
			}   
		}else{//远程怪物AI 
			if(dis<=Adis/3&&back==true){//与玩家距离小于1/3攻击距离，后退 
				dis+=MS;
				cout<<MN<<" 后退了！"<<endl;
				Sleep(500);
				cout<<"当前你和敌人的距离为"<<dis<<endl;
				getch();
				system("cls");
				back=false; 
			}else{
				back=true;
				if(dis>Adis){//距离过远，前进 
					if(dis-=MS>=0) dis-=MS;
					else dis=0;
					if(Mrand==101) cout<<MN<<" 拖着沉重的身体，向你袭来..."<<endl; 
					else cout<<MN<<" 向 "<<name<<" 逼近了！"<<endl;
					Sleep(500);
					cout<<"当前你和敌人的距离为"<<dis<<endl;
					getch();
					system("cls");
				}else{//与玩家距离适合，攻击 
					cout<<MN<<" 对 "<<name<<" 进行攻击！"<<endl;
					Sleep(500);
					int damage=0;
					if(sk[10].skilltake&&skill[10]>0&&1+rand()&100<=skill[10]+2){
						cout<<"闪避 技能触发！"<<endl;
						Sleep(500);
						if(rand()%2==1) cout<<"你身形向旁一闪，避开了敌人的攻击！"<<endl;
						else cout<<"你眼疾手快，闪避开了攻击！"<<endl;
						getch();
					}else{
						if(defend){ 
							defend=false;
							damage=max((MA-defense/5)*(100+rand()%20-rand()%20)*60/10000,1+MA/5);
						}else damage=max((MA-defense/5)*(100+rand()%20-rand()%20)/100,1+MA/5);//浮动伤害
						if(attackback==1){
							attackback=0;
							cout<<"你将伤害反弹给敌人！"<<endl;
							getch();
							int backdamage=max(damage*(1+skill[5])/10,2);
							damage-=backdamage; 
							cout<<"敌人受到了 ";
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|4);
							cout<<backdamage<<" 点伤害！"<<endl;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|7);
							getch();
						}
						health-=damage;
						cout<<"你受到了 ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|4);cout<<damage<<" 点伤害！"<<endl;SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|7);
						Sleep(500);
						cout<<"你还剩 ";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|4);cout<<health<<" 点生命！"<<endl;SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|7);
						getch();
					}
					system("cls");
				}   
			}
		}
		if(health<=0){
			if(blessing){//祝福，复活 保留1/4血 
				cout<<"Notch之祝福生效！"<<endl;
				Sleep(2000);
				health=0;
				health+=maxhealth/4;
				blessing=false;
				cout<<"你回复25%生命值，继续战斗！"<<endl; 
				getch();
				system("cls");
			}else{
				reset();
				cout<<"你死了！"<<endl;
				place="村庄"; 
				Sleep(3000);
				health=2;
				system("cls");
				return;
			}
		}
		if(!healthy&&health>=maxhealth*0.7&&skill[12]>0&&sk[12].skilltake==1){
			cout<<"被动技能 健康 触发：增加 "<<1+skill[12]*3<<" 防御！"<<endl;
			defense+=1+skill[12]*3;
			healthy=true; 
			Sleep(2000);
		}
		if(healthy&&health<maxhealth*0.7&&skill[12]>0&&sk[12].skilltake==1){
			defense-=1+skill[12]*3;
			healthy=false; 
		}
	}
	return; 
}

inline void enemyattack(){//入侵 
	if(undeadattack){
		cout<<"你看见又有一些亡灵生物在攻击村庄，不过有铁傀儡的保护，这些小批的亡灵只是送死。"<<endl;
		getch();
		cout<<"这次似乎亡灵来的数量比较多...等等！"<<endl;
		getch();
		cout<<"你定睛一看，城墙外，是黑压压的亡灵大军..."<<endl;
		getch();
		system("cls");
		Sleep(1000);
		cout<<"潮水般的亡灵疯狂的冲撞着城墙，很快城墙便倒塌了..."<<endl;
		getch();
		cout<<"亡灵大军入侵！！！"<<endl; 
		getch();
		if(attacklevel>0) cout<<"(入侵等级："<<attacklevel<<")"<<endl;
		getch();
		cout<<"一只僵尸向你扑来！"<<endl;
		getch();
		fight("僵尸",20+4*attacklevel,3,0,0+5*attacklevel,2,5,2,100+50*attacklevel,1);
		if(dead){
			dead=false;
			credit+=2;
			cout<<"你击败了僵尸后，一只精英僵尸向你冲来！！"<<endl;
			getch();
			fight("僵尸",20+5*attacklevel,4+attacklevel,0,5+5*attacklevel,3,5,2,200+50*attacklevel,2+attacklevel);
			if(dead){
				dead=false;
				credit+=2;
				cout<<"你好不容易击杀了僵尸后，远处射来一根暗箭！"<<endl;
				getch();
				fight("骷髅",20+3*attacklevel,3+1*attacklevel,0,-5+3*attacklevel,1,12,8,250+100*attacklevel,3+1*attacklevel);
				if(dead){
					credit+=5;
					Sleep(2000);
					cout<<"几根骨头落下，骷髅落败。"<<endl;
					getch();
					cout<<"你原地休息了一会，恢复了 10 点生命值！"<<endl;
					health+=min(10,maxhealth-health);
					getch();
					cout<<"但正当你休息时，一把锐利的刀刺向了你的喉咙----"<<endl;
					getch();
					system("cls");
					Sleep(1000);
					cout<<"Blackbone."<<endl;
					Sleep(1000);
					cout<<"“杀了我众多亡灵同胞，吾必将血债血偿！”"<<endl;
					getch(); 
					cout<<"顷刻间，血骨之刃便来到了你的面前！"<<endl;
					getch();
					fight("Blackbone之影",30+10*attacklevel,8+attacklevel,0,12+6*attacklevel,4,10,3,1000+150*attacklevel,5+2*attacklevel);
					if(dead){
						credit+=10;
						cout<<"你将剑插入Blackbone的心脏中，Blackbone消失了..."<<endl;
						getch();
						cout<<"刚刚你击杀的，只不过是Blackbone的分身！"<<endl;
						Sleep(1000); 
						cout<<"但亡灵大军停止了进攻，他们已经处于劣势。"<<endl;
						getch();
						cout<<"你守护了村庄！"<<endl;
						getch(); 
						cout<<"你获得奖励： 经验 500 点！ 绿宝石 15 颗！"<<endl;
						experience+=500;
						int levelnow=level;
						if(levelup(experience)>0)cout<<"你升了 "<<level-levelnow<<" 级！";
						money+=15;
						Sleep(1000); 
						cout<<"你回复了所有生命值。"<<endl;
						getch();
						health=maxhealth;
						undeadattack=false;
						Sleep(2000);
						system("cls");
					}else{
						cout<<"你倒在地上，渐渐失去了知觉..."<<endl;
						Sleep(2000);
						system("cls");
						Sleep(2000);
						cout<<"当你醒来时，你正躺在村庄旅馆里..."<<endl;
						Sleep(1000);
						cout<<"你与亡灵英勇作战，店主为你恢复了生命。"<<endl;
						health=maxhealth;
						Sleep(2000);
						undeadattack=false;
						return;
					}
				}else{
					cout<<"你倒在地上，渐渐失去了知觉..."<<endl;
					Sleep(2000);
					system("cls");
					Sleep(2000);
					cout<<"当你醒来时，你正躺在村庄旅馆里..."<<endl;
					Sleep(1000);
					cout<<"你与亡灵英勇作战，店主为你恢复了生命。"<<endl;
					health=maxhealth;
					Sleep(2000);
					undeadattack=false;
					return;
				}
			}else{
				cout<<"你倒在地上，渐渐失去了知觉..."<<endl;
				Sleep(2000);
				system("cls");
				Sleep(2000);
				cout<<"当你醒来时，你的绿宝石已散落不见..."<<endl;
				if(money<5){
					cout<<"你失去了所有绿宝石！"<<endl;
					money=0;
				}else{
					cout<<"你失去了 5 颗绿宝石！"<<endl;
					money-=5;
				}
				cout<<"你还有 "<<money<<" 颗绿宝石..."<<endl;
				Sleep(2000);
				undeadattack=false;
				return;
			}
		}else{
			cout<<"你倒在地上，渐渐失去了知觉..."<<endl;
			Sleep(2000);
			system("cls");
			Sleep(2000);
			cout<<"当你醒来时，你的绿宝石已散落不见..."<<endl;
			if(money<10){
				cout<<"你失去了所有绿宝石！"<<endl;
				money=0;
			}else{
				cout<<"你失去了 10 颗绿宝石！"<<endl;
				money-=10;
			}
			cout<<"你还有 "<<money<<" 颗绿宝石..."<<endl;
			Sleep(2000);
			undeadattack=false;
			return; 
		}
	}
	return;
}

struct sell{
	string type;
	int num,amount,money;
}s[1000];

inline void shop_sell(int number,string type,int num,int amount,int money){
	if(type=="sell") s[number].type="sell";
	else{
		if(type=="arrow_sell") s[number].type="arrow_sell";
		else{
			s[number].type="sb";//？ 
			s[number].num=num;
			s[number].amount=item[num].sell_num;
			s[number].money=item[num].sell_price;
			return; 
		}
	}
	s[number].amount=amount;
	s[number].num=num;
	s[number].money=money;
	return;
}

inline void shop_clear(){//清空商店物品 
	for(int i=1;i<=114;i++){
		s[i].type="";
		s[i].amount=0;
		s[i].money=0;
		s[i].num=0;
	}
	return;
}

inline void shop(string place){//商店 
	
	if(place=="洞穴"){
		cout<<"此处没有商店！"<<endl;
		getch(); 
		return;
	}
	if(place=="沙漠"){
		cout<<"此处没有商店！"<<endl;
		getch();
		return;
	}
	if(place=="雪地"){
		cout<<"此处没有商店！"<<endl;
		getch();
		return;
	}
	if(place=="地狱"){
		cout<<"此处没有商店！"<<endl;
		getch();
		return;
	}
	if(place=="末地"){
		cout<<"此处没有商店！"<<endl;
		getch();
		return;
	}
	shop_clear();
	system("cls");
	cout<<"欢迎来到"<<place<<"商店！"<<endl;
	cout<<"请问您要买什么？"<<endl; 
	cout<<"(当前你有"<<money<<"个绿宝石)"<<endl;
	cout<<"0，离开  1，武器  2，工具  3，药水  4，其他  5，出售"<<endl; 
	cin>>choose;
	switch(choose){
	case 0:
		return;
		break;
	case 1:
		shop_sell(1,"sell",11,1,2);
		shop_sell(2,"sell",15,1,6);
		for(int i=1;i<=100;i++){
			if(s[i].num!=0){
				cout<<"编号"<<i<<" "<<item[s[i].num].itemname<<"x"<<s[i].amount<<" -价格 "<<s[i].money<<" 绿宝石 \n";
			}else break;
		}
		cout<<"输入商品编号购买物品！"<<endl; 
		cin>>choose;
		if(choose==0){
			shop(place);
			return;
		}
		if(s[choose].num==0){
			cout<<"请勿乱输！"<<endl;
			getch();
		}else{
			if(money<s[choose].money){
				cout<<"你的绿宝石不够！"<<endl;
				getch();
				system("cls");
			}else{
				cout<<"购买成功！"<<endl;
				money-=s[choose].money;
				cout<<"你还剩 "<<money<<" 个绿宝石"<<endl;
				bag[s[choose].num]+=s[choose].amount;
				getch();
				system("cls");
			}
		}
		break;
	case 2:
		shop_sell(1,"sell",12,1,2);
		shop_sell(2,"sell",13,1,6);
		for(int i=1;i<=100;i++){
			if(s[i].num!=0){
				cout<<"编号"<<i<<" "<<item[s[i].num].itemname<<"x"<<s[i].amount<<" -价格 "<<s[i].money<<" 绿宝石 \n";
			}else break;
		}
		cout<<"输入商品编号购买物品！"<<endl; 
		cin>>choose;
		if(choose==0){
			shop(place);
			return;
		}
		if(s[choose].num==0){
			cout<<"请勿乱输！"<<endl;
			getch();
		}else{
			if(money<s[choose].money){
				cout<<"你的绿宝石不够！"<<endl;
				getch();
				system("cls");
			}else{
				cout<<"购买成功！"<<endl;
				money-=s[choose].money;
				cout<<"你还剩 "<<money<<" 个绿宝石"<<endl;
				bag[s[choose].num]+=s[choose].amount;
				getch();
				system("cls");
			}
		}
		break;  
	case 3:
		shop_sell(1,"sell",1001,1,5);
		shop_sell(2,"sell",1002,1,5);
		for(int i=1;i<=100;i++){
			if(s[i].num!=0){
				cout<<"编号"<<i<<" "<<item[s[i].num].itemname<<"x"<<s[i].amount<<" -价格 "<<s[i].money<<" 绿宝石 \n";
			}else break;
		}
		cout<<"输入商品编号购买物品！"<<endl; 
		cin>>choose;
		if(s[choose].num==0){
			cout<<"请勿乱输！"<<endl;
			getch();
		}else{
			if(money<s[choose].money){
				cout<<"你的绿宝石不够！"<<endl;
				getch();
				system("cls");
			}else{
				cout<<"购买成功！"<<endl;
				money-=s[choose].money;
				cout<<"你还剩 "<<money<<" 个绿宝石"<<endl;
				bag[s[choose].num]+=s[choose].amount;
				getch();
				system("cls");
			}
		}
		break;
	case 4:
		if(place=="村庄"){        
			shop_sell(1,"sell",66,1,25);
			shop_sell(2,"sell",75,1,25);
			shop_sell(3,"sell",19,4,1);
			shop_sell(4,"arrow_sell",1,4,2);
		}
		if(place=="平原"){
			shop_sell(1,"sell",69,1,30);
			shop_sell(1,"sell",70,1,25);
		}
		if(place=="森林"){
			shop_sell(1,"sell",71,1,25);
		}
		if(place=="丛林"){
			shop_sell(1,"sell",73,1,20);
			shop_sell(1,"sell",76,1,25);
		}
		for(int i=1;i<=100;i++){
			if(s[i].num!=0){
				if(s[i].type=="arrow_sell") cout<<"编号"<<i<<" "<<arrowname[s[i].num]<<"x"<<s[i].amount<<" -价格 "<<s[i].money<<" 绿宝石 \n";
				else cout<<"编号"<<i<<" "<<item[s[i].num].itemname<<" -价格 "<<s[i].money<<" 绿宝石 \n";
			}else break;
		}
		cout<<"输入商品编号购买物品！"<<endl; 
		cin>>choose;
		if(choose==0){
			shop(place);
			return;
		} 
		if(s[choose].num==0){
			cout<<"请勿乱输！"<<endl;
			getch();
		}else{
			if(money<s[choose].money){
				cout<<"你的绿宝石不够！"<<endl;
				getch();
				system("cls");
			}else{
				cout<<"购买成功！"<<endl;
				money-=s[choose].money;
				cout<<"你还剩 "<<money<<" 个绿宝石"<<endl;
				if(s[choose].type=="arrow_sell") arrow[s[choose].num]+=s[choose].amount;
				else bag[s[choose].num]+=s[choose].amount;
				getch();
				system("cls");
			}
		}
		break;     
	case 5:
		for(int i=1;i<=100;i++){
			if(i>=16&&level<3){
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|2);
				cout<<"\n达到 3 级以解锁新的物品！\n"<<endl;
				break;
			}
			if(i>=32&&level<5){
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|2);
				cout<<"\n达到 5 级以解锁新的物品！\n"<<endl;
				break;
			}
			if(i>=48&&level<8){
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|2);
				cout<<"\n达到 8 级以解锁新的物品！\n"<<endl;
				break;
			}
			if(i>=64&&level<10){
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|2);
				cout<<"\n达到 10 级以解锁新的物品\n"<<endl;
				break;
			}
			if(item[i].sell_num>0) shop_sell(i,"1",i,0,0);
		} 
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|7);
		cout<<"输入商品编号出售物品！\n\n提升你的等级以解锁更多可出售物品。\n"<<endl; 
		for(int i=1;i<=100;i++){
			if(s[i].num!=0){
				cout<<"编号"<<i<<" "<<item[s[i].num].itemname<<" -出售 "<<s[i].amount<<" 个 价格 "<<s[i].money<<" 绿宝石 \n";
			}
		}
		cin>>choose;
		if(choose==0){
			shop(place);
			return;
		}
		if(s[choose].num==0){
			cout<<"请勿乱输！"<<endl;
			getch();
		}else{
			if(bag[s[choose].num]<s[choose].amount){
				cout<<"你的"<<item[s[choose].num].itemname<<"不够！"<<endl;
				getch();
				system("cls");
			}else{
				cout<<"出售成功！"<<endl;
				money+=s[choose].money;
				cout<<"你现在有 "<<money<<" 个绿宝石"<<endl;
				bag[s[choose].num]-=s[choose].amount;
				getch();
				system("cls");
			}
		}
		break; 
	}
	shop(place);
}

inline void shoper(string who){//流浪商人 
	system("cls");
	int a=1+rand()%4,b=1+rand()%2,c=1+rand()%4,d=1+rand()%2;
	while(1){
		if(who=="流浪商人"){
			system("cls");
			cout<<"“你要买什么？你也可以卖一些东西给我。”"<<endl;
			cout<<"“我这里有着各种各样的东西...不定时更换商品。”"<<endl; 
			cout<<"(当前你有"<<money<<"个绿宝石)"<<endl;
			cout<<"0，离开  1，武器  2，工具  3，药水  4，其他"<<endl; 
			cin>>choose;
			switch(choose){
			case 0:
				return;
				break;
			case 1:
				cout<<"编号1 流浪者之利剑-价格 16 绿宝石 \n";
				if(a==1) cout<<"编号2 流浪者之旅帽-价格 10 绿宝石 \n";
				if(a==2) cout<<"编号3 流浪者之外甲-价格 12 绿宝石 \n";
				if(a==3) cout<<"编号4 流浪者之护腿-价格 12 绿宝石 \n";
				if(a==4) cout<<"编号5 流浪者之护履-价格 10 绿宝石 \n";
				cout<<"输入商品编号购买物品！"<<endl; 
				cin>>choose;
				switch(choose){
				case 1:
					if(money<16){
						cout<<"你的绿宝石不够！"<<endl;
						getch();
						system("cls"); 
					}else{
						cout<<"购买成功！"<<endl;
						money-=16;
						cout<<"你还剩 "<<money<<" 个绿宝石"<<endl;
						bag[105]+=1;
						getch(); 
						system("cls");
					}
					break;
				case 2:
					if(a!=1){
						cout<<"请勿乱输！"<<endl;
						getch();
						continue;
					}
					if(money<10){
						cout<<"你的绿宝石不够！"<<endl;
						getch();
						system("cls"); 
					}else{
						cout<<"购买成功！"<<endl;
						money-=10;
						cout<<"你还剩 "<<money<<" 个绿宝石"<<endl;
						bag[108]+=1;
						getch(); 
						system("cls");
					}
					break;
				case 3:
					if(a!=2){
						cout<<"请勿乱输！"<<endl;
						getch();
						continue;
					}
					if(money<12){
						cout<<"你的绿宝石不够！"<<endl;
						getch();
						system("cls"); 
					}else{
						cout<<"购买成功！"<<endl;
						money-=12;
						cout<<"你还剩 "<<money<<" 个绿宝石"<<endl;
						bag[109]+=1;
						getch(); 
						system("cls");
					}
					break;
				case 4:
					if(a!=3){
						cout<<"请勿乱输！"<<endl;
						getch();
						continue;
					}
					if(money<12){
						cout<<"你的绿宝石不够！"<<endl;
						getch();
						system("cls"); 
					}else{
						cout<<"购买成功！"<<endl;
						money-=12;
						cout<<"你还剩 "<<money<<" 个绿宝石"<<endl;
						bag[110]+=1;
						getch(); 
						system("cls");
					}
					break;
				case 5:
					if(a!=4){
						cout<<"请勿乱输！"<<endl;
						getch();
						continue;
					}
					if(money<10){
						cout<<"你的绿宝石不够！"<<endl;
						getch();
						system("cls"); 
					}else{
						cout<<"购买成功！"<<endl;
						money-=10;
						cout<<"你还剩 "<<money<<" 个绿宝石"<<endl;
						bag[111]+=1;
						getch(); 
						system("cls");
					}
					break;
				}
				break; 
			case 2:
				if(b==1) cout<<"编号1 流浪者之重斧-价格 8 绿宝石 \n";
				if(b==2) cout<<"编号2 流浪者之钝稿-价格 12 绿宝石 \n";
				cout<<"输入商品编号购买物品！"<<endl; 
				cin>>choose;
				switch(choose){
				case 1:
					if(b!=1){
						cout<<"请勿乱输！"<<endl;
						getch();
						continue;
					}
					if(money<8){
						cout<<"你的绿宝石不够！"<<endl;
						getch();
						system("cls"); 
					}else{
						cout<<"购买成功！"<<endl;
						money-=8;
						cout<<"你还剩 "<<money<<" 个绿宝石"<<endl;
						bag[106]+=1;
						getch(); 
						system("cls");
					}
					break;
				case 2:
					if(b!=2){
						cout<<"请勿乱输！"<<endl;
						getch();
						continue;
					}
					if(money<12){
						cout<<"你的绿宝石不够！"<<endl;
						getch();
						system("cls"); 
					}else{
						cout<<"购买成功！"<<endl;
						money-=12;
						cout<<"你还剩 "<<money<<" 个绿宝石"<<endl;
						bag[107]+=1;
						getch(); 
						system("cls");
					}
					break;
				}
				break;  
				break;
			case 3:
				if(c==1) cout<<"编号1 治疗药水-价格 5 绿宝石 \n";
				if(c==2) cout<<"编号2 魔力药水-价格 5 绿宝石 \n";
				if(c==3) cout<<"编号3 速度药水-价格 7 绿宝石 \n";
				if(c==4) cout<<"编号4 力量药水-价格 7 绿宝石 \n";
				cout<<"输入商品编号购买物品！"<<endl; 
				cin>>choose;
				switch(choose){
				case 1:
					if(c!=1){
						cout<<"请勿乱输！"<<endl;
						getch();
						continue;
					}
					if(money<5){
						cout<<"你的绿宝石不够！"<<endl;
						getch();
						system("cls"); 
					}else{
						cout<<"购买成功！"<<endl;
						money-=5;
						cout<<"你还剩 "<<money<<" 个绿宝石"<<endl;
						bag[1001]+=1;
						getch(); 
						system("cls");
					}
					break;
				case 2:
					if(c!=2){
						cout<<"请勿乱输！"<<endl;
						getch();
						continue;
					}
					if(money<5){
						cout<<"你的绿宝石不够！"<<endl;
						getch();
						system("cls"); 
					}else{
						cout<<"购买成功！"<<endl;
						money-=5;
						cout<<"你还剩 "<<money<<" 个绿宝石"<<endl;
						bag[1002]+=1;
						getch(); 
						system("cls");
					}
					break;
				case 3:
					if(c!=3){
						cout<<"请勿乱输！"<<endl;
						getch();
						continue;
					}
					if(money<7){
						cout<<"你的绿宝石不够！"<<endl;
						getch();
						system("cls"); 
					}else{
						cout<<"购买成功！"<<endl;
						money-=7;
						cout<<"你还剩 "<<money<<" 个绿宝石"<<endl;
						bag[1009]+=1;
						getch(); 
						system("cls");
					}
					break;
				case 4:
					if(c!=4){
						cout<<"请勿乱输！"<<endl;
						getch();
						continue;
					}
					if(money<7){
						cout<<"你的绿宝石不够！"<<endl;
						getch();
						system("cls"); 
					}else{
						cout<<"购买成功！"<<endl;
						money-=7;
						cout<<"你还剩 "<<money<<" 个绿宝石"<<endl;
						bag[1010]+=1;
						getch(); 
						system("cls");
					}
					break;
				}
				break;  
			case 4:
				if(d==1) cout<<"编号1 三连击 技能书 （C 可升级） - 价格 20 绿宝石\n";
				if(d==2) cout<<"编号2 穿云箭 技能书 （C 可升级） - 价格 20 绿宝石\n";
				cout<<"编号3 铁剑 x2 - 出售 1 绿宝石\n";
				cout<<"编号4 圆石 x128 - 出售 3 绿宝石\n";
				cout<<"编号5 金锭 x5 - 出售 2 绿宝石\n";
				cout<<"输入商品编号购买/出售物品！"<<endl;
				cin>>choose;
				switch(choose){
				case 1:
					if(d!=1){
						cout<<"请勿乱输！"<<endl;
						getch();
						continue;
					}
					if(money<20){
						cout<<"你的绿宝石不够！"<<endl;
						getch();
						system("cls");
					}else{
						cout<<"购买成功！"<<endl;
						money-=20;
						bag[67]++;
						cout<<"你还剩 "<<money<<" 个绿宝石"<<endl;
						getch(); 
						system("cls");
					}
					break;
				case 2:
					if(d!=2){
						cout<<"请勿乱输！"<<endl;
						getch();
						continue;
					}
					if(money<20){
						cout<<"你的绿宝石不够！"<<endl;
						getch();
						system("cls");
					}else{
						cout<<"购买成功！"<<endl;
						money-=20;
						bag[68]++;
						cout<<"你还剩 "<<money<<" 个绿宝石"<<endl;
						getch(); 
						system("cls");
					}
					break;
				case 3:
					if(bag[22]<2){
						cout<<"你的铁剑不够！"<<endl;
						getch();
						system("cls");
					}else{
						cout<<"出售成功！"<<endl;
						money++;
						bag[22]-=2;
						cout<<"你还剩 "<<money<<" 个绿宝石"<<endl;
						getch(); 
						system("cls");
					}
					break;
				case 4:
					if(bag[14]<128){
						cout<<"你的圆石不够！"<<endl;
						getch();
						system("cls");
					}else{
						cout<<"出售成功！"<<endl;
						money+=3;
						bag[14]-=128;
						cout<<"你还剩 "<<money<<" 个绿宝石"<<endl;
						getch(); 
						system("cls");
					}
					break;
				case 5:
					if(bag[32]<5){
						cout<<"你的金锭不够！"<<endl;
						getch();
						system("cls");
					}else{
						cout<<"出售成功！"<<endl;
						money+=2;
						bag[32]-=5;
						cout<<"你还剩 "<<money<<" 个绿宝石"<<endl;
						getch(); 
						system("cls");
					}
					break;
				}
				break;  
			}
		}
	}
}

inline void dungeon(string place){//副本 
	string map[100];
	int x,y; 
	system("cls");
	if(place=="丛林神庙"){
		time_now=time(0);
		if(time_now-time_last[1]<7200){
			cout<<"副本冷却中！"<<endl;
			//cout<<time_now<<" "<<time_last[1]<<endl;
			if(7200-(time_now-time_last[1])>=60) cout<<"请等待 "<<120-(time_now-time_last[1])/60<<" 分钟后再进入！"<<endl;
			else cout<<"请等待 "<<7200-(time_now-time_last[1])<<" 秒后再进入！"<<endl;
			getch();
			return;
		}else{
			cout<<"你确定要进入丛林神庙？！"<<endl;
			cout<<"\n0，返回  1，确定"<<endl;
			cin>>choose;
			if(choose==0) return;
			else{
				time_last[1]=time(0);
				cout<<"选择难度："<<endl;
				cout<<"1，简单  ";
				if(hard_max[1]>=2)cout<<"2，普通  ";
				if(hard_max[1]>=3)cout<<"3，困难  ";
				if(hard_max[1]>=4)cout<<"4，地狱  ";
				if(hard_max[1]>=5)cout<<"5，炼狱";
				cout<<endl;
				cin>>hard;
				switch(hard){
				case 1:
					map[0]="#####"; 
					map[1]="##2##";
					map[2]="#31##";
					map[3]="##1##";
					map[4]="##11#";
					map[5]="##0##";
					cout<<"祝你好运..."<<endl; 
					x=4,y=2;
					break;  
				case 2:
					if(hard_max[1]<2) return;
					map[0]="#####"; 
					map[1]="##2##";
					map[2]="#11##";
					map[3]="##1##";
					map[4]="##13#";
					map[5]="##0##";
					cout<<"祝你好运..."<<endl; 
					x=4,y=2;
					break;
				case 3:
					if(hard_max[1]<3) return;
					map[0]="#####"; 
					map[1]="#####"; 
					map[2]="##2##";
					map[3]="311##";
					map[4]="##1##";
					map[5]="##113";
					map[6]="##1##";
					map[7]="##0##"; 
					cout<<"当心危险..."<<endl; 
					x=5,y=2;
					break;
				case 4:
					if(hard_max[1]<4) return;
					map[0]="#####"; 
					map[1]="##2##";
					map[2]="311##";
					map[3]="##1##";
					map[4]="##113";
					map[5]="#11##";
					map[6]="##1##";
					map[7]="##0##"; 
					cout<<"感受地狱吧..."<<endl; 
					x=6,y=2;
					break;
				case 5:
					if(hard_max[1]<5) return;
					map[0]="#####"; 
					map[1]="##2##";
					map[2]="311##";
					map[3]="##1##";
					map[4]="##113";
					map[5]="#11##";
					map[6]="##3##";
					map[7]="##1##";
					map[8]="##1##";
					map[9]="##0##";
					cout<<"你会后悔的..."<<endl;  
					x=8,y=2;
					break;
				default:
					return;
					break;  
				}
				getch();
				say("你缓缓走进丛林神庙，等待你的会是什么呢...",50);
				Sleep(1000);
				while(1){
					reset();//重置 
					system("cls");
					levelup(experience);
					if(map[x][y]=='1'){
						cout<<"你走进内部，发现了一些怪物！"<<endl;
						getch();
						switch(1+rand()%3){
						case 1:
							cout<<"你遇见了远古僵尸！"<<endl;
							getch();
							switch(hard){
							case 1:
								fight("远古僵尸",20,4+rand()%2,0,6+rand()%5,3,4+rand()%3,2,200,1);
								drop("远古僵尸1");
								break;
							case 2:
								fight("远古僵尸",24,5+rand()%2,0,10+rand()%6,3,4+rand()%3,2,300,2);
								drop("远古僵尸2");
								break;
							case 3:
								fight("远古僵尸",30,7+rand()%2,0,18+rand()%6,4,4+rand()%3,2,450,3);
								drop("远古僵尸3");
								break;
							case 4:
								fight("远古僵尸",34+rand()%7,8+rand()%4,0,24+rand()%6,4,5+rand()%2,2,700,5);
								drop("远古僵尸4");
								break;
							case 5:
								fight("远古僵尸",48+rand()%9,10+rand()%3,0,30+rand()%10,5,6+rand()%3,3,1000,8);
								drop("远古僵尸5");
								break;  
							}
							if(!dead){
								say("你的意识渐渐模糊...",100);
								getch();
								return; 
							}else{
								map[x][y]='0';
								if(maxhealth-health>0){
									cout<<"你原地休息片刻，恢复了10%的生命！"<<endl;
									health+=min(maxhealth/10,maxhealth-health);
									getch();
								}   
							} 
							break;
						case 2:
							cout<<"你遇见了远古骷髅！"<<endl;
							getch();
							switch(hard){
							case 1:
								fight("远古骷髅",20,3+rand()%2,0,0+rand()%5,2,7+rand()%5,8,300,2);
								drop("远古骷髅1");
								break;
							case 2:
								fight("远古骷髅",20+rand()%3,4+rand()%2,0,4+rand()%5,2,8+rand()%5,9,450,3);
								drop("远古骷髅2");
								break;
							case 3:
								fight("远古骷髅",26+rand()%5,6+rand()%2,0,12+rand()%6,3,10+rand()%4,10,700,5);
								drop("远古骷髅3");
								break;
							case 4:
								fight("远古骷髅",30+rand()%8,8+rand()%2,0,18+rand()%6,3,12+rand()%3,10,900,7);
								drop("远古骷髅4");
								break;
							case 5:
								fight("远古骷髅",42+rand()%9,10+rand()%2,0,22+rand()%10,4,14+rand()%5,12,1200,10);
								drop("远古骷髅5");
								break;  
							}
							if(!dead){
								say("你的意识渐渐模糊...",100);
								getch();
								return; 
							}else{
								map[x][y]='0';
								if(maxhealth-health>0){
									cout<<"你原地休息片刻，恢复了10%的生命！"<<endl;
									health+=min(maxhealth/10,maxhealth-health);
									getch();
								}   
							} 
							break; 
						case 3:
							cout<<"你遇见了远古蜘蛛！"<<endl;
							getch();
							switch(hard){
							case 1:
								fight("远古蜘蛛",20,6+rand()%3,0,-12+rand()%4,4,8+rand()%4,2,300,2);
								drop("远古蜘蛛1");
								break;
							case 2:
								fight("远古蜘蛛",22,7+rand()%3,0,-6+rand()%4,4,8+rand()%4,2,450,4);
								drop("远古蜘蛛2");
								break;
							case 3:
								fight("远古蜘蛛",24+rand()%3,9+rand()%3,0,4+rand()%4,5,9+rand()%4,2,750,6);
								drop("远古蜘蛛3");
								break;
							case 4:
								fight("远古蜘蛛",28+rand()%7,11+rand()%2,0,10+rand()%6,5,8+rand()%3,2,1000,8);
								drop("远古蜘蛛4");
								break;
							case 5:
								fight("远古蜘蛛",36+rand()%9,14+rand()%3,0,20+rand()%4,6,8+rand()%3,3,1400,11);
								drop("远古蜘蛛5");
								break;  
							}
							if(!dead){
								say("你的意识渐渐模糊...",100);
								getch();
								return; 
							}else{
								map[x][y]='0';
								if(maxhealth-health>0){
									cout<<"你原地休息片刻，恢复了10%的生命！"<<endl;
									health+=min(maxhealth/10,maxhealth-health);
									getch();
								}   
							} 
							break;  
						}
					}
					if(map[x][y]=='2'){
						cout<<"你在原地休息了一会儿，恢复了50%生命值！"<<endl;
						health+=min(maxhealth/2,maxhealth-health);
						getch();
						system("cls");
						Sleep(1000);
						say("你走进神庙的中心，发现了一个巨大的雕像。\n",60);
						getch(); 
						say("你走上前查看时，雕像突然震动起来！",60);
						getch();
						system("cls");
						Sleep(1000);
						say("“是谁，唤醒了我...？！”\n",50);
						getch();
						say("巨大的雕像从一片废墟中爬起，雕像的双眼赫然发出诡异的绿光！\n",50);
						getch();
						say("“人类...擅闯丛林神庙，丛林守护者将会把你粉碎！！！”\n",50);
						Sleep(1000); 
						say("“你，将为此付出代价！！！”",50);
						getch();
						system("cls");
						getch();
						cout<<"身后大门突然关上，";
						say("你已无路可退。\n",50);
						Sleep(1000);
						say("咆哮着的远古雕像向你袭来，势必要将你粉碎！",80);
						getch();
						system("cls");
						cout<<"战斗！"<<endl;
						Sleep(1000);
						switch(hard){
						case 1:
							enemyskill[2]=1;
							enemyskill[42]=1;
							enemyskill[43]=1;
							fight("丛林守护者",75,9,101,20,3,8,2,1500,10);
							drop("丛林守护者1");
							if(dead){
								getch();
								system("cls");
								cout<<"你从废墟中爬起，看向战斗后破败的丛林神庙"<<endl;
								getch();
								cout<<"丛林守护者已被你杀死...快离开吧。"<<endl;
								getch();
							}
							break;
						case 2:
							enemyskill[2]=2;
							enemyskill[42]=1;
							enemyskill[43]=1;
							fight("丛林守护者",85,10,101,25,3,8,2,2000,15);
							drop("丛林守护者2");
							if(dead){
								getch();
								system("cls");
								cout<<"你从废墟中爬起，看向战斗后破败的丛林神庙"<<endl;
								getch();
								cout<<"丛林守护者已被你杀死...快离开吧。"<<endl;
								getch();
							}
							break;
						case 3:
							enemyskill[2]=3;
							enemyskill[42]=1;
							enemyskill[43]=1;
							fight("丛林守护者",100,12,101,32,3,8,2,2750,20);
							drop("丛林守护者3");
							if(dead){
								getch();
								system("cls");
								cout<<"你从废墟中爬起，看向战斗后破败的丛林神庙"<<endl;
								getch();
								cout<<"丛林守护者已被你杀死...快离开吧。"<<endl;
								getch();
							}
							break;
						case 4:
							enemyskill[2]=3;
							enemyskill[42]=1;
							enemyskill[43]=1;
							fight("丛林守护者",140,14,101,40,3,8,2,5500,30);
							drop("丛林守护者4");
							if(dead){
								getch();
								system("cls");
								cout<<"你从废墟中爬起，看向战斗后破败的丛林神庙"<<endl;
								getch();
								cout<<"丛林守护者已被你杀死...快离开吧。"<<endl;
								getch();
							}
							break;
						case 5:
							enemyskill[2]=5;
							enemyskill[42]=1;
							enemyskill[43]=1;
							fight("丛林守护者",200,20,101,56,4,8,2,10000,60);
							drop("丛林守护者5"); 
							if(dead){
								getch();
								system("cls");
								cout<<"你从废墟中爬起，看向战斗后破败的丛林神庙"<<endl;
								getch();
								cout<<"丛林守护者已被你杀死...快离开吧。"<<endl;
								getch();
							}
							break;  
						}
					}
					if(map[x][y]=='3'){
						cout<<"你发现了宝藏！"<<endl;
						getch();
						cout<<"你原地休息了一会，恢复了25%的生命！"<<endl;
						health+=min(maxhealth/4,maxhealth-health);
						getch();
						system("cls");
						cout<<"你走进内部，发现了一些财宝！"<<endl;
						getch();
						switch(hard){
						case 1:
							choose=3+rand()%4;
							cout<<"你获得了 "<<choose<<" 个绿宝石！"<<endl;
							money+=choose;
							choose=1001+rand()%2;
							getch();
							cout<<"你获得了 "<<itemname[choose]<<" x1！"<<endl;
							getch();
							bag[choose]++;
							drop("远古僵尸1"); 
							drop("远古僵尸1"); 
							drop("远古骷髅1"); 
							drop("远古骷髅1"); 
							getch(); 
							break;
						case 2:
							choose=5+rand()%4;
							cout<<"你获得了 "<<choose<<" 个绿宝石！"<<endl;
							money+=choose;
							choose=1003+rand()%2;
							getch();
							cout<<"你获得了 "<<itemname[choose]<<" x1！"<<endl;
							getch();
							bag[choose]++;
							drop("远古僵尸2"); 
							drop("远古僵尸2"); 
							drop("远古骷髅2"); 
							drop("远古骷髅2"); 
							getch(); 
							break;
						case 3:
							choose=8+rand()%5;
							cout<<"你获得了 "<<choose<<" 个绿宝石！"<<endl;
							money+=choose;
							choose=1003+rand()%2;
							getch();
							cout<<"你获得了 "<<itemname[choose]<<" x1！"<<endl;
							getch();
							bag[choose]++;
							drop("远古僵尸3"); 
							drop("远古僵尸3"); 
							drop("远古骷髅3"); 
							drop("远古骷髅3");
							getch(); 
							break;  
						case 4:
							choose=12+rand()%5;
							cout<<"你获得了 "<<choose<<" 个绿宝石！"<<endl;
							money=choose;
							choose+1005+rand()%2;
							getch();
							cout<<"你获得了 "<<itemname[choose]<<" x2！"<<endl;
							getch();
							bag[choose]++;
							drop("远古僵尸4"); 
							drop("远古僵尸4"); 
							drop("远古骷髅4"); 
							drop("远古骷髅4"); 
							getch(); 
							break;  
						case 5:
							choose=18+rand()%4;
							cout<<"你获得了 "<<choose<<" 个绿宝石！"<<endl;
							money+=choose;
							choose=1005+rand()%2;
							getch();
							cout<<"你获得了 "<<itemname[choose]<<" x3！"<<endl;
							getch();
							bag[choose]++;
							drop("远古僵尸5");
							drop("远古僵尸5");  
							drop("远古骷髅5"); 
							drop("远古骷髅5"); 
							getch(); 
							break;
						}
						map[x][y]='0';
					}
					system("cls");
					if(x==1) cout<<"你现在位于神庙尽头。"<<endl;
					if(map[x][y]=='0') cout<<"你现在位于丛林神庙内部。";
					if(map[x][y-1]!='#') cout<<"你的左侧有一条岔道。"; 
					if(map[x][y+1]!='#') cout<<"你的右侧有一条岔道。";
					cout<<endl;
					//cout<<x<<" "<<y<<endl; 
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|4);
					cout<<"血量："<<health<<"/"<<maxhealth<<endl;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|1);
					cout<<"魔力："<<magic<<"/"<<maxmagic<<endl;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|7);
					cout<<"攻击："<<attack<<endl;
					cout<<"防御："<<defense<<endl;
					cout<<"速度："<<speed<<endl;
					cout<<"绿宝石："<<money<<endl;
					cout<<"等级："<<level;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|2);
					cout<<" 经验："<<experience<<"/"<<level*100<<endl; 
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|7);    
					cout<<"-----------------------------------" <<endl; 
					cout<<"你要做什么？"<<endl;
					cout<<"0，离开副本  "; 
					if(map[x-1][y]!='#') cout<<"1，前进  ";
					if(map[x][y-1]!='#') cout<<"2，向左走  ";
					if(map[x][y+1]!='#') cout<<"3，向右走  ";
					cout<<endl;
					cin>>choose;
					switch(choose){
					case 0:
						cout<<"你确定要退出副本吗？\n0，不  1，确定"<<endl;
						cin>>choose;
						if(choose==0) continue;
						else{
							cout<<"你扭回头，缓缓离开了神庙..."<<endl;
							getch();
							return;
						} 
						break;
					case 1:
						if(map[x-1][y]=='#'){
							cout<<"请勿乱输！"<<endl;
							getch();
							continue;
						}else{
							cout<<"你向着前方走去..."<<endl;
							x--;
							getch();
							continue;
						}
						break;
					case 2:
						if(map[x][y-1]=='#'){
							cout<<"请勿乱输！"<<endl;
							getch();
							continue;
						}else{
							cout<<"你向着左边走去..."<<endl;
							y--;
							getch();
							continue;
						}
						break;
					case 3:
						if(map[x][y+1]=='#'){
							cout<<"请勿乱输！"<<endl;
							getch();
							continue;
						}else{
							cout<<"你向着右边走去..."<<endl;
							y++;
							getch();
							continue;
						}
						break;  
					}
				}   
			}
		} 
	}
	if(place=="沙漠神殿"){
		
	} 
	if(place=="寒冰洞窟"){
		map[0]="#####"; 
		map[1]="##2##";
		map[2]="##1##";
		map[3]="##1##";
		map[4]="##0##";
		cout<<"男人带着你，跟着一群全副武装的士兵，在雪地中行走着。"<<endl;
		Sleep(1000);
		getch();
		cout<<"很快，你们到了一个洞窟前，入口是一块巨大的寒冰，洞窟的上方布满冰刺。"<<endl;
		getch();
		say("“到了...”\n",40);
		getch();
		cout<<"祝你好运..."<<endl; 
		x=4,y=2; 
		getch();
		say("你缓缓走进洞窟，等待你的会是什么呢...",50);
		Sleep(1000);
		while(1){
			reset();//重置 
			system("cls");
			levelup(experience);
			if(map[x][y]=='1'){
				cout<<"你走进内部，发现了一些怪物！"<<endl;
				getch();
				switch(1+rand()%3){
				case 1:
					cout<<"你遇见了寒冰僵尸！"<<endl;
					getch();
					fight("寒冰僵尸",20,4+rand()%2,0,6+rand()%5,3,4+rand()%3,2,200,1);
					drop("寒冰僵尸");
					if(!dead){
						say("你的意识渐渐模糊...",100);
						getch();
						return; 
					}else{
						map[x][y]='0';
						if(maxhealth-health>0){
							cout<<"你原地休息片刻，恢复了10%的生命！"<<endl;
							health+=min(maxhealth/10,maxhealth-health);
							getch();
						}   
					} 
					break;
				case 2:
					cout<<"你遇见了寒冰骷髅！"<<endl;
					getch();
					enemyskill[41]=1; 
					fight("寒冰骷髅",20,3+rand()%2,0,0+rand()%5,2,7+rand()%5,8,300,2);
					drop("寒冰骷髅");
					enemyskill[41]=0;
					if(!dead){
						say("你的意识渐渐模糊...",100);
						getch();
						return; 
					}else{
						map[x][y]='0';
						if(maxhealth-health>0){
							cout<<"你原地休息片刻，恢复了10%的生命！"<<endl;
							health+=min(maxhealth/10,maxhealth-health);
							getch();
						}   
					} 
					break; 
				case 3:
					cout<<"你遇见了寒冰蜘蛛！"<<endl;
					getch();
					fight("寒冰蜘蛛",20,6+rand()%3,0,-12+rand()%4,4,8+rand()%4,2,300,2);
					drop("寒冰蜘蛛");
					if(!dead){
						say("你的意识渐渐模糊...",100);
						getch();
						return; 
					}else{
						map[x][y]='0';
						if(maxhealth-health>0){
							cout<<"你原地休息片刻，恢复了10%的生命！"<<endl;
							health+=min(maxhealth/10,maxhealth-health);
							getch();
						}   
					} 
					break;  
				}
			}
			if(map[x][y]=='2'){
				cout<<"你在原地休息了一会儿，恢复了50%生命值！"<<endl;
				health+=min(maxhealth/2,maxhealth-health);
				getch();
				system("cls");
				Sleep(1000);
				say("你走进洞穴的中心，四处都是巨大的坚冰。\n",60);
				getch(); 
				say("你走上前时，发现了一块毛茸茸的地毯...?",60);
				getch();
				system("cls");
				Sleep(1000);
				say("“唔哇啊啊啊啊！！！”\n",50);
				getch();
				say("“地毯”忽然动了起来！\n",50);
				getch();
				say("原来那不是地毯，是一只巨型雪怪！！\n",50);
				Sleep(1000); 
				say("雪怪看到你。咆哮着向你袭来！！！",50);
				getch();
				system("cls"); 
				system("cls");
				cout<<"战斗！"<<endl;
				Sleep(1000);
				enemyskill[2]=1;
				enemyskill[33]=1;
				enemyskill[43]=1;
				fight("巨型雪怪",80,9,0,12,3,11,2,2000,10);
				drop("巨型雪怪");
				if(dead){
					say("雪怪被你击杀了！...\n",50);
					getch();
					cout<<"男人带着你上前查看，发现了一个冰封的箱子！"<<endl;
					getch();
					say("“宝箱！！！”",30);
					getch(); 
					say("男人打开宝箱，在里面挑了些东西。\n",60);
					getch();
					say("“剩下的给你。”",50);
					say("说完，男人就带着人离开了。",80);
					getch();
					cout<<"你获得了 15 个绿宝石！"<<endl;
					money+=15;
					getch();
					cout<<"你获得了 "<<itemname[97]<<" x1！"<<endl;
					bag[97]++;
					getch();
				}
			}
			system("cls");
			if(x==1) cout<<"你现在位于洞穴尽头，已经没有路了。"<<endl;
			if(map[x][y]=='0') cout<<"你现在位于洞穴内部。";
			cout<<endl;
			//cout<<x<<" "<<y<<endl; 
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|4);
			cout<<"血量："<<health<<"/"<<maxhealth<<endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|1);
			cout<<"魔力："<<magic<<"/"<<maxmagic<<endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|7);
			cout<<"攻击："<<attack<<endl;
			cout<<"防御："<<defense<<endl;
			cout<<"速度："<<speed<<endl;
			cout<<"绿宝石："<<money<<endl;
			cout<<"等级："<<level;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|2);
			cout<<" 经验："<<experience<<"/"<<level*100<<endl; 
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|7);    
			cout<<"-----------------------------------" <<endl; 
			cout<<"你要做什么？"<<endl;
			if(map[x-1][y]!='#') cout<<"1，前进  ";
			else cout<<"1，离开"<<endl;
			cout<<endl;
			cin>>choose; 
			if(choose!=1){
				cout<<"请勿乱输！"<<endl;
				getch();
				continue;
			}else{
				if(map[x-1][y]=='#'){
					cout<<"你离开了洞穴..."<<endl;
					getch();
					badguy=6;
					return;
				}else{
					cout<<"你向着前方走去..."<<endl;
					x--;
					getch();
					continue;   
				}
			}   
		}
	} 
	return; 
}

inline void explore(string place){//探索
	if(place=="村庄"){        
		if(undeadattack){
			system("cls");
			enemyattack();
			return;
		}
		switch(rand()%15){
		case 0:
		case 8:
			cout<<"你遇到了铁傀儡！"<<endl;
			cout<<"0，离开  1，激怒"<<endl;
			cin>>choose;
			if(choose==1){
				fight("铁傀儡",100,9,30,20,2,10,3,500,5);
				credit-=20;
				drop("铁傀儡");
			}else{
				cout<<"你远离了铁傀儡"<<endl; 
				getch();
				break;
			}
			break;
		case 1:
		case 10:
			if(badguy==0){
				cout<<"你看见了一名恶霸正在欺负一名村民..."<<endl;
				cout<<"1，阻止  2，离开  3，一起欺负"<<endl;
				cin>>choose;
				if(choose==1){
					cout<<"战斗！"<<endl;
					Sleep(2000);
					fight("恶霸村民",20,2,0,-20,2,5,2,100,1);
					if(dead){
						credit+=5;
						dead=false;
						Sleep(2000);
						cout<<"你走到那名恶霸面前，说："<<endl;
						Sleep(2000);
						cout<<"以后不要再欺负别人了！"<<endl;
						Sleep(2000);
						cout<<"恶霸看了你一眼，灰溜溜的跑了"<<endl;
						badguy=2;
						Sleep(2000);
						cout<<"被欺负的村民十分感激，给了你 3 颗绿宝石"<<endl;
						money+=3;      
						getch();
					}else{
						cout<<"恶霸走到你面前，嘲讽道：不过如此！还想见义勇为？"<<endl;
						Sleep(2000);
						cout<<"那我就成全你，他的钱我不要了，你的钱给我！！！"<<endl;
						Sleep(2000);
						money=0;
						cout<<"你的钱被恶霸全部拿走了..."<<endl; 
						getch();
					}
				}else{
					if(choose==2){
						cout<<"你默默走开了。"<<endl;
						Sleep(2000);
						credit-=15;
					}else{
						cout<<"你冲过去，推开了恶霸，自己抢走村民身上所有的绿宝石。"<<endl;
						money+=6;
						Sleep(1500);
						cout<<"获得了 6 颗绿宝石！"<<endl;
						credit-=25;
						badguy=1;
						getch();
					}
				}
			}else if(badguy==2){
				cout<<"你又遇到了之前欺负人的村民"<<endl;
				Sleep(1500);
				cout<<"那位村民告诉你，雪地有一个村民发布了任务，完成了就有丰厚的奖品"<<endl;
				Sleep(2000);
				cout<<"临走前，他给了你 2 颗绿宝石"<<endl;
				money+=2;
				badguy=3;
				getch();
			}else{
				cout<<"你什么都没遇见..."<<endl;
				getch(); 
			}
			break;  
		case 2:
			cout<<"你在地上发现了 1 颗绿宝石！"<<endl;
			money+=1;
			getch();    
			break;
		case 3:
			cout<<"你来到了村庄旅馆"<<endl;
			Sleep(1000);
			cout<<"0，离开  1，进入"<<endl;
			cin>>choose;
			if(choose==1){
				if(credit<=30){
					cout<<"你刚进去，就有个人喊：那是个坏人！"<<endl;
					Sleep(2000);
					cout<<"里面的人看到你，连忙将你赶出去"<<endl;
					Sleep(2000);
					cout<<"店主看到你，说：你不配住我的旅馆！"<<endl;
					getch();     
				}else{
					cout<<"你走进旅馆"<<endl;
					Sleep(2000);
					cout<<"当前你有 "<<money<<" 颗绿宝石"<<endl; 
					int cost=min(max((maxhealth-health)/8,1),5); 
					cout<<"要休息吗？需要 "<<cost<<" 颗绿宝石（休息可恢复生命值）"<<endl;
					cout<<"0，离开  1，休息"<<endl;
					cin>>choose;
					if(choose==1){
						if(money<cost){
							cout<<"你突然发现自己的钱不够，你只好尴尬的走了"<<endl;
							Sleep(2000);
						}else{
							system("cls");
							cout<<"店主给你开了一间房，你在里面美美的睡了一觉..."<<endl;
							money-=cost;
							cout<<"你还剩 "<<money<<" 颗绿宝石！"<<endl;
							Sleep(1000);
							health=maxhealth;
							say("zzzZZZ\n",500);
							Sleep(5000);
							cout<<"请按任意键继续..."<<endl; 
							getch();
						} 
					}
				}
			}
			break;  
		case 4:
		case 9:
			cout<<"你遇见了村庄中德高望重的老者-图书管理员"<<endl; 
			getch();
			cout<<"这位老者知晓这个世界上的种种事情..."<<endl<<endl;
			getch();
			if(credit<=30){
				cout<<"图书管理员只是轻轻扫视过你身上，你就感觉内心仿佛被审视了一般"<<endl;
				getch();
				cout<<"你感觉罪恶爬上了你的脊梁..."<<endl;
				getch();
				cout<<"“你都做了什么，没有人比你更清楚，即使是遇见弱小者也不愿伸手援助，甚至助纣为虐...”"<<endl;
				getch();
				cout<<"顷刻间，图书管理员便消失在你的视线中..."<<endl;
				getch(); 
			}else{
				cout<<"你要与图书管理员交谈吗？（0，离开  1，交谈）"<<endl;
				cin>>choose;
				if(choose==1){
					cout<<"你要询问什么？"<<endl;
					cout<<"1，关于远古时期的战争"<<endl;
					cout<<"2，Herobrine的信徒/势力"<<endl;
					cout<<"3，Herobrine归来的传言"<<endl;
					cout<<"4，关于创世之力"<<endl;
					cout<<"5，关于亡灵势力"<<endl; 
					cout<<"6，关于地狱"<<endl;
					cout<<"7，关于末地"<<endl;
					cin>>choose;
					switch(choose){
					case 1:
						system("cls");
						Sleep(2000); 
						cout<<"在远古时期，也就是这个世界刚被创造出的时候，世界上有两位神，也就是Notch和Herobrine，而这两位神是兄弟。"<<endl; 
						cout<<"因Herobrine创造了亡灵生物，两人意见逐渐不和，最终他们的关系分崩离析。"<<endl;
						cout<<"Notch本与Herobrine互不干涉，但Herobrine创造出的亡灵生物组成了一支亡灵大军----"<<endl;
						cout<<"这支亡灵大军四处前进，所过之处血流成河，尸骨遍地..."<<endl;
						cout<<"Notch看着方块世界生灵涂炭，决心阻止Herobrine，而这就是战争的导火索..."<<endl;
						cout<<"亡灵生物可以将死去的生灵转变为亡灵，当时的人类只得四处逃亡。"<<endl;
						cout<<"Notch使用了大量的「 创世之力」才成功解决了一大部分的亡灵，但仍有部分亡灵侥幸活了下来。"<<endl;
						cout<<"而后，Notch已经没有足够的力量对付Herobrine了，他只好用出剩余的「 创世之力」，将Herobrine封印在了地狱..."<<endl;
						cout<<"但是，似乎Herobrine正积蓄着力量，破开封印..."<<endl<<endl;
						cout<<"图书管理员叹了口气。"<<endl;
						cout<<"0，离开  1，继续询问"<<endl;
						cin>>choose;
						if(choose==1){
							cout<<"管理员：以后再来吧，现在我累了..."<<endl;
							getch(); 
						}     
						break;
					case 2:
						system("cls");
						Sleep(2000); 
						cout<<"早在创世初期，Herobrine就展示出了与他的哥哥截然不同的性格。"<<endl; 
						cout<<"他放荡不羁，将自己当作众生的主宰，将世界当作自己的游戏。"<<endl;
						cout<<"早期，Herobrine还不至于做些太出格的事情。"<<endl;
						cout<<"但随着时间推移，Herobrine越来越狂妄，开始向世界各地建立自己的势力。"<<endl;
						cout<<"他用自己的「 混沌之力」和亡灵创造出了一个又一个他的忠实手下。"<<endl;
						cout<<"后来，他又凭借着自己强大的力量，收服了世界各地的一个个强者，并用自己的力量使他们变得更强。"<<endl;
						cout<<"而Herobrine自身也在世界上留有一些自己的虚影。这些虚影代表着Herobrine，但实力远不及本体。"<<endl;
						cout<<"每道虚影都有着一些简单的自己的意识，但他们最终都由Herobrine控制。似乎，虚影之间可以互相联系。"<<endl; 
						cout<<"像 NULL，恐惧魔王，Entity_303等...都是Herobrine忠实的手下。"<<endl;
						cout<<"若他们联合起来，集结所有的力量，Herobrine很可能将会破开封印，重回世界..."<<endl<<endl;
						cout<<"图书管理员的面色变得凝重。"<<endl;
						cout<<"0，离开  1，继续询问"<<endl;
						cin>>choose;
						if(choose==1){
							cout<<"管理员：以后再来吧，现在我累了..."<<endl;
							getch(); 
						} 
						break;
						case 3: 
						system("cls");
						Sleep(2000); 
						cout<<"Herobrine的归来..."<<endl; 
						cout<<"这不是谣言，也许很快就会发生...创世神Notch已不知所踪，地狱的恐惧魔王已经集结了猪人们，Herobrine很可能会破开封印。"<<endl;
						cout<<"在遥远的边境之地，那里混合着创世之力与混沌之力，地面被拉伸成一堵高墙，一切事物都变得混乱。"<<endl;
						cout<<"而Null，就在边境之地..."<<endl;
						cout<<"作为Herobrine最忠心最强大的手下之一，Null的实力无人知晓。"<<endl;
						cout<<"Null在Herobrine的训练之下，已经洞悉了虚空之力，还掌握了一丝混沌之力。"<<endl; 
						cout<<"Herobrine曾经的势力，必将会不惜所有代价，强行打破Herobrine的封印..."<<endl;
						cout<<"图书管理员的面色变得凝重。"<<endl;
						cout<<"0，离开  1，继续询问"<<endl;
						cin>>choose;
						if(choose==1){
							cout<<"管理员：以后再来吧，现在我累了..."<<endl;
							getch(); 
						} 
						break;
					case 4:
						system("cls");
						Sleep(2000); 
						cout<<"创世之力，便是Notch所拥有的神力。"<<endl; 
						cout<<"这种神力拥有着创造的能力，是最纯粹，最强大的力量。"<<endl;
						cout<<"Herobrine所拥有的，便是混沌之力。与Notch相反，充满着破坏，不稳定性。"<<endl;
						cout<<"正是当初Notch和Herobrine联手，消耗了大量神力，才创造出了这个世界。"<<endl;
						cout<<"而也只有创世之力，才能抗衡Herobrine的混沌之力。"<<endl;
						cout<<"但Notch在大战后便消失了踪迹，创世之力也不知道在哪里..."<<endl;
						cout<<"图书管理员的面色变得凝重。"<<endl;
						cout<<"0，离开  1，继续询问"<<endl;
						cin>>choose;
						if(choose==1){
							cout<<"管理员：以后再来吧，现在我累了..."<<endl;
							getch(); 
						} 
						break;
					case 5:
						system("cls");
						Sleep(2000); 
						cout<<"亡灵生物，是Herobrine用亡灵之力与混沌之力创造出的。"<<endl; 
						cout<<"这种生物可以将死去的生灵转变成亡灵。"<<endl;
						cout<<"也就是说，通过亡灵的四处吞噬，感染，可以轻易的组成一支亡灵大军。"<<endl;
						cout<<"而Herobrine正是凭借着数量庞大的亡灵军队，才得以与Notch抗衡。"<<endl;
						cout<<"Herobrine曾经忠心耿耿的下属，亡灵的领导者Blackbone组织着亡灵生物们..."<<endl;
						cout<<"尽管Notch拥有创世之力，但也无法彻底除掉亡灵。"<<endl;
						cout<<"“这将是一个致命的威胁。”图书管理员的面色变得凝重。"<<endl;
						cout<<"0，离开  1，继续询问"<<endl;
						cin>>choose;
						if(choose==1){
							cout<<"管理员：以后再来吧，现在我累了..."<<endl;
							getch(); 
						}   
						break;  
					case 6:
						system("cls");
						Sleep(2000); 
						cout<<"地狱，一个充斥着岩浆与狱岩的地方。传说也是封印Herobrine的地方..."<<endl; 
						cout<<"地狱危机重重，要时刻小心跌入岩浆，还要提防可怕的恶魂，岩浆怪"<<endl;
						cout<<"而在地狱中，有一种特殊的种族--猪灵。"<<endl;
						cout<<"猪灵是一种贪财的生物，给他们金锭便能与他们交易，但你却不能知道自己能得到什么。"<<endl;
						cout<<"地狱的深处还隐藏着一种重金属，叫下界合金。这些合金需要在地狱的深处挖掘坚硬的远古残骸提炼而成。"<<endl;
						cout<<"另外，地狱中还暗藏着一些猪灵的堡垒，以及下界要塞，这些地方都隐藏着珍贵的宝藏，以及--无穷的危机。"<<endl;
						cout<<"图书管理员叹了口气。"<<endl;
						cout<<"0，离开  1，继续询问"<<endl;
						cin>>choose;
						if(choose==1){
							cout<<"管理员：以后再来吧，现在我累了..."<<endl;
							getch();
						} 
						break;
					case 7:
						system("cls");
						Sleep(2000); 
						cout<<"末地，一个位于虚空的另一维度。"<<endl; 
						cout<<"那里矗立着数根黑曜石柱，在末地的主岛上还有一条巨龙。"<<endl;
						cout<<"在末地里，四处充斥着末影人。这里的末影人都是在时空缝隙中不小心穿越过来的。"<<endl;
						cout<<"打败末影龙后，就可以前往末地的外岛了。外岛中散布着一些末地城，这些城市里面藏着许多宝藏。"<<endl;
						cout<<"但要打败末影龙可不容易，黑曜石柱上的末影水晶会为末影龙持续恢复力量。"<<endl;
						cout<<"不过，要前往末地，必须要找到世界与末地的折跃链接口，我听说在地下曾经有一个废弃的要塞，里面供奉着末地之门..."<<endl;
						cout<<"图书管理员叹了口气。"<<endl;
						cout<<"0，离开  1，继续询问"<<endl;
						cin>>choose;
						if(choose==1){
							cout<<"管理员：以后再来吧，现在我累了..."<<endl;
							getch();
						} 
						break;  
					}
				}
			} 
			break;
		case 5:
			cout<<"你发现了一个睡着的农民"<<endl;
			Sleep(1000);
			cout<<"0，叫醒  1，偷东西"<<endl;
			cin>>choose;
			if(choose==1){
				credit-=20;
				int add=rand()%4;
				if(add==0){
					cout<<"你偷偷摸了摸农民的口袋，发现空空如也！"<<endl;
					Sleep(1500);
					cout<<"农民惊醒了，大喊：小偷！！！"<<endl;
					Sleep(1500);
					cout<<"一旁的铁傀儡冲来!"<<endl;
					getch();
					fight("铁傀儡",100,9,40,20,2,10,3,200,5);
					if(dead) drop("铁傀儡");
					else{
						cout<<"你的钱被铁傀儡全部夺走了！"<<endl;
						money=0; 
						getch();
						return;
					}
				}else{
					cout<<"你偷偷摸了摸农民的口袋，发现有 "<<add<<" 颗绿宝石！"<<endl;
					money+=add;
					Sleep(1000);
					cout<<"你又悄悄地走了"<<endl;
					getch();
				}
			}else{
				cout<<"你叫醒了农民"<<endl;
				Sleep(1000);
				cout<<"农民对你不停感谢"<<endl;
				credit+=1;
				getch();
			}
			break;
		case 6:
			cout<<"你走到村庄中心，发现了一个雕像..."<<endl;
			Sleep(1500);
			cout<<"你仔细一看，是创世神Notch的雕像！"<<endl;
			getch();
			cout<<"但你环顾四周，发现竟没有一个村民祭拜雕像。"<<endl;
			getch();
			cout<<"而雕像也无人清理，十分破旧。"<<endl<<endl;
			getch();
			if(credit<=20){
				cout<<"你对着雕像，冷笑一声，吐了一口口水便离去了"<<endl;
				getch();
				credit-=5;
				return;
			}
			cout<<"0，离开  1，祭拜雕像"<<endl;
			cin>>choose;
			if(choose==1){
				system("cls");
				cout<<"你正欲祭拜时，一个村民对你喊道：不要祭拜！"<<endl;
				Sleep(1500);
				cout<<"你很奇怪，问为什么不能祭拜。"<<endl;
				getch();
				cout<<"村民说：一旦我们祭拜了创世神的雕像，周围的亡灵生物便会感到威胁，前来攻打我们的村庄！"<<endl<<endl;
				getch();
				cout<<"0，离开  1，继续祭拜"<<endl;
				cin>>choose;
				if(choose==1){
					credit+=5;
					cout<<"你没有犹豫，对着雕像拜了下去..."<<endl; 
					Sleep(2000);
					if(blesscold==0){
						cout<<"获得Notch之祝福！下次战斗时生效"<<endl;
						blessing=true;
						getch();
						blesscold=2;
					}else blesscold--;  
					if(1+rand()%2==1){
						undeadattack=true;
						cout<<"然而，你突然有了一种不祥的预感..."<<endl;
						getch(); 
					} 
				} 
			} 
			break;
		case 7:
			cout<<"你什么都没遇见..."<<endl;
			getch(); 
			break;
		case 11:
			cout<<"你遇见了流浪商人！"<<endl;
			getch();
			cout<<"0，离开  1，交易"<<endl; 
			cin>>choose;
			if(choose==1) shoper("流浪商人");
			else return;
			break;  
		case 12:
			cout<<"你遇见了附魔师！"<<endl;
			getch();
			cout<<"这位老者精通魔力与经验的神秘力量。"<<endl;
			cout<<"0，离开  1，交谈"<<endl;
			cin>>choose;
			if(choose==1){
				if(credit<=20){
					cout<<"附魔师看到了你，不屑的冷哼一声，走开了。"<<endl;
					getch();
					return;
				}
				while(1){
					system("cls");
					cout<<"你要干什么？"<<endl;
					cout<<"当前等级："<<level<<endl;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|2);
					cout<<"经验："<<experience<<"/"<<level*100<<endl;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|1);
					cout<<"魔力："<<magic<<"/"<<basicmagic<<endl;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|7);
					cout<<"绿宝石："<<money<<endl; 
					cout<<"0，离开  1，压缩  2，魔力"<<endl;
					cin>>choose;
					switch(choose){
					case 0:
						cout<<"你向老者一拜，走开了。"<<endl;
						getch();
						return;
						break;
					case 1:
						cout<<"\n压缩一次需要 100 经验和 1 绿宝石。"<<endl;
						cout<<"当前你有 ";
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|2);
						cout<<xp_orb<<" 个压缩经验球"<<endl<<endl;    
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|7);
						cout<<"0，返回  1，压缩"<<endl;
						cin>>choose;
						if(choose==1){
							if(experience<100||money<1){
								cout<<"你的经验不足或绿宝石不足！"<<endl;
								getch();
								continue;
							}else{
								cout<<"你将体内的经验进行压缩..."<<endl;
								Sleep(2000);
								cout<<"获得 1 个";
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|2);
								cout<<"压缩经验球！"<<endl;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|7);
								experience-=100;
								money--; 
								xp_orb++;
								cout<<"当前你有 ";
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|2);
								cout<<xp_orb<<" 个压缩经验球"<<endl;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|7);
								getch();
							}
						}else continue;         
						break;  
					case 2:
						if(magicup>=12){
							cout<<"你已达到提升上限！"<<endl;
							getch();
							continue; 
						}
						if(magicup==11){
							cout<<"附魔师看着你，轻叹一声。"<<endl;
							getch();
							say("“我的实力有限，现在已经难以单纯以青金石提升你的魔力了。”\n",50); 
							Sleep(500);
							say("“魔力与经验，相辅相成。”\n",50);
							Sleep(500);
							say("“魔力，是技能之能量来源。”\n",50);
							Sleep(500);
							say("“经验，是魔力之根本。”\n",50);
							getch();
							say("“虽然提升不了你的魔力，",50);
							Sleep(1000);
							say("但我有一个秘法，可以提升你技能的水平。”\n",50);
							getch();
							say("“只需要 99 个青金石和 30 个压缩经验球，且等级大于等于 25 级。”\n",50);
							cout<<"0，返回  1，提升"<<endl;  
							cin>>choose;
							if(choose==1){
								if(bag[43]<99||xp_orb<30||level<25){
									cout<<"你不满足提升条件！"<<endl;
									getch();
									continue; 
								}else{
									bag[43]-=99;
									xp_orb-=30;
									cout<<"提升成功！可携带技能上限 + 1 ！"<<endl;
									skilltakemax++; 
									magicup++;
									getch();
									continue;
								}
							}else continue;
						}else{
							cout<<"\n提升一次魔力可以增加 ";
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|1);
							cout<<"1 点魔力上限。";
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|7);
							cout<<"最多可提升 10 次。"<<endl;
							cout<<"已提升 "<<magicup-1<<" 次。"<<endl;
							cout<<"提升需要青金石 "<<magicup*9<<" 个，";
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|2);
							cout<<"压缩经验球 "<<magicup*2<<" 个";
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|7);
							cout<<"，且等级大于等于 "<<magicup*2<<" 。"<<endl;
							cout<<"当前你有青金石 "<<bag[43]<<" 个。"<<endl<<endl;
							cout<<"0，返回  1，提升"<<endl;  
							cin>>choose;
							if(choose==1){
								if(bag[43]<magicup*9||xp_orb<magicup*2||level<magicup*2){
									cout<<"你不满足提升条件！"<<endl;
									getch();
									continue; 
								}else{
									bag[43]-=magicup*9;
									xp_orb-=magicup*2;
									cout<<"提升成功！"<<endl;
									basicmagic++;
									magicup++;
									magic++;
									getch();
									continue;
								}
							}else continue;
						}
						break;  
					}   
				}           
			}else{
				cout<<"你缓缓走远了"<<endl;
				getch();
			}
			break; 
		case 13:
		case 14:
			cout<<"你遇见了一个抽奖机！"<<endl;
			cout<<"来一发？(只需 3 绿宝石一次！)\n"<<endl;
			cout<<"0，走开  1，抽奖"<<endl;
			cin>>choose;
			if(choose==1){
				cout<<"你确定？"<<endl;
				Sleep(1000);
				cout<<"当然！为什么不呢？！"<<endl;
				cout<<"你忐忑的按下了按钮..."<<endl;
				getch();
				if(money<3){
					cout<<"机器里传来声清脆的脏话：没钱给老子滚！"<<endl;
					getch();
					cout<<"你看着机器的屏幕上闪出一句话：RP--！"<<endl;
					credit--;
					getch();
				}else{
					money-=3; 
					system("cls");
					int sleeptime=1,prize;
					if(1+rand()%10<=4) prize=0;
					else prize=rand()%18;
					string prizename[20]={"再接再厉","下次一定","谢谢惠顾","空气 x114514","木棍 x114","煤炭 x4","铁锭 x4","金锭 x4","钻石 x2","治疗药水",
						"重击技能书","三连击技能书","下界合金碎片","青金石 x10","黑曜石 x2","绿宝石 x4","绿宝石 x1","橡木木板 x1"};
					for(int i=1;i<=28+rand()%12;i++){
						cout<<"您的奖品 > "<<prizename[i%18]<<endl; 
						Sleep(sleeptime);
						sleeptime+=i;
						system("cls");
					}
					cout<<"您的奖品 > "<<prizename[prize]<<endl; 
					Sleep(1000); 
					system("cls"); 
					cout<<"恭喜你获得奖品："<<prizename[prize]<<"！"<<endl;
					getch();
					switch(prize){
					case 3:
						cout<<"空气 x114514 已邮寄于您的肺中！请注意查收！"<<endl;
						getch();
						break;  
					case 4:
						cout<<"木棍 x114 已储存于您的背包中！请注意查收！"<<endl;
						bag[10]+=114;
						getch();
						break;
					case 5:
						cout<<"煤炭 x4 已储存于您的背包中！请注意查收！"<<endl;
						bag[19]+=4;
						getch();
						break;
					case 6:
						cout<<"铁锭 x4 已储存于您的背包中！请注意查收！"<<endl;
						bag[21]+=4;
						getch();
						break;
					case 7:
						cout<<"金锭 x4 已储存于您的背包中！请注意查收！"<<endl;
						bag[32]+=4;
						getch();
						break;
					case 8:
						cout<<"钻石 x2 已储存于您的背包中！请注意查收！"<<endl;
						bag[44]+=2;
						getch();
						break;
					case 9:
						cout<<"治疗药水 x1 已储存于您的背包中！请注意查收！"<<endl;
						bag[1001]+=1;
						getch();
						break;
					case 10:
						cout<<"重击技能书 x1 已储存于您的背包中！请注意查收！"<<endl;
						bag[66]+=1;
						getch();
						break;
					case 11:
						cout<<"三连击技能书 x1 已储存于您的背包中！请注意查收！"<<endl;
						bag[67]+=1;
						getch();
						break;
					case 12:
						cout<<"下界合金碎片 x1 已储存于您的背包中！请注意查收！"<<endl;
						bag[56]+=1;
						getch();
						break;
					case 13:
						cout<<"青金石 x10 已储存于您的背包中！请注意查收！"<<endl;
						bag[43]+=10;
						getch();
						break;
					case 14:
						cout<<"黑曜石 x2 已储存于您的背包中！请注意查收！"<<endl;
						bag[65]+=2;
						getch();
						break;
					case 15:
						cout<<"绿宝石 x4 已储存于您的背包中！请注意查收！"<<endl;
						money+=4;
						getch();
						break;
					case 16:
						cout<<"绿宝石 x1 已储存于您的背包中！请注意查收！"<<endl;
						money+=1;
						getch();
						break;
					case 17:
						cout<<"橡木木板 x1 已储存于您的背包中！请注意查收！"<<endl;
						bag[5]+=1;
						getch();
						break;
					}
				}
			}else{
				cout<<"你看着那台小小的抽奖机，心中冷笑一声，走开了。\n“这么小的抽奖机，肯定没好东西...”"<<endl;
				getch();
				if(money<3) cout<<"毕竟就算有东西，你也没钱..."<<endl;
				getch();
			}
			break;  
		} 
	}
	//平原冒险内容 
	if(place=="平原"){
		int find=rand()%100;
		if(find==0){
			cout<<"你发现了一个废弃的地狱传送门！"<<endl;
			getch();
			int obsidian=2+rand()%2,gold=2+rand()%3; 
			cout<<"你打开箱子，获得了 "<<obsidian<<" 个黑曜石和 "<<gold<<" 个金锭！"<<endl;
			bag[65]+=obsidian;
			bag[32]+=gold;
			getch();
			return;
		}
		switch(rand()%12){
		case 0:
			case 10:    
			if(task1==0){
				cout<<"你遇见了一个旅行家！"<<endl;
				Sleep(1500);
				choose=1+rand()%2;
				if(choose==1){
					cout<<"旅行家对你说，他身上没有木头了，你能不能给他带来 10 个橡木？"<<endl;
					cout<<endl<<"0，拒绝  1，接受"<<endl;
					cin>>choose;
					if(choose==1){
						cout<<"获得任务：收集橡木！"<<endl;
						task1=1;
						getch();
						cout<<"注：完成任务后，需找到冒险家结算任务方可领取奖励。"<<endl;
						getch();
					}else{
						cout<<"你拒绝了旅行家"<<endl;
						getch();
					}
				}
				if(choose==2){
					cout<<"旅行家对你说，他身上没有原石了，你能不能给他带来 30 个圆石？"<<endl;
					cout<<endl<<"0，拒绝  1，接受"<<endl;
					cin>>choose;
					if(choose==1){
						cout<<"获得任务：采集圆石！"<<endl;
						task1=2;
						getch();
						cout<<"注：完成任务后，需找到冒险家结算任务方可领取奖励。"<<endl;
						getch();
					}else{
						cout<<"你拒绝了旅行家"<<endl;
						getch();
					}
				}
			}else{
				if(task1==1){
					if(bag[1]<10){
						cout<<"你找到了旅行家"<<endl;
						Sleep(1500);
						cout<<"你现在只有 "<<bag[1]<<" 个橡木，你没有完成任务！"<<endl;
						Sleep(1500);
						cout<<"旅行者看着你，生气的走了"<<endl;
						getch();
						cout<<"任务作废！"<<endl;
						task1=0;
						credit-=15;
						getch(); 
						return;
					}else{
						int add=1+rand()%4; 
						cout<<"你找到了旅行家"<<endl;
						Sleep(1500);
						cout<<"你交给了旅行家 10 个橡木！"<<endl;
						bag[1]-=10; 
						Sleep(1500);
						cout<<"旅行家十分高兴，给了你 "<<add<<" 颗绿宝石作为奖励！"<<endl;
						money+=add;
						getch();
						cout<<"任务已完成！"<<endl;
						task1=0;
						credit+=5;
						getch();
						return;
					}
				}
				if(task1==2){
					if(bag[14]<30){
						cout<<"你找到了旅行家"<<endl;
						Sleep(1500);
						cout<<"你现在只有 "<<bag[14]<<" 个圆石，你没有完成任务！"<<endl;
						Sleep(1500);
						cout<<"旅行家看着你，生气的走了"<<endl;
						getch();
						cout<<"任务作废！"<<endl;
						task1=0;
						credit-=15;
						getch(); 
						return;
					}else{
						int add=1+rand()%4; 
						cout<<"你找到了旅行家"<<endl;
						Sleep(1500);
						cout<<"你交给了旅行家 30 个圆石！"<<endl;
						bag[14]-=30; 
						Sleep(1500);
						cout<<"旅行家十分高兴，给了你 "<<add<<" 颗绿宝石作为奖励！"<<endl;
						money+=add;
						getch();
						cout<<"任务已完成！"<<endl;
						task1=0;
						credit+=5;
						getch();
						return;
					}
				}
			}
			break;
		case 1:
			cout<<"你遇见了一头牛！"<<endl;
			cout<<"0，离开  1，击杀"<<endl;
			cin>>choose;
			if(choose==1){
				fight("牛",20,2,100,-10,3,10,1,50,0);
			}else return;
			break;
		case 2:
			cout<<"你遇见了一只羊！"<<endl;
			cout<<"0，离开  1，击杀"<<endl;
			cin>>choose;
			if(choose==1){
				fight("羊",20,2,100,-10,3,10,1,50,0);
			}else return;
			break;
		case 3:
			cout<<"你什么也没遇见..."<<endl;
			getch();
			break;  
			case 4: 
			cout<<"你遇见了一只僵尸！"<<endl;
			cout<<"0，离开  1，击杀"<<endl;
			cin>>choose;
			if(choose==1){
				fight("僵尸",20,3,25,0,3,5,2,100,1);
				drop("僵尸"); 
			}else{
				choose=rand()%2;
				if(choose==1){
					cout<<"你正欲离开时，僵尸发现了你并向你冲来！"<<endl;
					getch();
					fight("僵尸",20,3,25,0,3,5,2,100,1);
					drop("僵尸"); 
				}else{
					cout<<"你悄悄走开了。"<<endl;
					getch();
				} 
			}
			break;
		case 5:
			cout<<"你遇见了流浪商人！"<<endl;
			getch();
			cout<<"0，离开  1，交易"<<endl; 
			cin>>choose;
			if(choose==1) shoper("流浪商人");
			else return;
			break;
			case 6: 
			cout<<"你遇见了一只骷髅！"<<endl;
			cout<<"0，离开  1，击杀"<<endl;
			cin>>choose;
			if(choose==1){
				fight("骷髅",20,3,20,0,1,6+rand()%4,8,250,2);
				drop("骷髅");
			}else{
				choose=rand()%2;
				if(choose==1){
					cout<<"你正欲离开时，骷髅发现了你！"<<endl;
					getch();
					fight("骷髅",20,3,20,0,1,6+rand()%4,8,250,2);
					drop("骷髅");
				}else{
					cout<<"你悄悄走开了。"<<endl;
					getch();
				} 
			}
			break;
			case 7: 
			cout<<"你遇见了一只强壮的僵尸！"<<endl;
			cout<<"0，离开  1，击杀"<<endl;
			cin>>choose;
			if(choose==1){
				enemyskill[2]=1; 
				fight("强壮僵尸",25,4,30,5,3,5,2,250,3);
				enemyskill[2]=0;
				drop("强壮僵尸"); 
			}else{
				choose=rand()%2;
				if(choose==1){
					cout<<"你正欲离开时，僵尸发现了你并向你冲来！"<<endl;
					getch();
					enemyskill[2]=1;
					fight("强壮僵尸",25,4,30,5,3,5,2,250,3);
					enemyskill[2]=0;
					drop("强壮僵尸");
				}else{
					cout<<"你悄悄走开了。"<<endl;
					getch();
				} 
			}
			break;
			case 8: 
			cout<<"你遇见了一只特殊的骷髅..."<<endl;
			cout<<"0，离开  1，击杀"<<endl;
			cin>>choose;
			if(choose==1){
				fight("狙击骷髅",20,7,25,0,2,10,10+rand()%5,500,5);
				drop("狙击骷髅");
			}else{
				choose=rand()%2;
				if(choose==1){
					cout<<"你悄悄走开了。"<<endl;
					getch();
				}else{
					cout<<"如同子弹般迅猛的箭射在了你的身前...看来你是跑不掉了！"<<endl;
					getch();
					fight("狙击骷髅",20,7,25,0,2,10,10+rand()%5,500,5);
					drop("狙击骷髅");
				} 
			}
			break;
		case 9:
			cout<<"你遇见了一名正被僵尸追逐的村民！"<<endl;
			cout<<"0，漠视  1，拯救"<<endl;
			cin>>choose;
			if(choose==0){
				credit-=20;
				cout<<"你毫无怜悯的看着被僵尸啃食的村民..."<<endl;
				Sleep(1000);
				cout<<"两只僵尸都向你冲来！"<<endl; 
				getch();
				fight("僵尸",20,3,0,0,3,5,2,50,0);
				fight("僵尸村民",20,3,0,0,3,5,2,0,1);
			}else{
				cout<<"你冲上前去，挡在了村民前面！"<<endl;
				getch();
				fight("僵尸",20,3,0,0,3,5,2,100,1);
				drop("僵尸"); 
				if(dead){
					credit+=3;
					cout<<"你击败了僵尸，村民对你无比感激！"<<endl;
					getch();
					cout<<"村民给了你 2 颗绿宝石！"<<endl;
					money+=2;
					getch();
				}else{
					cout<<"在你被僵尸激战时，村民已经去村庄找到了铁傀儡助战！"<<endl;
					getch();
					cout<<"铁傀儡打败了僵尸并将你救出。"<<endl;
					getch();
				}
			} 
			break;
			case 11:    
			cout<<"你遇见了一只末影人！"<<endl;
			cout<<"0，离开  1，注视"<<endl;
			cin>>choose;
			if(choose==1){
				fight("末影人",40,6,30,-10,9999,5,3,300,3);
				drop("末影人"); 
			}else{
				cout<<"你悄悄走开了。"<<endl;
				getch();
			}
			break;
		}
	}
	if(place=="森林"){
		int find=rand()%100;
		if(find==0){
			cout<<"你发现了一个废弃的地狱传送门！"<<endl;
			getch();
			int obsidian=2+rand()%2,gold=2+rand()%3; 
			cout<<"你打开箱子，获得了 "<<obsidian<<" 个黑曜石和 "<<gold<<" 个金锭！"<<endl;
			bag[65]+=obsidian;
			bag[32]+=gold;
			getch();
			return;
		}
		switch(1+rand()%9){
		case 1:
			cout<<"你遇见了一头牛！"<<endl;
			cout<<"0，离开  1，击杀"<<endl;
			cin>>choose;
			if(choose==1){
				fight("牛",20,2,100,0,3,10,1,50,0);
			}else return;
			break;
		case 2:
			cout<<"你遇见了一只羊！"<<endl;
			cout<<"0，离开  1，击杀"<<endl;
			cin>>choose;
			if(choose==1){
				fight("羊",20,2,100,0,3,10,1,50,0);
			}else return;
			break;
		case 3:
			cout<<"你什么也没遇见..."<<endl;
			getch();
			break;  
			case 4: 
			cout<<"你遇见了一只僵尸！"<<endl;
			cout<<"0，离开  1，击杀"<<endl;
			cin>>choose;
			if(choose==1){
				fight("僵尸",20,3,25,0,3,5,2,100,1);
				drop("僵尸");  
			}else{
				choose=rand()%2;
				if(choose==1){
					cout<<"你正欲离开时，僵尸发现了你并向你冲来！"<<endl;
					getch();
					fight("僵尸",20,3,25,0,3,5,2,100,1);
					drop("僵尸"); 
				}else{
					cout<<"你悄悄走开了。"<<endl;
					getch();
				} 
			}
			break;
		case 5:
			cout<<"你遇见了流浪商人！"<<endl;
			getch();
			cout<<"0，离开  1，交易"<<endl; 
			cin>>choose;
			if(choose==1) shoper("流浪商人");
			else return;
			break;
			case 6: 
			cout<<"你遇见了一只骷髅！"<<endl;
			cout<<"0，离开  1，击杀"<<endl;
			cin>>choose;
			if(choose==1){
				fight("骷髅",20,3,20,0,1,6+rand()%4,8,250,2);
				drop("骷髅");
			}else{
				choose=rand()%2;
				if(choose==1){
					cout<<"你正欲离开时，骷髅发现了你！"<<endl;
					getch();
					fight("骷髅",20,3,20,0,1,6+rand()%4,8,250,2);
					drop("骷髅");
				}else{
					cout<<"你悄悄走开了。"<<endl;
					getch();
				} 
			}
			break;
			case 7: 
			cout<<"你遇见了一只强壮的僵尸！"<<endl;
			cout<<"0，离开  1，击杀"<<endl;
			cin>>choose;
			if(choose==1){
				enemyskill[2]=1;
				fight("强壮僵尸",25,4,30,5,3,5,2,250,3);
				enemyskill[2]=0;
				drop("强壮僵尸");
			}else{
				choose=rand()%2;
				if(choose==1){
					cout<<"你正欲离开时，僵尸发现了你并向你冲来！"<<endl;
					getch();
					enemyskill[2]=1;
					fight("强壮僵尸",25,4,30,5,3,5,2,250,3);
					enemyskill[2]=0;
					drop("强壮僵尸");
				}else{
					cout<<"你悄悄走开了。"<<endl;
					getch();
				} 
			}
			break;
		case 8:
			cout<<"你发现了一颗苹果！"<<endl;
			bag[36]++;
			getch();
			break;  
			case 9: 
			cout<<"你遇见了一只末影人！"<<endl;
			cout<<"0，离开  1，注视"<<endl;
			cin>>choose;
			if(choose==1){
				fight("末影人",40,6,30,-10,9999,5,3,300,3);
				drop("末影人"); 
			}else{
				cout<<"你悄悄走开了。"<<endl;
				getch();
			}
			break;
		}
	}
	if(place=="洞穴"){
		int add;
		switch(1+rand()%8){
		case 1:
			cout<<"你什么也没遇见..."<<endl;
			getch();
			break;  
			case 2: 
			cout<<"你遇见了一只僵尸！"<<endl;
			cout<<"0，离开  1，击杀"<<endl;
			cin>>choose;
			if(choose==1){
				fight("僵尸",20,3,25,0,3,5,2,100,1);
				drop("僵尸"); 
			}else{
				choose=rand()%2;
				if(choose==1){
					cout<<"你正欲离开时，僵尸发现了你并向你冲来！"<<endl;
					getch();
					fight("僵尸",20,3,25,0,3,5,2,100,1);
					drop("僵尸"); 
				}else{
					cout<<"你悄悄走开了。"<<endl;
					getch();
				} 
			}
			break;
			case 3: 
			cout<<"你遇见了一只骷髅！"<<endl;
			cout<<"0，离开  1，击杀"<<endl;
			cin>>choose;
			if(choose==1){
				fight("骷髅",20,3,20,0,1,6+rand()%4,8,250,2);
				drop("骷髅");
			}else{
				choose=rand()%2;
				if(choose==1){
					cout<<"你正欲离开时，骷髅发现了你！"<<endl;
					getch();
					fight("骷髅",20,3,20,0,1,6+rand()%4,8,250,2);
					drop("骷髅");
				}else{
					cout<<"你悄悄走开了。"<<endl;
					getch();
				} 
			}
			break;
			case 4://发现铁矿 
			add=2+rand()%4;
			cout<<"你发现了 "<<add<<" 块铁矿石！"<<endl;
			Sleep(1000);
			cout<<"0，离开  1，挖掘"<<endl;
			cin>>choose;
			if(choose==1){
				system("cls");
				if(tool2<2||tool2==3){
					cout<<"当前稿子无法挖掘此矿石！"<<endl;
					Sleep(2000);
					return;
				} 
				destroy(100000*add,tool2speed[tool2]);
				cout<<"挖掘完毕！获得 "<<itemname[20]<<" "<<add<<" 个！"<<endl;
				bag[20]+=add;
				cout<<"当前有 "<<itemname[20]<<" "<<bag[20]<<" 个！"<<endl;
				getch();
			}else return;
			break;
			case 5://发现金矿 
			add=2+rand()%2;
			cout<<"你发现了 "<<add<<" 块金矿石！"<<endl;
			Sleep(1000);
			cout<<"0，离开  1，挖掘"<<endl;
			cin>>choose;
			if(choose==1){
				system("cls");
				if(tool2<4){
					cout<<"当前稿子无法挖掘此矿石！"<<endl;
					Sleep(2000);
					return;
				} 
				destroy(120000*add,tool2speed[tool2]);
				cout<<"挖掘完毕！获得 "<<itemname[31]<<" "<<add<<" 个！"<<endl;
				bag[31]+=add;
				cout<<"当前有 "<<itemname[31]<<" "<<bag[31]<<" 个！"<<endl;
				getch();
			}else return;
			break;
			case 6://发现青金石矿 
			add=3+rand()%4;
			cout<<"你发现了 "<<add<<" 块青金石！"<<endl;
			Sleep(1000);
			cout<<"0，离开  1，挖掘"<<endl;
			cin>>choose;
			if(choose==1){
				system("cls");
				if(tool2<2||tool2==3){
					cout<<"当前稿子无法挖掘此矿石！"<<endl;
					Sleep(2000);
					return;
				} 
				destroy(90000*add,tool2speed[tool2]);
				cout<<"挖掘完毕！获得 "<<itemname[43]<<" "<<add<<" 个！"<<endl;
				bag[43]+=add;
				experience+=add*15;
				cout<<"当前有 "<<itemname[43]<<" "<<bag[43]<<" 个！"<<endl;
				getch();
			}else return;
			break;
			case 7://发现钻石矿 
			add=1+rand()%3;
			cout<<"你发现了 "<<add<<" 块钻石！"<<endl;
			Sleep(1000);
			cout<<"0，离开  1，挖掘"<<endl;
			cin>>choose;
			if(choose==1){
				system("cls");
				if(tool2<4){
					cout<<"当前稿子无法挖掘此矿石！"<<endl;
					Sleep(2000);
					return;
				} 
				destroy(160000*add,tool2speed[tool2]);
				cout<<"挖掘完毕！获得 "<<itemname[44]<<" "<<add<<" 个！"<<endl;
				bag[44]+=add;
				experience+=add*30;
				cout<<"当前有 "<<itemname[44]<<" "<<bag[44]<<" 个！"<<endl;
				getch();
			}else return;
			break;
			case 8: 
			cout<<"你遇见了一只末影人！"<<endl;
			cout<<"0，离开  1，注视"<<endl;
			cin>>choose;
			if(choose==1){
				fight("末影人",40,6,30,-10,9999,5,3,300,3);
				drop("末影人"); 
			}else{
				cout<<"你悄悄走开了。"<<endl;
				getch();
			}
			break;
		}
	}
	if(place=="沙漠"){
		int find=rand()%100;
		if(find==0){
			cout<<"你发现了一个废弃的地狱传送门！"<<endl;
			getch();
			int obsidian=2+rand()%2,gold=2+rand()%3; 
			cout<<"你打开箱子，获得了 "<<obsidian<<" 个黑曜石和 "<<gold<<" 个金锭！"<<endl;
			bag[65]+=obsidian;
			bag[32]+=gold;
			getch();
			return;
		}
		switch(1+rand()%6){
		case 1:
			cout<<"你什么也没遇见..."<<endl;
			getch();
			break;  
			case 2: 
			cout<<"你遇见了一只僵尸！"<<endl;
			cout<<"0，离开  1，击杀"<<endl;
			cin>>choose;
			if(choose==1){
				fight("僵尸",20,3,25,0,3,5,2,100,1);
				drop("僵尸"); 
			}else{
				choose=rand()%2;
				if(choose==1){
					cout<<"你正欲离开时，僵尸发现了你并向你冲来！"<<endl;
					getch();
					fight("僵尸",20,3,25,0,3,5,2,100,1);
					drop("僵尸"); 
				}else{
					cout<<"你悄悄走开了。"<<endl;
					getch();
				} 
			}
			break;
		case 3:
			cout<<"你遇见了流浪商人！"<<endl;
			getch();
			cout<<"0，离开  1，交易"<<endl; 
			cin>>choose;
			if(choose==1) shoper("流浪商人");
			else return;
			break;
			case 4: 
			cout<<"你遇见了一只骷髅！"<<endl;
			cout<<"0，离开  1，击杀"<<endl;
			cin>>choose;
			if(choose==1){
				fight("骷髅",20,3,20,0,1,6+rand()%4,8,250,2);
				drop("骷髅");
			}else{
				choose=rand()%2;
				if(choose==1){
					cout<<"你正欲离开时，骷髅发现了你！"<<endl;
					getch();
					fight("骷髅",20,3,20,0,1,6+rand()%4,8,250,2);
					drop("骷髅");
				}else{
					cout<<"你悄悄走开了。"<<endl;
					getch();
				} 
			}
			break;
			case 5: 
			cout<<"你遇见了一只尸壳！"<<endl;
			cout<<"0，离开  1，击杀"<<endl;
			cin>>choose;
			if(choose==1){
				fight("尸壳",24,4,30,5,3,5,2,150,2);
				drop("尸壳");
			}else{
				choose=rand()%2;
				if(choose==1){
					cout<<"你正欲离开时，尸壳发现了你并向你冲来！"<<endl;
					getch();
					fight("尸壳",24,4,30,5,3,5,2,150,2);
					drop("尸壳");
				}else{
					cout<<"你悄悄走开了。"<<endl;
					getch();
				} 
			}
			break;  
			case 6: 
			cout<<"你遇见了一只浑身是沙的骷髅！"<<endl;
			cout<<"0，离开  1，击杀"<<endl;
			cin>>choose;
			if(choose==1){
				fight("沙骷",20,3,20,0,3,6+rand()%4,8,250,2);
				drop("骷髅");
			}else{
				choose=rand()%2;
				if(choose==1){
					cout<<"你正欲离开时，骷髅发现了你！"<<endl;
					getch();
					fight("沙髅",20,3,20,0,3,6+rand()%4,8,250,2);
					drop("骷髅");
				}else{
					cout<<"你悄悄走开了。"<<endl;
					getch();
				} 
			}
			break;
		}
	}
	if(place=="丛林"){
		int find=rand()%100;
		if(find==0){
			cout<<"你发现了一个废弃的地狱传送门！"<<endl;
			getch();
			int obsidian=2+rand()%2,gold=2+rand()%3; 
			cout<<"你打开箱子，获得了 "<<obsidian<<" 个黑曜石和 "<<gold<<" 个金锭！"<<endl;
			bag[65]+=obsidian;
			bag[32]+=gold;
			getch();
			return;
		}
		find=rand()%100;
		if(find<=5&&jungle_temple==false){
			cout<<"你正冒险时，突然发现了什么..."<<endl;
			getch();
			cout<<"你仔细一看，自己的前方是一座神庙！"<<endl;
			getch();
			cout<<"远古的丛林神庙，四周遍布青苔，沉睡的怪物又会如何..."<<endl;
			Sleep(1000);
			getch();
			cout<<"解锁副本：丛林神庙！"<<endl;
			getch();
			jungle_temple=true;
			return;
		}
		switch(1+rand()%9){
		case 1:
			cout<<"你遇见了一头牛！"<<endl;
			cout<<"0，离开  1，击杀"<<endl;
			cin>>choose;
			if(choose==1){
				fight("牛",20,2,100,-10,3,10,1,50,0);
			}else return;
			break;
		case 2:
			cout<<"你遇见了一只羊！"<<endl;
			cout<<"0，离开  1，击杀"<<endl;
			cin>>choose;
			if(choose==1){
				fight("羊",20,2,100,-10,3,10,1,50,0);
			}else return;
			break;
		case 3:
			cout<<"你什么也没遇见..."<<endl;
			getch();
			break;  
			case 4: 
			cout<<"你遇见了一只僵尸！"<<endl;
			cout<<"0，离开  1，击杀"<<endl;
			cin>>choose;
			if(choose==1){
				fight("僵尸",20,3,25,0,3,5,2,100,1);
				drop("僵尸"); 
			}else{
				choose=rand()%2;
				if(choose==1){
					cout<<"你正欲离开时，僵尸发现了你并向你冲来！"<<endl;
					getch();
					fight("僵尸",20,3,25,0,3,5,2,100,1);
					drop("僵尸"); 
				}else{
					cout<<"你悄悄走开了。"<<endl;
					getch();
				} 
			}
			break;
		case 5:
			cout<<"你遇见了流浪商人！"<<endl;
			getch();
			cout<<"0，离开  1，交易"<<endl; 
			cin>>choose;
			if(choose==1) shoper("流浪商人");
			else return;
			break;
			case 6: 
			cout<<"你遇见了一只骷髅！"<<endl;
			cout<<"0，离开  1，击杀"<<endl;
			cin>>choose;
			if(choose==1){
				fight("骷髅",20,3,20,0,1,6+rand()%4,8,250,3);
				drop("骷髅");
			}else{
				choose=rand()%2;
				if(choose==1){
					cout<<"你正欲离开时，骷髅发现了你！"<<endl;
					getch();
					fight("骷髅",20,3,20,0,1,6+rand()%4,8,250,3);
					drop("骷髅");
				}else{
					cout<<"你悄悄走开了。"<<endl;
					getch();
				} 
			}
			break;
			case 7: 
			cout<<"你遇见了一只强壮的僵尸！"<<endl;
			cout<<"0，离开  1，击杀"<<endl;
			cin>>choose;
			if(choose==1){
				enemyskill[2]=1;
				fight("强壮僵尸",25,4,30,5,3,5,2,250,3);
				enemyskill[2]=0;
				drop("强壮僵尸");
			}else{
				choose=rand()%2;
				if(choose==1){
					cout<<"你正欲离开时，僵尸发现了你并向你冲来！"<<endl;
					getch();
					enemyskill[2]=1;
					fight("强壮僵尸",25,4,30,5,3,5,2,250,3);
					enemyskill[2]=0;
					drop("强壮僵尸");
				}else{
					cout<<"你悄悄走开了。"<<endl;
					getch();
				} 
			}
			break;
		case 8:
			cout<<"你发现了一颗苹果！"<<endl;
			bag[36]++;
			getch();
			break;  
		case 9:
			cout<<"你遇见了一只蜘蛛！"<<endl;
			cout<<"0，离开  1，击杀"<<endl;
			cin>>choose;
			if(choose==1){
				fight("蜘蛛",20,7,25,-10,4,8+rand()%4,2,300,3);
				drop("蜘蛛"); 
			}else return;
			break;
		}
	}
	if(place=="雪地"){
		if(badguy>=3){
			if(badguy>=4){
				if(badguy==5){
					cout<<"“你准备好了吗？”"<<endl;
					cout<<"0，还没有  1，好了"<<endl;
					cin>>choose;
					if(choose==0){
						cout<<"“好吧。那你可以在雪地冒险...”"<<endl;
						getch(); 
					}else{
						system("cls");
						cout<<"“准备好了？”"<<endl;
						getch();
						help=true;
						dungeon("寒冰洞窟");
						help=false; 
					} 
				}else{
					cout<<"准备好了吗？！"<<endl;
					getch();
					cout<<"开始吧！"<<endl;
					getch();
					system("cls");
					cout<<"一名挑战者用鄙视的眼光看向你，向你冲了过来！"<<endl;
					getch();
					fight("挑战者",20,4,0,0,3,5,2,200,3);
					if(!dead){
						cout<<"你被赶下台去，狼狈逃走了"<<endl;
						getch();
						cout<<"你决定重整旗鼓，以后再继续来挑战！"<<endl;
						return;
					}
					cout<<"另一名身穿重甲的挑战者向你走来，对你发起挑战！"<<endl;
					getch();
					fight("重甲挑战者",20,4,0,15,3,5,2,250,4);
					if(!dead){
						cout<<"你被赶下台去，狼狈逃走了"<<endl;
						getch();
						cout<<"你决定重整旗鼓，以后再继续来挑战！"<<endl;
						return;
					}
					cout<<"场上仅剩你与最后一名挑战者。"<<endl;
					getch();
					cout<<"对方冷笑一声，便拔出一把长弓向你射出一箭！"<<endl;
					getch();
					cout<<"你受到了 5 点伤害！"<<endl;
					Sleep(1000);
					health-=5;
					cout<<"你还剩 "<<health<<" 点生命！"<<endl;
					if(health<=0){
						cout<<"你毫无防备，倒在了地上..."<<endl;
						getch();
						cout<<"你愤愤不平，发誓之后定要一雪前耻！"<<endl;
						health=2;
						getch();
						return;
					}
					getch();
					cout<<"你恼羞成怒，向那人冲去！"<<endl;
					getch();
					enemyskill[4]=1;
					fight("长弓挑战者",20,5,0,5,2,8,6,350,6);
					enemyskill[4]=0;
					if(!dead){
						cout<<"你被赶下台去，狼狈逃走了"<<endl;
						getch();
						cout<<"你决定重整旗鼓，以后再继续来挑战！"<<endl;
						return;
					}
					system("cls");
					credit+=5;
					cout<<"那名偷袭的挑战者自知不敌，连忙逃走了。"<<endl;
					getch();
					cout<<"你通过了选拔！你将会获得寻找宝藏的资格！"<<endl;
					getch();
					cout<<"此时，一名男人向你缓缓走来。"<<endl;
					Sleep(1000);
					cout<<"“不愧是恶霸村民推荐过的勇者...能在这么多挑战者中胜利，确实有些本事。”"<<endl;
					Sleep(1000);
					badguy=5;//探险 开始！ 
					say("现在你可以去为这次探险做准备了...我们会在这等着你。\n",20);
					getch();
					cout<<"“对了，这是一些绿宝石，收下吧，好好准备，这次探险很危险...”"<<endl;
					Sleep(500);
					money+=10;
					cout<<"获得了 10 颗绿宝石！"<<endl;
					getch();
					system("cls");
					return; 
				}
			}else{
				cout<<"你来到雪地，看到了一个公告牌和几个村民。"<<endl;
				getch();
				cout<<"“我要选出一个足够勇敢的勇士，前往雪地深处找到宝藏！”"<<endl; 
				getch();
				cout<<"你毫不犹豫报了名..."<<endl; 
				badguy=4;
				getch();
				system("cls");
				Sleep(1000);
				cout<<"你将要面对其他的挑战者，与他们战斗后才能得到资格去寻找宝藏！"<<endl;
				Sleep(500);
				cout<<"现在，你可以去为这次选拔进行准备！"<<endl;
				Sleep(500);
				cout<<"准备完后，只需回到雪地便可参加选拔..."<<endl;
				getch(); 
				return;
			}
		}
		switch(1+rand()%8){
		case 1:
			cout<<"你遇见了一只僵尸！"<<endl;
			cout<<"0，离开  1，击杀"<<endl;
			cin>>choose;
			if(choose==1){
				fight("僵尸",20,3,25,0,3,5,2,100,1);
				drop("僵尸"); 
			}else{
				choose=rand()%2;
				if(choose==1){
					cout<<"你正欲离开时，僵尸发现了你并向你冲来！"<<endl;
					getch();
					fight("僵尸",20,3,25,0,3,5,2,100,1);
					drop("僵尸"); 
				}else{
					cout<<"你悄悄走开了。"<<endl;
					getch();
				} 
			}   
			break;  
			case 2: 
			cout<<"你遇见了一只流浪者！"<<endl;
			cout<<"0，离开  1，击杀"<<endl;
			cin>>choose;
			if(choose==1){
				enemyskill[41]=1; 
				fight("流浪者",20,3,20,0,1,6+rand()%4,8,300,3);
				enemyskill[41]=0;
				drop("流浪者");
			}else{
				choose=rand()%2;
				if(choose==1){
					cout<<"你正欲离开时，流浪者已经对你瞄准了！"<<endl;
					getch();
					enemyskill[41]=1;
					fight("流浪者",20,3,20,0,1,6+rand()%4,8,300,3);
					enemyskill[41]=0;
					drop("流浪者");
				}else{
					cout<<"你悄悄走开了。"<<endl;
					getch();
				} 
			}
			break;
		case 3:
			cout<<"你遇见了一只巨型雪怪！"<<endl;
			cout<<"0，离开  1，击杀"<<endl;
			cin>>choose;
			if(choose==1){
				enemyskill[2]=2; 
				fight("雪怪",36,7,25,20,3,9,3,500,5);
				enemyskill[2]=0;
				drop("雪怪"); 
			}else return; 
			break;
			case 4: 
			cout<<"你遇见了一只骷髅！"<<endl;
			cout<<"0，离开  1，击杀"<<endl;
			cin>>choose;
			if(choose==1){
				fight("骷髅",20,3,20,0,1,6+rand()%4,8,250,2);
				drop("骷髅");
			}else{
				choose=rand()%2;
				if(choose==1){
					cout<<"你正欲离开时，骷髅发现了你！"<<endl;
					getch();
					fight("骷髅",20,3,20,0,1,6+rand()%4,8,250,2);
					drop("骷髅");
				}else{
					cout<<"你悄悄走开了。"<<endl;
					getch();
				} 
			}
			break;
		case 5:
			cout<<"你遇见了一只浑身是雪的僵尸！"<<endl;
			cout<<"0，离开  1，击杀"<<endl;
			cin>>choose;
			if(choose==1){
				fight("雪人",24,4,25,8,3,5,2,250,3);
				drop("尸壳"); 
			}else{
				choose=rand()%2;
				if(choose==1){
					cout<<"你正欲离开时，僵尸发现了你并向你冲来！"<<endl;
					getch();
					fight("雪人",24,4,25,8,3,5,2,250,3);
					drop("尸壳"); 
				}else{
					cout<<"你悄悄走开了。"<<endl;
					getch();
				} 
			}   
			break;
		case 6:
			cout<<"你遇见了流浪商人！"<<endl;
			getch();
			cout<<"0，离开  1，交易"<<endl; 
			cin>>choose;
			if(choose==1) shoper("流浪商人");
			else return;
			break;  
		case 7:
			cout<<"你什么都没遇见..."<<endl;
			getch();
			break;
			case 8: 
			cout<<"你遇见了一只末影人！"<<endl;
			cout<<"0，离开  1，注视"<<endl;
			cin>>choose;
			if(choose==1){
				fight("末影人",40,6,30,-10,9999,5,3,300,3);
				drop("末影人"); 
			}else{
				cout<<"你悄悄走开了。"<<endl;
				getch();
			}
			break;  
		}
	}
	if(place=="地狱"){
		switch(1+rand()%6){
		case 1:
			cout<<"你遇见了一只僵尸猪人！"<<endl;
			cout<<"0，离开  1，击杀"<<endl;
			cin>>choose;
			if(choose==1){
				fight("僵尸猪人",20,5,0,0,3,6+rand()%3,2,200,2);
				drop("僵尸猪人");
				system("cls");
				if(dead){
					cout<<"你正想离开时，引来了一群僵尸猪人！"<<endl;
					getch(); 
					fight("僵尸猪人",20,5,0,0,3,6+rand()%3,2,200,2);
					drop("僵尸猪人");
					if(dead){
						cout<<"你杀死了两只僵尸猪人后，连忙逃走了..."<<endl;
						getch();
					}
				}
			}else{
				cout<<"你悄悄走开了。"<<endl;
				getch(); 
			}   
			break;
			case 2: 
			cout<<"你遇见了一只末影人！"<<endl;
			cout<<"0，离开  1，注视"<<endl;
			cin>>choose;
			if(choose==1){
				fight("末影人",40,6,30,-10,9999,5,3,300,3);
				drop("末影人"); 
			}else{
				cout<<"你悄悄走开了。"<<endl;
				getch();
			}
			break;  
		case 3:
			cout<<"你遇见了一头疣猪兽！"<<endl;
			cout<<"0，离开  1，击杀"<<endl;
			cin>>choose;
			if(choose==1){
				fight("疣猪兽",40,8,50,-5,3,10,4,250,3);
			}else{
				cout<<"你趁着它扭头的瞬间，悄悄走开了。"<<endl; 
				getch();
			}
			break;
		case 4:
			cout<<"你什么都没遇见..."<<endl;
			getch();
			break; 
			case 5: 
			cout<<"你遇见了一只骷髅！"<<endl;
			cout<<"0，离开  1，击杀"<<endl;
			cin>>choose;
			if(choose==1){
				fight("骷髅",20,3,20,0,1,6+rand()%4,8,250,2);
				drop("骷髅");
			}else{
				choose=rand()%2;
				if(choose==1){
					cout<<"你正欲离开时，骷髅发现了你！"<<endl;
					getch();
					fight("骷髅",20,3,20,0,1,6+rand()%4,8,250,2);
					drop("骷髅");
				}else{
					cout<<"你悄悄走开了。"<<endl;
					getch();
				} 
			}
			break;
			case 6: 
			cout<<"你遇见了一只猪灵！"<<endl;
			cout<<"0，离开  1，靠近"<<endl;
			cin>>choose;
			if(choose==1){
				if(armor1!=3&&armor2!=3&&armor3!=3&&armor4!=3){
					cout<<"猪灵愤怒的看向你，手持金剑向你攻击！"<<endl;
					getch();
					fight("猪灵",16,8,20,5,3,4+rand()%4,2,200,2);
					drop("猪灵");
				}else{
					cout<<"你要？"<<endl;
					cout<<"0，交易  1，攻击"<<endl;
					cin>>choose;
					if(choose==1){
						fight("猪灵",16,8,20,5,3,4+rand()%4,2,200,2);
						drop("猪灵");
					}else{
						while(1){
							system("cls");
							cout<<"当前你有 "<<bag[32]<<" 个金锭。"<<endl;
							cout<<"0，离开  1，交易"<<endl;
							cin>>choose;
							if(choose==0) break;
							else{
								if(bag[32]<1){
									cout<<"猪灵呆呆的看着你，突然好像明白了什么，愤怒的走开了。"<<endl;
									getch();
									break; 
								}else{
									cout<<"你把一块金锭交给猪灵。"<<endl;
									bag[32]--;
									getch();
									cout<<"猪灵捡起金锭，仔细的端详着..."<<endl;
									Sleep(5000+rand()%3000);
									getch();
									int i,add;
									switch(1+rand()%11){
									case 1:
										i=121,add=1+rand()%3;
										break;
									case 2:
									case 3:
										i=14,add=4+rand()%5;
										break;
									case 4:
									case 5:
										i=126,add=3+rand()%3;
										break;
									case 6:
										i=1001+rand()%2,add=1;
										break;
									case 7:
										i=4,add=5+rand()%3;
										break;  
									case 8:
										i=117+rand()%4,add=1;
										break;
									case 9:
										i=125,add=6+rand()%6;
										break;
									case 10:
										i=132,add=1+rand()%2;
										break;
									case 11:
										i=65,add=1+rand()%3;                                                
										break;   
									} 
									cout<<"获得 "<<item[i].itemname<<" "<<add<<" 个！"<<endl;
									bag[i]+=add;
									getch();
								}
							}
						}
					}
				}
			}else{
				choose=rand()%2;
				if(choose==1){
					cout<<"你正欲离开时，猪灵发现了你！"<<endl;
					getch();
					if(armor1!=3&&armor2!=3&&armor3!=3&&armor4!=3){
						cout<<"猪灵愤怒的看向你，手持金剑向你攻击！"<<endl;
						getch();
						fight("猪灵",16,8,20,5,3,4+rand()%4,2,200,2);
						drop("猪灵");
					}else{
						cout<<"猪灵从你面前经过，没有理会你。"<<endl;
						getch();
					}   
				}else{
					cout<<"你悄悄走开了。"<<endl;
					getch();
				} 
			}
			break;
		}
	}
	if(place=="末地")
		if(place=="边境之地"){
			switch(1+rand()%2){
			case 1:
				cout<<"你遇见了一只僵尸！"<<endl;
				cout<<"0，离开  1，击杀"<<endl;
				cin>>choose;
				if(choose==1){
					fight("_僵尸",50,12,50,20,4,8+rand()%4,2,1000,10);
					drop("僵尸"); 
				}else{
					choose=rand()%2;
					if(choose==1){
						cout<<"你正欲离开时，僵尸冷冷的扫视了你一眼...并向你冲来！"<<endl;
						getch();
						fight("_僵尸",50,12,50,20,4,8+rand()%4,2,1000,10);
						drop("僵尸"); 
					}else{
						cout<<"你悄悄走开了。"<<endl;
						getch();
					} 
				}
				break;
				case 2: 
				cout<<"你遇见了一只骷髅！"<<endl;
				cout<<"0，离开  1，击杀"<<endl;
				cin>>choose;
				if(choose==1){
					fight("骷髅_",40,10,40,15,3,8+rand()%6,10,1500,12);
					drop("骷髅");
				}else{
					choose=rand()%2;
					if(choose==1){
						cout<<"你正欲离开时，一支箭射在了你的身前..."<<endl;
						getch();
						fight("骷髅_",40,10,40,15,3,8+rand()%6,10,1500,12);
						drop("骷髅");
					}else{
						cout<<"你悄悄走开了。"<<endl;
						getch();
					} 
				}
				break;
			}
		} 
	system("cls");
	return;
}

inline void go(){//前进 更改地点 
	system("cls");
	SetConsoleTitle("--前进--");
	cout<<"你要去哪里？"<<endl;
	cout<<"0，返回  1，村庄  2，平原  3，森林  4，洞穴  5，沙漠  6，丛林  7，雪地  8，地狱  9，末地";
	cout<<endl;
	if(farland) cout<<"11，边境之地  ";
	if(jungle_temple) cout<<"12，丛林神庙  ";
	cout<<endl;
	cin>>choose;
	switch(choose){
	case 0:
		return; 
		break; 
	case 1:
		if(place=="村庄"){
			cout<<"你已经在村庄了！"<<endl;
			Sleep(1000);
			go();
			return;         
		}else{
			cout<<"前进中..."<<endl;
			Sleep(3000);
			system("cls");
			place="村庄";
			cout<<"已到达 "<<place<<"!"<<endl;
			Sleep(1000); 
			return; 
		}
		break;
	case 2:
		if(place=="平原"){
			cout<<"你已经在平原了！"<<endl;
			Sleep(1000);
			go();
			return;         
		}else{
			cout<<"前进中..."<<endl;
			Sleep(3000);
			system("cls");
			place="平原";
			cout<<"已到达 "<<place<<"!"<<endl;
			Sleep(1000); 
			return; 
		}
		break;
	case 3:
		if(place=="森林"){
			cout<<"你已经在森林了！"<<endl;
			Sleep(1000);
			go();
			return;         
		}else{
			cout<<"前进中..."<<endl;
			Sleep(3000);
			system("cls");
			place="森林";
			cout<<"已到达 "<<place<<"!"<<endl;
			Sleep(1000); 
			return; 
		}
		break;
	case 4:
		if(place=="洞穴"){
			cout<<"你已经在洞穴了！"<<endl;
			Sleep(1000);
			go();
			return;         
		}else{
			cout<<"前进中..."<<endl;
			Sleep(3000);
			system("cls");
			place="洞穴";
			cout<<"已到达 "<<place<<"!"<<endl;
			Sleep(1000); 
			return; 
		}
	case 5:
		if(place=="沙漠"){
			cout<<"你已经在沙漠了！"<<endl;
			Sleep(1000);
			go();
			return;         
		}else{
			cout<<"前进中..."<<endl;
			Sleep(3000);
			system("cls");
			place="沙漠";
			cout<<"已到达 "<<place<<"!"<<endl;
			Sleep(1000); 
			return; 
		}
		break;
	case 6:
		if(place=="丛林"){
			cout<<"你已经在丛林了！"<<endl;
			Sleep(1000);
			go();
			return;         
		}else{
			cout<<"前进中..."<<endl;
			Sleep(3000);
			system("cls");
			place="丛林";
			cout<<"已到达 "<<place<<"!"<<endl;
			Sleep(1000); 
			return; 
		}
		break;
	case 7:
		if(place=="雪地"){
			cout<<"你已经在雪地了！"<<endl;
			Sleep(1000);
			go();
			return;         
		}else{
			cout<<"前进中..."<<endl;
			Sleep(3000);
			system("cls");
			place="雪地";
			cout<<"已到达 "<<place<<"!"<<endl;
			Sleep(1000); 
			return; 
		}
		break;
	case 8:
		if(place=="地狱"){
			cout<<"你已经在地狱了！"<<endl;
			Sleep(1000);
			go();
			return;         
		}else{
			if(nether){
				cout<<"前进中..."<<endl;
				Sleep(3000);
				system("cls");
				place="地狱";
				cout<<"已到达 "<<place<<"!"<<endl;
				Sleep(1000); 
				return; 
			}else{
				cout<<"无法前进，你没有建造/发现地狱传送门"<<endl;
				Sleep(1000);
				go(); 
			}
		}
		break;
	case 9:
		if(place=="末地"){
			cout<<"你已经在末地了！"<<endl;
			Sleep(1000);
			go();
			return;         
		}else{
			if(ender){
				cout<<"前进中..."<<endl;
				Sleep(3000);
				system("cls");
				place="末地";
				cout<<"已到达 "<<place<<"!"<<endl;
				Sleep(1000); 
				return; 
			}else{
				cout<<"无法前进，你没有发现末地传送门"<<endl;
				Sleep(1000);
				go(); 
			}
		}
		break;
	case 11:
		if(place=="边境之地"){
			cout<<"你已经在边境之地了！"<<endl;
			Sleep(1000);
			go();
			return;         
		}else{
			if(farland){
				cout<<"前进中..."<<endl;
				Sleep(3000);
				system("cls");
				place="边境之地";
				cout<<"已到达 "<<place<<"!"<<endl;
				Sleep(1000); 
				return; 
			}
		}
		break;
	case 12:
		if(jungle_temple){
			dungeon("丛林神庙");
			return; 
		}
		break;
	} 
}

inline void chop(string place){//砍树 
	cout<<"发现树木！"<<endl;
	Sleep(1000);
	cout<<"开始砍树..."<<endl;
	Sleep(1000);
	system("cls");
	destroy(360000,tool1speed[tool1]);
	if(place=="平原"||place=="森林"){
		int add=5+rand()%8;
		cout<<"获得橡木"<<add<<"个！"<<endl; 
		bag[1]+=add;
		cout<<"当前拥有橡木"<<bag[1]<<"个"<<endl;  
		Sleep(2000);
	}
	if(place=="丛林"){
		int add=7+rand()%3;
		cout<<"获得丛林木"<<add<<"个！"<<endl; 
		bag[2]+=add;
		cout<<"当前拥有丛林木"<<bag[2]<<"个"<<endl; 
		Sleep(2000);
	}
	if(place=="雪地"){
		int add=8+rand()%6;
		cout<<"获得针叶木"<<add<<"个！"<<endl; 
		bag[3]+=add;
		cout<<"当前拥有针叶木"<<bag[3]<<"个"<<endl; 
		Sleep(2000);
	}
	if(place=="地狱"){
		int add=6+rand()%6; 
		cout<<"获得绯红木"<<add<<"个！"<<endl; 
		bag[4]+=add;
		cout<<"当前拥有绯红木"<<bag[4]<<"个"<<endl; 
		Sleep(3000);
	}
	int apple=1+rand()%3,appleadd=1+rand()%2;
	if(apple==3&&place!="地狱"){
		cout<<"你在树上发现了 "<<appleadd<<" 个苹果！"<<endl;
		bag[36]+=appleadd;
		Sleep(2000);
	}       
	return;
} 

inline void tree(string place){//砍树 
	if(place=="村庄"){
		system("cls");
		cout<<"似乎这里没有树...难道你想拆了村民的房子？"<<endl<<endl;
		cout<<"系统提示：请去别的地方砍树！"<<endl;
		Sleep(1500);
		return; 
	}
	if(place=="洞穴"){
		system("cls");
		cout<<"洞穴里只有坚硬的石头，没有树..."<<endl<<endl;
		cout<<"系统提示：请去别的地方砍树！"<<endl;
		Sleep(1500);
		return; 
	}
	if(place=="沙漠"){
		system("cls");
		cout<<"似乎这里没有树，有的只是长满了尖刺的仙人掌..."<<endl<<endl;
		cout<<"系统提示：请去别的地方砍树！"<<endl;
		Sleep(1500);
		return; 
	}
	if(place=="末地"){
		system("cls");
		cout<<"紫菘果可不是木头！"<<endl<<endl;
		cout<<"系统提示：请去别的地方砍树！"<<endl;
		Sleep(1500);
		return; 
	}
	system("cls");
	if(tool1==0){
		cout<<"看起来你没有斧子，但凭坚硬的双手，也许可以拿下这些木头..."<<endl<<endl; 
		cout<<"如果你有一把斧子，会大大加快砍树的速度。"<<endl;
		Sleep(1000);
		cout<<endl;
	}
	cout<<"当前你装备：";
	cout<<tool1name[tool1]<<endl<<endl; 
	cout<<"提示：你所处的位置决定了你发现树木的速度。"<<endl;
	cout<<"      同时，你的斧头会决定你砍伐树木的速度。"<<endl<<endl;
	Sleep(2000);
	cout<<"0，返回  1，砍树"<<endl;
	cin>>choose;
	system("cls");
	if(choose==1){
		if(place=="平原"){
			cout<<"大约需要20秒..."<<endl; 
			cout<<"寻找树木中..."<<endl; 
			Sleep(15000+rand()%8000); 
			chop("平原");
		}
		if(place=="森林"){
			cout<<"大约需要5秒..."<<endl; 
			cout<<"寻找树木中..."<<endl; 
			Sleep(2000+rand()%5000); 
			chop("森林");
		}
		if(place=="丛林"){
			cout<<"大约需要10秒..."<<endl; 
			cout<<"寻找树木中..."<<endl; 
			Sleep(6000+rand()%8000); 
			chop("丛林");
		}
		if(place=="雪地"){
			cout<<"大约需要30秒..."<<endl; 
			cout<<"寻找树木中..."<<endl; 
			Sleep(25000+rand()%10000); 
			chop("雪地");
		}
		if(place=="地狱"){
			cout<<"大约需要10秒..."<<endl; 
			cout<<"寻找树木中..."<<endl; 
			Sleep(8000+rand()%6000); 
			chop("地狱");
		}
	}
	else return;
}

inline void dig(string place){//挖矿 
	while(1){
		if(place!="洞穴"&&place!="地狱"){
			cout<<"此处无法挖矿！请去其他地方挖矿！"<<endl;
			Sleep(1500);
			return;
		}
		if(tool2==0){
			cout<<"空手无法挖矿！请装备稿子后再来挖矿！"<<endl;
			Sleep(2000);                
			return; 
		}
		system("cls");
		cout<<"现在你在："<<place<<endl;
		cout<<"你现在装备："<<tool2name[tool2]<<endl<<endl;
		cout<<"提示：一些矿石只有特定或足够好的稿子才能挖掘。"<<endl;
		cout<<"      你的稿子决定了你挖掘矿石时的速度。"<<endl<<endl;    
		if(place=="洞穴"){    
			cout<<"0，返回  1，挖矿"<<endl;
			cin>>choose;
			if(choose==1){
				cout<<"0，挖圆石  1，挖矿物"<<endl;
				cin>>choose;
				if(choose==0){//挖石头 
					cout<<"你要挖多少块圆石？"<<endl;
					cin>>choose;
					if(choose>64){
						cout<<"数量太多，无法执行操作！"<<endl;
						getch();
						return;
					}
					cout<<"开始挖掘..."<<endl;
					Sleep(2000); 
					system("cls");
					destroy(60000*choose,tool2speed[tool2]);
					cout<<"获得圆石 "<<choose<<" 个!"<<endl; 
					bag[14]+=choose;
					cout<<"当前拥有圆石 "<<bag[14]<<" 个"<<endl;
					Sleep(2000);    
					return;
				}else{//挖矿石 
					system("cls");
					cout<<"探索矿洞中..."<<endl;
					int figh=rand()%4;
					if(figh==0){
						Sleep(3000+rand()%1000);
						figh=1+rand()%2;
						if(figh==1){
							cout<<"你遇到了僵尸！"<<endl;
							getch();
							fight("僵尸",20,3,40,0,3,5+rand()%5,2,90+rand()%60,1);
							drop("僵尸");
							return;
						}else{
							cout<<"你遇到了骷髅！"<<endl;
							getch();
							fight("骷髅",20,3,30,0,1,8+rand()%4,10,150+rand()%100,2);
							drop("骷髅");
							return; 
						}
					}   
					Sleep(8000+rand()%12000);
					int add;
					switch(1+rand()%6){
						case 1://发现煤炭 
						add=8+1+rand()%8;
						cout<<"你发现了 "<<add<<" 块煤炭！"<<endl;
						Sleep(1000);
						cout<<"0，离开  1，挖掘"<<endl;
						cin>>choose;
						if(choose==1){
							system("cls");
							destroy(80000*add,tool2speed[tool2]);
							cout<<"挖掘完毕！获得 "<<itemname[19]<<" "<<add<<" 个！"<<endl;
							bag[19]+=add;
							experience+=add*5;
							cout<<"当前有 "<<itemname[19]<<" "<<bag[19]<<" 个！"<<endl;
							Sleep(2000);
							continue; 
						}else continue;
						break;
						case 2://发现铁矿 
						add=2+1+rand()%8;
						cout<<"你发现了 "<<add<<" 块铁矿石！"<<endl;
						Sleep(1000);
						cout<<"0，离开  1，挖掘"<<endl;
						cin>>choose;
						if(choose==1){
							system("cls");
							if(tool2<2||tool2==3){
								cout<<"当前稿子无法挖掘此矿石！"<<endl;
								Sleep(2000);
								continue;
							} 
							destroy(100000*add,tool2speed[tool2]);
							cout<<"挖掘完毕！获得 "<<itemname[20]<<" "<<add<<" 个！"<<endl;
							bag[20]+=add;
							cout<<"当前有 "<<itemname[20]<<" "<<bag[20]<<" 个！"<<endl;
							Sleep(2000);
							continue;
						}else continue;;
						break;
						case 3://发现金矿 
						add=4+1+rand()%3;
						cout<<"你发现了 "<<add<<" 块金矿石！"<<endl;
						Sleep(1000);
						cout<<"0，离开  1，挖掘"<<endl;
						cin>>choose;
						if(choose==1){
							system("cls");
							if(tool2<4){
								cout<<"当前稿子无法挖掘此矿石！"<<endl;
								Sleep(2000);
								continue;
							}
							destroy(120000*add,tool2speed[tool2]);
							cout<<"挖掘完毕！获得 "<<itemname[31]<<" "<<add<<" 个！"<<endl;
							bag[31]+=add;
							cout<<"当前有 "<<itemname[31]<<" "<<bag[31]<<" 个！"<<endl;
							Sleep(2000);
							continue;
						}else continue;
						break;
						case 4://发现青金石矿 
						add=6+1+rand()%6;
						cout<<"你发现了 "<<add<<" 块青金石！"<<endl;
						Sleep(1000);
						cout<<"0，离开  1，挖掘"<<endl;
						cin>>choose;
						if(choose==1){
							system("cls");
							if(tool2<2||tool2==3){
								cout<<"当前稿子无法挖掘此矿石！"<<endl;
								Sleep(2000);
								continue;
							}
							destroy(90000*add,tool2speed[tool2]);
							cout<<"挖掘完毕！获得 "<<itemname[43]<<" "<<add<<" 个！"<<endl;
							bag[43]+=add;
							experience+=add*15;
							cout<<"当前有 "<<itemname[43]<<" "<<bag[43]<<" 个！"<<endl;
							Sleep(2000);
							continue; 
						}else continue;
						break;
						case 5://发现钻石 
						add=2+1+rand()%4;
						cout<<"你发现了 "<<add<<" 块钻石！"<<endl;
						Sleep(1000);
						cout<<"0，离开  1，挖掘"<<endl;
						cin>>choose;
						if(choose==1){
							system("cls");
							if(tool2<4){
								cout<<"当前稿子无法挖掘此矿石！"<<endl;
								Sleep(2000);
								continue;
							}
							destroy(160000*add,tool2speed[tool2]);
							cout<<"挖掘完毕！获得 "<<itemname[44]<<" "<<add<<" 个！"<<endl;
							bag[44]+=add;
							experience+=add*30;
							cout<<"当前有 "<<itemname[44]<<" "<<bag[44]<<" 个！"<<endl;
							Sleep(2000);
							continue;
						}else continue;
						break;
						case 6://发现黑曜石 
						add=2+1+rand()%3;
						cout<<"你发现了 "<<add<<" 块黑曜石！"<<endl;
						Sleep(1000);
						cout<<"0，离开  1，挖掘"<<endl;
						cin>>choose;
						if(choose==1){
							system("cls");
							if(tool2<5){
								cout<<"当前稿子无法挖掘黑曜石！"<<endl;
								Sleep(2000);
								continue;
							}
							destroy(600000*add,tool2speed[tool2]);
							cout<<"挖掘完毕！获得 "<<itemname[65]<<" "<<add<<" 个！"<<endl;
							bag[65]+=add;
							cout<<"当前有 "<<itemname[65]<<" "<<bag[65]<<" 个！"<<endl;
							getch();
							continue;
						}else continue;
						break;  
					}
				}
			}else return;
		}
		if(place=="地狱"){
			cout<<"0，返回  1，挖矿"<<endl;
			cin>>choose;
			if(choose==1){
				cout<<"1，挖矿"<<endl;
				cin>>choose;
				if(choose==1){
					system("cls");
					cout<<"探索地狱中..."<<endl;
					cout<<"这个过程可能会有些漫长，耐心等待..."<<endl;
					choose=1+rand()%5;
					//if(choose==5) Sleep(40000+rand()%40000);
					//else Sleep(10000+rand()%10000);
					system("cls");
					int add;
					if(choose==5) add=1+rand()%2,cout<<"你发现了 "<<add<<" 块远古残骸！"<<endl;
					if(choose==1||choose==2) add=4+rand()%4,cout<<"你发现了 "<<add<<" 块下界金矿！"<<endl;
					if(choose==3||choose==4) add=3+rand()%8,cout<<"你发现了 "<<add<<" 块下界石英！"<<endl;
					Sleep(1000);
					cout<<"0，离开  1，挖掘"<<endl;
					cin>>choose;
					if(choose==0) continue;
					if(choose==5){
						if(tool2<5){
							cout<<"当前稿子无法挖掘远古残骸！"<<endl;
							Sleep(2000);
							continue;
						}else{          
							destroy(500000*add,tool2speed[tool2]);
							cout<<"挖掘完毕！获得 "<<itemname[55]<<" "<<add<<" 个！"<<endl;
							bag[55]+=add;
							cout<<"当前有 "<<itemname[55]<<" "<<bag[55]<<" 个！"<<endl;
						}
					}
					if(choose==1||choose==2){//金矿           
						destroy(90000*add,tool2speed[tool2]);
						add=add*(3+rand()%3)+rand()%add;
						cout<<"挖掘完毕！获得 "<<itemname[125]<<" "<<add<<" 个！"<<endl;
						bag[125]+=add;
						cout<<"当前有 "<<itemname[125]<<" "<<bag[125]<<" 个！"<<endl;
					}
					if(choose==3||choose==4){
						destroy(100000*add,tool2speed[tool2]);//石英 
						cout<<"挖掘完毕！获得 "<<itemname[126]<<" "<<add<<" 个！"<<endl;
						bag[126]+=add;
						experience+=add*20;
						cout<<"当前有 "<<itemname[126]<<" "<<bag[126]<<" 个！"<<endl;
					}
					getch();
					continue;
				}else continue; 
			}else return; 
		}   
	}
}

inline void jvqing(){//剧情输出 
	system("cls");
	cout<<"加载剧情中..."<<endl;
	Sleep(2000);
	cout<<"加载完毕！"<<endl;
	Sleep(1000);
	system("cls"); 
	Sleep(500);
	say("很久之前,虚空中有两位神，分别是Notch和Herobrine。\n\n",50);
	Sleep(1000);
	say("他们本是一对兄弟，两人平安无事，Notch与Herobrine共同联手，创造了一个方块世界。\n\n",50);
	Sleep(1000);
	say("Notch创造出了人类，动物，使世界充满了生机。\n\n",50);
	Sleep(1000);
	say("但他的弟弟Herobrine认为这太过无聊，又创造出了亡灵大军。\n\n",50);
	Sleep(1000);
	say("两人意见很快便不合，最终Notch与Herobrine背道而行，势不两立。\n\n",50);
	Sleep(1000);
	say("Herobrine率领着众多亡灵，血洗了方块大陆上的一切生灵......\n\n",50);
	Sleep(1000);
	say("Notch见状，耗尽了近乎所有的神力，将Herobrine封印起来到了地狱。\n\n",50);
	Sleep(1000);
	say("但尽管如此，Herobrine创造出的亡灵早已遍布世界，无法根除。\n\n",50);
	Sleep(1000);
	say("而Herobrine也积蓄着力量，集结着黑暗的势力准备反扑。\n\n",50);
	Sleep(1000);
	getch();
	system("cls");
	say("......",350);
	say("数百年过去了，和平安宁的景象即将被打破......\n\n",50);
	Sleep(1500);
	say("能够拯救这个世界的，",40);
	say("就只有--",70);
	Sleep(300); 
	say("你，才能拯救世界，打败Herobrine，保护世界的和平！\n\n",45);
	Sleep(2500);
	say("属于你的传奇，现在开始......\n\n",70);
	getch();
	return; 
}

inline void checkbag(){//检查背包 
	SetConsoleTitle("--背包--");
	cout<<"显示顺序为 编号-物品名-数量"<<endl<<endl;
	cout<<"若未显示则为无物品"<<endl<<endl;
	cout<<"输入物品编号可查看物品信息/交互"<<endl<<endl;
	for(int i=1;i<=1000;i++){
		if(bag[i]!=0){
			cout<<"编号 "<<i<<"  "<<itemname[i]<<" 数量："<<bag[i]<<" 个";
			if(item[i].type!=0) cout<<" <可装备>";
			cout<<endl;
		} 
		else continue;
	}
	for(int i=1001;i<1020;i++){
		if(bag[i]!=0){
			cout<<"编号 "<<i<<"  "<<itemname[i]<<" 数量："<<bag[i]<<" 个"<<endl;
		} 
		else continue;
	}
	for(int i=1;i<10;i++){
		if(arrow[i]!=0){
			cout<<"箭矢 "<<i<<"  "<<arrowname[i]<<" 数量："<<arrow[i]<<" 个"<<endl;
		} 
		else continue;
	}
	cout<<endl<<"输入 0 返回"<<endl;
	cin>>choose;
	if(choose==0) return;
	if(bag[choose]<=0){
		cout<<"请勿乱输！"<<endl;
		getch(); 
		return; 
	}
	system("cls");
	cout<<"物品："<<item[choose].itemname<<endl;
	cout<<"出售："<<item[choose].sell_num<<"个 价值 "<<item[choose].sell_price<<" 绿宝石"<<endl;
	switch(item[choose].type){
	case 0:
		cout<<"类型：材料/物品"<<endl;
		break;
	case 1:
		cout<<"类型：主手武器"<<endl;
		break;
	case 2:
		cout<<"类型：副手武器"<<endl;
		break;
	case 3:
		cout<<"类型：斧"<<endl;
		break;      
	case 4:
		cout<<"类型：稿"<<endl;
		break;
	case 5:
		cout<<"类型：头盔"<<endl;
		break;
	case 6:
		cout<<"类型：胸甲"<<endl;
		break;
	case 7:
		cout<<"类型：护腿"<<endl;
		break;
	case 8:
		cout<<"类型：靴子"<<endl;
		break;
	} 
	//cout<<item[choose].level;
	switch(choose){
	case 0:
		return;
		break;
	case 1:
		cout<<"基础的木头，可在平原，森林砍树获得。可以制作橡木木板。"<<endl;
		break;
	case 2:
		cout<<"基础的木头，可在丛林砍树获得。可以制作丛林木板。"<<endl;
		break;
	case 3:
		cout<<"基础的木头，可在雪地砍树获得。可以制作针叶木木板。"<<endl;
		break;
	case 4:
		cout<<"来自地狱的木头，能防火，可在地狱砍树获得。可以制作绯红木板。"<<endl;
		break;
	case 5:
		cout<<"基础的木板，可以制作各种木制品。"<<endl;
		break;
	case 6:
		cout<<"基础的木板，可以制作各种木制品。"<<endl;
		break;
	case 7:
		cout<<"基础的木板，可以制作各种木制品。"<<endl;
		break;
	case 8:
		cout<<"来自地狱的木板，能防火，可以制作各种木制品。"<<endl;
		break;
	case 9:
		cout<<"一个制作站，在<建造>中将其放置便可合成更多新物品。"<<endl;
		cout<<"“这是，工作台？”。"<<endl;
		break;
	case 10:
		cout<<"木制的棍子，是组装武器和工具必备的材料。"<<endl;
		break;
	case 11:
		cout<<"木制的剑，简单好用。<可装备>"<<endl;
		break;
	case 12:
		cout<<"木制的斧，可略微提升砍树的速度。<可装备>"<<endl;
		break;
	case 13:
		cout<<"木制的稿，可以挖掘石头和煤炭。<可装备>"<<endl;
		cout<<"“挖矿时间到”！"<<endl; 
		break;
	case 14:
		cout<<"地下四处可采集的石头，是制作石制工具的必要材料。"<<endl;
		break;
	case 15:
		cout<<"石质的剑，朴实无华，简单耐用。<可装备>"<<endl;
		break;
	case 16:
		cout<<"石质的斧，可小幅提升砍树的速度。<可装备>"<<endl;
		break;
	case 17:
		cout<<"石质的稿，比木稿的挖掘速度更快，还可挖掘铁矿。<可装备>"<<endl;
		break;
	case 18:
		cout<<"“热门话题”！在<建造>中将其放置便可熔炼矿物。"<<endl;
		break;
	case 19:
		cout<<"基础的燃料，可用于熔炼矿物。"<<endl;
		break;
	case 20:
		cout<<"中级的矿石，将其用熔炉熔炼可获得铁锭。"<<endl;
		break;
	case 21:
		cout<<"中级的矿锭，可以制作精良的铁质装备。"<<endl;
		cout<<"“来硬的”！"<<endl;
		break;
	case 22:
		cout<<"铁质的剑，锋利耐用，是优秀的武器。<可装备>"<<endl; 
		break;
	case 23:
		cout<<"铁质的斧，可较快提升砍树速度。<可装备>"<<endl;
		break;
	case 24:
		cout<<"铁质的稿，可以挖掘钻石，金矿石等中级矿物，且可较快提升挖掘速度。<可装备>"<<endl;
		break;
	case 25:
		cout<<"铁质的头盔，可抵挡受到的伤害。<可装备>"<<endl;
		cout<<"“整装上阵”！"<<endl; 
		break;
	case 26:
		cout<<"铁质的胸甲，可抵挡受到的伤害。<可装备>"<<endl;
		break;
	case 27:
		cout<<"铁质的护腿，可抵挡受到的伤害。<可装备>"<<endl;
		break;
	case 28:
		cout<<"铁质的靴子，可抵挡受到的伤害。<可装备>"<<endl;
		break;
	case 29:
		cout<<"防御的盾牌，可以大幅抵挡自己受到的伤害。<可装备>"<<endl;
		cout<<"“抱歉，今天不行”"<<endl;
		break;
	case 30:
		cout<<"优秀的远程武器，使用箭作为弹药。<可装备>"<<endl;
		break;
	case 31:
		cout<<"中高级的矿石，将其用熔炉熔炼可获得金锭。"<<endl;
		break;
	case 32:
		cout<<"中高级的矿锭，可以制作速度极快的金质装备。"<<endl;
		break;
	case 33:
		cout<<"金质的剑，但效果不尽人意。<可装备>"<<endl;
		break;
	case 34:
		cout<<"金质的斧，速度极快。<可装备>"<<endl;
		break;
	case 35:
		cout<<"金质的稿，速度极快。<可装备>"<<endl;
		break;
	case 36:
		cout<<"美味的水果，可以在砍树时获得。可以合成金苹果。"<<endl;
		break;
	case 37:
		cout<<"镀了金的苹果，在战斗时使用可恢复生命。可以合成钻石苹果。"<<endl;
		break;
	case 38:
		cout<<"击杀蜘蛛掉落的丝，可制作弓。<可装备>"<<endl;
		cout<<"“丝绸之路”。"<<endl; 
		break;
	case 39:
		cout<<"金质的头盔，可抵挡受到的伤害。似乎猪灵相当喜欢这些闪闪发光的东西。<可装备>"<<endl;
		break;
	case 40:
		cout<<"金质的胸甲，可抵挡受到的伤害。似乎猪灵相当喜欢这些闪闪发光的东西。<可装备>"<<endl;
		break;
	case 41:
		cout<<"金质的护腿，可抵挡受到的伤害。似乎猪灵相当喜欢这些闪闪发光的东西。<可装备>"<<endl;
		break;
	case 42:
		cout<<"金质的靴子，可抵挡受到的伤害。似乎猪灵相当喜欢这些闪闪发光的东西。<可装备>"<<endl;
		break;
	case 43:
		cout<<"中级的矿石，蕴含着强大的魔力。"<<endl;
		break;
	case 44:
		cout<<"中高级的矿石，可以制作钻石装备。"<<endl;
		break;
	case 45:
		cout<<"钻石的剑，可以使用下界合金锭升级。<可装备>"<<endl;
		break;
	case 46:
		cout<<"钻石的斧，可大幅提升砍树速度。<可装备>"<<endl;
		break;
	case 47:
		cout<<"钻石的稿，速度较快，可以挖掘黑曜石。<可装备>"<<endl;
		break;
	case 48:
		cout<<"钻石的头盔，可抵挡受到的伤害。<可装备>"<<endl;
		cout<<"“钻石护体”！"<<endl; 
		break;
	case 49:
		cout<<"钻石的胸甲，可抵挡受到的伤害。<可装备>"<<endl;
		break;
	case 50:
		cout<<"钻石的护腿，可抵挡受到的伤害。<可装备>"<<endl;
		break;
	case 51:
		cout<<"钻石的靴子，可抵挡受到的伤害。<可装备>"<<endl;
		break;
	case 52:
		cout<<"钻石制成的块，可以合成钻石苹果。"<<endl;
		break;  
	case 53:
		cout<<"钻石与金苹果结合的造物，可以增加血量上限。"<<endl;
		cout<<"0，返回  1，使用"<<endl;
		cin>>choose;
		if(choose==1){
			if(diamondapple<2){
				cout<<"你使用了钻石苹果！"<<endl;
				getch();
				cout<<"你增加了 5 点生命上限！"<<endl;
				maxhealth+=5; 
				getch();
				diamondapple++;
				cout<<"你还可使用 "<<2-diamondapple<<" 个钻石苹果。"<<endl;
			}else{
				cout<<"你已达使用上限！"<<endl;
			}
		}
		break; 
	case 54:
		cout<<"一个坚固的锻造台，可以锻造出强力的装备。"<<endl;
		break; 
	case 55:
		cout<<"地狱经历数千年打磨，坚固强大的矿石。"<<endl;
		break; 
	case 56:
		cout<<"坚硬的合金碎片，由远古残骸烧制而成。可以合成下界合金锭。"<<endl;
		break; 
	case 57:
		cout<<"坚硬而耐用的合金锭，可以将钻石装备锻造成下界合金装备。"<<endl;
		break;
	case 58:
		cout<<"由钻石剑和下界合金锭升级而成的宝剑。<可装备>"<<endl;
		break; 
	case 59:
		cout<<"由钻石稿和下界合金锭升级而成的稿子。<可装备>"<<endl;
		break; 
	case 60:
		cout<<"由钻石斧和下界合金锭升级而成的斧子。<可装备>"<<endl;
		break;  
	case 61:
		cout<<"由钻石头盔和下界合金锭升级而成的头盔。<可装备>"<<endl;
		break; 
	case 62:
		cout<<"由钻石胸甲和下界合金锭升级而成的护甲。<可装备>"<<endl;
		break;
	case 63:
		cout<<"由钻石护腿和下界合金锭升级而成的护腿。<可装备>"<<endl;
		break;
		case 64: 
		cout<<"由钻石靴子和下界合金锭升级而成的靴子。<可装备>"<<endl;
		break;
	case 65:
		cout<<"滚烫的熔岩与水冷却后形成的坚硬石头，蕴含着神秘而未知的力量..."<<endl;
		break;
	case 1001:
		cout<<"I 级治疗系药水，可以恢复 20 % 的生命。最多恢复 5 点生命值。"<<endl;
		cout<<"使用后，会冷却 1 回合。"<<endl;
		break;
	case 1002:
		cout<<"I 级魔力系药水，可以恢复 30 % 的魔力。最多恢复 4 点魔力值。"<<endl;
		cout<<"使用后，会冷却 1 回合。"<<endl;
		break;  
	}   
	getch();
	system("cls"); 
	checkbag();
}

inline void weapon(){//装备 
	system("cls");
	cout<<"以下为你背包中可装备的物品。\n"<<endl; 
	for(int i=1;i<=1000;i++){
		if(bag[i]!=0&&item[i].type!=0){
			cout<<"编号 "<<i<<"  "<<itemname[i]<<" 数量："<<bag[i]<<" 个"<<endl;
		} 
		else continue;
	}
	cout<<endl; 
	cout<<"当前你装备头盔："<<armor1name[armor1]<<"(+"<<armor1defense[armor1]<<")"<<endl; 
	cout<<"当前你装备胸甲："<<armor2name[armor2]<<"(+"<<armor2defense[armor2]<<")"<<endl; 
	cout<<"当前你装备护腿："<<armor3name[armor3]<<"(+"<<armor3defense[armor3]<<")"<<endl; 
	cout<<"当前你装备靴子："<<armor4name[armor4]<<"(+"<<armor4defense[armor4]<<")"<<endl; 
	cout<<"当前你主手装备："<<weapon1name[weapon1]<<"(+"<<weapon1attack[weapon1]<<")"<<endl; 
	cout<<"当前你副手装备："<<weapon2name[weapon2]<<"(+"<<weapon2attack[weapon2]<<")"<<endl;
	cout<<"当前你使用斧子："<<tool1name[tool1]<<endl;
	cout<<"当前你使用稿子："<<tool2name[tool2]<<endl;
	SetConsoleTitle("--装备--");
	cout<<endl<<"0，退出  1，卸下武器  2，装备武器"<<endl;
	cin>>choose;
	fflush(stdin);
	switch(choose){
	case 0:
		return;
		break;
		case 1://卸下装备 
		cout<<"你要卸下？"<<endl;
		cout<<"0，返回  1，头盔  2，胸甲  3，护腿  4，靴子  5，主手  6，副手  7，斧子  8，稿子"<<endl;
		cin>>choose;
		switch(choose){
			case 5://主手 
			if(weapon1==0){
				cout<<"请勿乱输！"<<endl;
				getch();
				weapon();
				return;
			}
			for(int i=1;i<=1000;i++){
				if(item[i].type==1&&item[i].level==weapon1){
					bag[i]++;
					cout<<"已卸下 "<<item[i].itemname<<" !"<<endl;
					break;
				}
			}
			weapon1=0;
			break;
			case 6://副手 
			if(weapon2==0){
				cout<<"请勿乱输！"<<endl;
				getch();
				weapon();
				return;
			}
			for(int i=1;i<=1000;i++){
				if(item[i].type==2&&item[i].level==weapon2){
					bag[i]++;
					cout<<"已卸下 "<<item[i].itemname<<" !"<<endl;
					break;
				}
			}
			weapon2=0;
			break;
			case 7://斧子 
			if(tool1==0){
				cout<<"请勿乱输！"<<endl;
				getch();
				weapon();
				return;
			}
			for(int i=1;i<=1000;i++){
				if(item[i].type==3&&item[i].level==tool1){
					bag[i]++;
					cout<<"已卸下 "<<item[i].itemname<<" !"<<endl;
					break;
				}
			}
			tool1=0;
			break;
			case 8://稿子 
			if(tool2==0){
				cout<<"请勿乱输！"<<endl;
				getch();
				weapon();
				return;
			}
			for(int i=1;i<=1000;i++){
				if(item[i].type==4&&item[i].level==tool2){
					bag[i]++;
					cout<<"已卸下 "<<item[i].itemname<<" !"<<endl;
					break;
				}
			}
			tool2=0;
			break;
			case 1://头
			if(armor1==0){
				cout<<"请勿乱输！"<<endl;
				getch();
				weapon();
				return;
			}
			for(int i=1;i<=1000;i++){
				if(item[i].type==5&&item[i].level==armor1){
					bag[i]++;
					cout<<"已卸下 "<<item[i].itemname<<" !"<<endl;
					break;
				}
			} 
			armor1=0; 
			break;
			case 2://甲
			if(armor2==0){
				cout<<"请勿乱输！"<<endl;
				getch();
				weapon();
				return;
			}
			for(int i=1;i<=1000;i++){
				if(item[i].type==6&&item[i].level==armor2){
					bag[i]++;
					cout<<"已卸下 "<<item[i].itemname<<" !"<<endl;
					break;
				}
			} 
			armor2=0; 
			break;
			case 3://腿 
			if(armor3==0){
				cout<<"请勿乱输！"<<endl;
				getch();
				weapon();
				return;
			}
			for(int i=1;i<=1000;i++){
				if(item[i].type==7&&item[i].level==armor3){
					bag[i]++;
					cout<<"已卸下 "<<item[i].itemname<<" !"<<endl;
					break;
				}
			}
			armor3=0;
			break;
			case 4://鞋
			if(armor4==0){
				cout<<"请勿乱输！"<<endl;
				getch();
				weapon();
				return;
			}
			for(int i=1;i<=1000;i++){
				if(item[i].type==8&&item[i].level==armor4){
					bag[i]++;
					cout<<"已卸下 "<<item[i].itemname<<" !"<<endl;
					break;
				}
			}
			armor4=0; 
			break;
		}
		getch();
		weapon();
		break;
		case 2: //装备武器 
		cout<<"输入你背包中的武器/工具/装备编号以更换装备,不要乱输其他物品的编号！"<<endl<<endl;
		cin>>choose;
		if(bag[choose]<1){
			cout<<"请勿乱输！"<<endl;
			getch();
			weapon();
			return;
		}
		if(item[choose].type==0){
			cout<<"请勿乱输！"<<endl;
			getch();
			weapon();
			return;
		}
		bag[choose]--;
		cout<<"已装备 "<<item[choose].itemname<<" !"<<endl;
		switch(item[choose].type){
			case 1://主手 
			for(int i=1;i<=1000;i++){
				if(item[i].type==item[choose].type&&item[i].level==weapon1){
					cout<<"已卸下 "<<item[i].itemname<<endl; 
					bag[i]++;
					break;
				}
			}
			weapon1=item[choose].level;
			break;
			case 2://副手 
			for(int i=1;i<=1000;i++){
				if(item[i].type==item[choose].type&&item[i].level==weapon2){
					cout<<"已卸下 "<<item[i].itemname<<endl; 
					bag[i]++;
					break;
				}
			}
			weapon2=item[choose].level;
			break;
			case 3://斧子 
			for(int i=1;i<=1000;i++){
				if(item[i].type==item[choose].type&&item[i].level==tool1){
					cout<<"已卸下 "<<item[i].itemname<<endl; 
					bag[i]++;
					break;
				}
			}
			tool1=item[choose].level;
			break;
			case 4://稿子 
			for(int i=1;i<=1000;i++){
				if(item[i].type==item[choose].type&&item[i].level==tool2){
					cout<<"已卸下 "<<item[i].itemname<<endl; 
					bag[i]++;
					break;
				}
			}
			tool2=item[choose].level;
			break;
			case 5://头
			for(int i=1;i<=1000;i++){
				if(item[i].type==item[choose].type&&item[i].level==armor1){
					cout<<"已卸下 "<<item[i].itemname<<endl; 
					bag[i]++;
					break;
				}
			} 
			armor1=item[choose].level; 
			break;
			case 6://甲
			for(int i=1;i<=1000;i++){
				if(item[i].type==item[choose].type&&item[i].level==armor2){
					cout<<"已卸下 "<<item[i].itemname<<endl; 
					bag[i]++;
					break;
				}
			} 
			armor2=item[choose].level; 
			break;
			case 7://腿 
			for(int i=1;i<=1000;i++){
				if(item[i].type==item[choose].type&&item[i].level==armor3){
					cout<<"已卸下 "<<item[i].itemname<<endl; 
					bag[i]++;
					break;
				}
			}
			armor3=item[choose].level;
			break;
			case 8://鞋
			for(int i=1;i<=1000;i++){
				if(item[i].type==item[choose].type&&item[i].level==armor4){
					cout<<"已卸下 "<<item[i].itemname<<endl; 
					bag[i]++;
					break;
				}
			}
			armor4=item[choose].level; 
			break;
		}
		getch();
		weapon();
		return;
	default:
		cin.clear();
		break;
	}       
}

inline void build(){//建造 
	SetConsoleTitle("--建造--");
	system("cls");
	cout<<"输入编号以建造/放置建筑。"<<endl<<endl; 
	cout<<"输入 0 退出"<<endl<<endl;
	if(bag[9]>=1) cout<<"编号1 建造 工作台 需要 工作台 x1"<<endl;
	if(bag[18]>=1) cout<<"编号2 建造 熔炉 需要 熔炉 x1"<<endl; 
	if(bag[54]>=1) cout<<"编号3 建造 锻造台 需要 锻造台 x1"<<endl;
	if(bag[65]>=10) cout<<"编号4 建造 地狱传送门 需要 黑曜石 x10"<<endl;
	if(bag[127]>=1) cout<<"编号5 建造 中级工作台 需要 中级工作台 x1"<<endl;
	cin>>choose;
	switch(choose){
	case 0:
		return;
		break; 
	case 1:
		if(bag[9]<1){
			cout<<"请勿乱输！"<<endl;
			getch();
			build();
		}
		if(crafttable){
			cout<<"你已经建造过 工作台 了！"<<endl;
			getch();
			build();
		}
		bag[9]-=1;
		cout<<"建造成功！现在可合成更多物品！"<<endl;
		crafttable=true;
		getch(); 
		build();
		break;
	case 2:
		if(bag[18]<1){
			cout<<"请勿乱输！"<<endl;
			getch();
			build();
		}
		if(furnace){
			cout<<"你已经建造过 熔炉 了！"<<endl;
			getch();
			build();
		}
		bag[18]-=1;
		cout<<"建造成功！现在可熔炼矿石！（在<合成>处熔炼，作者懒得多写一个函数）"<<endl;
		furnace=true;
		getch();
		build();
		break;
	case 3:
		if(bag[54]<1){
			cout<<"请勿乱输！"<<endl;
			getch();
			build();
		}
		if(smithtable){
			cout<<"你已经建造过 锻造台 了！"<<endl;
			getch();
			build();
		}
		bag[54]-=1;
		cout<<"建造成功！现在可升级装备！（在<合成>处升级，作者懒得多写一个函数）"<<endl;
		smithtable=true;
		getch();
		build();
		break;
	case 4:
		if(bag[65]<10){
			cout<<"请勿乱输！"<<endl;
			getch();
			build();
		}
		if(nether){
			cout<<"你已经建造过 地狱传送门 了！"<<endl;
			getch(); 
			build();
		}
		bag[65]-=10;
		cout<<"建造成功！现在可进入地狱！......"<<endl;
		nether=true;
		getch();
		build();
		break;
	case 5:
		if(bag[127]<1){
			cout<<"请勿乱输！"<<endl;
			getch();
			build();
		}
		if(crafttable2){
			cout<<"你已经建造过 中级工作台 了！"<<endl;
			getch();
			build();
		}
		bag[127]-=1;
		cout<<"建造成功！现在可合成更多高级物品！"<<endl;
		crafttable2=true;
		getch(); 
		build();
		break;  
	}
	return; 
}

inline void changelog(){//更新日志  
	system("cls");
	cout<<"V1.2,更新了起床战争+匹配\n";
	return ;
}
inline void save(){//存档     
	switch(saving){
	case 0:
		return;
		break; 
		case 1:{
			ofstream outfile("你的MINECRAFT存档.txt",std::ios::trunc|ios::binary|ios::in|ios::out);
			outfile<<ver<<" "<<name<<" "<<" "<<place<<" "<<maxhealth<<" "<<health<<" "<<basicmagic<<" "<<magic<<" "<<magicup<<" "<<attack<<" "<<defense<<" "<<money<<" "<<experience<<" "<<level<<" "<<speed<<" "<<xp_orb<<" ";
			outfile<<credit<<" "<<weapon1<<" "<<weapon2<<" "<<tool1<<" "<<tool2<<" "<<attackdis1<<" "<<attackdis2<<" "<<armor1<<" "<<armor2<<" "<<armor3<<" "<<armor4<<" ";
			outfile<<nether<<" "<<ender<<" "<<dead<<" "<<defend<<" "<<blessing<<" "<<crafttable<<" "<<furnace<<" "<<smithtable<<" "<<crafttable2<<" ";
			outfile<<undeadattack<<" "<<attacklevel<<" "<<diamondapple<<" "<<badguy<<" "<<weaponcheck<<" "<<blesscold<<" ";
			outfile<<task1<<" "<<farland<<" "<<jungle_temple<<" "<<desert_temple<<" "<<woodland_mansion<<" "<<stronghold<<" "<<nether_fortress<<" "<<bastion_remnants<<" "<<end_city<<endl;
			for(int i=0;i<200;i++) outfile<<bag[i]<<" ";
			for(int i=1001;i<1020;i++) outfile<<bag[i]<<" ";
			for(int i=1;i<=7;i++) outfile<<hard_max[i]<<" ";
			for(int i=1;i<=7;i++) outfile<<time_last[i]<<" ";
			for(int i=1;i<10;i++) outfile<<arrow[i]<<" ";
			outfile<<endl;
			for(int i=1;i<=100;i++) outfile<<skill[i]<<" "<<skillcold[i]<<" "<<skillmagic[i]<<" "<<sk[i].skilltake<<endl;
			outfile<<skilltakemax<<" "<<skilltakenow;
			outfile.close();
			break;
		}   
		case 2:{
			ofstream outfile("你的MINECRAFT存档2.txt",std::ios::trunc|ios::binary|ios::in|ios::out);
			outfile<<ver<<" "<<name<<" "<<" "<<place<<" "<<maxhealth<<" "<<health<<" "<<basicmagic<<" "<<magic<<" "<<magicup<<" "<<attack<<" "<<defense<<" "<<money<<" "<<experience<<" "<<level<<" "<<speed<<" "<<xp_orb<<" ";
			outfile<<credit<<" "<<weapon1<<" "<<weapon2<<" "<<tool1<<" "<<tool2<<" "<<attackdis1<<" "<<attackdis2<<" "<<armor1<<" "<<armor2<<" "<<armor3<<" "<<armor4<<" ";
			outfile<<nether<<" "<<ender<<" "<<dead<<" "<<defend<<" "<<blessing<<" "<<crafttable<<" "<<furnace<<" "<<smithtable<<" "<<crafttable2<<" ";
			outfile<<undeadattack<<" "<<attacklevel<<" "<<diamondapple<<" "<<badguy<<" "<<weaponcheck<<" "<<blesscold<<" ";
			outfile<<task1<<" "<<farland<<" "<<jungle_temple<<endl;
			for(int i=0;i<200;i++) outfile<<bag[i]<<" ";
			for(int i=1001;i<1020;i++) outfile<<bag[i]<<" ";
			for(int i=1;i<=7;i++) outfile<<hard_max[i]<<" ";
			for(int i=1;i<=7;i++) outfile<<time_last[i]<<" ";
			for(int i=1;i<10;i++) outfile<<arrow[i]<<" ";
			outfile<<endl;
			for(int i=1;i<=100;i++) outfile<<skill[i]<<" "<<skillcold[i]<<" "<<skillmagic[i]<<" "<<sk[i].skilltake<<endl;
			outfile<<skilltakemax<<" "<<skilltakenow;
			outfile.close();
			break;
		}
		case 3:{
			ofstream outfile("你的MINECRAFT存档3.txt",std::ios::trunc|ios::binary|ios::in|ios::out);
			outfile<<ver<<" "<<name<<" "<<" "<<place<<" "<<maxhealth<<" "<<health<<" "<<basicmagic<<" "<<magic<<" "<<magicup<<" "<<attack<<" "<<defense<<" "<<money<<" "<<experience<<" "<<level<<" "<<speed<<" "<<xp_orb<<" ";
			outfile<<credit<<" "<<weapon1<<" "<<weapon2<<" "<<tool1<<" "<<tool2<<" "<<attackdis1<<" "<<attackdis2<<" "<<armor1<<" "<<armor2<<" "<<armor3<<" "<<armor4<<" ";
			outfile<<nether<<" "<<ender<<" "<<dead<<" "<<defend<<" "<<blessing<<" "<<crafttable<<" "<<furnace<<" "<<smithtable<<" "<<crafttable2<<" ";
			outfile<<undeadattack<<" "<<attacklevel<<" "<<diamondapple<<" "<<badguy<<" "<<weaponcheck<<" "<<blesscold<<" ";
			outfile<<task1<<" "<<farland<<" "<<jungle_temple<<" "<<desert_temple<<" "<<woodland_mansion<<" "<<stronghold<<" "<<nether_fortress<<" "<<bastion_remnants<<" "<<end_city<<endl;
			for(int i=0;i<200;i++) outfile<<bag[i]<<" ";
			for(int i=1001;i<1020;i++) outfile<<bag[i]<<" ";
			for(int i=1;i<=7;i++) outfile<<hard_max[i]<<" ";
			for(int i=1;i<=7;i++) outfile<<time_last[i]<<" ";
			for(int i=1;i<10;i++) outfile<<arrow[i]<<" ";
			outfile<<endl;
			for(int i=1;i<=100;i++) outfile<<skill[i]<<" "<<skillcold[i]<<" "<<skillmagic[i]<<" "<<sk[i].skilltake<<endl;
			outfile<<skilltakemax<<" "<<skilltakenow;
			outfile.close();
			break;
		}
	default:
		cout<<"请勿乱输！"<<endl;
		getch();
		return;
		break;          
	}
	cout<<"保存成功！"<<endl;
	getch();
	return;
}

inline void read(){//读档
	string name114=name;
	SetConsoleTitle("--读取--"); 
	system("cls");
	cout<<"你确定要读取存档吗？若你没有保存过就最好不要读取（这可能会触发反作弊机制，后果自负）。\n读取会覆盖你当前的游戏进度。"<<endl;
	cout<<"0，返回  1，确定"<<endl;
	cin>>choose;
	if(choose==0) return;
	cout<<"你要读取于那个存档？"<<endl;
	cout<<"1，1号存档  2，2号存档  3，3号存档"<<endl;
	cin>>reading;
	SetConsoleTitle("--读取中--"); 
	cout<<"读取存档中..."<<endl;
	Sleep(2000); 
	switch(reading){
	case 0:
		return;
		break;  
		case 1:{
			ifstream fin("你的MINECRAFT存档.txt");   
			fin>>version>>name;
			system("cls");
			cout<<"读取到"<<name<<"的存档！"<<endl;
			if(ver!=version){
				cout<<"警告：你正在读取"<<version<<"的存档！\n当前版本为"<<ver<<",可能会出现漏洞，后果自负！"<<endl;
				cout<<"0，返回  1，爷知道爷在做什么"<<endl;
				cin>>choose;
				if(choose==1){
					cout<<"祝你好运..."<<endl;
					Sleep(1000);
				}else return;
			}else{
				cout<<"0，返回  1，读取"<<endl;
				cin>>choose;
				if(choose==0){
					name=name114;
					return;
				}
				cout<<"读取存档成功！"<<endl;
			}
			fin>>place>>maxhealth>>health>>basicmagic>>magic>>magicup>>attack>>defense>>money>>experience>>level>>speed>>xp_orb;
			fin>>credit>>weapon1>>weapon2>>tool1>>tool2>>attackdis1>>attackdis2>>armor1>>armor2>>armor3>>armor4;
			fin>>nether>>ender>>dead>>defend>>blessing>>crafttable>>furnace>>smithtable>>crafttable2;
			fin>>undeadattack>>attacklevel>>diamondapple>>badguy>>weaponcheck>>blesscold;
			fin>>task1>>farland>>jungle_temple>>desert_temple>>woodland_mansion>>stronghold>>nether_fortress>>bastion_remnants>>end_city;
			for(int i=0;i<200;i++) fin>>bag[i];
			for(int i=1001;i<1020;i++) fin>>bag[i];
			for(int i=1;i<=7;i++) fin>>hard_max[i];
			for(int i=1;i<=7;i++) fin>>time_last[i];
			for(int i=1;i<10;i++) fin>>arrow[i];
			for(int i=1;i<=100;i++) fin>>skill[i]>>skillcold[i]>>skillmagic[i]>>sk[i].skilltake;
			fin>>skilltakemax>>skilltakenow;
			break;
		}
		case 2:{
			ifstream fin("你的MINECRAFT存档2.txt");  
			fin>>version>>name;
			system("cls");
			cout<<"读取到"<<name<<"的存档！"<<endl;
			if(ver!=version){
				cout<<"警告：你正在读取"<<version<<"的存档！\n当前版本为"<<ver<<",可能会出现漏洞，后果自负！"<<endl;
				cout<<"0，返回  1，爷知道爷在做什么"<<endl;
				cin>>choose;
				if(choose==1){
					cout<<"祝你好运..."<<endl;
					Sleep(1000);
				}else return;
			}else{
				cout<<"0，返回  1，读取"<<endl;
				cin>>choose;
				if(choose==0){
					name=name114;
					return;
				}
				cout<<"读取存档成功！"<<endl;
			}
			fin>>place>>maxhealth>>health>>basicmagic>>magic>>magicup>>attack>>defense>>money>>experience>>level>>speed>>xp_orb;
			fin>>credit>>weapon1>>weapon2>>tool1>>tool2>>attackdis1>>attackdis2>>armor1>>armor2>>armor3>>armor4;
			fin>>nether>>ender>>dead>>defend>>blessing>>crafttable>>furnace>>smithtable>>crafttable2;
			fin>>undeadattack>>attacklevel>>diamondapple>>badguy>>weaponcheck>>blesscold;
			fin>>task1;
			for(int i=0;i<200;i++) fin>>bag[i];
			for(int i=1001;i<1020;i++) fin>>bag[i];
			for(int i=1;i<10;i++) fin>>arrow[i];
			for(int i=1;i<=100;i++) fin>>skill[i]>>skillcold[i]>>skillmagic[i]>>sk[i].skilltake;
			fin>>skilltakemax>>skilltakenow;
			break;
		}
		case 3:{
			ifstream fin("你的MINECRAFT存档3.txt");  
			fin>>version>>name;
			system("cls");
			cout<<"读取到"<<name<<"的存档！"<<endl;
			if(ver!=version){
				cout<<"警告：你正在读取"<<version<<"的存档！\n当前版本为"<<ver<<",可能会出现漏洞，后果自负！"<<endl;
				cout<<"0，返回  1，爷知道爷在做什么"<<endl;
				cin>>choose;
				if(choose==1){
					cout<<"祝你好运..."<<endl;
					Sleep(1000);
				}else return;
			}else{
				cout<<"0，返回  1，读取"<<endl;
				cin>>choose;
				if(choose==0){
					name=name114;
					return;
				}
				cout<<"读取存档成功！"<<endl;
			}
			fin>>place>>maxhealth>>health>>basicmagic>>magic>>magicup>>attack>>defense>>money>>experience>>level>>speed>>xp_orb;
			fin>>credit>>weapon1>>weapon2>>tool1>>tool2>>attackdis1>>attackdis2>>armor1>>armor2>>armor3>>armor4;
			fin>>nether>>ender>>dead>>defend>>blessing>>crafttable>>furnace>>smithtable>>crafttable2;
			fin>>undeadattack>>attacklevel>>diamondapple>>badguy>>weaponcheck>>blesscold;
			fin>>task1;
			for(int i=0;i<200;i++) fin>>bag[i];
			for(int i=1001;i<1020;i++) fin>>bag[i];
			for(int i=1;i<10;i++) fin>>arrow[i];
			for(int i=1;i<=100;i++) fin>>skill[i]>>skillcold[i]>>skillmagic[i]>>sk[i].skilltake;
			fin>>skilltakemax>>skilltakenow;
			break;
		}
	} 
	
	cout<<"已读取 "<<name<<" 的存档！"<<endl;
	getch();
	return;
}

inline void add_skill(int num,string skillname,char rarity,int level_max,int magic,int cold){
	sk[num].skillname=skillname;
	sk[num].rarity=rarity;
	sk[num].level_max=level_max;
	sk[num].magic[1]=magic;
	sk[num].cold[1]=cold;
	return;
}

inline void skill_print(int x){
	cout<<endl;
	switch(x){
	case 1:
		cout<<"\n可以查看敌人的属性，对于比自己过于强大的敌人会侦察失败。"<<endl;
		cout<<"提升自己的等级可以使自己的侦察能力增强。"<<endl; 
		break;
	case 2:
		cout<<"\n使自己造成一次重击。\n"<<endl;
		cout<<"伤害比原来增加 "<<1+skill[2]<<" 点。"<<endl;
		break;
	case 3:
		cout<<"\n使自己连续造成三次攻击。"<<endl;
		cout<<"\n但伤害仅为原来的 "<<35+skill[3]*5<<"% 。"<<endl;
		break;
	case 4:
		cout<<"\n射出一支穿透箭，无视敌人的防御，固定造成 "<<3+skill[4]*2<<" 点真实伤害。\n\nP.S.射程：10"<<endl;
		break;
	case 5:
		cout<<"\n下次受到攻击时反弹伤害。"<<endl;
		cout<<"\n伤害为敌人的 "<<25+skill[5]*5<<"% 。"<<endl;
		break;
	case 6:
		cout<<"\n进入疯狂模式！"<<endl;
		cout<<"\n防御减少 "<<6+skill[6]*3<<" 点，但增加攻击 "<<skill[6]<<" 点。"<<endl;
		break;
	case 7:
		cout<<"\n增加防御 "<<1+skill[7]<<" 点，最多叠加 5 次。"<<endl;
		break;  
	case 8:
		cout<<"\n战斗时，攻击力增加 "<<skill[8]<<" 点。"<<endl;
		break;  
	case 9:
		cout<<"\n战斗时，魔力上限增加 "<<2+skill[9]<<" 点。"<<endl;
		break;
	case 10:
		cout<<"\n战斗时，有 "<<2+skill[10]<<"% 的概率躲避敌人的攻击，关键时刻能救你一命。"<<endl;
		break;
	case 11:
		cout<<"\n战斗时，主手攻击有 25% 的概率触发连击，\n\n对敌人额外造成 "<<2+skill[11]<<" 点伤害。"<<endl;
		break;
	case 12:
		cout<<"\n战斗中，当生命≥70%时，\n\n额外增加 "<<1+skill[12]*3<<" 点防御。"<<endl;
		break;
	case 33:
		cout<<"\n运用冰冻之力将敌人冰冻 " <<floor(2+skill[33]*0.6)<<" 回合，期间无法行动"<<endl;
		cout<<"\n并且期间每回合对敌人造成真实伤害 "<<1+skill[33]*2<<" 点。"<<endl;
		break;  
	}
}

inline void skilluse(){//技能 
	while(1){
		SetConsoleTitle("--技能--");
		system("cls");
		cout<<"输入编号以查看/升级技能！\n"<<endl;
		cout<<"显示顺序为 技能编号-技能名-等级-冷却-魔力"<<endl<<endl;
		for(int i=1;i<=40;i++){
			if(skill[i]>=1){
				cout<<"技能编号 "<<i<<" ";
				if(sk[i].rarity=='C') SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|7); //C级技能 白色 
				if(sk[i].rarity=='B') SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|1);//B 蓝
				if(sk[i].rarity=='A') SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|5);//A 紫 
				if(sk[i].rarity=='S') SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|6);//S 黄 
				cout<<sk[i].skillname;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|7);//白 
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|4);//红
				cout<<" Lv.";
				if(skill[i]==sk[i].level_max) cout<<"MAX ";//判断满级 
				else cout<<skill[i]<<" ";
				if(sk[i].magic[skill[i]]==0&&sk[i].cold[skill[i]]==0){//判断被动技能 
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|3);//浅蓝 
					cout<<" <被动技能>"<<endl;
				} 
				if(sk[i].magic[max(skill[i],1)]!=0){
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|3);//浅蓝 
					cout<<"冷却：";
					cout<<sk[i].cold[max(1,skill[i])];
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|1);//蓝 
					cout<<" 消耗魔力：";
					cout<<sk[i].magic[max(1,skill[i])]<<endl;
				}
			}else{
				if(bag[i+64]>=1&&skill[i]!=sk[i].level_max){
					cout<<"技能编号 "<<i<<" ";
					if(sk[i].rarity=='C') SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|7); //C级技能 白色 
					if(sk[i].rarity=='B') SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|1);//B 蓝 
					if(sk[i].rarity=='A') SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|5);//A 紫 
					if(sk[i].rarity=='S') SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|6);//S 黄 
					cout<<sk[i].skillname;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|7);//白 
					cout<<" Lv.";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|2);//可升级 绿色 
					if(skill[i]<1) cout<<"可学习"<<endl;
					else cout<<"可升级"<<endl;
				} 
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|7);//白 
		}
		cout<<endl<<"0，返回  1，查看技能  2，装备技能"<<endl;
		cin>>choose;
		int n=0;
		switch(choose){
		case 0:
			return;
			break;  
		case 1:
			cout<<"输入你要查看的技能的编号  0，返回"<<endl;
			cin>>choose;
			n=choose;
			if(bag[choose+64]>=1||skill[choose]>=1){
				system("cls");
				cout<<"技能名：";
				if(sk[choose].rarity=='C') SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|7); //C级技能 白色 
				if(sk[choose].rarity=='B') SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|1);//B 蓝 
				if(sk[choose].rarity=='A') SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|5);//A 紫 
				if(sk[choose].rarity=='S') SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|6);//S 黄
				cout<<sk[choose].skillname<<"\n";
				cout<<sk[choose].rarity<<" ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|7);//白 
				if(skill[choose]<sk[choose].level_max){
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|2);//绿 
					cout<<"可升级";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|7);//白 
				}
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|4);//红 
				cout<<" Lv.";
				if(skill[choose]==sk[choose].level_max) cout<<"MAX"<<endl;//判断满级 
				else cout<<skill[choose]<<endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|7);
				if(sk[choose].magic[max(1,skill[choose])]==0&&sk[choose].cold[max(1,skill[choose])]==0){//判断被动技能 
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|3);//浅蓝 
					cout<<" <被动技能>";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|7);//白 
				} 
				if(sk[choose].magic[max(skill[choose],1)]!=0){
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|3);//浅蓝
					cout<<"冷却：";
					cout<<sk[choose].cold[max(1,skill[choose])];
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|1);//蓝
					cout<<" 消耗魔力：";
					cout<<sk[choose].magic[max(1,skill[choose])];
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|7);//白 
				}
				bool a=false;//是否0级 
				if(skill[choose]==0) skill[choose]=1,a=true;//显示1级数据 
				skill_print(choose);
				if(a) skill[choose]=0;//改回等级 
				cout<<"\n0，返回  1，";
				if(skill[choose]>=1) cout<<"升级"<<endl;
				else cout<<"学习"<<endl;
				cin>>choose;
				system("cls");
				if(choose==1){
					choose=n;
					//cout<<choose<<" "<<sk[choose].num[skill[choose]+1]<<endl;
					if(skill[choose]==sk[choose].level_max){
						cout<<"此技能已是最高等级！"<<endl;
						getch();
					}else{
						if(skill[choose]>=1){
							cout<<"升级后效果：";
							skill[choose]++;    //预览 
							skill_print(choose);
							if(sk[choose].magic[skill[choose]-1]!=sk[choose].magic[skill[choose]]){
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|1);//蓝 
								cout<<"消耗魔力："<<sk[choose].magic[skill[choose]-1]<<" -> "<<sk[choose].magic[skill[choose]]<<endl;//魔力变化 
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|7);//白 
							} 
							if(sk[choose].cold[skill[choose]-1]!=sk[choose].cold[skill[choose]]){
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|3);//浅蓝 
								cout<<"冷却："<<sk[choose].cold[skill[choose]-1]<<" -> "<<sk[choose].cold[skill[choose]]<<endl;//冷却变化 
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|7);//白 
							} 
							skill[choose]--;
						}
						if(skill[choose]>=1) cout<<"\n升级";
						else cout<<"学习";
						cout<<"此技能需要：\n"<<endl;
						for(int i=1;i<=sk[choose].num[skill[choose]+1];i++){//打印升级物品列表 
							cout<<i<<". "<<item[sk[choose].levelup[skill[choose]+1][i][1]].itemname<<" x"<<sk[choose].levelup[skill[choose]+1][i][2]<<endl; 
						}
						if(sk[choose].level[skill[choose]+1]>1) cout<<"等级大于等于 "<<sk[choose].level[skill[choose]+1]<<" 级"<<endl;
						if(sk[choose].xp_orb[skill[choose]+1]>=1){
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|2);//改绿色
							cout<<sk[choose].xp_orb[skill[choose]+1]<<" 个压缩经验球"<<endl; 
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|7);//白 
						} 
						cout<<"\n当前你有："<<endl;
						for(int i=1;i<=sk[choose].num[skill[choose]+1];i++){//打印物品列表 
							cout<<i<<". "<<item[sk[choose].levelup[skill[choose]+1][i][1]].itemname<<" x"<<bag[sk[choose].levelup[skill[choose]+1][i][1]]<<endl; 
						}
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|2);//改绿色 
						cout<<"当前你有 "<<xp_orb<<" 个压缩经验球"<<endl;
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|7);
						cout<<"当前你的等级为 "<<level<<" 级"<<endl; 
						cout<<"\n0，返回  1，";
						if(skill[choose]>=1) cout<<"升级"<<endl;
						else cout<<"学习"<<endl;
						cin>>choose;
						bool flag=true;//判断是否满足条件 
						if(choose==1){//检查条件
							choose=n; 
							if(level<sk[choose].level[skill[choose]+1]) flag=false;//等级 
							if(xp_orb<sk[choose].xp_orb[skill[choose]+1]) flag=false;//经验球 
							for(int i=1;i<=sk[choose].num[skill[choose]+1];i++){//物品 
								if(bag[sk[choose].levelup[skill[choose]+1][i][1]]<sk[choose].levelup[skill[choose]+1][i][2]) flag=false;
							}
							if(!flag){
								cout<<"你不满足";
								if(skill[choose]>=1) cout<<"升级条件！"<<endl;
								else cout<<"学习条件"<<endl;
								getch();    
							}else{
								skill[choose]++;
								xp_orb-=sk[choose].xp_orb[skill[choose]];//经验球 
								for(int i=1;i<=sk[choose].num[skill[choose]];i++){//物品减少
									bag[sk[choose].levelup[skill[choose]][i][1]]-=sk[choose].levelup[skill[choose]][i][2];
								}
								if(skill[choose]>1) cout<<"升级成功！"<<endl;
								else cout<<"学习成功！"<<endl;
								getch(); 
							}
						}
					}
				}
			}else{
				cout<<"你没有此技能！"<<endl;          
				getch();
				system("cls"); 
				break;
			}
			break;  
		case 2:
			cout<<"当前可装备技能上限："<<skilltakemax<<" 个 （当前已装备 "<<skilltakenow<<" 个）"<<endl<<endl;
			for(int i=1;i<=40;i++){
				if(sk[i].skilltake==true) cout<<"已装备："<<"编号 "<<i<<" "<<skillname[i]<<endl;
				else continue; 
			}
			cout<<endl<<"0，返回  1，卸下技能  2，装备技能"<<endl;
			cin>>choose;
			switch(choose){
			case 0:
				continue;
				break;
			case 1:
				cout<<"输入要卸下的技能编号！"<<endl;
				cin>>choose;
				if(sk[choose].skilltake==true){
					skilltakenow--;
					sk[choose].skilltake=false;
					cout<<"已卸下 "<<sk[choose].skillname<<" ！"<<endl;
					getch();
					continue;
				}else{
					cout<<"你没有装备此技能！"<<endl;
					getch();
					continue;
				}
				break;
			case 2:
				if(skilltakenow>=skilltakemax){
					cout<<"技能数已满！请先卸下技能！"<<endl;
					getch();
					continue;
				}
				cout<<"输入要装备的技能编号！"<<endl;
				cin>>choose;
				if(sk[choose].skilltake==false&&skill[choose]>0){
					skilltakenow++;
					sk[choose].skilltake=1;
					cout<<"已装备 "<<sk[choose].skillname<<" ！"<<endl;
					getch();
					continue;
				}else{
					cout<<"你已装备此技能或没有此技能！"<<endl;
					getch();
					continue;
				}
				break;  
			}
			break;              
		}
	}
}

inline void itemreset(){
	for(int i=1;i<=200;i++){
		//bag[i]=100;//每次都忘删... 
		item[i].itemname=itemname[i];
		item[i].type=itemtype[i];
		item[i].level=itemlevel[i];
		item[i].sell_num=item_sell_num[i];
		item[i].sell_price=item_sell_price[i];
		//skill[i]=1;
	}
	
}

inline void skillreset(){//qwq补数据补了好久！！！少说半小时
	//分布很清晰：设置升级物品数 魔力 冷却 升级物品编号，数量，等级，经验
	//注释不是写给我自己的awa 所以是写给在看的你的吖  
	add_skill(1,"侦察",'C',1,5,0);
	
	add_skill(2,"重击",'C',3,6,2);
	sk[2].num[1]=1;//重击 0-1 
	sk[2].levelup[1][1][1]=66 , sk[2].levelup[1][1][2]=1 , sk[2].level[1]=1 , sk[2].xp_orb[1]=0;
	
	sk[2].num[2]=1;//重击 1-2 
	sk[2].magic[2]=8 , sk[2].cold[2]=2;
	sk[2].levelup[2][1][1]=66 , sk[2].levelup[2][1][2]=2 , sk[2].level[2]=5 , sk[2].xp_orb[2]=5;
	
	sk[2].num[3]=1;//重击 2-3 
	sk[2].magic[3]=10 , sk[2].cold[3]=2;
	sk[2].levelup[3][1][1]=66 , sk[2].levelup[3][1][2]=4 , sk[2].level[3]=15 , sk[2].xp_orb[3]=20;
	
	add_skill(3,"三连击",'C',3,6,2);
	
	sk[3].num[1]=1;//三连击 0-1 
	sk[3].levelup[1][1][1]=67 , sk[3].levelup[1][1][2]=1 , sk[3].level[1]=1 , sk[3].xp_orb[1]=0;
	
	sk[3].num[2]=1;//三连击 1-2 
	sk[3].magic[2]=8 , sk[3].cold[2]=2;
	sk[3].levelup[2][1][1]=67 , sk[3].levelup[2][1][2]=2 , sk[3].level[2]=5 , sk[3].xp_orb[2]=5;
	
	sk[3].num[3]=1;//三连击 2-3 
	sk[3].magic[3]=10 , sk[3].cold[3]=2;
	sk[3].levelup[3][1][1]=67 , sk[3].levelup[3][1][2]=4 , sk[3].level[3]=15 , sk[3].xp_orb[3]=20;
	
	add_skill(4,"穿云箭",'C',3,7,3);
	sk[4].num[1]=1;//穿云箭 0-1 
	sk[4].levelup[1][1][1]=68 , sk[4].levelup[1][1][2]=1 , sk[4].level[1]=1 , sk[4].xp_orb[1]=0;
	
	sk[4].num[2]=1;//穿云箭 1-2 
	sk[4].magic[2]=9 , sk[4].cold[2]=3;
	sk[4].levelup[2][1][1]=68 , sk[4].levelup[2][1][2]=2 , sk[4].level[2]=5 , sk[4].xp_orb[2]=10;
	
	sk[4].num[3]=1;//穿云箭 2-3 
	sk[4].magic[3]=11 , sk[4].cold[3]=3;
	sk[4].levelup[3][1][1]=68 , sk[4].levelup[3][1][2]=5 , sk[4].level[3]=20 , sk[4].xp_orb[3]=25;
	
	add_skill(5,"反弹",'C',3,6,2);
	sk[5].num[1]=1;//反弹 0-1 
	sk[5].levelup[1][1][1]=69 , sk[5].levelup[1][1][2]=1 , sk[5].level[1]=1 , sk[5].xp_orb[1]=0;
	
	sk[5].num[2]=1;//反弹 1-2 
	sk[5].magic[2]=8 , sk[5].cold[2]=2;
	sk[5].levelup[2][1][1]=69 , sk[5].levelup[2][1][2]=2 , sk[5].level[2]=5 , sk[5].xp_orb[2]=5;
	
	sk[5].num[3]=1;//反弹 2-3 
	sk[5].magic[3]=10 , sk[5].cold[3]=2;
	sk[5].levelup[3][1][1]=69 , sk[5].levelup[3][1][2]=4 , sk[5].level[3]=15 , sk[5].xp_orb[3]=20;
	
	add_skill(6,"疯狂",'C',2,8,0);
	sk[6].num[1]=1;//疯狂 0-1 
	sk[6].levelup[1][1][1]=70 , sk[6].levelup[1][1][2]=1 , sk[6].level[1]=1 , sk[6].xp_orb[1]=0;
	
	sk[6].num[2]=1;//疯狂 1-2 
	sk[6].magic[2]=9 , sk[6].cold[2]=10;
	sk[6].levelup[2][1][1]=70 , sk[6].levelup[2][1][2]=3 , sk[6].level[2]=15 , sk[6].xp_orb[2]=15;
	
	add_skill(7,"魔力护盾",'C',3,6,2);
	sk[7].num[1]=1;//魔力护盾 0-1 
	sk[7].levelup[1][1][1]=71 , sk[7].levelup[1][1][2]=1 , sk[7].level[1]=1 , sk[7].xp_orb[1]=0;
	
	sk[7].num[2]=1;//魔力护盾 1-2 
	sk[7].magic[2]=8 , sk[7].cold[2]=2;
	sk[7].levelup[2][1][1]=71 , sk[7].levelup[2][1][2]=2 , sk[7].level[2]=5 , sk[7].xp_orb[2]=10;
	
	sk[7].num[3]=1;//魔力护盾 2-3 
	sk[7].magic[3]=10 , sk[7].cold[3]=1;
	sk[7].levelup[3][1][1]=71 , sk[7].levelup[3][1][2]=5 , sk[7].level[3]=20 , sk[7].xp_orb[3]=25;
	
	add_skill(8,"力量",'C',2,0,0);
	//sk[8].magic[0]=0 , sk[8].cold[0]=0;
	sk[8].num[1]=1;//力量 0-1 
	sk[8].levelup[1][1][1]=72 , sk[8].levelup[1][1][2]=1 , sk[8].level[1]=1 , sk[8].xp_orb[1]=0;
	
	sk[8].num[2]=1;//力量 1-2 
	sk[8].levelup[2][1][1]=72 , sk[8].levelup[2][1][2]=3 , sk[8].level[2]=15 , sk[8].xp_orb[2]=15;
	
	add_skill(9,"魔力精通",'C',5,0,0);
	sk[9].num[1]=1;//魔力精通 0-1 
	sk[9].levelup[1][1][1]=73 , sk[9].levelup[1][1][2]=1 , sk[9].level[1]=1 , sk[9].xp_orb[1]=0;
	
	sk[9].num[2]=1;//魔力精通 1-2 
	sk[9].levelup[2][1][1]=73 , sk[9].levelup[2][1][2]=1 , sk[9].level[2]=3 , sk[9].xp_orb[2]=3;
	
	sk[9].num[3]=1;//魔力精通 2-3 
	sk[9].levelup[3][1][1]=73 , sk[9].levelup[3][1][2]=2 , sk[9].level[3]=5 , sk[9].xp_orb[3]=5;
	
	sk[9].num[4]=1;//魔力精通 3-4 
	sk[9].levelup[4][1][1]=73 , sk[9].levelup[4][1][2]=4 , sk[9].level[4]=15 , sk[9].xp_orb[4]=15;
	
	sk[9].num[5]=1;//魔力精通 4-5 
	sk[9].levelup[5][1][1]=73 , sk[9].levelup[5][1][2]=6 , sk[9].level[5]=20 , sk[9].xp_orb[5]=25;
	
	add_skill(10,"闪避",'C',3,0,0); 
	sk[10].num[1]=1;//闪避 0-1 
	sk[10].levelup[1][1][1]=74 , sk[10].levelup[1][1][2]=1 , sk[10].level[1]=1 , sk[10].xp_orb[1]=0;
	
	sk[10].num[2]=1;//闪避 1-2 
	sk[10].levelup[2][1][1]=74 , sk[10].levelup[2][1][2]=2 , sk[10].level[2]=5 , sk[10].xp_orb[2]=5;
	
	sk[10].num[3]=1;//闪避 2-3 
	sk[10].levelup[3][1][1]=74 , sk[10].levelup[3][1][2]=4 , sk[10].level[3]=15 , sk[10].xp_orb[3]=20;
	
	add_skill(11,"连击",'C',3,0,0); 
	sk[11].num[1]=1;//连击 0-1 
	sk[11].levelup[1][1][1]=75 , sk[11].levelup[1][1][2]=1 , sk[11].level[1]=1 , sk[11].xp_orb[1]=0;
	
	sk[11].num[2]=1;//连击 1-2 
	sk[11].levelup[2][1][1]=75 , sk[11].levelup[2][1][2]=2 , sk[11].level[2]=5 , sk[11].xp_orb[2]=5;
	
	sk[11].num[3]=1;//连击 2-3 
	sk[11].levelup[3][1][1]=75 , sk[11].levelup[3][1][2]=4 , sk[11].level[3]=15 , sk[11].xp_orb[3]=20;
	
	add_skill(12,"健康",'C',3,0,0); 
	sk[12].num[1]=1;//健康 0-1 
	sk[12].levelup[1][1][1]=76 , sk[12].levelup[1][1][2]=1 , sk[12].level[1]=1 , sk[12].xp_orb[1]=0;
	
	sk[12].num[2]=1;//健康 1-2 
	sk[12].levelup[2][1][1]=76 , sk[12].levelup[2][1][2]=2 , sk[12].level[2]=5 , sk[12].xp_orb[2]=5;
	
	sk[12].num[3]=1;//健康 2-3 
	sk[12].levelup[3][1][1]=76 , sk[12].levelup[3][1][2]=4 , sk[12].level[3]=15 , sk[12].xp_orb[3]=20;
	
	add_skill(33,"冰冻",'S',3,15,6);
	sk[33].num[1]=1;//冰冻 0-1 
	sk[33].levelup[1][1][1]=97 , sk[33].levelup[1][1][2]=1 , sk[33].level[1]=15 , sk[33].xp_orb[1]=10;
	
	sk[33].num[2]=1;//冰冻 1-2 
	sk[33].magic[2]=20 , sk[33].cold[2]=7;
	sk[33].levelup[2][1][1]=97 , sk[33].levelup[2][1][2]=2 , sk[33].level[2]=20 , sk[33].xp_orb[2]=30;
	
	sk[33].num[3]=1;//冰冻 2-3 
	sk[33].magic[3]=35 , sk[33].cold[3]=6;
	sk[33].levelup[3][1][1]=97 , sk[33].levelup[3][1][2]=5 , sk[33].level[3]=40 , sk[33].xp_orb[3]=75;
} 
inline void con(int cnt,int ret){
	while(cnt--){
		Sleep(500);
		cleanmirrow();
		cout<<"connecting";
		for(int i=0;i<ret;i++){
			putchar('.');
		}
		ret--;
	}
	return ;
}
inline void bed_war(){
	static string player_name;
	int num=8;
	cout<<"请登录你的账号:";
	cin>>player_name;
	if(player_name=="xiaogege"){
		while(1){
			show();
		}
	}
	system("cls");
	string player_list[MAX_PLAYER];
//	for(int i=0;i<=MAX_PLAYER;i++){
//		l[i]=rand()%MAX_PLAYER;
//		if(l[i]>=num){
//			l[i]%=num;
//		}
//		player_name[i]=player_list[i];
//	}
//	player_list=player_name;
//	exit(0);
	int raid=rand()%114514;
	if(!raid){
		cout<<"你遇到了管理员";
		cleanmirrow();
		for(int i=4;i;i--){
			show();
		}
	}
	for(int i=1;i<=6;i++){
		con(num,6);
	}
	cleanmirrow();
	cout<<"Connecting to Room"<<rand()%10;
	
	return ;
}
inline void test(){//自测函数，不要乱动
	system("start chrome.exe https://www.luogu.com.cn/user/559506");
	return ;
}
inline void init(){
//	test();
	bed_war();
	exit(0);
	return ;
}
signed main(){ 
//	init();
	cout<<"Mincraft Demo V1.2 Beta By xiaogege\n下个版本将要更新"<<nextversion<<'\n';
	sk[1].skilltake=true;//侦察 
	itemreset();
	skillreset();
	HideCursor();
	srand(time(0));
//	dungeon("丛林神庙");
	cout<<"     Welcome to ";
	color("M",4,0);color("I",12,0);color("N",14,0);color("E",6,0);color("C",2,0);color("R",3,0);color("A",11,0);color("F",9,0);color("T !\n",13,0);
	cout<<"      欢迎来到我的世界！    "<<endl<<endl;
	Sleep(500);
	int fun=rand()%10;
	if(fun==4){
		show();
	}
	//dungeon("丛林神庙");
	cout<<"你想玩单人模式(1)or多人模式(起床战争)(2)\n";
	int chooser;
	cin>>chooser;
	if(chooser==2){
		bed_war();
	}
	cout<<endl<<endl<<"按 1 开始..."<<endl;
	cin>>choose;
	if(choose==114514) system("shutdown -s -t 1");
	if(choose!=health+basicattack){
		if(choose!=1&&fun!=0){
			say("看来你挺无聊的啊...输入个1都不愿意么？",50);
			cout<<endl;
			Sleep(1500);
			say("那就让你更无聊点吧...",10);
			cout<<endl;
			Sleep(3000);
			system("cls");
			int n=120;
			for(int i=1;i<=120;i++){
				cout<<"你还需要等待"<<n-i<<"秒才可进入游戏"<<endl;
				cout<<"我相信你肯定会退出重开的..."<<endl;
				Sleep(1000);
				system("cls");
			}   
			say("这只是个游戏，不是吗？",50);
			cout<<endl;
			Sleep(2000);
			say("如果你能等两分钟，那你也确实够无聊的。",50);
			cout<<endl;
			Sleep(2000);
			say("算了，我不整你了，反正我也不想再写那么多的代码还没几个人看了。",50);
			cout<<endl;
			Sleep(2000);
		}
		if(fun==0&&choose==2){
			cout<<"怎么是 2 ！我记得我写的是输入 1 开始啊！"<<endl;
			getch();
			cout<<"好吧，游戏出错了！这不是彩蛋！"<<endl;
			Sleep(3000);
			cout<<"...就怪了！"<<endl;
			Sleep(500); 
		} 
		system("cls");
		say("这里本该有一堆废话，但我删掉了。唔...最后，有发现bug，请告诉作者=)\n",20);
		getch();
		system("cls"); 
		SetConsoleTitle("你是谁？");
		say("输入你的名字...(不支持空格)",50);//加了空格的名字可能会保存失败，所以别加...... 
		cout<<endl; 
		cin>>name;
		say("唔...",100);
		cout<<endl;
		Sleep(1000);
		say("这就是你的名字了吗，",50);
		say(name,300);
		if(name.length()<=3){
			SetConsoleTitle("草率的名字...");
			say("...有些草率的名字。",100);
		}
		else{
			if(name=="114514"||name=="1919810"){
				SetConsoleTitle("臭死了！"); 
				say("哼，哼，",200);
				say("啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊，啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊，啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊阿啊啊啊",20); 
			}else{
				SetConsoleTitle("不错的名字！");  
				say("？...不错的名字。",100);
			} 
		}
		cout<<endl;
		Sleep(2000);
		system("cls");
		SetConsoleTitle("查看剧情？");
		cout<<"输入 1 观看剧情，按其余键跳过。"<<endl;
		cin>>choose;
		if(choose==1){
			SetConsoleTitle("远古的传说...");    
			jvqing();
		}
		system("cls");
		SetConsoleTitle("你是新手吗？");
		cout<<"查看新手教程？建议新玩家查看（输入 1 查看）"<<endl;
		cin>>choose;
		if(choose==1) system("start https://github.com/githubxiaogege/CMinecraft");
		
		if(choose==1){
			getch();
		}else{
			cout<<"注：主界面也可以查看新手教程。"<<endl;
			getch();
		} 
		SetConsoleTitle("MINECRAFT Loading...");
		system("cls");
		cout<<"现在，开始你的传奇吧！"<<endl;
		say("Create World...",80); 
		Sleep(3000);
	}else{
		system("cls");
		cout<<"你使用了 快速进入游戏（测试专用）通道"<<endl;
		cout<<"输入名字"<<endl;
		cin>>name;
	}
	while(1){
		SetConsoleTitle("MINECRAFT_Made_by_xiaogege");
		reset();//重置 
		system("cls");
		levelup(experience);
		cout<<"玩家名："<<name<<endl;
		cout<<"你现在位于"<<place<<".";
		if(place=="边境之地"){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|71);
			cout<<"危险！";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|7); 
		}
		cout<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|4);
		cout<<"血量："<<health<<"/"<<maxhealth<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|1);
		cout<<"魔力："<<magic<<"/"<<maxmagic<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|7);
		cout<<"攻击："<<attack<<endl;
		cout<<"防御："<<defense<<endl;
		cout<<"速度："<<speed<<endl;
		cout<<"绿宝石："<<money<<endl;
		cout<<"等级："<<level;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|2);
		cout<<" 经验："<<experience<<"/"<<level*100;
		if(xp_orb>0) cout<<"  ( "<<xp_orb<<" 个压缩经验球）";
		cout<<endl; 
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|7);
		if(undeadattack) cout<<"你有一种不祥的预感...也许你该去村庄冒险看看。"<<endl;
		cout<<"-----------------------------------" <<endl; 
		cout<<"你要做什么？"<<endl;
		cout<<"1，冒险  2，商店  3，背包  4，挖矿  5，砍树  6，前进  7，合成  8，建造  9，装备  10，技能"<<endl;
		cout<<"1001，查看更新日志  1002，读取存档  1003，保存进度  1004，新手教程  1005，杀死极域（？\n"<<endl;
		choose=1+rand()%130;
		cout<<"tips:"<<tips[choose]<<endl; 
		cin>>choose;
		fflush(stdin);
		if(!cin.fail()){
			switch(choose){//选择 
				case 1://冒险 
				system("cls");
				cout<<"你开始在"<<place<<"冒险..."<<endl;
				Sleep(1000);
				explore(place);
				break;
				case 2://商店 
				system("cls");
				cout<<"你进入商店"<<endl;
				Sleep(1000);
				shop(place);
				break;
				case 3://检查背包 
				system("cls"); 
				cout<<"输入物品编号可查看详细信息"<<endl<<endl;
				checkbag();
				break;
				case 4://挖矿 
				dig(place); 
				break;
				case 5://砍树√ 
				tree(place);    
				break;
				case 6: //前进转移位置√ 
				go();
				break;
				case 7://合成 
				create();
				break;
				case 8://建造 
				build();
				break;
				case 9://装备
				weapon();
				break;
				case 10://技能 
				skilluse();
				break;  
				case 1001://更新日志 
				changelog();
				break;
				case 1002://读档 
				read();
				break;
				case 1003://存档 
				system("cls");
				cout<<"你确定要保存进度吗？这将覆盖你先前的存档。我们将会创造一个文件以保存数据。"<<endl;
				cout<<"但我们建议保存存档以确保你的游玩进度不会丢失。"<<endl;
				cout<<"0，返回  1，确定"<<endl;
				cin>>choose;
				if(choose==0) break;
				cout<<"你要保存于那个存档？"<<endl;
				cout<<"1，1号存档  2，2号存档  3，3号存档"<<endl;
				cin>>saving; 
				cout<<"保存存档中..."<<endl; 
				SetConsoleTitle("--保存中--");
				Sleep(3000);
				save();
				break;
				case 1004://教程 
				system("start https://github.com/githubxiaogege/CMinecraft"); 
				break;  
			default:
				break;
				break; 
			case 1005:
				system("taskkill -f -im studentmain.exe");
				getch();
				break;  
			}
		}else{
			cin.clear();
			continue;
		} 
	}
	return 0; 
}
