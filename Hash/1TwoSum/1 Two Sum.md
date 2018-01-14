# 1 Two Sum

It is hard for me, although it is in the easy problems. I mean that it can be solved in a brute method, but I prefer the smart method.

* **HashTable**

	* here almostly improve the speed and reduce the running time complexity.

* **Main thought** 

	* every time we encounter a number, we check whether its complementary number in the hash table or not. If the answer is not, we insert it in the hashtable, otherwise we find the solution and output them.

* **Main point** 

	* here we need sort and we choose hashtable **O(1)** average search, insert time.

* **Main problem**

	* we may encounter the negative value, so the hash function should be revised.

	* the element may be duplicate and we need to be careful that the find operation should be revised.

* **Detail** 

	* the size of hashtable I set twice larger than the numSize, only for the performance.
	* I use Quadratic probing to solve the collisions.

