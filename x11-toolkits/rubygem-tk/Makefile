PORTNAME=	tk
PORTVERSION=	0.4.0
CATEGORIES=	x11-toolkits rubygems
MASTER_SITES=	RG

MAINTAINER=	nmingotti@gmail.com
COMMENT=	Ruby interface to TclTk-8.6
WWW=		https://github.com/ruby/tk

LICENSE=	BSD2CLAUSE
LICENSE_FILE_BSD2CLAUSE=${WRKSRC}/BSDL
LICENSE_FILE_RUBY=	${WRKSRC}/LICENSE.txt

CONFIGURE_ARGS=--with-tcltkversion=8.6,8.6 \
		--with-tk-include=${LOCALBASE}/include/tk8.6 \
		--with-tcl-include=${LOCALBASE}/include/tcl8.6

USES=		gem tk:86 xorg
USE_XORG=	x11

.include <bsd.port.mk>
