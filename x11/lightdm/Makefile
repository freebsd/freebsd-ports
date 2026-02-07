PORTNAME=	lightdm
PORTVERSION=	1.32.0
PORTREVISION=	7
CATEGORIES=	x11
MASTER_SITES=	https://github.com/canonical/${PORTNAME}/releases/download/${DISTVERSIONPREFIX}${DISTVERSION}/

MAINTAINER=	desktop@FreeBSD.org
COMMENT=	Lightweight Display Manager
WWW=		https://github.com/canonical/lightdm

# library/bindings are LGPLv2 or LGPLv3, the rest GPLv3+
LICENSE=	GPLv3 LGPL20 LGPL3
LICENSE_COMB=	multi
LICENSE_FILE_GPLv3=	${WRKSRC}/COPYING.GPL3
LICENSE_FILE_LGPL20=	${WRKSRC}/COPYING.LGPL2
LICENSE_FILE_LGPL3=	${WRKSRC}/COPYING.LGPL3

BUILD_DEPENDS=	itstool:textproc/itstool
LIB_DEPENDS=	libgcrypt.so:security/libgcrypt \
		libxklavier.so:x11/libxklavier
RUN_DEPENDS=	accountsservice>=0:sysutils/accountsservice \
		ck-launch-session:sysutils/consolekit2

USES=		autoreconf compiler:c++11-lang cpe gettext-tools gmake gnome \
		libtool localbase pathfix pkgconfig tar:xz xorg
CPE_VENDOR=	${PORTNAME}_project
USE_CXXSTD=	c++11
USE_GNOME=	glib20 intltool
USE_LDCONFIG=	yes
USE_RC_SUBR=	lightdm
USE_XORG=	x11 xcb xdmcp

GNU_CONFIGURE=		yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
# tests causes PAM errors
CONFIGURE_ARGS=		--disable-libaudit \
			--disable-tests
INSTALL_TARGET=		install-strip
LIBS=			-lutil
CONFLICTS_INSTALL=	sddm
PORTSCOUT=		limitw:1,even
SUB_FILES=		Xsession
USERS=			lightdm
GROUPS=			lightdm video

OPTIONS_DEFINE=		DOCS NLS QT5 VAPI
OPTIONS_DEFAULT=	VAPI
OPTIONS_SUB=		yes

DOCS_BUILD_DEPENDS=	${LOCALBASE}/share/aclocal/yelp.m4:textproc/yelp-tools \
			gtkdoc-check:textproc/gtk-doc
DOCS_CONFIGURE_ON=	--enable-gtk-doc

NLS_USES=		gettext-runtime
NLS_CONFIGURE_ENABLE=	nls

QT5_USES=		qt:5
QT5_USE=		QT=buildtools,core,dbus,gui
QT5_CONFIGURE_ENABLE=	liblightdm-qt5

VAPI_USES=		vala:build
VAPI_USE=		GNOME=introspection:build
VAPI_CONFIGURE_ENABLE=	vala

post-patch:
	@${REINPLACE_CMD} -i "" -e 's,%%PREFIX%%,${PREFIX},' \
		${WRKSRC}/data/lightdm.1 \
		${WRKSRC}/data/lightdm.conf

post-patch-DOCS-off:
	@${REINPLACE_CMD} -e '/^GTK_DOC_CHECK/d' \
		-e '/^YELP_HELP_INIT/d' \
		-e '/^doc\/Makefile/d' \
		-e '/^help\/Makefile/d' \
		${WRKSRC}/configure.ac
	@${REINPLACE_CMD} -e '/^SUBDIRS/s/ doc help//' \
		${WRKSRC}/Makefile.am

post-install:
	${RM} -r ${STAGEDIR}${PREFIX}/etc/init
	${INSTALL_SCRIPT} ${WRKDIR}/Xsession ${STAGEDIR}${ETCDIR}
	${MV} ${STAGEDIR}${ETCDIR}/keys.conf ${STAGEDIR}${ETCDIR}/keys.conf.sample
	${MV} ${STAGEDIR}${ETCDIR}/lightdm.conf ${STAGEDIR}${ETCDIR}/lightdm.conf.sample
	${MV} ${STAGEDIR}${ETCDIR}/users.conf ${STAGEDIR}${ETCDIR}/users.conf.sample
	${MV} ${STAGEDIR}${PREFIX}/etc/pam.d/lightdm ${STAGEDIR}${PREFIX}/etc/pam.d/lightdm.sample
	${MV} ${STAGEDIR}${PREFIX}/etc/pam.d/lightdm-autologin ${STAGEDIR}${PREFIX}/etc/pam.d/lightdm-autologin.sample
	${MV} ${STAGEDIR}${PREFIX}/etc/pam.d/lightdm-greeter ${STAGEDIR}${PREFIX}/etc/pam.d/lightdm-greeter.sample
	${MKDIR} ${STAGEDIR}/var/cache/lightdm \
		${STAGEDIR}/var/log/lightdm \
		${STAGEDIR}/var/run/lightdm
	${MKDIR} ${STAGEDIR}${PREFIX}/share/xgreeters
	@(cd ${STAGEDIR}${PREFIX}/share/xgreeters && \
		${LN} -sf lightdm-gtk-greeter.desktop default.desktop)

.include <bsd.port.mk>
