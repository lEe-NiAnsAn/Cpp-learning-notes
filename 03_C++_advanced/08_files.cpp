#include<iostream>
using namespace std;
#include<string>
//�ļ�������Ҫ����ͷ�ļ�
#include<fstream>
//ʹ����ʱ���ݲ����ڳ������ʱ���Զ��ͷţ���ͨ���ļ��洢ʵ�ֳ־û�
//1���ı��ļ������ı���ASCII����ʽ�洢
//2���������ļ������ı��Ķ�������ʽ�洢
#pragma region �����ļ������󷽷�
	//ios::in����>Ϊ���ļ�����
	//ios::out����>Ϊд�ļ�����
	//ios::ate����>��ʼλ�ã��ļ�β
	//ios::app����>׷�ӷ�ʽд�ļ�
	//ios::trunc����>���ļ����ڣ���ɾ���󴴽�
	//ios::binary����>�����Ʒ�ʽ
	//ע�⣺�ļ��򿪷�ʽ�����ʹ�ã����á�|��������
	#pragma region һ ofstream:д����
//�ı��ļ�
void test21()
{
	//1������ͷ�ļ���include<fstream>
	//2������������
	ofstream ofs;//��ʹ�� fstream ofs;
	//3��ָ���򿪷�ʽ��(����/���)��·��(�����ļ���)���򿪷�ʽ
	//��δָ��·��(�������ļ���)����Ĭ��Ϊ��.cppͬ�ļ�����
	ofs.open("test21.txt", ios::out);
	//4��д����
	ofs << "test21д�������" << endl;
	ofs << "����һ" << endl;
	ofs << "���ݶ�" << endl;
	ofs << "������" << endl;
	//5���ر��ļ�
	ofs.close();
}
//�������ļ�
class Btext
{
public:
	int m_i;
	char m_c[64];	//ʹ��string�����ڵ�����������ļ�ʱ����
};
void test22()
{
	//1������ͷ�ļ���include<fstream>
	//2������������ + ָ���򿪷�ʽ	
	ofstream ofs("test22.txt", ios::out | ios::binary);
	//3��д����
	Btext b = { 10,"abc" };
	//����ļ�������.write((const char*)&Ŀ�����,Ŀ�곤��);
	//����ǿתΪchar*�͵�ַ,������������ʹ��char����
	ofs.write((const char*)&b,sizeof(Btext));
	//4���ر��ļ�
	ofs.close();
}
	#pragma endregion 

	#pragma region �� ifstream:������
//�ı��ļ�
void test21_1()
{
	//1������ͷ�ļ���include<fstream>
	//2������������
	ifstream ifs;//��ʹ�� fstream ifs;
	//3�����ļ����ж��ܷ��
	ifs.open("test21.txt", ios::in);
	if (!ifs.is_open()) {	//��δ�ɹ���
		cout << "�ļ���ʧ��" << endl;

		return;
	}
	//4��������
	//����һ��ͨ�������������ʶ�ȡ���ַ��б�
	char buf1[1024] = { 0 };	//��������ʼ���ַ����б�
	while (ifs >> buf1) {		//��ȡ���ļ�β�Զ�����false
		cout << buf1 << endl;	//��ʾ��ȡ����
	}

	//��������ͨ�������ļ���������getline��Ա�������ж�ȡ���ַ��б�
	//char buf2[1024] = { 0 };
	//while (ifs.getline(buf2,sizeof(buf2))) {	//�ﵽ��󳤶��Զ�����false
	////����.getline(�ַ��б�,����ȡ����)
	//	cout << buf2 << endl;
	//}

	//��������ͨ��ȫ�ֺ���getline���ж�ȡ���ַ���
	//string buf3;
	////�����ͷ�ļ�#include<string>
	//while (getline(ifs,buf3))	//��ȡ���ļ�β�Զ�����false
	////getline(�����ļ�������,Ŀ���ַ���)
	//{
	//	cout << buf3 << endl;
	//}

	//�����ģ�ͨ�������ļ���������get��Ա�������ַ���ȡ���ַ�����
	//char c;
	//while ((c = ifs.get()) != EOF) {	//EOF��end of file
	//	cout << c;
	//}

	//5���ر��ļ�
	ifs.close();
}
//�������ļ�
void test22_1()
{
	//1������ͷ�ļ���include<fstream>
	//2������������
	ifstream ifs;//��ʹ�� fstream ifs;
	//3�����ļ����ж��ܷ��
	ifs.open("test22.txt", ios::in | ios::binary);
	if (!ifs.is_open()) {	
		cout << "�ļ���ʧ��" << endl;

		return;
	}
	//4��������	//ͨ�������ļ��������ó�Ա����read��ȡ����������
	Btext br;	//��ȡ����ΪBtext���ʴ����������洢��ȡֵ
	ifs.read((char*)&br, sizeof(Btext));
	cout << "test22��m_iΪ" << br.m_i << "\ttest22�е�m_cΪ" << br.m_c << endl;
	//5���ر��ļ�
	ifs.close();
}
	#pragma endregion

	#pragma region �� fstream:��д����
//ͬofstream��ifstream
	#pragma endregion
#pragma endregion

int main()
{
	test21();
	test21_1();
	cout << endl;
	test22();
	test22_1();
	cout << endl;



	system("pause");

	return 0;
}