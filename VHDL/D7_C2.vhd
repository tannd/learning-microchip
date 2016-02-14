
library IEEE;
use IEEE.STD_LOGIC_1164.all;

entity D7_C2 is
	port( 
		 SI : in bit;
		 sel : in bit_VECTOR(2 downto 0);
		 SO : out bit_vector (7 downto 0)
	     );
end D7_C2;

architecture D7_C2 of D7_C2 is
begin	   
	 SO <= (SI & "0000000") when (sel="000") else
            ('0' & SI & "000000") when (sel="001") else
            ("00" & SI & "00000") when (sel="010") else
            ("000" & SI & "0000") when (sel="011") else
            ("0000" & SI & "000") when (sel="100") else
            ("00000" & SI & "00") when (sel="101") else
            ("000000" & SI & '0') when (sel="110") else
            ("0000000" & SI) ;

end D7_C2;
-- SI=random 1 ns; sel=random 3 ns;