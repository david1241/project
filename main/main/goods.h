#ifndef __GOODSH__
#define __GOODSH__

#include <string>
#include <vector>
#include "date.h"
using namespace std;

enum State {in_warehouse, on_shelf, saled, rejected};
const int statenum = 4;

struct Brand
{
	string name;
	int num;
};

class Goods
{
public:
	Goods();
	Goods(Goods &good);
	~Goods();

	string GetBarcode();
	string GetName();
	string GetReason();
	string GetState();
	Date GetSaleDate();
	
	void NumBasedSort(State state); //ʵ�֡���ѯ���/�ϼ�/�۳�/�˻ص���Ʒ���������������ٵ�N����Ʒ�����Ӵ�С���򡱹���
	void TimeBasedSort(State state); //��ѯ���/�ϼ�ʱ����õ�N����Ʒ������ʱ��ӳ���������
	void ChangeState(State state);//ʵ�ֶ���Ʒ����״̬��Ϣ���޸ģ����ڱ��˻ص���ƷҪ��ӻ��޸��䱻�˻ص�ԭ��

	static vector<Brand> s_inWarehouse;
	static vector<Brand> s_onShelf;
	static vector<Brand> s_saled;
	static vector<Brand> s_rejected;
	static vector<Goods> s_all;

protected:
	string m_barcode;
	string m_name;
	string m_reason;
	State m_state;
	Date m_date[statenum];
	int m_purchasePrice;
	int m_sellingPrice;
};

#endif