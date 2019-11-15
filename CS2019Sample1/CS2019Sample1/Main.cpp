#include <iostream>
#include <time.h>
using namespace std;
int dice()
{
	return rand() % 6 + 1;
}
int dice(int max)
{
	return rand() % max + 1;
}
int ndice(int max, int times)
{
	int sum = 0;
	for (int i = 0; i < times; i++)
	{
		sum += dice(max);
	}
	return sum;
}
class Character
{
public:
	const char* name;
	int HP = 0;
	int AP = 0;
	int DP = 0;
	void showStatus();
	void newCharacter();
	int attack();
	int guard();
};
void Character::newCharacter()
{
	HP = ndice(6, 10);
	AP = ndice(6, 3);
	DP = ndice(6, 3);
}
void Character::showStatus()
{
	cout << name << " : 生命力 " << HP << ", 攻撃力 " << AP << ", 防御力 " << DP << endl;
}
int Character::attack()
{
	return AP + ndice(12, 2);
}
int Character::guard()
{
	return DP + ndice(10, 2);
}
int battle(Character C1, Character C2)
{
	int damage1 = 0, damage2 = 0;
	for (int turn = 1; turn > 0; turn++)
	{
		getchar();
		cout << turn << "ターン" << endl;
		damage2 = C1.attack() - C2.guard();
		damage1 = C2.attack() - C1.guard();
		if (damage2 > 0)
		{
			C2.HP -= damage2;
			cout << C1.name << "の攻撃!　" << damage2 << "ポイントのダメージを与えた" << endl;
		}
		else
		{
			damage2 = 0;
			cout << C1.name << "の攻撃!　ミス、ダメージを与えられない" << endl;
		}
		if (damage1 > 0)
		{
			C1.HP -= damage1;
			cout << C2.name << "の攻撃!　" << damage1 << "ポイントのダメージを受けた" << endl;
		}
		else
		{
			damage1 = 0;
			cout << C2.name << "の攻撃!　ミス、ダメージを受けない" << endl;
		}
		if (C1.HP > 0 && C2.HP <= 0)
		{
			cout << "勝利！" << endl;
			return 1;
		}
		else if (C1.HP <= 0 && C2.HP >0)
		{
			cout << "敗北・・・" << endl;
			return 2;
		}
		else if (C1.HP <= 0 && C2.HP <= 0)
		{
			return 0;
		}
		cout << C1.name << "生命力 " << C1.HP << "： " << C2.name << "生命力 " << C2.HP << endl;
	}
}
int main()
{
	srand(time(NULL));
	int OKflag = 0;
	int result = 0;
	Character player, enemy;
	player.name = "プレイヤー";
	enemy.name = "モンスター";
	enemy.newCharacter();
	while (OKflag == 0)
	{
		player.newCharacter();
		cout << "キャラクターを作成しました" << endl;
		player.showStatus();
		cout << "このキャラクターでOKですか？ (OK=1, NO=0)" << endl;
		cin >> OKflag;
		getchar();
	}
	enemy.showStatus();
	cout << "戦闘開始！" << endl;
	battle(player, enemy);
	getchar();
	return 0;
}