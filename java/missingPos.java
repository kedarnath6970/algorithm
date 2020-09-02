
class MissingPos {

    static int segregate(int array[], int size) {

        int j = 0;
        for (int i = 0; i < size; i++) {
            if (array[i] <= 0) {
                int temp;
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
                j++;
            }
        }
        return j;
    }

    static int findMissingPositive(int array[], int size) {

        for (int i = 0; i < size; i++) {
            int x = Math.abs(array[i]);
            if (x - 1 < size && array[x - 1] > 0)
                array[x - 1] = -array[x - 1];
        }

        for (int i = 0; i < size; i++) {
            if (array[i] > 0)
                return i + 1;
        }

        return size + 1;
    }

    static int findMissing(int array[], int size) {
    
        int shift = segregate(array, size);
        int array2[] = new int[size - shift];
        int j = 0;
        for (int i = shift; i < size; i++) {
            array2[j] = array[i];
            j++;
        }
        return findMissingPositive(array2, j);
    }    

    public static void main(String args[]) {
    
        int array[] = {0, 10, 2, -10, -20};
        int size = 5;
        int missing = findMissing(array, size);
        System.out.println("The smallest positive missing number is " + missing);
    }
}
