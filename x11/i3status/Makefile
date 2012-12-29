# $FreeBSD$

PORTNAME=	i3status
PORTVERSION=	2.6
CATEGORIES=	x11
MASTER_SITES=	http://i3wm.org/i3status/

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Small program for generating a status bar

LICENSE=	BSD

LIB_DEPENDS=	confuse:${PORTSDIR}/devel/libconfuse \
		yajl:${PORTSDIR}/devel/yajl

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USE_BZIP2=	yes
USE_GMAKE=	yes

PLIST_FILES=	bin/i3status \
		etc/i3status.conf.sample
MAN1=	i3status.1

post-patch:
	@${REINPLACE_CMD} -e 's|/etc|${PREFIX}/etc|g' ${WRKSRC}/i3status.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/i3status ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/man/i3status.1 ${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/i3status.conf ${PREFIX}/etc/i3status.conf.sample

.include <bsd.port.mk>
