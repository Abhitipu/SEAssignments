import java.util.*;

public class SocialNetwork{
	public static void main(String[] args) {
		
		ArrayList<Individual> ind = new ArrayList<>();
		ArrayList<Group> grp = new ArrayList<>();
		ArrayList<Business> bus = new ArrayList<>();
		ArrayList<Organization> org = new ArrayList<>();
		Set<Integer> ids = new HashSet<>();
		
		Scanner fs = new Scanner(System.in);
		
		boolean done = false;
		while(done == false) {
			System.out.println();
			System.out.println("Enter: ");
			System.out.println("1 for creating a new account.");
			System.out.println("2 for deleting an account.");
			System.out.println("3 for searching for an account.");
			System.out.println("4 for printing linked accounts to an account.");
			System.out.println("5 creating and posting content.");
			System.out.println("6 for searching for content posted by any account.");
			System.out.println("7 for printing out content posted by accounts linked to any given account.");
			System.out.println("8 for printing out all accounts in the system.");
			System.out.println("9 to quit.");
			
			System.out.print("\nEnter the correct choice (1-9): ");
			
			String j = fs.nextLine();
			System.out.println();
			
			switch(j) {
			
				case "1" : createNewAccount(fs, ind, grp, bus, org, ids);
						   break;
				case "2" : deleteAccount(fs, ind, grp, bus, org, ids);
				 		   break;
				case "3" : search(fs, ind, grp, bus, org);
				 		   break;
				case "4" : printAllLinkedNodes(fs, ind, grp, bus, org, false);
				 		   break;
				case "5" : createNpostContent(fs, ind, grp, bus, org);
		 		 		   break;
				case "6" : searchContent(fs, ind, grp, bus, org);
		 		 		   break;
				case "7" : printAllLinkedNodes(fs, ind, grp, bus, org, true);   // basically the same function works as in case 4, the last parameter ensures that content is printed
		 		 		   break;
				case "8" : printAll(ind, grp, bus, org);
		 		 		   break;
				case "9" : System.out.println("Thank you for tesing this program!");
						   done = true;
		 		 		   break;
				default  : System.out.println("Enter a valid choice!");
			}
		}		
	}
	
	// case "1"
	public static void createNewAccount(Scanner fs, ArrayList<Individual> ind, ArrayList<Group> grp, ArrayList<Business> bus, ArrayList<Organization> org, Set<Integer> ids) {
		
		System.out.println("Follow the steps to create a new account: ");
		
		boolean done = false;
		while(done == false) {
			
			System.out.println("Enter : ");
			System.out.println("1 for Individual account.");
			System.out.println("2 for Group account.");
			System.out.println("3 for Business account.");
			System.out.println("4 for Organization account.");
			
			System.out.print("\nEnter the correct choice (1-4) for the type of account: ");
			
			String j = fs.nextLine();
			System.out.println();
			done = true;
			
			switch(j) {
			
				case "1" : Individual i1 = new Individual(fs, ids);
						 ind.add(i1);
						 break;
				case "2" : Group g = new Group(fs, ids);
						 createLinksToGroup(fs, g, ind, bus);
					     grp.add(g);
				 		 break;
				case "3" : Business b = new Business(fs, ids);
						 createLinksToBusiness(fs, b, ind);
						 bus.add(b);
				 		 break;
				case "4" : Organization o = new Organization(fs, ids);
						 createLinksToOrganization(fs, o, ind);
						 org.add(o);
				 		 break;
				default: System.out.println("Enter a valid choice!");
						 done = false;
			}
		}
	}
	
	public static void createLinksToGroup(Scanner fs, Group g, ArrayList<Individual> ind, ArrayList<Business> bus) {
		System.out.print("Enter the number of individuals to link to this Group: ");
		int n = fs.nextInt();
		fs.nextLine();
		for(int i = 0; i < n; i++) {
			System.out.print("Enter the unique id of the individual: ");
			int t = fs.nextInt();
			fs.nextLine();
			boolean found = false;
			for(Individual in: ind) {
				if(in.uniqueId == t) {
					g.members.add(in);
					found = true;
					break;
				}
			}
			if(!found)
				System.out.println("No matching records found!");
		}
		
		System.out.print("Enter the number of businesses to link to this Group: ");
		n = fs.nextInt();
		fs.nextLine();
		for(int i = 0; i < n; i++) {
			System.out.print("Enter the unique id of the business: ");
			int t = fs.nextInt();
			fs.nextLine();
			boolean found = false;
			for(Business bu: bus) {
				if(bu.uniqueId == t) {
					g.Bmembers.add(bu);
					found = true;
					break;
				}
			}
			if(!found)
				System.out.println("No matching records found!");
		}
	}
	
	public static void createLinksToBusiness(Scanner fs, Business b, ArrayList<Individual> ind) {
		System.out.print("Enter the number of owners to link to this Business: ");
		int n = fs.nextInt();
		fs.nextLine();
		for(int i = 0; i < n; i++) {
			System.out.print("Enter the unique id of the individual: ");
			int t = fs.nextInt();
			fs.nextLine();
			boolean found = false;
			for(Individual in: ind) {
				if(in.uniqueId == t) {
					b.owners.add(in);
					found = true;
					break;
				}
			}
			if(!found)
				System.out.println("No matching records found!");
		}
		System.out.print("Enter the number of customers to link to this Organization: ");
		n = fs.nextInt();
		fs.nextLine();
		for(int i = 0; i < n; i++) {
			System.out.print("Enter the unique id of the individual: ");
			int t = fs.nextInt();
			fs.nextLine();
			boolean found = false;
			for(Individual in: ind) {
				if(in.uniqueId == t) {
					b.customers.add(in);
					found = true;
					break;
				}
			}
			if(!found)
				System.out.println("No matching records found!");
		}
	}
	
	public static void createLinksToOrganization(Scanner fs, Organization o, ArrayList<Individual> ind) {
		System.out.print("Enter the number of individuals to link to this Organization: ");
		int n = fs.nextInt();
		fs.nextLine();
		for(int i = 0; i < n; i++) {
			System.out.print("Enter the unique id of the individual: ");
			int t = fs.nextInt();
			fs.nextLine();
			boolean found = false;
			for(Individual in: ind) {
				if(in.uniqueId == t) {
					o.members.add(in);
					found = true;
					break;
				}
			}
			if(!found)
				System.out.println("No matching records found!");
		}
	}
	
	// Case "2"
	public static void deleteAccount(Scanner fs, ArrayList<Individual> ind, ArrayList<Group> grp, ArrayList<Business> bus, ArrayList<Organization> org, Set<Integer> ids) {
		
		
		System.out.print("Enter the unique ID of the account: ");
		int idx = fs.nextInt();
		fs.nextLine();
		
		for(Individual i: ind) {
			if(i.uniqueId == idx) {
				delIndividual(idx, grp, bus, org);
				ind.remove(i);
				ids.remove(i.uniqueId);
				System.out.println("Deleted");
				return;
			}
		}
		for(Group i : grp) {
			if(i.uniqueId == idx) {
				grp.remove(i);
				ids.remove(i.uniqueId);
				System.out.println("Deleted");
				return;
			}
		}
		for(Business i: bus) {
			if(i.uniqueId == idx) {
				delBusiness(idx, grp);
				bus.remove(i);
				ids.remove(i.uniqueId);
				System.out.println("Deleted");
				return;
			}
		}
		for(Organization i: org) {
			if(i.uniqueId == idx) {
				org.remove(i);
				ids.remove(i.uniqueId);
				System.out.println("Deleted");
				return;
			}
		}
		
		System.out.println("No matching records found");
	}
	
	public static void delIndividual(int uid, ArrayList<Group> grp, ArrayList<Business> bus, ArrayList<Organization> org) {
		for(Group g: grp) {
			for(Individual i : g.members) {
				if(uid == i.uniqueId) {
					g.members.remove(i);
					break;
				}
			}
		}
		for(Business b: bus) {
			for(Individual i : b.owners) {
				if(uid == i.uniqueId) {
					b.owners.remove(i);
					break;
				}
					
			}
			for(Individual i : b.customers) {
				if(uid == i.uniqueId) {
					b.customers.remove(i);
					break;
				}
			}
		}
		for(Organization o: org) {
			for(Individual i : o.members) {
				if(uid == i.uniqueId) {
					o.members.remove(i);
					break;
				}
			}
		}
	}
	
	public static void delBusiness(int uid, ArrayList<Group> grp) {
		for(Group g: grp) {
			for(Business b : g.Bmembers) {
				if(uid == b.uniqueId) {
					g.Bmembers.remove(b);
					break;
				}
			}
		}
	}
	
	// case "3"
	public static void search(Scanner fs, ArrayList<Individual> ind, ArrayList<Group> grp, ArrayList<Business> bus, ArrayList<Organization> org) {
		
		String s;
		System.out.println("Enter : ");
		System.out.println("1 to search by name.");
		System.out.println("2 to search by type.");
		System.out.println("3 to search by birthday.");
		
		s = fs.nextLine();
		String inp;
		
		switch(s) {
			case "1" : System.out.print("Enter name: ");
					 inp = fs.nextLine();
					 SearchByName(inp, ind, grp, bus, org);
					 break;
			case "2" : System.out.print("Enter type(individual/group/business/organization) : ");
					 inp = fs.nextLine();
					 SearchByType(inp, ind, grp, bus, org);
					 break;
			case "3" : System.out.print("Enter birthdate: ");
					 inp = fs.nextLine();
					 SearchByDOB(inp, ind);
					 break;
			default: System.out.println("Incorrect value entered!");
		}
	}
	
	public static void SearchByName(String Name, ArrayList<Individual> ind, ArrayList<Group> grp, ArrayList<Business> bus, ArrayList<Organization> org) {
		
		boolean notFound = true;
		for(Individual i : ind) {
			if(Name.equals(i.name)) {
				if(notFound) {
					System.out.println("Account(s) found: ");
					notFound = false;
				}
				i.print();
			}
		}
		for(Group i : grp) {
			if(Name.equals(i.name)) {
				if(notFound) {
					System.out.println("Account(s) found: ");
					notFound = false;
				}
				i.print();
			}
		}
		for(Business i : bus) {
			if(Name.equals(i.name)) {
				if(notFound) {
					System.out.println("Account(s) found: ");
					notFound = false;
				}
				i.print();
			}
		}
		for(Organization i : org) {
			if(Name.equals(i.name)) {
				if(notFound) {
					System.out.println("Account(s) found: ");
					notFound = false;
				}
				i.print();
			}
		}
		if(notFound)
			System.out.println("No matching records found!");
	}
	
	public static void SearchByDOB(String dob, ArrayList<Individual> ind) {
		
		boolean flag = false;
		for(Individual i : ind) {
			if(i.birthday.equals(dob)) {
				if(!flag)
					System.out.println("Account(s) found: ");
				i.print();
				flag = true;
			}
		}
		if(!flag)
			System.out.println("No matching records found!");
	}
	
	public static void SearchByType(String type, ArrayList<Individual> ind, ArrayList<Group> grp, ArrayList<Business> bus, ArrayList<Organization> org) {
		
		if(type.equals("individual")) {
			if(ind.size() != 0) {
				System.out.println("Account(s) found: ");
				for(Individual i : ind)
					i.print();
			}
			else
				System.out.println("List is empty!");
		}
		else if(type.equals("group")) {
			if(grp.size() != 0) {
				System.out.println("Account(s) found: ");
				for(Group i : grp) 
					i.print();
			}
			else
				System.out.println("List is empty!");
		}
		else if(type.equals("business")) {
			if(bus.size() != 0) {
				System.out.println("Account(s) found: ");
				for(Business i : bus) 
					i.print();
			}
			else
				System.out.println("List is empty!");
		}
		else if(type.equals("organization")) {
			if(org.size() != 0) {
				System.out.println("Account(s) found: ");
				for(Organization i : org) 
					i.print();
			}
			else
				System.out.println("List is empty!");
		}
		else
			System.out.println("No matching records found!");
	}
	
	// Case "4" and "7":
	public static void printAllLinkedNodes(Scanner fs, ArrayList<Individual> ind, ArrayList<Group> grp, ArrayList<Business> bus, ArrayList<Organization> org, boolean forContent) {
		System.out.println("Enter the unique id: ");
		int idx = fs.nextInt();
		fs.nextLine();
		
		for(Individual i: ind) {
			if(i.uniqueId == idx) {
				GetLinksIndividual(idx, grp, bus, org, forContent);
				return;
			}
		}
		for(Group i : grp) {
			if(i.uniqueId == idx) {
				i.GetLinks(forContent);
				return;
			}
		}
		for(Business i: bus) {
			if(i.uniqueId == idx) {
				i.GetLinks(forContent);
				GetLinksBusiness(idx, grp, forContent);
				return;
			}
		}
		for(Organization i: org) {
			if(i.uniqueId == idx) {
				i.GetLinks(forContent);
				return;
			}
		}
		
		System.out.println("No matching records found");
	}
	
	public static void GetLinksIndividual(int uid, ArrayList<Group> grp, ArrayList<Business> bus, ArrayList<Organization> org, boolean forContent) {
		
		boolean flag = true;
		boolean nolinks = true;
		for(Group g: grp) {
			for(Individual i: g.members) {
				if(i.uniqueId == uid) {
					System.out.println();
					if(flag) {
						System.out.println("Groups to this individual is linked (as members): ");
						flag = false;
						nolinks = false;
					}
					g.partialPrint(forContent);
					break;
				}
			}
		}
		
		flag = true;
		for(Business b: bus) {
			for(Individual i: b.owners) {
				if(i.uniqueId == uid) {
					System.out.println();
					if(flag) {
						System.out.println("Businesses to which this individual is linked (as owners): ");
						flag = false;
						nolinks = false;
					}
					b.partialPrint(forContent);
					break;
				}
			}
		}
		
		flag = true;
		for(Business b: bus) {
			for(Individual i: b.customers) {
				if(i.uniqueId == uid) {
					System.out.println();
					if(flag) {
						System.out.println("Businesses to which this individual is linked (as customers): ");
						flag = false;
						nolinks = false;
					}
					b.partialPrint(forContent);
					break;
				}
			}
		}
		
		flag = true;
		for(Organization o: org) {
			for(Individual i: o.members) {
				if(i.uniqueId == uid) {
					System.out.println();
					if(flag) {
						flag = false;
						nolinks = false;
						System.out.println("Organizations to which this individual is linked (as members): ");
					}
					o.partialPrint(forContent);
					break;
				}
			}
		}
		if(nolinks)
			System.out.println("No accounts are linked to this individual account!");
		
	}
	
	public static void GetLinksBusiness(int uid, ArrayList<Group> grp, boolean forContent) {
		
		boolean flag = true;
		for(Group g: grp) {
			for(Business b: g.Bmembers) {
				if(b.uniqueId == uid) {
					if(flag) {
						flag = false;
						System.out.println("Groups to which business is linked: ");
					}
					g.partialPrint(forContent);
					break;
				}
			}
		}
		
		if(flag)
			System.out.println("This Business account is not linked to any group!");
	}
	
	// Case "6"
	public static void createNpostContent(Scanner fs, ArrayList<Individual> ind, ArrayList<Group> grp, ArrayList<Business> bus, ArrayList<Organization> org) {
		System.out.print("Enter the unique ID of the account: ");
		int idx = fs.nextInt();
		fs.nextLine();
		
		for(Individual i: ind) {
			if(i.uniqueId == idx) {
				System.out.println("Enter content to be posted: ");
				String s = fs.nextLine();
				i.content.add(s);
				System.out.println("Content posted!");
				return;
			}
		}
		for(Group i : grp) {
			if(i.uniqueId == idx) {
				System.out.println("Enter content to be posted: ");
				String s = fs.nextLine();
				i.content.add(s);
				System.out.println("Content posted!");
				return;
			}
		}
		for(Business i: bus) {
			if(i.uniqueId == idx) {
				System.out.println("Enter content to be posted: ");
				String s = fs.nextLine();
				i.content.add(s);
				System.out.println("Content posted!");
				return;
			}
		}
		for(Organization i: org) {
			if(i.uniqueId == idx) {
				System.out.println("Enter content to be posted: ");
				String s = fs.nextLine();
				i.content.add(s);
				System.out.println("Content posted!");
				return;
			}
		}
		
		System.out.println("No matching records found");
	}
	
	// Case "6"
	public static void searchContent(Scanner fs, ArrayList<Individual> ind, ArrayList<Group> grp, ArrayList<Business> bus , ArrayList<Organization> org) {
		System.out.print("Enter the unique ID of the account: ");
		int idx = fs.nextInt();
		fs.nextLine();
		
		for(Individual i: ind) {
			if(i.uniqueId == idx) {
				System.out.println("\nAccount Found");
				i.printContent();
				return;
			}
		}
		for(Group i : grp) {
			if(i.uniqueId == idx) {
				System.out.println("\nAccount Found");
				i.printContent();
				return;
			}
		}
		for(Business i: bus) {
			if(i.uniqueId == idx) {
				System.out.println("\nAccount Found");
				i.printContent();
				return;
			}
		}
		for(Organization i: org) {
			if(i.uniqueId == idx) {
				System.out.println("\nAccount Found");
				i.printContent();
				return;
			}
		}
		
		System.out.println("No matching records found");
	}
	
	// Case "8" :
	public static void printAll(ArrayList<Individual> ind, ArrayList<Group> grp, ArrayList<Business> bus , ArrayList<Organization> org) {
		System.out.println("\nDisplaying all accounts:\n");
		if(ind.size() != 0) {
			System.out.println("Individuals :\n");
			for(Individual i: ind) {
				i.print();
				System.out.println("");
			}
		}
		if(grp.size() != 0) {
			System.out.println("Groups: ");
			for(Group g: grp) {
				g.print();
				System.out.println("");
			}
		}
		if(bus.size() != 0) {
			System.out.println("Businesses: ");
			for(Business b: bus) {
				b.print();
				System.out.println("");
			}	
		}
		if(org.size() != 0) {
			System.out.println("Organizations: ");
			for(Organization o: org) {
				o.print();
				System.out.println("");
			}
		}
	}
	
}

class User {
	public int uniqueId;
	public String name;
	public String date;
	public Set<String> content;
	
	User(Scanner fs, Set<Integer> ids) {
		boolean ok = false;
		while(!ok) {
			System.out.print("Enter the user Id: ");
			uniqueId = fs.nextInt();
			fs.nextLine();
			if(ids.contains(uniqueId)) {
				System.out.println("This ID has already been used! Try another id!\n");
			}
			else {
				ok = true;
				ids.add(uniqueId);
			}
		}
		System.out.print("Enter the name: ");
		name = fs.nextLine();
		System.out.print("Enter the date: " );
		date = fs.nextLine();
		content = new HashSet<>();
	}
	
	void print() {     // Prints everything
		System.out.println("ID: " + uniqueId);
		System.out.println("Name: " + name);
		System.out.println("Creation date: " + date);
		printContent();
	}
	
	void partialPrint(boolean forContent) {    // this is for the linked nodes: printing their basic info / content posted
		System.out.println("ID: " + uniqueId);
		if(forContent) {
			printContent();
			return;
		}
		System.out.println("Name: " + name);
	}
	
	void printContent() {        // utility function for printing the content posted by the user
		if(content.size() == 0) {
			System.out.println("No content posted yet!");
			return;
		}
		
		System.out.println("Content posted by the user: ");
		for(String s: content)
			System.out.println(s);
	}
}

class Individual extends User { 
	String birthday;
	
	Individual(Scanner fs, Set<Integer> ids) {
		super(fs, ids);
		System.out.print("Do you wish to enter birthday (1 for yes and 0 for No)? : ");     // since entering the birthday is optional
		String j = fs.nextLine();
		
		if(j.equals("1")) {
			System.out.print("Enter the birthday: ");
			this.birthday = fs.nextLine();
		}
		else
			this.birthday = "-1";
	}
	
	void print() {
		super.print();
		if(!birthday.equals("-1"))
			System.out.println("Birthday : "+ birthday);
		else
			System.out.println("Birthday: Not Given");
	}
	
	void partialPrint(boolean forContent) {
		super.partialPrint(forContent);
	}
}

class Group extends User {
	public ArrayList<Individual> members;
	public ArrayList<Business> Bmembers;
	
	Group (Scanner fs, Set<Integer> ids) {
		super(fs, ids);
		members = new ArrayList<>();
		Bmembers = new ArrayList<>();
	}
	void AddMember(Individual i) {
		members.add(i);
	}
	
	void AddBusiness(Business b) {
		Bmembers.add(b);
	}
	
	void GetLinks(boolean forContent) {
		if(members.size() != 0) {
			System.out.println("Linked individuals as members: ");
			for(Individual in : members) 
				in.partialPrint(forContent);
		}
		
		if(Bmembers.size() != 0) {
			System.out.println("Linked businesses as members: ");
			for(Business in : Bmembers) 
				in.partialPrint(forContent);
		}
	}
	
	void print() {
		super.print();
	}
	
	void partialPrint(boolean forContent) {   // used for printing some details only
		super.partialPrint(forContent);
	}
}

class Organization extends User {
	public ArrayList<Individual> members;
	int xCord, yCord;
	
	Organization (Scanner fs, Set<Integer> ids) {
		super(fs, ids);
		members = new ArrayList<>();
		System.out.println("Enter the coordinates: ");
		xCord = fs.nextInt();
		yCord = fs.nextInt();
		fs.nextLine();
	}
	
	void AddMember(Individual i) {
		members.add(i);
	}
	
	void GetLinks(boolean forContent) {
		if(members.size() != 0) {
			System.out.println("Individuals linked to this group (as members): ");
			for(Individual i: members)
				i.partialPrint(forContent);
		}
		else
			System.out.println("No Individuals are linked to this Organizaton!");
	}
	
	void print() {
		super.print();
		System.out.println("Coordinates: [" + xCord + ", "+ yCord + "]");
	}
	void partialPrint(boolean forContent) {    // used for printing some details only
		super.partialPrint(forContent);
	}
}

class Business extends User { 
	int xCord, yCord;
	public ArrayList<Individual> owners;
	public ArrayList<Individual> customers;
	
	Business (Scanner fs, Set<Integer> ids) {
		super(fs, ids);
		owners = new ArrayList<>();
		customers = new ArrayList<>();
		System.out.println("Enter the coordinates: ");
		xCord = fs.nextInt();
		yCord = fs.nextInt();
		fs.nextLine();
	}
	
	void AddOwner(Individual i) {
		owners.add(i);
	}
	
	void AddCustomer(Individual i) {
		customers.add(i);
	}
	
	void GetLinks(boolean forContent) {
		if(owners.size() != 0) {
			System.out.println("Individuals linked to this business (as owners): ");
			for(Individual i: owners) 
				i.partialPrint(forContent);
		}
		if(customers.size() != 0) {
			System.out.println("Individuals linked to this business (as customers): ");
			for(Individual i : customers)
				i.partialPrint(forContent);
		}
		
		if(customers.size() == 0 && owners.size() == 0) {
			System.out.println("No individuals are linked to this Business account!");
		}
	}
	
	void print() {         
		super.print();
		System.out.println("Coordinates: [" + xCord + ", "+ yCord + "]");
	}
	void partialPrint(boolean forContent) {   // used for printing some details only
		super.partialPrint(forContent);
	}
}