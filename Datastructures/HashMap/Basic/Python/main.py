def main():
    # Use of dict
    contacts = {}
    contacts['abc'] = 81
    contacts['pqr'] = 21
    contacts['xyz'] = 99

    def print_dict():
        for k,v in contacts.items():
            print 'dict[', k, '] = ', v
    
    print("Length of dict is %s" % len(contacts))

    print("Dict contains:")
    print_dict()

    print("Deleting dict[key]:")
    del(contacts['abc'])
    print_dict()

    print("Checking if pqr key is present %r :" % ('pqr' in contacts))
    
    print("Deleting non existant key \'lmn\'")
    try:
        del(contacts['lmn'])
    except KeyError:
        print("Caught error : KeyError:item does not exist")




if __name__ == "__main__":
    main()

