#include <iostream>
#include <vector>
#include <cmath> // to calculate the euclidean math
#include <set> // to calculate the euclidean math

using namespace std;

/*
    A KNN (k-Nearest Neighbors) Algorithm is a machine learning algorithm where:
    KNN can be used for both classification and regression predictive
    problems. However, it is more widely used in classification problems
    in the industry.

    After calculate the euclidean distance, we must find the k nearest neighbors, and then get the one the repeat more

    The first phase of train is to store the set of train data
    The second phase, calculate the distance and then get the k-nearest neighbors and take the more frequent class

*/


// Class to store data from the dataset.txt

class Object {
private:
    string class_name; // The file has a class name
    double a, b, c, d; // The file has 4 double values

public:

    Object(double a, double b, double c, double d, string class_name) {
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
        this->class_name = class_name;
    }

    // Methods to get attributes
    string getClass_name() {
        return this->class_name;
    }

    double getA() {
        return this->a;
    }

    double getB() {
        return this->b;
    }

    double getC() {
        return this->c;
    }

    double getD() {
        return this->d;
    }
};

// Calculate the euclidean distance made in between two objects O1 and O2
// The euclidean distance is the square root of the sum of the difference of the attributes to the power of two
// X1 = 1, 2, 3;
// X2 = 4, 5, 6;
// sqrt((4 - 1)^2 + (5 - 2)^2 + (6 - 3)^2)

double getEuclideanDistance(Object ob1, Object ob2) {
    double sum = pow((ob1.getA() - ob2.getA()), 2) +
                 pow((ob1.getB() - ob2.getB()), 2) +
                 pow((ob1.getC() - ob2.getC()), 2) +
                 pow((ob1.getD() - ob2.getD()), 2);

    return sqrt(sum); // Return the square root of the sum
}

// function to classify the data
string classify(vector<Object>& object, Object newExample, int k) {
    // If k is even, decrement
    if(k % 2 == 0) {
        k--;
        if(k <= 0)
            k = 1; // When k is 1, it cannot represent well the result
    }

    int size_object_vector = object.size(); // Getting the size of the vector of objects

    // Each pair will have the distance from each object to the newExample and index of the object in the vector
    set<pair<double, int> > dist_objects;

    for(int i = 0; i < size_object_vector; i++) {
        double distance = getEuclideanDistance(object[i], newExample); // Calculating the euclidean distance from each object to the given example object
        dist_objects.insert(make_pair(distance, i)); // Inserting the distance and the index in the set
    }

    // Verify in which class the given example object belongs.

    set<pair<double, int> >::iterator it; // to iterate through the set
    vector<int> count_class(3); // to count the classes
    int contK = 0; // k neighbors;

    for(it = dist_objects.begin(); it != dist_objects.end(); it++) {
        string class_name = object[it->second].getClass_name();
        if(class_name == "Iris-setosa") {
            count_class[0]++;
        } else if (class_name == "Iris-versicolor") {
            count_class[1]++;
        } else { // Iris-virginica
            count_class[2]++;
        }

        if(contK == k) // k neighbors
            break;
        contK++;
    }

    // Get the most frequent class
    string class_classification;
    if(count_class[0] >= count_class[1] && count_class[0] >= count_class[2]) {
        class_classification = "Iris-setosa";
    } else if (count_class[1] >= count_class[0] && count_class[1] >= count_class[2]) {
        class_classification = "Iris-versicolor";
    } else {
        class_classification = "Iris-virginica";
    }

    return class_classification;
}

int main()
{
    // The data will be entered through the cmd
    freopen("dataset.txt", "r", stdin);
    // read data from the txt file
    vector<Object> object;
    int k = 9; // k neighbors
    int size_train = 105; // size of the train process. this process stores the set of data

    string class_name;
    double a, b, c, d;

    for(int i = 0; i < size_train; i++) {
        cin >> a >> b >> c >> d >> class_name;
        object.push_back(Object(a,b,c,d,class_name)); // Insert data in the object vector
    }

    // Amount of right answer
    int right_answer = 0;
    int size_test = 150 - size_train; // Amount of test, 150 is the total of examples - size train

    // last size_test lines from the file
    for (int i = 0; i < size_test; i++) {
        cin >> a >> b >> c >> d >> class_name;
        Object ob(a,b,c,d,class_name);

        string classify_test = classify(object, ob, k);

        cout << "Expected class: " << class_name << endl;
        cout << "Obtained class: " << classify_test << endl;

        if(classify_test == class_name)
            right_answer++;
    }

    cout << "The total of right answers was " << right_answer << " of a total of " << size_test << " tests" << endl;

    return 0;
}
