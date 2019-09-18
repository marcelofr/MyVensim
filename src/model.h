#ifndef MODEL_H
#define MODEL_H

#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include "flow.h"
#include "system.h"

using namespace std;

/*!
 * \class Model
 *
 * \brief Class to define the model
 *
 */

class Model
{
protected:
    vector<Flow*> MyFlows; /**< Pointers to the model flow set Flow*/
    vector<System*> MySystems; /**< Pointers to the model system set*/
    int initial, /**< Model initial time*/
        final, /**< Model final time*/
        step; /**< Model step value*/
public:
    Model(int i = 0, int f = 0, int s = 0);
    virtual ~Model();
    Model& operator=(const Model&);
    Model( Model& );
    void Execute();
    void Add(Flow *f);
    void Add(System *s);
    void Report();
    int getInitial() const;
    void setInitial(int value);
    int getFinal() const;
    void setFinal(int value);
    int getStep() const;
    void setStep(int value);
    int SizeMySystems();
    int SizeMyFlows();
};

#endif // MODEL_H
