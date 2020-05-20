use strict;    
use warnings;    
use IO::Socket;    
  
my $socket = new IO::Socket::INET (    
PeerAddr => 'localhost',    
PeerPort => '9874',    
Proto => 'tcp',    
);    
die "Could not create socket: $!n" unless $socket; 
while(1){
	my $data = <STDIN>;   
	chomp $data;   
	print $socket "$data\n";   
}
close($socket); 
