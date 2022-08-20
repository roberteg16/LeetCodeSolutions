class Solution {
public:
  std::vector<int> memLeak(int memory1, int memory2) {
    int i = 1;
    while (true) {
      if (memory1 < i && memory2 < i) {
        return {i, memory1, memory2};
      }

      int &memoryToDoReservation = memory1 >= memory2 ? memory1 : memory2;
      memoryToDoReservation -= i;
      i++;
    }
  }
};