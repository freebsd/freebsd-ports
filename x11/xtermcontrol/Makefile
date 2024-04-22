PORTNAME=	xtermcontrol
PORTVERSION=	3.6
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://www.thrysoee.dk/xtermcontrol/ \
		http://fossies.org/linux/privat/

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Tool for dynamic control of xterm properties
WWW=		https://www.thrysoee.dk/xtermcontrol/

LICENSE=	GPLv2+

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_header_libintl_h=no
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share

PLIST_FILES=	bin/xtermcontrol share/man/man1/xtermcontrol.1.gz

.include <bsd.port.mk>
