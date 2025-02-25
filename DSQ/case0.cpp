#include <iostream>
#include <random>
#include <vector>
#include <algorithm>

class SelectSort {
public:
    // 选择排序
    std::vector<int> select(std::vector<int> ori_arr) {
        int size = ori_arr.size();
        for (int i = 0; i < size; i++) {
            int min_index = i; // 记录最小值的索引
            for (int j = i + 1; j < size; j++) {
                if (ori_arr[j] < ori_arr[min_index]) {
                    min_index = j; // 更新最小值的索引
                }
            }
            // 交换当前位置和最小值位置
            std::swap(ori_arr[i], ori_arr[min_index]);
        }
        return ori_arr;
    }

    // 生成随机数组
    std::vector<int> generateRandomArray(int maxsize, int maxvalue) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> dist_value(0, maxvalue); // 生成 0 到 maxvalue 间的整数
        std::uniform_int_distribution<int> dist_size(1, maxsize);  // 生成 1 到 maxsize 间的整数，确保数组至少有一个元素

        int size = dist_size(gen);  // 随机生成数组的大小
        std::vector<int> num(size); // 创建一个大小为 size 的 vector

        for (int i = 0; i < size; i++) {
            num[i] = dist_value(gen); // 填充随机数
        }

        return num; // 返回生成的随机数组
    }

    // 复制数组
    std::vector<int> copyArray(const std::vector<int>& ori_arr) {
        return ori_arr; // 直接返回副本
    }

    // 使用 std::sort 作为比较器
    std::vector<int> comparator(std::vector<int> ori_arr) {
        std::sort(ori_arr.begin(), ori_arr.end());
        return ori_arr;
    }

    // 运行测试
    void runTest() {
        for (int i = 0; i < 100; i++) {
            std::vector<int> ori_arr = generateRandomArray(100, 100);
            std::vector<int> ori_arr2 = copyArray(ori_arr);

            std::vector<int> a_arr = select(ori_arr);    // 使用选择排序
            std::vector<int> a_arr2 = comparator(ori_arr2); // 使用 std::sort 排序

            // 检查两个数组是否相同
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
    s.runTest(); // 运行测试
    return 0;
}