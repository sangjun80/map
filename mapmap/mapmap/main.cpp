// ** ContainerMap v0.1
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <list>

using namespace std;


	struct Vector3
	{
		float x, y, z;

		Vector3() : x(0.0f), y(0.0f), z(0.0f) {};
		Vector3(const float _x, const float _y) : x(_x), y(_y), z(0.f) {};
		Vector3(const float _x, const  float _y, const  float _z)
			: x(_x), y(_y), z(_z) {};

	};

	struct Trasnform
	{
		Vector3 Position;
		Vector3 Rotation;
		Vector3 Scale;

	};

	struct Object
	{
		Trasnform Info;

		Object() {};
		Object(const Trasnform& _Info) : Info(_Info) {};
	};

	struct Player : public Object
	{
		Player() {};

		Player(const Trasnform& _Info) : Object(_Info) {};

	};

	map <string, list<Object*>> Objects;

	void Initialize();
	void AddObject(string _key, Object* _Object);

int main(void)
{
	/*
	map<int, int> Numbers;
	// ** Key, Value
	//map<int, int>
	Numbers[0] = 1;
	Numbers[1] = 2;
	Numbers[2] = 3;
	Numbers[3] = 4;
	Numbers[4] = 5;
	*/

	/*
	map<string, int> Numbers;
	// ** Key, Value
	//map<int, int>
	Numbers["A"] = 1;
	Numbers["B"] = 2;
	Numbers["C"] = 3;
	Numbers["D"] = 4;
	Numbers["E"] = 5;
	//for (map<string, int>::iterator iter = Numbers.begin();
	//	iter != Numbers.end(); ++iter)
	//{
	//	cout << iter->first << endl;
	//	cout << iter->second << endl << endl;
	//}
	for (auto iter = Numbers.begin(); iter != Numbers.end(); ++iter)
	{
		cout << iter->first << endl;
		cout << iter->second << endl << endl;
	}
	*/

	/*
	enum Key { AAA, BBB, CCC, DDD, EEE };
	const int Max = 10;
	int max = 10;
	Key _State = AAA;
	int Array[EEE];
	cout << Array[_State] << endl;
	*/
	
	Trasnform Info;

	Info.Position.x = 10;
	Info.Position.y = 20;
	Info.Position.z = 30;


	//Initialize();
	AddObject("Player", new Player);
	//cout << Objects["Player"]->Info.Position.x << endl;
	//cout << Objects["Player"]->Info.Position.y << endl;
	//cout << Objects["Player"]->Info.Position.z << endl;
	
	//cout << iter->second << endl;



	return 0;
}


	/* 
	enum Key
	{
		Player,
		Enemy,
		Bullet,
		Max,
	};

	const int MaxObject = 128;

	int Array[Max][MaxObject];

	for (int i = 0; i < Max; ++i)
	{
		for (int j = 0; j < MaxObject; ++j)
		{
			Array[i][j] = j;
		}
	}

	for (int i = 0; i < MaxObject; ++i)
		cout << Array[Enemy][i] << endl;
	*/


void Initialize()
{
	Trasnform Info;

	Info.Position.x = 10;
	Info.Position.y = 20;
	Info.Position.z = 30;

	//Objects["Player"] = new Player(Info);
}

void AddObject(string _key, Object* _Object)
{
	map<string, list<Object*>>::iterator iter = Objects.find(_key);

	if (iter == Objects.end())
	{
		list<Object*> Temp;
		Temp.push_back(_Object);
		Objects.insert(make_pair(_key, Temp));

	}
	else
		iter->second.push_back(_Object);
}
