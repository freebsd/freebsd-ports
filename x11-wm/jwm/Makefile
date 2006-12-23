# New ports collection makefile for:   jwm
# Date created:        26 DEC 2005
# Whom:                babak@farrokhi.net
#
# $FreeBSD$
#

PORTNAME=	jwm
PORTVERSION=	1.8
CATEGORIES=	x11-wm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://joewing.net/programs/
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	farrokhi@FreeBSD.org
COMMENT=	Joe's Window Manager

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png

USE_X_PREFIX=	yes
USE_XPM=	yes
GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GCC=	3.4+
CFLAGS+=	-I${LOCALBASE}/include -I${X11BASE}/include
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib"

MAN1=		jwm.1

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|' ${WRKSRC}/example.jwmrc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/jwm ${TARGETDIR}/bin
	${INSTALL_DATA} ${WRKSRC}/example.jwmrc ${TARGETDIR}/etc/system.jwmrc.sample
	if ! [ -f ${TARGETDIR}/etc/system.jwmrc ]; then \
		${INSTALL_DATA} ${WRKSRC}/example.jwmrc ${TARGETDIR}/etc/system.jwmrc; \
	fi
	${INSTALL_MAN} ${WRKSRC}/jwm.1 ${MANPREFIX}/man/man1/

.include <bsd.port.post.mk>
