#include "QS.h"

void QS::sortAll(){
    quicksort(0, insertCount);
}
void QS::quicksort(int first, int last){
    if(table !=0 && first < last){
        int pivot = medianOfThree(first, last);
        pivot = partition(first, last, pivot);
        quicksort(first, pivot-1);
        quicksort(pivot+1, last);
    } 
    return;
}

	
	int QS::medianOfThree(int left, int right){
        if(left == 0 & right == 0) return -1;
        int size = getSize();
        if(table == 0 || left < 0 || left > size || right  < 0 || right >= size || left >= right) {
            return -1;
        }
        int middle = (left + right)/2;
        int temp;
        while((table[left] > table[middle]) || (table[middle] > table[right])){
            if(table[left] > table[middle]){
                temp = table[left];
                table[left] = table[middle];
                table[middle] = temp;
            }
            if (table[middle] > table[right]){
                temp = table[middle];
                table[middle] = table[right];
                table[right] = temp;
            }
        }
        //cout << left << " " << middle << " " << right << endl;
        return middle;
    }

	
	int QS::partition(int left, int right, int pivotIndex){
        int size = getSize();
        if(table == 0 || pivotIndex < 0 || pivotIndex > size || left < 0 || left > size || right  < 0 || right > insertCount || left >= right || pivotIndex > right) {
            return -1;
        }
        
        int temp = table[pivotIndex];
        table[pivotIndex] = table[left];
        table[left] = temp;
        int up = left+1;
        int down = right;
        do{
            while(((table[up] <= table[left]) && (up < right))){
                up++;
            }
            while((left < down)  && (table[down] > table[left])){
                down--;
            }
            if(up < down){
                temp = table[up];
                table[up] = table[down];
                table[down] = temp;
            }
        }while(up < down);
        temp = table[left];
        table[left] = table[down];
        table[down] = temp;
        return down;
    }

	
	string QS::getArray() const{
        if(!(table == 0 && insertCount < 0)){
            string strTable = "";
            //cout << "\nInsert Count: " << insertCount << endl;
            for(int i = 0; i <= insertCount; i++){
                //cout << "i = " << i << endl;
                //cout << "table[" << i << "] = " << table[i] << endl;
                strTable += to_string(table[i]);
                //cout << "strTable = " << strTable << endl;
                if(i != insertCount){
                    strTable += ",";
                }
            }
            return strTable;
        }
        return "";
    }

	
	int QS::getSize() const{
        return insertCount+1;
    }

	bool QS::addToArray(int value){
        if(!(arraySize-1 <= insertCount)){
            insertCount++;
            table[insertCount] = value;
            return true;
        } else{
            return false;
        }
    }


	bool QS::createArray(int capacity){
        if(table != 0){
            clear();
        }
        if(capacity <= 0){
            return false;
        }
        table = new int[capacity];
        arraySize = capacity;
        return true;
    }

	void QS::clear(){
        delete []table;
        insertCount = -1;
        table = 0;
        arraySize = 0;
        return;
    }