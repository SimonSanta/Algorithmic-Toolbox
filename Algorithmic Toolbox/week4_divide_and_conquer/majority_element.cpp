#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

int countFreq(const vector<int> &a, int left, int right, int elem)
{
	int count = 0;
	for (unsigned int i = left; i <= right; i++)
	{
		if (a[i] == elem)
		{
			count++;
		}
	}
	     return count;
}

// Check : https://www.enjoyalgorithms.com/blog/find-the-majority-element-in-an-array (section 3)
int get_majority_element(vector<int> &a, int left, int right) {

	// Solving the problem using divide and conquer
    // Checking the subtrees for a majority element recursively
    // Complexity is O(nlog(n))

	if (left > right) return -1;
	if (left == right) return a[left]; // base case

	int mid = left + (right - left) / 2;

	int leftMaj = get_majority_element(a, left, mid);
	int rightMaj = get_majority_element(a, mid + 1, right);

	if (leftMaj == -1 && rightMaj != -1)
	{
		int freq = countFreq(a, left, right, rightMaj);
		if (freq > (right - left + 1) / 2)
		{
			return rightMaj;
		}
		else
		{
			return -1;
		}

	}
	if (leftMaj != -1 && rightMaj == -1)
	{
		int freq = countFreq(a, left, right, leftMaj);
		if (freq > (right - left + 1) / 2)
		{
			return leftMaj;
		}
		else
		{
			return -1;
		}

	}
	if (leftMaj != -1 && rightMaj != -1)
	{
		int leftFreq = countFreq(a, left, right, leftMaj);
		int rightFreq = countFreq(a, left, right, rightMaj);

		if (leftFreq > (right - left + 1) / 2)
		{
			return leftMaj;
		}
		else if (rightFreq > (right - left + 1) / 2)
		{
			return rightMaj;
		}
		else
		{
			return -1;
		}
	}
	return -1;
}


int main() {
	int n;
	std::cin >> n;
	vector<int> a(n);
	for (size_t i = 0; i < a.size(); ++i) {
		std::cin >> a[i];
	}
	std::cout << (get_majority_element(a, 0, a.size() - 1) != -1) << '\n';
}