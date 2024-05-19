# General Healthcare Facility Pre-Triage Application

The key points about this module are:
✒ It creates a lineup of patients and issues tickets for them as they arrive at the healthcare facility, categorizing them as either contagion or triage patients.
✒The module is instantiated by loading a data file containing records of patients already in the lineup, allowing it to resume from the previous state.
✒When the module exits, it saves all patient information to a data file, enabling the application to restart in the same state as the last execution by loading this file.

The purpose of creating this Pre-Triage module is to manage the intake and queuing of patients arriving at the healthcare facility in an organized and efficient manner. 
By issuing tickets and categorizing patients, it helps streamline the process of admitting them to the appropriate care centers (contagion test center or triage center). 
The stateful nature of the module, with the ability to save and load patient data, allows for continuity and seamless operation even after the application is restarted.

# Learnings and Skill Development
Working on the "General Healthcare Facility Pre-Triage Application" project has been a valuable learning experience for me.
As I transitioned from C to C++, I gained a deeper understanding of object-oriented programming (OOP) concepts and how they
can be applied to real-world problems.

# Encapsulation and Data Abstraction
✒ One of the key learnings was the importance of encapsulation and data abstraction. By designing classes to represent the different 
entities in the healthcare facility, such as Patients, ContagionPatients, and TriagePatients, I was able to create a more modular 
and maintainable codebase. This allowed me to focus on the specific responsibilities of each class and ensure that the data and 
functionality were properly encapsulated.

# Inheritance and Polymorphism
✒ Additionally, I expanded my knowledge of inheritance and polymorphism. Implementing the ContagionPatient and TriagePatient classes
as derived from the base Patient class helped me understand how to leverage inheritance to create specialized behaviors while 
maintaining a common interface. This, in turn, improved the flexibility and extensibility of the application.
Challenges and Strategies

# Module Architecture
✒ One of the most significant challenges I faced was designing the overall architecture of the application and ensuring that the different
components (e.g., PreTriage module, Contagion Test Center, Triage Center) worked together seamlessly. Coordinating the flow of patients, 
managing the queue, and handling the ticket assignment required careful planning and implementation.

# Strategies 
✒ To overcome this challenge, I employed a combination of strategies. First, I spent time carefully planning the class hierarchy and 
the interactions between the different modules. I created detailed UML diagrams to visualize the relationships and dependencies, 
which helped me identify potential bottlenecks and areas for improvement.
✒ Additionally, I made extensive use of unit testing to validate the correctness of each individual component. By writing comprehensive
test cases, I was able to identify and address issues early in the development process, ensuring that the overall system functioned as expected.
✒ Throughout the project, I also relied on effective debugging techniques, such as strategic use of print statements and the debugger, 
to identify and resolve complex issues. This allowed me to gain a deeper understanding of the underlying logic and make informed decisions 
during the development process.

# Conclusion
The "General Healthcare Facility Pre-Triage Application" project has been a transformative experience for me. It has not only strengthened my
C++ programming skills but also helped me develop a better understanding of object-oriented design principles and their practical application. 
The challenges I faced and the strategies I employed have contributed to my personal growth as a software developer, and I am confident that 
the lessons learned will continue to benefit me in future projects.
