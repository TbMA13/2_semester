#include <iostream>
#include <vector>
#include <string>

class cipher{
private:
    std::string m_text;
    std::vector <std::string> m_words;
    std::vector <int> m_key;
    std::vector <int> m_fibonachi = {0, 1};

    // ��������� ������������������ ��������
    void generateFibonachi(){
    for (int i = 2; i < m_words.size() + 2; i++){
        m_fibonachi.push_back(m_fibonachi[i - 1] + m_fibonachi[i - 2]);
    }
    }

    // ���������� ������ ����� ���������
    int findFibonachiIndex(int number){
        for (int i = 2; i < m_words.size() + 2; i++){
            if (number == m_fibonachi[i]){
                return i - 2;
            }
        }
        return -1;
    }

public:

    // ���� ������
    void encode(){
    std::cout << "������� �����" << std::endl;
    getline(std::cin, m_text);
    m_text += ' ';
    std::string temp = "";
    for (int i = 0; i < m_text.length(); i++){
        if (m_text[i] != ' '){
            temp += m_text[i];
        }
        else if (temp.length() > 0){
            m_words.push_back(temp);
            temp = "";
        }
    }
    generateFibonachi();
    }

    // ����� ���� � ������������ � ������ �����
    void decode(){
        if (m_words.size() > 30){
            std::cout << "���...\n���-�� ����� �� ���!" << std::endl;
            system("pause");
        }
        bool flag = true;
        std::cout << "������� ������� ����\n������ ����� �� ����� ������" << std::endl;
        int count = 0;
        while (count < m_fibonachi.size() - 2){
            int currentNumber;
            std::cout << "������� �����" << std::endl;
            std::cin >> currentNumber;
            m_key.push_back(currentNumber);
            count++;
            if (findFibonachiIndex(currentNumber) == -1){
                flag = false;
            }
        }
        //TODO �������� �� ������
        if (flag){
            for (int i = 0; i < m_fibonachi.size() - 2; i++){
                std::cout << m_words[findFibonachiIndex(m_key[i])] << " ";
            }
            std::cout << std::endl;
        }
        else{
            std::cout << "���...\n���-�� ����� �� ���!" << std::endl;
        }
    }
};

int main() {
    setlocale(LC_ALL, "Rus");

    cipher first;
    first.encode();
    first.decode();
    system("pause");
}
