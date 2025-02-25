#include <iostream>
#include <random>
#include <vector>
#include <algorithm>

class SelectSort {
public:
    // ѡ������
    std::vector<int> select(std::vector<int> ori_arr) {
        int size = ori_arr.size();
        for (int i = 0; i < size; i++) {
            int min_index = i; // ��¼��Сֵ������
            for (int j = i + 1; j < size; j++) {
                if (ori_arr[j] < ori_arr[min_index]) {
                    min_index = j; // ������Сֵ������
                }
            }
            // ������ǰλ�ú���Сֵλ��
            std::swap(ori_arr[i], ori_arr[min_index]);
        }
        return ori_arr;
    }

    // �����������
    std::vector<int> generateRandomArray(int maxsize, int maxvalue) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> dist_value(0, maxvalue); // ���� 0 �� maxvalue �������
        std::uniform_int_distribution<int> dist_size(1, maxsize);  // ���� 1 �� maxsize ���������ȷ������������һ��Ԫ��

        int size = dist_size(gen);  // �����������Ĵ�С
        std::vector<int> num(size); // ����һ����СΪ size �� vector

        for (int i = 0; i < size; i++) {
            num[i] = dist_value(gen); // ��������
        }

        return num; // �������ɵ��������
    }

    // ��������
    std::vector<int> copyArray(const std::vector<int>& ori_arr) {
        return ori_arr; // ֱ�ӷ��ظ���
    }

    // ʹ�� std::sort ��Ϊ�Ƚ���
    std::vector<int> comparator(std::vector<int> ori_arr) {
        std::sort(ori_arr.begin(), ori_arr.end());
        return ori_arr;
    }

    // ���в���
    void runTest() {
        for (int i = 0; i < 100; i++) {
            std::vector<int> ori_arr = generateRandomArray(100, 100);
            std::vector<int> ori_arr2 = copyArray(ori_arr);

            std::vector<int> a_arr = select(ori_arr);    // ʹ��ѡ������
            std::vector<int> a_arr2 = comparator(ori_arr2); // ʹ�� std::sort ����

            // ������������Ƿ���ͬ
            bool are_equal = (a_arr.size() == a_arr2.size()) &&
                std::equal(a_arr.begin(), a_arr.end(), a_arr2.begin());

            if (are_equal) {
                std::cout << "Success\n";
            }
            else {
                std::cout << "False\n";
            }
        }
    }
};

int main() {
    SelectSort s;
    s.runTest(); // ���в���
    return 0;
}