class Person
{
  public:
  bool isAlive;
  vector<Person*> children;
  string personName;
  
  Person(string name)
  {
    personName = name;
    isAlive = true;
  }
};

class ThroneInheritance {
public:
  Person* king;
  map<string, Person*> family;
  ThroneInheritance(string kingName) 
  {
    king = new Person(kingName);
    family[kingName] = king;
    // cout<<kingName<<" is born.\n";
  }

  void birth(string parentName, string childName) 
  {
    // cout<<"Birth: "<<parentName<<" "<<childName<<".\n";
//     Person* temp = king;
//     Person* foundPerson = searchPerson(king, parentName);
//     // Person* foundPerson = searchPerson(temp, parentName);
//     if(foundPerson)
//     {
      
//       Person* child = new Person(childName);
//       foundPerson->children.push_back(child); 
//       // cout<<childName<<" is born to "<<parentName<<".\n";
//     }
//     else
//     {
//       // cout<<parentName<<" is not found.\n";
//     }
    Person* child = new Person(childName);
    Person* parent = family[parentName];
    parent->children.push_back(child);
    family[childName] = child;
  }

  void death(string name) 
  {
    // // cout<<"Death: "<<name<<".\n";
    // Person* temp = king;
    // Person* foundPerson = searchPerson(king, name);
    // // Person* foundPerson = searchPerson(temp, name);
    // if(foundPerson)
    // {
    //   foundPerson->isAlive = false;
    //   // cout<<name<<" is dead.\n";
    // }
    // else
    // {
    //   // cout<<name<<" is not found.\n";
    // }
    
    Person* person = family[name];
    person->isAlive = false;
  }

  vector<string> getInheritanceOrder() 
  {
    vector<string> order;
    // cout<<"DFS: ";
    Person* temp = king;
    // DFS(temp, order);
    DFS(king, order);
    // cout<<endl;
    return order;
  }
  
  void DFS(Person* currentPerson, vector<string>& order)
  {
    if(!currentPerson)
      return;
    // cout<<currentPerson->personName<<" ";
    if(currentPerson->isAlive)
      order.push_back(currentPerson->personName);
    for(Person* childOfCurrentPerson : currentPerson->children)
    {
      DFS(childOfCurrentPerson, order);
    }
  }
  
  Person* searchPerson(Person* currentPerson, string searchPersonName)
  {
    if(!currentPerson)
      return NULL;
    // cout<<"Search: "<<searchPersonName<<" "<<currentPerson->personName<<endl;
    if((currentPerson->personName == searchPersonName))
    {
      // cout<<"Found";
      return currentPerson; 
    }
    for(Person* childOfCurrentPerson : currentPerson->children)
    {
      if((childOfCurrentPerson->personName == searchPersonName))
        return childOfCurrentPerson;
      Person* foundPerson = searchPerson(childOfCurrentPerson, searchPersonName);
      if(foundPerson)
        return foundPerson;
    }
    return NULL;
  }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */