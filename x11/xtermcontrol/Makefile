# Created by: krion
# $FreeBSD$

PORTNAME=	xtermcontrol
PORTVERSION=	3.3
CATEGORIES=	x11
MASTER_SITES=	http://www.thrysoee.dk/xtermcontrol/ \
		http://fossies.org/linux/privat/

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Tool for dynamic control of xterm properties

LICENSE=	GPLv2+

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_header_libintl_h=no
CONFIGURE_ARGS=	--disable-silent-rules

PLIST_FILES=	bin/xtermcontrol man/man1/xtermcontrol.1.gz

.include <bsd.port.mk>
