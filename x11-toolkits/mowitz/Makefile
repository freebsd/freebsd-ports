# New ports collection makefile for:	Mowitz
# Date created:		this 7th day of January, 2002
# Whom:			mi
#
# $FreeBSD$

PORTNAME=	Mowitz
PORTVERSION=	0.1.1
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://siag.nu/pub/mowitz/

MAINTAINER=	mi@aldan.algebra.com

LIB_DEPENDS=	Xaw3d:${PORTSDIR}/x11-toolkits/Xaw3d

USE_X_PREFIX=	yes
USE_XPM=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-xawm=Xaw3d

.if defined(X11BASE) && ${X11BASE} != /usr/X11R6
post-patch:
	${PERL} -pi -e 's,/usr/X11R6,${X11BASE},g' \
		`find ${WRKSRC} | xargs fgrep -l --mmap /usr/X11R6`
.endif

post-install:
	${RM} ${PREFIX}/lib/libMowitz.la
# Anyone knows a better way?

.include <bsd.port.mk>
