#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <cassert>

class Hero
{
    public:
        //=== Alias
        enum attribute_t { NUMERIC=0, STRING };
        using attribute = std::pair < std::string, attribute_t >
        enum attribute_id_t { NAME=0, ATTACK, DEFENSE, HEALING, N_ATTRIBUTES };

    public:

        Hero( std::string _n = "" ) : m_name( _n )
        {
            m_attribs.resize( N_ATTRIBUTES );
            m_attribs[NAME] = std::make_pair( n_, STRING );
        }

        void set_attribute( attribute_t _at, std::string _val ) {
            m_attribs[at_] = std::make_pair(val_, NUMERIC );
            if ( at_ == NAME )
                m_attribs[ at_ ].second = STRING;
        }

        int get_attribute( attribute_t _at ) const {
            return m_attribs[ _at ];
        }
        
    private:
        std::vector< attribute > m_attribs; // Stores hero's attributes
        Hero::attribute_t type;
};

std::ostream & operator<< ( std::ostream & _os, const Hero & _h ) {

     _os << "{<" << _h.get_attribute(Hero::NAME) << ">"
                << ", A=" << _h.get_attribute( Hero::attribute_t::ATTACK)
                << ", D=" << _h.get_attribute( Hero::attribute_t::DEFENSE)
                << ", H=" << _h.get_attribute( Hero::attribute_t::HEALING)
                << "}";
    return _os;
}

struct SortingPolicy
{

public:
    enum sorting_order_t {ASCENDING=0, DESCENDING };

private:
    Hero::attribute_t att; //<! atributo na ordenação
    sorting_order_t type; //<! tipo de ordem

public:
    SortingPolicy( Hero::attribute_t a_ = Hero::ATTACK, sorting_order_t t_ = ASCENDING )
        : att(a_)
        , type(t_)
    {/*empty*/}

    void set_order( sorting_order_t so_ )
    {
        type = so_;
    }
    
    bool operator() ( const Hero& a_, const Hero& b_ )
    {
        if ( type == ASCENDING )
            return a_.get_attribute( att ) < b_.get_attribute( att );
        else if ( type == DESCENDING )
            return a_.get_attribute( att ) > b_.get_attribute( att );
        else 
            assert( false );

        return true;       

    }
};
 
int main() {
    std::vector< Hero > heros =
    {
        Hero("Hulk"),
        Hero("Batman"),
        Hero("Wolverine"),
        Hero("Superman")
    };

    enum heros_t { HULK, BATMAN, WOLVERINE, SUPERMAN };

    heros[HULK].set_attribute( Hero::ATTACK, "10000" );
    heros[HULK].set_attribute( Hero::DEFENSE, "10000" );
    heros[HULK].set_attribute( Hero::HEALING, "10" );

    heros[BATMAN].set_attribute( Hero::ATTACK, "100" );
    heros[BATMAN].set_attribute( Hero::DEFENSE, "10" );
    heros[BATMAN].set_attribute( Hero::HEALING, "10" );

    heros[SUPERMAN].set_attribute( Hero::ATTACK, "200000" );
    heros[SUPERMAN].set_attribute( Hero::DEFENSE, "200000" );
    heros[SUPERMAN].set_attribute( Hero::HEALING, "20000" );

    heros[ WOLVERINE ].set_attribute( Hero::ATTACK, "560" );
    heros[ WOLVERINE ].set_attribute( Hero::DEFENSE, "800" );
    heros[ WOLVERINE ].set_attribute( Hero::HEALING, "10000000" );

    std::cout << ">>> Hero list BEFORE sorting: \n";
    std::copy( heros.begin(), heros.end(),
               std::ostream_iterator< Hero >( std::cout, "\n") );
    std::cout << "\n";

    SortingPolicy p( Hero::ATTACK ); //atributo
    p.set_order( SortingPolicy::ASCENDING ); //tipo de ordem
    std::sort( heros.begin(), heros.end(), p);

    std::sort( heros.begin(), heros.end(), compare_by_name );

    std::cout << ">>> Hero list AFTER sorting: \n";
    std::copy( heros.begin(), heros.end(),
               std::ostream_iterator< Hero >( std::cout, "\n") );
    std::cout << "\n";


    return EXIT_SUCCESS;
}
