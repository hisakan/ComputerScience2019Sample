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
	cout << name << " : ������ " << HP << ", �U���� " << AP << ", �h��� " << DP << endl;
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
		cout << turn << "�^�[��" << endl;
		damage2 = C1.attack() - C2.guard();
		damage1 = C2.attack() - C1.guard();
		if (damage2 > 0)
		{
			C2.HP -= damage2;
			cout << C1.name << "�̍U��!�@" << damage2 << "�|�C���g�̃_���[�W��^����" << endl;
		}
		else
		{
			damage2 = 0;
			cout << C1.name << "�̍U��!�@�~�X�A�_���[�W��^�����Ȃ�" << endl;
		}
		if (damage1 > 0)
		{
			C1.HP -= damage1;
			cout << C2.name << "�̍U��!�@" << damage1 << "�|�C���g�̃_���[�W���󂯂�" << endl;
		}
		else
		{
			damage1 = 0;
			cout << C2.name << "�̍U��!�@�~�X�A�_���[�W���󂯂Ȃ�" << endl;
		}
		if (C1.HP > 0 && C2.HP <= 0)
		{
			cout << "�����I" << endl;
			return 1;
		}
		else if (C1.HP <= 0 && C2.HP >0)
		{
			cout << "�s�k�E�E�E" << endl;
			return 2;
		}
		else if (C1.HP <= 0 && C2.HP <= 0)
		{
			return 0;
		}
		cout << C1.name << "������ " << C1.HP << "�F " << C2.name << "������ " << C2.HP << endl;
	}
}
int main()
{
	srand(time(NULL));
	int OKflag = 0;
	int result = 0;
	Character player, enemy;
	player.name = "�v���C���[";
	enemy.name = "�����X�^�[";
	enemy.newCharacter();
	while (OKflag == 0)
	{
		player.newCharacter();
		cout << "�L�����N�^�[���쐬���܂���" << endl;
		player.showStatus();
		cout << "���̃L�����N�^�[��OK�ł����H (OK=1, NO=0)" << endl;
		cin >> OKflag;
		getchar();
	}
	enemy.showStatus();
	cout << "�퓬�J�n�I" << endl;
	battle(player, enemy);
	getchar();
	return 0;
}