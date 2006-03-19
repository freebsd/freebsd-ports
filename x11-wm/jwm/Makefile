# New ports collection makefile for:   jwm
# Date created:        26 DEC 2005
# Whom:                babak@farrokhi.net
#
# $FreeBSD$
#

PORTNAME=	jwm
PORTVERSION=	1.5
CATEGORIES=	x11-wm
MASTER_SITES=	http://joewing.net/programs/jwm/ \
		http://www.unixified.net/distfiles/

MAINTAINER=	babak@farrokhi.net
COMMENT=	Joe's Window Manager

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png

USE_X_PREFIX=	yes
USE_XPM=	yes
GNU_CONFIGURE=	yes
USE_BZIP2=	yes
CFLAGS+=	-I${LOCALBASE}/include -I${X11BASE}/include
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib"

MAN1=		jwm.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		Does not compile
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|' ${WRKSRC}/example.jwmrc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/jwm ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/example.jwmrc ${PREFIX}/etc/system.jwmrc.sample
	if ! [ -f ${PREFIX}/etc/system.jwmrc ]; then \
		${INSTALL_DATA} ${WRKSRC}/example.jwmrc ${PREFIX}/etc/system.jwmrc; \
	fi
	${INSTALL_MAN} ${WRKSRC}/jwm.1 ${MANPREFIX}/man/man1/

.include <bsd.port.post.mk>
