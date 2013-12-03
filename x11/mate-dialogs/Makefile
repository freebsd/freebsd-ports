# Created by: Franz Klammer <klammer@webonaut.com>
# $FreeBSD$

PORTNAME=	mate-dialogs
PORTVERSION=	1.6.2
CATEGORIES=	x11 mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Display MATE dialogs from the command line

BUILD_DEPENDS=	rarian-sk-config:${PORTSDIR}/textproc/rarian
RUN_DEPENDS=	rarian-sk-config:${PORTSDIR}/textproc/rarian

PORTSCOUT=	limitw:1,even

USES=		gettext gmake pathfix pkgconfig
USE_XZ=		yes
USE_MATE=	docutils
USE_GNOME=	gnomehier glib20 gtk20 intlhack
INSTALLS_OMF=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-gtk=2.0
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	NOTIFY
OPTIONS_DEFAULT=NOTIFY

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNOTIFY}
LIB_DEPENDS+=	libnotify.so:${PORTSDIR}/devel/libnotify
CONFIGURE_ARGS+=--enable-libnotify
.else
CONFIGURE_ARGS+=--disable-libnotify
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|bin_SCRIPTS = gdialog||g' \
		${WRKSRC}/src/Makefile.am

.include <bsd.port.mk>
