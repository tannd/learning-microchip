-------------------------------------------------------------------------------
--
-- Title       : ALU_procedure
-- Design      : de1
-- Author      : phamthanh1992@hotmail.com
-- Company     : homes
--
-------------------------------------------------------------------------------
--
-- File        : ALU_procedure.vhd
library IEEE;
use IEEE.STD_LOGIC_1164.all;
use IEEE.STD_LOGIC_ARITH.ALL; 
use IEEE.STD_LOGIC_UNSIGNED.ALL;
entity ALU_procedure is
	 port(
		 cin : in STD_LOGIC;
		 a : in STD_LOGIC_VECTOR(7 downto 0);
		 b : in STD_LOGIC_VECTOR(7 downto 0);
		 sel : in STD_LOGIC_VECTOR(3 downto 0);
		 y : out STD_LOGIC_VECTOR(7 downto 0)
	     );
end ALU_procedure;

--}} End of automatically maintained section

architecture ALU_procedure of ALU_procedure is	   
procedure hamlogic
(
		signal x1,x2: in std_logic_vector(7 downto 0);
		signal sel : in STD_LOGIC_VECTOR(2 downto 0);
		signal y1: out std_logic_vector(7 downto 0)
) is   
  begin  
   		if sel = "000" then y1<= not x1;
		elsif sel ="001" then y1<= not x2;
		elsif sel ="010" then y1<= x1 and x2;
		elsif sel ="011" then y1<= x1 or x2;
		elsif sel ="100" then y1<= x1 nand x2;
		elsif sel ="101" then y1<= x1 nor x2;
		elsif sel ="110" then y1<= x1 xor x2;
		elsif sel ="111" then y1<= x1 xnor x2;	
		end if ;
  end  hamlogic;
procedure hamsohoc
(
	signal x1,x2: in std_logic_vector(7 downto 0) ;
	signal sel : in STD_LOGIC_VECTOR(2 downto 0);
	signal  cin: in std_logic;
	signal y2: out std_logic_vector(7 downto 0)
) is 

  begin  
   	if sel ="000" then y2<= a;
		elsif sel ="001" then y2<=a+1;
		elsif sel ="010" then y2<=a-1;
		elsif sel ="011" then y2<=b;
		elsif sel ="100" then y2<=b+1;
		elsif sel ="101" then y2<=b-1;
		elsif sel ="110" then y2<=a+b;
		elsif sel ="111" then y2<=a+b+cin;
		end if;
  end  hamsohoc; 
procedure hammux
(
	signal y1: in std_logic_vector(7 downto 0) ;
	signal  y2: in std_logic_vector(7 downto 0);
	signal sel : in STD_LOGIC;
	signal y: out std_logic_vector(7 downto 0)
) is    
  begin  
   	if sel='0'then y<=y1;
	else y<=y2;
	end if;
  end  hammux;
  
signal w1,w2: std_logic_vector (7 downto 0);
begin

process(sel,a,b,cin)
begin
	hamlogic(a,b,sel(2 downto 0),w1);
	hamsohoc(a,b,sel(2 downto 0),cin,w2);
	hammux(w1,w2,sel(3),y);
	
end process;	

end ALU_procedure;
