#include<iostream>
using namespace std;

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define BOLD    "\033[1m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define BLACK       "\033[30m"
#define BOLD_BLACK  "\033[1m\033[30m"
#define BOLD_RED    "\033[1m\033[31m"
#define BOLD_GREEN  "\033[1m\033[32m"
#define BOLD_YELLOW "\033[1m\033[33m"
#define BOLD_BLUE   "\033[1m\033[34m"
#define BOLD_MAGENTA "\033[1m\033[35m"
#define BOLD_CYAN   "\033[1m\033[36m"
#define BOLD_WHITE  "\033[1m\033[37m"
#define BRIGHT_BLACK        "\033[90m"
#define BRIGHT_RED          "\033[91m"
#define BRIGHT_GREEN        "\033[92m"
#define BRIGHT_YELLOW       "\033[93m"
#define BRIGHT_BLUE         "\033[94m"
#define BRIGHT_MAGENTA      "\033[95m"
#define BRIGHT_CYAN         "\033[96m"
#define BRIGHT_WHITE        "\033[97m"

void intro()
{
    cout <<BOLD_WHITE<< "----------------------------------------------------------------------------------------------------------" <<RESET<< endl;
    cout<<BRIGHT_CYAN<<"DAIICT was created as one of the most advanced institute in 2001 which believes in overall development. Along with academics"
    <<"the focus is also on co-curricular activities. As a part of this, DA-IICT has also many clubs that allows students to enhance"
    <<"their skills and hobbies along with academics. The clubs at DAIICT works to provide platform for students to showcase their"
    <<"talent and skills regarding their hobbies. One of our oldest and most prominent events at DAIICT is Synapse."
    <<"Synapse is a celebration - a celebration of culture, technology and life. It is about realizing the underlying inherent" 
    <<"junction of the three in an electrifying atmosphere. Similarly, through exciting workshops, impressive events, and "
    <<"mesmerizing pro-nights, other clubs and their events are a medium through which the youth can express their views; be it through art," 
    <<"culture, technological skills, knowledge or entertainment.  It also promotes various cultural activities like music, "
    <<"drama and dance amongst the student community. LETS GET A SNEEK-PEEK OF CLUBS"<<RESET<<endl;

    cout<<BRIGHT_CYAN<<"--AI Club--"<<RESET<<endl;
    cout<<"Started in 2020, it aims to educate others about AI.EVENT: i.Prompt, Prompt-A-Thon to create AI framework."<<endl;

    cout<<BRIGHT_CYAN<<"--Press Club--"<<RESET<<endl;
    cout<<"Started in 2010, it is the main journalism cell of DAIICT. EVENT: Comic Carnival: A Comic Making Challenge. and Entelechy-the student run magazine of DA"<<endl;

    cout<<BRIGHT_CYAN<<"--Debate Club--"<<RESET<<endl;
    cout<<"We are a group of people who believe in the power of words to bring change, who promote discussion.EVENT: Parliamentary Debates to enhance knowledge and dissent"<<endl;

    cout<<BRIGHT_CYAN<<"--Dance Club--"<<RESET<<endl;
    cout<<"Dance Club or DADC as it is known, tries to cater the dancing instincts of students. EVENT: WALTZ to electrify the atmosphere"<<endl;

    cout<<BRIGHT_CYAN<<"--DCEI Club--"<<RESET<<endl;
    cout<<"We are DA-IICT Centre for Entrepreneurship and Incubation. EVENT: SellOut, to show business skills"<<endl;

    cout<<BRIGHT_CYAN<<"--Music Club--"<<RESET<<endl;
    cout<<"We aim to develop an interest in students towards music and create a healthy music atmosphere. EVENT: RAAGA AND RHAPSODY"<<endl;

    cout<<BRIGHT_CYAN<<"--DTG Club--"<<RESET<<endl;
    cout<<"DAIICT Theatre Group is a club that conducts and administers theatrics events of DAIICT.EVENT: Rangmanch - The Drama Night"<<endl;

    cout<<BRIGHT_CYAN<<"--Research Club--"<<RESET<<endl;
    cout<<"We aim to work to foster a community within the college for those interested in research.EVENT: i.Papyrus to develop liking for research"<<endl;

    cout<<BRIGHT_CYAN<<"--Chess Club--"<<RESET<<endl;
    cout<<"We focus on enhancing the skills of the students having interest in chess. EVENT: Rapid Chess Contest"<<endl;

    cout<<BRIGHT_CYAN<<"--Sambhav--"<<RESET<<endl;
    cout<<"Sambhav means possible. Sambhav is a group of students with a motive to bring about some positive change in the societyEVENT: Blood Donation "<<endl;

    cout<<BRIGHT_CYAN<<"--Programming Club--"<<RESET<<endl;
    cout<<"We have been working to help people explore their hidden passion for programming. EVENT: Holi Long Programming Contest, to enhance coding skills"<<endl;

    cout<<BRIGHT_CYAN<<"--Film Club--"<<RESET<<endl;
    cout<<"Started in 2011, we are the most celebrated club, the Film Club occupies a special place in every student's heart.EVENT:IPL Screening and Movie Screening to create lifetime memories."<<endl;

    cout<<BRIGHT_CYAN<<"--Developer Student Club--"<<RESET<<endl;
    cout<<"We're a chapter of Google Developer Groups, which has numerous chapters all over the globe. DA-IICT has its own chapter. EVENT: India Regional Bootcamp, to elevate our projects and skills in development"<<endl;

    cout<<BRIGHT_CYAN<<"--Khelaiya Club--"<<RESET<<endl;
    cout<<"Started in 2002, we provide a medium and platform to express through the art of folk dance and thus strives to keep the culture of folk dance alive. EVENT: Garba Night, one of the most memorable events of DAIICT"<<endl;

    cout<<BRIGHT_CYAN<<"--Cubing Club--"<<RESET<<endl;
    cout<<"It is a community by and for people interested in solving Rubik's Cube and its other variants.EVENT: SYNOCUBIX, to give chance to everyone to flaunt their cubing speed."<<endl;

    cout<<BRIGHT_CYAN<<"--WebKit Club--"<<RESET<<endl;
    cout<<"WebKit club is a student community of Web development enthusiasts, interested both in creating and maintaining codes.EVENT: We organize Workshops every semester.."<<endl;

    cout<<BRIGHT_CYAN<<"--Electronics Hobby Centre--"<<RESET<<endl;
    cout<<"Started in 2005, we as a group of enthusiastic electronics' students aim to maintain and grow the culture of electronics in the campus.EVENT: Session on Arduino for freshers and to help them to compete in various electronics contest."<<endl;

    cout<<BRIGHT_CYAN<<"--Heritage Club--"<<RESET<<endl;
    cout<<"We want everyone to experience the inspiration and mysticism in Indian Architectrue.EVENT: Local Visits to enhace the ideas of cultural art form."<<endl;

    cout<<BRIGHT_CYAN<<"--Radio Club--"<<RESET<<endl;
    cout<<"We are a small group of people, who collectively try to emulate the real life radio shows, allowing people to speak their minds and have fun meanwhile.EVENT: Poetry week, to allow diffrent perspectives through the art of poetry."<<endl;

    cout<<BRIGHT_CYAN<<"--Headrush Quizzing Club--"<<RESET<<endl;
    cout<<"Started in 2014, We aim to grow the level of competitive quizzing in campus.EVENT: i.Quiz, where your knowledge is put to test."<<endl;

    cout<<BRIGHT_CYAN<<"--Photography and Movie Making Club--"<<RESET<<endl;
    cout<<"We, as the members of the club, seek to display our love of photography through capturing our college's events and festivals.EVENT: Rolling Shutter, to narrate tales using lens of camera."<<endl;

    cout<<BRIGHT_CYAN<<"--Microsoft Student Club--"<<RESET<<endl;
    cout<<"We, as MSTC, come here and help the curious developers give the right environment to inculcate their ideas and develop for Microsoft. EVENT: Winter Of Code, a chance to learn new tech-stack."<<endl;

    cout<<BRIGHT_CYAN<<"--MUSE Club--"<<RESET<<endl;
    cout<<" Welcome to the Muse Club, where the creative vibes are high and the fun is even higherEVENT: Museliversary, where exciting events happen"<<endl;

    cout<<BRIGHT_CYAN<<"--Business Club--"<<RESET<<endl;
    cout<<"We here try to explore the skills of entrepreneurship in students through sessions and events.EVENT: echai, to ignite business spirit and foster innovation."<<endl;

    cout<<BRIGHT_CYAN<<"--CINS Club--"<<RESET<<endl;
    cout<<"Started in 2023, we are a new bunch of people who are excited about cyber security and related technologies.EVENT: Cyber Samvad, to create awareness about cyber security"<<endl;

    cout<<BRIGHT_CYAN<<"--BIS Club--"<<RESET<<endl;
    cout<<"Started recently in 2022, we collaborate with industry experts, contribute to national standards and gain hands-on experience in emerging fields like robotics.EVENT: Shaping Tomorrow's Sustainability Standards, to learn more about this field."<<endl;

    cout<<BRIGHT_CYAN<<"--IEEE--"<<RESET<<endl;
    cout<<" IEEE's main focus is to foster technological innovation and excellence for the benefit of humanity. EVENT: DAIICT MUN, to give chance to students to learn about ineternaational diplomacy."<<endl;
    
}
