# New ports collection makefile for:	gnomelibs
# Date created:				17 June 1998
# Whom:					Yukihiro Nakai <Nakai@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	gnomelibs
PORTVERSION=	1.4.1.3
CATEGORIES?=	x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	stable/sources/gnome-libs
DISTNAME=	gnome-libs-${PORTVERSION}

MAINTAINER?=	gnome@FreeBSD.org

BUILD_DEPENDS=	scrollkeeper-config:${PORTSDIR}/textproc/scrollkeeper
LIB_DEPENDS+=	xml.5:${PORTSDIR}/textproc/libxml \
		ORBit.2:${PORTSDIR}/devel/ORBit
RUN_DEPENDS=	scrollkeeper-config:${PORTSDIR}/textproc/scrollkeeper

USE_X_PREFIX=	yes
USE_XPM=	yes
USE_PERL5=	yes
USE_GMAKE=	yes
USE_IMLIB=	yes
USE_ESOUND=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=${PREFIX}/share/gnome \
		--datadir=${PREFIX}/share/gnome \
		--disable-test-gnome
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

MAN1=		dns-helper.1 gconfigger.1 gnome-config.1 gnome-doc.1 \
		gnome-dump-metadata.1 gnome-gen-mimedb.1 gnome-mkstub.1 \
		gnome-moz-remote.1 gnome-name-service.1 gnome-pty-helper.1 \
		gnome.1 gnome_segv.1 goad-browser.1 libart-config.1 \
		loadshlib.1 new-object.1
MAN5=		gnome-mime.5

pre-patch:
	@${PERL} -pi -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure
	@find ${WRKSRC} -name "Makefile.in*" | xargs ${PERL} -pi -e \
		's|\$\(datadir\)/gnome/|\$\(datadir\)/|g ; \
		 s|\$\(datadir\)/locale|\$\(prefix\)/share/locale|g'

post-patch:
	@${PERL} -pi -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/gnome-config.in ${WRKSRC}/libgnome/gnome-util.c

# need to make launched gnome-terminals appear in utmp/wtmp
post-install:
	@${CHMOD} u+s ${PREFIX}/bin/gnome-pty-helper

.include <bsd.port.mk>
