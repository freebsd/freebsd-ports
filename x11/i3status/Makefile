# $FreeBSD$

PORTNAME=	i3status
PORTVERSION=	2.10
CATEGORIES=	x11
MASTER_SITES=	http://i3wm.org/i3status/

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Small program for generating a status bar

LICENSE=	BSD3CLAUSE

OPTIONS_DEFINE=	PULSEAUDIO

LIB_DEPENDS=	libconfuse.so:devel/libconfuse \
		libyajl.so:devel/yajl

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USES=		gmake tar:bzip2

PULSEAUDIO_EXTRA_PATCHES_OFF=	${FILESDIR}/no-pulseaudio.diff
PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio

post-patch:
	@${REINPLACE_CMD} -e 's|/etc|${PREFIX}/etc|g' ${WRKSRC}/i3status.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/i3status ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/man/i3status.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/i3status.conf ${STAGEDIR}${PREFIX}/etc/i3status.conf.sample

.include <bsd.port.mk>
