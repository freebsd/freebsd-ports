# Created by: Miguel Mendez <flynn@energyhq.homeip.net>
# $FreeBSD$

PORTNAME=	decurs
PORTVERSION=	0.55.1
PORTREVISION=	12
CATEGORIES=	x11
MASTER_SITES=	http://freebsd.nsu.ru/distfiles/ \
		#http://varg.dyndns.org/psi/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Lets you edit your X11 mouse cursors

LIB_DEPENDS=	libgtkmm-2.0.6.so:${PORTSDIR}/x11-toolkits/gtkmm20

DEPRECATED=	Abandonware, not staged
EXPIRATION_DATE=	2014-04-24

USE_XORG=	x11
USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
USES=		pkgconfig

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${ARCH} != "i386"
BROKEN=		Does not compile on !i386
.endif

post-patch:
	@${SED} -e 's:%%PREFIX%%:${PREFIX}:g' \
		${FILESDIR}/decurs.exec > ${WRKSRC}/decurs.exec
# Hacks for contemporary GCC
	@${REINPLACE_CMD} -e 's/CppString \&str/const &/' \
		${WRKSRC}/src/cppstring.cc ${WRKSRC}/src/cppstring.hh
	@${REINPLACE_CMD} -E 's/^\/\/ friend// ; \
		s/([^:])ostream/\1std::ostream/g' ${WRKSRC}/src/cppstring.hh

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/decurs ${PREFIX}/bin/decurs.bin
	${INSTALL_SCRIPT} ${WRKSRC}/decurs.exec ${PREFIX}/bin/decurs
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/fonts/*.bdf ${DATADIR}

.include <bsd.port.post.mk>
